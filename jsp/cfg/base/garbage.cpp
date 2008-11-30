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
 *  @(#) $Id: garbage.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/garbage.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/garbage.h"

#include <stdexcept>
#include <algorithm>

using namespace std;

TrashBox * TrashBox::current_box = 0;

//----------------------------------------------------------------
// Garbage : �S�~

    //�R���X�g���N�^
Garbage::Garbage(void) throw()
{
        //�S�~���Ɋ֘A�t����
    assigned_box = TrashBox::getCurrentTrashBox();
    if(assigned_box->isValid())
        cookie = assigned_box->addGarbage(this);
}

    //�f�X�g���N�^
Garbage::~Garbage(void) throw()
{
    rescue();
}

    //�S�~�~�o
void Garbage::rescue(void) throw()
{
    if(assigned_box->isValid()) {
        assigned_box->recoverGarbage(cookie);
        assigned_box = 0;
    }
}


//----------------------------------------------------------------
// TrashBox : �S�~�����锠

TrashBox::TrashBox(void) throw()
{
        //�S�~���̍����ւ�
    previous_box = current_box;
    current_box  = this;
}

TrashBox::~TrashBox(void) throw()
{
        //�S�~���Ȃ��Ȃ�܂ō폜
    while(!garbage.empty()) {
            //�ӂ�
        try{   cleanup();   }
        catch(...) {}
    }

        //�S�~���̍����ւ�
    current_box = previous_box;
}

/*
    //�S�~���ɓ��ꂽ�S�~����菜��
void TrashBox::recoverGarbage(Garbage * _garbage, TrashBox::Cookie cookie) throw()
{
    if(isValid() && _garbage != 0) {
        bool forward = true;
        list<Garbage *>::iterator scope;

        if(!garbage.empty()) {
            scope = garbage.erase(cookie);

                //�������n������
            if(scope != garbage.end() || garbage.empty())
                forward = false;
        }

            //�e�S�~���ɉ�
        if(forward && previous_box->isValid())
            previous_box->recoverGarbage(_garbage, cookie);
    }
}
*/
    /*  �C�����̃��� 
              �֘A�t����ꂽ�S�~���������邱�Ƃ͖���(�������Ԃ̓S�~���̂ق��������͂�)�̂ŁA�e�ɉ񑗂���K�v�͖����B�����if(forward...�߂͕s�v�B
              �������n���ł��Ȃ��S�~�͖����̂�(cleanup��recoverGargabe���Ă΂Ȃ�)�Aerase�̕ԋp�l�̃`�F�b�N�͕s�v�B
              �ʍ폜�v���̓S�~����o�����̂ŁA���s���ꂽ���_�ŃS�~��1�ȏ㑶�݂���͂��Ȃ̂ŁAempty�`�F�b�N�͕s�v.
              ���̎��_��erase�����ɂȂ�A�������͕s�v�B
    */

    //�S�~���ɓ��ꂽ�S�~����菜��  
void TrashBox::recoverGarbage(TrashBox::Cookie cookie) throw()
{   garbage.erase(cookie);  }

    //�S�~������ɂ���
void TrashBox::cleanup(void)
{
        //�������g�b�v���x���S�~���łȂ������玸�s
    if(current_box != this)
        throw std::runtime_error("TrashBox::cleanup can be performed from the top level trash box only.");

    try {
        while(!garbage.empty())
            delete *garbage.begin();        //�S�~���X�g����v�f���O���͎̂q�̖��
    }
    catch(...) {
        garbage.erase(garbage.begin());     //��O���N�������ŏ��̗v�f���폜
        throw;                              //�đ�
    }
}



/****************************************** �e�X�g�X�B�[�g ******************************************/

#ifdef TESTSUITE
#include "coverage_undefs.h"

namespace { int counter = 0; }

#ifdef _MSC_VER
    class DummyGarbage : public Garbage
    {
    public:
        int * count;
        bool throw_exception;

        DummyGarbage(int * _count = 0) : count(_count), throw_exception(false)
        { TestSuite::check("DummyGarbage::DummyGarbage");  }

        ~DummyGarbage(void) throw(int)
        {
            if(count != 0) *count = ++counter;
            if(throw_exception) throw 0;
            TestSuite::check("DummyGarbage::~DummyGarbage"); 
        }

    };
#elif __GNUC__
    class DummyGarbage : public Garbage
    {
    public:
        int * count;

        DummyGarbage(int * _count = 0) : count(_count)
        { TestSuite::check("DummyGarbage::DummyGarbage");  }

        ~DummyGarbage(void) throw()
        {
            if(count != 0) *count = ++counter;
            TestSuite::check("DummyGarbage::~DummyGarbage"); 
        }
    };
#endif

TESTSUITE(main, TrashBox)
{
    BEGIN_CASE("1","�S�~�������Ɠo�^�����") {
        TrashBox mybox;
        TEST_CASE("1", "������S�~�������݂̃S�~���ɂȂ��Ă���", TrashBox::current_box == &mybox);
        
        {
            TrashBox mybox2;
            TEST_CASE("2", "������S�~�������݂̃S�~���ɂȂ��Ă��� (2)", TrashBox::current_box == &mybox2);
            TEST_CASE("3", "���Ƃ��Ƃ̃S�~�����ۑ�����Ă���", mybox2.previous_box == &mybox);
        }

        TEST_CASE("4", "���Ƃ̃S�~���ɖ߂�", TrashBox::current_box == &mybox);
    } END_CASE;

    BEGIN_CASE("2","isValid") {
        TrashBox mybox;

        TEST_CASE("1","������S�~���͐���", mybox.isValid());
        TEST_CASE("2","NULL���ُ͈�", !((TrashBox *)0)->isValid());
    } END_CASE;

    BEGIN_CASE("3","operator new") {
        BEGIN_CASE("1","new TrashBox��bad_alloc��O��Ԃ�") {
            bool result = false;

            try { TrashBox * box = new TrashBox; }
            catch(bad_alloc) { result = true; }

            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","new(nothrow) TrashBox��NULL��Ԃ�") {
            bool result = true;
            TrashBox * box;

            try { box = new(nothrow) TrashBox; }
            catch(...) { result = false; }

            TEST_CASE("1", "new(nothrow)�͗�O��Ԃ��Ȃ�", result);
            TEST_CASE("2", "new(nothrow)��NULL��Ԃ�",   box == 0);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("4","��{�I�Ȑ����폜") {
        BEGIN_CASE("1","�����ƃS�~������O����") {
            TrashBox mybox;

            DummyGarbage * garbage = new DummyGarbage;

            TEST_CASE("0","[�O��] �S�~�������Ă���", std::find(mybox.garbage.begin(), mybox.garbage.end(), garbage) != mybox.garbage.end());
            delete garbage;
            TEST_CASE("1","�S�~�������Ă���", std::find(mybox.garbage.begin(), mybox.garbage.end(), garbage) == mybox.garbage.end());


        } END_CASE;

        BEGIN_CASE("2","�e�̃S�~���ɓ����Ă�����̂��S�~������O����") {
            TrashBox mybox;
            DummyGarbage * garbage = new DummyGarbage;
            TEST_CASE("0","[�O��] �S�~�������Ă���", find(mybox.garbage.begin(), mybox.garbage.end(), garbage) != mybox.garbage.end());

            TrashBox secondbox;
            delete garbage;

            TEST_CASE("1","�S�~�������Ă���", find(mybox.garbage.begin(), mybox.garbage.end(), garbage) == mybox.garbage.end());
           
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("5","TrashBox::cleanup") {
        BEGIN_CASE("1","���I�ɍ�����I�u�W�F�N�g���j���ł���") {
            TrashBox mybox;
            DummyGarbage * garbage;

            TestSuite::clearCheckpoints();

            garbage = new DummyGarbage;
            TEST_CASE("0","[�O��] �R���X�g���N�^���N������Ă���", TestSuite::isReached("DummyGarbage::DummyGarbage"));

            mybox.cleanup();
            TEST_CASE("1","�f�X�g���N�^���N������Ă���", TestSuite::isReached("DummyGarbage::~DummyGarbage"));
        } END_CASE;

#ifdef _MSC_VER
        BEGIN_CASE("2","��O�͂����") {
            TrashBox mybox;
            DummyGarbage * garbage;

            TestSuite::clearCheckpoints();

            garbage = new DummyGarbage;
            garbage->throw_exception = true;

            bool result = false;
            try { mybox.cleanup(); }
            catch(...) { result = true; }

            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","��O���N�������I�u�W�F�N�g���j�󂳂�Ă��� (2�d�j���ɂȂ�Ȃ�)") {
            TrashBox mybox;
            DummyGarbage * garbage;
            DummyGarbage * garbage2;

            TestSuite::clearCheckpoints();

            garbage = new DummyGarbage;
            garbage->throw_exception = true;
            garbage2 = new DummyGarbage;
            garbage2->throw_exception = true;

            try { mybox.cleanup(); }
            catch(...) {}
            try { mybox.cleanup(); }    //������AccessViolation���N����Ȃ�
            catch(...) {}

            if(!mybox.garbage.empty())
                TEST_FAIL;
        } END_CASE;
#endif

        BEGIN_CASE("4","�폜�̏�����������") {
            TrashBox mybox;
            DummyGarbage * garbage;
            DummyGarbage * garbage2;
            DummyGarbage * garbage3;
            int g  = 0;
            int g2 = 0;
            int g3 = 0;

            TestSuite::clearCheckpoints();

            garbage  = new DummyGarbage(&g);
            garbage2 = new DummyGarbage(&g2);
            garbage3 = new DummyGarbage(&g3);

            mybox.cleanup();

            TEST_CASE("1","�ŏ��ɓo�^���ꂽ���͍̂Ō�ɍ폜",g == 3);
            TEST_CASE("2","���ɓo�^���ꂽ���̂�2�Ԗڂɍ폜",g2 == 2);
            TEST_CASE("3","���ɓo�^���ꂽ���͍̂ŏ��ɍ폜",g3 == 1);
        } END_CASE;

        BEGIN_CASE("5","�g�b�v���x���łȂ��S�~����cleanup�ł��Ȃ�") {
            TrashBox outerbox;
            TrashBox innerbox;

            bool result = false;
            try {   outerbox.cleanup();   }
            catch(std::runtime_error)
            {   result = true;   }

            if(!result)
                TEST_FAIL;
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("6","�f�X�g���N�^�ɂ��j��") {
        BEGIN_CASE("1","���I�ɍ�����I�u�W�F�N�g���j���ł��� (TrashBox::~TrashBox)") {
            {
                TrashBox mybox;
                DummyGarbage * garbage;

                TestSuite::clearCheckpoints();

                garbage = new DummyGarbage;
                TEST_CASE("0","[�O��] �R���X�g���N�^���N������Ă���", TestSuite::isReached("DummyGarbage::DummyGarbage"));
            }
            TEST_CASE("1","�f�X�g���N�^���N������Ă���", TestSuite::isReached("DummyGarbage::~DummyGarbage"));
        } END_CASE;

        BEGIN_CASE("2","��O�͂���Ȃ�") {
            bool result = true;
            try{
                TrashBox mybox;
                DummyGarbage * garbage;

                TestSuite::clearCheckpoints();

                garbage = new DummyGarbage;
                TEST_CASE("0","[�O��] �R���X�g���N�^���N������Ă���", TestSuite::isReached("DummyGarbage::DummyGarbage"));
            }
            catch(...)
            { result = false; }
            TEST_CASE("1","��O�͂���Ȃ�", result);
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("7","rescue") {
        DummyGarbage * garbage;
        {
            TrashBox mybox;
            garbage = new DummyGarbage;
            garbage->rescue();

            TestSuite::clearCheckpoints();
        }
        TEST_CASE("1","rescue�����S�~�͍폜����Ȃ�", !TestSuite::isReached("DummyGarbage::~DummyGarbage"));
        delete garbage;
    } END_CASE;

    BEGIN_CASE("8","�ÓI�ȃI�u�W�F�N�g�����d�j������Ȃ�") {
        TrashBox outerbox;
        {
            DummyGarbage garbage;
            TrashBox innerbox;
            DummyGarbage garbage2;

            TEST_CASE("0","[�O��] �R���X�g���N�^���N������Ă���", TestSuite::isReached("DummyGarbage::DummyGarbage"));
        }   //������2�d�j����MACV�ɂȂ�Ȃ�
    } END_CASE;
}

#endif



