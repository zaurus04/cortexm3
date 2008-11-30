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
#include <cstdio>
#include <string>
#include "toppers/diagnostics.hpp"
#include "toppers/text_line.hpp"

namespace toppers
{
  namespace
  {
    int error_abort_threshold = 100;
    int error_count = 0;
    std::string program_name( "(unknown)" );
  }

  int get_error_count()
  {
    return error_count;
  }

  int increment_error_count()
  {
    return ++error_count;
  }

  void set_program_name( char const* name )
  {
    program_name = name;
  }

  std::string const& get_program_name()
  {
    return program_name;
  }

  int set_error_abort_threshold( int thresh )
  {
    if ( thresh < 1 )
    {
      return -1;
    }
    int previous = error_abort_threshold;
    error_abort_threshold = thresh;
    return previous;
  }

  void warning( const char* msg )
  {
    fprintf( stderr, "%s: %s: %s\n", program_name.c_str(), _( "warning" ), msg );
  }
  void warning( text_line const& line, const char* msg )
  {
    fprintf( stderr, "%s:%s:%ld: %s: %s\n", program_name.c_str(), line.file.c_str(), line.line, _( "warning" ), msg );
  }
  void error( const char* msg )
  {
    fprintf( stderr, "%s: %s: %s\n", program_name.c_str(), _( "error" ), msg );
    ++error_count;
    if ( error_abort_threshold <= error_count )
    {
      throw diagnostics_error( _( "too many errors" ) );
    }
  }
  void error( text_line const& line, const char* msg )
  {
    fprintf( stderr, "%s:%s:%ld: %s: %s\n", program_name.c_str(), line.file.c_str(), line.line, _( "error" ), msg );
    ++error_count;
    if ( error_abort_threshold <= error_count )
    {
      throw diagnostics_error( _( "too many errors" ) );
    }
  }
  void fatal( const char* msg )
  {
    fprintf( stderr, "%s: %s: %s\n", program_name.c_str(), _( "error" ), msg );
    throw diagnostics_error( _( "fatal error" ) );
  }
  void fatal( text_line const& line, const char* msg )
  {
    fprintf( stderr, "%s:%s:%d: %s: %s\n", program_name.c_str(), line.file.c_str(), line.line, _( "error" ), msg );
    throw diagnostics_error( _( "fatal error" ) );
  }

}
