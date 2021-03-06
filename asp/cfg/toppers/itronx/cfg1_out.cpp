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
#include <cstdlib>
#include <cerrno>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stack>
#include "toppers/text.hpp"
#include "toppers/diagnostics.hpp"
#include "toppers/c_parser.hpp"
#include "toppers/global.hpp"
#include "toppers/macro_processor.hpp"
#include "toppers/s_record.hpp"
#include "toppers/nm_symbol.hpp"
#include "toppers/itronx/cfg1_out.hpp"
#include "toppers/itronx/preprocess.hpp"
#include <boost/spirit.hpp>
#include <boost/filesystem/path.hpp>

namespace toppers
{
  namespace itronx
  {
    namespace
    {
      struct block_t
      {
        std::string type;
        std::string id;
        text_line line;
      };
    }

    //! cfg_out クラスの実装詳細
    struct cfg1_out::implementation
    {
    protected:
      output_file ofile_;
      std::vector< static_api > static_api_array_;
      std::string cfg1_out_list_;
      std::string includes_;
      std::vector< block_t > block_table_;

      std::tr1::shared_ptr< s_record > srec_;
      std::tr1::shared_ptr< nm_symbol > syms_;
      bool little_endian_;
      std::size_t base_;
      cfg1_def_table const* def_table_;

      implementation( std::string const& filename, std::ios_base::openmode omode, cfg1_def_table const* def_table = 0 )
        : ofile_( filename, omode ), little_endian_( true ), base_( 1 ), def_table_( def_table )
      {
      }
      virtual ~implementation()
      {
      }
      virtual void do_load_cfg( std::string const& input_file, codeset_t codeset, std::map< std::string, static_api::info > const& info_map );
      virtual void do_generate_includes() const
      {
      }
      virtual void do_generate_cfg1_def() const
      {
        ofile_ << "const uint32_t TOPPERS_cfg_magic_number = 0x12345678;\n"
                  "const uint32_t TOPPERS_cfg_sizeof_signed_t = sizeof(signed_t);\n"
                  "const unsigned_t TOPPERS_cfg_CHAR_BIT = CHAR_BIT;\n"
                  "const unsigned_t TOPPERS_cfg_CHAR_MAX = CHAR_MAX;\n"
                  "const unsigned_t TOPPERS_cfg_CHAR_MIN = CHAR_MIN;\n"
                  "const unsigned_t TOPPERS_cfg_SCHAR_MAX = SCHAR_MAX;\n"
                  "const unsigned_t TOPPERS_cfg_SHRT_MAX = SHRT_MAX;\n"
                  "const unsigned_t TOPPERS_cfg_INT_MAX = INT_MAX;\n"
                  "const unsigned_t TOPPERS_cfg_LONG_MAX = LONG_MAX;\n"
                  "\n";

        if ( def_table_ != 0 )
        {
          for ( cfg1_def_table::const_iterator iter( def_table_->begin() ), last( def_table_->end() );
                iter != last;
                ++iter )
          {
            // 式の最初に # があれば、それは前処理式
            bool is_pp = ( iter->expression[ 0 ] == '#' );

            std::string definition = ( iter->is_signed ? "const signed_t " : "const unsigned_t " );
            definition += "TOPPERS_cfg_" + iter->name;
            if ( is_pp )
            {
              definition +=
                          " = \n"
                          "#if " + iter->expression.substr( 1 ) + "\n"
                          "1;\n"
                          "#else\n"
                          "0;\n"
                          "#endif\n";
            }
            else
            {
              definition +=
                          " = " + iter->expression + ";\n";
            }
            ofile_ << definition;
          }
        }
      }
      virtual void do_assign_params();
      virtual implementation* do_clone() const
      {
        return new implementation( *this );
      }

      void preprocess( std::string const& input_file, codeset_t codeset, text& txt );

      friend class cfg1_out;
    };


    /*!
     *  \brief  コンストラクタ
     *  \param[in]  filename    cfg1_out.c または cfg1_out.srec 若しくはそれらの代替名
     *  \param[in]  def_table   cfg1_out.c 生成用の定義テーブル
     */
    cfg1_out::cfg1_out( std::string const& filename, cfg1_def_table const* def_table )
      : pimpl_( new implementation( filename, std::ios_base::out, def_table ) )
    {
    }

    /*!
     *  \brief  コピーコンストラクタ
     *  \param[in]  other   コピー元
     */
    cfg1_out::cfg1_out( cfg1_out const& other )
      : pimpl_( other.pimpl_->do_clone() )
    {
    }

    //! デストラクタ
    cfg1_out::~cfg1_out()
    {
      delete pimpl_;
      pimpl_ = 0;
    }

