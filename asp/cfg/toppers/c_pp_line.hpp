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
 *  \file   toppers/c_pp_line.hpp
 *  \brief  \#line����˴ؤ���������
 */
#ifndef TOPPERS_C_PP_LINE_HPP_
#define TOPPERS_C_PP_LINE_HPP_

#include "toppers/text_line.hpp"
#include "toppers/c_parser.hpp"
#include "toppers/workaround.hpp"
#include <vector>
#include <functional>

namespace toppers
{

  namespace detail
  {

    //! \#line ����ι�ʸ����
    struct c_pp_line_parser : boost::spirit::grammar< c_pp_line_parser >
    {
      template < class Scanner >
      struct definition
      {
        typedef boost::spirit::rule< Scanner > rule_t;
        rule_t r;
        definition( c_pp_line_parser const& self )
        {
          using namespace boost::spirit;
          r = (
                '#' >> lexeme_d[ str_p( "line" ) >> space_p >> uint_p[ assign_a( self.line_ ) ] ] >>
                c_strlit_parser( self.codeset_ )[ assign_a( self.file_ ) ]
              )
            | (
                '#' >>
                uint_p[ assign_a( self.line_ ) ] >>
                c_strlit_parser( self.codeset_ )[ assign_a( self.file_ ) ] >>
                *anychar_p
              );
        }
        rule_t const& start() const { return r; }
      };

      c_pp_line_parser( long& line, std::string& file, codeset_t codeset = ascii )
        : line_( line ), file_( file ), codeset_( codeset )
      {
      }

      long& line_;
      std::string& file_;
      codeset_t codeset_;
    };

    //! \#pragma ����ι�ʸ����
    struct c_pp_pragma_parser : boost::spirit::grammar< c_pp_pragma_parser >
    {
      template < class Scanner >
      struct definition
      {
        typedef boost::spirit::rule< Scanner > rule_t;
        rule_t r;
        definition( c_pp_pragma_parser const& self )
        {
          using namespace boost::spirit;
          r = '#' >> lexeme_d[ str_p( "pragma" ) >> space_p >> ( +anychar_p )[ assign_a( self.parameter_ ) ] ];
        }
        rule_t const& start() const { return r; }
      };

      c_pp_pragma_parser( std::string& parameter ) : parameter_( parameter )
      {
      }
      std::string& parameter_;
    };

  }

  /*!
   *  \class  c_pp_line c_pp_line.hpp "toppers/c_pp_line.hpp"
   *  \brief  \#line�������������뤿��Υե��󥯥����饹
   *
   *  ���Υ��饹�� basic_text ���饹���Ȥ߹�碌�ƻ��Ѥ��ޤ���
   */
  template < class Container >
  class c_pp_line : public std::binary_function< Container, line_buf, void >
  {
  public:
    typedef Container conatiner;

    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  codeset ʸ�������ɻ���
     */
    explicit c_pp_line( codeset_t codeset = ascii )
      : codeset_( codeset ), pragmas_( new std::vector< line_buf > )
    {
    }
    /*!
     *  \brief  ��̱黻��
     *  \param  cont  line_buf �����ǤȤ��륳��ƥ�
     *  \param  buf   1�ԥХåե�
     */
    void operator()( conatiner& cont, line_buf& buf )
    {
      using namespace boost::spirit;
      long line;
      std::string file;
      detail::c_pp_line_parser c_pp_line_p( line, file, codeset_ );

      if ( parse( buf.buf.begin(), buf.buf.end(), c_pp_line_p, space_p ).full ) // #line����ν���
      {
        buf.line.line = line;
        assert( file.size() >= 2 );
        buf.line.file = file.substr( 1, file.size()-2 );
      }
      else
      {
        std::string param;
        detail::c_pp_pragma_parser c_pp_pragma_p( param );

        if ( parse( buf.buf.begin(), buf.buf.end(), c_pp_pragma_p, space_p ).full ) // #pragma����ν���
        {
          line_buf t( buf );
          t.buf = param;
          pragmas_->push_back( t );
        }
        else
        {
          std::string::size_type pos = buf.buf.find_first_not_of( " \t" );
          if ( pos == std::string::npos || buf.buf[pos] != '#' )
          {
            cont.push_back( buf );
          }
          ++buf.line.line;
        }
      }
      buf.buf.clear();
    }
    /*!
     *  \brief  \#pragma����ꥹ�Ȥμ���
     *  \return \#pragma����ꥹ�Ȥ��֤�
     */
    std::vector< line_buf > const& pragmas() const { return *pragmas_; }
  private:
    codeset_t codeset_;
    std::tr1::shared_ptr< std::vector< line_buf > > pragmas_;
  };

}

#endif  // ! TOPPERS_C_PP_LINE_HPP_
