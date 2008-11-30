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
 *  \file   toppers/diagnostics.hpp
 *  \brief  ���ǽ����˴ؤ���������
 */
#ifndef TOPPERS_DIAGNOSTICS_HPP_
#define TOPPERS_DIAGNOSTICS_HPP_

#include <stdexcept>
#include "toppers/debug.hpp"
#include "toppers/gettext.hpp"
#include <boost/format.hpp>

namespace toppers
{

  struct text_line;

  class diagnostics_error : public std::runtime_error
  {
  public:
    diagnostics_error( std::string const& msg ) : std::runtime_error( msg ) {}
  };

  class normal_exit {};

  int get_error_count();
  int increment_error_count();
  void set_program_name( char const* name );
  std::string const& get_program_name();
  int set_error_abort_threshold( int thresh );
  void warning( const char* msg );
  void warning( text_line const& line, const char* msg );
  void error( const char* msg );
  void error( text_line const& line, const char* msg );
  void fatal( const char* msg );
  void fatal( text_line const& line, const char* msg );

  template < typename T1 >
    inline void warning( const char* str, T1 const& arg1 )
  {
    warning( ( boost::format( str ) % arg1 ).str().c_str() );
  }

  template < typename T1, typename T2 >
    inline void warning( const char* str, T1 const& arg1, T2 const& arg2 )
  {
    warning( ( boost::format( str ) % arg1 % arg2 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3 >
    inline void warning( const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3 )
  {
    warning( ( boost::format( str ) % arg1 % arg2 % arg3 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3, typename T4 >
    inline void warning( const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3, T4 const& arg4 )
  {
    warning( ( boost::format( str ) % arg1 % arg2 % arg3 % arg4 ).str().c_str() );
  }

  template < typename T1 >
    inline void warning( text_line const& line, const char* str, T1 const& arg1 )
  {
    warning( line, ( boost::format( str ) % arg1 ).str().c_str() );
  }

  template < typename T1, typename T2 >
    inline void warning( text_line const& line, const char* str, T1 const& arg1, T2 const& arg2 )
  {
    warning( line, ( boost::format( str ) % arg1 % arg2 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3 >
    inline void warning( text_line const& line, const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3 )
  {
    warning( line, ( boost::format( str ) % arg1 % arg2 % arg3 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3, typename T4 >
    inline void warning( text_line const& line, const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3, T4 const& arg4 )
  {
    warning( line, ( boost::format( str ) % arg1 % arg2 % arg3 % arg4 ).str().c_str() );
  }

  template < typename T1 >
    inline void error( const char* str, T1 const& arg1 )
  {
    error( ( boost::format( str ) % arg1 ).str().c_str() );
  }

  template < typename T1, typename T2 >
    inline void error( const char* str, T1 const& arg1, T2 const& arg2 )
  {
    error( ( boost::format( str ) % arg1 % arg2 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3 >
    inline void error( const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3 )
  {
    error( ( boost::format( str ) % arg1 % arg2 % arg3 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3, typename T4 >
    inline void error( const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3, T4 const& arg4 )
  {
    error( ( boost::format( str ) % arg1 % arg2 % arg3 % arg4 ).str().c_str() );
  }

  template < typename T1 >
    inline void error( text_line const& line, const char* str, T1 const& arg1 )
  {
    error( line, ( boost::format( str ) % arg1 ).str().c_str() );
  }

  template < typename T1, typename T2 >
    inline void error( text_line const& line, const char* str, T1 const& arg1, T2 const& arg2 )
  {
    error( line, ( boost::format( str ) % arg1 % arg2 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3 >
    inline void error( text_line const& line, const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3 )
  {
    error( line, ( boost::format( str ) % arg1 % arg2 % arg3 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3, typename T4 >
    inline void error( text_line const& line, const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3, T4 const& arg4 )
  {
    error( line, ( boost::format( str ) % arg1 % arg2 % arg3 % arg4 ).str().c_str() );
  }

  template < typename T1 >
    inline void fatal( const char* str, T1 const& arg1 )
  {
    fatal( ( boost::format( str ) % arg1 ).str().c_str() );
  }

  template < typename T1, typename T2 >
    inline void fatal( const char* str, T1 const& arg1, T2 const& arg2 )
  {
    fatal( ( boost::format( str ) % arg1 % arg2 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3 >
    inline void fatal( const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3 )
  {
    fatal( ( boost::format( str ) % arg1 % arg2 % arg3 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3, typename T4 >
    inline void fatal( const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3, T4 const& arg4 )
  {
    fatal( ( boost::format( str ) % arg1 % arg2 % arg3 % arg4 ).str().c_str() );
  }

  template < typename T1 >
    inline void fatal( text_line const& line, const char* str, T1 const& arg1 )
  {
    fatal( line, ( boost::format( str ) % arg1 ).str().c_str() );
  }

  template < typename T1, typename T2 >
    inline void fatal( text_line const& line, const char* str, T1 const& arg1, T2 const& arg2 )
  {
    fatal( line, ( boost::format( str ) % arg1 % arg2 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3 >
    inline void fatal( text_line const& line, const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3 )
  {
    fatal( line, ( boost::format( str ) % arg1 % arg2 % arg3 ).str().c_str() );
  }

  template < typename T1, typename T2, typename T3, typename T4 >
    inline void fatal( text_line const& line, const char* str, T1 const& arg1, T2 const& arg2, T3 const& arg3, T4 const& arg4 )
  {
    fatal( line, ( boost::format( str ) % arg1 % arg2 % arg3 % arg4 ).str().c_str() );
  }

  inline void exit()
  {
    throw normal_exit();
  }

#undef  _
#define _( str )  ::toppers::gettext( str ).c_str()

}

#endif  // ! TOPPERS_DIAGNOSTICS_HPP_

