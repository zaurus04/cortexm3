/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: fc_binutils.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#if defined(FILECONTAINER_BINUTILS) || defined(TESTSUITE)

#ifdef _MSC_VER
#pragma warning(disable:4786) //�f�o�b�O�������255�����ɐ؂�l�߂�
#endif

#include "base/filecontainer.h"
#include <string>
#include <map>
#include <fstream>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>

#define _isspace(x)  isspace(x)
#define _isprint(x)  isprint(x)

#define SIZE_LOADPAGE 65536         //�o�C�i���f�[�^���i�[����y�[�W�P��

#define SIZE_TO_CONFIRM_BINARYFILE 128  //�t�@�C�����o�C�i�����܂ނ��ǂ������m�F����̂ɓǂݏo���f�[�^�̒��� (�o�b�t�@�����̂ł��܂�傫�����Ȃ�����)

#define MAGIC_SYMBOL "_checker_magic_number"
#define MAGIC_NUMBER 0x01234567                         //4�o�C�g�̐���

#define CMD_GNUNM      "nm"
#define CMD_GNUOBJCOPY "objcopy"

#define MAKE_BASEADDRESS(x)   ((x) & ~(SIZE_LOADPAGE-1))
#define MAKE_OFFSETADDRESS(x) ((x) &  (SIZE_LOADPAGE-1))

using namespace std;

namespace {

    class FileContainerBinutilsImpl : public FileContainer
    {
    public:
        typedef void (interceptor_func_t)(fstream &, const string &);      //�s�ӂɖK�ꂽ�o�C�i���t�@�C���̏P���ɑΉ�����֐��̌^

    protected:
        string                 symbol_prefix;
        map<string, address_t> symbol_table;
        map<address_t, char *> contents;

        address_t last_address;     //�L���b�V�����ǂ�
        char *    last_page;

            //�f�[�^��荞��
        void loadSymbols(fstream & file)  throw(Exception);
        void loadDataContents(fstream & file) throw(Exception);

            //contents��1�o�C�g��������
        void writeByte(address_t address, unsigned int) throw(Exception);

            //��������
        void searchSymbolPrefix(void) throw();
        void searchByteOrder(void)    throw();

    public:
        FileContainerBinutilsImpl(void) throw();
        virtual ~FileContainerBinutilsImpl(void) throw();

            /* �C���^�t�F�[�X�� */
        virtual void        attachModule(const string & filename) throw(Exception);
        virtual void        loadContents(void * dest, address_t address, size_t size) throw(Exception);
        virtual address_t   getSymbolAddress(const string & symbol) throw(Exception);
        virtual std::string getArchitecture(void) throw();

        TESTSUITE_PROTOTYPE(main)
    };

    namespace {
        FileContainerBinutilsImpl instance_of_FileContainerBinutilsImpl;
    }

        /* �R���X�g���N�^ */
    FileContainerBinutilsImpl::FileContainerBinutilsImpl(void) throw()
        : symbol_prefix(""), symbol_table(), contents(), last_address(0), last_page(0)
    {}

        /* �f�X�g���N�^ : �f�[�^�o�b�t�@�̉�� */
    FileContainerBinutilsImpl::~FileContainerBinutilsImpl(void) throw()
    {
        map<address_t, char *>::iterator scope;

        scope = contents.begin();
        while(scope != contents.end()) {
            delete [] scope->second;
            ++ scope;
        }
        symbol_table.clear();
        contents.clear();
    }

        /* �t�@�C�������J���}�œ�ɕ����� */
    void splitFilename(const string & src, string & first, string & second) throw(Exception)
    {
        if(!src.empty()) {
            string::size_type pos;

            pos = src.find_first_of(',');
            if(pos != string::npos) {
                first  = src.substr(0, pos);
                second = src.substr(pos + 1);
            }
            else {
                    //�t�@�C������������w�肳��Ă��Ȃ�
                first  = src;
                second = src;
            }
        }
        else
            ExceptionMessage("[FCBI] Empty filename could not be accepted.","[FCBI] �t�@�C����������܂���").throwException();
    }

        /* �t�@�C�����o�C�i���f�[�^�������Ă��邩�ǂ����𔻒� */
    bool hasBinaryContents(fstream & file) throw()
    {
        assert(file.is_open());

        bool        result = false;
        char        buffer[SIZE_TO_CONFIRM_BINARYFILE];
        streamsize  length;

        file.read(buffer, SIZE_TO_CONFIRM_BINARYFILE);
        length = file.gcount();

        for(streamsize i = 0; i < length; ++ i) {
            if(buffer[i] < 0 || !(_isprint(buffer[i]) || _isspace(buffer[i]))){
                result = true;
                break;
            }
        }

		if(!result) {
	        file.clear();
    	    file.seekg(0, ios::beg);    //�擪�ɖ߂��Ă���
		}

        return result;
    }

