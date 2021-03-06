/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2007-2008 by TAKAGI Nobuhisa
 * 
 *  上記著作権者は，以下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェ
 *  ア（本ソフトウェアを改変したものを含む．以下同じ）を使用・複製・改
 *  変・再配布（以下，利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *      また，本ソフトウェアのユーザまたはエンドユーザからのいかなる理
 *      由に基づく請求からも，上記著作権者およびTOPPERSプロジェクトを
 *      免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，特定の使用目的
 *  に対する適合性も含めて，いかなる保証も行わない．また，本ソフトウェ
 *  アの利用により直接的または間接的に生じたいかなる損害に関しても，そ
 *  の責任を負わない．
 * 
 */
#include <fstream>
#include "toppers/output_file.hpp"
#include "cfg.hpp"

/*!
 *  \brief  パス１処理
 *  \retval true  成功
 *  \retval false 失敗
 */
bool cfg1_main()
{
  using namespace toppers;
  using namespace toppers::itronx;

  std::string kernel( boost::any_cast< std::string const& >( global( "kernel" ) ) );
  itronx::factory factory( kernel );

  std::string input_file;
  try
  {
    input_file = boost::any_cast< std::string const& >( toppers::global( "input-file" ) );
  }
  catch ( boost::bad_any_cast& )
  {
    fatal( _( "no input files" ) );
  }
  codeset_t codeset = boost::any_cast< codeset_t >( global( "codeset" ) );

  std::string cfg1_out_name( boost::any_cast< std::string& >( global( "cfg1_out" ) ) );
  std::auto_ptr< cfg1_out > cfg1_out( factory.create_cfg1_out( cfg1_out_name + ".c" ) );
  cfg1_out->load_cfg( input_file, codeset, *factory.get_static_api_info_map() );
  cfg1_out->generate();

  if ( get_error_count() > 0 )
  {
    return false;
  }
  output_file::save();
  return true;
}
