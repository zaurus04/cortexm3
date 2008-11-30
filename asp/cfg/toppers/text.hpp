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
 *  \file   toppers/text.hpp
 *  \brief  �ƥ����ȥǡ��������˴ؤ���������
 *
 *  ���Υե�������������륯�饹
 *  \code
 *  class basic_text< Container, CharT, Traits, Allocator >;
 *  \endcode
 */
#ifndef TOPPERS_TEXT_HPP_
#define TOPPERS_TEXT_HPP_

#include <algorithm>
#include <iterator>
#include <vector>
#include <numeric>
#include "toppers/text_line.hpp"
#include "toppers/misc.hpp"
#include <boost/utility.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/format.hpp>

namespace toppers
{

  /*!
   *  \class  basic_text  text.hpp "toppers/text.hpp"
   *  \brief  �ƥ����ȥǡ��������ƥ�ץ졼�ȥ��饹
   *
   *  �ե����뤫���ɤ߹�����ƥ����ȥǡ����δ�����Ԥ�����Υ��饹�Ǥ���
   *  ���Υ��饹�Ǥϡ��ƥ����ȥǡ�����ñ�ʤ�ʸ����Ȥ��ƤǤϤʤ������ϸ���
   *  �ե�����̾�ȹ��ֹ���ղä������Ǵ������ޤ���
   *
   *  \note   ���Υ��饹�ϥƥ������Խ������Ӥ����ꤷ����ΤǤϤ���ޤ���
   */
  template
  <
    template < typename, class > class Container,
    typename CharT,
    class Traits = std::char_traits< CharT >,
    class Allocator = std::allocator< CharT >
  >
    class basic_text
  {
  public:
    typedef basic_text< Container, CharT, Traits, Allocator > self_t;
    typedef std::basic_string< CharT, Traits, Allocator > string_type;
    typedef ::toppers::text_line line_type;
    typedef basic_line_buf< CharT, Traits, Allocator > line_buf;

    //  �ʲ��ϰ���Ū�ʥ���ƥʤȤθߴ��Τ���η����
    ////////////////////////////////////////////////////////////////////////////////
    typedef CharT value_type;
    typedef Container< line_buf, std::allocator< line_buf > > container;
    typedef value_type& reference;
    typedef value_type const& const_reference;
    typedef value_type* pointer;
    typedef value_type const* const_pointer;
    typedef Allocator allocator_type;
    typedef typename Allocator::difference_type difference_type;
    typedef typename Allocator::size_type size_type;

    /*!
     *  \class  const_iterator text.hpp "toppers/text.hpp"
     *  \brief  toppers::basic_text �Υ��ƥ졼��
     */
    class const_iterator : public boost::iterator_facade< const_iterator, CharT, boost::random_access_traversal_tag, CharT const& >
    {
      friend class boost::iterator_core_access;
    public:
      typedef boost::iterator_facade< const_iterator, CharT, boost::random_access_traversal_tag, CharT const& > base_t;
      typedef typename container::const_iterator row_iterator;
      typedef typename base_t::value_type value_type;
      typedef typename base_t::reference reference;
      typedef typename base_t::pointer pointer;
      typedef typename base_t::difference_type difference_type;

      const_iterator() : row_(), col_( 0 ) {}
      const_iterator( row_iterator row, size_type col = 0 ) : row_( row ), col_( col ) {}
      line_type const& line() const { return row_->line; }
      row_iterator const& get_row() const { return row_; }
      size_type get_col() const { return col_; }
    protected:
      reference dereference() const { return row_->buf[col_]; }
      bool equal( const_iterator const& rhs ) const { return row_ == rhs.row_ && col_ == rhs.col_; }
      void increment() { if ( ++col_ == row_->buf.size() ) { col_ = 0; ++row_; } }
      void decrement() { if ( col_ == 0 ) col_ = ( --row_ )->buf.size(); --col_; }
      void advance( difference_type n )
      {
        typename container::const_iterator row = row_;
        size_type col = col_;
        while ( col + n > row->buf.size() )
        {
          n -= row->buf.size() - col;
          ++row;
          col = 0;
        }
        col += n;
        if ( col == row->buf.size() )
        {
          col = 0;
          ++row;
        }
        row_ = row;
        col_ = col;
      }
      difference_type distance_to( const_iterator const& rhs ) const
      {
        difference_type n;
        typename container::const_iterator row = row_;
        if ( rhs.row_ < row_ )
        {
          n = -static_cast< difference_type >( col_ + ( rhs.row_->buf.size() - rhs.col_ ) );
          while ( --row != rhs.row_ )
          {
            n -= row->buf.size();
          }
        }
        else if ( row_ < rhs.row_ )
        {
          n = col_ + rhs.col_;
          while ( ++row != rhs.row_ )
          {
            n += row->buf.size();
          }
        }
        else
        {
          n = static_cast< difference_type >( rhs.col_ ) - static_cast< difference_type >( col_ );
        }
        return n;
      }
    private:
      typename container::const_iterator row_;
      size_type col_;
    };

