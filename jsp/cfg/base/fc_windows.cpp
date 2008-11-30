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
 *  @(#) $Id: fc_windows.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#if (defined(FILECONTAINER_WINDOWS) || defined(TESTSUITE)) && defined(_MSC_VER)

#pragma warning(disable:4786)

#include "base/filecontainer.h"
#include <windows.h>
#include <imagehlp.h>
#include <string>

using namespace std;

namespace {

    class FileContainerWindowsImpl : public FileContainer
    {
    protected:
        HANDLE          process;
        LOADED_IMAGE    image;
        DWORD           base;

        inline bool isLoaded(void) const
        {   return base != 0;   }

    public:
        FileContainerWindowsImpl(void) throw();
        virtual ~FileContainerWindowsImpl(void) throw();

            /* �C���^�t�F�[�X�� */
        virtual void        attachModule(const string & filename) throw(Exception);
        virtual void        loadContents(void * dest, address_t address, size_t size) throw(Exception);
        virtual address_t   getSymbolAddress(const string & symbol) throw(Exception);
        virtual std::string getArchitecture(void) throw();

        TESTSUITE_PROTOTYPE(main)
    };

    FileContainerWindowsImpl instance_of_FileContaienrWindowsImpl;

        /* �R���X�g���N�^ */
    FileContainerWindowsImpl::FileContainerWindowsImpl(void) throw()
        : process(NULL), image(), base(0)
    {}

        /* �f�X�g���N�^ */
    FileContainerWindowsImpl::~FileContainerWindowsImpl(void) throw()
    {
        if(isLoaded()) {
            ::UnMapAndLoad(&image);
            ::SymUnloadModule(process, base);
            process = NULL;
            base    = 0;
        }
    }

        /* �Ώۃ��W���[���̊��t */
    void FileContainerWindowsImpl::attachModule(const std::string & _filename) throw(Exception)
    {
        string filename(_filename);

        process = ::GetCurrentProcess();
        if(::SymInitialize( process , NULL, FALSE) == FALSE)
            ExceptionMessage("[Internal Error] ImageHelper API initialization failure","[�����G���[] �������Ɏ��s���܂��� (ImageHlp)").throwException();

        base = ::SymLoadModule(process, NULL, (PSTR)filename.c_str(), NULL, 0, 0);

        image.SizeOfImage = sizeof(LOADED_IMAGE);
        if(::MapAndLoad((PSTR)filename.c_str(), NULL, &image, FALSE, TRUE) == FALSE)
            ExceptionMessage("[Internel error] Module loading failure [%]","[�����G���[] ���W���[���̓ǂݍ��݂Ɏ��s���܂��� [%]") << filename << throwException;
    }

        /* ���e�̎擾 */
    void FileContainerWindowsImpl::loadContents(void * dest, address_t address, size_t size) throw(Exception)
    {
        PIMAGE_SECTION_HEADER header;
        unsigned int i;

        address -= base;
        for(i=0;i<image.NumberOfSections;i++) {
            header = image.Sections+i;
            if(address >= header->VirtualAddress && address < header->VirtualAddress + header->SizeOfRawData) {
                address -= header->VirtualAddress - header->PointerToRawData;
                ::CopyMemory(dest,image.MappedAddress + address,size);
                break;
            }
        }

        if(i == image.NumberOfSections)
            ExceptionMessage("[Internel error] Memory read with unmapped address","[�����G���[] �}�b�v����ĂȂ��A�h���X���g���ă��������[�h���s���܂���").throwException();
    }

        /* �V���{���A�h���X�̉��� */
    FileContainer::address_t FileContainerWindowsImpl::getSymbolAddress(const string & _symbol) throw(Exception)
    {
        FileContainer::address_t result = 0;
        string symbol(_symbol);
        IMAGEHLP_SYMBOL sym;

        if(process == NULL || base == 0)
            ExceptionMessage("Not initialized","����������Ă܂���").throwException();

        sym.SizeOfStruct = sizeof(sym);
        sym.MaxNameLength = 0;

        if(::SymGetSymFromName(process, (PSTR)symbol.c_str(), &sym) == TRUE)
            result = static_cast<FileContainer::address_t>(sym.Address);
     
        if(result == 0)
            ExceptionMessage("Unknown symbol [%]","�s���ȃV���{���� [%]") << symbol << throwException;

        return static_cast<FileContainer::address_t>(sym.Address);
    }

    string FileContainerWindowsImpl::getArchitecture(void) throw()
    {   return "Windows (Win32)";   }

}

//---------------------------------------------

#ifdef TESTSUITE
#include "base/coverage_undefs.h"

#pragma warning(disable:4311) //'reinterpret_cast' : �|�C���^�� 'const int *__w64 ' ���� 'FileContainer::address_t' �֐؂�l�߂܂��B

extern "C" const int FileContainerWindowsImplTestVariable = 0x01234567;
extern "C" const int _FileContainerWindowsImplTestVariableWithUnderbar = 0x89abcdef;

TESTSUITE(main, FileContainerWindowsImpl)
{
    PREDECESSOR("TFileContainer");

    SingletonBase::ContextChain chain;
    chain.saveContext<RuntimeObjectTable>();
    chain.renewInstance();

    BEGIN_CASE("attachModule","attachModule") {
        BEGIN_CASE("1","���s���Ă���v���O�������J���邩") {
            FileContainerWindowsImpl fcwi;
            bool result = true;
            try { fcwi.attachModule(TestSuite::getProgName()); } catch(...) { result = false; }
            
            TEST_CASE("1", "��O�͋N���Ȃ�", result);
        } END_CASE;

        BEGIN_CASE("2","���݂��Ȃ��t�@�C�����ŗ�O") {
            FileContainerWindowsImpl fcwi;
            bool result = false;
            try { fcwi.attachModule("..."); } catch(...) { result = true; }
            
            TEST_CASE("1", "��O���N����", result);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("getSymbolAddress","getSymbolAddress") {
        FileContainerWindowsImpl fcwi;

        BEGIN_CASE("1","���������Ă��Ȃ���ԂŌ�������") {
            bool result = false;
            try { fcwi.getSymbolAddress("FileContainerWindowsImplTestVariable"); } catch(...) { result = true; }
            TEST_CASE("1","��O��������", result);
        } END_CASE;

        fcwi.attachModule(TestSuite::getProgName());

        BEGIN_CASE("2","���݂���V���{������������") {
            FileContainer::address_t addr = 0;
            bool result = true;

            try { addr = fcwi.getSymbolAddress("FileContainerWindowsImplTestVariable"); } catch(...) { result = false; }

            TEST_CASE("1","��O�͋N���Ȃ�", result);
            TEST_CASE("2","�A�h���X��������", addr == reinterpret_cast<FileContainer::address_t>(&FileContainerWindowsImplTestVariable));
        } END_CASE;

        BEGIN_CASE("3","�]�v��_������ɕt�����Ȃ�") {
            FileContainer::address_t addr = 0;
            bool result = false;

            try { addr = fcwi.getSymbolAddress("FileContainerWindowsImplTestVariableWithUnderbar"); } catch(...) { result = true; }

            TEST_CASE("1","��O���N����", result);
            TEST_CASE("2","�A�h���X��0�̂܂�", addr == 0);
        } END_CASE;

        BEGIN_CASE("4","���݂��Ȃ��V���{������������") {
            FileContainer::address_t addr = 0;
            bool result = false;

            try { addr = fcwi.getSymbolAddress("____unknown____"); } catch(...) { result = true; }

            TEST_CASE("1","��O��������", result);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("loadContents","loadContents") {
        FileContainerWindowsImpl fcwi;
        fcwi.attachModule(TestSuite::getProgName());

        BEGIN_CASE("1","���݂���ϐ���ǂݏo��") {
            FileContainer::address_t addr;
            int i;

            addr = fcwi.getSymbolAddress("FileContainerWindowsImplTestVariable");
            bool result = true;
            try { fcwi.loadContents(&i, addr, sizeof(i)); } catch(...) { result = false; }

            TEST_CASE("1","��O�͋N���Ȃ�", result);
            TEST_CASE("2","�ǂݏo���ꂽ���e�͐�����", i == FileContainerWindowsImplTestVariable);
        } END_CASE;

        BEGIN_CASE("2","���݂��Ȃ��ϐ���ǂݏo��") {
            FileContainer::address_t addr;
            int i;

            addr = ~0;
            bool result = false;
            try { fcwi.loadContents(&i, addr, sizeof(i)); } catch(Exception &) { result = true; }

            TEST_CASE("1","��O���N����", result);
        } END_CASE;

    } END_CASE;

    chain.restoreContext();
}

#endif /* TESTSUITE */

#endif /* FILECONTAINER_WINDOWS || TESTSUITE */

