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
 *  \file   toppers/misc.hpp
 *  \brief  ��¿�ʥ饤�֥��Τ����������
 */
#ifndef TOPPERS_MISC_HPP_
#define TOPPERS_MISC_HPP_

#include <stdexcept>
#include <locale>
#include <iosfwd>
#include <string>
#include <algorithm>
#include <cctype>
#include <cwchar>
#include <cwctype>
#include <cstdlib>
#include "toppers/config.hpp"
#include <boost/scoped_array.hpp>

// workaround
#include <ctype.h>
#include <wctype.h>

#define TOPPERS_STRINGIFY( s )  TOPPERS_STRINGIFY_( s )
#define TOPPERS_STRINGIFY_( s ) # s

namespace toppers
{

  /*!
   *  \class  conversion_error misc.hpp "toppers/misc.hpp"
   *  \brief  �Ѵ����顼�㳰���饹
   */
  class conversion_error : public std::runtime_error
  {
  public:
    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  what  �㳰����ʸ����
     */
    explicit conversion_error( std::string const& what ) : std::runtime_error( what ) {}
  };

  /*!
   *  \brief  ���󥰥�Х���ʸ������ CharT ����¿���� wchar_t ����ʸ���ؤ��Ѵ�
   *  \param  ch  ���󥰥�Х���ʸ��
   *  \return CharT ��ʸ�����֤�
   */
  template < typename CharT >
    inline CharT widen( char ch )
  {
    return std::use_facet< std::ctype< CharT > >( std::locale() ).widen( ch );
  }

  template <>
    inline char widen< char >( char ch )
  {
    return ch;
  }

  template <>
    inline unsigned char widen< unsigned char >( char ch )
  {
    return static_cast< unsigned char >( ch );
  }

  template <>
    inline wchar_t widen< wchar_t >( char ch )
  {
#if defined( __MINGW32__ )
    wchar_t wc = wchar_t( -1 );
    if ( std::mbtowc( &wc, &ch, 1 ) < 0 )
    {
      return WEOF;
    }
    return wc;
#elif defined( __CYGWIN__ )
    return static_cast< wchar_t >( static_cast< unsigned char >( ch ) );
#else
    return static_cast< wchar_t >( std::btowc( static_cast< unsigned char >( ch ) ) );
#endif
  }

  /*!
   *  \brief  ���󥰥�Х���ʸ���󤫤� CharT ��ʸ����ؤ��Ѵ�
   *  \param  str   ���󥰥�Х���ʸ����
   *  \return CharT ��ʸ������֤�
   */
  template < typename CharT >
    std::basic_string< CharT > const widen( std::string const& str );

  template <>
    inline std::basic_string< char > const widen( std::string const& str )
  {
    return str;
  }

  template <>
    inline std::basic_string< wchar_t > const widen( std::string const& str )
  {
    boost::scoped_array< wchar_t > t( new wchar_t[str.size()+1] );
    if ( std::mbstowcs( t.get(), str.c_str(), str.size() ) == size_t( -1 ) )
    {
      static conversion_error x( "in function widen" );
      throw x;
    }
    return t.get();
  }

#undef  tolower

  /*!
   *  \brief  ��ʸ���ؤ��Ѵ�
   *  \param  ch    �Ѵ��оݤ�ʸ��
   *  \return ch ����ʸ���Ǥ�����б����뾮ʸ���򡢤���ʳ��� ch ���֤�
   */
  inline char tolower( char ch )
  {
    return static_cast< char >( std::tolower( static_cast< unsigned char >( ch ) ) );
  }

  /*!
   *  \brief  ʸ�����ʸ�����Ѵ�
   *  \param  str   �Ѵ��оݤ�ʸ��
   *  \return str �˴ޤޤ����ʸ����ʸ�����Ѵ�����ʸ������֤�
   */
  inline std::string const tolower( std::string str )
  {
    char ( *f )( char ) = &tolower;
    std::transform( str.begin(), str.end(), str.begin(), f );
    return str;
  }

