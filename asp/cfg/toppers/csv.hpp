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

/*!
 *  \file   toppers/csv.hpp
 *  \brief  CSV�ե����������Ϥ˴ؤ���������
 */
#ifndef TOPPERS_CSV_HPP_
#define TOPPERS_CSV_HPP_

#include <stdexcept>
#include <ostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/utility.hpp>
#include "toppers/misc.hpp"

namespace toppers
{

  class csv_error : public std::runtime_error
  {
  public:
    explicit csv_error( long line )
      : std::runtime_error( "CSV parse error" ), line_( line )
    {
    }
    long line() const
    {
      return line_;
    }
  private:
    long line_;
  };

  /*!
   *  \class  basic_csv csv.hpp "toppers/csv.hpp"
   *  \brief  CSV �ե�����β��ϥ��饹
   */
  template < typename CharT, class Traits = std::char_traits< CharT > >
    class basic_csv
  {
  public:
    typedef std::basic_string< CharT, Traits > string_type;
    typedef typename std::vector< std::vector< string_type > >::const_iterator const_iterator;
    typedef typename std::vector< std::vector< string_type > >::const_reference const_reference;
    typedef typename std::vector< std::vector< string_type > >::value_type value_type;
    typedef typename std::vector< std::vector< string_type > >::size_type size_type;

    basic_csv();
    template < class InputIterator >
      basic_csv( InputIterator first, InputIterator last )
    {
      read( first, last );
    }

    template < class InputIterator >
      void read( InputIterator first, InputIterator last )
    {
      const CharT dquo = widen< CharT >( '\"' );
      const CharT comma = widen< CharT >( ',' );
      const CharT lf = widen< CharT >( '\n' );
      enum
      {
        none,
        non_escaped,
        escape_opened,
        escape_closed
      } state = none;
      std::vector< std::vector< string_type > > records;
      std::vector< string_type > record;
      string_type field;
      long line = 1;

      record.reserve( 16 );
      field.reserve( 255 );

      while ( first != last )
      {
        CharT ch = *first;
        if ( ch == dquo )
        {
          switch ( state )
          {
          case none:
            state = escape_opened;
            break;
          case escape_opened:
            ++first;
            ch = *first;
            if ( ch == dquo ) // "" ���ä��Τǡ�" ���ɲ�
            {
              field.push_back( dquo );
            }
            else  // �Ĥ� "
            {
              state = escape_closed;
            }
            continue;   // ++first �򤳤�ʾ�¹Ԥ����ʤ�
          default:
            throw csv_error( line );
            break;
          }
        }
        else  // ch != dquo
        {
          if ( state == escape_opened )
          {
            field.push_back( ch );
          }
          else
          {
            if ( ch == comma || ch == lf )
            {
              record.push_back( field );
              field.clear();
              state = none;
              if ( ch == lf ) // ���ԡ�RFC4180 �Ǥϸ�̩�ˤ� CR-LF �ʤ���Фʤ�ʤ������Ȥꤢ���� '\n' �Ȥ����
              {
                records.push_back( record );
                record.clear();
                ++line;
              }
            }
            else
            {
              field.push_back( ch );
//              CharT const* debug_string = field.c_str();
            }
          }
        }
        ++first;
      }
      records_.swap( records );
    }
    template < class OutputIterator >
      void write( OutputIterator result ) const
    {
      const CharT dquo = widen< CharT >( '\"' );
      const CharT comma = widen< CharT >( ',' );
      const CharT lf = widen< CharT >( '\n' );

      for ( typename std::vector< std::vector< string_type > >::const_iterator r_iter( records_.begin() ), r_last( records_.end() );
            r_iter != r_last;
            ++r_iter )
      {
        for ( typename std::vector< string_type >::const_iterator f_iter( r_iter->begin() ), f_last( r_iter->end() );
              f_iter != f_last;
              ++f_iter )
        {
          std::string field;
          bool need_escape = false;

          for ( typename string_type::const_iterator s_iter( f_iter->begin() ), s_last( f_iter->end() );
                s_iter != s_last;
                ++s_iter )
          {
            CharT ch = *s_iter;
            if ( ch == dquo )
            {
              field.push_back( dquo );
              need_escape = true;
            }
            else if ( ch == comma || ch == lf )
            {
              need_escape = true;
            }
            field.push_back( ch );
          }

          if ( need_escape )
          {
            field = dquo + field + dquo;
          }
          result = std::copy( field.begin(), field.end(), result );
          if ( boost::next( f_iter ) != f_last )
          {
            *result++ = comma;
          }
        }
        *result++ = lf;
      }
    }

    const_iterator begin() const
    {
      return records_.begin();
    }
    const_iterator end() const
    {
      return records_.end();
    }
    const_reference at( size_type pos ) const
    {
      return records_.at( pos );
    }
    const_reference operator[]( size_type pos ) const
    {
      return records_[ pos ];
    }
    bool empty() const
    {
      return records_.empty();
    }
    size_type size() const
    {
      return records_.size();
    }
    void swap( basic_csv& other )
    {
      records_.swap( other.records_ );
    }
  private:
    std::vector< std::vector< string_type > > records_;
  };

  typedef basic_csv< char > csv;
  typedef basic_csv< wchar_t > wcsv;

}

#endif  // TOPPERS_CSV_HPP_
