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
 *  \file   toppers/nm_symbol.hpp
 *  \brief  "nm"���ޥ�ɤ������륷��ܥ�ơ��֥�򰷤������������
 *
 *  ���Υե�������������륯�饹
 *  \code
 *  class nm_symbol;
 *  \endcode
 */
#ifndef TOPPERS_NM_SYMBOL_HPP_
#define TOPPERS_NM_SYMBOL_HPP_

#include "toppers/config.hpp"
#include <iosfwd>
#include <string>
#include <map>

namespace toppers
{

  /*!
   *  \class  nm_symbol nm_symbol.hpp "toppers/nm_symbol.hpp"
   *  \brief  `nm'���ޥ�ɤ������륷��ܥ�ơ��֥�򰷤�����Υ��饹
   *
   *  \sa nm_symbol::entry
   */
  class nm_symbol
  {
  public:
    /*!
     *  \struct entry nm_symbol.hpp "toppers/nm_symbol.hpp"
     *  \brief  ���ɥ쥹�ȥ����׾�����Ǽ���빽¤��
     *
     *  `nm'���ޥ�ɤν��Ϸ�̤���
     *  \code
     *  01234567 T foo
     *  \endcode
     *  �Ȥʤä���硢0x01234567�� address �ˡ�'T'�� type �˳�Ǽ����ޤ���
     */
    struct entry
    {
      unsigned long address;
      int type;
    };

    /*!
     *  \brief  �ǥե���ȥ��󥹥ȥ饯��
     */
    nm_symbol() {}
    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  istr  ���ϥ��ȥ꡼��
     */
    explicit nm_symbol( std::istream& istr ) { load( istr ); }

    void load( std::istream& istr );
    entry const find( std::string const& symbol ) const; 
  private:
    std::map< std::string, entry > symbol_map_;
  };

}

#endif  // ! TOPPERS_NM_SYMBOL_HPP_
