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
 *  \file   toppers/output_file.hpp
 *  \brief  ���ϥե���������򰷤������������
 *
 *  ���Υե�������������륯�饹
 *  \code
 *  class output_file;
 *  \endcode
 */
#ifndef TOPPERS_OUTPUT_FILE_HPP_
#define TOPPERS_OUTPUT_FILE_HPP_

#include <ostream>
#include <string>
#include "toppers/config.hpp"

namespace toppers
{

  /*!
   *  \class  output_file output_file.hpp "toppers/output_file.hpp"
   *  \brief  ���ϥե�����������饹
   */
  class output_file
  {
  public:
    output_file() : omode_( static_cast< std::ios_base::openmode >( 0 ) ) {}
    output_file( std::string const& filename, std::ios_base::openmode omode )
      : filename_( filename ), omode_( omode ), enable_( true ) {}
    virtual ~output_file() {}

    std::ostream& ostr() const;
    std::string const& file_name() const { return filename_; }
    bool is_enable() const { return enable_; }
    void enable( bool flag = true ) { enable_ = flag; }
    void push_back( char c )
    {
      if ( enable_ )
      {
        ostr() << c;
      }
    }

    static std::string path_name( std::string const& filename );
    static std::string get_file_data( std::string const& filename );
    static bool set_file_data( std::string const& filename, std::string const& data );
    static bool clear_file_data( std::string const& filename );
    static void save();
  private:
    std::string filename_;
    std::ios_base::openmode omode_;
    bool enable_;
  };

  template < typename T >
    inline output_file const& operator << ( output_file const& ofile, T const& value )
  {
    if ( ofile.is_enable() )
    {
      ofile.ostr() << value;
    }
    return ofile;
  }

}

#endif  // ! TOPPERS_OUTPUT_FILE_HPP_
