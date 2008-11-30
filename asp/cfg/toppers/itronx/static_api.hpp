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
 *  \file   toppers/itronx/static_api.hpp
 *  \brief  ��ŪAPI����β��Ϥȴ����˴ؤ���������
 *
 *  ���Υե�������������륯�饹
 *  \code
 *  class static_api;
 *  \endcode
 */
#ifndef TOPPERS_ITRONX_STATIC_API_HPP_
#define TOPPERS_ITRONX_STATIC_API_HPP_

#include <string>
#include <map>
#include <set>
#include <algorithm>
#include "toppers/workaround.hpp"
#include "toppers/text.hpp"
#include "toppers/text.hpp"
#include "toppers/codeset.hpp"
#include "toppers/diagnostics.hpp"
#include <boost/any.hpp>
#include <boost/optional.hpp>

namespace toppers
{
  namespace itronx
  {

    /*!
     *  \class  static_api static_api.hpp "toppers/itronx/static_api.hpp"
     *  \brief  ����ե�����졼�����ե�����˵��Ҥ��줿��ŪAPI�ξ����������뤿��Υ��饹
     */
    class static_api
    {
    public:
      /*!
       *  \struct info  static_api.hpp "toppers/itronx/static_api.hpp"
       *  \brief  ��ŪAPI�λ��ͤ˴ؤ������
       *
       *  static_api::info �� params ������γ����Ǥ��դ���줿��Ƭ���ΰ�̣�ϼ��ΤȤ���
       *
       *  - #: ���֥������ȼ��̻�
       *  - %: ���֥������ȼ��̻Ҥǡ����ļ�ư���դ����оݤȤʤ�ʤ����
       *  - .: ���̵������������ѥ�᡼��
       *  - +: ����դ�����������ѥ�᡼��
       *  - &: ����������ѥ�᡼��
       *
       *  �ʤ���{ ����� } ���ص�Ū�˥ѥ�᡼���ΰ��Ȥ��ư��äƤ���ʹ�ʸ���Ϥ�ɬ�פʤ���ˡ�
       */
      struct info
      {
        char const* type;     //!< �����ͥ륪�֥������Ȥμ��̤�ɽ����ʸ����"tsk", "sem"����
        char const* api_name; //!< ��ŪAPI̾��"CRE_TSK", "CRE_SEM"����
        char const* params;   //!< �ѥ�᡼���¤�
        int id_pos;           //!< �ѥ�᡼���Τ���ID�ֹ�ΰ��֡�-1�ξ���ID�ֹ�̵����
        bool slave;           //!< ¾����ŪAPI���Ф��ƽ�°�ط��ˤ������true��"DEF_TEX"����
      };
      /*!
       *  \struct parameter static_api.hpp "toppers/itronx/static_api.hpp"
       *  \brief  ��ŪAPI�Υѥ�᡼���˴ؤ������
       */
      struct parameter
      {
        std::string symbol;   //!< ������̾
        std::string text;     //!< �°����λ���
        boost::optional< std::tr1::intmax_t > value;  //!< �°�������
      };
      typedef std::vector< parameter > parameter_container;
      typedef parameter_container::iterator iterator;
      typedef parameter_container::const_iterator const_iterator;
      typedef parameter_container::reference reference;
      typedef parameter_container::const_reference const_reference;
      typedef parameter_container::size_type size_type;

      char const* api_name() const { return pinfo_ != 0 ? pinfo_->api_name : ""; }
      info const* get_info() const { return pinfo_; }

      parameter_container const& params() const { return params_; }
      iterator begin() { return params_.begin(); }
      const_iterator begin() const { return params_.begin(); }
      iterator end() { return params_.end(); }
      const_iterator end() const { return params_.end(); }
      reference at( size_type pos ) { return params_.at( pos ); }
      reference at( std::string const& symbol )
      {
        iterator iter = std::find_if( params_.begin(), params_.end(), match_param_symbol( symbol ) );
        if ( iter == params_.end() )
        {
          throw std::out_of_range( "out of range" );
        }
        return *iter;
      }
      const_reference at( size_type pos ) const { return params_.at( pos ); }
      const_reference at( std::string const& symbol ) const
      {
        const_iterator iter = std::find_if( params_.begin(), params_.end(), match_param_symbol( symbol ) );
        if ( iter == params_.end() )
        {
          throw std::out_of_range( "out of range" );
        }
        return *iter;
      }
      parameter id() const
      {
        if ( pinfo_->id_pos < 0 )
        {
          return parameter();
        }
        return at( pinfo_->id_pos );
      }
      
      text_line const& line() const { return line_; }
      void line( text_line const& value ) { line_ = value; }
      template < typename T >
        T const& exinf() const { return boost::any_cast< T& >( exinf_ ); }
      template < typename T >
        void exinf( T const& value ) { exinf_ = value; }

      size_type count_integer_params() const;
        
