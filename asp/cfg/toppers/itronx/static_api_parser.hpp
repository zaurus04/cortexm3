/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2005-2008 by TAKAGI Nobuhisa
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

/*!
 *  \file   toppers/itronx/static_api_parser.hpp
 *  \brief  ��ŪAPI��ʸˡ�˴ؤ���������
 *
 *  ���Υե�������������륯�饹
 *  \code
 *  struct static_api_parser;
 *  struct static_api_parser::error_handler;
 *  struct static_api_parser::definition< Scanner >;
 *  \endcode
 */
#ifndef TOPPERS_ITRONX_STATIC_API_PARSER_HPP_
#define TOPPERS_ITRONX_STATIC_API_PARSER_HPP_

#include "toppers/diagnostics.hpp"
#include "toppers/c_expr.hpp"
#include <boost/spirit/error_handling.hpp>

namespace toppers
{
  namespace itronx
  {

    /*!
     *  \struct static_api_parser static_api_parser.hpp "toppers/itronx/static_api_parser.hpp"
     *  \brief  ��ŪAPI�ι�ʸ���ϥ��饹
     */
    struct static_api_parser : boost::spirit::grammar< static_api_parser >
    {
      enum rule_id_t
      {
        id_top = 1, id_api_name, id_parameter_list, id_parameter, id_packet, id_cexpr
      };
      enum expected_t
      {
        open_paren_expected, close_paren_expected, open_brace_expected, close_brace_expected,
        comma_expected, semicolon_expected
      };

      /*!
       *  \struct error_handler static_api_parser.hpp "toppers/itronx/static_api_parser.hpp"
       *  \brief  ��ŪAPI�ι�ʸ���Ϥˤ����륨�顼�����ե��󥯥�
       */
      struct error_handler
      {
        template < class Scanner, class Error >
          boost::spirit::error_status<> operator()( Scanner const& scan, Error const& error ) const
        {
          typename Error::iterator_t iter( error.where );
          while ( *iter != '\0' && *iter != '\n' )
          {
            ++iter;
          }
          std::string str( error.where, iter );
          str = '\"' + str + '\"';

          text_line ln( get_text_line( error.where ) );
          switch ( error.descriptor )
          {
          case open_paren_expected:
            toppers::fatal( ln, _( "missing `%1%\' before %2%" ), '(', str );
            break;
          case close_paren_expected:
            toppers::fatal( ln, _( "missing `%1%\' before %2%" ), ')', str );
            break;
          case close_brace_expected:
            toppers::fatal( ln, _( "missing `%1%\' before %2%" ), '}', str );
            break;
          case semicolon_expected:
            toppers::fatal( ln, _( "missing `%1%\' before %2%" ), ';', str );
            break;
          }
          return  boost::spirit::error_status<>( boost::spirit::error_status<>::fail );
        }
      };

      /*!
       *  \struct definition static_api_parser.hpp "toppers/itronx/static_api_parser.hpp" 
       *  \brief  ��ŪAPI�ι�ʸ���Ϥˤ�����ʸˡ���
       */
      template < class Scanner >
        struct definition
      {
        typedef boost::spirit::rule< Scanner, boost::spirit::dynamic_parser_tag > rule_t;
        typedef boost::spirit::guard< expected_t > guard_t;
        typedef boost::spirit::assertion< expected_t > assertion_t;

        c_strlit_parser_t const c_strlit_p;
        c_ident_parser_t const c_ident_p;

        rule_t  top, api_name, parameter_list, parameter, packet, cexpr;
        guard_t guard_api, guard_packet;
        assertion_t expect_open_paren,
                    expect_close_paren,
                    expect_close_brace,
                    expect_comma, expect_semicolon;

        /*!
         *  \brief  ���󥹥ȥ饯��
         *  \param  self  ��ʸ���ϥ��饹��ʸˡ���饹�ˤؤλ���
         */
        definition( static_api_parser const& self )
          : c_strlit_p( c_strlit_parser( self.cexpr_p_.codeset_ ) ),
            c_ident_p( c_ident_parser( self.cexpr_p_.ucn_, self.cexpr_p_.c_plus_plus_ ) ),
            expect_open_paren( open_paren_expected ),
            expect_close_paren( close_paren_expected ),
            expect_close_brace( close_brace_expected ),
            expect_comma( comma_expected ),
            expect_semicolon( semicolon_expected )
        {
          using namespace boost::spirit;
          set_id();
          top =
              guard_api
              (
                api_name >> 
                  str_p( "(" ) >>
                  !parameter_list >>
                  expect_close_paren( str_p( ")" ) ) >>
                  expect_semicolon( ch_p( ';' ) )
              )
              [
                error_handler()
              ];
          api_name =
              c_ident_p[ push_back_a( self.tokens_ ) ];
          parameter_list =
              parameter % ',';
          parameter =
              packet | cexpr;
          packet =
              guard_packet
              (
                str_p( "{" )[ push_back_a( self.tokens_ ) ] >>
                parameter_list >>
                expect_close_brace( str_p( "}" )[ push_back_a( self.tokens_ ) ] ) 
              )
              [
                error_handler()
              ];
          cexpr =
              self.cexpr_p_[ push_back_a( self.tokens_ ) ];
        }
        void set_id()
        {
          top.set_id( id_top );
          api_name.set_id( id_api_name );
          parameter_list.set_id( id_parameter_list );
          parameter.set_id( id_parameter );
          packet.set_id( id_packet );
          cexpr.set_id( id_cexpr );
        }
        rule_t const& start() const { return top; }
      };
      /*!
       *  \brief  ���󥹥ȥ饯��
       *  \param  tokens  ��ŪAPI�ι����ȡ�����γ�Ǽ��
       *  \param  cexpr_p C������������ʸ���ϴؿ����֥�������
       */
      explicit static_api_parser( std::vector< std::string >& tokens, c_const_expr_parser const& cexpr_p )
        : tokens_( tokens ), cexpr_p_( cexpr_p )
      {
      }

      std::vector< std::string >& tokens_;
      c_const_expr_parser const& cexpr_p_;
    };

  }
}

#endif  // ! TOPPERS_ITRONX_STATIC_API_PARSER_HPP_