        /* �e�L�X�g�t�@�C�����J�� (�o�C�i���������ꍇ�ɂ͑Ώ�) */
    void openTextFile(fstream & file, const string & filename, FileContainerBinutilsImpl::interceptor_func_t * interceptor) throw(Exception)
    {
        assert(!filename.empty());
        assert(!file.is_open());

        file.open(filename.c_str(), ios::in|ios::binary);
        if(!file.is_open()) {
            ExceptionMessage("File '%' could not be opened.","�t�@�C�� '%' �͊J���܂���") << filename << throwException;
            return;
        }

            /* �o�C�i���t�@�C����������... */
        while(hasBinaryContents(file)) {
            file.close();
            
            if(interceptor != 0) {
                (*interceptor)(file, filename);
                interceptor = 0;    //�Ώ��͈��̂�
            }

            if(!file.is_open()) {
                break;
            }
        }

            /* �t�@�C�����J���Ȃ��������O */
        if(!file.is_open())
            ExceptionMessage("Program failed to convert the binary '%' into suitable style. Please specify a suitable TEXT file.",
                            "�v���O�����̓o�C�i���t�@�C��'%'�̕ϊ��Ɏ��s���܂����B�������e�L�X�g�t�@�C�����w�肵�����Ă��������B")
                                << filename << throwException;
    }

        /* �ꎞ�I�ȃt�@�C�����̐��� */
    const char * makeTemporaryFilename(void) throw()
    {
        static char filename[10];

        sprintf(filename, "cfg%06x", (int)(rand() & 0xffffffl));

        return filename;
    }


        /* �o�C�i����GNU-NM���g���ĕϊ����� */
    void interceptWithGnuNM(fstream & file, const string & filename) throw(Exception)
    {
        assert(!file.is_open());

        string cmdline;
        string symfile;

        symfile.assign(makeTemporaryFilename());
        cmdline = string(CMD_GNUNM) + " " + filename + " > " + symfile;
        VerboseMessage("[EXEC] %\n") << cmdline;

		system(cmdline.c_str());

            /* �������J������t�@�C�����폜 */
        file.open(symfile.c_str(), ios::in);
        if(file.is_open()) {
            remove(symfile.c_str());
        }
    }

        /* �o�C�i����GNU-OBJCOPY���g���ĕϊ����� */
    void interceptWithGnuObjcopy(fstream & file, const string & filename) throw(Exception)
    {
        assert(!file.is_open());

        string cmdline;
        string srecfile;

        srecfile.assign(makeTemporaryFilename());
        cmdline = string(CMD_GNUOBJCOPY) + " -F srec " + filename + " " + srecfile;
        VerboseMessage("[EXEC] %\n") << cmdline;

		system(cmdline.c_str());

            /* �������J������t�@�C�����폜 */
        file.open(srecfile.c_str(), ios::in);
        if(file.is_open()) {
            remove(srecfile.c_str());
        }
    }

        /* 16�i����10�i�ւ̕ϊ� (�|�C���^�ړ�, �����w��t��) */
    unsigned int hextodec(const char * & src, size_t length) throw()
    {
        assert(length <= sizeof(unsigned int) * 2);

        unsigned int result = 0;
        unsigned int digit;

        while(length-- > 0) {
            if(*src >= '0' && *src <= '9')
                digit = *src - '0';
            else if(*src >= 'A' && *src <='F')
                digit = *src - 'A' + 10;
            else if(*src >= 'a' && *src <='f')
                digit = *src - 'a' + 10;
            else
                break;

            ++ src;
            result = (result << 4) | (digit & 0xf);
        }

        return result;
    }

        /* NM���o�͂����s���p�[�X */
    bool readGnuNmLine(fstream & file, FileContainer::address_t & address, string & attribute, string & symbolname) throw()
    {
        assert(file.is_open());

        string src;
        string addr;
        string::size_type pos1;
        string::size_type pos2;

            /* ���g����ɂ��Ă��� */
        address = 0;
        if(!attribute.empty())
            attribute.erase();
        if(!symbolname.empty())
            symbolname.erase();

            //���̍s���擾 (��s, ����`�V���{���͓ǂݔ�΂�)
        do {
            if(file.eof())
                return false;

            getline(file, src, '\n');
        } while(src.empty() || src.at(0) == ' ');

            //�s�𕪉�
        pos1 = src.find_first_of(' ');
        addr = src.substr(0, pos1);

        pos2 = src.find_first_of(' ', pos1 + 1);
        attribute  = src.substr(pos1 + 1, pos2 - pos1 - 1);
        symbolname = src.substr(pos2 + 1);

            //�A�h���X�̃p�[�X  (�� : �Ȃ�ł���Ȃ��܂��܂���Ă邩�Ƃ����ƁA�A�h���X��32bit�𒴂���^�[�Q�b�g�����邩��)
        while(!addr.empty()) {
            size_t length = addr.size();
            const char * src = addr.c_str();
            if(length > sizeof(unsigned int) * 2)
                length = sizeof(unsigned int) * 2;
            address = (address << (length * 2)) | (hextodec(src, length));
            addr.erase(0, length);
        }

        return true;
    }

        /* �V���{���̓ǂݍ��� */
    void FileContainerBinutilsImpl::loadSymbols(fstream & file) throw(Exception)
    {
        assert(file.is_open());

        address_t address;
        string    attribute;
        string    symbolname;

        while(readGnuNmLine(file, address, attribute, symbolname)) {
            symbol_table.insert(map<string, address_t>::value_type(symbolname, address));
        }

		VerboseMessage("% symbols loaded\n") << symbol_table.size() << &throwException;

        file.close();
    }