      //! ���֥������Ȥθ�
      void swap( static_api& other )
      {
        std::swap( pinfo_, other.pinfo_ );
        params_.swap( other.params_ );
        line_.swap( other.line_ );
        exinf_.swap( other.exinf_ );
      }

      bool parse( text::const_iterator& next, text::const_iterator last, 
                  std::map< std::string, info > const& info_map,
                  bool ucn = false, codeset_t codeset = ascii );

      bool set_class( std::string const& id )
      {
        return set_block( "*CLASS", id );
      }
      bool set_domain( std::string const& id )
      {
        return set_block( "*DOMAIN", id );
      }

      /*!
       *  \brief  ID�ֹ�γ��դ�
       *  \param[in]  first   ID�ֹ�����դ��� static_api �����Ƭ����
       *  \param[in]  last    ID�ֹ�����դ��� static_api ��ν�ü + 1
       */
      template < class ForwardIterator >
        static void assign_id( ForwardIterator first, ForwardIterator last )
      {
        std::map< std::string, long > id_map;
        std::set< std::string > slave_id_set;
        std::vector< std::string > id_res;
        typedef std::vector< std::string >::size_type size_type;

        // ͽ��Ѥߤ�ID�ֹ�������Ф�
        for ( ForwardIterator iter( first ); iter != last; ++iter )
        {
          static_api::info const* info = iter->get_info();
          if ( info->id_pos >= 0 )
          {
            if ( !info->slave )
            {
              if ( iter->at( info->id_pos ).symbol[0] == '#' )
              {
                boost::optional< std::tr1::int64_t > id_value = iter->at( info->id_pos ).value;
                if ( id_value )
                {
                  long id = static_cast< long >( *id_value );
                  if ( id > 0 )
                  {
                    long n = static_cast< long >( id_res.size() );
                    if ( n < id + 1 )
                    {
                      n = id + 1;
                    }
                    id_res.resize( n );
                    std::string name( iter->at( info->id_pos ).text );
                    if ( !id_res[ id ].empty() )
                    {
                      fatal( _( "%1% `%2%\' in %3% is duplicated" ), iter->at( info->id_pos ).symbol.c_str() + 1, id, info->api_name );
                    }
                    id_res[ id ] = name;
                  }
                }
              }
            }
          }
        }

        // ͽ�󤵤�Ƥ��ʤ�ID�ֹ��ư���դ�
        long id = 1;
        for ( ForwardIterator iter( first ); iter != last; ++iter )
        {
          static_api::info const* info = iter->get_info();
          if ( info->id_pos >= 0 )
          {
            std::string name( iter->at( info->id_pos ).text );
            if ( !info->slave )
            {
              long id_value = -1;
              if ( iter->at( info->id_pos ).symbol[0] == '#' )
              {
                std::vector< std::string >::iterator id_iter( std::find( id_res.begin(), id_res.end(), name ) );
                if ( id_iter != id_res.end() )  // ����դ��Ѥߤξ��...
                {
                  id_value = id_iter - id_res.begin();
                }
                else  // �ޤ�����դ����Ƥ��ʤ����...
                {
                  long n = static_cast< long >( id_res.size() );
                  while ( id < n && !id_res[ id ].empty() )
                  {
                    ++id;
                  }
                  if ( n < id + 1 )
                  {
                    n = id + 1;
                  }
                  id_res.resize( n );
                  id_res[ id ] = name;
                  id_value = id;
                  iter->at( info->id_pos ).value = id_value;
                }
                if ( id_map.find( name ) != id_map.end() )
                {
                  fatal( iter->line(), _( "`%1%\' is duplicated" ), name );
                }
              }
              else if ( iter->at( info->id_pos ).value )
              {
                id_value = static_cast< long >( iter->at( info->id_pos ).value.get() );
              }
              id_map[ name ] = id_value;
            }
            else  // slave
            {
              if ( id_map[ name ] < 1 )
              {
                fatal( iter->line(), _( "`%1%\' is undefined" ), iter->at( info->id_pos ).text );
              }
              if ( slave_id_set.find( name ) != slave_id_set.end() )  // DEF_TEX��ʣ�����Ƚ��
              {
                fatal( iter->line(), _( "E_OBJ: `%1%\' is duplicated" ), iter->at( info->id_pos ).text );
              }
              slave_id_set.insert( name );
            }
          }
        }

        if ( !id_res.empty() && std::find( id_res.begin() + 1, id_res.end(), std::string() ) != id_res.end() )
        {
          error( _( "`%1%\' id numbers do not continue" ), first->get_info()->type );          
        }
      }
    private:
      class match_param_symbol
      {
      public:
        explicit match_param_symbol( std::string const& symbol ) : symbol_( symbol ) {}
        bool operator()( parameter const& param ) const
        {
          return param.symbol == symbol_;
        }
      private:
        std::string symbol_;
      };

      bool set_block( char const* type, std::string const& id );

      info const* pinfo_;
      std::vector< parameter > params_;
      text_line line_;
      boost::any exinf_;
    };

  }
}

#endif  // ! TOPPERS_ITRONX_STATIC_API_HPP_