    /*!
     *  \class  iterator text.hpp "toppers/text.hpp"
     *  \brief  toppers::basic_text �Υ��ƥ졼��
     */
    class iterator : public const_iterator
    {
    public:
      typedef typename container::iterator row_iterator;
      typedef typename const_iterator::value_type value_type;
      typedef typename const_iterator::reference reference;
      typedef typename const_iterator::pointer pointer;
      typedef typename const_iterator::difference_type difference_type;

      iterator() {}
      explicit iterator( row_iterator row, size_type col = 0 ) : const_iterator( row, col ) {}
      value_type& operator*() const { return const_cast< value_type& >( const_iterator::dereference() ); }
      iterator& operator++() { const_iterator::increment(); return *this; }
      iterator operator++( int ) { iterator t( *this ); const_iterator::increment(); return t; }
      iterator& operator--() { const_iterator::decrement(); return *this; }
      iterator operator--( int ) { iterator t( *this ); const_iterator::decrement(); return t; }
    };

    typedef std::reverse_iterator< const_iterator > const_reverse_iterator;
    typedef std::reverse_iterator< iterator > reverse_iterator;

  public:
    /*!
     *  \brief  �ǥե���ȥ��󥹥ȥ饯��
     */
    basic_text() {}

    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  first   ��������Ѥ���ǡ��������Ƭ
     *  \param  last    ��������Ѥ���ǡ�����ν�ü+1
     */
    basic_text( const_iterator const& first, const_iterator const& last )
    {
      if ( first != last )
      {
        init( first, last );
      }
    }

    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  first   ��������Ѥ���ǡ��������Ƭ
     *  \param  last    ��������Ѥ���ǡ�����ν�ü+1
     *  \note   �ե�����̾��"unknown"�ˤʤ�ޤ���
     */
    template < class InputIterator >
      basic_text( InputIterator first, InputIterator last )
    {
      if ( first != last )
      {
        init( first, last, append_directive );
      }
    }

    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  first   ��������Ѥ���ǡ��������Ƭ
     *  \param  last    ��������Ѥ���ǡ�����ν�ü+1
     *  \param  directive ���Ԥ򥳥�ƥʤ˳�Ǽ���뤿��ν���
     *  \note   �ե�����̾��"unknown"�ˤʤ�ޤ���
     *
     *  directive �� void directive( container& cont, line_buf& buf )�η�����
     *  �Ȥ�ؿ��ؤΥݥ��󥿤ޤ��ϥե��󥯥��Ǥ��뤳�Ȥ����ꤷ�Ƥ��ޤ���
     *  cont �������ǥǡ����γ�Ǽ�˻��Ѥ��륳��ƥʡ� buf �ϣ���ʬ��ʸ��
     *  ��ȥե�����̾�����ֹ���Ǽ�����Хåե��Ǥ���
     */
    template < class InputIterator, class Directive >
      basic_text( InputIterator first, InputIterator last, Directive directive )
    {
      if ( first != last )
      {
        init( first, last, directive );
      }
    }

    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  istr    ��������Ѥ������ϥ��ȥ꡼��
     *  \note   �ե�����̾��"unknown"�ˤʤ�ޤ���
     */
    basic_text( std::basic_istream< CharT, Traits >& istr )
    {
      init( istr, append_directive );
    }

    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  istr    ��������Ѥ������ϥ��ȥ꡼��
     *  \param  directive ���Ԥ򥳥�ƥʤ˳�Ǽ���뤿��ν���
     *  \note   �ե�����̾��"unknown"�ˤʤ�ޤ���
     *
     *  directive �� void directive( container& cont, line_buf& buf )�η�����
     *  �Ȥ�ؿ��ؤΥݥ��󥿤ޤ��ϥե��󥯥��Ǥ��뤳�Ȥ����ꤷ�Ƥ��ޤ���
     *  cont �������ǥǡ����γ�Ǽ�˻��Ѥ��륳��ƥʡ� buf �ϣ���ʬ��ʸ��
     *  ��ȥե�����̾�����ֹ���Ǽ�����Хåե��Ǥ���
     */
    template < class Directive >
      basic_text( std::basic_istream< CharT, Traits >& istr, Directive directive )
    {
      init( istr, directive );
    }

