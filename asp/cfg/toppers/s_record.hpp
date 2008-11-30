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
 *  \file   toppers/s_record.hpp
 *  \brief  ��ȥ���S�쥳���ɤ򰷤������������
 *
 *  ���Υե�������������륯�饹
 *  \code
 *  class s_record;
 *  struct s_record::record;
 *  class s_record::format_error;
 *  class s_record::checksum_error;
 *  \endcode
 */
#ifndef TOPPERS_S_RECORD_HPP_
#define TOPPERS_S_RECORD_HPP_

#include "toppers/config.hpp"
#include <iosfwd>
#include <string>
#include <vector>
#include <utility>
#include <stdexcept>
#include <boost/cstdint.hpp>

namespace toppers
{

  /*!
   *  \class  s_record s_record.hpp "toppers/s_recored.hpp"
   *  \brief  ��ȥ���S�쥳���ɤ򰷤�����Υ��饹
   *
   *  \sa s_record::record, s_record::format_error, s_record::checksum_error
   */
  class s_record
  {
  public:
    typedef std::pair< unsigned long, std::vector< unsigned char > > value_type;
    typedef std::vector< value_type >::size_type size_type;

    /*!
     *  \struct record s_record.hpp "toppers/s_record.hpp"
     *  \brief  S�쥳���ɤΣ��ԥ쥳���ɾ�����Ǽ���뤿��ι�¤��
     */
    struct record
    {
      int type;
      int length;
      unsigned long address;
      std::vector< unsigned char > data;
      int checksum;
    };

    /*!
     *  \class  data_error s_record.hpp "toppers/s_record.hpp"
     *  \brief  S�쥳���ɤΥǡ������顼�㳰���饹
     */
    class data_error : public std::runtime_error
    {
    public:
      data_error() : std::runtime_error( "S-record data error" ) {}
    };
    /*!
     *  \class  format_error s_record.hpp "toppers/s_record.hpp"
     *  \brief  S�쥳���ɤν񼰥��顼�㳰���饹
     */
    class format_error : public std::runtime_error
    {
    public:
      format_error() : std::runtime_error( "S-record format error" ) {}
    };
    /*!
     *  \class  checksum_error s_record.hpp "toppers/s_record.hpp"
     *  \brief  S�쥳���ɤΥ����å����२�顼�㳰���饹
     */
    class checksum_error : public std::runtime_error
    {
    public:
      checksum_error() : std::runtime_error( "S-record checksum error" ) {}
    };

    /*!
     *  \brief  �ǥե���ȥ��󥹥ȥ饯��
     */
    s_record() : cache_( data_.end() ) {}
    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  istr  ���ϥ��ȥ꡼��
     *
     *  s_record ���饹��������Ʊ���˥ǡ����Υ��ɤ�Ԥ��ޤ���
     */
    explicit s_record( std::istream& istr ) { load( istr ); }
    /*!
     *  \brief  �ǥ��ȥ饯��
     */
    virtual ~s_record() {}

    void load( std::istream& istr );
    int operator[]( size_type address ) const;
    boost::uintmax_t get_value( std::size_t base, std::size_t size, bool little_endian ) const;
    unsigned long lower_bound() const;
    unsigned long upper_bound() const;
  protected:
    static record const read_record( std::string const& rec_buf );
    static int xdigit_to_int( int ch );
  private:
    std::vector< value_type > data_;
    mutable std::vector< value_type >::const_iterator cache_;
  };

}

#endif  // ! TOPPERS_S_RECORD_HPP_
