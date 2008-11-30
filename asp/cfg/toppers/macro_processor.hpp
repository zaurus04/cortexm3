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
 *  \file   toppers/macro_processor.hpp
 *  \brief  �ޥ�������Τ����������
 *
 *  ���Υե�������������륯�饹
 *  \code
 *  class macro_processor;
 *  \endcode
 */
#ifndef TOPPERS_MACRO_PROCESSOR_HPP_
#define TOPPERS_MACRO_PROCESSOR_HPP_

#include <string>
#include <vector>
#include <stack>
#include <map>
#include "toppers/workaround.hpp"
#include "toppers/output_file.hpp"
#include "toppers/text.hpp"

namespace toppers
{

  class macro_processor
  {
  public:
    struct context;

    /*!
     *  \struct element macro_processor.hpp "toppers/macro_processor.hpp"
     *  \brief  �ޥ�����ǻ��Ѥ����ѿ�����
     *
     *  ���Τˤϡ��ѿ����ͤϾ�˽���դ��ꥹ�ȤȤ��ư����ޤ���element �Ͻ���դ��ꥹ�Ȥ� 1 ���Ǥ�ɽ���ޤ���
     */
    struct element
    {
      boost::optional< std::tr1::int64_t > i;
      std::string s;
    };
    /*!
     *  \brief  �ޥ�����ǻ��Ѥ����ѿ���ɽ�����뷿
     */
    typedef std::vector< element > var_t;

    /*!
     *  \struct func_t macro_processor.hpp "toppers/macro_processor.hpp"
     *  \brief  �ޥ�����ǰ����ؿ���ɽ�����뷿
     */
    struct func_t
    {
      char const* name;   //!< �ؿ�̾
      var_t ( * f )( text_line const& line, std::vector< var_t > const&, context const* );  //!< ��������
    };

    typedef void ( * hook_t )( text_line const&, std::string const&, var_t const&, var_t const&, context* );

    struct context
    {
      std::stack< var_t > stack;
      std::map< std::string, var_t > var_map;
      std::map< std::string, func_t > func_map;
      output_file target_file;
      hook_t hook_on_assign;
      text_line line;
      explicit context( hook_t hoa = 0 ) : hook_on_assign( hoa ) {}
    };

    explicit macro_processor( hook_t hook_on_assign = 0 );
    macro_processor( macro_processor const& other );
    explicit macro_processor( text const& in, hook_t hook_on_assign = 0 );
    ~macro_processor();
    macro_processor& operator=( macro_processor const& other );
    void swap( macro_processor& other );
    void evaluate( text const& in );
    void set_var( std::string const& name, var_t const& value );
    void set_var( std::string const& name, long name2, var_t const& value );
    var_t const& get_var( std::string const& name ) const;
    var_t const& get_var( std::string const& name, long name2 ) const;
    void add_builtin_function( func_t const& f );

    static void remove_comment( text const& in, text& out );
    static void expand_include( text const& in, text& out );
    static void preprocess( text const& in, text& out );
    static std::tr1::int64_t to_integer( var_t const& var, context const* p_ctx );
    static std::string to_string( var_t const& var, context const* p_ctx );
    static bool check_arity( text_line const& line, std::size_t arity, std::size_t valid, char const* function_name );
  private:
    context* p_ctx_;
    static func_t const builtin_function_table[];
  };

  inline bool operator == ( macro_processor::element const& lhs, macro_processor::element const& rhs )
  {
    return lhs.i == rhs.i;
  }

  inline bool operator < ( macro_processor::element const& lhs, macro_processor::element const& rhs )
  {
    return lhs.i < rhs.i;
  }

  struct element_eq
  {
    explicit element_eq( std::tr1::int64_t value ) : value_( value ) {}
    bool operator()( toppers::macro_processor::element const& e ) const
    {
      return e.i && ( e.i.get() == value_ );
    }
    std::tr1::int64_t value_;
  };

}

#endif  // ! TOPPERS_MACRO_PROCESSOR_HPP_
