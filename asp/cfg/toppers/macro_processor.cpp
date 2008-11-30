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
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <functional>
#include <iterator>
#include <sstream>
#include <fstream>
#include <limits>
#include "toppers/workaround.hpp"
#include "toppers/io.hpp"
#include "toppers/cpp.hpp"
#include "toppers/global.hpp"
#include "toppers/macro_processor.hpp"
#include "toppers/diagnostics.hpp"
#include "toppers/misc.hpp"
#include <boost/spirit.hpp>
#include <boost/spirit/dynamic.hpp>
#include <boost/spirit/tree/parse_tree.hpp>
#include <boost/lexical_cast.hpp>

// ��ɸ��ޥ������������
#ifdef  max
#undef  max
#endif
#ifdef  min
#undef  min
#endif

#define DEBUG_TRACE   0

namespace toppers
{

  namespace
  {

    struct expr_error {};

     /*!
      *  \struct parser macro_processor.cpp "toppers/macro_processor.cpp"
      *  \brief  �ޥ�����˵��Ҥ���뼰�Υѡ���
      */
    struct parser : boost::spirit::grammar< parser >
    {
      enum rule_id_t
      {
        id_other = 0,

        id_expression, id_assignment_expr, id_logical_or_expr, id_logical_and_expr,
        id_or_expr, id_xor_expr, id_and_expr, id_equality_expr, id_relational_expr,
        id_shift_expr, id_additive_expr, id_multiplicative_expr, id_unary_expr,
        id_postfix_expr, id_primary_expr, id_lvalue_expr, id_identifier, id_constant,
        id_string_literal, id_ordered_list, id_ordered_sequence, id_ordered_item,

        id_root, id_top, id_if_, id_foreach_, id_joineach_, id_error_, id_warning_,
        id_file_, id_expr_, id_plain,

        id_illegal = -1
      };
      enum expected_t
      {
        doller_expected, end_expected, close_paren_expected, close_brace_expected,
        close_bracket_expected
      };

      /*!
       *  \struct error_handler static_api_parser.hpp "toppers/itronx/static_api_parser.hpp"
       *  \brief  ��ŪAPI�ι�ʸ���Ϥˤ����륨�顼�����ե��󥯥�
       */
      struct error_handler
      {
        template < class Scanner, class Error >
          boost::spirit::error_status<> operator()( Scanner const& scan, Error const& error ) const
        {
          typename Error::iterator_t iter( error.where );
          while ( iter != scan.last && *iter != '\0' && *iter != '\n' )
          {
            ++iter;
          }
          std::string str;
          if ( error.where == iter )
          {
            str = _( "end of line" );
          }
          else
          {
            str = '\"' + std::string( error.where, iter ) + '\"';
          }

          text_line ln;
          if ( error.where != scan.last )
          {
            ln = get_text_line( error.where );
          }
          else
          {
            // �ƥ�ץ졼�ȥե�����κǽ��Ԥ����
            typename Error::iterator_t prev( scan.first );
            for ( iter = scan.first; iter != scan.last; ++iter )
            {
              prev = iter;
            }
            ln = get_text_line( prev );
          }
          switch ( error.descriptor )
          {
          case doller_expected:
            toppers::fatal( ln, _( "missing `%1%\' before %2%" ), '$', str );
            break;
          case end_expected:
            toppers::fatal( ln, _( "missing `%1%\' before %2%" ), "$END$", str );
            break;
          case close_paren_expected:
            toppers::fatal( ln, _( "missing `%1%\' before %2%" ), ")", str );
            break;
          case close_brace_expected:
            toppers::fatal( ln, _( "missing `%1%\' before %2%" ), "}", str );
            break;
          case close_bracket_expected:
            toppers::fatal( ln, _( "missing `%1%\' before %2%" ), "]", str );
            break;
          }
          return  boost::spirit::error_status<>( boost::spirit::error_status<>::fail );
        }
      };


      template < class Scanner >
        struct definition
      {
        typedef boost::spirit::rule< Scanner, boost::spirit::dynamic_parser_tag > rule_t;
        typedef boost::spirit::guard< expected_t > guard_t;
        typedef boost::spirit::assertion< expected_t > assertion_t;

        rule_t  expression,
                assignment_expr,
                logical_or_expr,
                logical_and_expr,
                or_expr,
                xor_expr,
                and_expr,
                equality_expr,
                relational_expr,
                shift_expr,
                additive_expr,
                multiplicative_expr,
                unary_expr,
                postfix_expr,
                primary_expr,
                lvalue_expr,
                identifier,
                constant,
                string_literal,
                ordered_list,
                ordered_sequence,
                ordered_item;

        rule_t  root,
                top,
                if_,
                foreach_,
                joineach_,
                error_,
                warning_,
                file_,
                expr_,
                call,
                plain;

        guard_t guard_if_,
                guard_foreach_,
                guard_joineach_,
                guard_expr,
                guard_postfix_expr,
                guard_lvalue_expr,
                guard_ordered_list;

        assertion_t expect_doller,
                    expect_end,
                    expect_close_paren,
                    expect_close_brace,
                    expect_close_bracket;