  /*!
   *  \brief  �磻��ʸ�����ʸ�����Ѵ�
   *  \param  str   �Ѵ��оݤ�ʸ��
   *  \return str �˴ޤޤ����ʸ����ʸ�����Ѵ������磻��ʸ������֤�
   */
  template < class Traits, class Allocator >
    std::basic_string< wchar_t, Traits, Allocator > const tolower( std::basic_string< wchar_t, Traits, Allocator > str )
  {
  	wint_t ( *f )( wint_t ) = &towlower;
    std::transform( str.begin(), str.end(), str.begin(), f );
    return str;
  }

#undef  toupper

  /*!
   *  \brief  ��ʸ���ؤ��Ѵ�
   *  \param  ch    �Ѵ��оݤ�ʸ��
   *  \return ch ����ʸ���Ǥ�����б�������ʸ���򡢤���ʳ��� ch ���֤�
   */
  inline char toupper( char ch )
  {
    return static_cast< char >( std::toupper( static_cast< unsigned char >( ch ) ) );
  }

  /*!
   *  \brief  ʸ�������ʸ�����Ѵ�
   *  \param  str   �Ѵ��оݤ�ʸ��
   *  \return str �˴ޤޤ�뾮ʸ������ʸ�����Ѵ�����ʸ������֤�
   */
  inline std::string const toupper( std::string str )
  {
    char ( *f )( char ) = &toupper;
    std::transform( str.begin(), str.end(), str.begin(), f );
    return str;
  }

  /*!
   *  \brief  �磻��ʸ�������ʸ�����Ѵ�
   *  \param  str   �Ѵ��оݤ�ʸ��
   *  \return str �˴ޤޤ�뾮ʸ������ʸ�����Ѵ������磻��ʸ������֤�
   */
  template < class Traits, class Allocator >
    std::basic_string< wchar_t, Traits, Allocator > const toupper( std::basic_string< wchar_t, Traits, Allocator > str )
  {
  	wint_t ( *f )( wint_t ) = &towupper;
    std::transform( str.begin(), str.end(), str.begin(), f );
    return str;
  }

#undef  isspace

  /*!
   *  \brief  �������Ƚ��
   *  
   */
  inline bool isspace( char ch )
  {
    return std::isspace( static_cast< unsigned char >( ch ) ) != 0;
  }

  /*!
   *  \brief  ����ʸ���Ƕ��ڤ�줿�ꥹ�Ƚ���
   *  \param  first   ���Ϥ�����Ƭ���ǰ���
   *  \param  last    ���Ϥ��뽪ü���ǰ���+1
   *  \param  ostr    ���ϥ��ȥ꡼��
   *  \param  pred    �����Ǥ�����������ͤ��֤��Ҹ�
   *  \param  delim   ����ʸ��
   *
   *  ���δؿ��϶�� [first, last) �γ����Ǥ� pred ���Ϥ����������ͤ� delim
   *  �Ƕ��ڤä� ostr �˽��Ϥ��ޤ���\n
   *  ��ü�����Ǥθ�ˤ� delim �Ͻ��Ϥ��줺�����Ǥ����Ǥδ֤ˤΤ� delim ��
   *  ���Ϥ���ޤ���
   */
  template < class InputIterator, typename CharT, class Traits, class Pred >
    void output_list( InputIterator first, InputIterator last, std::basic_ostream< CharT, Traits >& ostr, Pred pred, CharT const* delim = 0 )
  {
    if ( delim == 0 )
    {
      static CharT const null_delim[] = { 0 };
      delim = null_delim;
    }

    for ( bool f = false; first != last; ++first )
    {
      if ( f )
      {
        ostr << delim;
      }
      ostr << pred( *first );
      f = true;
    }
  }

  template < typename CharT, class Traits, class Allocator >
    std::basic_string< CharT, Traits, Allocator > trim( std::basic_string< CharT, Traits, Allocator > const& str, std::basic_string< CharT, Traits, Allocator > const& ws )
  {
    if ( str.empty() || ws.empty() )
    {
      return str;
    }
    typename std::basic_string< CharT, Traits, Allocator >::size_type first = str.find_first_not_of( ws, 0 );
    for ( typename std::basic_string< CharT, Traits, Allocator >::size_type i = str.size() - 1; i >= 0; i-- )
    {
      if ( ws.find( str[ i ] ) == ws.npos )
      {
        return str.substr( first, i );
      }
    }
    return str.substr( first );
  }

}

#endif  // ! TOPPERS_MISC_HPP_