        /* contents��1�o�C�g�������� */
    void FileContainerBinutilsImpl::writeByte(address_t address, unsigned int value) throw(Exception)
    {
        address_t & base = last_address;
        char *    & page = last_page;

            /* �L���b�V�����ǂ����g���Ȃ��Ȃ�A�y�[�W��T�� */
        if(MAKE_BASEADDRESS(address) != last_address || last_page == 0) {
            map<address_t, char *>::iterator scope;

            base  = MAKE_BASEADDRESS(address);
            scope = contents.find(base);
            if(scope == contents.end()) {
                page = new(nothrow) char [SIZE_LOADPAGE];
                if(page == 0) {
                    ExceptionMessage("Not enough memory available to store the contents","�󂫃������s���̂��߁A�f�[�^�̊i�[�Ɏ��s���܂���").throwException();
                    return;
                }
                contents.insert(map<address_t,char*>::value_type(base, page));
            }
            else
                page = scope->second;
        }

        *(page + (address - base)) = static_cast<char>(value & 0xff);
    }

        /* �����̋󔒕�����؂��� */
    void trimString(string & src) throw()
    {
        string::size_type pos;

        pos = src.find_last_not_of(" \t\r\n");
        if(pos != string::npos && pos != src.size())
            src.erase(pos + 1);
    }

        /* ���g���[��S���R�[�h����s�ǂݍ��� */
        /*
                The general format of an S-record follows: 
                +-------------------//------------------//-----------------------+
                | type | count | address  |            data           | checksum |
                +-------------------//------------------//-----------------------+
        */
    bool readRecord(fstream & file, string & dest) throw(Exception)
    {
        unsigned int sum;
        unsigned int count;
        unsigned int i;
        const char * pos;

            /* ���̍s��ǂݍ��� */
        do {
                //getline��ReadFile���Ă�Ńu���b�N����̂ŁA�m����EOF�𔽉������邽�߂ɂ�������
            int ch = file.get();
            if(ch == EOF)
                return false;

            file.putback(static_cast<char>(ch));
            getline(file, dest);
        } while(dest.empty());

        trimString(dest);

            /* �������̔��� */

        if(dest[0] != 'S')      //�s����'S'�Ŏn�܂�Ȃ�
            ExceptionMessage("The file is not a Motorola S-Record file.","���g���[��S�t�H�[�}�b�g�Ŗ����s��������܂���") << throwException;

        pos = dest.c_str() + 2;
        count = hextodec(pos, 2);
        if(dest.size() != (count + 2)*2)
            ExceptionMessage("Illegal S-Record found (count unmatched).","�s����S���R�[�h������܂� (�T�C�Y�s��v)") << throwException;

        sum = count;
        for(i = 0; i < count; ++ i)
            sum += hextodec(pos, 2);

        if((sum & 0xff) != 0xff)
            ExceptionMessage("Illegal S-Record found (check-sum unmatched).","�s����S���R�[�h������܂� (�`�F�b�N�T���s��v)") << throwException;

        return true;
    }

        /* ���̊J�n�A�h���X�𓾂� */
    FileContainer::address_t parseRecordAddress(const string & src, FileContainer::address_t base) throw()
    {
        const char * record = src.c_str();
        FileContainer::address_t result = 0;

        record += 4;
        switch(*(record - 3)) {
            case '1':
                result = hextodec(record, 4);
                break;
            case '2':
                result = hextodec(record, 6);
                break;
            case '3':
                result = hextodec(record, 8);
                break;
            case '5':
                result = base;
                break;
            default:
                break;
        }

        return result;
    }

        /* �f�[�^�����������c���ă`���b�v */
    void chopRecord(string & src) throw()
    {
        string::size_type start;

        switch(src[1]) {
            case '1':  start = 4 + 4;  break;
            case '2':  start = 4 + 6;  break;
            case '3':  start = 4 + 8;  break;
            default:   start = 4;      break;
        }

            //�擪4�o�C�g + �A�h���X�� + �Ō�̃T������菜��
        src = src.substr(start, src.size() - start - 2);
    }

        /* �v���O�����f�[�^�̓ǂݍ��� */
    void FileContainerBinutilsImpl::loadDataContents(fstream & file) throw(Exception)
    {
        assert(file.is_open());

        address_t address;
        string    line;

        address = 0;
        while(readRecord(file, line)) {

            address = parseRecordAddress(line, address);

            chopRecord(line);

                /* �f�[�^�̊i�[ */
            const char * pos = line.c_str();
            while(*pos != '\x0') {
                unsigned int data = hextodec(pos, 2);
                writeByte(address, data);
                ++ address;
            }
        }

        file.close();
    }

        /* �V���{���v���t�B�N�X�̎������� */
    void FileContainerBinutilsImpl::searchSymbolPrefix(void) throw()
    {
        const char *  candidate_list[] = {"", "_", NULL};
        const char ** candidate;

        for(candidate = candidate_list; *candidate != NULL; ++ candidate) {
            map<string, address_t>::const_iterator scope;
            string symbol;
            
            symbol = string(*candidate) + MAGIC_SYMBOL;
            scope  = symbol_table.find(symbol);

            if(scope != symbol_table.end())
                break;
        }

        if(*candidate != NULL)
            symbol_prefix.assign(*candidate);
    }

