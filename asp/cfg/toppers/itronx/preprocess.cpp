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
#include <algorithm>
#include <iostream>
#include <iterator>
#include "toppers/io.hpp"
#include "toppers/cpp.hpp"
#include "toppers/global.hpp"
#include "toppers/diagnostics.hpp"
#include "toppers/itronx/preprocess.hpp"
#include <boost/spirit.hpp>

namespace toppers
{
  namespace itronx
  {

    /*!
     *  \brief  ��ŪAPI `INCLUDE'��Ÿ��
     *  \param[in]  in      ���ϥե����������
     *  \param[out] out     ���ϥե����������
     *  \param[in]  codeset ʸ��������
     *  \param[out] dependencies  ��¸�ط��γ�Ǽ���NULL�ξ��ϳ�Ǽ���ʤ���
     *  \param[out] onces   #pragma once�����Ҥ���Ƥ����ե�����̾�γ�Ǽ���NULL�ξ��ϳ�Ǽ���ʤ���
     *
     *  `INCLUDE' �ΰ����ϡ���ITRON ���ͤΤ�ΤȤϰۤʤꡢ��Ű�����ǰϤޤ��� #include �����
     *  Ʊ���������Ѥ��롣
     */
    void expand_include( text const& in, text& out, codeset_t codeset, std::set< std::string >* dependencies, std::set< std::string >* onces )
    {
      typedef text::container::const_iterator const_row_iterator;
      typedef std::string::size_type size_type;
      size_type const npos = std::string::npos;
      const_row_iterator first( in.begin().get_row() ), last( in.end().get_row() );

      out.set_line( first->line.file, first->line.line );
      for ( const_row_iterator iter( first ); iter != last; ++iter )
      {
        std::string const& buf = iter->buf;
        char state = 0;

        for ( size_type i = 0, n = buf.size(); i != n; ++i )
        {
          char c = buf[i];
          if ( c == '\'' || c == '\"' )
          {
            if ( state == 0 )
            {
              state = c;    // ʸ������˥�ƥ�볫��
            }
            else if ( buf[i - 1] != '\\' ) //  \' �ޤ��� \" �ǤϤʤ�
            {
              state = 0;    // ʸ������˥�ƥ�뽪λ
            }
            else if ( ( codeset == shift_jis ) && ( i >= 2 ) && is_lead< shift_jis >( buf[i - 2] ) )
            {
              state = 0;
            }
            out.push_back( c );
          }
          else if ( state != 0 )  // ʸ������˥�ƥ����
          {
            out.push_back( c );
          }
          else
          {
            using namespace boost::spirit;
            std::string headername;
            if ( iter == last )
            {
              return;
            }
            text::const_iterator iter2( iter, i );
            if ( iter2 == in.end() )
            {
              break;
            }
            parse_info< text::const_iterator > info
              = parse( iter2, in.end(),
                        ( str_p( "INCLUDE" ) >> *space_p
                          >> '(' >> *space_p
                            >> '\"' >> ( +( anychar_p - '\"' ) )[ assign( headername ) ] >> '\"' >> *space_p
                          >> ')' >> *space_p >> ';' ) );  // ���ֹ椬�����Τǡ������åץѡ����ϻ��Ѥ��ʤ�
            if ( info.hit )
            {
              std::vector< std::string > include_paths = boost::any_cast< std::vector< std::string >& >( global( "include-path" ) );
              std::string hname = search_include_file( include_paths.begin(), include_paths.end(), headername );
              if ( hname.empty() )  // �إå�̾�����Ĥ���ʤ�
              {
                error( iter->line, _( "cannot open file `%1%\'" ), headername );
              }
              else if ( onces == 0 || onces->find( hname ) == onces->end() )
              {
                if ( dependencies != 0 )
                {
                  dependencies->insert( hname );
                }
                out.push_back( ' ' ); // ���ߡ����������Ƥ����ʤ��ȹ��ֹ椬�����
                preprocess( hname, out, codeset, dependencies, onces );  // �إå�̾�ǻ��ꤵ�줿�ե�������Ф�����������Ƶ�Ū�˹Ԥ�
                iter = info.stop.get_row();
                i = info.stop.get_col() - 1;
                if ( iter != last )
                {
                  out.set_line( iter->line.file, iter->line.line );
                }
              }
            }
            else
            {
              if ( iter2.get_col() == 0 )
              {
                info = parse( iter2, in.end(),
                              ( *( space_p - eol_p ) >>
                                  ch_p( '#' ) >> *space_p >> "pragma" >> *space_p
                                    >> "once"
                                    >> *( space_p - eol_p ) >> eol_p ) );
                if ( info.hit )
                {
                  if ( onces != 0 )
                  {
                    onces->insert( iter2.line().file );
                  }
                  out.push_back( ' ' );
                  iter = info.stop.get_row();
                  if ( iter != last )
                  {
                    out.set_line( iter->line.file, iter->line.line );
                  }
                  --iter;   // ���󥯥���Ȥ����ΤǤ��ä����᤹��
                  break;
                }
              }
              if ( parse( iter2, in.end(),
                        ( str_p( "INCLUDE" ) >> *space_p >> '(' >> +( anychar_p - ')' ) >> ')' >> *space_p >> ';' ) ).hit )
              {
                warning( iter->line, _( "probably, %1% argument of `%2%\' is illegal" ), _( "1st" ), "INCLUDE" );
              }
              out.push_back( c );
            }
          }
        }
      }
    }

    /*!
     *  \brief  ����ե�����졼�����ե������������
     *  \param[in]  file    ����ե�����졼�����ե�����̾
     *  \param[out] result  �������������
     *  \param[in]  codeset ʸ��������
     *  \param[out] dependencies  ��¸�ط��γ�Ǽ���NULL�ξ��ϳ�Ǽ���ʤ���
     *  \param[out] onces   #pragma once�����Ҥ���Ƥ����ե�����̾�γ�Ǽ���NULL�ξ��ϳ�Ǽ���ʤ���
     */
    void preprocess( std::string const& file, text& result, codeset_t codeset, std::set< std::string >* dependencies, std::set< std::string >* onces )
    {
      std::string buf;
      read( file, buf );
      if ( buf.empty() )
      {
        return;
      }
      text txt;
      txt.set_line( file, 1 );
      remove_comment( buf.begin(), buf.end(), std::back_inserter( txt ), codeset );
      expand_include( txt, result, codeset, dependencies, onces );
    }

  }
}
