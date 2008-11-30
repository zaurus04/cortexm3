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
 *  \file   toppers/c_expr.hpp
 *  \brief  C����μ��ι�ʸ���Ϥ˴ؤ���������
 *
 *  ���Υե�������������륯�饹
 *  \code
 *  struct c_expr_parser_base< Derived >;
 *  struct c_expr_parser;
 *  struct c_const_expr_parser;
 *  \endcode
 */
#ifndef TOPPERS_C_EXPR_HPP_
#define TOPPERS_C_EXPR_HPP_

#include "toppers/c_parser.hpp"
#include <boost/cstdint.hpp>

namespace toppers
{

  /*!
   *  \struct c_expr_parser_base c_expr.hpp "toppers/c_expr.hpp"
   *  \brief  C����μ���ʸ���Ϥ��뤿��δ��쥯�饹
   *
   *  �ºݤ˻��Ѥ���ݤϡ� c_expr_parser_base ����� c_expr_parser_base::definition
   *  ���饹����������ɬ�פ�����ޤ��� c_expr_parser_base::definition ���������饹�Ǥϡ�
   *  start ���дؿ���������ơ���ʸ���ɬ�פʥ롼�����Ф��褦�ˤ��Ƥ���������
   *  �������뤳�Ȥǡ��������ʸˡ���켡����ʸˡ�Ȥ��ä��褦�ˡ�C�����ʸˡ�Υ���
   *  ���åȤ��ưפ˺��Ф����Ȥ��Ǥ��ޤ���
   *
   *  \code
   *  // �켡������Ф���
   *  struct c_primary_expression : c_expr_parser_base< c_primary_expression >
   *  {
   *    template < class Scanner >
   *    struct definition : c_expr_parser_base< c_primary_expression >::definition
   *    {
   *      rule_t const& start() const { return primary_expression; }
   *    };
   *  };
   *  \endcode
   */
  template < class Derived >
    struct c_expr_parser_base : boost::spirit::grammar< Derived >
  {
  public:
    /*!
     *  \struct definition c_expr.hpp "toppers/c_expr.hpp"
     *  \brief  ʸˡ���
     */
    template < class Scanner >
      struct definition
    {
      typedef boost::spirit::rule< Scanner > rule_t;
      rule_t  primary_expression,   
              expression,
              constant_expression,
              conditional_expression,
              assignment_expression,
              assignment_operator,
              postfix_expression,
              unary_expression,
              unary_operator,
              cast_expression,
              multiplicative_expression,
              additive_expression,
              shift_expression,
              relational_expression,
              equality_expression,
              AND_expression,
              exclusive_OR_expression,
              inclusive_OR_expression,
              logical_AND_expression,
              logical_OR_expression,
              string_literal,
              constant,
              floating_constant,
              decimal_floating_constant,
              hexadecimal_floating_constant,
              integer_constant,
              character_constant,
              declaration_specifiers,
              type_name,
              specifier_qualifier_list,
              storage_class_specifier,
              type_specifier,
              type_qualifier,
              declarator,
              direct_declarator,
              struct_or_union_specifier,
              struct_declaration,
              struct_declarator,
              enum_specifier,
              enumerator,
              abstract_declarator,
              pointer,
              parameter_type_list,
              parameter_list,
              parameter_declaration,
              direct_abstract_declarator;

      c_ident_parser_t identifier;
      c_strlit_parser_t c_strlit_p;
      c_chlit_parser_t c_chlit_p;

