/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
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
#include <fstream>
#include <map>
#include "toppers/workaround.hpp"
#include "toppers/s_record.hpp"
#include "toppers/nm_symbol.hpp"
#include "toppers/misc.hpp"
#include "toppers/diagnostics.hpp"
#include "toppers/itronx/checker.hpp"
#include "toppers/itronx/cfg1_out.hpp"

namespace toppers
{
  namespace itronx
  {

    struct checker::implementation
    {
    protected:
      std::tr1::shared_ptr< s_record > srec_;
      std::tr1::shared_ptr< nm_symbol > syms_;

      virtual ~implementation() {}
      virtual bool do_check( cfg1_out& cfg1out, std::map< std::string, std::size_t > const& count_map )
      {
        return true;
      }
      virtual implementation* do_clone() const
      {
        return new implementation( *this );
      }

      friend class checker;
    };

    checker::checker()
      : pimpl_( new implementation )
    {
    }

    /*!
     *  \brief  ���ԡ����󥹥ȥ饯��
     *  \param[in]  ���ԡ���
     */
    checker::checker( checker const& other )
      : pimpl_( other.pimpl_->do_clone() )
    {
    }

    //! �ǥ��ȥ饯��
    checker::~checker()
    {
      delete pimpl_;
      pimpl_ = 0;
    }

    /*!
     *  \brief  ROM���᡼���Υ���
     *  \param[in]  srec_file   S�쥳���ɷ����Υե�����̾
     *  \param[in]  nm_file     nm���ޥ�ɤ����Ϥ�������ܥ�ơ��֥�Υե�����̾
     */
    void checker::load_rom_image( std::string const& srec_file, std::string const& nm_file )
    {
      std::ifstream ifs_srec( srec_file.c_str() );
      if ( !ifs_srec.is_open() )
      {
        fatal( _( "cannot open file `%1%\'" ), srec_file );
      }
      std::tr1::shared_ptr< s_record > srec( new s_record( ifs_srec ) );

      std::ifstream ifs_nm( nm_file.c_str() );
      if ( !ifs_nm.is_open() )
      {
        fatal( _( "cannot open file `%1%\'" ), nm_file );
      }
      std::tr1::shared_ptr< nm_symbol > syms( new nm_symbol( ifs_nm ) );

      pimpl_->srec_.swap( srec );
      pimpl_->syms_.swap( syms );
    }

    /*!
     *  \brief  �����å��μ»�
     *  \param[in]  cfg1_out����
     */
    bool checker::check( cfg1_out& cfg1out ) const
    {
      cfg1_out::static_api_map api_map( cfg1out.merge() );

      std::map< std::string, std::size_t > count_map;
      for ( cfg1_out::static_api_map::const_iterator iter( api_map.begin() ), last( api_map.end() );
            iter != last;
            ++iter )
      {
        std::size_t count = 0;
        for ( std::vector< static_api >::const_iterator iter2( iter->second.begin() ), last2( iter->second.end() );
              iter2 != last2;
              ++iter2 )
        {
          if ( !iter2->get_info()->slave )
          {
            ++count;
          }
        }
        count_map[ iter->first ] = count;
      }

      return pimpl_->do_check( cfg1out, count_map );
    }

    /*!
     *  \brief  ����ܥ����θ���
     *  \param[in]  symbol  �������륷��ܥ�̾
     *  \return     �������
     *
     *  �����˼��Ԥ������ˤϡ��ֵ��ͤ�.type�ե�����ɤ�-1�����ꤵ��롣
     */
    nm_symbol::entry checker::find( std::string const& symbol ) const
    {
      return pimpl_->syms_->find( symbol );
    }

    /*!
     *  \brief  ���ꥢ�ɥ쥹�������ͤ����
     *  \param[in]  address   ���ɥ쥹
     *  \param[in]  size      �����ͤ�������Х��ȿ�
     *  \param[in]  little_endian   �Х��ȥ�����������ȥ륨��ǥ�����ʤ�true����ꤹ��
     *  \return     �������������ͤ����̵�����֤���
     */
    std::tr1::uintmax_t checker::get( std::size_t address, std::size_t size, bool little_endian ) const
    {
      return pimpl_->srec_->get_value( address, size, little_endian );
    }

  }
}
