/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: filecontainer.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#ifdef _MSC_VER
#pragma warning(disable:4786) //�f�o�b�O�������255�����ɐ؂�l�߂�
#endif

#include "base/filecontainer.h"
#include <memory.h>
#include <fstream>

using namespace std;

namespace {
        /* �����Ȃ�10�i������̃p�[�X */
    char * parse_uint(char * src, unsigned int * dest, unsigned int default_value = 0)
    {
        int result = 0;

        if(*src < '0' || *src > '9') {
            *dest = default_value;
            return src;
        }

        do {
            result = result * 10 + *(src++) - '0';
        } while(*src >= '0' && *src <='9');

        *dest = result;
        return src;
    }
}

    /* �ϐ����̓ǂݍ��� */
void FileContainer::attachInfo(const string & filename) throw(Exception)
{
    char    buffer[256];
    fstream file;

    char * work;
    struct tagVariableInfo info;

    memset(&info, 0, sizeof(info));

    file.open(filename.c_str(), ios::in);
    if(!file.is_open()) {
        ExceptionMessage("Structure information file(%) was not found. ","�\���̏��t�@�C��(%)��������܂��� ") << filename << throwException;
        return;
    }

    while(!file.eof())
    {
        file.get(buffer, 256);

        if(!file.fail()) {
            switch(buffer[0])
            {
            case 's':
                {
                    unsigned int address = 0;
                    unsigned int size    = 0;

                    work = buffer+1;
                    while(*work != ',' && *work != '\x0')
                        work++;
                    if(*work != '\x0') {
                        *work = '\x0';
                        work = parse_uint(work+1,&size);
                        work = parse_uint(work+1,&address);
                    }

                    info.address = static_cast<address_t>(address);
                    info.size    = static_cast<size_t>(size);
                    variableinfo[string(buffer+1)] = info;
                    break;
                }

            case 'd':   //���ʎq���͖���
                break;

            default:
                ExceptionMessage("Unknown information type identifier found - [%]","���m�̌^���ʎq - [%]") << buffer[0] << throwException;
            }
        }
        else
            file.clear();

        file.get();
    }

    file.close();
}

    /* �ϐ����̎擾 */
struct FileContainer::tagVariableInfo FileContainer::getVariableInfo(const string & name) throw(Exception)
{
    map<string, tagVariableInfo>::const_iterator scope;

    scope = variableinfo.find(name);
    if(scope == variableinfo.end()) {
        ExceptionMessage("Operation against the unknwon symbol [%] was rejected.","�s���ȃV���{���� [%] �̏����擾���悤�Ƃ��Ă��܂�") << name << throwException;

        struct tagVariableInfo dummy;
        memset(&dummy, 0, sizeof(dummy));
        return dummy;
    }

    return scope->second;
}


    /* �R���X�g���N�^ (�V���{�������w�肵�ď�����) */
TargetVariableBase::TargetVariableBase(const std::string & sym) throw() 
    : address(0), size(0), offset(0), structure_size(0), loaded(false)
{
    try{
        FileContainer * fc = FileContainer::getInstance();
        address = fc->getSymbolAddress(sym);
        size    = fc->getVariableInfo(sym).size;
        structure_size = size;
    }
    catch(...) {
        address = 0;
        size    = 0;
    }
}

    /* �R���X�g���N�^ (�V���{����, �f�[�^�����w�肵�ď�����) */
TargetVariableBase::TargetVariableBase(const string & sym, size_t _size) throw() 
    : address(0), size(_size), offset(0), structure_size(_size), loaded(false)
{
    try{
        FileContainer * fc = FileContainer::getInstance();
        address = fc->getSymbolAddress(sym);
    }
    catch(...) {
        address = 0;
        size    = 0;
    }
}

    /* �R���X�g���N�^ (�V���{�����A�����o�����w�肵�ď�����) */
