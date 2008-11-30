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
 *  \file   toppers/c_parser.hpp
 *  \brief  ����Ū�ʥѡ�������������
 */
#ifndef TOPPERS_PARSER_HPP_
#define TOPPERS_PARSER_HPP_

#include "toppers/codeset.hpp"
#include <boost/spirit/core.hpp>
#include <boost/spirit/actor.hpp>
#include <boost/spirit/utility.hpp>
#include <boost/spirit/dynamic.hpp>

namespace toppers
{

  namespace detail
  {

    struct c_integer_suffix_parse_functor
    {
      typedef boost::spirit::nil_t result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& ) const
      {
        using namespace boost::spirit;
        int length =
                  as_lower_d
                  [
                      ch_p( 'u' ) >> !( str_p( "ll" ) | 'l' | "i8" | "i16" | "i32" | "i64" )
                    | ( str_p( "ll" ) | 'l' | "i8" | "i16" | "i32" | "i64" ) >> !ch_p( 'u' )
                  ].parse( scan ).length();
        return length;
      }
    };

    template < typename T >
    struct c_integer_constant_parse_functor
    {
      typedef T result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& result ) const
      {
        using namespace boost::spirit;
        result_t x = T( 0 );
        int length =
                  (
                    if_p( '0' ) // 16�ʤޤ���8��
                    [
                      !(
                          ( ch_p( 'x' ) | 'X' ) >> uint_parser< T, 16 >()[ assign_a( x ) ]
                        | uint_parser< T, 8 >()[ assign_a( x ) ]
                      )
                    ]
                    .else_p // 10��
                    [
                      uint_parser< T, 10 >()[ assign_a( x ) ]
                    ]
                  ).parse( scan ).length();
        result = x;
        return length;
      }
    };

    template < typename T >
    struct c_integer_parse_functor
    {
      typedef T result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& result ) const
      {
        using namespace boost::spirit;
        static functor_parser< c_integer_constant_parse_functor< T > > const c_int_const_p;
        static functor_parser< c_integer_suffix_parse_functor > const c_int_suffix_p;
        bool negative = false;
        result_t x;
        int length =
                  (
                    !sign_p[ assign_a( negative ) ] >> lexeme_d[ c_int_const_p[ assign_a( x ) ] >> !c_int_suffix_p ]
                  ).parse( scan ).length();
        result = ( negative ? -x : x );
        return length;
      }
    };

    template < int CodeSet = -1 > struct mbchar_parse_functor;

    template <>
    struct mbchar_parse_functor< ascii >
    {
      typedef boost::spirit::nil_t result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& ) const
      {
        return boost::spirit::range_p( '\x01', '\x7f' ).parse( scan ).length();
      }
    };

    template <>
    struct mbchar_parse_functor< shift_jis >
    {
      typedef boost::spirit::nil_t result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& ) const
      {
        using namespace boost::spirit;
        int length =
                (
                    range_p( '\x01', '\x7f' ) // Ⱦ�ѱѿ�������
                  | range_p( '\xa1', '\xdf' ) // Ⱦ�ѥ�������
                  | ( chset<>( "\x81-\x9f\xe0-\xef" ) >> chset<>( "\x40-\x7e\x80-\xfc" ) )  // ����
                ).parse( scan ).length();
        return length;
      }
    };

    template <>
    struct mbchar_parse_functor< euc_jp >
    {
      typedef boost::spirit::nil_t result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& ) const
      {
        using namespace boost::spirit;
        int length =
                (
                    range_p( '\x01', '\x7f' ) // Ⱦ�ѱѿ�������
                  | ( ch_p( '\x8e' ) >> range_p( '\xa1', '\xdf' ) )   // Ⱦ�ѥ�������
                  | ( !ch_p( '\x8f' ) >> range_p( '\xa1', '\xf0' ) >> range_p( '\xa1', '\xf0' ) ) // ����
                ).parse( scan ).length();
        return length;
      }
    };

    template <>
    struct mbchar_parse_functor< utf8 >
    {
      typedef boost::spirit::nil_t result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& ) const
      {
        using namespace boost::spirit;
        int length =
                (
                    range_p( '\x01', '\x7f' ) // 1�Х���
                  | ( range_p( '\xc0', '\xdf' ) >> range_p( '\x80', '\xbf' ) )  // 2�Х���
                  | ( range_p( '\xe0', '\xef' ) >> repeat_p( 2 )[ range_p( '\x80', '\xbf' ) ] ) // 3�Х���
                  | ( range_p( '\xf0', '\xf7' ) >> repeat_p( 3 )[ range_p( '\x80', '\xbf' ) ] ) // 4�Х���
                  | ( range_p( '\xf8', '\xfb' ) >> repeat_p( 4 )[ range_p( '\x80', '\xbf' ) ] ) // 5�Х���
                  | ( range_p( '\xfc', '\xfd' ) >> repeat_p( 5 )[ range_p( '\x80', '\xbf' ) ] ) // 6�Х���
                ).parse( scan ).length();
        return length;
      }
    };

    template <>
    struct mbchar_parse_functor< -1 >
    {
      typedef boost::spirit::nil_t result_t;
      explicit mbchar_parse_functor( codeset_t codeset = ascii ) : codeset_( codeset ) {}
      template < class Scanner >
      int operator()( Scanner scan, result_t& result ) const
      {
        int length;
        switch ( codeset_ )
        {
        case ascii:
          {
            static mbchar_parse_functor< ascii > f;
            length = f( scan, result );
          }
          break;
        case shift_jis:
          {
            static mbchar_parse_functor< shift_jis > f;
            length = f( scan, result );
          }
          break;
        case euc_jp:
          {
            static mbchar_parse_functor< euc_jp > f;
            length = f( scan, result );
          }
          break;
        case utf8:
          {
            static mbchar_parse_functor< utf8 > f;
            length = f( scan, result );
          }
          break;
        default:
          length = -1;
          break;
        }
        return length;
      }
      codeset_t codeset_;
    };

    struct ucn_parse_functor
    {
      typedef long result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& result ) const
      {
        using namespace boost::spirit;
        result_t x;
        int length =
                (
                  lexeme_d
                  [
                      ch_p( '\\' ) >>
                      (
                          ( 'U' >> int_parser< long, 16, 8, 8 >()[ assign_a( x ) ] )  // \Uhhhhhhhh����
                        | ( 'u' >> int_parser< long, 16, 4, 4 >()[ assign_a( x ) ] )  // \uhhhh����
                      )
                  ]
                ).parse( scan ).length();
        if ( ( x < 0xa0 && !( x == 0x24 || x == 0x40 || x == 0x60 ) )
          || ( 0xd800 <= x && x <= 0xdfff ) 
          || 0x10ffff < x ) // ���ʸ��̾�˻Ȥ��ʤ��͡�JIS X3010:2003 6.4.3��
        {
          x = -1;
        }
        result = x;
        return length;
      }
    };

    template < int CodeSet = -1 > struct c_strlit_parse_functor;

    template < int CodeSet >
    struct c_strlit_parse_functor
    {
      typedef boost::spirit::nil_t result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& result ) const
      {
        using namespace boost::spirit;
        static functor_parser< detail::mbchar_parse_functor< CodeSet > > const mbchar_p;
        static functor_parser< detail::ucn_parse_functor > const ucn_p;
        int length =
                (
                  confix_p( '\"', *( "\\\"" | mbchar_p - '\\' | ucn_p | c_escape_ch_p ), '\"' )
                ).parse( scan ).length();
        return length;
      }
    };

    template <>
    struct c_strlit_parse_functor< -1 >
    {
      typedef boost::spirit::nil_t result_t;
      explicit c_strlit_parse_functor( codeset_t codeset = ascii ) : codeset_( codeset ) {}
      template < class Scanner >
      int operator()( Scanner scan, result_t& result ) const
      {
        using namespace boost::spirit;
        mbchar_parse_functor<> const functor( codeset_ );
        functor_parser< detail::mbchar_parse_functor<> > const mbchar_p( functor );
        static functor_parser< detail::ucn_parse_functor > const ucn_p;
        int length =
                (
                  confix_p( '\"', *( "\\\"" | ( mbchar_p - ch_p( '\\' ) ) | ucn_p | c_escape_ch_p ), '\"' )
                ).parse( scan ).length();
        return length;
      }
      codeset_t codeset_;
    };

    template < int CodeSet = -1 > struct c_chlit_parse_functor;

    template < int CodeSet >
    struct c_chlit_parse_functor
    {
      typedef boost::spirit::nil_t result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& result ) const
      {
        using namespace boost::spirit;
        static functor_parser< detail::mbchar_parse_functor< CodeSet > > const mbchar_p;
        static functor_parser< detail::ucn_parse_functor > const ucn_p;
        int length =
                (
                  confix_p( '\'', +( "\\\'" | mbchar_p - '\\' | ucn_p | c_escape_ch_p ), '\'' )
                ).parse( scan ).length();
        return length;
      }
    };

    template <>
    struct c_chlit_parse_functor< -1 >
    {
      typedef boost::spirit::nil_t result_t;
      explicit c_chlit_parse_functor( codeset_t codeset = ascii ) : codeset_( codeset ) {}
      template < class Scanner >
      int operator()( Scanner scan, result_t& result ) const
      {
        using namespace boost::spirit;
        mbchar_parse_functor<> const functor( codeset_ );
        functor_parser< detail::mbchar_parse_functor<> > const mbchar_p( functor );
        static functor_parser< detail::ucn_parse_functor > const ucn_p;
        int length =
                (
                  confix_p( '\'', +( "\\\'" | mbchar_p - '\\' | ucn_p | c_escape_ch_p ), '\'' )
                ).parse( scan ).length();
        return length;
      }
      codeset_t codeset_;
    };

    extern char const* const c_keywords[];
    extern char const* const c_plus_plus_keywords[];

    struct c_identifier_parse_functor
    {
      typedef boost::spirit::nil_t result_t;
      template < class Scanner >
      int operator()( Scanner scan, result_t& result ) const
      {
        using namespace boost::spirit;
        static functor_parser< detail::ucn_parse_functor > const ucn_p;
        int length;
        typename Scanner::iterator_t const first( scan.first );

        if ( ucn_ )
        {
          length =
                (
                  lexeme_d
                  [
                    ( alpha_p | '_' | ucn_p ) >>
                   *( alnum_p | '_' | ucn_p )
                  ]
                ).parse( scan ).length();
        }
        else
        {
          length =
                (
                  lexeme_d
                  [
                     ( alpha_p | '_' ) >>
                    *( alnum_p | '_' )
                  ]
                ).parse( scan ).length();
        }
        std::string token( first, scan.first );

        for ( int i = 0; c_keywords[i] != 0; i++ )
        {
          if ( token == c_keywords[i] )
          {
            length = -1;
            break;
          }
        }
        if ( c_plus_plus_ )
        {
          for ( int i = 0; c_plus_plus_keywords[i] != 0; i++ )
          {
            if ( token == c_plus_plus_keywords[i] )
            {
              length = -1;
              break;
            }
          }
        }
        return length;
      }
      explicit c_identifier_parse_functor( bool ucn = false, bool c_plus_plus = false )
        : ucn_( ucn ), c_plus_plus_( c_plus_plus )
      {
      }

      bool ucn_;
      bool c_plus_plus_;
    };

  }

  /*!
   *  \brief  C�����������������ѡ�����
   *
   *  boost::spirit::int_parser�Ȥΰ㤤�ϡ���Ƭ���˱�����8�ʿ���16�ʿ��Ȥ��Ʋ��
   *  �������Ǥ����ޤ��������ꤹ�뤿������������������ޤ���
   */
  template < typename T >
  inline boost::spirit::functor_parser< detail::c_integer_parse_functor< T > > const c_int_parser()
  {
    return boost::spirit::functor_parser< detail::c_integer_parse_functor< T > >();
  }

  extern boost::spirit::functor_parser< detail::c_integer_parse_functor< int > > const c_int_p;
  extern boost::spirit::functor_parser< detail::c_integer_parse_functor< unsigned int > > const c_uint_p;

  /*!
   *  \brief  �ޥ���Х���ʸ���ѡ�����
   *
   *  �ƥ�ץ졼�Ȱ��� CodeSet �ǻ��ꤷ��ʸ�������ɤ���Ϥ��ޤ���
   *  ascii �ʳ�����ꤷ�����Ǥ⡢ASCII���ϰϡ�0x7f�ʲ��ˤˤ���פ��ޤ���
   *  0x00 ��ʸ����ν�ü�ȶ��̤Ǥ��ʤ����ᡢ�����оݤˤϤʤ�ޤ���
   */
  template < int CodeSet >
  inline boost::spirit::functor_parser< detail::mbchar_parse_functor< CodeSet > > const mbchar_parser()
  {
    return boost::spirit::functor_parser< detail::mbchar_parse_functor< CodeSet > >();
  }
  inline boost::spirit::functor_parser< detail::mbchar_parse_functor<> > const mbchar_parser( codeset_t codeset )
  {
    return boost::spirit::functor_parser< detail::mbchar_parse_functor<> >( detail::mbchar_parse_functor<>( codeset ) );
  }

  extern boost::spirit::functor_parser< detail::mbchar_parse_functor< ascii > > const ascii_p;
  extern boost::spirit::functor_parser< detail::mbchar_parse_functor< shift_jis > > const shift_jis_p;
  extern boost::spirit::functor_parser< detail::mbchar_parse_functor< euc_jp > > const euc_jp_p;
  extern boost::spirit::functor_parser< detail::mbchar_parse_functor< utf8 > > const utf8_p;

  /*!
   *  \brief  ���ʸ��̾�ѡ�����
   *
   *  \\u�ޤ���\\U�ǻϤޤ���ʸ��̾��Universal Character Name�ˤ���Ϥ��ޤ���
   *  \\uhhhh�ޤ���\\Uhhhhhhhh��h��16�ʿ����ˤ˹��פ��ޤ����ʤ��������η�����
   *  ���פ��Ƥ�����Ǥ⡢�������ͤϹ��ʸ��̾�Ȥ��ƻ��ѤǤ��ޤ���
   */
  inline boost::spirit::functor_parser< detail::ucn_parse_functor > const ucn_parser()
  {
    return boost::spirit::functor_parser< detail::ucn_parse_functor >();
  }

  extern boost::spirit::functor_parser< detail::ucn_parse_functor > const ucn_p;

  /*!
   *  \brief  C���������ʸ��������ѡ�����
   *
   *  ��Ű�����ǰϤޤ줿C���������ʸ�������Ϥ��ޤ���
   *  ʸ�����ʸ�������ɤ� CodeSet �ǻ��ꤷ����Τˤʤ�ޤ���
   */
  template < int CodeSet >
  inline boost::spirit::functor_parser< detail::c_strlit_parse_functor< CodeSet > > const c_strlit_parser()
  {
    return boost::spirit::functor_parser< detail::c_strlit_parse_functor< CodeSet > >();
  }

  typedef boost::spirit::functor_parser< detail::c_strlit_parse_functor<> > c_strlit_parser_t;

  /*!
   *  \brief  C���������ʸ��������ѡ�����
   *  \param  codeset ʸ����˻��Ѥ���Ƥ���ʸ��������
   *
   *  ��Ű�����ǰϤޤ줿C���������ʸ�������Ϥ��ޤ���
   */
  inline boost::spirit::functor_parser< detail::c_strlit_parse_functor<> > const c_strlit_parser( codeset_t codeset )
  {
    return boost::spirit::functor_parser< detail::c_strlit_parse_functor<> >( detail::c_strlit_parse_functor<>( codeset ) );
  }

  extern boost::spirit::functor_parser< detail::c_strlit_parse_functor< ascii > > const ascii_str_p;
  extern boost::spirit::functor_parser< detail::c_strlit_parse_functor< shift_jis > > const shift_jis_str_p;
  extern boost::spirit::functor_parser< detail::c_strlit_parse_functor< euc_jp > > const euc_jp_str_p;
  extern boost::spirit::functor_parser< detail::c_strlit_parse_functor< utf8 > > const utf8_str_p;

  /*!
   *  \brief  C���������ʸ������ѡ�����
   *
   *  ñ������ǰϤޤ줿C���������ʸ���������Ϥ��ޤ���
   *  ʸ�������ɤ� CodeSet �ǻ��ꤷ����Τˤʤ�ޤ���
   */
  template < int CodeSet >
  inline boost::spirit::functor_parser< detail::c_chlit_parse_functor< CodeSet > > const c_chlit_parser()
  {
    return boost::spirit::functor_parser< detail::c_chlit_parse_functor< CodeSet > >();
  }

  typedef boost::spirit::functor_parser< detail::c_chlit_parse_functor<> > c_chlit_parser_t;

  /*!
   *  \brief  C���������ʸ������ѡ�����
   *  \param  codeset ʸ��������
   *
   *  ñ������ǰϤޤ줿C���������ʸ���������Ϥ��ޤ���
   */
  inline boost::spirit::functor_parser< detail::c_chlit_parse_functor<> > const c_chlit_parser( codeset_t codeset )
  {
    return boost::spirit::functor_parser< detail::c_chlit_parse_functor<> >( detail::c_chlit_parse_functor<>( codeset ) );
  }

  extern boost::spirit::functor_parser< detail::c_chlit_parse_functor< ascii > > const ascii_ch_p;
  extern boost::spirit::functor_parser< detail::c_chlit_parse_functor< shift_jis > > const shift_jis_ch_p;
  extern boost::spirit::functor_parser< detail::c_chlit_parse_functor< euc_jp > > const euc_jp_ch_p;
  extern boost::spirit::functor_parser< detail::c_chlit_parse_functor< utf8 > > const utf8_ch_p;

  typedef boost::spirit::functor_parser< detail::c_identifier_parse_functor > c_ident_parser_t;

  /*!
   *  \brief  C��������μ��̻ҥѡ�����
   *  \param  ucn         ���ʸ������Ƥ������ true �����
   *  \param  c_plus_plus C++��ͽ����ػߤ������ true �����
   *
   *  C����μ��̻ҤȤ��ƻ��ѤǤ���ʸ����β��Ϥ�Ԥ��ޤ���
   *  ���̻Ҥϲ����ޤ��ϱ�ʸ���ǻϤޤꡢ�����ޤ��ϱѿ�����³���Τ���§�Ǥ�����
   *  C99�ʹߤǤϹ��ʸ��̾����ѤǤ��뤿�ᡢ���� ucn �� true ����ꤹ�뤳�Ȥǡ�
   *  ���ʸ��̾�б�����ǽ�ˤʤ�ޤ���
   *
   *  \note �����³������ͽ���̻Ҥ�Ƚ�̤ϹԤäƤ��ޤ���
   */
  inline boost::spirit::functor_parser< detail::c_identifier_parse_functor > const c_ident_parser( bool ucn = false, bool c_plus_plus = false )
  {
    return boost::spirit::functor_parser< detail::c_identifier_parse_functor >( detail::c_identifier_parse_functor( ucn, c_plus_plus ) );
  }

  extern boost::spirit::functor_parser< detail::c_identifier_parse_functor > const c_ident_p;
  extern boost::spirit::functor_parser< detail::c_identifier_parse_functor > const c99_ident_p;
  extern boost::spirit::functor_parser< detail::c_identifier_parse_functor > const c_plus_plus_ident_p;

}

#endif  // ! TOPPERS_PARSER_HPP_