    /*!
     *  \brief  システムコンフィギュレーションファイルのロード
     *  \param[in]  input_file  入力ファイル名
     *  \param[in]  codeset     文字コード
     *  \param[in]  info_map    静的API情報の連想配列
     */
    void cfg1_out::load_cfg( std::string const& input_file, codeset_t codeset, std::map< std::string, static_api::info > const& info_map )
    {
      return pimpl_->do_load_cfg( input_file, codeset, info_map );
    }

    //! 前処理
    void cfg1_out::implementation::preprocess( std::string const& input_file, codeset_t codeset, text& txt )
    {
      boost::any print_depend = global( "print-dependencies" );
      if ( !print_depend.empty() )
      {
        std::set< std::string > depend, onces;
        itronx::preprocess( input_file, txt, codeset, &depend, &onces );

        // 依存関係の出力（GNU makeに適した形式）
        std::string target_file = boost::any_cast< std::string& >( print_depend );
        std::cout << target_file << ": " << input_file << ' ';
        std::copy( depend.begin(), depend.end(), std::ostream_iterator< std::string >( std::cout, " " ) );
        std::cout << std::endl;
        exit();
      }
      else
      {
        std::set< std::string > onces;
        itronx::preprocess( input_file, txt, codeset, 0, &onces );
      }
    }

