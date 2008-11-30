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
#include <cctype>
#include <sstream>
#include "toppers/diagnostics.hpp"
#include "toppers/itronx/static_api.hpp"
#include "toppers/itronx/static_api_parser.hpp"
#include <boost/spirit.hpp>

namespace toppers
{
  namespace itronx
  {
    namespace
    {
      class find_api_predicate
      {
      public:
        explicit find_api_predicate( std::string const& api_name ) : api_name_( api_name ) {}
        bool operator()( static_api::info const& info ) const
        {
          return info.api_name == api_name_;
        }
      private:
        std::string api_name_;
      };
    }

    /*!
     *  \brief  ��ŪAPI�ι�ʸ����
     *  \param[in,out]  next      �ƥ����Ȥ��ɤ߹��߰��֡���ʸ���ϸ�μ����ɤ߹��߰��֤γ�Ǽ��
     *  \param[in]      last      �ƥ����Ȥν�ü����
     *  \param[in]      info_map  ��ŪAPI����ޥå�
     *  \param[in]      ucn       ���ʸ��̾��ͭ���ˤ������ true ����ꤹ�롣
     *  \param[in]      codeset   ʸ��������
     *  \retval         true    ����
     *  \retval         false   ����
     */
    bool static_api::parse( text::const_iterator& next, text::const_iterator last,
                            std::map< std::string, info > const& info_map,
                            bool ucn, codeset_t codeset )
    {
      boost::spirit::parse_info< text::const_iterator > pi;
      std::vector< std::string > tokens;
      c_const_expr_parser cexpr_p( ucn, codeset );
      static_api_parser parser( tokens, cexpr_p );
      static_api temp;

      text::const_iterator next_temp;
      for ( next_temp = next; next_temp != last; ++next_temp )
      {
        if ( !std::isspace( static_cast< unsigned char >( *next_temp ) ) )
        {
          break;
        }
      }
      if ( next_temp == last )
      {
        return false;
      }

      // ���顼��å������Ѥι��ֹ�
      // ���ι��ֹ�ϡ���ŪAPI�γ��ϰ��֤Τ�ΤǤ��뤿�ᡢ���顼ȯ���սꤽ�Τ�Υ��Х��ؤ����ȤϤǤ��ʤ���
      temp.line_ = next_temp.line();

      pi = boost::spirit::parse( next_temp, last, parser, boost::spirit::space_p );
      if ( !pi.hit )
      {
        return false;
      }

      // ��ŪAPI��¸�ߤ��뤫�ɤ�����Ƚ�ꤪ��ӥ����˥���μ���
      std::string api_name( tokens.front() );
      std::map< std::string, info >::const_iterator info_iter = info_map.find( api_name );
      info const* pinfo = 0;
      if ( info_iter != info_map.end() )
      {
        pinfo = &info_iter->second;
        temp.pinfo_ = pinfo;
      }
      else
      {
        error( temp.line_, _( "static API `%1%\' is unknown" ), api_name );
        return false;
      }

      // �ƥѥ�᡼���β���
      std::istringstream iss( pinfo->params );
      for ( std::vector< std::string >::const_iterator iter( tokens.begin() + 1 ), last( tokens.end() );
            iter != last;
            ++iter )
      {
        std::string symbol;
        iss >> symbol;
        if ( symbol == "{" || symbol == "}" )
        {
          // TODO ��ά��ǽ�ѥ�᡼���Υ����åפϤ����ǹԤ�

          if ( symbol != *iter )
          {
            error( temp.line_, _( "missing token `%1%\'" ), symbol );
            --iter;
          }
        }
        else if ( *iter == "{" || *iter == "}" )
        {
          error( temp.line_, _( "illegal token `%1%\'" ), *iter );
        }
        else
        {
          parameter value;
          value.symbol = symbol;
          value.text = *iter;
          value.value = 0;
          temp.params_.push_back( value );
        }
      }
      next = pi.stop;
      swap( temp );
      return true;
    }

    bool static_api::set_block( char const* type, std::string const& id )
    {
      for ( std::vector< parameter >::const_iterator iter( params_.begin() ), last( params_.end() );
            iter != last;
            ++iter )
      {
        if ( iter->symbol == type )
        {
          return false;
        }
      }
      parameter value;
      value.symbol = type;
      value.text = id;
      value.value = 0;
      params_.push_back( value );
      return true;
    }

    static_api::size_type static_api::count_integer_params() const
    {
      size_type result = 0;
      for ( std::vector< parameter >::const_iterator iter( params_.begin() ), last( params_.end() );
            iter != last;
            ++iter )
      {
        if ( !iter->symbol.empty()
          && ( ( iter->symbol[0] == '.' ) || ( iter->symbol[0] == '+' ) ) )
        {
          ++result;
        }
      }
      return result;
    }

  }
}
