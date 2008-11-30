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
 *  @(#) $Id: event.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/event.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/event.h"

using namespace std;

/***************************** �e�X�g�X�B�[�g *****************************/

#ifdef TESTSUITE
#include "base/coverage_undefs.h"

namespace {
    class Event_fortest : public Event<int> 
    {   TESTSUITE_PROTOTYPE(main)   };

    int * ptr_i_dummy_handler;
    void dummy_handler(int & i)
    {
        ptr_i_dummy_handler = &i;
        ++ i;
        TestSuite::check("dummy_handler");
    }

    class EventHandler : public Event_fortest::Handler
    {
    public:
        int * ptr_i;

        EventHandler(void)  throw() { TestSuite::check("EventHandler::EventHandler");  }
        ~EventHandler(void) throw() { TestSuite::check("EventHandler::~EventHandler"); }
        void handler(Event_fortest::value_type & i) { ptr_i = &i; ++i; TestSuite::check("EventHandler::handler"); }
    };
}

TESTSUITE(main,Event_fortest)
{
    BEGIN_CASE("add","add") {
        BEGIN_CASE("1","add�Ńn���h�����o�^�ł���") {
            Singleton<Event_fortest::handler_list_type>::renewInstance();

            Event_fortest::add(dummy_handler);

            TEST_CASE("1","�n���h�����X�g��1�����Ă���", Singleton<Event_fortest::handler_list_type>::getInstance()->size() == 1);
            TEST_CASE("2","�n���h�����X�g�̒��g�͐�����", *Singleton<Event_fortest::handler_list_type>::getInstance()->begin() == dummy_handler);
        } END_CASE;

        BEGIN_CASE("2","�����n���h���𕡐���o�^�ł���") {
            Singleton<Event_fortest::handler_list_type>::renewInstance();

            Event_fortest::add(dummy_handler);
            Event_fortest::add(dummy_handler);
            Event_fortest::add(dummy_handler);

            TEST_CASE("1","�n���h�����X�g�̒��g��3", Singleton<Event_fortest::handler_list_type>::getInstance()->size() == 3);
            TEST_CASE("2","�n���h�����X�g�̒��g�͐�����", *Singleton<Event_fortest::handler_list_type>::getInstance()->begin() == dummy_handler);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("remove","remove") {
        BEGIN_CASE("1","add�œo�^�����n���h�����폜�ł���") {
            Singleton<Event_fortest::handler_list_type>::renewInstance();

            Event_fortest::add(dummy_handler);
            Event_fortest::remove(dummy_handler);

            TEST_CASE("1","�n���h�����X�g�̗v�f����0", Singleton<Event_fortest::handler_list_type>::getInstance()->size() == 0);
        } END_CASE;

        BEGIN_CASE("2","�o�^�����S�Ẵn���h����������") {
            Singleton<Event_fortest::handler_list_type>::renewInstance();

            Event_fortest::add(dummy_handler);
            Event_fortest::add(dummy_handler);
            Event_fortest::add(dummy_handler);
            Event_fortest::remove(dummy_handler);

            TEST_CASE("1","�n���h�����X�g�̗v�f����0", Singleton<Event_fortest::handler_list_type>::getInstance()->size() == 0);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("constructor/destructor","constructor/destructor") {
        Singleton<Event_fortest::Handler::instance_list_type>::renewInstance();

        TEST_CASE("0","[�O��] �n���h�����X�g�̒��g��0", Singleton<Event_fortest::Handler::instance_list_type>::getInstance()->size() == 0);
        {
            EventHandler evhdr;
            TEST_CASE("1","�n���h�����X�g�ɓo�^����Ă���", Singleton<Event_fortest::Handler::instance_list_type>::getInstance()->size() == 1);
            TEST_CASE("2","�������o�^����Ă���", *Singleton<Event_fortest::Handler::instance_list_type>::getInstance()->begin() == &evhdr);
        }
        TEST_CASE("3","�n���h���͉�������Ă���", Singleton<Event_fortest::Handler::instance_list_type>::getInstance()->size() == 0);
    } END_CASE;

    BEGIN_CASE("raise","raise") {
        BEGIN_CASE("1","�o�^�����ÓI�ȃn���h�������s�����") {
            Singleton<Event_fortest::handler_list_type>::renewInstance();
            TestSuite::clearCheckpoints();

            Event_fortest::add(dummy_handler);

            int i = 0;
            Event_fortest::raise(i);

            TEST_CASE("1","�n���h�������s�����",TestSuite::isReached("dummy_handler"));
            TEST_CASE("2","�����ԂŌ��Ă���ϐ��͓���", &i == ptr_i_dummy_handler);
            TEST_CASE("3","�l���C���N�������g����Ă���", i == 1);
        } END_CASE;

        BEGIN_CASE("2","�o�^�����C���X�^���X�̃n���h�������s�����") {
            Singleton<Event_fortest::handler_list_type>::renewInstance();
            TestSuite::clearCheckpoints();
            EventHandler evhdr;

            int i = 0;
            Event_fortest::raise(i);

            TEST_CASE("1","�n���h�������s�����",TestSuite::isReached("EventHandler::handler"));
            TEST_CASE("2","�����ԂŌ��Ă���ϐ��͓���", &i == evhdr.ptr_i);
            TEST_CASE("3","�l���C���N�������g����Ă���", i == 1);
        } END_CASE;

        BEGIN_CASE("3","�������� (���Ԃ͓��ɋC�ɂ��Ȃ�)") {
            Singleton<Event_fortest::handler_list_type>::renewInstance();
            TestSuite::clearCheckpoints();
            EventHandler evhdr;

            Event_fortest::add(dummy_handler);

            int i = 0;
            Event_fortest::raise(i);

            TEST_CASE("1","�n���h�������s�����",TestSuite::isReached("dummy_handler"));
            TEST_CASE("2","�n���h�������s�����",TestSuite::isReached("EventHandler::handler"));
            TEST_CASE("3","�l���C���N�������g����Ă���", i == 2);
        } END_CASE;

        BEGIN_CASE("4","�����o�^") {
            Singleton<Event_fortest::handler_list_type>::renewInstance();
            TestSuite::clearCheckpoints();
            EventHandler evhdr;
            EventHandler evhdr2;

            Event_fortest::add(dummy_handler);
            Event_fortest::add(dummy_handler);

            int i = 0;
            Event_fortest::raise(i);

            TEST_CASE("1","�n���h�������s�����",TestSuite::isReached("dummy_handler"));
            TEST_CASE("2","�n���h�������s�����",TestSuite::isReached("EventHandler::handler"));
            TEST_CASE("3","�l���C���N�������g����Ă���", i == 4);
        } END_CASE;
    } END_CASE;
}


#endif