TargetVariableBase::TargetVariableBase(const string & sym, const string & sz) throw() 
    : address(0), size(0), offset(0), structure_size(0), loaded(false)
{
    try{
        FileContainer * fc = FileContainer::getInstance();
        address = fc->getSymbolAddress(sym);                                //�\���̂̐擪�A�h���X
        size    = fc->getVariableInfo(sz).size;                             //�����o�ϐ��̒���
        offset  = static_cast<size_t>(fc->getVariableInfo(sz).address);     //�����o�ϐ��̃I�t�Z�b�g
        structure_size = fc->getVariableInfo(sym).size;                     //�\���̂̒���
    }
    catch(...) {
        address = 0;
        size    = 0;
    }
}

    /* �R�s�[�R���X�g���N�^ */
TargetVariableBase::TargetVariableBase(const TargetVariableBase & src) throw()
    : address(0), size(0), offset(0), structure_size(0), loaded(false)
{
    if(src.isValid()) {
        address        = src.address;
        size           = src.size;
        offset         = src.offset;   
        structure_size = src.structure_size;
        loaded         = false;
    }
}


    /* �I�u�W�F�N�g���e�̎擾 */
void TargetVariableBase::loadContent(void * dest, size_t dest_size) throw(Exception)
{
    char * buffer = 0;

    try {
        if(isValid()) {
            buffer = new char[getSize()];
            FileContainer * fc = FileContainer::getInstance();

            fc->loadContents(buffer, getAddress() + getOffset(), getSize());
            if(fc->getByteOrder() != FileContainer::HOSTORDER)
                changeEndian(buffer, getSize());

            if(size < dest_size)
                memset(dest, 0, dest_size);
            else if(size > dest_size)
                ExceptionMessage("[TargetVariableBase::loadContent] Destination storage is too small to store the contents.","[TargetVariableBase::loadContent] �o�͐�o�b�t�@�̃T�C�Y�����������܂�").throwException();
            memcpy(dest, buffer, getSize());

            delete [] buffer;
            loaded = true;
        }
        else {
            ExceptionMessage("loadContent was performed with an illegal target variable.","�s���ȃ^�[�Q�b�g�ϐ�����loadContent���Ă΂�܂���").throwException();
        }
    }
    catch(bad_alloc &) {
        ExceptionMessage("No available memory [%B]","�������s���ł� [%B]") << (unsigned int)getSize() << throwException;
    }
    catch(Exception &) {
        if(buffer)
            delete [] buffer;
        throw;
    }
}

    /* �o�C�g�I�[�_�̕ύX */
void TargetVariableBase::changeEndian(char * buffer, size_t size) throw()
{
    char * tail = buffer + size - 1;

    while(buffer < tail) {
        char temporary = *buffer;
        *buffer = *tail;
        *tail   = temporary;

        ++ buffer;
        -- tail;
    }
}



//---------------------------------------------

#ifdef TESTSUITE
#include "base/coverage_undefs.h"

#include <cctype>
#define _isprint(x) isprint(x)

class TFileContainer : public FileContainer
{
public:
    TFileContainer(void) throw() {}
    virtual ~TFileContainer(void) throw() {}

    string module;
    void attachModule(const std::string & _module) throw(Exception) 
    {
        CHECKPOINT("attachModule"); 
        module = _module;
    }

    void *    dest;
    address_t addr;
    size_t    sz;
    void loadContents(void * _dest, address_t _addr, size_t _sz) throw(Exception) 
    {
        CHECKPOINT("loadContents");
        dest = _dest;
        addr = _addr;
        sz   = _sz;
        memset(_dest, ~0, _sz);
    }

    string symbol;
    address_t getSymbolAddress(const std::string & _symbol) throw(Exception) 
    {
        CHECKPOINT("getSymbolAddress");
        symbol = _symbol;
        return 1; 
    }

    std::string getArchitecture(void) throw(Exception)
    {   return "TFileContainer";   }

    TESTSUITE_PROTOTYPE(main)
};