        definition( parser const& self )
          : expect_doller( doller_expected ),
            expect_end( end_expected ),
            expect_close_paren( close_paren_expected ),
            expect_close_brace( close_brace_expected ),
            expect_close_bracket( close_bracket_expected )
        {
          using namespace boost::spirit;

          set_id();

          expression =
              logical_or_expr;
          assignment_expr =
              lvalue_expr >> '=' >> expression;
          logical_or_expr =
              logical_and_expr >> *( "||" >> logical_and_expr );
          logical_and_expr =
              or_expr >> *( "&&" >> or_expr );
          or_expr =
              xor_expr >> *( '|' >> xor_expr );
          xor_expr =
              and_expr >> *( '^' >> and_expr );
          and_expr =
              equality_expr >> *( '&' >> equality_expr );
          equality_expr =
              relational_expr >> *( ( str_p( "==" ) | "!=" ) >> relational_expr );
          relational_expr =
              shift_expr >> *( ( str_p( "<=" ) | ">=" | "<" | ">" ) >> shift_expr );
          shift_expr =
              additive_expr >> *( ( str_p( "<<" ) | ">>" ) >> additive_expr );
          additive_expr =
              multiplicative_expr >> *( chset<>( "+-" ) >> multiplicative_expr );
          multiplicative_expr =
              unary_expr >> *( chset<>( "*/%" ) >> unary_expr );
          unary_expr =
              *chset<>( "-+~!" ) >> postfix_expr;
          postfix_expr =
            guard_postfix_expr
            (
                ( identifier >> '(' >> *( expression % ',' ) >> expect_close_paren( ch_p( ')' ) ) )
              | primary_expr
            )
            [
              error_handler()
            ];
          primary_expr =
              lvalue_expr | ordered_list | constant | string_literal
            | ( '(' >> expression >> ')' );
          lvalue_expr =
            guard_lvalue_expr
            (
                ( identifier >> '[' >> expression >> expect_close_bracket( ch_p( ']' ) ) )
              | identifier
            )
            [
              error_handler()
            ];
          identifier =
              leaf_node_d[ lexeme_d[ ( alpha_p | '_' ) >> *( alnum_p | '_' | '.' ) ] ];
          constant =
              leaf_node_d
              [
                lexeme_d
                [
                  if_p( '0' ) // 16�ʤޤ���8��
                  [
                    !(
                        ( ( ch_p( 'x' ) | 'X' ) >> ( hex_p | +xdigit_p ) )
                      | ( oct_p | +chset<>( "0-7" ) )
                     )
                  ]
                  .else_p // 10��
                  [
                    ( int_p | +digit_p )
                  ]
                ]
              ];
          string_literal =
              leaf_node_d[ lexeme_d[ '\"' >> *( c_escape_ch_p - '\"' ) >> '\"' ] ];
          ordered_list =
            guard_ordered_list
            (
              '{' >> !( ( ordered_sequence | ordered_item ) >> *( ';' >> ( ordered_sequence | ordered_item ) ) ) >> expect_close_brace( ch_p( '}' ) )
            )
            [
              error_handler()
            ];
          ordered_sequence =
              ( constant >> ',' >> constant >> ',' >> "..." >> ',' >> constant );
          ordered_item =
              expression >> *( ',' >> expression );

          root =
              top >> lexeme_d[ !space_p ];  // Boost 1.34 �к�
          top =
              *( if_ | foreach_ | joineach_ | warning_ | error_ | file_ | expr_ | plain );
          if_ =
            guard_if_
            (
                ( "$IF" >> expression >> expect_doller( ch_p( '$' ) ) >> top >> "$ELSE$" >> top >> expect_end( str_p( "$END$" ) ) )
              | ( "$IF" >> expression >> expect_doller( ch_p( '$' ) ) >> top >> expect_end( str_p( "$END$" ) ) )
            )
            [
              error_handler()
            ];
          foreach_ =
            guard_foreach_
            (
              "$FOREACH" >> identifier >> expression >> expect_doller( ch_p( '$' ) ) >> top >> expect_end( str_p( "$END$" ) )
            )
            [
              error_handler()
            ];
          joineach_ =
            guard_joineach_
            (
              "$JOINEACH" >> identifier >> expression >> expression >> expect_doller( ch_p( '$' ) ) >> top >> expect_end( str_p( "$END$" ) )
            )
            [
              error_handler()
            ];
          warning_ =
              "$WARNING$" >> top >> "$END$" >> !eol_p
            | "$WARNING" >> expression >> '$' >> top >> "$END$";
          error_ =
              "$ERROR$" >> top >> "$END$" >> !eol_p
            | "$ERROR" >> expression >> '$' >> top >> "$END$";
          file_ =
              "$FILE" >> string_literal >> '$';
          expr_ =
            guard_expr
            (
              ( ( '$' >> ( assignment_expr | expression ) >> expect_doller( ch_p( '$' ) ) ) - "$END$" - "$ELSE$" )
            )
            [
              error_handler()
            ];
          plain =
              leaf_node_d[ lexeme_d[ +( anychar_p - '$' ) | "$$" ] ];
        }
        rule_t const& start() const { return root; }
        void set_id()
        {
          expression.set_id( id_expression );
          assignment_expr.set_id( id_assignment_expr );
          logical_or_expr.set_id( id_logical_or_expr );
          logical_and_expr.set_id( id_logical_and_expr );
          or_expr.set_id( id_or_expr );
          xor_expr.set_id( id_xor_expr );
          and_expr.set_id( id_and_expr );
          equality_expr.set_id( id_equality_expr );
          relational_expr.set_id( id_relational_expr );
          shift_expr.set_id( id_shift_expr );
          additive_expr.set_id( id_additive_expr );
          multiplicative_expr.set_id( id_multiplicative_expr );
          unary_expr.set_id( id_unary_expr );
          postfix_expr.set_id( id_postfix_expr );
          primary_expr.set_id( id_primary_expr );
          lvalue_expr.set_id( id_lvalue_expr );
          identifier.set_id( id_identifier );
          constant.set_id( id_constant );
          string_literal.set_id( id_string_literal );
          ordered_list.set_id( id_ordered_list );
          ordered_sequence.set_id( id_ordered_sequence );
          ordered_item.set_id( id_ordered_item );

          root.set_id( id_root );
          top.set_id( id_top );
          if_.set_id( id_if_ );
          foreach_.set_id( id_foreach_ );
          joineach_.set_id( id_joineach_ );
          error_.set_id( id_error_ );
          warning_.set_id( id_warning_ );
          file_.set_id( id_file_ );
          expr_.set_id( id_expr_ );
          plain.set_id( id_plain );
        }
      };

      parser()
      {
      }
    };

    typedef macro_processor::element element;
    typedef macro_processor::var_t var_t;
    typedef macro_processor::context context;

    //! �ѿ����ݻ�������ͤλ���
    std::tr1::int64_t get_i( var_t const& var, context const* p_ctx )
    {
      if ( var.empty() )
      {
        fatal( p_ctx->line, _( "non-value is referred" ) );
        return 0;
      }
      element e = var.front();
      if ( !e.i )
      {
        fatal( p_ctx->line, _( "non-value is referred" ) );
        return 0;
      }
      return e.i.get();
    }
    //! �ѿ����ݻ�����ʸ����λ���
    std::string get_s( var_t const& var, context const* p_ctx )
    {
      if ( var.empty() )
      {
        return "";
      }
      std::string result;
      for ( var_t::const_iterator iter( var.begin() ), last( var.end() ); iter != last; ++iter )
      {
        if ( !iter->s.empty() )
        {
          result += iter->s;
        }
        else if ( iter->i )
        {
          result += boost::lexical_cast< std::string >( iter->i.get() );
        }
        if ( boost::next( iter ) != last )
        {
          result += ",";
        }
      }
      return result;
    }

