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
 *  @(#) $Id: jsp_common.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

#include "jsp/jsp_common.h"

#include "base/option.h"

#include <ctime>

#if defined(_MSC_VER) || defined(__BORLANDC__)
#  define  GETLOGINNAME_WINDOWS
#  include <windows.h>
#elif __GNUC__
#  define  GETLOGINNAME_UNIX
#  include <unistd.h>
#endif

using namespace std;

#if 0
namespace {
    string get_loginname(void) throw()
    {
        string result("TOPPERS/JSP KernelConfigurator");

#ifdef GETLOGINNAME_WINDOWS
        char  buffer[1024];
        DWORD sz = 1024;
        ::GetUserName(buffer, &sz);
        result.assign(buffer);
#elif defined(GETLOGINNAME_UNIX)
        result.assign(getlogin());
#endif

        return result;
    }
}
#endif


    //�C���N���[�h�t�@�C���̌`��ύX����
string ToppersJsp::conv_includefile(string file) throw()
{
    OptionParameter & option = getOptionParameter();
    string result;

        //il�I�v�V�������t�����Ƃ��ɂ� "<...>" �`���ŏo��
    if(option["il"].isValid())
        result = string("<") + file + ">";
    else
        result = string("\"") + file + "\"";

    return result;
}

    //�J�[�l���̕ϐ����̌`��ύX����
string ToppersJsp::conv_kernelobject(string obj) throw()
{
    OptionParameter & option = getOptionParameter();
    string result;

    result = obj;

        // TOPPERS/JSP rel 1.3����̓J�[�l���ϐ��̓��� _kernel_ ������
    if(!option["1.3"].isValid())
        result = string("_kernel_") + obj;

    return result;
}

ToppersJsp::SpecialtyFile::SpecialtyFile(void) throw() : MultipartStream(), RuntimeObject(true)
{}

#if 0
string ToppersJsp::get_agreement(string filename) throw()
{
    const char * base_agreement =
        "/*\n"
        " *  TOPPERS/JSP Kernel\n"
        " *      Toyohashi Open Platform for Embedded Real-Time Systems/\n"
        " *      Just Standard Profile Kernel\n"
        " * \n"
        " *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory\n"
        " *                              Toyohashi Univ. of Technology, JAPAN\n"
        " * \n"
        " *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation \n"
        " *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL\n"
        " *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A\n"
        " *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C\n"
        " *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D\n"
        " *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���\n"
        " *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[\n"
        " *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD\n"
        " *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg\n"
        " *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p\n"
        " *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L\n"
        " *      �̖��ۏ؋K����f�ڂ��邱�ƁD\n"
        " *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg\n"
        " *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����\n"
        " *      �ƁD\n"
        " *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�\n"
        " *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD\n"
        " *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��\n"
        " *        �񍐂��邱�ƁD\n"
        " *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹\n"
        " *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD\n"
        " * \n"
        " *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�\n"
        " *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����\n"
        " *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼\n"
        " *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D\n"
        " * \n";

    string work(base_agreement);

        //CVS��ID���̂��̂���������
    time_t t;
    time(&t);

    work += string(" * @(#)$Id: ");
    work += filename;
    work += " ";
    work += static_cast<const char *>(asctime(localtime(&t)));
    
    work.erase(work.size() - 1);    //asctime�ŉ��s������̂�chomp

    work += " ";
    work += get_loginname();
    work += " Exp $\n */\n\n";

    return work;
}
#endif


/***************************************** �e�X�g�X�B�[�g *****************************************/

#ifdef TESTSUITE

class SpecialtyFile_test : public ToppersJsp::SpecialtyFile
{
public:
    ~SpecialtyFile_test(void) throw() { TestSuite::check("SpecialtyFile::~SpecialtyFile"); }
    TESTSUITE_PROTOTYPE(main)
};

TESTSUITE(main, SpecialtyFile_test)
{
    BEGIN_CASE("constructor","constructor") {
        BEGIN_CASE("1","���������ROT�ɏ��") {
            SpecialtyFile_test file;

            if(RuntimeObjectTable::getInstance<SpecialtyFile_test>() == 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�j���̑ΏۂɂȂ��Ă���") {
            Singleton<RuntimeObjectTable>::Context context;
            Singleton<RuntimeObjectTable>::saveContext(context);

            Singleton<RuntimeObjectTable>::renewInstance();

            new SpecialtyFile_test;

            TEST_CASE("0","[�O��] �o�^����Ă���", RuntimeObjectTable::getInstance<SpecialtyFile_test>() != 0);
            
            TestSuite::clearCheckpoints();
            Singleton<RuntimeObjectTable>::renewInstance(); //�C���X�^���X�̍Đ�����ROT���폜�����

            TEST_CASE("1","ROT�����������Ă���", RuntimeObjectTable::getInstance<SpecialtyFile_test>() == 0);
            TEST_CASE("2","�f�X�g���N�^���N������Ă���", TestSuite::isReached("SpecialtyFile::~SpecialtyFile"));

            Singleton<RuntimeObjectTable>::restoreContext(context);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("createInstance","createInstance") {
        BEGIN_CASE("1","�C���X�^���X�������ł���") {
            SpecialtyFile_test * file = SpecialtyFile::createInstance<SpecialtyFile_test>("test.txt");

            file->disableOutput();  //�o�͂���Ă�����̂�

            TEST_CASE("1","��NULL���Ԃ�", file != 0);
            TEST_CASE("2","�t�@�C����������",  file->getFilename().compare("test.txt") == 0);
        } END_CASE;

        BEGIN_CASE("2","�󕶎���n���Ɨ�O") {

            bool result = false;
            try {
                SpecialtyFile::createInstance<SpecialtyFile_test>("");
            }
            catch(Exception &) {
                result = true;
            }

            TEST_CASE("1","��O���N����", result);
            TEST_CASE("2","�I�u�W�F�N�g�͂Ȃ�", RuntimeObjectTable::getInstance<SpecialtyFile_test>() == 0);
        } END_CASE;
    } END_CASE;
}

namespace {
    extern void testsuite(TestSuiteControl & _suite_control);
    TestSuite testsuite_onTop("TOPPERS/JSP Common Function(main)", testsuite);

            //�e�X�g�X�B�[�g�̖{��
    void testsuite(TestSuiteControl & _suite_control)
    {
        Singleton<OptionParameter>::Context context;
        Singleton<OptionParameter>::saveContext(context);

        BEGIN_CASE("conv_includefile","conv_includefile") {
            BEGIN_CASE("1","-il���t���Ă��Ȃ��ƃ_�u���N�H�[�g�ł�����") {
                Singleton<OptionParameter>::renewInstance();

                if(ToppersJsp::conv_includefile("test.h").compare("\"test.h\"") != 0)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("1","-il���t���Ă����<>�ł�����") {
                Singleton<OptionParameter>::renewInstance();
                char * argv[] = {"test.exe","-il"};
                getOptionParameter().parseOption(2, argv);

                if(ToppersJsp::conv_includefile("test.h").compare("<test.h>") != 0)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("conv_kernelobject","conv_kernelobject") {
            BEGIN_CASE("1","-1.3���t���Ă��Ȃ���_kernel_���t��") {
                Singleton<OptionParameter>::renewInstance();

                if(ToppersJsp::conv_kernelobject("test").compare("_kernel_test") != 0)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("1","-1.3���t���Ă���Ƃ��̂܂܏o�Ă���") {
                Singleton<OptionParameter>::renewInstance();
                char * argv[] = {"test.exe","-1.3"};
                getOptionParameter().parseOption(2, argv);

                if(ToppersJsp::conv_kernelobject("test").compare("test") != 0)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        Singleton<OptionParameter>::restoreContext(context);

    }
}
#endif