    /*!
     *  \brief  システムコンフィギュレーションファイルのロード処理の実体
     *  \param[in]  input_file  入力ファイル名
     *  \param[in]  codeset     文字コード
     *  \param[in]  info_map    静的API情報の連想配列
     */
    void cfg1_out::implementation::do_load_cfg( std::string const& input_file, codeset_t codeset, std::map< std::string, static_api::info > const& info_map )
    {
      text txt;
      preprocess( input_file, codeset, txt );

      // システムコンフィギュレーションファイルの解析
      std::ostringstream oss, includes_oss;
      std::vector< static_api > api_array;
      long serial = 0;
      std::stack< block_t > block_stack;
      std::vector< block_t > block_table;
      std::string current_class, current_domain;

      for ( text::const_iterator iter( txt.begin() ), last( txt.end() ); iter != last; ++iter )
      {
        using namespace boost::spirit;
        parse_info< text::const_iterator > info;

        info = parse( iter, last, ( ch_p( '#' ) >> *( anychar_p - eol_p ) >> eol_p ) ); // 前処理指令の検出
        if ( info.hit ) // 前処理指令ならば...
        {
          if ( std::size_t col = info.stop.get_col() )
          {
            if ( info.stop.get_row()->buf.find_first_not_of( " \t" ) < col )
            {
              error( _( "illegal character `%1%\' is found" ), '#' );
            }
          }
          text::const_iterator stop = info.stop;
          std::string directive;
          info = parse( iter, last, ( ch_p( '#' ) >> ( +alnum_p )[ assign_a( directive ) ] >> *( anychar_p - eol_p ) >> eol_p ) );
          if ( info.hit )
          {
            if ( directive == "include" )
            {
              std::string directive_line_str( iter, info.stop );
              if ( *directive_line_str.rbegin() == '\n' )
              {
                directive_line_str.erase( directive_line_str.size() - 1 );
              }
              includes_oss << directive_line_str << '\n';
              oss << "/* " << directive_line_str << " */\n";
            }
            else if ( directive == "if" || directive == "ifdef" || directive == "ifndef"
                   || directive == "else" || directive == "elif" || directive == "endif" )
            {
              oss << '\n' << std::string( iter, stop );
            }
            else if ( directive != "pragma" ) // コンフィギュレータが処理すべき#pragma指令はこの時点では除去されている
            {
              error( iter.line(), _( "`#%1%\' is not supported" ), directive );
            }
          }
          else
          {
            oss << std::string( iter, stop );
          }
          iter = boost::prior( stop );
        }
        else // 前処理指令ではなく...
          if ( !std::isspace( static_cast< unsigned char >( *iter ) ) )
        {
          while ( iter != last )
          {
            int ch = static_cast< unsigned char >( *iter );
            if ( !std::isspace( ch ) )
            {
              break;
            }
          }

          std::string block_type;
          std::string id;
          info = parse( iter, last,
                        (
                          ( str_p( "CLASS" ) | "DOMAIN" )[ assign_a( block_type ) ]
                          >> '(' >> c_ident_p[ assign_a( id ) ] >> ')' >> '{'
                        ),
                        space_p );
          if ( info.hit )               // CLASS or DOMAINブロック開始ならば...
          {
            block_t b;
            b.type = block_type;
            b.id = id;
            b.line = iter.line();

            // 入れ子判定
            if ( block_type == "CLASS" && !current_class.empty()
              || block_type == "DOMAIN" && !current_domain.empty() )
            {
              fatal( iter.line(), _( "`%1%\' is nested" ), block_type );
            }

            block_stack.push( b );
            block_table.push_back( b );

            oss << "\n#ifndef TOPPERS_cfg_valueof_" << id << "_DEFINED\n"
                   "#define TOPPERS_cfg_valueof_" << id << "_DEFINED 1\n";
            oss << boost::format( "\n#line %1% \"%2%\"\n" ) % ( iter.line().line ) % iter.line().file;
            if ( block_type == "CLASS" )
            {
              current_class = id;
              oss << "const unsigned_t TOPPERS_cfg_valueof_" << id << " = " << id << ";\n";
            }
            if ( block_type == "DOMAIN" )
            {
              current_domain = id;
              // DOMAINには未対応
            }
            oss << "\n#endif\n";

            oss << "#define TOPPERS_cfg_inside_of_" << id << "\n";

            iter = boost::prior( info.stop );
          }
          else if ( *info.stop == '}' ) // ブロック末尾ならば...
          {
            if ( block_stack.empty() )
            {
              fatal( iter.line(), _( "syntax error" ) );
            }
            block_t b = block_stack.top();
            block_stack.pop();

            oss << "\n#ifndef TOPPERS_cfg_inside_of_" << b.id << "\n";
            oss << boost::format( "\n#line %1% \"%2%\"\n" ) % ( iter.line().line ) % iter.line().file;
            oss << "#error syntax error\n"
                    "#endif\n";
            oss << "#undef TOPPERS_cfg_inside_of_" << b.id << "\n"
                    "\n";

            if ( b.type == "CLASS" )
            {
              current_class.clear();
            }
            if ( b.type == "DOMAIN" )
            {
              current_domain.clear();
            }
            iter = info.stop;
          }
          else
          {
            static_api api;
            if ( api.parse( iter, last, info_map, false, codeset ) )  // 静的APIならば...
            {
              if ( !current_class.empty() )
              {
                api.set_class( current_class );
                oss << "const unsigned_t TOPPERS_cfg_valueof_CLASS_" << serial << " = " << current_class << ";";
              }
              if ( !current_domain.empty() )
              {
                api.set_domain( current_domain );
              }

              api_array.push_back( api );

              std::string file( boost::filesystem::path( api.line().file, boost::filesystem::native ).string() ); // ディレクトリ区切子を / に変更
              oss << boost::format( "\n#line %1% \"%2%\"\n" ) % api.line().line % file;
              oss << "const unsigned_t TOPPERS_cfg_static_api_" << serial << " = " << serial << ";\n";

              if ( !api.params().empty() && api.begin()->symbol[0] == '#' )   // オブジェクト識別名
              {
                std::string object_id( api.begin()->text );
                bool valid_object_id = true;
                if ( !object_id.empty() && ( std::isalpha( static_cast< unsigned char >( object_id[ 0 ] ) ) || object_id[ 0 ] == '_' ) )
                {
                  for ( std::string::const_iterator id_iter( object_id.begin() + 1 ), id_last( object_id.end() );
                        id_iter != id_last;
                        ++id_iter )
                  {
                    if ( !( std::isalnum( static_cast< unsigned char >( *id_iter ) ) || *id_iter == '_' ) )
                    {
                      valid_object_id = false;
                    }
                  }
                }
                else
                {
                  valid_object_id = false;
                }
                if ( !valid_object_id )
                {
                  error( _( "`%1%\' is illegal object identifier" ), object_id );
                }
                else
                {
                  oss << "#define " << object_id << "\t(<>)\n";   // でたらめな字句（基本ソース文字集合のみで構成）に定義することで、誤使用を検出する
                  oss << boost::format( "\n#line %1% \"%2%\"\n" ) % ( api.line().line ) % file;
                }
              }
              for ( static_api::iterator api_iter( api.begin() ), api_last( api.end() );
                    api_iter != api_last;
                    ++api_iter )
              {
                if ( ( api_iter->symbol[0] == '.' ) || ( api_iter->symbol[0] == '+' ) )
                    // 整数定数式パラメータのみ出力
                {
                  if ( api_iter->symbol[0] == '.' )
                  {
                    oss << "const unsigned_t ";
                  }
                  else
                  {
                    oss << "const signed_t ";
                  }
                  oss << "TOPPERS_cfg_valueof_" << ( api_iter->symbol.c_str() + 1 ) << "_" << serial << " = ( " << api_iter->text << " ); ";

                  // 暫定値を設定
                  char* endptr;
                  errno = 0;
                  unsigned long value = std::strtoul( api_iter->text.c_str(), &endptr, 0 );
                  if ( errno == 0 && *endptr == '\0' )
                  {
                    api_iter->value = value;
                  }
                }
              }
            }
            else
            {
              fatal( iter.line(), _( "syntax error" ) );
            }

            ++serial;
            iter = boost::prior( iter );
          }
        }
      }

      for ( std::vector< block_t >::const_iterator iter( block_table.begin() ), last( block_table.end() );
            iter != last;
            ++iter )
      {
        oss << "\n#ifdef TOPPERS_cfg_inside_of_" << iter->id << "\n";
//        oss << boost::format( "\n#line %1% \"%2%\"\n" ) % ( txt.end() - 1 ).line().line % ( txt.end() - 1 ).line().file;
        oss << "#error missing \'}\'\n"
               "#endif\n";
      }

      // データメンバへの反映
      std::string cfg1_list_temp( oss.str() );
      std::string includes_temp( includes_oss.str() );

      cfg1_out_list_.swap( cfg1_list_temp );
      includes_.swap( includes_temp );
      static_api_array_.swap( api_array );
      block_table_.swap( block_table );
    }

