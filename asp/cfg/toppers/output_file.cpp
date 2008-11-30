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
#include <map>
#include <iostream>
#include <sstream>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include "toppers/workaround.hpp"
#include "toppers/output_file.hpp"
#include "toppers/io.hpp"
#include "toppers/global.hpp"
#include "toppers/diagnostics.hpp"

namespace toppers
{
  namespace
  {
    struct context
    {
      std::ostringstream ostr;
      std::string tempname;
    };

    typedef std::map< std::string, std::tr1::shared_ptr< context > > context_map;

    inline context_map& get_context_map()
    {
      static context_map m;
      return m;
    }
  }

  /*!
   *  \brief  ���ϥ��ȥ꡼��λ���
   *  \return ���ϥ��ȥ꡼��
   *
   *  ���ꤵ��Ƥ���ե�����˽��Ϥ��뤿��ν��ϥ��ȥ꡼����֤���
   *  ���˽��ϥ��ȥ꡼�ब��������Ƥ�����Ϥ��λ��Ȥ��֤��������Ǥʤ���п����˽��ϥ��ȥ꡼����������롣
   *
   *  �ե�����̾�Ȥ��ơ�"stdout"�����ꤵ��Ƥ����ɸ����ϡ�"stderr"�����ꤵ��Ƥ����ɸ�२�顼���Ϥˤʤ롣
   */
  std::ostream& output_file::ostr() const
  {
    if ( filename_ == "stdout" )
    {
      return std::cout;
    }
    else if ( filename_ == "stderr" )
    {
      return std::cerr;
    }

    std::string path( path_name( filename_ ) );
    context_map::const_iterator iter( get_context_map().find( path ) );
    if ( iter == get_context_map().end() )
    {
      std::tr1::shared_ptr< context > ctx( new context );
      get_context_map().insert( std::make_pair( path, ctx ) );
      return ctx->ostr;
    }
    return iter->second->ostr;
  }

  /*!
   *  \brief  �����˳�Ǽ����Ƥ������Ƥ�ºݤ˥ե�����˽��Ϥ��롣
   *
   *  context_map �Ȥ��ƥ����˳�Ǽ���줿���Ƥ򡢤��줾��Υե�������Ф��ƽ��Ϥ��롣
   *  ���Ϥ���ˤ����ꡢ�ޤ����Υե������ .org ���դ����ե�����̾���ѹ����롣
   *  �����ǡ������ˤ��ä� .org ���˲�����롣
   *  �ե�������˽񤭹��ߡ�����ǥ��顼��ȯ���������ϡ�.org �򸵤Υե�����̾���᤹��
   *  ����ǤҤȤĤǤ⥨�顼��ȯ���������ϡ����ե�����ˤĤ��� .org �򸵤��᤹��
   *  �����ˤ��ä� .org �����褷�ʤ���
   */
  void output_file::save()
  {
    namespace fs = boost::filesystem;
    std::vector< std::string > saved_files;

    try
    {
      for ( context_map::const_iterator iter( get_context_map().begin() ), last( get_context_map().end() );
            iter != last;
            ++iter )
      {
        if ( iter->first != "" )
        {
          fs::path filename( iter->first, fs::native );
          fs::path backup( iter->first + ".org", fs::native );
          bool existed = fs::exists( filename );

          try
          {
            std::string file( filename.native_file_string() );
            if ( existed )
            {
              fs::rename( filename, backup );
            }
            write( file, iter->second->ostr.str() );  // �����ǽ񤭹���
            saved_files.push_back( file );
            fs::remove( backup );
          }
          catch ( ... )
          {
            if ( existed )
            {
              fs::remove( filename );
              fs::rename( backup, filename ); 
            }
            throw;
          }
        }
      }
    }
    catch ( ... )
    {
      // ���Ǥ˽񤭹�����ե�����򸵤��᤹��
      for ( std::vector< std::string >::const_iterator iter( saved_files.begin() ), last( saved_files.end() );
            iter != last;
            ++iter )
      {
        fs::path filename( *iter, fs::native );
        fs::remove( filename );
        fs::path backup( *iter + ".org", fs::native );
        if ( fs::exists( backup ) )
        {
          fs::rename( backup, filename );
        }
      }
      throw;
    }
  }

  /*!
   *  \brief  ���ꤷ���ե�����̾���б������ѥ�̾���֤���
   *  \param[in]  filename  �ե�����̾
   *  \return     �ѥ�̾
   *
   *  --output-directory ���ץ����ǻ��ꤷ��������ǥ��쥯�ȥ��ȿ�Ǥ����ѥ�̾���������롣
   *  �������������Υե�����̾�ξ��Ϥ��Τޤޤ�ʸ������֤���
   *  - "stdout"
   *  - "stderr"
   *  - ""
   */
  std::string output_file::path_name( std::string const& filename )
  {
    if ( filename == "stdin" || filename == "stderr" || filename == "" )
    {
      return filename;
    }
    namespace fs = boost::filesystem;
    boost::any output_directory = global( "output-directory" );
    if ( output_directory.empty() )
    {
      return filename;
    }
    fs::path dir( boost::any_cast< std::string >( global( "output-directory" ) ), fs::native  );
    return ( dir/filename ).native_file_string();
  }

  /*!
   *  \brief  ����ե�����ؤν񤭹��ߥǡ����򻲾�
   *  \param[in]  filename  ������Υե�����̾
   *  \return     �񤭹��ߥǡ���
   */
  std::string output_file::get_file_data( std::string const& filename )
  {
    context_map::const_iterator iter( get_context_map().find( path_name( filename ) ) ), last( get_context_map().end() );
    if ( iter != last )
    {
      return iter->second->ostr.str();
    }
    return "";
  }

  /*!
   *  \brief  ����ե�����ؤν񤭹��ߥǡ���������
   *  \param[in]  filename  ������Υե�����̾
   *  \param[in]  data      �񤭹��ߥǡ���
   *  \retval     true      ��������
   *  \retval     false     ���꼺��
   */
  bool output_file::set_file_data( std::string const& filename, std::string const& data )
  {
    output_file ofile( filename, std::ios_base::out );
    dynamic_cast< std::ostringstream& >( ofile.ostr() ).str( data );
    return true;
  }

  /*!
   *  \brief  �����˳�Ǽ����Ƥ���񤭹��ߤ褦�ǡ�����õ�
   *  \param[in]  filename  ������Υե�����̾
   *  \retval     true      �ǡ����ξõ�����
   *  \retval     false     ���ꤷ���ե�����ؤν��ϥǡ�����¸�ߤ��ʤ�
   */
  bool output_file::clear_file_data( std::string const& filename )
  {
    context_map::const_iterator iter( get_context_map().find( path_name( filename ) ) ), last( get_context_map().end() );
    if ( iter != last )
    {
      iter->second->ostr.str( "" );
      return true;
    }
    return false;
  }

}