    /*!
     *  \brief  ��Ƭ���֤μ���
     *  \return ��Ƭʸ���ؤΥ��ƥ졼�����֤�
     */
    const_iterator begin() const
    {
      return const_iterator( container_.begin() );
    }

    /*!
     *  \brief  ��Ƭ���֤μ���
     *  \return ��Ƭʸ���ؤΥ��ƥ졼�����֤�
     */
    iterator begin()
    {
      return iterator( container_.begin() );
    }

    /*!
     *  \brief  ��ü����+1�μ���
     *  \return ��üʸ���μ����ǤؤΥ��ƥ졼�����֤�
     */
    const_iterator end() const
    {
      return const_iterator( container_.end() );
    }

    /*!
     *  \brief  ��ü����+1�μ���
     *  \return ��üʸ���μ����ǤؤΥ��ƥ졼�����֤�
     */
    iterator end()
    {
      return iterator( container_.end() );
    }

    /*!
     *  \brief  �ս���Ƭ���֤μ���
     *  \return �ս���Ƭʸ���ؤεե��ƥ졼�����֤�
     */
    const_reverse_iterator rbegin() const
    {
      string_type const* pbuf = &container_.back().buf;
      return const_reverse_iterator( container_.rbegin() + pbuf->empty() ? 0 : pbuf->size()-1 );
    }

    /*!
     *  \brief  �ս���Ƭ���֤μ���
     *  \return �ս���Ƭʸ���ؤεե��ƥ졼�����֤�
     */
    reverse_iterator rbegin()
    {
      string_type* pbuf = &container_.back().buf;
      return reverse_iterator( container_.rbegin() + pbuf->empty() ? 0 : pbuf->size()-1 );
    }

    /*!
     *  \brief  �ս罪ü����+1�μ���
     *  \return �ս罪üʸ���μ����Ǥؤεե��ƥ졼�����֤�
     */
    const_reverse_iterator rend() const
    {
      return const_reverse_iterator( container_.rend() );
    }

    /*!
     *  \brief  �ս罪ü����+1�μ���
     *  \return �ս罪üʸ���μ����Ǥؤεե��ƥ졼�����֤�
     */
    reverse_iterator rend()
    {
      return reverse_iterator( container_.rend() );
    }

    /*!
     *  \brief  ��Ƭʸ���λ���
     *  \return ��Ƭʸ���ؤλ��Ȥ��֤�
     */
    const_reference front() const
    {
      return container_.front().buf[0];
    }

    /*!
     *  \brief  ��Ƭʸ���λ���
     *  \return ��Ƭʸ���ؤλ��Ȥ��֤�
     */
    reference front()
    {
      return container_.front().buf[0];
    }

    /*!
     *  \brief  ��üʸ���λ���
     *  \return ��üʸ���ؤλ��Ȥ��֤�
     */
    const_reference back() const
    {
      string_type const* pbuf = &container_.back().buf;
      return pbuf->at( pbuf->size()-1 );
    }

    /*!
     *  \brief  ��üʸ���λ���
     *  \return ��üʸ���ؤλ��Ȥ��֤�
     */
    reference back()
    {
      string_type* pbuf = &container_.back().buf;
      return pbuf->at( pbuf->size()-1 );
    }

    /*!
     *  \brief  ������֤�ʸ���λ���
     *  \return ������֤�ʸ���ؤλ��Ȥ��֤�
     */
    const_reference at( size_type pos ) const
    {
      return container_.front().buf[pos];
    }