    typedef boost::spirit::tree_node< boost::spirit::node_iter_data< text::const_iterator > > tree_node_t;
    bool eval_node( tree_node_t const& node, context* p_ctx );

    //! ������
    bool assignment_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0 1   2
      // lhs = rhs
      if ( eval_node( node.children[0], p_ctx ) )
      {
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        std::string name( get_s( lhs, p_ctx ) );
        if ( eval_node( node.children[2], p_ctx ) )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          var_t old_var( p_ctx->var_map[ name ] );
          p_ctx->var_map[ name ] = rhs;
          if ( p_ctx->hook_on_assign != 0 )
          {
            ( *p_ctx->hook_on_assign )( node.children[0].value.begin().line(), name, old_var, rhs, p_ctx );
          }
        }
      }
      return true;
    }

    //! �����¼�
    bool logical_or_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0  1   2
      // lhs || rhs ...
      bool result = true;

      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 2; i < n; i += 2 )
        {
          std::tr1::int64_t value = 0;
          try
          {
            value = get_i( lhs, p_ctx );
          }
          catch ( expr_error& )
          {
            error( node.children[0].value.begin().line(), _( "`%1%\' does not have a value" ), get_s( lhs, p_ctx ) );
            throw;
          }
          if ( value )
          {
            break;
          }
          result = eval_node( node.children[i], p_ctx );
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          element e;
          std::tr1::int64_t value2 = 0;
          try
          {
            value2 = get_i( rhs, p_ctx );
          }
          catch ( expr_error& )
          {
            error( node.children[i].value.begin().line(), _( "`%1%\' does not have a value" ), get_s( lhs, p_ctx ) );
            throw;
          }
          e.i = ( value || value2 );
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return result;
    }

    //! �����Ѽ�
    bool logical_and_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0  1   2
      // lhs && rhs ...
      bool result = true;

      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 2; i < n; i += 2 )
        {
          std::tr1::int64_t value = 0;
          try
          {
            value = get_i( lhs, p_ctx );
          }
          catch ( expr_error& )
          {
            error( node.children[0].value.begin().line(), _( "`%1%\' does not have a value" ), get_s( lhs, p_ctx ) );
            throw;
          }
          if ( !value )
          {
            break;
          }
          result = eval_node( node.children[i], p_ctx );
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          element e;
          std::tr1::int64_t value2 = 0;
          try
          {
            value2 = get_i( rhs, p_ctx );
          }
          catch ( expr_error& )
          {
            error( node.children[i].value.begin().line(), _( "`%1%\' does not have a value" ), get_s( lhs, p_ctx ) );
            throw;
          }
          e.i = ( value && value2 );
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return result;
    }

    //! �ӥå��¼�
    bool or_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0 1   2
      // lhs | rhs ...
      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1; ( i < n ) && eval_node( node.children[i+1], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          element e;
          e.i = ( get_i( lhs, p_ctx ) | get_i( rhs, p_ctx ) );
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! ��¾Ū�����¼�
    bool xor_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0 1   2
      // lhs ^ rhs ...
      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1; ( i < n ) && eval_node( node.children[i+1], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          element e;
          e.i = ( get_i( lhs, p_ctx ) ^ get_i( rhs, p_ctx ) );
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! �ӥå��Ѽ�
    bool and_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0 1   2
      // lhs & rhs ...
      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1; ( i < n ) && eval_node( node.children[i+1], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          element e;
          e.i = ( get_i( lhs, p_ctx ) & get_i( rhs, p_ctx ) );
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! ��������==��!=��
    bool equality_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0  1   2
      // lhs op rhs ...
      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1; ( i < n ) && eval_node( node.children[i+1], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          std::string op( node.children[i].value.begin(), node.children[i].value.end() );
          std::tr1::int64_t value;
          if ( op == "==" )
          {
            value = ( get_i( lhs, p_ctx ) == get_i( rhs, p_ctx ) );
          }
          else
          {
            value = ( get_i( lhs, p_ctx ) != get_i( rhs, p_ctx ) );
          }
          element e;
          e.i = value;
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! �ط������������
    bool relational_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0  1   2
      // lhs op rhs ...
      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1; ( i < n ) && eval_node( node.children[i+1], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          std::string op( node.children[i].value.begin(), node.children[i].value.end() );
          std::tr1::int64_t value;
          if ( op == "<" )
          {
            value = ( get_i( lhs, p_ctx ) < get_i( rhs, p_ctx ) );
          }
          else if ( op == "<=" )
          {
            value = ( get_i( lhs, p_ctx ) <= get_i( rhs, p_ctx ) );
          }
          else if ( op == ">" )
          {
            value = ( get_i( lhs, p_ctx ) > get_i( rhs, p_ctx ) );
          }
          else
          {
            value = ( get_i( lhs, p_ctx ) >= get_i( rhs, p_ctx ) );
          }
          element e;
          e.i = value;
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! ���եȼ�
    bool shift_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0  1   2
      // lhs op rhs ...
      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1; ( i < n ) && eval_node( node.children[i+1], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          std::string op( node.children[i].value.begin(), node.children[i].value.end() );
          std::tr1::int64_t value = get_i( lhs, p_ctx );
          std::tr1::int64_t shift = get_i( rhs, p_ctx );
          if ( shift < 0 )  // ����ͤǥ��եȤ��褦�Ȥ���
          {
            error( node.children[0].value.begin().line(), _( "shift with nagative value `%1%\'" ), shift );
          }
          if ( shift > 64 )
          {
            error( node.children[0].value.begin().line(), _( "shift with too large value `%1%\'" ), shift );
          }
          if ( op == "<<" )
          {
            if ( value < 0 )
            { // ����ͤΥ��եȤϤǤ��ʤ�
              error( node.children[0].value.begin().line(), _( "negative value `%1%\' is shift" ), value );
            }
            else if ( shift != 0 && static_cast< std::tr1::int64_t >( static_cast< std::tr1::uint64_t >( 1 ) << ( 63 - shift ) ) <= value )
            { // ���եȤη�̤���ˤʤ�
              error( node.children[0].value.begin().line(), _( "shift with too large value `%1%\'" ), shift );
            }
            value = value << shift;
          }
          else
          {
            if ( value < 0 )  // ����Ū�˻��ѥ��եȤ�����
            {
              value = static_cast< std::tr1::int64_t >( ( static_cast< std::tr1::uint64_t >( value ) >> shift ) | ( ~static_cast< std::tr1::uint64_t >( 0 ) << shift ) );
            }
            else
            {
              value = value >> shift;
            }
          }
          element e;
          e.i = value;
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! �ø���
    bool additive_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0  1   2
      // lhs op rhs ...
      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1; ( i < n ) && eval_node( node.children[i+1], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          std::string op( node.children[i].value.begin(), node.children[i].value.end() );
          std::tr1::int64_t x = get_i( lhs, p_ctx );
          std::tr1::int64_t y = get_i( rhs, p_ctx );
          element e;
          if ( op == "+" )
          {
            if ( ( y > 0 && ( std::numeric_limits< std::tr1::int64_t >::max() - y ) < x )
              || ( y < 0 && ( std::numeric_limits< std::tr1::int64_t >::min() - y ) > x ) )
            {
              error( node.children[0].value.begin().line(), _( "overflow at `%1%\'" ), get_s( lhs, p_ctx ) + "+" + get_s( rhs, p_ctx ) );
              // e.i ���ͤϥ��åȤ���ʤ�
            }
            else
            {
              e.i = x + y;
            }
          }
          else  // "-"
          {
            if ( ( y < 0 && ( std::numeric_limits< std::tr1::int64_t >::max() + y ) < x )
              || ( y > 0 && ( std::numeric_limits< std::tr1::int64_t >::min() + y ) > x ) )
            {
              error( node.children[0].value.begin().line(), _( "overflow at `%1%\'" ), get_s( lhs, p_ctx ) + "-" + get_s( rhs, p_ctx ) );
              // e.i ���ͤϥ��åȤ���ʤ�
            }
            else
            {
              e.i = x - y;
            }
          }
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! �����
    bool multiplicative_expr( tree_node_t const& node, context* p_ctx )
    {
      //   0  1   2
      // lhs op rhs ...
      if ( eval_node( node.children[0], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // ���դΤ�
        {
          return true;
        }
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1; ( i < n ) && eval_node( node.children[i+1], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          std::string op( node.children[i].value.begin(), node.children[i].value.end() );
          std::tr1::int64_t x = get_i( lhs, p_ctx );
          std::tr1::int64_t y = get_i( rhs, p_ctx );
          element e;
          if ( op == "*" )
          {
            if ( ( ( x < 0 ) == ( y < 0 ) ) && ( std::numeric_limits< std::tr1::int64_t >::max() / y < x )
              || ( ( x < 0 ) != ( y < 0 ) ) && ( std::numeric_limits< std::tr1::int64_t >::min() / y > x ) )
            {
              error( node.children[0].value.begin().line(), _( "overflow at `%1%\'" ), get_s( lhs, p_ctx ) + "*" + get_s( rhs, p_ctx ) );
              // e.i ���ͤϥ��åȤ���ʤ�
            }
            else
            {
              e.i = x * y;
            }
          }
          else
          {
            if ( y == 0 )
            {
              error( node.value.begin().line(), _( "devide by zero" ) );
              // e.i �ˤ��ͤ����åȤ���ʤ�
            }
            else
            {
              std::tr1::int64_t value;
              // �����Ϥ����ǰ����Υ��ڥ��ɤ���ξ��ν�����Ԥ�ɬ�פ����롣
              // ������Ѥʽ����Ϥϼ¼�Ū�ˤʤ��Τ�����
              if ( op == "/" )
              {
                value = ( x / y );
              }
              else  // "%"
              {
                value = ( x % y );
              }
              e.i = value;
            }
          }
          lhs[0] = e;
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! ñ�༰�ʸ��ּ���ñ��黻�� �켡����
    bool unary_expr( tree_node_t const& node, context* p_ctx )
    {
      //  0 1..n-2          n-1
      // op ...... primary_expr
      if ( eval_node( node.children[ node.children.size() - 1 ], p_ctx ) )
      {
        std::size_t const n = node.children.size();
        if ( n == 1 )  // �켡���Τ�
        {
          return true;
        }
        var_t expr( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( long i = static_cast< long >( n ) - 2, t = 0; i >= 0 && eval_node( node.children[i+1], p_ctx ); i-- )
        {
          std::string op( node.children[i].value.begin(), node.children[i].value.end() );
          element e;
          std::tr1::int64_t value = 0;
          try
          {
            value = get_i( expr, p_ctx );
          }
          catch ( expr_error& )
          {
            error( node.children[0].value.begin().line(), _( "`%1%\' is undefined" ), get_s( expr, p_ctx ) );
            throw;
          }
          if ( op == "+" )
          {
            e.i = +value;
          }
          else if ( op == "-" )
          {
            if ( value == std::numeric_limits< std::tr1::int64_t >::min() )
            {
              error( node.children[0].value.begin().line(), _( "overflow at `%1%\'" ), "-" + get_s( expr, p_ctx ) );
              // e.i ���ͤϥ��åȤ���ʤ�
            }
            else
            {
              e.i = -value;
            }
          }
          else if ( op == "~" )
          {
            e.i = ~value;
          }
          else if ( op == "!" )
          {
            e.i = !value;
          }
          expr[0] = e;  // �黻��̤����Ѥ���
          value = *e.i;
          if ( i == t )
          {
            break;
          }
        }
        p_ctx->stack.push( expr );
      }
      return true;
    }

    //! ���ּ����Ȥ߹��ߴؿ��ƤӽФ����켡����
    bool postfix_expr( tree_node_t const& node, context* p_ctx )
    {
      //            0 1    2 3 4..2+2*n-1 2+2*n 2+2*n+1 
      //   identifier ( arg0 , ..........  argn       )
      // primary_expr
      if ( eval_node( node.children[0], p_ctx ) )
      {
        if ( node.children.size() > 1 )   // �ؿ��θƤӽФ�
        {
          var_t ident( p_ctx->stack.top() ); p_ctx->stack.pop();
          std::string func_name( get_s( ident, p_ctx ) );
          std::map< std::string, macro_processor::func_t >::const_iterator iter( p_ctx->func_map.find( func_name ) );
          if ( iter == p_ctx->func_map.end() )  // ����ʴؿ��Ϥʤ�
          {
            error( node.children[0].value.begin().line(), _( "function `%1%\' is undefined" ), func_name );
            p_ctx->stack.push( var_t() );
          }
          else
          {
            std::vector< var_t > arg_list;
            for ( std::size_t i = 0, n = node.children.size() - 1; 2 + 2*i < n; i++ )
            {
              if ( eval_node( node.children[2 + 2*i], p_ctx ) )
              {
                var_t arg( p_ctx->stack.top() ); p_ctx->stack.pop();
                arg_list.push_back( arg );
              }
            }
            var_t result = ( *iter->second.f )( node.children[0].value.begin().line(), arg_list, p_ctx );
            p_ctx->stack.push( result );
          }
        }
      }
      return true;
    }

    //! �켡���ʺ����ͼ���(��)��
    bool primary_expr( tree_node_t const& node, context* p_ctx )
    {
      bool result = true;

      if ( node.children.size() == 1 )
      {
        result = eval_node( node.children[0], p_ctx );
        if ( node.children[0].value.id() == parser::id_lvalue_expr )
        {
          var_t ident( p_ctx->stack.top() ); p_ctx->stack.pop();
          std::string name( get_s( ident, p_ctx ) );
          var_t value( p_ctx->var_map[ name ] );
          p_ctx->stack.push( value );
        }
      }
      else
      {
        // 0          1 2
        // ( expression )
        result = eval_node( node.children[1], p_ctx );
      }
      return result;
    }

    //! �����ͼ����ѿ��������ѿ���
    bool lvalue_expr( tree_node_t const& node, context* p_ctx )
    {
      //          0 1          2 3
      // identifier
      // identifier [ expression ]
      if ( eval_node( node.children[0], p_ctx ) )
      {
        if ( ( node.children.size() > 1 ) && eval_node( node.children[2], p_ctx ) )
        {
          var_t expr( p_ctx->stack.top() ); p_ctx->stack.pop();
          var_t ident( p_ctx->stack.top() ); p_ctx->stack.pop();
          element e;
          std::string subscript;
          try
          {
            std::tr1::int64_t i = get_i( expr, p_ctx );
            subscript = boost::lexical_cast< std::string >( i );
          }
          catch ( expr_error& )
          {
            subscript = get_s( expr, p_ctx );
            error( node.children[0].value.begin().line(), _( "`%1%\' does not have a value" ), subscript );
            throw;
          }
          e.s = ( boost::format( "%s[%s]" ) % get_s( ident, p_ctx ) % subscript ).str();
          p_ctx->stack.push( var_t( 1, e ) );
        }
      }
      return true;
    }

    //! ���̻�
    bool identifier( tree_node_t const& node, context* p_ctx )
    {
      element e;
      std::string ident( node.children[0].value.begin(), node.children[0].value.end() );
      std::string::size_type n = ident.find_first_not_of( " \t\r\n" );
      e.s = ident.c_str() + n;
      p_ctx->stack.push( var_t( 1, e ) );
      return true;
    }

    //! �������
    bool constant( tree_node_t const& node, context* p_ctx )
    {
      element e;
      e.s.assign( node.children[0].value.begin(), node.children[0].value.end() );
      std::istringstream iss( e.s );
      iss.unsetf( std::ios_base::basefield );
      std::tr1::int64_t value;
      iss >> value;
      if ( iss.bad() )
      {
        error( node.children[0].value.begin().line(), _( "overflow at `%1%\'" ), e.s );
      }
      e.i = value;
      p_ctx->stack.push( var_t( 1, e ) );
      return true;
    }

    //! ʸ����
    bool string_literal( tree_node_t const& node, context* p_ctx )
    {
      // 0 1..n-2 n-1
      // " ......   "
      element e;
      // �����ǹ�ʸ���顼�㳰�ˤʤ뤳�ȤϤ������ʤ����ʹ�ʸ���ϸ�ʤΤǡ�
      e.s = expand_quote( std::string( node.children[0].value.begin(), node.children[0].value.end() ) );
      p_ctx->stack.push( var_t( 1, e ) );
      return true;
    }

    //! ����դ��ꥹ��
    bool ordered_list( tree_node_t const& node, context* p_ctx )
    {
      // 0                1 2     n-1
      // { ordered_sequence ; ...   }
      // {     ordered_item ; ...   }
      if ( node.children.size() < 3 )
      {
        p_ctx->stack.push( var_t() );
      }
      else if ( eval_node( node.children[1], p_ctx ) )
      {
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1, n = node.children.size(); ( i+2 < n ) && eval_node( node.children[i+2], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          std::copy( rhs.begin(), rhs.end(), std::back_inserter( lhs ) );
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! ����դ��ꥹ�ȡ����������
    bool ordered_sequence( tree_node_t const& node, context* p_ctx )
    {
      //   0 1   2 3   4 5   6
      // int , int , ... , int
      if ( eval_node( node.children[0], p_ctx ) )
      {
        var_t first( p_ctx->stack.top() ); p_ctx->stack.pop();
        if ( eval_node( node.children[2], p_ctx ) )
        {
          var_t second( p_ctx->stack.top() ); p_ctx->stack.pop();
          if ( eval_node( node.children[6], p_ctx ) )
          {
            var_t last( p_ctx->stack.top() ); p_ctx->stack.pop();
            std::tr1::int64_t a0 = get_i( first, p_ctx );
            std::tr1::int64_t a1 = get_i( second, p_ctx );
            std::tr1::int64_t an = get_i( last, p_ctx );
            std::tr1::int64_t d = a1 - a0;
            if ( ( an - a0 ) % d != 0 )
            {
              error( node.children[0].value.begin().line(), _( "illegal arithmetic sequence" ) );
            }
            else
            {
              for ( std::tr1::int64_t i = a1, t = an + d; i != t; i += d )
              {
                element e;
                e.i = i;
                first.push_back( e );
              }
              first[1].s = second[0].s;
              first.back().s = last[0].s;
            }
            p_ctx->stack.push( first );
          }
        }
      }
      return true;
    }

    //! ����դ��ꥹ�ȡ��󵭡�
    bool ordered_item( tree_node_t const& node, context* p_ctx )
    {
      //   0 1   2
      // int , int ...
      if ( eval_node( node.children[0], p_ctx ) )
      {
        var_t lhs( p_ctx->stack.top() ); p_ctx->stack.pop();
        for ( std::size_t i = 1, n = node.children.size(); ( i < n ) && eval_node( node.children[i+1], p_ctx ); i += 2 )
        {
          var_t rhs( p_ctx->stack.top() ); p_ctx->stack.pop();
          lhs.push_back( rhs[0] );
        }
        p_ctx->stack.push( lhs );
      }
      return true;
    }

    //! �ȥåץ�٥�
    bool top( tree_node_t const& node, context* p_ctx )
    {
      bool result = true;

      for ( std::size_t i = 0, n = node.children.size(); i < n; i++ )
      {
        for ( text::const_iterator iter( node.children[i].value.begin() ), last( node.children[i].value.end() );
              iter != last;
              ++iter )
        {
          char c = *iter;
          if ( !std::isspace( static_cast< unsigned char >( c ) ) )
          {
            break;
          }
          if ( c != '\n' )
          {
            p_ctx->target_file << c;
          }
        }
        result &= eval_node( node.children[i], p_ctx );
      }
      return result;
    }

    //! $IF̿��
    bool if_( tree_node_t const& node, context* p_ctx )
    {
      bool result = true;

      if ( node.children.empty() )
      {
        fatal( node.value.begin().line(), "no body of %1%", "'IF' or 'ELSE'" );
      }

      //   0          1 2   3      4   5     6
      // $IF expression $ top  $END$
      // $IF expression $ top $ELSE$ top $END$
      if ( eval_node( node.children[1], p_ctx ) )   // expression
      {
        var_t expr( p_ctx->stack.top() ); p_ctx->stack.pop();
        bool cond = false;
        try
        {
          cond = !!get_i( expr, p_ctx );
        }
        catch ( expr_error& )
        {
          error( node.children[0].value.begin().line(), _( "`%1%\' does not have a value" ), get_s( expr, p_ctx ) );
          throw;
        }
        if ( cond )           // $IF expr$
        {
          result &= eval_node( node.children[3], p_ctx );   // top
        }
        else if ( node.children.size() == 7 ) // $ELSE$
        {
          result &= eval_node( node.children[5], p_ctx );   // top
        }
      }
      return result;
    }

    //! FOREACH̿��
    bool foreach_( tree_node_t const& node, context* p_ctx )
    {
      bool result = true;

      if ( node.children.empty() )
      {
        fatal( node.value.begin().line(), "no body of %1%", "'FOREACH'" );
      }

      //        0          1          2 3   4     5
      // $FOREACH identifier order_list $ top $END$
      if ( eval_node( node.children[1], p_ctx ) )   // identifier
      {
        var_t ident( p_ctx->stack.top() ); p_ctx->stack.pop();
        if ( eval_node( node.children[2], p_ctx ) ) // order_list
        {
          var_t order_list( p_ctx->stack.top() ); p_ctx->stack.pop();
          if ( !order_list.empty() && order_list[0].i )
          {
            for ( var_t::const_iterator iter( order_list.begin() ), last( order_list.end() ); iter != last; ++iter )
            {
              p_ctx->var_map[ get_s( ident, p_ctx ) ] = var_t( 1, *iter );
              result &= eval_node( node.children[4], p_ctx ); // top
            }
          }
        }
      }
      return result;
    }

    //! $JOINEACH̿��
    bool joineach_( tree_node_t const& node, context* p_ctx )
    {
      bool result = true;

      if ( node.children.empty() )
      {
        fatal( node.value.begin().line(), "no body of %1%", "'JOINEACH'" );
      }

      //         0          1          2         3 4   5     6
      // $JOINEACH identifier order_list delimitor $ top $END$
      if ( eval_node( node.children[1], p_ctx ) )       // identifier
      {
        var_t ident( p_ctx->stack.top() ); p_ctx->stack.pop();
        if ( eval_node( node.children[2], p_ctx ) )     // order_list
        {
          var_t order_list( p_ctx->stack.top() ); p_ctx->stack.pop();
          if ( !order_list.empty() && order_list[0].i )
          {
            if ( eval_node( node.children[3], p_ctx ) ) // delimitor
            {
              var_t delimitor( p_ctx->stack.top() ); p_ctx->stack.pop();
              for ( var_t::const_iterator iter( order_list.begin() ), last( order_list.end() ); iter != last; ++iter )
              {
                p_ctx->var_map[ get_s( ident, p_ctx ) ] = var_t( 1, *iter );
                result &= eval_node( node.children[5], p_ctx ); // top
                if ( boost::next( iter ) != last )
                {
                  p_ctx->target_file << get_s( delimitor, p_ctx );
                }
              }
            }
          }
        }
      }
      return result;
    }

    //! $ERROR̿��
    bool error_( tree_node_t const& node, context* p_ctx )
    { 
      //         0    1     2   3     4
      //   $ERROR$  top $END$
      // $WARNING$  top $END$
      //    $ERROR expr     $ top $END$
      //  $WARNING expr     $ top $END$

      if ( node.children.empty() )
      {
        fatal( node.value.begin().line(), "no body of %1%", "'ERROR' or 'WARNING'" );
      }

      output_file of = p_ctx->target_file;
      p_ctx->target_file = output_file( "stderr", std::ios_base::out ); // ���������Ū��ɸ�२�顼���Ϥ��ڤ��ؤ��롣

      bool is_error = ( static_cast< parser::rule_id_t >( node.value.id().to_long() ) == parser::id_error_ );

      p_ctx->target_file << get_program_name() << ':';

      bool has_expr = ( node.children.size() > 3 );

      if ( has_expr && eval_node( node.children[1], p_ctx ) ) // expr
      {
        var_t expr( p_ctx->stack.top() ); p_ctx->stack.pop();
        if ( !expr.empty() )
        {
          if ( !expr.front().s.empty() )
          {
            p_ctx->target_file << expr.front().s << ':';
          }
          if ( expr.front().i )
          {
            p_ctx->target_file << expr.front().i.get() << ':';
          }
        }
      }

      p_ctx->target_file << ( is_error ? " error: " : " warning: " );

      bool result = eval_node( node.children[has_expr ? 3 : 1], p_ctx ); // top
      p_ctx->target_file << '\n';
      p_ctx->target_file = of;

      if ( is_error )
      {
        increment_error_count();  // error�ؿ���Ȥ�ʤ��Τǡ�����Ū�˥��顼������Ȥ����롣
      }
      return result;
    }

    //! $WARNING̿��
    bool warning_( tree_node_t const& node, context* p_ctx )
    {
      return error_( node, p_ctx );
    }

    //! $FILE̿��
    bool file_( tree_node_t const& node, context* p_ctx )
    {
      //     0              1 2
      // $FILE string-literal $
      if ( eval_node( node.children[1], p_ctx ) ) // string-literal
      {
        var_t filename( p_ctx->stack.top() ); p_ctx->stack.pop();
        p_ctx->target_file << '\n';
        p_ctx->target_file = output_file( get_s( filename, p_ctx ), std::ios_base::out );
      }
      return true;
    }

    //! ��
    bool expr_( tree_node_t const& node, context* p_ctx )
    {
      // 0          1 2
      // $ expression $
      if ( eval_node( node.children[1], p_ctx ) ) // expression
      {
        if ( node.children[1].value.id().to_long() == parser::id_expression )
        {
          var_t expr( p_ctx->stack.top() ); p_ctx->stack.pop();
          p_ctx->target_file << get_s( expr, p_ctx );
        }
      }
      return true;
    }

    // �ޥ���̿��ʳ�
    bool plain( tree_node_t const& node, context* p_ctx )
    {
      std::string buf;
      buf.reserve( node.children[0].value.end() - node.children[0].value.begin() );
      for ( text::const_iterator iter( node.children[0].value.begin() ), last( node.children[0].value.end() ); iter != last; ++iter )
      {
        if ( *iter == '$' )
        {
          ++iter;
        }
        switch ( char c = *iter )
        {
        case '\r':
        case '\n':
          break;
        default:
          buf.push_back( c );
          break;
        }
      }
      p_ctx->target_file << buf;
      return true;
    }

    // ��ʸ�ڤγƥΡ��ɤ�ɾ��
    bool eval_node( tree_node_t const& node, context* p_ctx )
    {
      bool result = true;
      if ( p_ctx != 0 )
      {
        p_ctx->line = node.value.begin().line();
      }

#if defined( _MSC_VER ) && DEBUG_TRACE
      ::OutputDebugString( ( boost::format( "%s:%d:%s\n" )
                        % node.children[0].value.begin().line().file
                        % node.children[0].value.begin().line().line
                        % std::string( node.children[0].value.begin(), node.children[0].value.end() )
                        ).str().c_str() );
#endif

      switch ( parser::rule_id_t id = static_cast< parser::rule_id_t >( node.value.id().to_long() ) )
      {
      case parser::id_expression:
        result = eval_node( node.children[0], p_ctx );
        break;
      case parser::id_assignment_expr:
        result = assignment_expr( node, p_ctx );
        break;
      case parser::id_logical_or_expr:
        result = logical_or_expr( node, p_ctx );
        break;
      case parser::id_logical_and_expr:
        result = logical_and_expr( node, p_ctx );
        break;
      case parser::id_or_expr:
        result = or_expr( node, p_ctx );
        break;
      case parser::id_xor_expr:
        result = xor_expr( node, p_ctx );
        break;
      case parser::id_and_expr:
        result = and_expr( node, p_ctx );
        break;
      case parser::id_equality_expr:
        result = equality_expr( node, p_ctx );
        break;
      case parser::id_relational_expr:
        result = relational_expr( node, p_ctx );
        break;
      case parser::id_shift_expr:
        result = shift_expr( node, p_ctx );
        break;
      case parser::id_additive_expr:
        result = additive_expr( node, p_ctx );
        break;
      case parser::id_multiplicative_expr:
        result = multiplicative_expr( node, p_ctx );
        break;
      case parser::id_unary_expr:
        result = unary_expr( node, p_ctx );
        break;
      case parser::id_postfix_expr:
        result = postfix_expr( node, p_ctx );
        break;
      case parser::id_primary_expr:
        result = primary_expr( node, p_ctx );
        break;
      case parser::id_lvalue_expr:
        result = lvalue_expr( node, p_ctx );
        break;
      case parser::id_identifier:
        result = identifier( node, p_ctx );
        break;
      case parser::id_constant:
        result = constant( node, p_ctx );
        break;
      case parser::id_string_literal:
        result = string_literal( node, p_ctx );
        break;
      case parser::id_ordered_list:
        result = ordered_list( node, p_ctx );
        break;
      case parser::id_ordered_sequence:
        result = ordered_sequence( node, p_ctx );
        break;
      case parser::id_ordered_item:
        result = ordered_item( node, p_ctx );
        break;
      case parser::id_root:
        result = eval_node( node.children[0], p_ctx );
        break;
      case parser::id_top:
        result = top( node, p_ctx );
        break;
      case parser::id_if_:
        result = if_( node, p_ctx );
        break;
      case parser::id_foreach_:
        result = foreach_( node, p_ctx );
        break;
      case parser::id_joineach_:
        result = joineach_( node, p_ctx );
        break;
      case parser::id_error_:
        result = error_( node, p_ctx );
        break;
      case parser::id_warning_:
        result = warning_( node, p_ctx );
        break;
      case parser::id_file_:
        result = file_( node, p_ctx );
        break;
      case parser::id_expr_:
        result = expr_( node, p_ctx );
        break;
      case parser::id_plain:
        result = plain( node, p_ctx );
        break;
      default:
        result = false;
        break;
      }
      return result;
    }

    bool eval_text( text::const_iterator first, text::const_iterator last, context* p_ctx )
    {
      using namespace boost::spirit;
      typedef text::const_iterator iterator_t;
      tree_parse_info< iterator_t, node_iter_data_factory<> > info;
      info = pt_parse( first, last, parser(), space_p, node_iter_data_factory<>() );
      if ( info.full && !info.trees.empty() )
      {
        bool result;
        if ( info.length <= 0 )
        {
          result = true;
        }
        else
        {
          result = eval_node( info.trees[0], p_ctx );
        }
        return result;
      }
      else
      {
        fatal( info.stop.line(), _( "syntax error" ) );
      }
      return false;
    }

  }

  std::tr1::int64_t macro_processor::to_integer( var_t const& var, context const* p_ctx )
  {
    return get_i( var, p_ctx );
  }

  std::string macro_processor::to_string( var_t const& var, context const* p_ctx )
  {
    return get_s( var, p_ctx );
  }

  macro_processor::macro_processor( hook_t hook_on_assign )
    : p_ctx_( new context( hook_on_assign ) )
  {
  }

  macro_processor::macro_processor( macro_processor const& other )
    : p_ctx_( new context( *other.p_ctx_ ) )
  {
  }

  macro_processor::macro_processor( text const& in, hook_t hook_on_assign )
    : p_ctx_( new context( hook_on_assign ) )
  {
    evaluate( in );
  }

  macro_processor::~macro_processor()
  {
    delete p_ctx_;
    p_ctx_ = 0;
  }

  macro_processor& macro_processor::operator=( macro_processor const& other )
  {
    macro_processor t( *this );
    swap( t );
    return *this;
  }

  void macro_processor::swap( macro_processor& other )
  {
    std::swap( p_ctx_, other.p_ctx_ );
  }

  void macro_processor::evaluate( text const& in )
  {
    try
    {
      for ( func_t const* p_bf = builtin_function_table; p_bf->name != 0; p_bf++ )
      {
        p_ctx_->func_map[ p_bf->name ] = *p_bf;
      }
      if ( !eval_text( in.begin(), in.end(), p_ctx_ ) )
      {
        fatal( _( "macro processing error" ) );
      }
    }
    catch ( expr_error& )
    {
      fatal( _( "macro processing error" ) );
    }
  }

  void macro_processor::set_var( std::string const& name, var_t const& value )
  {
#if defined( _MSC_VER ) && DEBUG_TRACE
    std::string s( "$" + name + " = " + get_s( value, p_ctx_ ) + "$" );
    if ( !value.empty() && value[0].i )
    {
      s += "(" + boost::lexical_cast< std::string >( get_i( value, p_ctx_ ) ) + ")";
    }
    s += "\n";
    ::OutputDebugString( s.c_str() );
#endif
    p_ctx_->var_map[ name ] = value;
  }

  void macro_processor::set_var( std::string const& name, long name2, var_t const& value )
  {
    set_var( ( boost::format( "%s[%d]" ) % name % name2 ).str(), value );
  }

  macro_processor::var_t const& macro_processor::get_var( std::string const& name ) const
  {
    return p_ctx_->var_map[ name ];
  }

  macro_processor::var_t const& macro_processor::get_var( std::string const& name, long name2 ) const
  {
    return get_var( ( boost::format( "%s[%d]" ) % name % name2 ).str() );
  }

  /*!
    *  \brief  �����Ȥν���
    *  \param[in]  first   �����оݥ������󥹤���Ƭ����  
    *  \param[in]  last    �����оݥ������󥹤ν�ü���֤μ�
    *  \param[out] result  ������̤γ�Ǽ��
    *  \return     ������λ��� result ����
    *
    *  ��$ + ������ʸ���פǻϤޤꡢ���Ԥǽ���륳���Ȥ����ޤ���
    */
  void macro_processor::remove_comment( text const& in, text& out )
  {
    text::const_iterator first( in.begin() ), last( in.end() );
    std::back_insert_iterator< text > result( std::back_inserter( out ) );
    out.set_line( first.line().file, first.line().line );

    for ( text::const_iterator iter; ( iter = std::find( first, last, '\n' ) ) != last ; first = iter + 1 )
    {
      std::string buf( first, iter );
      if ( ( ( buf[0] == '$' ) && ( buf.size() >= 2 ) && std::isspace( static_cast< unsigned char >( buf[1] ) ) ) )
      {
        *result = '\n'; 
      }
      else
      {
        // �����ȹ԰ʳ��Ϲ�Ƭ�ζ���������롣
        first = std::find_if( first, iter, std::not1( std::ptr_fun< char, bool >( &toppers::isspace ) ) );
        result = std::copy( first, iter + 1, result );
      }
    }
  }

  void macro_processor::expand_include( text const& in, text& out )
  {
    typedef text::container::const_iterator const_row_iterator;
    typedef std::string::size_type size_type;
    size_type const npos = std::string::npos;
std::string debug_str;

    if ( in.empty() ) // ���Υե����뤬���Ϥ��줿�����к�
    {
      return;
    }

    const_row_iterator first( in.begin().get_row() ), last( in.end().get_row() );

    out.set_line( first->line.file, first->line.line );
    for ( const_row_iterator iter( first ); iter != last; ++iter )
    {
      std::string const& buf = iter->buf;

      for ( size_type i = 0, n = buf.size(); i != n; ++i )
      {
        using namespace boost::spirit;
        char c = buf[i];
        std::string headername;
        text::const_iterator iter2( iter, i );
        if ( iter2 == in.end() )
        {
          break;
        }
        parse_info< text::const_iterator > info
          = parse( iter2, in.end(),
                    ( ch_p( '$' ) >> str_p( "INCLUDE" ) >> *space_p
                        >> '\"' >> ( +( anychar_p - '\"' ) )[ assign( headername ) ] >> '\"'
                      >> '$' ) );
        if ( info.hit )
        {
          std::vector< std::string > include_paths = boost::any_cast< std::vector< std::string >& >( global( "include-path" ) );
          std::string hname = search_include_file( include_paths.begin(), include_paths.end(), headername );
          if ( hname.empty() )
          {
            fatal( iter->line, _( "cannot open file `%1%\'" ), headername );
          }
          else
          {
            text t;
            t.set_line( hname, 1 );
            std::ifstream ifs( hname.c_str() );
            t.append( ifs );

            preprocess( t, out );
            iter = info.stop.get_row();
            i = info.stop.get_col() - 1;
            out.set_line( iter->line.file, iter->line.line );
          }
        }
        else
        {
          out.push_back( c );
          debug_str.push_back( c );
          if ( c == '\n' )
          {
//            ::OutputDebugString( ( out.get_line().file + ":" + boost::lexical_cast< std::string >( out.get_line().line ) + ":" ).c_str() );
//            ::OutputDebugString( debug_str.c_str() );
            debug_str.clear();
          }
        }
      }
    }
  }

  void macro_processor::preprocess( text const& in, text& out )
  {
    if ( in.empty() )
    {
      return;
    }
    text temp;
    macro_processor::remove_comment( in, temp );
    expand_include( temp, out );
  }

  void macro_processor::add_builtin_function( func_t const& f )
  {
    p_ctx_->func_map[ f.name ] = f;
  }

}
