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
 *  toppers/nm_symbol.cpp
 */
#include "toppers/nm_symbol.hpp"
#include <istream>
#include <sstream>
#include <cctype>

namespace toppers
{

  /*!
   *  \brief  ����ܥ�ơ��֥�Υ���
   *  \param  istr  ���ϥ��ȥ꡼��
   */
  void nm_symbol::load( std::istream& istr )
  {
    while ( istr )
    {
      std::string buf;
      std::getline( istr, buf );
      std::istringstream isstr( buf );

      unsigned long address = 0;
      char type;
      std::string symbol;
      if ( !std::isspace( static_cast< unsigned char >( buf[0] ) ) )
      {
        isstr >> std::hex >> address;
      }
      isstr >> type >> symbol;

      if ( !symbol.empty() )
      {
        entry e;
        e.address = address;
        e.type = static_cast< unsigned char >( type );
        symbol_map_[symbol] = e;
      }
    }
  }

  /*!
   *  \brief  ����ܥ��õ��
   *  \param  symbol  õ�����륷��ܥ�ʸ����
   *  \return ����ܥ���б����륨��ȥ���֤�
   */
  nm_symbol::entry const nm_symbol::find( std::string const& symbol ) const
  {
    std::map< std::string, entry >::const_iterator iter( symbol_map_.find( symbol ) );
    entry e = { 0, -1 };
    if ( iter != symbol_map_.end() )
    {
      e = iter->second;
    }
    else
    {
      iter = symbol_map_.find( "_" + symbol );  // ���̻Ҥ�'_'���ղä��������б�
      if ( iter != symbol_map_.end() )
      {
        e = iter->second;
      }
    }
    return e;
  }

}