        /* �G���f�B�A���̎������� */
    void FileContainerBinutilsImpl::searchByteOrder(void) throw()
    {
        address_t address;
        union {
            char         buffer[4];
            unsigned int value;
        };

        try {
            value   = 0;
            address = getSymbolAddress(MAGIC_SYMBOL);
            loadContents(buffer, address, 4);

            if(value == MAGIC_NUMBER) {
                byteorder = HOSTORDER;
            }
            else {
                buffer[0] ^= buffer[3], buffer[3] ^= buffer[0], buffer[0] ^= buffer[3]; // swap(buffer[0], buffer[3])
                buffer[1] ^= buffer[2], buffer[2] ^= buffer[1], buffer[1] ^= buffer[2]; // swap(buffer[1], buffer[2])

                if(value == MAGIC_NUMBER)
                    byteorder = HOSTORDER == LITTLE ? BIG : LITTLE;
                else
                    throw false;
            }
        }
        catch(...) {}
    }

        /* ���W���[���̃A�^�b�` -> �V���{���Ǐo��, �f�[�^�i�[ */
    void FileContainerBinutilsImpl::attachModule(const string & filename) throw(Exception)
    {
        fstream file;
        string  symbol_filename;
        string  contents_filename;

        splitFilename(filename, symbol_filename, contents_filename);

        openTextFile(file, symbol_filename, interceptWithGnuNM);
        loadSymbols(file);

        openTextFile(file, contents_filename, interceptWithGnuObjcopy);
        loadDataContents(file);

        searchSymbolPrefix();
        searchByteOrder();
    }

        /* �i�[���Ă�����e�̎擾 */
    void FileContainerBinutilsImpl::loadContents(void * _dest, address_t address, size_t size) throw(Exception)
    {
        char * dest = static_cast<char *>(_dest);

        while(size > 0) {
            map<address_t, char *>::const_iterator scope;

            address_t  base   = MAKE_BASEADDRESS(address);
            address_t  offset = MAKE_OFFSETADDRESS(address);
            size_t     transfer_size = size;

            if(transfer_size > SIZE_LOADPAGE - offset)
                transfer_size = SIZE_LOADPAGE - offset;

            scope = contents.find(base);
            if(scope == contents.end())
                ExceptionMessage("[Internel error] Memory read with unmapped address","[�����G���[] �}�b�v����ĂȂ��A�h���X���g���ă��������[�h���s���܂���").throwException();

            memcpy(dest, scope->second + offset, transfer_size);

            dest += transfer_size;
            size -= transfer_size;
        }
    }

        /* �V���{���̃A�h���X�̎擾 */
    FileContainer::address_t FileContainerBinutilsImpl::getSymbolAddress(const string & symbol) throw(Exception)
    {
        string symbolname;
        map<string, address_t>::const_iterator scope;

        symbolname = symbol_prefix + symbol;

        scope = symbol_table.find(symbolname);
        if(scope == symbol_table.end())
            ExceptionMessage("Unknown symbol '%'","�s���ȃV���{���� '%'") << symbol << throwException;

        return scope->second;
    }

        /* �A�[�L�e�N�`�����̎擾 */
    string FileContainerBinutilsImpl::getArchitecture(void) throw()
    {
        if(byteorder == LITTLE)
            return "Little endian target (with GNU/Binutils)";
        else
            return "Big endian target (with GNU/Binutils)";
    }

}

//---------------------------------------------

#ifdef TESTSUITE
#include "base/coverage_undefs.h"

namespace {
    fstream * interceptor_file;
    string    interceptor_filename;
    void interceptor(fstream & file, const string & filename)
    {
        CHECKPOINT("interceptor");
        interceptor_file = &file;
        interceptor_filename = filename;

        if(filename.compare("textfile") == 0) {
            remove(filename.c_str());
            file.open(filename.c_str(), ios::out);
            file << "text";
            file.close();

            file.open(filename.c_str(), ios::in|ios::binary);
        }
        else if(filename.compare("binaryfile") == 0) {
            remove(filename.c_str());
            file.open(filename.c_str(), ios::out|ios::binary);
            file.write("\x1",1);
            file.close();

            file.open(filename.c_str(), ios::in|ios::binary);
        }
    }
}

