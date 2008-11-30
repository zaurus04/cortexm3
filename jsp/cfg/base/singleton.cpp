/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2002-2003 by Embedded and Real-Time Systems Laboratory
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
 *  @(#) $Id: singleton.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/singleton.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/singleton.h"
#include "base/testsuite.h"

using namespace std;

    //Singleton �ÓI�ϐ�
bool SingletonBase::initialize = false;     //�������ς݃t���O
bool SingletonBase::is_valid   = true;      //�C���X�^���X���������t���O

struct SingletonBase::chain * SingletonBase::top  = 0;  //�f�X�g���N�^�`�F�[���̃g�b�v


/************************************* �e�X�g�X�B�[�g *************************************/

#ifdef TESTSUITE
#include "base/coverage_undefs.h"

    bool throw_DummyType;
    class DummyType {
    public:
        static int counter;
        int dummy_value;
        int order;
        SINGLETON_CONSTRUCTOR(DummyType) throw(bad_alloc) : dummy_value(0), order(++counter)
        {
            CHECKPOINT("DummyType::DummyType");
            if(throw_DummyType)
                throw bad_alloc();
        } 
        ~DummyType(void) throw(int)
        {
            CHECKPOINT("DummyType::~DummyType");
            if(throw_DummyType)
                throw 0;
            if(counter-- != order)
                CHECKPOINT("illegal order");
        }
    };

    SINGLETON_WRAPPER(DummyType2, DummyType)

    int DummyType::counter = 0;

    TESTSUITE(main, SingletonBase)
    {
        struct chain * old_top  = top;

        top  = 0;

        BEGIN_CASE("getInstance","getInstance") {
            BEGIN_CASE("1","�P��̃C���X�^���X�����������") {
                TestSuite::clearCheckpoints();
                DummyType * dummy = Singleton<DummyType>::getInstance();
                TEST_CASE("1","�R���X�g���N�^���N������Ă���", TestSuite::isReached("DummyType::DummyType"));

                TestSuite::clearCheckpoints();
                TEST_CASE("2","�C���X�^���X�����������", Singleton<DummyType>::getInstance() == dummy);
                TEST_CASE("3","2��ڈȍ~�̓R���X�g���N�^���N������Ȃ�", !TestSuite::isReached("DummyType::DummyType"));
                TEST_CASE("4","�V���O���g���̏��������I����Ă���", SingletonBase::initialize);
                TEST_CASE("5","�f�X�g���N�^�`�F�[�����\������Ă���", SingletonBase::top != 0);
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("final_release","final_release") {
            BEGIN_CASE("1","�C���X�^���X���폜�ł���") {
                TEST_CASE("0","[�O��] �폜���ׂ��v�f������", SingletonBase::top != 0);

                TestSuite::clearCheckpoints();
                SingletonBase::final_release();

                TEST_CASE("1","�f�X�g���N�^���N������Ă���", TestSuite::isReached("DummyType::~DummyType"));
                TEST_CASE("2","�f�X�g���N�^�`�F�[�����Ȃ��Ȃ��Ă���", SingletonBase::top == 0);
            } END_CASE;

            BEGIN_CASE("2","���Ԃ�������") {
                DummyType::counter = 0;

                DummyType  * dummy  = Singleton<DummyType>::getInstance();
                DummyType2 * dummy2 = Singleton<DummyType2>::getInstance();

                TEST_CASE("0","[�O��] ����������������", dummy->order == 1 && dummy2->order == 2);

                TestSuite::clearCheckpoints();
                SingletonBase::final_release();

                TEST_CASE("1","�f�X�g���N�^���N������Ă���", TestSuite::isReached("DummyType::~DummyType"));
                TEST_CASE("2","�f�X�g���N�^�`�F�[�����Ȃ��Ȃ��Ă���", SingletonBase::top == 0);
                TEST_CASE("3","�j��������������", !TestSuite::isReached("illegal order"));
            } END_CASE;

        } END_CASE;

        BEGIN_CASE("getInstance","getInstance") {
            BEGIN_CASE("1","�������ɗ�O") {
                BEGIN_CASE("1","getInstance()") {
                    throw_DummyType = true;
                    bool result = false;
                    try { Singleton<DummyType>::getInstance(); }
                    catch(...) { result = true; }

                    TEST_CASE("1","��O�͋N����",result);
                    TEST_CASE("2","�f�X�g���N�^�`�F�[���ɂ͉����Ȃ����Ă��Ȃ�", SingletonBase::top == 0);
                } END_CASE;

                SingletonBase::final_release();

                BEGIN_CASE("2","getInstance(nothrow)") {

                    DummyType * dummy;
                    throw_DummyType = true;
                    bool result = true;
                    try { dummy = Singleton<DummyType>::getInstance(nothrow); }
                    catch(...) { result = false; }

                    TEST_CASE("1","��O�͋N���Ȃ�",result);
                    TEST_CASE("2","NULL���Ԃ�", dummy == 0);
                    TEST_CASE("3","�f�X�g���N�^�`�F�[���ɂ͉����Ȃ����Ă��Ȃ�", SingletonBase::top == 0);
                } END_CASE;
            } END_CASE;
        } END_CASE;

        top  = old_top;
    }

#endif