    /*!
     *  \brief  cfg1_out.c の内容生成
     *  \param[in]  type  配列 cfg1_out[] の要素型。空ポインタの場合は uint32_t として扱われる。
     */
    void cfg1_out::generate( char const* type ) const
    {
      if ( type == 0 )
      {
        type = "uint32_t";
      }
      pimpl_->ofile_ << "/* cfg1_out.c */\n"
                        "#define TOPPERS_CFG1_OUT  1\n" 
                        "#include \"kernel/kernel_int.h\"\n";
      pimpl_->do_generate_includes();
      pimpl_->ofile_ << pimpl_->includes_ << '\n';

      // int128_tは故意に無視
      // int128_tに揃えると処理が重くなりすぎるため
      pimpl_->ofile_ << "\n#ifdef INT64_MAX\n"
                        "  typedef int64_t signed_t;\n"
                        "  typedef uint64_t unsigned_t;\n"
                        "#else\n"
                        "  typedef int32_t signed_t;\n"
                        "  typedef uint32_t unsigned_t;\n"
                        "#endif\n";

      pimpl_->ofile_ << "\n#include <target_cfg1_out.h>\n\n";

      pimpl_->do_generate_cfg1_def();
      pimpl_->ofile_ << pimpl_->cfg1_out_list_ << '\n';
    }

    /*!
     *  \brief  静的API配列の参照
     *  \return 内部で保持している静的API配列への参照
     */
    std::vector< static_api > const& cfg1_out::get_static_api_array() const
    {
      return pimpl_->static_api_array_;
    }

    /*!
     *  \brief  #include指令の並びを取得する
     *  \return #include指令の並び
     *
     *  このメンバ関数は、
     *  \code
     *  #include <...>
     *  #include "..."
     *  \endcode
     *  といった#include指令の並びを文字列として返す。
     */
    std::string const& cfg1_out::get_includes() const
    {
      return pimpl_->includes_;
    }

    /*!
     *  \brief  Sレコードのロード
     */
    void cfg1_out::load_srec()
    {
      std::ifstream srec_ifs( ( pimpl_->ofile_.file_name() + ".srec" ).c_str() );
      if ( !srec_ifs.is_open() )
      {
        fatal( _( "cannot open file `%1%\'" ), pimpl_->ofile_.file_name() + ".srec" );
      }
      pimpl_->srec_ = std::tr1::shared_ptr< s_record >( new s_record( srec_ifs ) );

      std::ifstream syms_ifs( ( pimpl_->ofile_.file_name() + ".syms" ).c_str() );
      if ( !syms_ifs.is_open() )
      {
        fatal( _( "cannot open file `%1%\'" ), pimpl_->ofile_.file_name() + ".syms" );
      }
      pimpl_->syms_ = std::tr1::shared_ptr< nm_symbol >( new nm_symbol( syms_ifs ) );

      nm_symbol::entry nm_entry = pimpl_->syms_->find( "TOPPERS_cfg_magic_number" );
      if ( nm_entry.type < 0 )
      {
        fatal( _( "magic number is not found in `%1%\'" ), ( pimpl_->ofile_.file_name() + ".srec/.syms" ) );
      }
      unsigned long magic[ 4 ];
      magic[ 0 ] = ( *pimpl_->srec_ )[ nm_entry.address + 0 ];
      magic[ 1 ] = ( *pimpl_->srec_ )[ nm_entry.address + 1 ];
      magic[ 2 ] = ( *pimpl_->srec_ )[ nm_entry.address + 2 ];
      magic[ 3 ] = ( *pimpl_->srec_ )[ nm_entry.address + 3 ];
      unsigned long magic_number = ( magic[ 0 ] << 24 ) | ( magic[ 1 ] << 16 ) | ( magic[ 2 ] << 8 ) | magic[ 3 ];
      if ( magic_number == 0x12345678 )
      {
        pimpl_->little_endian_ = false;
      }
      else if ( magic_number == 0x78563412 )
      {
        pimpl_->little_endian_ = true;
      }
      else
      {
        fatal( _( "magic number is not found in `%1%\'" ), ( pimpl_->ofile_.file_name() + ".srec/.syms" ) );
      }
      pimpl_->do_assign_params();
    }

