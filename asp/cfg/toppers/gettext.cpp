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
#include <stdlib.h>	// Cygwin�к�
#include <cstring>
#include <clocale>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include "toppers/gettext.hpp"
#include "toppers/cpp.hpp"
#include "toppers/global.hpp"
#include <boost/scoped_array.hpp>
#include <boost/any.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

namespace toppers
{
  namespace
  {

    std::map< std::string, std::string > msgcat;

    void register_msgcat( std::string const& msgid, std::string const& msgstr )
    {
      std::string::size_type size = msgstr.size();
      boost::scoped_array< wchar_t > wbuf( new wchar_t[ size + 1 ] );
      boost::scoped_array< char > buf( new char[ size + 1 ] );
      wchar_t* wcs = wbuf.get();
      wchar_t wc = 0;
      for ( std::string::const_iterator iter( msgstr.begin() ), last( msgstr.end() ); iter != last; ++iter )
      {
        int c = static_cast< unsigned char >( *iter );
        if ( ( ( c & 0xc0 ) == 0xc0 ) || ( c < 0x80 ) ) // ��ԥХ���
        {
          if ( wc != 0 )
          {
            *wcs++ = wc;
            wc = 0;
          }
          if ( ( c & 0x80 ) == 0 )
          {
            wc = static_cast< wchar_t >( c );
          }
          else if ( ( c & 0xe0 ) == 0xc0 )
          {
            wc = static_cast< wchar_t >( c & 0x1f );
          }
          else if ( ( c & 0xf0 ) == 0xe0 )
          {
            wc = static_cast< wchar_t >( c & 0xf );
          }
          else
          {
            // �������Ȥ�̤�б��ʤ������б������Ȥ��Ƥ⡢ʸ���������Ѵ����ˤ��������ǽ�����
          }
        }
        else    // ��³�Х���
        {
          wc = static_cast< wchar_t >( ( wc << 6 ) | ( c & 0x3f ) );
        }
      }
      if ( wc != 0 )
      {
        *wcs++ = wc;
      }
      *wcs = L'\0';

      // �� ���δ֤Ϸ褷���㳰��ȯ�����ʤ�
      char const* locale = std::setlocale( LC_CTYPE, "" );
      /* std:: */wcstombs( buf.get(), wbuf.get(), size + 1 );     // Unicode ����Ķ���¸��ʸ�������ɤ��Ѵ�
      std::setlocale( LC_CTYPE, locale );
      // �� ���δ֤Ϸ褷���㳰��ȯ�����ʤ�

      msgcat[ msgid ] = std::string( buf.get() );
    }

    bool msgcat_loaded = false;

  }

  /*!
   *  \brief      ��å������������Υ���
   *  \param[in]  dir     *.po �ե����뤬¸�ߤ���ǥ��쥯�ȥ�
   *  \retval     true    ����
   *  \retval     false   ����
   *
   *  ��������ز����뤿�ᡢ.po�ե�����ε�����ˡ�ˤϰʲ������󤬤��롣
   *  - msgid, msgstr ��ɬ���Ԥ���Ƭ�˵��Ҥ��롣
   *  - msgid, msgstr ��ľ��ˤϡ�ɬ��������ʸ����ʸ���Ȥ�������ľ���ʸ����򵭽Ҥ��롣
   *  - ʸ����Τߤ򵭽Ҥ���Ԥ�ɬ�� " �ǻϤ�롣
   *  - .po�ե�����Ϥ�ʸ�������ɤ�ɬ�� UTF-8N �Ȥ��롣
   */
  bool load_msgcat( std::string const& dir )
  {
    namespace fs = boost::filesystem;
    char const* env = std::getenv( "TOPPERS_CFG_LANG" );
//      env = "ja";
    if ( env == 0 )
    {
      return false;
    }
    std::string lang( env );

    fs::path cfg_dir( dir, fs::native );
    fs::path po_file( cfg_dir/fs::path( lang + ".po", fs::native ) );
    std::ifstream ifs( po_file.native_file_string().c_str() );
    std::string msgid;
    std::string msgstr;

    while ( ifs )
    {
      std::string str;
      std::getline( ifs, str );

      // ����ʸ���ΰ㤤��ۼ�
      std::string::size_type pos = str.find_last_not_of( " \t\r\n" ); // �Ĥ��Ǥ˹����ζ���������
      if ( pos != std::string::npos && pos < str.size() - 1 )
      {
        char c = str[pos];
        str.erase( pos + 1, std::string::npos );
      }

      if ( str.empty() || str[ 0 ] == '#' || str == "" )
      {
        ;   // ���Ԥޤ��ϥ����ȹ�
      }
      else
      {
        try
        {
          if ( std::strncmp( str.c_str(), "msgid", sizeof( "msgid" )-1 ) == 0 )
          {
            str.erase( 0, sizeof( "msgid" )-1+1 );
            msgid = expand_quote( str );           
          }
          else if ( std::strncmp( str.c_str(), "msgstr", sizeof( "msgstr" )-1 ) == 0 )
          {
            str.erase( 0, sizeof( "msgstr" )-1+1 );
            msgstr = expand_quote( str );
          }
          else
          {
            msgstr += expand_quote( str );
          }
          if ( !msgid.empty() && !msgstr.empty() )  // ľ���� msgid / msgstr ����Ͽ
          {
            register_msgcat( msgid, msgstr );
            msgid.clear();
            msgstr.clear();
          }
        }
        catch ( std::invalid_argument& )
        {
          return false;
        }
      }
    }
    msgcat_loaded = true;
    return true;
  }

  /*!
   *  \brief      ��å�����������
   *  \param[in]  message   ��å�����ID
   *  \return     ������Υ�å�����
   */
  std::string const& gettext( std::string const& message )
  {
    static bool f = load_msgcat( boost::any_cast< std::string const& >( global( "cfg-directory" ) ) );
    if ( !msgcat_loaded )
    {
      return message;
    }

    std::map< std::string, std::string >::const_iterator iter( msgcat.find( message ) ), last( msgcat.end() );
    if ( iter != last )
    {
      std::string const& result( iter->second );
      return result;
    }
    return message;
  }

}