      /*!
       *  \brief  ���󥹥ȥ饯��
       *  \param  self  ʸˡ���饹�� c_expr_parser_base< Derived > ���饹����ηѾ��ˤؤλ���
       */
      definition( Derived const& self )
        : identifier( c_ident_parser( self.ucn_, self.c_plus_plus_ ) ),
          c_strlit_p( c_strlit_parser( self.codeset_ ) ),
          c_chlit_p( c_chlit_parser( self.codeset_ ) )
      {
        using namespace boost::spirit;
        static functor_parser< detail::c_integer_constant_parse_functor< boost::uintmax_t > > const c_int_const_p;
        static functor_parser< detail::c_integer_suffix_parse_functor > const c_int_suffix_p;

        primary_expression =  // ʣ���ƥ��̤�б�
            identifier
          | constant
          | string_literal
          | ( '(' >> expression >> ')' );
        expression =
            assignment_expression % ',';
        constant_expression = 
            conditional_expression;
        conditional_expression =
            logical_OR_expression >> *( '\?' >> expression >> ':' >> logical_OR_expression );
        assignment_expression =
           *( unary_expression >> assignment_operator ) >> conditional_expression;
        assignment_operator =
            ch_p( '=' ) | "*=" | "/=" | "%=" | "+=" | "?=" | "<<=" | ">>=" | "&=" | "^=" | "|=";
        postfix_expression =
            primary_expression >>
          *(
                ( '[' >> expression >> ']' )
              | ( '(' >> list_p( assignment_expression, ',' ) >> ')' )
              | ( '.' >> identifier )
              | ( "->" >> identifier )
              | "++"
              | "--"
            );
        unary_expression =
           *( str_p( "++" ) || "--" ) >>
            (
                ( "sizeof" >> unary_expression )
              | ( str_p( "sizeof" ) >> '(' >> type_name >> ')' )
              | postfix_expression
              | ( unary_operator >> cast_expression )
            );
        unary_operator =
            chset<>( "&*~!+-" );
        cast_expression =
            *( '(' >> type_name >> ')' ) >> unary_expression
          | +( '(' >> ( type_name | identifier ) >> ')' );  // ��ʸ���Ϥ˼��Ԥ����Զ���к�
        multiplicative_expression =
            cast_expression >>
           *(
                ( '*' >> cast_expression )
              | ( '/' >> cast_expression )
              | ( '%' >> cast_expression )
            );
        additive_expression =
            multiplicative_expression >>
           *(
                ( '+' >> multiplicative_expression )
              | ( '-' >> multiplicative_expression )
            );
        shift_expression =
            additive_expression >>
           *(
                ( "<<" >> additive_expression )
              | ( ">>" >> additive_expression )
            );
        relational_expression =
            shift_expression >>
           *(
                ( '<' >> shift_expression )
              | ( '>' >> shift_expression )
              | ( "<=" >> shift_expression )
              | ( ">=" >> shift_expression )
            );
        equality_expression =
            relational_expression >>
           *(
                ( "==" >> relational_expression )
              | ( "!=" >> relational_expression )
            );
        AND_expression =
            equality_expression >> *( '&' >> equality_expression );
        exclusive_OR_expression =
            AND_expression >> *( '^' >> AND_expression );
        inclusive_OR_expression =
            exclusive_OR_expression >> *( '|' >> exclusive_OR_expression );
        logical_AND_expression =
            inclusive_OR_expression >> *( "&&" >> inclusive_OR_expression );
        logical_OR_expression =
            logical_AND_expression >> *( "||" >> logical_AND_expression );
        string_literal =
            c_strlit_p
          | lexeme_d[ 'L' >> c_strlit_p ];
        constant =
            floating_constant
          | integer_constant
          | identifier  // ������
          | character_constant;
        floating_constant =
            decimal_floating_constant
          | hexadecimal_floating_constant;
        decimal_floating_constant =
            lexeme_d
            [
              as_lower_d
              [
                ( ( *digit_p >> '.' >> +digit_p ) | ( +digit_p >> '.' ) ) >>
                'e' >> !chset<>( "+-" ) >> +digit_p >>
                !chset<>( "fl" )
              ]
            ];
        hexadecimal_floating_constant =
            lexeme_d
            [
              as_lower_d
              [
                "0x" >>
                ( ( *xdigit_p >> '.' >> +xdigit_p ) | ( +xdigit_p >> '.' ) ) >>
                'p' >> !chset<>( "+-" ) >> +digit_p >>
                !chset<>( "fl" )
              ]
            ];
        integer_constant =
            lexeme_d[ c_int_const_p >> !c_int_suffix_p ];
        character_constant =
            c_chlit_p
          | lexeme_d[ 'L' >> c_chlit_p ];
        declaration_specifiers =
           +( storage_class_specifier | type_specifier | type_qualifier );
        type_name =
            specifier_qualifier_list >> !abstract_declarator;
        specifier_qualifier_list =
           +( type_specifier | type_qualifier );
        storage_class_specifier =
            str_p( "auto" )
          | "register"
          | "static"
          | "extern"
          | "typedef";
        type_specifier =
            str_p( "void" ) | "char" | "short" | "int" | "long" | "float" | "double"
          | "signed" | "unsigned"
          | identifier
          | struct_or_union_specifier
          | enum_specifier;
        type_qualifier =
            str_p( "const" ) | "volatile" | "restrict";
        declarator =
            !pointer >> direct_declarator;
        direct_declarator = 
            ( identifier | ( '(' >> declarator >> ')' ) )
            >>
          *(
                ( '[' >> !constant_expression >> ']' )
              | ( '(' >> parameter_type_list >> ')' )
              | ( '(' >> !( identifier % ',' ) >> ')' )
            );
        struct_or_union_specifier =
            lexeme_d[ ( str_p( "struct" ) | "union" ) >> +space_p >> identifier ]
          | ( lexeme_d[ ( str_p( "struct" ) | "union" ) >> +space_p >> !identifier ] >> '{' >> +struct_declaration >> '}' );
        struct_declaration =
            specifier_qualifier_list >> !list_p( struct_declarator, ',' ) >> ';';
            // lisp_p( struct_declarator, ',' )���ά��ǽ�Ȥ��Ƥ���Τϡ�
            // struct_declarator �� identifier �� specifier_qualifier_list ��
            // typedef ̾�ȴְ㤦���Ȥ���򤹤뤿��
        struct_declarator =
            ( !declarator >> ':' >> constant_expression ) // �ӥåȥե������
          | declarator;
        enum_specifier =
            ( lexeme_d[ "enum" >> +space_p >> !identifier ] >> '{' >> list_p( enumerator, ',', ',' ) >> '}' )   // C99�Ǥ������Υ���ޤ����äƤ�褤
          | lexeme_d[ "enum" >> +space_p >> identifier ];
        enumerator =
            identifier >> !( '=' >> constant_expression );
        abstract_declarator =
            ( !pointer >> direct_abstract_declarator )
          | pointer;
        pointer =
           +( '*' >> *type_qualifier );
        parameter_type_list =
            parameter_list >> !( ch_p( ',' ) >> "..." );  // ���Ѹİ���
        parameter_list =
            parameter_declaration % ',';
        parameter_declaration = 
            ( declaration_specifiers >> declarator )
          | ( declaration_specifiers >> !abstract_declarator );
        direct_abstract_declarator =
            (
             !( '(' >> abstract_declarator >> ')' ) >>
             +(
                  ( '[' >> !constant_expression >> ']' )
                | ( '(' >> !parameter_type_list >> ')' ) 
              )
            )
          | ( '(' >> abstract_declarator >> ')' );
      }
    };
    bool ucn_;
    codeset_t codeset_;
    bool c_plus_plus_;

    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  ucn         ���ʸ��̾���б�������� true ����ꤹ��
     *  \param  codeset     ʸ��������
     *  \param  c_plus_plus C++ ���б�������� true ����ꤹ��
     */
    explicit c_expr_parser_base( bool ucn = false, codeset_t codeset = ascii, bool c_plus_plus = false )
      : ucn_( ucn ), codeset_( codeset ), c_plus_plus_( c_plus_plus )
    {
    }
  };

