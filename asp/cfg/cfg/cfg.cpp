/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2007-2008 by TAKAGI Nobuhisa
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 */
#include "cfg.hpp"
#include <boost/program_options.hpp>
#include <boost/spirit.hpp>

namespace
{

  //! 起動オプションの解析
  int parse_program_options( int argc, char* argv[] )
  {
    namespace po = boost::program_options;
    int pass = 0;

    // 一般オプション
    po::options_description generic( _( "Generic options" ) );
    generic.add_options()
      ( "help", _( "display this information" ) )    
      ( "version,v", _( "display cfg version number" ) )
      ;

    // 設定オプション
    po::options_description config( _( "Configuration" ) );
    config.add_options()
      ( "kernel,k", po::value< std::string >()->default_value( std::string( "asp" ) ), _( "kernel type (default: asp)" ) )
      ( "pass,p", po::value< int >( &pass )->default_value( 0 ), _( "run for pass #`arg\'" ) )
      ( "include-path,I", po::value< std::vector< std::string > >(), _( "include path" ) )
      ( "template-file,T", po::value< std::string >(), _( "template file" ) )
      ( "input-charset", po::value< std::string >()->default_value( std::string( "ascii" ) ), _( "character set of input file (default: ascii)" ) )
      ( "api-table", po::value< std::vector< std::string > >(), _( "specify static API table" ) )
      ( "cfg1-def-table", po::value< std::vector< std::string > >(), _( "specify cfg1 definition table" ) )
      ( "cfg1_out", po::value< std::string >()->default_value( std::string( "cfg1_out" ) ), _( "specify file name instead of `cfg1_out.srec\' (default: cfg1_out)" ) )
      ( "rom-image,r", po::value< std::string >(), _( "ROM image (S-record)" ) )
      ( "symbol-table,s", po::value< std::string >(), _( "Symbol table (`nm' style)" ) )
      ( "cfg-directory,d", po::value< std::string >(), _( "cfg directory" ) )
      ( "msgcat-directory,m", po::value< std::vector< std::string > >(), _( "msgcat(*.po) directory" ) )
      ( "destination-directory,n", po::value< std::string >()->default_value( "." ), _( "destination directory" ) )
      ( "id-output-file", po::value< std::string >()->default_value( std::string() ), _( "output file for id assignment" ) )
      ( "id-input-file", po::value< std::string >()->default_value( std::string() ), _( "input file for id assignment" ) )
      ( "alignof-fp", po::value< std::size_t >()->default_value( 1 ), _( "alignment of pointer to function" ) )
      ( "external-id", _( "output ID numbers as external `const\' object" ) )
      ( "print-dependencies,M", po::value< std::string >(), _( "output dependencies of source file (for `make\')" ) )
      ;

    // 非表示オプション
    po::options_description hidden( _( "Hidden options" ) );
    hidden.add_options()
      ( "input-file,s", po::value< std::string >(), _( "input file" ) )
      ;
    
    po::options_description cmdline_options;
    cmdline_options.add( generic ).add( config ).add( hidden );

    po::options_description visible( _( "Allowed options" ) );
    visible.add( generic ).add( config );
    
    po::positional_options_description p;
    p.add( "input-file", -1 );
    
    po::variables_map vm;
    try
    {
      store( po::command_line_parser( argc, argv ).
            options( cmdline_options ).positional( p ).run(), vm );
      notify( vm );
    }
    catch ( boost::program_options::error& )
    {
      toppers::fatal( _( "illegal options" ) );
    }

    // グローバル変数の設定
    if ( vm.count( "print-dependencies" ) )
    {
      toppers::global( "print-dependencies" ) = vm["print-dependencies"].as< std::string >();
      pass = 1; // 依存関係の出力が必要な場合、強制的にパス1に変更
    }

    toppers::global( "pass" ) = pass;
    if ( vm.count( "kernel" ) )
    {
      std::string kernel = toppers::tolower( vm["kernel"].as< std::string >() );
      toppers::global( "kernel" ) = kernel;
      bool has_class = false;
      bool has_domain = false;

      if ( kernel == "fmp" )
      {
        has_class = true;
      }

      toppers::global( "has-class" ) = has_class;
      toppers::global( "has-domain" ) = has_domain;
    }
    if ( vm.count( "include-path" ) )
    {
      toppers::global( "include-path" ) = vm["include-path"].as< std::vector< std::string > >();
    }
    if ( vm.count( "template-file" ) )
    {
      toppers::global( "template-file" ) = vm["template-file"].as< std::string >();
    }
    if ( vm.count( "input-file" ) )
    {
      toppers::global( "input-file" ) = vm["input-file"].as< std::string >();
    }
    if ( vm.count( "input-charset" ) )
    {
      std::string input_charset( toppers::tolower( vm["input-charset"].as< std::string >() ) );
      toppers::global( "input-charset" ) = input_charset;

      toppers::codeset_t codeset = toppers::ascii;
      if ( ( input_charset == "cp932" )
        || ( input_charset == "shift_jis" )
        || ( input_charset == "sjis" ) )
      {
        codeset = toppers::shift_jis;
      }
      else if ( ( input_charset == "eucjp" )
        || ( input_charset == "euc-jp" )
        || ( input_charset == "euc" ) )
      {
        codeset = toppers::euc_jp;
      }
      else if ( ( input_charset == "utf-8" )
        || ( input_charset == "utf8" ) )
      {
        codeset = toppers::utf8;
      }
      toppers::global( "codeset" ) = codeset;
    }
    if ( vm.count( "api-table" ) )
    {
      toppers::global( "api-table" ) = vm["api-table"].as< std::vector< std::string > >();
    }
    if ( vm.count( "cfg1-def-table" ) )
    {
      toppers::global( "cfg1-def-table" ) = vm["cfg1-def-table"].as< std::vector< std::string > >();
    }
    if ( vm.count( "cfg1_out" ) )
    {
      toppers::global( "cfg1_out" ) = vm["cfg1_out"].as< std::string >();
    }
    else
    {
      toppers::global( "cfg1_out" ) = std::string( "cfg1_out" );
    }
    if ( vm.count( "cfg-directory" ) )
    {
      std::string cfg_directory( vm["cfg-directory"].as< std::string >() );
      toppers::global( "cfg-directory" ) = cfg_directory;
      toppers::load_msgcat( cfg_directory );
    }
    if ( vm.count( "msgcat-directory" ) )
    {
      std::vector< std::string > msgcat_dirs( vm["msgcat-directory"].as< std::vector< std::string > >() );
      std::for_each( msgcat_dirs.begin(), msgcat_dirs.end(), &toppers::load_msgcat );
    }
    if ( true ) // include-path を空にしてはならない
    {
      std::vector< std::string > include_path;
      boost::any t( toppers::global( "include-path" ) );
      if ( !t.empty() )
      {
        include_path = boost::any_cast< std::vector< std::string > >( t );
      }
      include_path.push_back( boost::any_cast< std::string >( toppers::global( "cfg-directory" ) ) );
      toppers::global( "include-path" ) = include_path;
    }
    if ( vm.count( "output-directory" ) )
    {
      toppers::global( "output-directory" ) = vm["output-directory"].as< std::string >();
    }
    if ( vm.count( "rom-image" ) )
    {
      toppers::global( "rom-image" ) = vm["rom-image"].as< std::string >();
    }
    if ( vm.count( "symbol-table" ) )
    {
      toppers::global( "symbol-table" ) = vm["symbol-table"].as< std::string >();
    }
    else
    {
      toppers::global( "symbol-table" ) = boost::any_cast< std::string& >( toppers::global( "kernel" ) ) + ".syms";
    }
    if ( vm.count( "id-output-file" ) )
    {
      toppers::global( "id-output-file" ) = vm["id-output-file"].as< std::string >();
    }
    if ( vm.count( "id-input-file" ) )
    {
      toppers::global( "id-input-file" ) = vm["id-input-file"].as< std::string >();
    }
    if ( vm.count( "alignof-fp" ) )
    {
      toppers::global( "alignof-fp" ) = vm["alignof-fp"].as< std::size_t >();
    }
    toppers::global( "external-id" ) = vm.count( "external-id" ) ? true : false;

    if ( vm.count( "version" ) )
    {
      toppers::global( "version" ) = CFG_VERSION;
      std::cout << "TOPPERS Kernel Configurator version "
                << ( CFG_VERSION / 10000 ) << '-' << ( CFG_VERSION / 100 % 100 ) << '-' << ( CFG_VERSION % 100 )
                << std::endl;
      toppers::global( "pass0" ) = true;
    }
    if ( vm.count( "help" ) )
    {
      toppers::global( "help" ) = boost::lexical_cast< std::string >( visible );
      std::cout << visible << std::endl;
      toppers::global( "pass0" ) = true;
    }
    return pass;
  }

}

