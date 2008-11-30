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
#include <cstdlib>
#include <cerrno>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <ostream>
#include <utility>
#include "toppers/macro_processor.hpp"
#include "toppers/diagnostics.hpp"
#include "toppers/gettext.hpp"
#include <boost/format.hpp>
#include <boost/utility.hpp>
#include <boost/lexical_cast.hpp>

namespace toppers
{
  namespace
  {
    typedef macro_processor::element element;
    typedef macro_processor::var_t var_t;
    typedef macro_processor::context context;

    inline std::tr1::int64_t get_i( var_t const& var, context const* p_ctx )
    {
      return macro_processor::to_integer( var, p_ctx );
    }
    inline std::string get_s( var_t const& var, context const* p_ctx )
    {
      return macro_processor::to_string( var, p_ctx );
    }

  }

  /*!
    *  \brief  �����θĿ������å�
    *  \param[in]  line    ���ֹ����
    *  \param[in]  arity   �����θĿ�
    *  \param[in]  valid   ���Ԥ��Ƥ�������θĿ�
    *  \param[in]  function_name �Ȥ߹��ߴؿ�̾
    */
  bool macro_processor::check_arity( text_line const& line, std::size_t arity, std::size_t valid, char const* function_name )
  {
    bool result = false;
    if ( arity < valid )
    {
      error( line, _( "too few arguments for `%1%\'" ), function_name );
    }
    else if ( arity > valid )
    {
      error( line, _( "too many arguments for `%1%\'" ), function_name );
    }
    else
    {
      result = true;
    }
    return result;
  }

  /*!
   *  \brief  �ѿ�����פΤ����<<�黻��
   *  \param[in,out]  ostr  ���ϥ��ȥ꡼��
   *  \param[in]      arg   �ѿ��򻲾Ȥ��뤿��Υڥ�
   *  \return         ostr���֤�
   *  \note ���ߤμ����Ǥϡ�arg.second �ϻ��Ѥ��Ƥ��ʤ���
   */
  std::ostream& operator<<( std::ostream& ostr, std::pair< var_t const*, context const* > const& arg )
  {
    for ( var_t::const_iterator iter( arg.first->begin() ), last( arg.first->end() ); iter != last; ++iter )
    {
      if ( !iter->s.empty() )
      {
        ostr << iter->s;
      }
      else if ( iter->i )
      {
        ostr << iter->i.get();
      }
      if ( boost::next( iter ) != last )
      {
        ostr << ",";
      }
    }
    return ostr;
  }

  /*!
   *  \brief  ����ꥹ�Ȥ�Ĺ��
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°����Ȥ��ƻ��ꤷ������դ��ꥹ�Ȥ����ǿ����֤���
   *  ��1�ޥ���°���������դ��ꥹ�ȤǤʤ�����1���֤����ޤ�����1�ޥ���°�����̵�����ѿ��ξ���0���֤���
   */
  var_t bf_length( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    if ( macro_processor::check_arity( line, arg_list.size(), 1, "LENGTH" ) )
    {
      std::tr1::int64_t size = arg_list.front().size();
      e.i = size;
    }
    return var_t( 1, e );
  }

  /*!
   *  \brief  ʸ����ΰ���Ƚ��
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°�������2�ޥ���°�����ʸ����Ȥ�����Ӥ������פ�����Ͽ��򡢤����Ǥʤ���е����֤���
   */
  var_t bf_eq( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    if ( macro_processor::check_arity( line, arg_list.size(), 2, "EQ" ) )
    {
      e.i = get_s( arg_list[0], p_ctx ) == get_s( arg_list[1], p_ctx );
    }
    return var_t( 1, e );
  }

  /*!
   *  \brief  ������
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°�����̵�����ѿ��ξ�����2�°������֤�������¾����1�°������֤���
   */
  var_t bf_alt( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    if ( macro_processor::check_arity( line, arg_list.size(), 2, "ALT" ) )
    {
      if ( !arg_list[0].empty() )
      {
        return arg_list[0];
      }
      else
      {
        return arg_list[1];                
      }
    }
    return var_t( 1, e );
  }