TESTSUITE(main, FileContainerBinutilsImpl)
{
    PREDECESSOR("TFileContainer");

    SingletonBase::ContextChain chain;
    chain.saveContext<RuntimeObjectTable>();

    BEGIN_CASE("splitFilename","splitFilename") {
        BEGIN_CASE("1","�J���}�̑O��Ő؂��") {
            string first, second;
            
            splitFilename("a,b", first, second);
            TEST_CASE("1","first�̒��g�͐�����", first.compare("a") == 0);
            TEST_CASE("2","second�̒��g�͐�����", second.compare("b") == 0);
        } END_CASE;

        BEGIN_CASE("2","�J���}�̖���������^����ƁA�����ɓ������g������") {
            string first, second;

            splitFilename("abc", first, second);
            TEST_CASE("1","first�̒��g�͐�����", first.compare("abc") == 0);
            TEST_CASE("2","second�̒��g�͐�����", second.compare("abc") == 0);
        } END_CASE;

        BEGIN_CASE("3","�󕶎���^����Ɨ�O") {
            bool result = false;
            string first, second;
            try { splitFilename("", first, second); } catch(Exception &) { result = true; }
            if(!result)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("hasBinaryContents","hasBinaryContents") {
        BEGIN_CASE("1","�e�L�X�g�t�@�C����H�킹��") {
            fstream file("test", ios::out);
            file << "This is a sample text file.";
            file.close();

            file.open("test",ios::in|ios::binary);
            TEST_CASE("1","�֐���false��Ԃ�", !hasBinaryContents(file));
            TEST_CASE("2","file��eof�ɒB���Ă��Ȃ�", !file.eof());
            file.close();

            remove("test");
        } END_CASE;

        BEGIN_CASE("2","�o�C�i���f�[�^��H�킹��") {
            fstream file("test", ios::out|ios::binary);
            file << "This is a sample text file.";
            file.write("\x0\x1\x2\x3", 4);
            file.close();

            file.open("test",ios::in|ios::binary);
            TEST_CASE("1","�֐���true��Ԃ�", hasBinaryContents(file));
            TEST_CASE("2","file��eof�ɒB���Ă��Ȃ�", !file.eof());
            file.close();

            remove("test");
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("openTextFile","openTextFile") {
        BEGIN_CASE("1","�e�L�X�g�t�@�C�����w�肷��") {
            TestSuite::clearCheckpoints();
            fstream file("test", ios::out);
            file << "This is a sample text file.";
            file.close();

            bool result = true;
            try { openTextFile(file, "test", interceptor); } catch(Exception &) { result = false; }

            TEST_CASE("1","��O�͋N���Ȃ�", result);
            TEST_CASE("2","�t�@�C�����J����Ă���", file.is_open());
            TEST_CASE("3","interceptor�̓R�[������Ă��Ȃ�", !TestSuite::isReached("interceptor"));

            string work;
            getline(file, work, '\n');
            TEST_CASE("4","�ǂݏo���ꂽ���e��������", work.compare("This is a sample text file.") == 0);

            file.close();
            remove("test");
        } END_CASE;

        BEGIN_CASE("2","�o�C�i���t�@�C�����w�肷�� (interceptor�̓t�@�C�����J���Ȃ�)") {
            TestSuite::clearCheckpoints();
            fstream file("test", ios::out|ios::binary);
            file.write("\x1", 1);
            file.close();

            bool result = false;
            try { openTextFile(file, "test", interceptor); } catch(Exception &) { result = true; }

            TEST_CASE("1","��O���N����", result);
            TEST_CASE("2","�t�@�C�����J����Ă���", !file.is_open());
            TEST_CASE("3","interceptor���R�[������Ă���", TestSuite::isReached("interceptor"));
            TEST_CASE("4","interceptor�̈����������� (file)", interceptor_file == &file);
            TEST_CASE("5","interceptor�̈�����������", interceptor_filename.compare("test") == 0);

            file.close();
            remove("test");
        } END_CASE;

        BEGIN_CASE("3","���݂��Ȃ��t�@�C�����w�肷��") {
            TestSuite::clearCheckpoints();
            fstream file;
            bool result = false;
            try { openTextFile(file, "___unknown___", interceptor); } catch(Exception &) { result = true; }

            TEST_CASE("1","��O���N����", result);
            TEST_CASE("2","�t�@�C�����J����Ă��Ȃ�", !file.is_open());
            TEST_CASE("3","interceptor���R�[������Ă��Ȃ�", !TestSuite::isReached("interceptor"));
        } END_CASE;

        BEGIN_CASE("4","interceptor���e�L�X�g�t�@�C���𐶐�����") {
            TestSuite::clearCheckpoints();
            fstream file("textfile", ios::out|ios::binary);
            file.write("\x1", 1);
            file.close();

            bool result = true;
            try { openTextFile(file, "textfile", interceptor); } catch(Exception &) { result = false; }

            TEST_CASE("1","��O�͋N���Ȃ�", result);
            TEST_CASE("2","�t�@�C�����J����Ă���", file.is_open());
            TEST_CASE("3","interceptor���R�[������Ă���", TestSuite::isReached("interceptor"));
            TEST_CASE("4","interceptor�̈����������� (file)", interceptor_file == &file);
            TEST_CASE("5","interceptor�̈�����������", interceptor_filename.compare("textfile") == 0);

            string work;
            getline(file, work, '\n');
            TEST_CASE("4","�ǂݏo���ꂽ���e��������", work.compare("text") == 0);

            file.close();
            remove("textfile");
        } END_CASE;

        BEGIN_CASE("5","interceptor���o�C�i���t�@�C���𐶐�����") {
            TestSuite::clearCheckpoints();
            fstream file("binaryfile", ios::out|ios::binary);
            file.write("\x1", 1);
            file.close();

            bool result = false;
            try { openTextFile(file, "binaryfile", interceptor); } catch(Exception &) { result = true; }

            TEST_CASE("1","��O�͋N����", result);
            TEST_CASE("2","�t�@�C�����J����Ă��Ȃ�", !file.is_open());
            TEST_CASE("3","interceptor���R�[������Ă���", TestSuite::isReached("interceptor"));
            TEST_CASE("4","interceptor�̈����������� (file)", interceptor_file == &file);
            TEST_CASE("5","interceptor�̈�����������", interceptor_filename.compare("binaryfile") == 0);

            file.close();
            remove("binaryfile");
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("hextodec","hextodec") {
        const char * letter = "0123456789abcdEFg";
        const char * work = letter;

        TEST_CASE("1", "�؂�o���ꂽ�l��������", hextodec(work, 2) == 1);
        TEST_CASE("2", "work���i��ł���", work == letter + 2);
        TEST_CASE("3", "�؂�o���ꂽ�l��������", hextodec(work, 4) == 0x2345);
        TEST_CASE("4", "work���i��ł���", work == letter + 6);
        TEST_CASE("5", "�؂�o���ꂽ�l��������", hextodec(work, 8) == 0x6789abcd);
        TEST_CASE("6", "work���i��ł���", work == letter + 14);
        TEST_CASE("7", "�؂�o���ꂽ�l��������", hextodec(work, 8) == 0xef);
        TEST_CASE("8", "work��'g'�̈ʒu�łƂ܂�", *work == 'g');
        TEST_CASE("9", "�؂�o���ꂽ�l��������", hextodec(work, 8) == 0);
        TEST_CASE("10", "work��'g'�̈ʒu�łƂ܂�", *work == 'g');
    } END_CASE;

    BEGIN_CASE("readGnuNmLine","readGnuNmLine") {
        fstream file("test", ios::out);
        file << "0804aab0 T _kernel_task_initialize\n0805d8a0 B _kernel_tcb_table\n\n0804e560 R _kernel_tinib_table\n         U getpid@@GLIBC_2.0\n";
        file.close();

        address_t address;
        string    attribute;
        string    symbolname;

        file.open("test", ios::in);
        BEGIN_CASE("1","���ʂ̃G���g�����ǂ߂�") {
            TEST_CASE("1","�֐��͐�������", readGnuNmLine(file, address, attribute, symbolname));
            TEST_CASE("2","address�͐�����", address == 0x0804aab0);
            TEST_CASE("3","attribute�͐�����", attribute.compare("T") == 0);
            TEST_CASE("4","symbolname�͐�����", symbolname.compare("_kernel_task_initialize") == 0);
        } END_CASE;

        BEGIN_CASE("2","���ʂ̃G���g�����ǂ߂� (2)") {
            TEST_CASE("1","�֐��͐�������", readGnuNmLine(file, address, attribute, symbolname));
            TEST_CASE("2","address�͐�����", address == 0x0805d8a0);
            TEST_CASE("3","attribute�͐�����", attribute.compare("B") == 0);
            TEST_CASE("4","symbolname�͐�����", symbolname.compare("_kernel_tcb_table") == 0);
        } END_CASE;

        BEGIN_CASE("3","��s��ǂݔ�΂��Ď����ǂ߂�") {
            TEST_CASE("1","�֐��͐�������", readGnuNmLine(file, address, attribute, symbolname));
            TEST_CASE("2","address�͐�����", address == 0x0804e560);
            TEST_CASE("3","attribute�͐�����", attribute.compare("R") == 0);
            TEST_CASE("4","symbolname�͐�����", symbolname.compare("_kernel_tinib_table") == 0);
        } END_CASE;

        BEGIN_CASE("4","�A�h���X�̖����G���g���͖�������") {
            TEST_CASE("1","�֐��͎��s����", !readGnuNmLine(file, address, attribute, symbolname));
        } END_CASE;

        file.close();
        remove("test");
    } END_CASE;

    BEGIN_CASE("loadSymbols","loadSymbols") {
        fstream file("test", ios::out);
        file << "0804aab0 T _kernel_task_initialize\n0805d8a0 B _kernel_tcb_table\n\n0804e560 R _kernel_tinib_table\n         U getpid@@GLIBC_2.0\n";
        file.close();

        file.open("test",ios::in);

        FileContainerBinutilsImpl fcbi;
        fcbi.loadSymbols(file);

        TEST_CASE("1","�ǂݍ��܂ꂽ�G���g���̐���������", fcbi.symbol_table.size() == 3);
        TEST_CASE("2","�t�@�C���͕����Ă���", !file.is_open());

        remove("test");
    } END_CASE;

    BEGIN_CASE("writeByte","writeByte") {
        FileContainerBinutilsImpl fcbi;

        BEGIN_CASE("1","���݂��Ȃ��y�[�W�ւ̏�������") {
            TEST_CASE("0", "[�O��] contents�̗v�f����0", fcbi.contents.size() == 0);
            fcbi.writeByte(0x100, 0);

            TEST_CASE("1","contents�̗v�f�������Ă���", fcbi.contents.size() == 1);

            const char * scope = fcbi.contents.find(MAKE_BASEADDRESS(0x100))->second + MAKE_OFFSETADDRESS(0x100);
            TEST_CASE("2","�������܂�Ă�����e��������", *scope == 0);
        } END_CASE;

        BEGIN_CASE("2","���݂���y�[�W�ւ̏������� (�A���A�N�Z�X)") {
            fcbi.writeByte(0x100, 0xff);

            TEST_CASE("1","contents�̗v�f�������Ă��Ȃ�", fcbi.contents.size() == 1);

            const char * scope = fcbi.contents.find(MAKE_BASEADDRESS(0x100))->second + MAKE_OFFSETADDRESS(0x100);
            TEST_CASE("2","�������܂�Ă�����e��������", *scope == 0xff);
        } END_CASE;

        BEGIN_CASE("3","�V�����y�[�W�ւ̏�������") {
            fcbi.writeByte(0x10000000, 0xff);

            TEST_CASE("1","contents�̗v�f�������Ă���", fcbi.contents.size() == 2);

            const char * scope = fcbi.contents.find(MAKE_BASEADDRESS(0x10000000))->second + MAKE_OFFSETADDRESS(0x10000000);
            TEST_CASE("2","�������܂�Ă�����e��������", *scope == 0xff);
        } END_CASE;

        BEGIN_CASE("4","�����̃y�[�W�ւ̃A�N�Z�X") {
            fcbi.writeByte(0x100, 0x0);

            TEST_CASE("1","contents�̗v�f�������Ă��Ȃ�", fcbi.contents.size() == 2);

            const char * scope = fcbi.contents.find(MAKE_BASEADDRESS(0x100))->second + MAKE_OFFSETADDRESS(0x100);
            TEST_CASE("2","�������܂�Ă�����e��������", *scope == 0x0);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("readRecord","readRecord") {
        fstream file("test",ios::out);
        file << "S315080480F42F6C69622F6C642D6C696E75782E736F98\n\nS315080480F42F6C69622F6C642D6C696E75782E736F98\nS308080481042E320005\nDUMMY\nS31808048108040000001000000001000000474E550056\nS31008048108040000001000000001000000474E550056\n";
        file.close();

        file.open("test",ios::in);
        BEGIN_CASE("1","����P�[�X") {
            string work;
            bool result;
            bool exception = false;
            try { result = readRecord(file, work); } catch(Exception &) { exception = true; }
            TEST_CASE("1","��O�͋N����Ȃ�", !exception);
            TEST_CASE("2","�֐���true��Ԃ�", result);
            TEST_CASE("3","�ǂݏo���ꂽ���e��������", work.compare("S315080480F42F6C69622F6C642D6C696E75782E736F98") == 0);
        } END_CASE;

        BEGIN_CASE("2","����P�[�X (��s�̓ǂݔ�΂�)") {
            string work;
            bool result;
            bool exception = false;
            try { result = readRecord(file, work); } catch(Exception &) { exception = true; }
            TEST_CASE("1","��O�͋N����Ȃ�", !exception);
            TEST_CASE("2","�֐���true��Ԃ�", result);
            TEST_CASE("3","�ǂݏo���ꂽ���e��������", work.compare("S315080480F42F6C69622F6C642D6C696E75782E736F98") == 0);
        } END_CASE;

        BEGIN_CASE("3","�`�F�b�N�T��������Ă���G���g��") {
            string work;
            bool result;
            bool exception = false;
            try { result = readRecord(file, work); } catch(Exception &) { exception = true; }
            TEST_CASE("1","��O��������", exception);
        } END_CASE;

        BEGIN_CASE("4","�擪��S�Ŏn�܂�Ȃ��G���g��") {
            string work;
            bool result;
            bool exception = false;
            try { result = readRecord(file, work); } catch(Exception &) { exception = true; }
            TEST_CASE("1","��O��������", exception);
        } END_CASE;

        BEGIN_CASE("5","�w�肳�ꂽ�������������G���g��") {
            string work;
            bool result;
            bool exception = false;
            try { result = readRecord(file, work); } catch(Exception &) { exception = true; }
            TEST_CASE("1","��O��������", exception);
        } END_CASE;

        BEGIN_CASE("6","�w�肳�ꂽ���������Z���G���g��") {
            string work;
            bool result;
            bool exception = false;
            try { result = readRecord(file, work); } catch(Exception &) { exception = true; }
            TEST_CASE("1","��O��������", exception);
        } END_CASE;

        BEGIN_CASE("7","�t�@�C���I�[") {
            string work;
            bool result;
            bool exception = false;
            try { result = readRecord(file, work); } catch(Exception &) { exception = true; }
            TEST_CASE("1","��O���������Ȃ�", !exception);
            TEST_CASE("2","�֐���false��Ԃ�", !result);
        } END_CASE;

        remove("test");
    } END_CASE;

    BEGIN_CASE("chopRecord","chopRecord") {
        BEGIN_CASE("1","S1���R�[�h") {
            string src("S106080480F42F4A");

            chopRecord(src);
            TEST_CASE("1","�l��������", src.compare("80F42F") == 0);
        } END_CASE;

        BEGIN_CASE("2","S2���R�[�h") {
            string src("S206080480F42F4A");

            chopRecord(src);
            TEST_CASE("1","�l��������", src.compare("F42F") == 0);
        } END_CASE;

        BEGIN_CASE("3","S3���R�[�h") {
            string src("S306080480F42F4A");

            chopRecord(src);
            TEST_CASE("1","�l��������", src.compare("2F") == 0);
        } END_CASE;

        BEGIN_CASE("4","S4���R�[�h") {
            string src("S406080480F42F4A");

            chopRecord(src);
            TEST_CASE("1","�l��������", src.compare("080480F42F") == 0);
        } END_CASE;

        BEGIN_CASE("5","S5���R�[�h") {
            string src("S506080480F42F4A");

            chopRecord(src);
            TEST_CASE("1","�l��������", src.compare("080480F42F") == 0);
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("loadDataContents/loadContents","loadDataContents/loadContents") {
        fstream file("test", ios::out);
        file << "S30D000000000123456789ABCDEF32\nS509FEDCBA9876543210BE";
        file.close();

        BEGIN_CASE("1","����P�[�X") {
            FileContainerBinutilsImpl fcbi;

            file.open("test",ios::in);
            bool exception = false;
            try { fcbi.loadDataContents(file); } catch(...) { exception = true; }

            TEST_CASE("1","��O�͋N����Ȃ�", !exception);
            TEST_CASE("2","�f�[�^���m�ۂ���Ă���", fcbi.contents.size() == 1);
            TEST_CASE("3","�t�@�C���͕����Ă���", !file.is_open());
            BEGIN_CASE("4","�i�[�����l���������ǂ߂�") {
                unsigned int i;

                assert(sizeof(unsigned int) >= 4);
                i = 0;
                
                fcbi.loadContents(&i, 0, 4);
                TEST_CASE("1","1-4�o�C�g��", i == 0x67452301);
                fcbi.loadContents(&i, 4, 4);
                TEST_CASE("1","5-8�o�C�g��", i == 0xefcdab89);
                fcbi.loadContents(&i, 8, 4);
                TEST_CASE("1","9-12�o�C�g��", i == 0x98badcfe);
                fcbi.loadContents(&i,12, 4);
                TEST_CASE("1","13-16�o�C�g��", i == 0x10325476);
            } END_CASE;
        } END_CASE;
        remove("test");

        BEGIN_CASE("2","loadContents�ň�x�Ƀy�[�W�T�C�Y�𒴂���ʂ�v������") {
            FileContainerBinutilsImpl fcbi;
            unsigned int i;

            for(i=0;i<SIZE_LOADPAGE*2;++i)
                fcbi.writeByte(i, i);

            unsigned char * buffer = new unsigned char [SIZE_LOADPAGE * 2];
            fcbi.loadContents(buffer, 0, SIZE_LOADPAGE * 2);

            for(i=0;i<SIZE_LOADPAGE*2;++i)
                if(*(buffer + i) != (i & 0xff))
                    TEST_FAIL;

            delete [] buffer;
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("searchSymbolPrefix","searchSymbolPrefix") {

        BEGIN_CASE("1","�v���t�B�N�X���Ȃ�") {
            FileContainerBinutilsImpl fcbi;
            fcbi.symbol_table.insert(pair<string, address_t>(MAGIC_SYMBOL, 0x100));

            fcbi.searchSymbolPrefix();
            if(!fcbi.symbol_prefix.empty())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�ϐ�����\"_\"�����^�C�v") {
            FileContainerBinutilsImpl fcbi;
            fcbi.symbol_table.insert(pair<string, address_t>("_" MAGIC_SYMBOL, 0x100));

            fcbi.searchSymbolPrefix();
            if(fcbi.symbol_prefix.compare("_") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","\"__\"�ɂ͔������Ȃ�") {
            FileContainerBinutilsImpl fcbi;
            fcbi.symbol_table.insert(pair<string, address_t>("__" MAGIC_SYMBOL, 0x100));

            fcbi.searchSymbolPrefix();
            if(!fcbi.symbol_prefix.empty())
                TEST_FAIL;
        } END_CASE;
            
        BEGIN_CASE("4","�����ł��Ȃ��ꍇ�A�ύX���Ȃ�") {
            FileContainerBinutilsImpl fcbi;
            fcbi.symbol_prefix.assign("test");

            fcbi.searchSymbolPrefix();
            if(fcbi.symbol_prefix.compare("test") != 0)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("searchByteOrder","searchByteOrder") {
        BEGIN_CASE("1","�z�X�g�Ɠ����G���f�B�A��") {
            FileContainerBinutilsImpl fcbi;
            unsigned int value = MAGIC_NUMBER;
            fcbi.symbol_table.insert(pair<string, address_t>(MAGIC_SYMBOL, 0x100));

            for(int i=0;i<4;i++)
                fcbi.writeByte(0x100 + i, *((char *)&value + i));

            fcbi.byteorder = UNKNOWN;
            fcbi.searchByteOrder();

            if(fcbi.byteorder != HOSTORDER)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�z�X�g�ƈႤ�G���f�B�A��") {
            FileContainerBinutilsImpl fcbi;
            unsigned int value = MAGIC_NUMBER;
            fcbi.symbol_table.insert(pair<string, address_t>(MAGIC_SYMBOL, 0x100));

            for(int i=0;i<4;i++)
                fcbi.writeByte(0x100 + i, *((char *)&value + (3 - i)));

            fcbi.byteorder = UNKNOWN;
            fcbi.searchByteOrder();

            if(fcbi.byteorder == HOSTORDER)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","�V���{��������") {
            FileContainerBinutilsImpl fcbi;
            unsigned int value = MAGIC_NUMBER;

            for(int i=0;i<4;i++)
                fcbi.writeByte(0x100 + i, *((char *)&value + (3 - i)));

            fcbi.byteorder = UNKNOWN;
            fcbi.searchByteOrder();

            if(fcbi.byteorder != UNKNOWN)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","�f�[�^������") {
            FileContainerBinutilsImpl fcbi;
            unsigned int value = MAGIC_NUMBER;
            fcbi.symbol_table.insert(pair<string, address_t>(MAGIC_SYMBOL, 0x100));

            fcbi.byteorder = UNKNOWN;
            fcbi.searchByteOrder();

            if(fcbi.byteorder != UNKNOWN)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    chain.restoreContext();
}

#endif /* TESTSUITE */

#endif /* FILECONTAINER_BINUTILS || TESTSUITE */