    /*!
     *  \brief  "cfg1_out.srec" から読み取った情報の参照
     */
    std::tr1::shared_ptr< s_record > cfg1_out::get_srec() const
    {
      return pimpl_->srec_;
    }

    /*!
     *  \brief  "cfg1_out.syms" から読み取った情報の参照
     */
    std::tr1::shared_ptr< nm_symbol > cfg1_out::get_syms() const
    {
      return pimpl_->syms_;
    }

    cfg1_out::cfg1_def_table const* cfg1_out::get_def_table() const
    {
      return pimpl_->def_table_;
    }

    /*!
     *  \brief  カーネルオブジェクトごとに静的API情報をまとめる
     *  \return 静的API情報
     *
     *  この関数は、"tsk"や"sem"といった種別をキーとして、その種別に分類される静的API情報の連想配列を生成する。
     */
    cfg1_out::static_api_map cfg1_out::merge() const
    {
      static_api_map result;
      for ( std::vector< static_api >::const_iterator iter( pimpl_->static_api_array_.begin() ), last( pimpl_->static_api_array_.end() );
            iter != last;
            ++iter )
      {
        static_api::info const* info = iter->get_info();
        if ( info != 0 )
        {
          result[ info->type ].push_back( *iter );
        }
      }
      return result;
    }

    /*!
     *  \brief  リトルエンディアンかどうかの判定
     *  \retval     true  リトルエンディアン
     *  \retval     false ビッグエンディアン
     *  \attention  load_srec 呼び出し前は正しい結果を得られない。
     */
    bool cfg1_out::is_little_endian() const
    {
      return pimpl_->little_endian_;
    }

    /*!
     *  \brief  静的APIのパラメータにSレコードから取得した値を代入する
     */
    void cfg1_out::implementation::do_assign_params()
    {
      std::vector< toppers::itronx::static_api > temp_array;

      for ( std::vector< static_api >::size_type serial = 0, n = static_api_array_.size(); serial < n; ++serial )
      {
        toppers::itronx::static_api api( static_api_array_.at( serial ) );

        nm_symbol::entry nm_entry = syms_->find( boost::str( boost::format( "TOPPERS_cfg_static_api_%d" ) % serial ) );
        if ( nm_entry.type == -1 )
        {
          continue;
        }

        // sizeof( signed_t )
        std::size_t const sizeof_signed_t = static_cast< std::size_t >( srec_->get_value( syms_->find( "TOPPERS_cfg_sizeof_signed_t" ).address, 4, little_endian_ ) );

        for ( toppers::itronx::static_api::iterator api_iter( api.begin() ),
                                                    api_last( api.end() );
              api_iter != api_last;
              ++api_iter )
        {
          if ( ( api_iter->symbol[0] == '.' ) || ( api_iter->symbol[0] == '+' ) || ( api_iter->symbol[0] == '*' ) )
            // 整数定数式パラメータのみ値を取得
          {
//            const char* debug_str = api_iter->symbol.c_str();
            std::string symbol = boost::str( boost::format( "TOPPERS_cfg_valueof_%s_%d" ) % ( api_iter->symbol.c_str() + 1 ) % serial );
            nm_symbol::entry nm_entry = syms_->find( symbol );
            if ( nm_entry.type == -1 )
            {
              // TODO エラーメッセージ
              continue;
            }
            const std::size_t size = sizeof_signed_t;
            std::tr1::intmax_t value = srec_->get_value( nm_entry.address, size, little_endian_ );

            if ( api_iter->symbol[0] == '+' )
            {
              value = make_signed( static_cast< std::tr1::uint32_t >( value ) );
            }
            api_iter->value = value;
          }
        }
        temp_array.push_back( api );
      }
      static_api_array_.swap( temp_array );
    }

  }
}
