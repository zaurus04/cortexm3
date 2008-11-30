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
 *  \file   toppers/cpp.hpp
 *  \brief  C�ץ�ץ��å����ص�ǽ�˴ؤ���������
 */
#ifndef TOPPERS_CPP_HPP_
#define TOPPERS_CPP_HPP_

#include "toppers/codeset.hpp"
#include <boost/utility.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/exception.hpp>

namespace toppers
{

  /*!
   *  \brief  �����Ȥν���
   *  \param[in]  first     ���ϸ�����Ƭ����
   *  \param[in]  last      ���ϸ��ν�ü���֤μ�
   *  \param[out] result    ��̤ν�����
   *  \param[in]  codeset   ʸ��������
   *  \return     ������λ��� result ����
   *
   *  C��������Υ֥�å������Ȥ�C++��������ιԥ����Ȥ�������ޤ���
   *  �ԥ����Ȥϡ������� \\ �����äƤ⼡�ιԤˤ�³���ޤ���
   */
  template < class ForwardIterator, class OutputIterator >
    OutputIterator remove_comment( ForwardIterator first, ForwardIterator last, OutputIterator result, codeset_t codeset = ascii )
  {
    enum { none, line_comment, block_comment, single_quote, double_quote } state = none;
    char prev = '\0';

    for ( ; first != last; ++first, ++result )
    {
      char c = *first;
      ForwardIterator next_iter = boost::next( first );
      char next = ( next_iter != last ? *next_iter : '\0' );

      switch ( state )
      {
      case line_comment:
        if ( c == '\n' )
        {
          state = none;
          *result = c;
        }
        break;
      case block_comment:
        if ( c == '*' && next == '/' )
        {
          state = none;
          ++first;
        }
        else if ( c == '\n' )
        {
          *result = c;
        }
        break;
      case single_quote:
        if ( c == '\\'
          && !( codeset == shift_jis && is_lead< shift_jis >( prev ) )
          && next == '\'' )   // '��\'�� �ξ��
        {
          *result++ = *first++;
        }
        else if ( c == '\'' )
        {
          state = none;
        }
        *result = *first;
        break;
      case double_quote:
        if ( c == '\\'
          && !( codeset == shift_jis && is_lead< shift_jis >( prev ) )
          && next == '\"' )   // "��\"�� �ξ��
        {
          *result++ = *first++;
        }
        else if ( c == '\"' )
        {
          state = none;
        }
        *result = *first;
        break;
      default:
        switch ( c )
        {
        case '/':   // �����ȳ��Ϥθ���
          if ( next == '*' )
          {
            state = block_comment;
            ++first;
          }
          else if ( next == '/' )
          {
            state = line_comment;
            ++first;
          }
          else
          {
            *result = *first;
          }
          break;
        case '\'':
          state = single_quote;
          *result = c;
          break;
        case '\"':
          state = double_quote;
          *result = c;
          break;
        default:
          *result = c;
          break;
        }
      }
      prev = *first;
    }
    return result;
  }

  /*!
   *  \brief  ���󥯥롼�ɥѥ���õ��
   *  \param[in]  first       õ���оݥǥ��쥯�ȥ������Ƭ����
   *  \param[in]  last        õ���оݥǥ��쥯�ȥ���ν�ü���֤μ�
   *  \param[in]  headername  õ���оݤΥإå�̾
   *  \return     õ������������Хإå��ؤ����Фޤ��ϥե�ѥ����֤������Ԥ������϶�ʸ������֤���
   */
  template < class InputIterator >
    std::string search_include_file( InputIterator first, InputIterator last, std::string const& headername )
  {
    namespace fs = boost::filesystem;
    fs::path filename( headername, fs::native );

    if ( fs::exists( filename ) && !fs::is_directory( filename ) )
    {
      return headername;
    }
    while ( first != last )
    {
      fs::path pathname = fs::path( *first, fs::native )/filename;
      if ( fs::exists( pathname ) && !fs::is_directory( pathname ) )
      {
        return pathname.native_file_string();
      }
      ++first;
    }
    return std::string();
  }

  std::string expand_quote( std::string const& str );

}

#endif  // ! TOPPERS_CPP_HPP_
