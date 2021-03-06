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
#include <fstream>
#include <sstream>
#include "toppers/diagnostics.hpp"
#include "toppers/s_record.hpp"
#include "toppers/macro_processor.hpp"
#include "cfg.hpp"
#include <boost/spirit.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

/*!
 *  \brief  オブジェクトID番号の割付け
 *  \param[in]  api_map   ソースに記述された静的APIを登録したコンテナ
 */
void assign_id( toppers::itronx::cfg1_out::static_api_map& api_map )
{
  using namespace toppers;
  using namespace toppers::itronx;

  std::string id_input_file( boost::any_cast< std::string& >( global( "id-input-file" ) ) );
  if ( id_input_file.empty() )  // --id-input-file オプションが指定されていない場合...
  {
    for ( cfg1_out::static_api_map::iterator iter( api_map.begin() ), last( api_map.end() );
          iter != last;
          ++iter )
    {
      static_api::assign_id( iter->second.begin(), iter->second.end() );
    }
  }
  else  // --id-input-file オプションが指定されている場合...
  {
    typedef std::map< std::string, std::pair< long, bool > > id_map_t;
    id_map_t id_map;
    std::ifstream ifs( id_input_file.c_str() );
    while ( ifs )
    {
      std::string linebuf;
      std::getline( ifs, linebuf );
      if ( ifs.bad() )
      {
        fatal( _( "I/O error" ) );
      }
      if ( linebuf.empty() || linebuf == "\r" )
      {
        break;
      }

      std::istringstream iss( linebuf );
      std::string name;
      iss >> name;
      if ( iss.fail() )
      {
        fatal( _( "id file `%1%\' is invalid" ), id_input_file );
      }

      long value;
      iss >> value;
      if ( iss.fail() )
      {
        fatal( _( "id file `%1%\' is invalid" ), id_input_file );
      }

      if ( id_map.find( name ) != id_map.end() )
      {
        fatal( _( "`%1%\' is duplicated" ), name );
      }
      else
      {
        id_map[ name ] = std::make_pair( value, false );
      }
    }

    for ( cfg1_out::static_api_map::iterator iter( api_map.begin() ), last( api_map.end() );
          iter != last;
          ++iter )
    {
      for ( std::vector< static_api >::iterator iter2( iter->second.begin() ), last2( iter->second.end() );
            iter2 != last2;
            ++iter2 )
      {
        static_api::info const* info = iter2->get_info();
        if ( info->id_pos >= 0 )
        {
          std::string name( iter2->at( info->id_pos ).text );
          std::string symbol( iter2->at( info->id_pos ).symbol );
          if ( !info->slave && symbol[0] == '#' )
          {
            id_map_t::iterator hit( id_map.find( name ) );
            if ( hit != id_map.end() )
            {
              long id_value = hit->second.first;
              if ( id_value > 0 )
              {
                iter2->at( info->id_pos ).value = id_value;
                hit->second.second = true;
              }
            }
          }
        }
      }
      static_api::assign_id( iter->second.begin(), iter->second.end() );
    }

    for ( id_map_t::const_iterator iter( id_map.begin() ), last( id_map.end() ); iter != last; ++iter )  // 残り物があれば...
    {
      if ( !iter->second.second )
      {
        warning( _( "object identifier `%1%\' is not used" ), iter->first );
      }
    }
  }

  // --id-output-file オプションが指定されている場合
  std::string id_output_file( boost::any_cast< std::string& >( global( "id-output-file" ) ) );
  if ( !id_output_file.empty() )
  {
    std::ofstream ofs( id_output_file.c_str() );
    for ( cfg1_out::static_api_map::iterator iter( api_map.begin() ), last( api_map.end() );
      iter != last;
      ++iter )
    {
      for ( std::vector< static_api >::const_iterator iter2( iter->second.begin() ), last2( iter->second.end() );
            iter2 != last2;
            ++iter2 )
      {
        static_api::info const* info = iter2->get_info();
        if ( info->id_pos >= 0 )
        {
          std::string name( iter2->at( info->id_pos ).text );
          std::string symbol( iter2->at( info->id_pos ).symbol );
          if ( !info->slave && symbol[0] == '#' )
          {
            ofs << name << '\t' << iter2->at( info->id_pos ).value.get() << std::endl;
          }
        }
      }
    }
  }
}

/*!
 *  \brief  パス２処理
 *  \retval true  成功
 *  \retval false 失敗
 */
bool cfg2_main()
{
  using namespace toppers;
  using namespace toppers::itronx;

  std::string kernel( boost::any_cast< std::string& >( global( "kernel" ) ) );
  itronx::factory factory( kernel );

  // *.cfgとcfg1_out.srecの読み込み
  std::string input_file;
  try
  {
    input_file = boost::any_cast< std::string const& >( toppers::global( "input-file" ) );
  }
  catch ( boost::bad_any_cast& )
  {
    fatal( _( "no input files" ) );
  }
  std::string cfg1_out_name( boost::any_cast< std::string& >( global( "cfg1_out" ) ) );
  std::auto_ptr< cfg1_out > cfg1_out( factory.create_cfg1_out( cfg1_out_name ) );

  codeset_t codeset = boost::any_cast< codeset_t >( global( "codeset" ) );
  cfg1_out->load_cfg( input_file, codeset, *factory.get_static_api_info_map() );
  cfg1_out->load_srec();
  cfg1_out::static_api_map api_map( cfg1_out->merge() );

  // ID番号の割付け
  assign_id( api_map );

  std::auto_ptr< macro_processor > mproc( factory.create_macro_processor( factory.get_hook_on_assign(), *cfg1_out, api_map ) );

  // テンプレート処理
  boost::any template_file( global( "template-file" ) );
  namespace fs = boost::filesystem;
  fs::path cfg_dir( boost::any_cast< std::string& >( global( "cfg-directory" ) ), fs::native );
  std::vector< std::string > include_paths = boost::any_cast< std::vector< std::string > >( global( "include-path" ) );
  include_paths.push_back( cfg_dir.empty() ? "." : cfg_dir.native_file_string() );
  if ( !template_file.empty() )
  {
    toppers::text in_text;
    toppers::text pp_text;
    std::string file_name( boost::any_cast< std::string& >( template_file ) );

    in_text.set_line( file_name, 1 );
    std::ifstream ifs( file_name.c_str() );
    in_text.append( ifs );
    macro_processor::preprocess( in_text, pp_text );
    mproc->evaluate( pp_text );
  }
  else  // テンプレートファイルが指定されていないので、共通部分（kernel.tf）のみを処理
  {
    fs::path kernel_cfg_template_file( cfg_dir/fs::path( "../../kernel/kernel.tf" ) );
    if ( !fs::exists( kernel_cfg_template_file ) )
    {
      error( _( "cannot open file `%1%\'" ), kernel_cfg_template_file.native_file_string() );
    }
    else
    {
      toppers::text in_text;
      toppers::text pp_text;

      in_text.set_line( kernel_cfg_template_file.native_file_string(), 1 );
      std::ifstream ifs( kernel_cfg_template_file.native_file_string().c_str() );
      in_text.append( ifs );
      macro_processor::preprocess( in_text, pp_text );
      mproc->evaluate( pp_text );
    }
  }

  if ( get_error_count() > 0 )
  {
    return false;
  }
  output_file::save();
  return true;
}
