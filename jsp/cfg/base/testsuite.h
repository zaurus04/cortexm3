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
 *  @(#) $Id: testsuite.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *   �e�X�g�X�B�[�g���s�⏕ �N���X/�}�N�����C�u����
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/testsuite.h,v 1.1 2008/06/17 00:04:36 suikan Exp $


#ifdef TESTSUITE

    //�V�i���I�I�[�}�N��(Exception�N���X�̗L���ɂ���Ē��g��ւ������̂ł����ɂ���)
#  undef END_CASE
#  ifdef EXCEPT_H
#    define END_CASE }catch(TestSuite::Fail & x) { _suite_control.fail_in_suite(x.getMessage()); } catch(Exception & exc) { _suite_control.fail_in_suite(string("�s���ȗ�O : ") + exc.getDetails()); } catch(...) { _suite_control.fail_in_suite("�e�X�g���s���ɕs���ȗ�O���󂯎�������ߒ��f���ꂽ"); } _suite_control.leave_case(); }
#  else
#    define END_CASE }catch(TestSuite::Fail & x) { _suite_control.fail_in_suite(x.getMessage()); } catch(...) { _suite_control.fail_in_suite("�e�X�g���s���ɕs���ȗ�O���󂯎�������ߒ��f���ꂽ"); } _suite_control.leave_case(); }
#  endif

#endif


#ifndef TESTSUITE_H
#define TESTSUITE_H

    //�e�X�g�X�B�[�g�������邩�ǂ���
//#define TESTSUITE


#if defined(TESTSUITE) //&& defined(_DEBUG)

    //�X�g���[���̓��e���e�X�g�Ŏg�������̂œ���ւ���
#include <iostream>
#define cin  _cin
#define cout _cout
#define cerr _cerr

#include <sstream>

namespace std {
    extern stringstream _cin;
    extern stringstream _cout;
    extern stringstream _cerr;
}

#include <string>
#include <list>
#include <set>
#include <map>


    //�W���̃e�X�g�X�B�[�g�֐��̃v���g�^�C�v�錾�p�}�N��
#define TESTSUITE_PROTOTYPE(suite) \
    public: \
        static void test_suite_##suite(TestSuiteControl & _suite_control);


    //�W���̃e�X�g�X�B�[�g�֐��̒�`�p�}�N�� (�킴�ƃX�B�[�g���s�̏����R���p�C���p�̒�`���Ɠ������O�ɂ���)
#undef TESTSUITE
#define TESTSUITE(suite,cls) \
    TestSuite TestSuite_##cls##_##suite(#cls "(" #suite ")", cls::test_suite_##suite); \
    void cls::test_suite_##suite(TestSuiteControl & _suite_control)

#define TESTSUITE_(suite,cls,spr) \
    TestSuite TestSuite_##spr##_##cls##_##suite(#spr "::" #cls "(" #suite ")", spr::cls::test_suite_##suite); \
    void spr::cls::test_suite_##suite(TestSuiteControl & _suite_control)

    //���d���s�h�~�p�}�N��
#define PROCEED_ONCE static bool _proceed_once_flag_ = false; if(_proceed_once_flag_) return; else _proceed_once_flag_ = true;

    //�V�i���I�J�n�}�N��
#define BEGIN_CASE(x,y) if(_suite_control.enter_case(x,y,__FILE__,__LINE__)) { try {

    //�V�i���I���s�}�N��
#define TEST_FAIL     throw TestSuite::Fail();
#define TEST_FAIL_(x) throw TestSuite::Fail(x);

    //�Z���V�i���I�p�}�N��
#define TEST_CASE(x,y,z)   BEGIN_CASE(x,y) { if(!(z)) TEST_FAIL;    } END_CASE
#define TEST_CASE_(x,y,z,u) BEGIN_CASE(x,y) { if(!(z)) TEST_FAIL_(u); } END_CASE

    //���B����}�N��
#define CHECKPOINT(x) TestSuite::check(x);

    //�V���O���g���ޔ�
#define SINGLETON(x)    Singleton<x>::Context context;     Singleton<x>::saveContext(context);
#define SINGLETON_(x,y) Singleton<x>::Context context_##y; Singleton<x>::saveContext(context_##y);

/*
 *  �e�X�g�X�B�[�g�̎��s����N���X
 */
class TestSuiteControl {
protected:
    std::list<std::string> session;         //���݂̃Z�b�V�������X�^�b�N

    std::string    target_session;          //�����ΏۃZ�b�V������
    std::string    current_session;         //���݂̃X�B�[�g�V�i���I��
    std::string    current_description;     //���݂̃X�B�[�g�V�i���I�̐���
    std::ostream * out;                     //�����̏o�͐�
    bool           fail;                    //���s�����V�i���I�����������ǂ���
    bool           verbose;                 //�璷�o�͂��邩�ۂ�

    unsigned int   case_count;              //�P�[�X�̑���
    unsigned int   fail_count;              //���s�����P�[�X�̐�

        //�V�i���I���̎擾
    std::string get_suitename(const char * name = "") const;


public:
        //�R���X�g���N�^
    TestSuiteControl(std::ostream & _out, const char * _pattern = "");

        //�e�X�g�V�i���I�̕\��ݒ� (�ԋp�l : ���s����K�v�����邩�ǂ���)
    bool        _enter_case(const char * session, const char * description, const char * filename = "", long lineno = -1);
    inline void leave_case(void) { leave_session(); }

        //�V���O���X�e�b�v���s���ɒ��ɔ�э��܂Ȃ����߂̃��b�p
    inline bool enter_case(const char * session, const char * description, const char * filename = "", long lineno = -1)
    {   return _enter_case(session, description, filename, lineno);   }

        //�e�X�g�Z�b�V������ (�V�i���I�v���t�B�N�X) �̐ݒ�/����
    void enter_session(const std::string & session);
    void leave_session(void);

        //�e�X�g�V�i���I�̎��s��
    void fail_in_suite(std::string msg="");                                           

        //���s�����V�i���I�̗L���̊m�F
    inline bool is_failed(void) const
    {   return fail;   }

        //�璷�o�͂̐ݒ�
    inline void set_verbose(bool _verbose = true)
    {   verbose = _verbose;   }

        //���s�����e�X�g�P�[�X�̐�
    inline unsigned int countCases(void) const
    {   return case_count;   }

        //���s�����e�X�g�P�[�X�̐�
    inline unsigned int countFails(void) const
    {   return fail_count;   }
};

    //�V���O���g���̃e�X�g�X�B�[�g�̂��߂ɂ����ŃC���N���[�h
#include "base/singleton.h"

/*
 *  �e�X�g�X�B�[�g���s�N���X
 */
class TestSuite {
public:
    class Fail  //�e�X�g�P�[�X���s�ʒm�ɗp�����O�p�N���X
    {
    protected:
        std::string msg;

    public:
            //�R���X�g���N�^
        Fail(std::string src = "") throw() : msg(src) {}

            //�R�s�[�R���X�g���N�^
        Fail(const Fail & src) throw() : msg(src.msg) {}
        
            //���b�Z�[�W���擾
        inline const std::string & getMessage(void) const throw()
        {   return msg;   }
    };

    typedef void (*SuiteFunction)(TestSuiteControl &);

        /* �N���X���̃e�X�g�X�B�[�g�Ɋւ������ێ�����N���X */
    class SuiteContainerNode
    {
    protected:
        std::string   session;
        SuiteFunction suite;
    
    public:
            //�X�B�[�g���R���X�g���N�^
        SuiteContainerNode(const char * session, SuiteFunction suite);
        SuiteContainerNode(const SuiteContainerNode & src);

            //�X�B�[�g�̎��s
        bool invoke(TestSuiteControl & suite_control);

            //�X�B�[�g���̎擾
        inline const std::string & getName(void) const throw()
        {   return session;   }
    };

        //���s���ׂ��e�X�g�X�B�[�g�����C���X�^���X�̃��X�g�̌^
    class SuiteContainer : public std::list<SuiteContainerNode>
    {   public: SINGLETON_CONSTRUCTOR(SuiteContainer) {}   };

        /* ���s�I�v�V���� */
    enum tagPerformOption {
        THROUGH = 1,    //���ׂĒʂ��Ŏ��s���� (���������~�߂Ȃ�)
        VERBOSE = 2,    //�璷�o��

        DEFAULT = THROUGH
    };

        /* �`�F�b�N�|�C���g���i�[����N���X */
    class Checkpoint : public std::set<std::string>
    { public: SINGLETON_CONSTRUCTOR(Checkpoint) throw() {} };

protected:
    bool            fail;       //�Ō�Ɏ��s�����X�B�[�g�����s�������ǂ�����ێ�����ϐ�
    static bool     starvated;  //new�Ɏ��s���邩�ǂ���

public:
        //�R���X�g���N�^
    TestSuite(const char * session, SuiteFunction suite);

        //�f�X�g���N�^
    ~TestSuite(void);

        //�e�X�g�X�B�[�g�̎��s  (�ԋp�l:�X�B�[�g�����������s���ꂽ���ǂ���)
    static bool performTestSuite(int flags = THROUGH, const char * pattern = "");

        //�e�X�g�X�B�[�g�̎��s (�����ϊ�)
    inline static bool performTestSuite(const char * pattern)
    {   return performTestSuite(THROUGH, pattern);   }

        //�o�^����Ă���g�b�v���x���X�B�[�g�̈ꗗ�\��
    static void listTestSuite(void);

        /*
         *   �`�F�b�N�|�C���g�p�֐�
         */

        //�ʉ߂������Ƃ��
    inline static void check(std::string checkname)
    {   Singleton<Checkpoint>::getInstance()->insert(checkname);   }

        //����܂łɎ󂯂��񍐂��폜
    inline static void clearCheckpoints(void)
    {   Singleton<Checkpoint>::getInstance()->clear();   }

        //���̈ʒu�ɗ�����
    static bool isReached(std::string checkname);

        /*
         *   �e�X�g�p��Ɗ֐�
         */

        //�t�@�C���̒��g���J���ă`�F�b�N����
    static bool compareFileContents(const char * filename, const char * filecontents, bool remove = true);
};

/*
 *  �X�B�[�g���s�pmain�֐�
 */
extern int main(int argc, char ** argv);

#define main pseudo_main    //�ʏ��main����������

    //�ȈՃ\�t�g�E�F�A�g���[�X�@�\�̃C���N���[�h
#include "base/coverage_defs.h"

#else

/*********************************************************************************************/
/*
 *  �e�X�g�����s���Ȃ��Ƃ��̃N���X��`
 */

#define TESTABLEOBJECT(x)
#define TESTABLEOBJECT_(x,y)
#define TESTSUITE_PROTOTYPE(x)
#define TESTSUITE_(x,y)
#define PROCEED_ONCE

#define BEGIN_CASE(x,y)
#define END_CASE
#define TEST_FAIL

#define CHECKPOINT(x)

/*
    *  �e�X�g�X�B�[�g���s�N���X
    */
class TestSuite {
public:
        //�e�X�g�X�B�[�g�̎��s  (�ԋp�l:�X�B�[�g�𐳂������s�������ǂ���)
    inline static bool performTestSuite(void) { return true; };
};

#endif

#endif /* TESTSUITE_H */

