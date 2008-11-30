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
 *  @(#) $Id: manager.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/manager.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifdef _MSC_VER
#  pragma warning(disable:4786)
#  define CDECL __cdecl
#else
#  define CDECL
#endif

#include <stdlib.h>
#include <fstream>
#include <iostream>

#include "base/event.h"
#include "base/message.h"
#include "base/component.h"
#include "base/directorymap.h"

using namespace std;

Event<StartupEvent>   startupEvent;
Event<ShutdownEvent>  shutdownEvent;

int CDECL main(int argc, char ** argv)
{
    ShutdownEvent evt;
    OptionParameter & option= getOptionParameter();

    evt.exit_code = EXIT_FAILURE;

    if(SingletonBase::isValid() && Component::isValid()) {

        option.parseOption(argc, argv, "-h");

        try {
            startupEvent.raise();
            Component::executeComponents(option);
            evt.exit_code = EXIT_SUCCESS;
        }
        catch(Exception & e)
        {
            cerr << Message("Program failed in its process by following reason.\n","�v���O�����͒v���I�ȃG���[�ɂ�蒆�f����܂���.\n");
            cerr << "  " << e.getDetails() << '\n';
        }
        catch(ExceptionMessage & e) {
            CHECKPOINT("catch(ExceptionMessage)");
            cerr << "Program failed : " << e << '\n';
        }
        catch(bad_alloc & e) {
            CHECKPOINT("catch(bad_alloc)");
            cerr << "Program failed : bad_alloc (" << e.what() << ")\n";
        }
        catch(...) {
            CHECKPOINT("catch(...)");
            cerr << "Program filed : Unknown Exception Occured\n";
        }
    }
    else
        cerr << "Program initialization failure\n";

    try {
        DebugMessage("shutdown event - exitcode(%)\n") << evt.exit_code;
        shutdownEvent.raise(evt);
    }
    catch(Exception & e)
    {
        DebugMessage("exception was raised in the event - %\n") << e.getDetails();
        cerr << Message("Program failed in its process by following reason.\n","�v���O�����͒v���I�ȃG���[�ɂ�蒆�f����܂���.\n");
        cerr << "  " << e.getDetails() << '\n';
    }

    catch(...) {
        DebugMessage("exception was raised in the event\n");
        CHECKPOINT("catch(...) in shutdownEvent::raise");
        evt.exit_code = EXIT_FAILURE;
    }

    DebugMessage("Exit code (%)\n") << evt.exit_code;

    return evt.exit_code;
}

/************************************* �e�X�g�X�B�[�g *************************************/

#ifdef TESTSUITE
#include "coverage_undefs.h"

namespace {

    extern void testsuite(TestSuiteControl & _suite_control);
    TestSuite testsuite_onTop("Entrypoint(main)", testsuite);

    class TestComponent : public Component
    {
    public:
        int mode;

        void parseOption(OptionParameter &)
        {
            switch(mode) {
                case 0:
                    CHECKPOINT("TestComponent::case 0");
                    break;
                case 1:
                    ExceptionMessage("exception").throwException();
                case 2:
                    throw bad_alloc();
            }
        }
    };

    void dummyStartupHandler(StartupEvent &)
    {
        TestSuite::check("dummyStartupHandler");
    }

    int dummyShutdownHandler_exit_code;
    void dummyShutdownHandler(ShutdownEvent & evt)
    {
        dummyShutdownHandler_exit_code = evt.exit_code;
        TestSuite::check("dummyShutdownHandler");
    }

        //�e�X�g�X�B�[�g�̖{��
    void testsuite(TestSuiteControl & _suite_control)
    {
        SingletonBase::ContextChain chain;

        chain.saveContext<Component::ComponentInfo>();
        chain.saveContext<Event<StartupEvent>::handler_list_type>();
        chain.saveContext<Event<ShutdownEvent>::handler_list_type>();

        BEGIN_CASE("1","main�֐��P�� + �R���|�[�l���g�Ȃ�") {
            chain.renewInstance();

            Event<StartupEvent>::add(dummyStartupHandler);
            Event<ShutdownEvent>::add(dummyShutdownHandler);

            BEGIN_CASE("1","���ʂɎ��s����") {
                TestSuite::clearCheckpoints();

                char * argv[] = { "test.exe" };

                Exception::setThrowControl(true);
                TestComponent test;
                test.mode = 0;

                TEST_CASE("1","main�֐���EXIT_SUCCESS��Ԃ�", main(1, argv) == EXIT_SUCCESS);

                TEST_CASE("2","��O�����s����Ȃ� catch(Exception)", !TestSuite::isReached("catch(Exception)"));
                TEST_CASE("3","��O�����s����Ȃ� catch(bad_alloc)", !TestSuite::isReached("catch(bad_alloc)"));
                TEST_CASE("4","��O�����s����Ȃ� catch(...)",       !TestSuite::isReached("catch(...)"));
                TEST_CASE("5","Component�����s����Ă���", TestSuite::isReached("TestComponent::case 0"));
                TEST_CASE("6","�X�^�[�g�A�b�v�n���h�����N������Ă���", TestSuite::isReached("dummyStartupHandler"));
                TEST_CASE("7","�V���b�g�_�E���n���h�����N������Ă���", TestSuite::isReached("dummyShutdownHandler"));
                TEST_CASE("8","�V���b�g�_�E���n���h����EXIT_SUCCESS���󂯂Ă���", dummyShutdownHandler_exit_code == EXIT_SUCCESS);
            } END_CASE;

            BEGIN_CASE("2","Exception��O��Ԃ�") {
                TestSuite::clearCheckpoints();

                char * argv[] = { "test.exe" };

                Exception::setThrowControl(true);
                TestComponent test;
                test.mode = 1;

                TEST_CASE("1","main�֐���EXIT_FAILURE��Ԃ�", main(1, argv) == EXIT_FAILURE);

                TEST_CASE("2","��O�����s�����   catch(Exception)", TestSuite::isReached("catch(Exception)"));
                TEST_CASE("3","��O�����s����Ȃ� catch(bad_alloc)", !TestSuite::isReached("catch(bad_alloc)"));
                TEST_CASE("4","��O�����s����Ȃ� catch(...)",       !TestSuite::isReached("catch(...)"));
                TEST_CASE("5","�X�^�[�g�A�b�v�n���h�����N������Ă���", TestSuite::isReached("dummyStartupHandler"));
                TEST_CASE("6","�V���b�g�_�E���n���h�����N������Ă���", TestSuite::isReached("dummyShutdownHandler"));
                TEST_CASE("7","�V���b�g�_�E���n���h����EXIT_FAILURE���󂯂Ă���", dummyShutdownHandler_exit_code == EXIT_FAILURE);
            } END_CASE;

            BEGIN_CASE("3","bad_alloc��O��Ԃ�") {
                TestSuite::clearCheckpoints();

                char * argv[] = { "test.exe" };

                Exception::setThrowControl(true);
                TestComponent test;
                test.mode = 2;

                TEST_CASE("1","main�֐���EXIT_FAILURE��Ԃ�", main(1, argv) == EXIT_FAILURE);

                TEST_CASE("2","�Ή�����catch�݂̂����s����Ă���", !TestSuite::isReached("catch(Exception)") && TestSuite::isReached("catch(bad_alloc)") && !TestSuite::isReached("catch(...)"));
                TEST_CASE("3","�X�^�[�g�A�b�v�n���h�����N������Ă���", TestSuite::isReached("dummyStartupHandler"));
                TEST_CASE("4","�V���b�g�_�E���n���h�����N������Ă���", TestSuite::isReached("dummyShutdownHandler"));
                TEST_CASE("5","�V���b�g�_�E���n���h����EXIT_FAILURE���󂯂Ă���", dummyShutdownHandler_exit_code == EXIT_FAILURE);
            } END_CASE;
        } END_CASE;

        chain.restoreContext();
    }

}

#endif


