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
 *  \file   toppers/text_line.hpp
 *  \brief  �ƥ����ȥǡ����ιԤ˴ؤ���������
 *
 *  ���Υե�������������륯�饹
 *  \code
 *  struct text_line;
 *  struct basic_line_buf< CharT, Traits, Allocator >;
 *  \endcode
 */
#ifndef TOPPERS_TEXTLINE_HPP_
#define TOPPERS_TEXTLINE_HPP_

#include <iosfwd>
#include <string>
#include <algorithm>
#include "toppers/config.hpp"

namespace toppers
{

  /*!
   *  \struct text_line text_line.hpp "toppers/text_line.hpp"
   *  \brief  �ե�����̾�ȹ��ֹ���ݻ����饹
   */
  struct text_line
  {
    std::string file;   //!< �ե�����̾
    long line;          //!< ���ֹ��1����

    /*!
     *  \brief  �ǥե���ȥ��󥹥ȥ饯��
     */
    text_line()
      : line( 0 )
    {
    }
    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  filename  �ե�����̾
     *  \param  lineno    ���ֹ�
     */
    explicit text_line( std::string const& filename, long lineno = 0 )
      : file( filename ), line( lineno )
    {
    }
    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  filename  �ե�����̾
     *  \param  lineno    ���ֹ�
     */
    explicit text_line( char const* filename, long lineno = 0 )
      : file( filename ), line( lineno )
    {
    }
    /*!
     *  \brief  ���֥������Ȥθ�
     *  \param  other   ���оݤΥ��֥�������
     */
    void swap( text_line& other ) throw()
    {
      std::swap( line, other.line );
      file.swap( other.file );
    }
  };

  /*!
   *  \struct line_buf text_line.hpp "toppers/text_line.hpp"
   *  \brief  1 �ԥƥ����Ȥδ������饹
   */
  template
  <
    typename CharT,
    class Traits = std::char_traits< CharT >,
    class Allocator = std::allocator< CharT >
  >
  struct basic_line_buf
  {
    typedef std::basic_string< CharT, Traits, Allocator > string_type;

    string_type buf; //!< �ԥǡ�����ɽ��ʸ����
    text_line line;  //!< ���ֹ����

    /*!
     *  \brief  �ǥե���ȥ��󥹥ȥ饯��
     */
    basic_line_buf()
    {
    }
    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  line  ���ֹ����
     */
    basic_line_buf( text_line const& line )
      : line( line )
    {
    }
    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  line  ���ֹ����
     *  \param  data  �ԥǡ���
     */
    basic_line_buf( text_line const& line, string_type const& data )
      : buf( data ), line( line )
    {
    }
  };

  //! char �Ǥ� 1 �ԥƥ����ȴ������饹
  typedef basic_line_buf< char > line_buf;

  /*!
   *  \brief  ���ƥ졼�����ݻ�������ֹ����μ���
   *  \param  iter  ���ƥ졼��
   *  \return ���ֹ����ؤλ��Ȥ��֤�
   *
   *  iter �ǻ��ꤷ�����ƥ졼�������ֹ������ݻ����Ƥ���ʤ顢���ι��ֹ������֤��ޤ���
   *  ���ֹ������ݻ����Ƥ��ʤ����ϥ��ߡ����֥������Ȥؤλ��Ȥ��֤��ޤ���
   */
  template < class Iterator >
  inline text_line const& get_text_line( Iterator iter )
  {
    static text_line dummy;
    return dummy;
  }

}

#endif  // ! TOPPERS_TEXTLINE_HPP_