TESTSUITE(main, TFileContainer)
{
    PREDECESSOR("SingletonBase");
    PREDECESSOR("RuntimeObjectTable");

    SingletonBase::ContextChain chain;
    chain.saveContext<RuntimeObjectTable>();
    chain.renewInstance();

    BEGIN_CASE("getInstance","getInstance") {
        BEGIN_CASE("1","�����o�^����Ă��Ȃ��Ƃ���getInstance�ŗ�O") {
            bool result = false;
            try { FileContainer::getInstance(); } catch(Exception &) { result = true; }
            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","getInstance�ŃC���X�^���X���Ԃ�") {
            TFileContainer fc;
            FileContainer * instance;
            bool result = true;
            try { instance = FileContainer::getInstance(); } catch(...) { result = false; }
            TEST_CASE("1","��O�͂����Ȃ�", result);
            TEST_CASE("2","�擾�ł���C���X�^���X��������", instance == &fc);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("parse_uint","parse_uint") {
        BEGIN_CASE("1","������؂�o����") {
            unsigned int dest;
            char * src = "123";
            char * result = parse_uint(src, &dest);

            TEST_CASE("1","result���Ō�ɗ��Ă���", result == src + 3);
            TEST_CASE("2","�l�͐�����", dest == 123);
        } END_CASE;

        BEGIN_CASE("2","�����Ŗ���������^����ƃf�t�H���g�l���Ԃ�") {
            unsigned int dest;
            char * src = "abc";
            char * result = parse_uint(src, &dest, 1234567);

            TEST_CASE("1","result�͐i��ł��Ȃ�", result == src);
            TEST_CASE("2","�f�t�H���g�l���Ԃ�", dest == 1234567);
        } END_CASE;

        BEGIN_CASE("3","�f���~�^�łƂ܂�") {
            unsigned int dest;
            char * src = "321,123";
            char * result = parse_uint(src, &dest);

            TEST_CASE("1","result�͐i��ł��Ȃ�", result == src + 3);
            TEST_CASE("2","�f�t�H���g�l���Ԃ�", dest == 321);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("attachInfo","attachInfo") {
        BEGIN_CASE("1","���ʂɏ�����������") {
            fstream file("dummy",ios::out);
            file << "s_kernel_tinib_table,32,0\nstask_initialization_block::texrtn,4,28\n";
            file.close();

            TFileContainer fc;

            bool result = true;
            try { fc.attachInfo("dummy"); } catch(...) { result = false; }

            TEST_CASE("1","��O�͂����Ȃ�", result);

            map<string, struct tagVariableInfo>::iterator scope = fc.variableinfo.find("_kernel_tinib_table");
            TEST_CASE("2","�v�f���ǉ�����Ă��� (tinib)", scope != fc.variableinfo.end());
            TEST_CASE("3","�l�������� (tinib)", scope->second.size == 32);

            scope = fc.variableinfo.find("task_initialization_block::texrtn");
            TEST_CASE("4","�v�f���ǉ�����Ă��� (texrtn)", scope != fc.variableinfo.end());
            TEST_CASE("5","�l�������� (texrtn.size)", scope->second.size == 4);
            TEST_CASE("6","�l�������� (texrtn.address)", scope->second.address == 28);
        } END_CASE;
        remove("dummy");

        BEGIN_CASE("2","���ʕ��� 'd' �𖳎�����") {
            fstream file("dummy",ios::out);
            file << "ddummy,0\ndtask_initialization_block::texrtn,4,28\n";
            file.close();

            TFileContainer fc;

            bool result = true;
            try { fc.attachInfo("dummy"); } catch(...) { result = false; }

            TEST_CASE("1","��O�͂����Ȃ�", result);
            TEST_CASE("2","�v�f�͒ǉ�����Ă��Ȃ�", fc.variableinfo.size() == 0);
        } END_CASE;
        remove("dummy");

        BEGIN_CASE("3","��s�𖳎��ł���") {
            fstream file("dummy",ios::out);
            file << "s_kernel_tinib_table,32,0\n\nstask_initialization_block::texrtn,4,28\n";
            file.close();

            TFileContainer fc;

            bool result = true;
            try { fc.attachInfo("dummy"); } catch(...) { result = false; }

            TEST_CASE("1","��O�͂����Ȃ�", result);

            map<string, struct tagVariableInfo>::iterator scope = fc.variableinfo.find("_kernel_tinib_table");
            TEST_CASE("2","�v�f���ǉ�����Ă��� (tinib)", scope != fc.variableinfo.end());
            TEST_CASE("3","�l�������� (tinib)", scope->second.size == 32);

            scope = fc.variableinfo.find("task_initialization_block::texrtn");
            TEST_CASE("4","�v�f���ǉ�����Ă��� (texrtn)", scope != fc.variableinfo.end());
            TEST_CASE("5","�l�������� (texrtn.size)", scope->second.size == 4);
            TEST_CASE("6","�l�������� (texrtn.address)", scope->second.address == 28);
        } END_CASE;
        remove("dummy");

        BEGIN_CASE("4","'s'��'d'�ȊO���͂���") {
            char c;
            char msg[2] = {0, 0};

            for(c=0;c<128;++c) {
                if(isprint(c) && (c != 's' && c != 'd')) {
                    fstream file("dummy",ios::out);
                    file << c;
                    file << "dummy,0\n";
                    file.close();

                    TFileContainer fc;

                    bool result = false;
                    try { fc.attachInfo("dummy"); } catch(...) { result = true; }

                    msg[0] = c;
                    TEST_CASE_("1","��O��������", result, string(msg));
                    TEST_CASE_("2","�v�f�͒ǉ�����Ă��Ȃ�", fc.variableinfo.size() == 0, string(msg));
                }
            }
        } END_CASE;
        remove("dummy");
    } END_CASE;

    chain.restoreContext();
}

class TTargetVariable : public TargetVariable<int>
{
    TESTSUITE_PROTOTYPE(main)

        /*
         * �R���X�g���N�^ (TargetVariable<int>�ɉ�)
         */
    inline TTargetVariable(FileContainer::address_t addr) throw()
        : TargetVariable<int>(addr)
    {}
    
    inline TTargetVariable(FileContainer::address_t addr, size_t sz) throw()
        : TargetVariable<int>(addr, sz)
    {}

    inline TTargetVariable(FileContainer::address_t addr, size_t sz, size_t ofs, size_t ssz) throw()
        : TargetVariable<int>(addr, sz, ofs, ssz)
    {}

    inline TTargetVariable(const std::string & sym) throw()
        : TargetVariable<int>(sym)
    {}

    inline TTargetVariable(const std::string & sym, const std::string & sz) throw()
        : TargetVariable<int>(sym, sz)
    {}

        /* �f�X�g���N�^ (���ɉ������Ȃ�) */
    virtual ~TTargetVariable(void) throw() 
    {}
};

TESTSUITE(main, TTargetVariable)
{
    PREDECESSOR("SingletonBase");
    PREDECESSOR("TFileContainer");
    PREDECESSOR("RuntimeObjectTable");

    SingletonBase::ContextChain chain;
    chain.saveContext<RuntimeObjectTable>();
    chain.renewInstance();

    TFileContainer fc;
    fstream file("dummy",ios::out);
    file << "s_test,4,0\ns_kernel_tinib_table,32,0\nstask_initialization_block::texrtn,4,28\n";
    file.close();

    fc.attachInfo("dummy");

    BEGIN_CASE("constructor","�R���X�g���N�^") {
        BEGIN_CASE("1", "(address_t, size_t)") {
            TTargetVariable tv(1, 2);

            TEST_CASE("1","�ϐ��͗L��", tv.isValid());
            TEST_CASE("2","�A�h���X�͐�����", tv.getAddress() == 1);
            TEST_CASE("3","�T�C�Y�͐�����", tv.getSize() == 2);
            TEST_CASE("4","�I�t�Z�b�g��0", tv.getOffset() == 0);
            TEST_CASE("5","�\���̃T�C�Y�͕ϐ��T�C�Y�ƈꏏ", tv.getStructureSize() == tv.getSize());
        } END_CASE;

        BEGIN_CASE("2","(address_t, size_t, size_t, size_t)") {
            TTargetVariable tv(1,2,3,4);

            TEST_CASE("1","�ϐ��͗L��", tv.isValid());
            TEST_CASE("2","�A�h���X�͐�����", tv.getAddress() == 1);
            TEST_CASE("3","�T�C�Y�͐�����", tv.getSize() == 2);
            TEST_CASE("4","�I�t�Z�b�g�͐�����", tv.getOffset() == 3);
            TEST_CASE("5","�\���̃T�C�Y�͐�����", tv.getStructureSize() == 4);
        } END_CASE;

        BEGIN_CASE("3","(string)") {
            TestSuite::clearCheckpoints();

            TTargetVariable tv("_test");

            TEST_CASE("1","�ϐ��͗L��", tv.isValid());
            TEST_CASE("2","getSymbolAddress���R�[������Ă���", TestSuite::isReached("getSymbolAddress"));
            TEST_CASE("3","getSymbolAddress�̈�����������", fc.symbol.compare("_test") == 0);
            TEST_CASE("3","�A�h���X�͐�����", tv.getAddress() == 1);
            TEST_CASE("4","�T�C�Y�͐�����", tv.getSize() == 4);
            TEST_CASE("5","�I�t�Z�b�g�͐�����", tv.getOffset() == 0);
            TEST_CASE("6","�\���̃T�C�Y�͐�����", tv.getStructureSize() == 4);
        } END_CASE;

        BEGIN_CASE("4","(string,string)") {
            TestSuite::clearCheckpoints();

            TTargetVariable tv("_kernel_tinib_table", "task_initialization_block::texrtn");

            TEST_CASE("1","�ϐ��͗L��", tv.isValid());
            TEST_CASE("2","getSymbolAddress���R�[������Ă���", TestSuite::isReached("getSymbolAddress"));
            TEST_CASE("3","getSymbolAddress�̈�����������", fc.symbol.compare("_kernel_tinib_table") == 0);
            TEST_CASE("3","�A�h���X�͐�����", tv.getAddress() == 1);
            TEST_CASE("4","�T�C�Y�͐�����", tv.getSize() == 4);
            TEST_CASE("5","�I�t�Z�b�g�͐�����", tv.getOffset() == 28);
            TEST_CASE("6","�\���̃T�C�Y�͐�����", tv.getStructureSize() == 32);
        } END_CASE;

        BEGIN_CASE("5","�����ȃP�[�X") {
            TEST_CASE("1","�A�h���X0�̕ϐ��͖��� (1)", !TTargetVariable(0,4).isValid());
            TEST_CASE("2","�A�h���X0�̕ϐ��͖��� (2)", !TTargetVariable(0,4,4,4).isValid());
            TEST_CASE("3","�T�C�Y0�̕ϐ��͖��� (1)", !TTargetVariable(4,0).isValid());
            TEST_CASE("4","�T�C�Y0�̕ϐ��͖��� (2)", !TTargetVariable(4,0,4,4).isValid());
            TEST_CASE("5","�\���̃T�C�Y0�̕ϐ��͖���", !TTargetVariable(4,4,4,0).isValid());

            TEST_CASE("6","���݂��Ȃ��V���{�����̕ϐ�������(1)", !TTargetVariable("unknown").isValid());
            TEST_CASE("7","���݂��Ȃ��V���{�����̕ϐ�������(2)", !TTargetVariable("unknown","task_initialization_block::texrtn").isValid());
            TEST_CASE("8","���݂��Ȃ������o���̕ϐ�������", !TTargetVariable("_kernel_tinib_table","unknown").isValid());

            TEST_CASE("10","�i�[�̈悪�s�����Ă���ϐ�", !TTargetVariable("_kernel_tinib_table").isValid());
            TEST_CASE("11","�����Ȉ�������������ꍇ", !TTargetVariable(*((TTargetVariable *)0)).isValid());
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("loadContents", "loadContents") {
        BEGIN_CASE("1","�ʏ�N��") {
            int i;
            TTargetVariable tv(0x100);

            bool result = true;
            try { tv.loadContent(&i, sizeof(int)); } catch(...) { result = false; }

            TEST_CASE("1","��O�͋N����Ȃ�", result);
            TEST_CASE("2","���g��~0�Ńt�B������Ă���", i == ~0);
        } END_CASE;

        BEGIN_CASE("2","�������傫�Ȍ^�Ŏ󂯂�") {
            struct { int first; int second; } i;
            TTargetVariable tv(0x100);

            bool result = true;
            try { tv.loadContent(&i, sizeof(i)); } catch(...) { result = false; }

            TEST_CASE("1","��O�͋N����Ȃ�", result);
            TEST_CASE("2","���g��~0�Ńt�B������Ă���", i.first == ~0);
            TEST_CASE("3","�c���0�Ńt�B������Ă���", i.second == 0);
        } END_CASE;

        BEGIN_CASE("3","�����ȗv�f�ɑ΂��Ď��s����") {
            TTargetVariable tv(0, 0, 0, 0);
            int i;

            bool result = false;
            try{ tv.loadContent(&i, sizeof(i)); } catch(...) { result = true; }
            TEST_CASE("1","��O���N����", result);
        } END_CASE;

        BEGIN_CASE("4","�����������Ȍ^�Ŏ󂯂�") {
            char i;
            TTargetVariable tv(0x100);

            bool result = false;
            try { tv.loadContent(&i, sizeof(i)); } catch(...) { result = true; }

            TEST_CASE("1","��O���N����", result);
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("pointer_operators","�|�C���^���̉��Z") {
        TargetVariable<int> tv(0x100);
        TargetVariable<int> tvl(0x100);

        *tvl;

        TEST_CASE("0","[�O��] tv:�A�h���X��0x100", tv.getAddress() == 0x100);
        TEST_CASE("0","[�O��] tv:�T�C�Y��4", tv.getSize() == 4);
        TEST_CASE("0","[�O��] tv:�\���̃T�C�Y��4", tv.getStructureSize() == 4);
        TEST_CASE("0","[�O��] tv:�Ǐo������", !tv.isLoaded());
        TEST_CASE("0","[�O��] tvl:�A�h���X��0x100", tvl.getAddress() == 0x100);
        TEST_CASE("0","[�O��] tvl:�T�C�Y��4", tvl.getSize() == 4);
        TEST_CASE("0","[�O��] tvl:�\���̃T�C�Y��4", tvl.getStructureSize() == 4);
        TEST_CASE("0","[�O��] tvl:�Ǐo������", tvl.isLoaded());

        BEGIN_CASE("1","operator +") {
            TestSuite::clearCheckpoints();

            TargetVariable<int> work = tv + 0x10;
            TEST_CASE("1","work�̃A�h���X��0x140", work.getAddress() == 0x100 + sizeof(int) * 0x10);
            TEST_CASE("2","work�͓ǂݍ��܂�Ă��Ȃ�", !work.isLoaded());
        } END_CASE;

        BEGIN_CASE("2","operator -") {
            TestSuite::clearCheckpoints();

            TargetVariable<int> work = tv - 0x10;
            TEST_CASE("1","work�̃A�h���X��0xc0", work.getAddress() == 0x100 - sizeof(int) * 0x10);
            TEST_CASE("2","work�͓ǂݍ��܂�Ă��Ȃ�", !work.isLoaded());
        } END_CASE;

        BEGIN_CASE("3","operator ++") {
            TestSuite::clearCheckpoints();

            TargetVariable<int> work(tvl);

            TargetVariable<int> result = (++ work);

            TEST_CASE("1","work�̃A�h���X��0x104", work.getAddress() == 0x100 + sizeof(int));
            TEST_CASE("2","work == result", work == result);
            TEST_CASE("3","�ǂݍ��ݖ������", !result.isLoaded());
        } END_CASE;

        BEGIN_CASE("4","operator ++(int)") {
            TestSuite::clearCheckpoints();

            TargetVariable<int> work(tvl);

            TargetVariable<int> result = (work++);

            TEST_CASE("1","work�̃A�h���X��0x104", work.getAddress() == 0x100 + sizeof(int));
            TEST_CASE("2","result�̃A�h���X��0x100", result.getAddress() == 0x100);
            TEST_CASE("3","�ǂݍ��݊������", result.isLoaded());
        } END_CASE;

        BEGIN_CASE("5","operator --") {
            TestSuite::clearCheckpoints();

            TargetVariable<int> work(tvl);

            TargetVariable<int> result = (-- work);

            TEST_CASE("1","work�̃A�h���X��0x9c", work.getAddress() == 0x100 - sizeof(int));
            TEST_CASE("2","work == result", work == result);
            TEST_CASE("3","�ǂݍ��ݖ������", !result.isLoaded());
        } END_CASE;

        BEGIN_CASE("6","operator --(int)") {
            TestSuite::clearCheckpoints();

            TargetVariable<int> work(tvl);

            TargetVariable<int> result = (work--);

            TEST_CASE("1","work�̃A�h���X��0x9c", work.getAddress() == 0x100 - sizeof(int));
            TEST_CASE("2","result�̃A�h���X��0x100", result.getAddress() == 0x100);
            TEST_CASE("3","�ǂݍ��݊������", result.isLoaded());
        } END_CASE;

        BEGIN_CASE("7","operator +=") {
            TestSuite::clearCheckpoints();

            TargetVariable<int> work(tvl);

            work += 0x10;

            TEST_CASE("1","work�̃A�h���X��0x140", work.getAddress() == 0x100 + sizeof(int) * 0x10);
            TEST_CASE("2","�ǂݍ��ݖ������", !work.isLoaded());
        } END_CASE;

        BEGIN_CASE("8","operator -=") {
            TestSuite::clearCheckpoints();

            TargetVariable<int> work(tvl);

            work -= 0x10;

            TEST_CASE("1","work�̃A�h���X��0xc0", work.getAddress() == 0x100 - sizeof(int) * 0x10);
            TEST_CASE("2","�ǂݍ��ݖ������", !work.isLoaded());
        } END_CASE;

        BEGIN_CASE("9", "operator &") {
            TEST_CASE("1","�A�h���X��������", &tv == 0x100);
            TEST_CASE("2","NULL�C���X�^���X�ɂ�0���Ԃ�", &(*((TargetVariable<int> *)0)) == 0);
        } END_CASE;

        BEGIN_CASE("10", "operator *") {
            TestSuite::clearCheckpoints();
            TargetVariable<int> work(0x100);

            const void * result = &(*work);

            TEST_CASE("1","loadContents�����s����Ă���", TestSuite::isReached("loadContents"));
            TEST_CASE("2","������������", fc.addr == 0x100);
            TEST_CASE("3","������������", fc.sz == sizeof(int));

            TestSuite::clearCheckpoints();
            *work;

            TEST_CASE("4","loadContents�͎��s����Ȃ�", !TestSuite::isReached("loadContents"));
        } END_CASE;

        BEGIN_CASE("11","operator ==/!=") {
            TEST_CASE("1","�A�h���X����v�����OK", tv == TTargetVariable(tv.getAddress()));
            TEST_CASE("2","NULL�C���X�^���X�Ƃ̔�r���ł���", tv != *((TTargetVariable *)0));
        } END_CASE;

        BEGIN_CASE("cvr","�J�o���b�W�΍�") {
            
            (*((TTargetVariable *)0)) ++;

        } END_CASE;

    } END_CASE;

    chain.restoreContext();
}


#endif

