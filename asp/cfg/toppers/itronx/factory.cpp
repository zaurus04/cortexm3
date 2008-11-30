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
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <boost/lexical_cast.hpp>
#include "toppers/misc.hpp"
#include "toppers/global.hpp"
#include "toppers/csv.hpp"
#include "toppers/nm_symbol.hpp"
#include "toppers/s_record.hpp"
#include "toppers/diagnostics.hpp"
#include "toppers/macro_processor.hpp"
#include "toppers/io.hpp"
#include "toppers/itronx/factory.hpp"
#include "toppers/itronx/cfg1_out.hpp"

namespace toppers
{
  namespace itronx
  {
    namespace
    {

      // �����ͥ륪�֥��������������������ŪAPI�γƥѥ�᡼����ޥ���ץ��å����ѿ��Ȥ������ꤹ�롣
      void set_object_vars( cfg1_out::static_api_map const& api_map, macro_processor& mproc )
      {
        typedef macro_processor::element element;
        typedef macro_processor::var_t var_t;
        std::map< std::string, var_t > order_list_map;
        std::map< std::string, long > id_map;

        for ( cfg1_out::static_api_map::const_iterator m_iter( api_map.begin() ), m_last( api_map.end() );
              m_iter != m_last;
              ++m_iter )
        {
          int order = 1;

          for ( std::vector< static_api >::const_iterator v_iter( m_iter->second.begin() ), v_last( m_iter->second.end() );
                v_iter != v_last;
                ++v_iter )
          {
            static_api::info const* info = v_iter->get_info();

            long id = -1;
            if ( !info->slave )
            {
              // �и��� $OBJ.ORDER$
              if ( v_iter->id().value )
              {
                id = static_cast< long >( v_iter->id().value.get() );
              }
              else
              {
                id = order;
              }
              id_map[ v_iter->id().text ] = id;
              element e;
              e.i = order;
              mproc.set_var( toppers::toupper( ( boost::format( "%s.order" ) % info->type ).str() ), id, var_t( 1, e ) );

              e.i = id;
              e.s = v_iter->id().text;
              order_list_map[ info->type ].push_back( e );
              ++order;
            }
            else
            {
              std::map< std::string, long >::iterator iter( id_map.find( v_iter->id().text ) );
              if ( iter == id_map.end() )
              {
                error( v_iter->line(), _( "E_NOEXS: `%1%\' is undefined" ), v_iter->id().text );
              }
              else
              {
                id = iter->second;
              }
            }

            // �ƥѥ�᡼��
            for ( static_api::const_iterator api_iter( v_iter->begin() ), api_last( v_iter->end() );
                  api_iter != api_last;
                  ++api_iter )
            {
              std::string name( toppers::toupper( ( boost::format( "%s.%s" ) % info->type % ( api_iter->symbol.c_str() + 1 ) ).str() ) );
              element e;
              e.s = api_iter->text;
              if ( api_iter->symbol[0] != '&' )   // ����������ѥ�᡼�����ͤ�����Ǥ��ʤ�
              {
                e.i = api_iter->value;
                if ( api_iter->symbol[0] == '%' )
                {
                  continue;
                }
              }
              mproc.set_var( name, id, var_t( 1, e ) );
            }

            // ��ŪAPI���и��������ֹ�
            {
              element e;
              e.s = v_iter->line().file;
              e.i = v_iter->line().line;
              std::string type( toppers::toupper( info->type ) );

              if ( info->slave )
              {
                type = info->api_name;
              }
              mproc.set_var( type + ".TEXT_LINE", id, var_t( 1, e ) );
            }
          }
        }

        std::map< std::string, var_t > id_list_map;

        for ( std::map< std::string, var_t >::const_iterator iter( order_list_map.begin() ), last( order_list_map.end() );
              iter != last;
              ++iter )
        {
          // �и���ꥹ�� $OBJ.ORDER_LIST$ -- ID�ֹ���¤�
          mproc.set_var( toppers::toupper( iter->first + ".order_list" ), iter->second );
          var_t rorder_list( iter->second );

          // �ս�ꥹ�� $OBJ.RORDER_LIST$ -- ID�ֹ���¤�
          std::reverse( rorder_list.begin(), rorder_list.end() );
          mproc.set_var( toppers::toupper( iter->first + ".rorder_list" ), rorder_list );

          // ID�ֹ�ꥹ�� $OBJ.ID_LIST$ -- ID�ֹ���¤�
          var_t id_list( iter->second );
          std::sort( id_list.begin(), id_list.end() );
          mproc.set_var( toppers::toupper( iter->first + ".id_list" ), id_list );
        }

        element external_id;
        external_id.i = boost::any_cast< bool >( global( "external-id" ) );
        mproc.set_var( "USE_EXTERNAL_ID", var_t( 1, external_id ) );
      }

