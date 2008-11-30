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

/*
 *  toppers/s_record.cpp
 */
#include "toppers/s_record.hpp"
#include <istream>
#include <algorithm>
#include <cctype>
#include <cstring>

namespace toppers
{

  /*!
   *  \brief  S�쥳���ɤΥ���
   *  \param  istr  ���ϥ��ȥ꡼��
   */
  void s_record::load( std::istream& istr )
  {
    int type = -1;

    while ( istr )
    {
      std::string buf;
      std::getline( istr, buf );
      if ( buf.empty() )
      {
        break;
      }
      record rec = read_record( buf );

      // ���ޤ긷̩�ˤϽ������ʤ�
      if ( '1' <= rec.type && rec.type <= '3' )
      {
        bool done = false;
        typedef std::vector< value_type >::iterator iterator;
        for ( iterator iter( data_.begin() ), last( data_.end() ); iter != last; ++iter )
        {
          if ( rec.address == iter->first + iter->second.size() )
          {
            std::copy( rec.data.begin(), rec.data.end(), std::back_inserter( iter->second ) );
            done = true;
          }
        }
        if ( !done )
        {
          data_.push_back( value_type( rec.address, std::vector< unsigned char >( rec.data.begin(), rec.data.end() ) ) );
        }
      }
      type = rec.type;
    }

    cache_ = data_.begin();
  }

  /*!
   *  \brief  ���ꥢ�ɥ쥹�ΥХ��ȥǡ�������
   *  \param  address   ���ɥ쥹����
   *  \return address �ǻ��ꤷ�����ɥ쥹�ΥХ��ȥǡ������֤�
   */
  int s_record::operator[]( size_type address ) const
  {
    typedef std::vector< value_type >::const_iterator const_iterator;
    if ( cache_ != data_.end() )
    {
      const_iterator iter( cache_ );
      if ( iter->first <= address && address < iter->first + iter->second.size() )
      {
        return iter->second.at( address - iter->first );
      }
    }
    for ( const_iterator iter( cache_ ), last( data_.end() ); iter != last; ++iter )
    {
      if ( iter->first <= address && address < iter->first + iter->second.size() )
      {
        cache_ = iter;
        return iter->second.at( address - iter->first );
      }
    }
    for ( const_iterator iter( data_.begin() ), last( cache_ ); iter != last; ++iter )
    {
      if ( iter->first <= address && address < iter->first + iter->second.size() )
      {
        cache_ = iter;
        return iter->second.at( address - iter->first );
      }
    }
    return -1;
  }

  /*!
   *  \brief  S�쥳��������������ɤ߹���
   *  \param  base  �ɤ߹��߰��֤���Ƭ���ɥ쥹
   *  \param  size  �����ͤΥХ��ȿ�
   *  \param  little_endian ��ȥ륨��ǥ�����ʤ� true���ӥå�����ǥ�����ʤ� false �����
   *  \return �ɤ߹���������ͤ��֤�
   */
  boost::uintmax_t s_record::get_value( std::size_t base, std::size_t size, bool little_endian ) const
  {
    boost::uintmax_t value = 0;
    if ( little_endian )
    {
      for ( long j = static_cast< long >( size-1 ); j >= 0; j-- )
      {
        int t = ( *this )[ base + j ];
        if ( t < 0 )
        {
          throw data_error();
        }
        value = ( value << 8 ) | ( t & 0xff );
      }
    }
    else
    {
      for ( std::size_t j = 0; j < size; j++ )
      {
        int t = ( *this )[ base + j ];
        if ( t < 0 )
        {
          throw data_error();
        }
        value = ( value << 8 ) | ( t & 0xff );
      }
    }
    return value;
  }

  unsigned long s_record::lower_bound() const
  {
    return data_.front().first;
  }

  unsigned long s_record::upper_bound() const
  {
    return data_.back().first + data_.back().second.size();
  }

  /*!
   *  \brief  S�쥳���ɤΣ����ɤ߹���
   *  \param  rec_buf ���ԥХåե�
   *  \return �ɤ߹��߷�̤��֤�
   */
  s_record::record const s_record::read_record( std::string const& rec_buf )
  {
    std::string buf( rec_buf );

    // ������'\r'�ޤ���'\n'����α���Ƥ�������к�
    while ( std::isspace( static_cast< unsigned char >( *buf.rbegin() ) ) )
    {
      buf = buf.substr( 0, buf.size()-1 );
    }

    if ( buf.size() < 10 || buf[0] != 'S' )
    {
      throw format_error();
    }
    int ch = static_cast< unsigned char >( buf[1] );
    int address_length = 4;
    std::string::size_type size = buf.size();

    switch ( ch )
    {
    case '1':
    case '9':
      address_length = 4;
      break;
    case '2':
    case '8':
      address_length = 6;
      break;
    case '3':
    case '7':
      address_length = 8;
      break;
    default:
      if ( !std::isdigit( static_cast< unsigned char >( ch ) ) )
      {
        throw format_error();
      }
      break;
    }
    
    record rec;
    rec.type = ch;
    rec.length = xdigit_to_int( buf[2] ) << 4 | xdigit_to_int( buf[3] );
    if ( rec.length * 2u + 4 != buf.size() )
    {
      throw format_error();
    }
    rec.length -= address_length/2 + 1; // ���ɥ쥹�ȥ����å������Ĺ��������ơ��ǡ���Ĺ��ľ��

    rec.address = 0;
    int base = 4;
    for ( int i = 0; i < address_length; i++ )
    {
      rec.address = rec.address << 4 | xdigit_to_int( buf[base+i] );
    }

    base += address_length;
    rec.data.reserve( rec.length );
    for ( int i = 0; i < rec.length; i++ )
    {
      rec.data.push_back( static_cast< unsigned char >( xdigit_to_int( buf[base+i*2] ) << 4 | xdigit_to_int( buf[base+i*2+1] ) ) );
    }

    rec.checksum = xdigit_to_int( buf[size-2] ) << 4 | xdigit_to_int( buf[size-1] );

    // �����å�����Ƚ��Ͼ�ά

    return rec;
  }

  /*!
   *  \brief  ��ϻ�ʿ���������ͤؤ��Ѵ�
   *  \param  ch  ��ϻ�ʿ�����ʸ����
   *  \return ch ���б��������
   */
  int s_record::xdigit_to_int( int ch )
  {
    static char const xdigits[] = "0123456789abcdef";

    ch = std::tolower( static_cast< unsigned char >( ch ) );
    char const* s = std::strchr( xdigits, ch );
    if ( s == 0 )
    {
      return -1;
    }
    return s - xdigits;
  }

}