  /*!
   *  \brief  ����ꥹ�Ȥ�����
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°����Ȥ���Ϳ��������դ��ꥹ�Ȥγ����Ǥ���2�ޥ���°�����ź�����Ȥ��������ѿ���ɾ������
   *  ����ɾ����̤˴�Ť���������󤹤롣
   *
   *  \example
   *  $FOO[1] = 20$
   *  $FOO[2] = 10$
   *  $FOO[3] = 30$
   *  $SORT({ 1,2,3 }, "FOO")$
   *  �� { 2,1,3 }
   *  \endexample
   */
  var_t bf_sort( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    var_t result;
    if ( macro_processor::check_arity( line, arg_list.size(), 2, "SORT" ) )
    {
      var_t list( arg_list[0] );
      std::string field( get_s( arg_list[1], p_ctx ) );
      std::vector< std::pair< element, std::tr1::int64_t > > temp;

      for ( var_t::const_iterator iter( list.begin() ), last( list.end() ); iter != last; ++iter )
      {
        std::tr1::int64_t order = iter->i.get();
        std::string name( ( boost::format( "%s[%d]" ) % field % order ).str() );
        std::map< std::string, var_t >::const_iterator m_iter( p_ctx->var_map.find( name ) );
        if ( m_iter == p_ctx->var_map.end() )
        {
          return var_t();
        }
        if ( !m_iter->second.empty() )
        {
          temp.push_back( std::make_pair( m_iter->second.front(), order ) );
        }
      }

      std::stable_sort( temp.begin(), temp.end() );

      for ( std::vector< std::pair< element, std::tr1::int64_t > >::const_iterator iter( temp.begin() ), last( temp.end() );
            iter != last;
            ++iter )
      {
        element e;
        e.i = iter->second;
        result.push_back( e );
      }
    }
    return result;
  }

  /*!
   *  \brief  �Ķ��ѿ��μ���
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°����ǻ��ꤷ���Ķ��ѿ����ͤ��֤���
   */
  var_t bf_environ( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    if ( macro_processor::check_arity( line, arg_list.size(), 1, "ENVIRON" ) )
    {
      std::string name = get_s( arg_list[0], p_ctx );
      char const* env = std::getenv( name.c_str() );
      if ( env == 0 )
      {
        return var_t();
      }
      e.s = env;
      errno = 0;
      char* endptr;
      if ( std::tr1::int64_t value = std::strtol( env, &endptr, 0 ) )
      {
        if ( *endptr == '\0' && errno == 0 )
        {
          e.i = value;
        }
      }
    }
    return var_t( 1, e );
  }

  /*!
   *  \brief  �ͤ�����
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°�����ƥ����ȡ���2�ޥ���°�������ͤȤ��ơ��ͤ��������롣
   */
  var_t bf_value( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    if ( macro_processor::check_arity( line, arg_list.size(), 2, "VALUE" ) )
    {
      if ( !arg_list[0].empty() )
      {
        e.s = get_s( arg_list[0], p_ctx );
      }
      if ( !arg_list[1].empty() )
      {
        e.i = get_i( arg_list[1], p_ctx );
      }
    }
    return var_t( 1, e );
  }

  /*!
   *  \brief  ʸ�����Ϣ��
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°�������2�ޥ���°�����Ϣ�뤷�ƿ�����ʸ������������롣
   */
  var_t bf_concat( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    if ( macro_processor::check_arity( line, arg_list.size(), 2, "CAT" ) )
    {
      e.s = get_s( arg_list[0], p_ctx ) + get_s( arg_list[1], p_ctx );
    }
    return var_t( 1, e );
  }

  /*!
   *  \brief  ����ꥹ�Ȥν�ü�����Ǥ��ɲ�
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°�������2�ޥ���°�����Ϣ�뤷�ƿ���������դ��ꥹ�Ȥ��������롣
   */
  var_t bf_append( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    var_t result;
    if ( macro_processor::check_arity( line, arg_list.size(), 2, "APPEND" ) )
    {
      result = arg_list[0];
      result.insert( result.end(), arg_list[1].begin(), arg_list[1].end() );
    }
    return result;
  }

  /*!
   *  \brief  ����ꥹ�Ȥλ������Ǥλ���
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°����ǻ��ꤷ������ꥹ�ȤΡ���2�ޥ���°����ǻ��ꤷ�����Ǥ��֤���
   */
  var_t bf_at( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    if ( macro_processor::check_arity( line, arg_list.size(), 2, "CAT" ) )
    {
      try
      {
        e = arg_list[0].at( static_cast< std::vector< var_t >::size_type >( get_i( arg_list[1], p_ctx ) ) );
      }
      catch ( std::out_of_range& )
      {
        // ź����������
        // �ä˲��⤷�ʤ� �� ���λ����� e �����ͤǤ��뤳�Ȥ����
      }
    }
    return var_t( 1, e );
  }

