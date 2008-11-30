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
 *  \file   toppers/itronx/init_helper.hpp
 *  \brief  �����ͥ�ޤ��ϥ⥸�塼��ν���������إ�ѡ��ؿ�����������
 */
#ifndef TOPPERS_ITRONX_INIT_HELPER_HPP_
#define TOPPERS_ITRONX_INIT_HELPER_HPP_

#include <string>
#include <map>
#include <iostream>
#include "toppers/global.hpp"
#include "toppers/itronx/static_api.hpp"
#include "toppers/itronx/asp/factory.hpp"

namespace toppers
{
  namespace itronx
  {

    /*!
     *  \brief      �����ͥ�ޤ��ϥ⥸�塼��ν���������إ�ѡ��ؿ�
     *  \param[in]  module_name   �⥸�塼��̾
     *  \param[in]  info_table    ��ŪAPI�˴ؤ������ơ��֥�
     *  \param[in]  table_count   info_table �����ǿ�
     *  retval      true          ���������
     *  retval      false         ���������
     */
    template < class Factory >
      bool init_helper( std::string const& module_name, static_api::info const* info_table, std::size_t table_count )
    {
      try
      {
        std::map< std::string, static_api::info > temp_map;
        for ( std::size_t i = 0; ( i < table_count ) && ( info_table[ i ].type != 0 ); ++i )
        {
          temp_map[ info_table[ i ].api_name ] = info_table[ i ];
        }
        static std::map< std::string, static_api::info > const info_map( temp_map );
        global( module_name + "_static_api_info_map" ) = static_cast< void const* >( &info_map );	// GCC�Х��к�

        static Factory factory;
        global( module_name + "_factory" ) = static_cast< itronx::factory* >( &factory );
      }
      catch ( ... )
      {
        std::cerr << "module `" << module_name << "\' is failed to initialize" << std::endl;
        return false;
      }
      return true;
    }

  }
}

#endif  // ! TOPPERS_ITRONX_INIT_HELPER_HPP_