      // �ץ�åȥե����ࡦ����ѥ����¸���ͤ�ޥ���ץ��å����ѿ��Ȥ������ꤹ�롣
      void set_platform_vars( cfg1_out const& cfg1out, macro_processor& mproc )
      {
        typedef macro_processor::element element;
        typedef macro_processor::var_t var_t;

        cfg1_out::cfg1_def_table const* def_table = cfg1out.get_def_table();
        std::size_t sizeof_signed_t;

        static cfg1_out::cfg1_def_t const limit_defs[] =
        {
          { false, "TOPPERS_cfg_CHAR_BIT",  "CHAR_BIT" },
          { false, "TOPPERS_cfg_CHAR_MAX",  "CHAR_MAX" },
          { true, "TOPPERS_cfg_CHAR_MIN",  "CHAR_MIN" },
          { false, "TOPPERS_cfg_SCHAR_MAX", "SCHAR_MAX" },  // ���������դ���������ˤʤ뤳�ȤϤʤ�
          { false, "TOPPERS_cfg_SHRT_MAX",  "SHRT_MAX" },   // ���������դ���������ˤʤ뤳�ȤϤʤ�
          { false, "TOPPERS_cfg_INT_MAX",   "INT_MAX" },    // ���������դ���������ˤʤ뤳�ȤϤʤ�
          { false, "TOPPERS_cfg_LONG_MAX",  "LONG_MAX" },   // ���������դ���������ˤʤ뤳�ȤϤʤ�
        };

        nm_symbol::entry nm_entry = cfg1out.get_syms()->find( "TOPPERS_cfg_sizeof_signed_t" );
        sizeof_signed_t = static_cast< std::size_t >( cfg1out.get_srec()->get_value( nm_entry.address, 4, cfg1out.is_little_endian() ) );

        for ( std::size_t i = 0; i < sizeof limit_defs / sizeof limit_defs[ 0 ]; ++i )
        {
          element e;
          e.s = limit_defs[ i ].expression;
          nm_entry = cfg1out.get_syms()->find( limit_defs[ i ].name );
          std::tr1::int64_t value = cfg1out.get_srec()->get_value( nm_entry.address, sizeof_signed_t, cfg1out.is_little_endian() );
          if ( sizeof_signed_t < 8 && limit_defs[ i ].is_signed )
          {
            value = cfg1_out::make_signed( static_cast< std::tr1::uint32_t >( value ) );
          }
          mproc.set_var( e.s, var_t( 1, e ) );
        }

        for ( cfg1_out::cfg1_def_table::const_iterator iter( def_table->begin() ), last( def_table->end() );
              iter != last;
              ++iter )
        {
          element e;
          e.s = iter->expression;
          nm_entry = cfg1out.get_syms()->find( "TOPPERS_cfg_" + iter->name );
          if ( nm_entry.type >= 0 )
          {
            std::tr1::int64_t value = cfg1out.get_srec()->get_value( nm_entry.address, sizeof_signed_t, cfg1out.is_little_endian() );
            if ( sizeof_signed_t < 8 && iter->is_signed )
            {
              value = cfg1_out::make_signed( static_cast< std::tr1::uint32_t >( value ) );
            }
            e.i = value;
            mproc.set_var( iter->name, var_t( 1, e ) );
          }
        }

        // �Х��ȥ�������
        {
          bool little_endian = cfg1out.is_little_endian();
          element e;
          e.i = little_endian;
          mproc.set_var( "LITTLE_ENDIAN", var_t( 1, e ) );

          e.i = !little_endian;
          mproc.set_var( "BIG_ENDIAN", var_t( 1, e ) );
        }
      }

    }