    /*!
     *  \brief  ������֤�ʸ���λ���
     *  \return ������֤�ʸ���ؤλ��Ȥ��֤�
     */
    reference at( size_type pos )
    {
      return container_.front().buf[pos];
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ������ɲ�
     *  \param  first �ɲä��Ѥ���ǡ��������Ƭ
     *  \param  last  �ɲä��Ѥ���ǡ�����ν�ü+1
     */
    void append( const_iterator const& first, const_iterator const& last )
    {
      if ( first != last )
      {
        self_t t( *this );
        t.init( first, last );
        swap( t );
      }
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ������ɲ�
     *  \param  first �ɲä��Ѥ���ǡ��������Ƭ
     *  \param  last  �ɲä��Ѥ���ǡ�����ν�ü+1
     *  \note   �ե�����̾�ȹ��ֹ���ɲ���ν�ü�Τ�Τ��³���ޤ���
     *          �ɲ���˥ǡ������ʤ�����"unknown"�ˤʤ�ޤ���
     */
    template < class InputIterator >
      void append( InputIterator first, InputIterator last )
    {
      append( first, last, append_directive );
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ������ɲ�
     *  \param  first �ɲä��Ѥ���ǡ��������Ƭ
     *  \param  last  �ɲä��Ѥ���ǡ�����ν�ü+1
     *  \param  directive ���Ԥ򥳥�ƥʤ˳�Ǽ���뤿��ν���
     *  \note   �ե�����̾�ȹ��ֹ���ɲ���ν�ü�Τ�Τ��³���ޤ���
     *          �ɲ���˥ǡ������ʤ�����"unknown"�ˤʤ�ޤ���
     *
     *  directive �� void directive( container& cont, line_buf& buf )�η�����
     *  �Ȥ�ؿ��ؤΥݥ��󥿤ޤ��ϥե��󥯥��Ǥ��뤳�Ȥ����ꤷ�Ƥ��ޤ���
     *  cont �������ǥǡ����γ�Ǽ�˻��Ѥ��륳��ƥʡ� buf �ϣ���ʬ��ʸ��
     *  ��ȥե�����̾�����ֹ���Ǽ�����Хåե��Ǥ���
     */
    template < class InputIterator, class Directive >
      void append( InputIterator first, InputIterator last, Directive directive )
    {
      if ( first != last )
      {
        self_t t( *this );
        t.init( first, last, directive );
        swap( t );
      }
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ������ɲ�
     *  \param  istr      �ɲä��Ѥ������ϥ��ȥ꡼��
     *  \note   �ե�����̾�ȹ��ֹ���ɲ���ν�ü�Τ�Τ��³���ޤ���
     *          �ɲ���˥ǡ������ʤ�����"unknown"�ˤʤ�ޤ���
     */
    void append( std::basic_istream< CharT, Traits >& istr )
    {
      append( istr, append_directive );
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ������ɲ�
     *  \param  istr      �ɲä��Ѥ������ϥ��ȥ꡼��
     *  \param  directive ���Ԥ򥳥�ƥʤ˳�Ǽ���뤿��ν���
     *  \note   �ե�����̾�ȹ��ֹ���ɲ���ν�ü�Τ�Τ��³���ޤ���
     *          �ɲ���˥ǡ������ʤ�����"unknown"�ˤʤ�ޤ���
     *
     *  directive �� void directive( container& cont, line_buf& buf )�η�����
     *  �Ȥ�ؿ��ؤΥݥ��󥿤ޤ��ϥե��󥯥��Ǥ��뤳�Ȥ����ꤷ�Ƥ��ޤ���
     *  cont �������ǥǡ����γ�Ǽ�˻��Ѥ��륳��ƥʡ� buf �ϣ���ʬ��ʸ��
     *  ��ȥե�����̾�����ֹ���Ǽ�����Хåե��Ǥ���
     */
    template < class Directive >
      void append( std::basic_istream< CharT, Traits >& istr, Directive directive )
    {
      self_t t( *this );
      t.init( istr, directive );
      swap( t );
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ���������
     *  \param  first �������Ѥ���ǡ��������Ƭ
     *  \param  last  �������Ѥ���ǡ�����ν�ü+1
     */
    void assign( const_iterator const& first, const_iterator const& last )
    {
      self_t t( first, last );
      swap( t );
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ���������
     *  \param  first �������Ѥ���ǡ��������Ƭ
     *  \param  last  �������Ѥ���ǡ�����ν�ü+1
     *  \note   �ե�����̾��"unknown"�ˤʤ�ޤ���
     */
    template < class InputIterator >
      void assign( InputIterator first, InputIterator last )
    {
      self_t t( first, last, append_directive );
      swap( t );
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ���������
     *  \param  first �������Ѥ���ǡ��������Ƭ
     *  \param  last  �������Ѥ���ǡ�����ν�ü+1
     *  \param  directive ���Ԥ򥳥�ƥʤ˳�Ǽ���뤿��ν���
     *  \note   �ե�����̾��"unknown"�ˤʤ�ޤ���
     *
     *  directive �� void directive( container& cont, line_buf& buf )�η�����
     *  �Ȥ�ؿ��ؤΥݥ��󥿤ޤ��ϥե��󥯥��Ǥ��뤳�Ȥ����ꤷ�Ƥ��ޤ���
     *  cont �������ǥǡ����γ�Ǽ�˻��Ѥ��륳��ƥʡ� buf �ϣ���ʬ��ʸ��
     *  ��ȥե�����̾�����ֹ���Ǽ�����Хåե��Ǥ���
     */
    template < class InputIterator, class Directive >
      void assign( InputIterator first, InputIterator last, Directive directive )
    {
      self_t t( first, last, directive );
      swap( t );
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ���������
     *  \param  istr      �������Ѥ������ϥ��ȥ꡼��
     *  \note   �ե�����̾�ȹ��ֹ��������ν�ü�Τ�Τ��³���ޤ���
     *          �ɲ���˥ǡ������ʤ�����"unknown"�ˤʤ�ޤ���
     */
    void assign( std::basic_istream< CharT, Traits >& istr )
    {
      self_t t( istr, append_directive );
      swap( t );
    }

    /*!
     *  \brief  �����ϰϤΥƥ����ȥǡ���������
     *  \param  istr      �������Ѥ������ϥ��ȥ꡼��
     *  \param  directive ���Ԥ򥳥�ƥʤ˳�Ǽ���뤿��ν���
     *  \note   �ե�����̾�ȹ��ֹ��������ν�ü�Τ�Τ��³���ޤ���
     *          �ɲ���˥ǡ������ʤ�����"unknown"�ˤʤ�ޤ���
     *
     *  directive �� void directive( container& cont, line_buf& buf )�η�����
     *  �Ȥ�ؿ��ؤΥݥ��󥿤ޤ��ϥե��󥯥��Ǥ��뤳�Ȥ����ꤷ�Ƥ��ޤ���
     *  cont �������ǥǡ����γ�Ǽ�˻��Ѥ��륳��ƥʡ� buf �ϣ���ʬ��ʸ��
     *  ��ȥե�����̾�����ֹ���Ǽ�����Хåե��Ǥ���
     */
    template < class Directive >
      void assign( std::basic_istream< CharT, Traits >& istr, Directive directive )
    {
      self_t t( istr, directive );
      swap( t );
    }

    /*!
     *  \brief  ��ü��ʸ�����ɲ�
     *  \param  value �ɲä���ʸ��
     */
    void push_back( value_type value )
    {
      if ( container_.empty() || container_.back().line.file != line_.file )
      {
        line_buf buf( initial_line(), string_type( 1, value ) );
        container_.push_back( buf );
      }
      else
      {
        string_type const* pbuf = &container_.back().buf;
        if ( pbuf->at( pbuf->size()-1 ) == widen( '\n' ) )
        {
          ++line_.line;
          line_buf buf( initial_line(), string_type( 1, value ) );
          container_.push_back( buf );
        }
        else
        {
          container_.back().buf += value;
        }
      }
    }

    /*!
     *  \brief  ��ü����ʸ������
     */
    void pop_back()
    {
      if ( container_.empty() )
      {
        container_.pop_back();
      }
      else
      {
        string_type const* pbuf = &container_.back().buf;
        pbuf->resize( pbuf->size()-1 );
        if ( container_.back().buf.empty() )
        {
          container_.pop_back();
        }
      }
    }

    /*!
     *  \brief  ����ƥʤ������ɤ�����Ƚ��
     *  \return ���ξ��� true ���֤�
     */
    bool empty() const
    {
      return container_.empty();
    }

    /*!
     *  \brief  ����ƥʤΥ�����
     *  \return ����ƥʤ˴ޤޤ�Ƥ���ʸ�������֤�
     */
    size_type size() const
    {
      return std::accumulate( container_.begin(), container_.end(), size_type( 0 ), add_line_size );
    }

    /*!
     *  \brief  ����ƥʤθ�
     *  \param  other   ���оݤȤʤ륳��ƥ�
     */
    void swap( self_t& other )
    {
      container_.swap( other.container_ );
      line_.swap( other.line_ );
    }

    /*!
     *  \brief  ����ƥʤΥ��ꥢ
     */
    void clear()
    {
      container_.clear();
      line_.file.clear();
      line_.line = 0;
    }

    void set_line( std::string const& file, long line )
    {
      line_.file = file;
      line_.line = line;
    }

    line_type get_line() const
    {
      return line_;
    }
  private:
    //! Ʊ��Υ���ƥʤ����ϸ��Ȥ�����������
    void init( const_iterator const& first, const_iterator const& last )
    {
      line_buf buf( *first.get_row() );
      if ( first.get_col() > 0 )
      {
        buf.buf = buf.buf.substr( first.get_col() );
      }
      container_.push_back( buf );
      std::copy( boost::next( first ).get_row(), last.get_row(), std::back_inserter( container_ ) );
      buf = *last.get_row();
      buf.buf = buf.buf.substr( 0, last.get_col() );
      container_.push_back( buf );
      line_ = buf.line;
    }

    //! �ۼ�Υ���ƥʤ����ϸ��Ȥ�����������
    template < class InputIterator, class Directive >
      void init( InputIterator first, InputIterator last, Directive directive )
    {
      line_buf buf( initial_line() );
      value_type const nl = widen( '\n' );
      for ( InputIterator iter = first; iter != last; ++iter )
      {
        value_type ch = *iter;
        buf.buf += ch;
        if ( ch == nl )
        {
          directive( container_, buf );
          line_ = buf.line;
        }
      }
      if ( !buf.buf.empty() )
      {
        container_.push_back( buf );
      }
      line_ = buf.line;
    }

    //! ���ϥ��ȥ꡼������ϸ��Ȥ�����������
    template < class Directive >
      void init( std::basic_istream< CharT, Traits >& istr, Directive directive )
    {
      line_buf buf( initial_line() );
      value_type const nl = widen( '\n' );
      while ( istr )
      {
        value_type ch;
        istr.get( ch );
        buf.buf += ch;
        if ( ch == nl )
        {
          directive( container_, buf );
          line_ = buf.line;
        }
      }
      if ( !buf.buf.empty() )
      {
        container_.push_back( buf );
      }
      line_ = buf.line;
    }

    //! �ե�����̾�����ֹ�ν������μ���
    line_type const initial_line() const
    {
      if ( line_.line > 0 )
      {
        return line_;
      }
      if ( container_.empty() )
      {
        return line_type( "unknown", 1 );
      }
      return container_.back().line;
    }

    //! ���󥰥�Х���ʸ�������̷�����ʸ�����ؤ��Ѵ�
    static value_type widen( char ch )
    {
      return ::toppers::widen< value_type >( ch );
    }

    //! size �ؿ���ǻ��Ѥ����߻�����
    static size_type add_line_size( size_type value, line_buf const& buf )
    {
      return value + buf.buf.size();
    }

    //! Directive �Υǥե���Ƚ���
    static void append_directive( container& cont, line_buf& buf )
    {
      cont.push_back( buf );
      ++buf.line.line;
      buf.buf.clear();
    }
  private:
    container container_;
    line_type line_;
  };

  typedef basic_text< std::vector, char > text;

  inline text_line const& get_text_line( text::const_iterator iter )
  {
    return iter.line();
  }

  inline text_line const& get_text_line( text::iterator iter )
  {
    return iter.line();
  }

}

#endif  // ! TOPPERS_TEXT_HPP_