  /*!
   *  \brief  �ƥ����Ȥ�����
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°����ǻ��ꤷ��ʸ������������롣
   */
  var_t bf_gettext( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    if ( macro_processor::check_arity( line, arg_list.size(), 1, "GETTEXT" ) )
    {
      std::string message = get_s( arg_list[0], p_ctx );
      e.s = gettext( message );
    }
    return var_t( 1, e );
  }

  /*!
   *  \brief  �ޥ���°����ν񼰲�
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°����ǻ��ꤷ�������ʸ����ˤ�äơ���2�ޥ���°����ʹߤ�񼰲����롣
   *  �񼰲�ʸ����ϡ�%n���Ȥ��ʤ����Ȥ������printf�ؿ��Υ����ѡ����åȤǤ��롣
   *  ���Τʻ��ͤϡ�boost::format�򻲾ȤΤ��ȡ�
   */
  var_t bf_format( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    std::size_t arity = arg_list.size();
    if ( arity < 1 )
    {
      error( line, _( "too few arguments for `%1%\'" ), "FORMAT" );
    }
    boost::format fmt( get_s( arg_list[0], p_ctx ) );
    for ( std::size_t i = 1; i < arity; i++ )
    {
      std::pair< var_t const*, context const* > arg( &arg_list[i], p_ctx );
      fmt % arg;
    }
    e.s = fmt.str();
    return var_t( 1, e );
  }

  /*!
   *  \brief  ����դ��ꥹ�����õ��
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°����ǻ��ꤷ������դ��ꥹ�Ȥ˴ޤޤ����2�ޥ���°����ǻ��ꤷ���ͤ����������Ǥ�
   *  ��Ƭ������õ�����롣
   *  ���������Ǥ����Ĥ���Ф������ǤؤΥ���ǥå����򡢤����Ǥʤ���ж��ͤ��֤���
   */
  var_t bf_find( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    if ( macro_processor::check_arity( line, arg_list.size(), 2, "FIND" ) )
    {
      var_t list( arg_list[0] );
      std::tr1::int64_t value( get_i( arg_list[1], p_ctx ) );

      for ( var_t::const_iterator iter( list.begin() ), last( list.end() ); iter != last; ++iter )
      {
        if ( iter->i.get() == value ) // ȯ����
        {
          e.i = iter - list.begin();  // iter �� RandomAccessIterator
          return var_t( 1, e );
        }
      }
    }
    return var_t();
  }

  /*!
   *  \brief  �ϰϻ���ˤ�����դ��ꥹ��
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°����Ǻǽ���ͤ���2�ޥ���°����ǺǸ���ͤ���ꤹ�롣
   *  { �ǽ����, �ǽ���� + 1, ... �Ǹ���� }
   *  �Ȥʤ����դ��ꥹ�Ȥ��������롣
   *  �������������ʤ����϶��ͤ��֤���
   */
  var_t bf_range( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    var_t result;
    if ( macro_processor::check_arity( line, arg_list.size(), 2, "RANGE" ) )
    {
      std::tr1::int64_t arg1( get_i( arg_list[0], p_ctx ) );
      std::tr1::int64_t arg2( get_i( arg_list[1], p_ctx ) );

      for ( ; arg1 <= arg2; ++arg1 )
      {
        element e;
        e.i = arg1;
        result.push_back( e );
      }
    }
    return result;
  }

  /*!
   *  \brief  ���ѿ��Υ����
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  �ޥ���°�������ꤷ����硢����ʸ����°���ǻ��ꤷ���ե�����˥���פ���ʸ������ɵ����롣
   *  �ե�����̾�Ȥ��ơ�"stdout"����ꤷ������ɸ����ϡ�"stderr"����ꤷ������ɸ�२�顼�˽��Ϥ��롣
   *  �ե�����̾���ά��������"stderr"����ꤷ����ΤȤ��ƿ��񤦡�
   */
  var_t bf_dump( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    std::size_t arity = arg_list.size();

    if ( arity > 1 )
    {
      error( line, _( "too many arguments for `%1%\'" ), "DUMP" );
    }

    std::string dump_str;

    // ���ѿ���ʤ��
    for ( std::map< std::string, var_t >::const_iterator iter( p_ctx->var_map.begin() ), last( p_ctx->var_map.end() );
          iter != last;
          ++iter )
    {
      dump_str += "$" + iter->first + "$ = { ";
      if ( !iter->second.empty() )
      {
        // ���ѿ���������
        for ( var_t::const_iterator iter2( iter->second.begin() ), last2( iter->second.end() );
              iter2 != last2;
              ++iter2 )
        {
          dump_str += "\"" + iter2->s + "\"(";
          if ( iter2->i ) // ��°���������...
          {
            dump_str += boost::lexical_cast< std::string >( *iter2->i );
          }
          dump_str += "), ";
        }
      }
      dump_str += " }\n";
    }

    std::string filename( "stderr" );
    if ( arity == 1 )
    {
      filename = get_s( arg_list[0], p_ctx );
    }
    if ( filename == "stdout" )
    {
      fputs( dump_str.c_str(), stdout );
    }
    else if ( filename == "stderr" )
    {
      fputs( dump_str.c_str(), stderr );
    }
    else
    {
      std::FILE* stream = std::fopen( filename.c_str(), "a" );
      if ( stream != 0 )
      {
        fputs( dump_str.c_str(), stream );
        std::fclose( stream );
      }
    }
    element e;
    return var_t( 1, e );
  }