    //! ���󥹥ȥ饯��
    factory::factory( std::string const& kernel )
      : kernel_( tolower( kernel ) )
    {
    }

    //! �ǥ��ȥ饯��
    factory::~factory()
    {
    }

    //! ���ݡ��Ȥ��Ƥ�����ŪAPI����μ���
    std::map< std::string, static_api::info > const* factory::get_static_api_info_map() const
    {
      // CSV������ŪAPI������ɤ߼�ꡢ��Ͽ���뤿��Υ����륯�饹
      struct init_t
      {
        init_t()
        {
          boost::any t = global( "api-table" );
          if ( !t.empty() )
          {
            std::vector< std::string > api_tables( boost::any_cast< std::vector< std::string >& >( t ) );
            for ( std::vector< std::string >::const_iterator iter( api_tables.begin() ), last( api_tables.end() );
                  iter != last;
                  ++iter )
            {
              std::string buf;
              read( iter->c_str(), buf );
              csv data( buf.begin(), buf.end() );
              for ( csv::const_iterator d_iter( data.begin() ), d_last( data.end() );
                    d_iter != d_last;
                    ++d_iter )
              {
                csv::size_type len = d_iter->size();
                if ( len < 3 )  // type, api_name, params ��ɬ������
                {
                  toppers::fatal( _( "too little fields in `%1%\'" ), *iter );
                }
                static_api::info api_info = { 0 };
                try
                {
                    char* s;
                    s = new char[ ( *d_iter )[ 0 ].size() + 1 ];
                    std::strcpy( s, ( *d_iter )[ 0 ].c_str() );
                    api_info.type = s;

                    s = new char[ ( *d_iter )[ 1 ].size() + 1 ];
                    std::strcpy( s, ( *d_iter )[ 1 ].c_str() );
                    api_info.api_name = s;

                    s = new char[ ( *d_iter )[ 2 ].size() + 1 ];
                    std::strcpy( s, ( *d_iter )[ 2 ].c_str() );
                    api_info.params = s;
                    if ( len >= 4 && !( *d_iter )[ 3 ].empty() )
                    {
                      api_info.id_pos = std::strtol( ( *d_iter )[ 3 ].c_str(), 0, 0 );
                    }
                    if ( len >= 5 && !( *d_iter )[ 4 ].empty() )
                    {
                      api_info.slave = !!std::strtol( ( *d_iter )[ 4 ].c_str(), 0, 0 );
                    }
                    static_api_table_[ api_info.api_name ] = api_info;
                }
                catch ( ... )
                {
                  delete[] api_info.type;
                  delete[] api_info.api_name;
                  delete[] api_info.params;
                  throw;
                }
              }
            }
          }
        }

        ~init_t()
        {
          for ( std::map< std::string, static_api::info >::const_iterator iter( static_api_table_.begin() ), last( static_api_table_.end() );
                iter != last;
                ++iter )
          {
            delete[] iter->second.type;
            delete[] iter->second.api_name;
            delete[] iter->second.params;
          }
        }

        std::map< std::string, static_api::info > static_api_table_;
      };
      static init_t init;
      std::map< std::string, static_api::info > const* result = &init.static_api_table_;
      return result;
    }

