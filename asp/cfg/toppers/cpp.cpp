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
#include <cstring>
#include <stdexcept>
#include "toppers/cpp.hpp"

namespace toppers
{

  std::string expand_quote( std::string const& str )
  {
    // boost-1.35.x�к�
    std::string::size_type n = str.find_first_not_of( " \t\r\n" );
    std::string quoted( str, n );

    if ( quoted.empty() || quoted[0] != quoted[quoted.size() - 1] )
    {
      throw std::invalid_argument( "argument is not quoted" );
    }
    std::string result;
    for ( std::string::const_iterator iter( quoted.begin() + 1 ), last( quoted.end() - 1 );
          iter != last;
          ++iter )
    {
      if ( *iter == '\\' )
      {
        if ( ++iter == last )
        {
          throw std::invalid_argument( "argument is not quoted" );
        }
        char c = *iter;
        switch ( c )
        {
        case 'a':
          c = '\a';
          break;
        case 'b':
          c = '\b';
          break;
        case 'f':
          c = '\f';
          break;
        case 'n':
          c = '\n';
          break;
        case 'r':
          c = '\r';
          break;
        case 't':
          c = '\t';
          break;
        case 'v':
          c = '\v';
          break;
        case 'x':
          if ( std::isxdigit( static_cast< unsigned char >( *iter ) ) )
          {
            c = 0;
            for ( std::string::const_iterator bound( iter + 2 );
                  iter != bound && std::isxdigit( static_cast< unsigned char >( *iter ) );
                  ++iter )
            {
              c <<= 4;
              int t = std::tolower( static_cast< unsigned char >( *iter ) );
              static char const xdigits[] = "0123456789abcdef";
              c += std::strchr( xdigits, t ) - xdigits;
            }
          }
          break;
        default:
          if ( '0' <= c && c <= '7' ) // '\ooo'
          {
            c = 0;
            for ( std::string::const_iterator bound( iter + 3 );
                  iter != bound && ( '0' <= *iter && *iter <= '7' );
                  ++iter )
            {
              c = ( c << 3 ) + *iter - '0';
            }
          }
          // ���ʸ��̾��\uhhhh, \Uhhhhhhhh��̤�б�
          // ��ʸ��ɽ����<:����̤�б�
          // ��ʸ��ɽ����??/����̤�б�
          break;
        }
        result.push_back( c );
      }
      else
      {
        result.push_back( *iter );
      }
    }
    return result;
  }

}