  /*!
   *  \brief  �ѿ��Υȥ졼��
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  ��1�ޥ���°����ǻ��ꤷ���ѿ������Ƥ�ȥ졼�����롣
   *  ��2�ޥ���°�������ꤷ����硢����ʸ����°���ǻ��ꤷ���ե�����˥ȥ졼�����Ƥ��ɵ����롣
   *  �ե�����̾�Ȥ��ơ�"stdout"����ꤷ������ɸ����ϡ�"stderr"����ꤷ������ɸ�२�顼�˽��Ϥ��롣
   *  �ե�����̾���ά��������"stderr"����ꤷ����ΤȤ��ƿ��񤦡�
   */
  var_t bf_trace( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    std::size_t arity = arg_list.size();

    if ( arity < 1 )
    {
      error( line, _( "too few arguments for `%1%\'" ), "TRACE" );
    }
    else if ( arity > 2 )
    {
      error( line, _( "too many arguments for `%1%\'" ), "TRACE" );
    }

    var_t value( arg_list[ 0 ] );

    std::string trace_str = "{ ";
    for ( var_t::const_iterator iter( value.begin() ), last( value.end() );
          iter != last;
          ++iter )
    {
      trace_str += "\"" + iter->s + "\"(";
      if ( iter->i ) // ��°���������...
      {
        trace_str += boost::lexical_cast< std::string >( *iter->i );
      }
      trace_str += "), ";
    }
    trace_str += " }\n";

    std::string filename( "stderr" );
    if ( arity == 2 )
    {
      filename = get_s( arg_list[ 1 ], p_ctx );
    }
    if ( filename == "stdout" )
    {
      fputs( trace_str.c_str(), stdout );
    }
    else if ( filename == "stderr" )
    {
      fputs( trace_str.c_str(), stderr );
    }
    else
    {
      std::FILE* stream = std::fopen( filename.c_str(), "a" );
      if ( stream != 0 )
      {
        fputs( trace_str.c_str(), stream );
        std::fclose( stream );
      }
    }

    element e;
    return var_t( 1, e );
  }

  /*!
   *  \brief  ���⤷�ʤ��Ȥ߹��ߴؿ�
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *  �����Ȥ߹��ߴؿ��ϲ���Ԥ�ʤ����ޤ����ޥ���°����Υ����å���Ԥ�ʤ���
   *  NOOP�ؿ��Ͼ�� "" ���֤���
   *  \note       ���ͤ��֤��ʤ��Τϡ�$NOOP()$�Τ褦�ʻȤ����򤷤��Ȥ��Ǥ������ʻ��Ȥ�������ʤ��褦�ˤ��뤿�ᡣ
   */
  var_t bf_noop( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    element e;
    return var_t( 1, e );
  }

  macro_processor::func_t const macro_processor::builtin_function_table[] =
  {
    { "LENGTH", bf_length },
    { "EQ", bf_eq },
    { "ALT", bf_alt },
    { "SORT", bf_sort },
    { "ENVIRON", bf_environ },
    { "VALUE", bf_value },
    { "CONCAT", bf_concat },
    { "APPEND", bf_append },
    { "AT", bf_at },
    { "GETTEXT", bf_gettext },
    { "_", bf_gettext },  // GETTEXT�Υ��Υ˥�
    { "FORMAT", bf_format },
    { "FIND", bf_find },
    { "RANGE", bf_range },
    { "DUMP", bf_dump },
    { "TRACE", bf_trace },
    { "NOOP", bf_noop },
    { 0, 0 },
  };

}