    /*!
     * \brief   cfg1_out.c �ؤν��Ͼ���ơ��֥������
     * \return  �������� cfg1_out::cfg1_def_table ���֥������ȤؤΥݥ���
     * \note    ���δؿ����֤��ݥ��󥿤� delete ���ƤϤʤ�ʤ�
     *
     * --cfg1-def-table ���ץ����ǻ��ꤷ���ե����뤫�顢cfg1_out.c �ؽ��Ϥ��������ɤ߼�ꡢ
     * cfg1_out::cfg1_def_table ���֥������Ȥ��������롣
     *
     * CSV �η����ϰʲ����̤�
     *
     *    ����ܥ�̾,��[,s|signed]
     *
     * ������ s �ޤ��� signed �Ͼ�ά��ǽ����ά�������̵�������Ȥߤʤ���s �ޤ��� signed �������
     * ����դ������Ȥߤʤ���\n
     * �ּ��פκǽ�� # ����������������Ȥߤʤ���
     */
    cfg1_out::cfg1_def_table const* factory::get_cfg1_def_table() const
    {
      struct init_t
      {
        init_t()
        {
          boost::any t = global( "cfg1-def-table" );
          if ( !t.empty() )
          {
            std::vector< std::string > cfg1_def_table = boost::any_cast< std::vector< std::string >& >( t );
            for ( std::vector< std::string >::const_iterator iter( cfg1_def_table.begin() ), last( cfg1_def_table.end() );
                  iter != last;
                  ++iter )
            {
              std::string buf;
              read( iter->c_str(), buf );
              csv data( buf.begin(), buf.end() );
              for ( csv::const_iterator d_iter( data.begin() ), d_last( data.end() );
                    d_iter != d_last;
                    ++d_iter )
              {
                csv::size_type len = d_iter->size();
                if ( len < 2 )
                {
                  toppers::fatal( _( "too little fields in `%1%\'" ), *iter );
                }
                cfg1_out::cfg1_def_t def = { 0 };
                def.name = ( *d_iter )[ 0 ];
                def.expression = ( *d_iter )[ 1 ];
                if ( len >= 3 )
                {
                  std::string is_signed( ( *d_iter )[ 2 ] );
                  def.is_signed = ( is_signed == "s" || is_signed == "signed" );
                }
                cfg1_def_table_.push_back( def );
              }
            }
          }
        }
        cfg1_out::cfg1_def_table cfg1_def_table_;
      };
      static init_t init;
      cfg1_out::cfg1_def_table const* result = &init.cfg1_def_table_;
      return result;
    }

    //! ���֥������Ȥθ�
    void factory::do_swap( factory& other )
    {
      kernel_.swap( other.kernel_ );
    }

    macro_processor::hook_t factory::do_get_hook_on_assign() const
    {
//      return &hook_on_assign;
      return 0;
    }

    /*!
     *  \brief  �ޥ���ץ��å�������
     *  \param[in]  hook    �ѿ����ͤ����������ݤΥեå�����
     *  \param[in]  cfg1out cfg1_out ���֥�������
     *  \param[in]  api_map .cfg �ե�����˵��Ҥ��줿��ŪAPI����
     *  \return     �ޥ���ץ��å��ؤΥݥ���
     */
    std::auto_ptr< macro_processor > factory::do_create_macro_processor( macro_processor::hook_t hook, cfg1_out const& cfg1out, cfg1_out::static_api_map const& api_map ) const
    {
      typedef macro_processor::element element;
      typedef macro_processor::var_t var_t;
      std::auto_ptr< macro_processor > mproc( new macro_processor( hook ) );
      element e;

      e.s = " ";    mproc->set_var( "SPC", var_t( 1, e ) );  // $SPC$
      e.s = "\t";   mproc->set_var( "TAB", var_t( 1, e ) );  // $TAB$
      e.s = "\n";   mproc->set_var( "NL",  var_t( 1, e ) );  // $NL$
        
      set_object_vars( api_map, *mproc );
      set_platform_vars( cfg1out, *mproc );
      e.s = cfg1out.get_includes();
      mproc->set_var( "INCLUDES", var_t( 1, e ) );
      return mproc;
    }

    std::auto_ptr< cfg1_out > factory::do_create_cfg1_out( std::string const& filename ) const
    {
      return std::auto_ptr< itronx::cfg1_out >( new cfg1_out( filename, get_cfg1_def_table() ) );
    }

    std::auto_ptr< checker > factory::do_create_checker() const
    {
      return std::auto_ptr< itronx::checker >( new checker );
    }

  }
}