//! コンフィギュレータのメイン処理
int cfg_main( int argc, char* argv[] )
{
  using namespace toppers;

  std::string const cfg_path( argv[0] );
  std::string const cfg_name( "cfg" );
  std::string::const_iterator iter = std::find_end( cfg_path.begin(), cfg_path.end(), cfg_name.begin(), cfg_name.end() );
  // 環境変数のサーチまでは行わない
  std::string cfg_dir( cfg_path.begin(), iter );
  if ( *cfg_dir.rbegin() == '/' || *cfg_dir.rbegin() == '\\' )
  {
    cfg_dir.resize( cfg_dir.size() - 1 );
  }
  toppers::global( "cfg-directory" ) = cfg_dir;

  int pass = parse_program_options( argc, argv );
  bool ( * pfn_cfg[] )() = { &cfg0_main, &cfg1_main, &cfg2_main, &cfg3_main };
  int max_pass = static_cast< int >( sizeof( pfn_cfg ) / sizeof( pfn_cfg[0] ) );

  if ( pass < 0 || max_pass < pass )
  {
    fatal( _( "illegal cfg pass #%d" ), pass );
  }

  if ( !( *pfn_cfg[pass] )() )
  {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int main( int arg, char* argv[] )
{
  int status;
  try
  {
    toppers::set_program_name( "cfg" );
    status = cfg_main( arg, argv );
    if ( status != EXIT_SUCCESS && toppers::get_error_count() == 0 )
    {
      std::fprintf( stderr, "cfg: %s\n", _( "unknown error" ) );
    }
    if ( toppers::get_error_count() > 0 )
    {
      status = EXIT_FAILURE;
    }
  }
  catch ( toppers::normal_exit& )
  {
    status = EXIT_SUCCESS;
  }
  catch ( std::exception& e )
  {
    std::fprintf( stderr, "cfg: %s\n", e.what() );
    status = EXIT_FAILURE;
  }
  catch ( ... )
  {
    std::fprintf( stderr, "cfg: %s\n", _( "internal error" ) );
    status = EXIT_FAILURE;
  }
  return status;
}