  /*!
   *  \class  c_expr_parser c_expr.hpp "toppers/c_expr.hpp" 
   *  \brief  C����μ��ι�ʸ���ϥ��饹
   */
  struct c_expr_parser : c_expr_parser_base< c_expr_parser >
  {
    typedef c_expr_parser_base< c_expr_parser > base_t;

    /*!
     *  \struct definition c_expr.hpp "toppers/c_expr.hpp"
     *  \brief  ʸˡ���
     */
    template < class Scanner >
    struct definition : base_t::definition< Scanner >
    {
      typedef typename base_t::definition< Scanner >::rule_t rule_t;

      definition( c_expr_parser const& self ) : base_t::definition< Scanner >( self ) {}
      rule_t const& start() const { return base_t::definition< Scanner >::expression; };
    };

    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  ucn     ���ʸ��̾���б�������� true ����ꤹ��
     *  \param  codeset ʸ��������
     */
    explicit c_expr_parser( bool ucn = false, codeset_t codeset = ascii )
      : c_expr_parser_base< c_expr_parser >( ucn, codeset )
    {
    }
  };

  /*!
   *  \class  c_const_expr_parser c_expr.hpp "toppers/c_expr.hpp"
   *  \brief  C�����������ι�ʸ���ϥ��饹
   */
  struct c_const_expr_parser : c_expr_parser_base< c_const_expr_parser >
  {
    typedef c_expr_parser_base< c_const_expr_parser > base_t;

    /*!
     *  \struct definition c_expr.hpp "toppers/c_expr.hpp"
     *  \brief  ʸˡ���
     */
    template < class Scanner >
    struct definition : base_t::definition< Scanner >
    {
      typedef typename base_t::definition< Scanner >::rule_t rule_t;

      definition( c_const_expr_parser const& self ) : base_t::definition< Scanner >( self ) {}
      rule_t const& start() const { return base_t::definition< Scanner >::constant_expression; };
    };

    /*!
     *  \brief  ���󥹥ȥ饯��
     *  \param  ucn     ���ʸ��̾���б�������� true ����ꤹ��
     *  \param  codeset ʸ��������
     */
    explicit c_const_expr_parser( bool ucn = false, codeset_t codeset = ascii )
      : c_expr_parser_base< c_const_expr_parser >( ucn, codeset )
    {
    }
  };

}

#endif  // ! TOPPERS_C_EXPR_HPP_
