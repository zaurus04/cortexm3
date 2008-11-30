/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2007-2008 by TAKAGI Nobuhisa
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
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

    //! cfg_out ���饹�μ����ܺ�
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
            // ���κǽ�� # ������С��������������
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
     *  \brief  ���󥹥ȥ饯��
     *  \param[in]  filename    cfg1_out.c �ޤ��� cfg1_out.srec �㤷���Ϥ���������̾
     *  \param[in]  def_table   cfg1_out.c �����Ѥ�����ơ��֥�
     */
    cfg1_out::cfg1_out( std::string const& filename, cfg1_def_table const* def_table )
      : pimpl_( new implementation( filename, std::ios_base::out, def_table ) )
    {
    }

    /*!
     *  \brief  ���ԡ����󥹥ȥ饯��
     *  \param[in]  other   ���ԡ���
     */
    cfg1_out::cfg1_out( cfg1_out const& other )
      : pimpl_( other.pimpl_->do_clone() )
    {
    }

    //! �ǥ��ȥ饯��
    cfg1_out::~cfg1_out()
    {
      delete pimpl_;
      pimpl_ = 0;
    }

    /*!
     *  \brief  �����ƥॳ��ե�����졼�����ե�����Υ���
     *  \param[in]  input_file  ���ϥե�����̾
     *  \param[in]  codeset     ʸ��������
     *  \param[in]  info_map    ��ŪAPI�����Ϣ������
     */
    void cfg1_out::load_cfg( std::string const& input_file, codeset_t codeset, std::map< std::string, static_api::info > const& info_map )
    {
      return pimpl_->do_load_cfg( input_file, codeset, info_map );
    }

    //! ������
    void cfg1_out::implementation::preprocess( std::string const& input_file, codeset_t codeset, text& txt )
    {
      boost::any print_depend = global( "print-dependencies" );
      if ( !print_depend.empty() )
      {
        std::set< std::string > depend, onces;
        itronx::preprocess( input_file, txt, codeset, &depend, &onces );

        // ��¸�ط��ν��ϡ�GNU make��Ŭ����������
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
     *  \brief  �����ƥॳ��ե�����졼�����ե�����Υ��ɽ����μ���
     *  \param[in]  input_file  ���ϥե�����̾
     *  \param[in]  codeset     ʸ��������
     *  \param[in]  info_map    ��ŪAPI�����Ϣ������
     */
    void cfg1_out::implementation::do_load_cfg( std::string const& input_file, codeset_t codeset, std::map< std::string, static_api::info > const& info_map )
    {
      text txt;
      preprocess( input_file, codeset, txt );

      // �����ƥॳ��ե�����졼�����ե�����β���
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

        info = parse( iter, last, ( ch_p( '#' ) >> *( anychar_p - eol_p ) >> eol_p ) ); // ����������θ���
        if ( info.hit ) // ����������ʤ��...
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
            else if ( directive != "pragma" ) // ����ե�����졼�����������٤�#pragma����Ϥ��λ����ǤϽ����Ƥ���
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
        else // ����������ǤϤʤ�...
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
          if ( info.hit )               // CLASS or DOMAIN�֥�å����Ϥʤ��...
          {
            block_t b;
            b.type = block_type;
            b.id = id;
            b.line = iter.line();

            // �����Ƚ��
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
              // DOMAIN�ˤ�̤�б�
            }
            oss << "\n#endif\n";

            oss << "#define TOPPERS_cfg_inside_of_" << id << "\n";

            iter = boost::prior( info.stop );
          }
          else if ( *info.stop == '}' ) // �֥�å������ʤ��...
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
            if ( api.parse( iter, last, info_map, false, codeset ) )  // ��ŪAPI�ʤ��...
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

              std::string file( boost::filesystem::path( api.line().file, boost::filesystem::native ).string() ); // �ǥ��쥯�ȥ���ڻҤ� / ���ѹ�
              oss << boost::format( "\n#line %1% \"%2%\"\n" ) % api.line().line % file;
              oss << "const unsigned_t TOPPERS_cfg_static_api_" << serial << " = " << serial << ";\n";

              if ( !api.params().empty() && api.begin()->symbol[0] == '#' )   // ���֥������ȼ���̾
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
                  oss << "#define " << object_id << "\t(<>)\n";   // �Ǥ����ʻ���ʴ��ܥ�����ʸ������Τߤǹ����ˤ�������뤳�Ȥǡ�����Ѥ򸡽Ф���
                  oss << boost::format( "\n#line %1% \"%2%\"\n" ) % ( api.line().line ) % file;
                }
              }
              for ( static_api::iterator api_iter( api.begin() ), api_last( api.end() );
                    api_iter != api_last;
                    ++api_iter )
              {
                if ( ( api_iter->symbol[0] == '.' ) || ( api_iter->symbol[0] == '+' ) )
                    // ����������ѥ�᡼���Τ߽���
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

                  // �����ͤ�����
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

      // �ǡ������Фؤ�ȿ��
      std::string cfg1_list_temp( oss.str() );
      std::string includes_temp( includes_oss.str() );

      cfg1_out_list_.swap( cfg1_list_temp );
      includes_.swap( includes_temp );
      static_api_array_.swap( api_array );
      block_table_.swap( block_table );
    }

    /*!
     *  \brief  cfg1_out.c ����������
     *  \param[in]  type  ���� cfg1_out[] �����Ƿ������ݥ��󥿤ξ��� uint32_t �Ȥ��ư����롣
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

      // int128_t�ϸΰդ�̵��
      // int128_t��·����Ƚ������Ť��ʤꤹ���뤿��
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
     *  \brief  ��ŪAPI����λ���
     *  \return �������ݻ����Ƥ�����ŪAPI����ؤλ���
     */
    std::vector< static_api > const& cfg1_out::get_static_api_array() const
    {
      return pimpl_->static_api_array_;
    }

    /*!
     *  \brief  #include������¤Ӥ��������
     *  \return #include������¤�
     *
     *  ���Υ��дؿ��ϡ�
     *  \code
     *  #include <...>
     *  #include "..."
     *  \endcode
     *  �Ȥ��ä�#include������¤Ӥ�ʸ����Ȥ����֤���
     */
    std::string const& cfg1_out::get_includes() const
    {
      return pimpl_->includes_;
    }

    /*!
     *  \brief  S�쥳���ɤΥ���
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
     *  \brief  "cfg1_out.srec" �����ɤ߼�ä�����λ���
     */
    std::tr1::shared_ptr< s_record > cfg1_out::get_srec() const
    {
      return pimpl_->srec_;
    }

    /*!
     *  \brief  "cfg1_out.syms" �����ɤ߼�ä�����λ���
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
     *  \brief  �����ͥ륪�֥������Ȥ��Ȥ���ŪAPI�����ޤȤ��
     *  \return ��ŪAPI����
     *
     *  ���δؿ��ϡ�"tsk"��"sem"�Ȥ��ä����̤򥭡��Ȥ��ơ����μ��̤�ʬ�व�����ŪAPI�����Ϣ��������������롣
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
     *  \brief  ��ȥ륨��ǥ����󤫤ɤ�����Ƚ��
     *  \retval     true  ��ȥ륨��ǥ�����
     *  \retval     false �ӥå�����ǥ�����
     *  \attention  load_srec �ƤӽФ�������������̤������ʤ���
     */
    bool cfg1_out::is_little_endian() const
    {
      return pimpl_->little_endian_;
    }

    /*!
     *  \brief  ��ŪAPI�Υѥ�᡼����S�쥳���ɤ�����������ͤ���������
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
            // ����������ѥ�᡼���Τ��ͤ����
          {
//            const char* debug_str = api_iter->symbol.c_str();
            std::string symbol = boost::str( boost::format( "TOPPERS_cfg_valueof_%s_%d" ) % ( api_iter->symbol.c_str() + 1 ) % serial );
            nm_symbol::entry nm_entry = syms_->find( symbol );
            if ( nm_entry.type == -1 )
            {
              // TODO ���顼��å�����
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
