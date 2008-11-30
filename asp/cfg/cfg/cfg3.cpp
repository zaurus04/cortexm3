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
#include <fstream>
#include <sstream>
#include "toppers/diagnostics.hpp"
#include "toppers/s_record.hpp"
#include "toppers/macro_processor.hpp"
#include "toppers/itronx/checker.hpp"
#include "cfg.hpp"
#include <boost/spirit.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

namespace
{
  using toppers::text_line;
  typedef toppers::macro_processor::element element;
  typedef toppers::macro_processor::var_t var_t;
  typedef toppers::macro_processor::context context;

  /*!
   *  \brief  ����ܥ���б����륢�ɥ쥹�μ���
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   */
  var_t bf_symbol( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    using namespace toppers;
    using namespace toppers::itronx;

    if ( macro_processor::check_arity( line, arg_list.size(), 1, "SYMBOL" ) )
    {
      std::string symbol( macro_processor::to_string( arg_list[0], p_ctx ) );
      std::tr1::shared_ptr< checker > chk = boost::any_cast< std::tr1::shared_ptr< checker > >( toppers::global( "checker" ) );
      nm_symbol::entry entry = chk->find( symbol );
      if ( entry.type >= 0 )
      {
        element e;
        e.i = entry.address;
        return var_t( 1, e );
      }
    }
    return var_t();
  }

  /*!
   *  \brief  ���ꤷ�����ɥ쥹�˳�Ǽ����Ƥ����ͤμ���
   *  \param[in]  line      ���ֹ�
   *  \param[in]  arg_list  �ޥ���°����ꥹ��
   *  \param[in]  p_ctx     �ޥ�����ƥ�����
   *  \retval     �ޥ����ֵ���
   *
   *  ��1�����˥��ɥ쥹����2�������ɤ߹���Х��ȿ�����ꤷ�ޤ���
   */
  var_t bf_peek( text_line const& line, std::vector< var_t > const& arg_list, context const* p_ctx )
  {
    using namespace toppers;
    using namespace toppers::itronx;

    if ( macro_processor::check_arity( line, arg_list.size(), 2, "PEEK" ) )
    {
      std::size_t address = static_cast< std::size_t >( macro_processor::to_integer( arg_list[0], p_ctx ) );
      std::size_t size = static_cast< std::size_t >( macro_processor::to_integer( arg_list[1], p_ctx ) );
      std::tr1::shared_ptr< checker > chk = boost::any_cast< std::tr1::shared_ptr< checker > >( toppers::global( "checker" ) );

      std::map< std::string, var_t >::const_iterator le_iter( p_ctx->var_map.find( "LITTLE_ENDIAN" ) );
      if ( le_iter != p_ctx->var_map.end() )
      {
        bool little_endian = !!( *le_iter->second.front().i );
        element e;
        e.i = chk->get( address, size, !!little_endian );
        return var_t( 1, e );
      }
    }
    return var_t();
  }

}

bool cfg3_main()
{
  using namespace toppers;
  using namespace toppers::itronx;

  std::string kernel( boost::any_cast< std::string& >( global( "kernel" ) ) );
  itronx::factory factory( kernel );

  // *.cfg��cfg1_out.srec���ɤ߹���
  std::string input_file;
  try
  {
    input_file = boost::any_cast< std::string const& >( toppers::global( "input-file" ) );
  }
  catch ( boost::bad_any_cast& )
  {
    fatal( _( "no input files" ) );
  }
  std::string cfg1_out_name( boost::any_cast< std::string& >( global( "cfg1_out" ) ) );
  std::auto_ptr< cfg1_out > cfg1_out( factory.create_cfg1_out( cfg1_out_name ) );

  codeset_t codeset = boost::any_cast< codeset_t >( global( "codeset" ) );
  cfg1_out->load_cfg( input_file, codeset, *factory.get_static_api_info_map() );
  cfg1_out->load_srec();
  cfg1_out::static_api_map api_map( cfg1_out->merge() );

  // ID�ֹ�γ��դ�
  assign_id( api_map );

  std::auto_ptr< checker > p_checker( factory.create_checker() );
  std::tr1::shared_ptr< checker > chk( p_checker );
  toppers::global( "checker" ) = chk;
  std::string rom_image( boost::any_cast< std::string& >( toppers::global( "rom-image" ) ) );
  std::string symbol_table( boost::any_cast< std::string& >( toppers::global( "symbol-table" ) ) );
  chk->load_rom_image( rom_image, symbol_table );

  // �ƥ�ץ졼�ȥե�����
  boost::any template_file( global( "template-file" ) );
  if ( template_file.empty() )
  {
    // �ƥ�ץ졼�ȥե����뤬���ꤵ��Ƥ��ʤ���к���¤Υ����å��Τߡʸ����ߴ����Τ����
    // �ѥ�᡼�������å�
    if ( !chk->check( *cfg1_out ) )
    {
      return false;
    }
  }
  else
  {
    namespace fs = boost::filesystem;

    // �ƥ�ץ졼�Ƚ���
    std::auto_ptr< macro_processor > mproc( factory.create_macro_processor( factory.get_hook_on_assign(), *cfg1_out, api_map ) );

    toppers::macro_processor::func_t func_info;
    func_info.name = "SYMBOL";
    func_info.f = &bf_symbol;
    mproc->add_builtin_function( func_info );

    func_info.name = "PEEK";
    func_info.f = &bf_peek;
    mproc->add_builtin_function( func_info );

    fs::path cfg_dir( boost::any_cast< std::string& >( global( "cfg-directory" ) ), fs::native );
    std::vector< std::string > include_paths = boost::any_cast< std::vector< std::string > >( global( "include-path" ) );
    include_paths.push_back( cfg_dir.empty() ? "." : cfg_dir.native_file_string() );

    toppers::text in_text;
    toppers::text pp_text;
    std::string file_name( boost::any_cast< std::string& >( template_file ) );

    in_text.set_line( file_name, 1 );
    std::ifstream ifs( file_name.c_str() );
    if ( ifs.is_open() )
    {
      in_text.append( ifs );
      macro_processor::preprocess( in_text, pp_text );
      mproc->evaluate( pp_text );
    }

    if ( get_error_count() > 0 )
    {
      return false;
    }
    // ���ϥե����뤬���뤫�ɤ���ʬ����ʤ�������������֤��롣
    output_file::save();
  }

  std::cerr << _( "check complete" ) << std::endl;

  return true;
}
