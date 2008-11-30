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
 *  @(#) $Id: collection.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/collection.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/collection.h"


using namespace std;

    //���ɉ������Ȃ��R���X�g���N�^
Collection::Collection(void) throw()
{}

    //�f�X�g���N�^
Collection::~Collection(void) throw()
{
        //�O�̂��߂ɗ�O�ɂӂ�������
    try { clear(); }
    catch(...) {}
}

    //�C���X�^���X���R���N�V�����ɒǉ� (�����͓o�^��)
bool Collection::addInstance(Collectable * _instance, bool _destruction) throw()
{
    bool result = false;

    if(isValid() && _instance != 0) {

            // �����C���X�^���X��2��o�^���Ȃ��悤�ɂ���
        list<Element>::iterator scope;

        scope = container.begin();
        while(scope != container.end()) {
            if(scope->instance == _instance)
                break;
            ++ scope;
        }

        if(scope == container.end()) {
                // �����ɗv�f��ǉ�
            struct Element element;
            element.instance    = _instance;
            element.destruction = _destruction;
            container.push_back(element);
        }
        else {
                // �j���w���͍ŐV�ɒ����Ă���
            scope->destruction = _destruction;
        }

        result = true;
    }

    return result;
}

    //�w�肳�ꂽCollectable�C���X�^���X�ɑ�������ꏊ���w���C�e���[�^�̎擾 (getInstance)
list<Collection::Element>::const_iterator Collection::_findInstance(const Collectable * predecessor) const throw()
{
    list<Element>::const_iterator result;

    result = container.begin();

        //predecessor���w�肳��Ă����ꍇ�͒T��
    if(predecessor != 0) {
        while(result != container.end()) {
            if(result->instance == predecessor) {
                ++ result;   //������predecessor�̎�����
                break;
            }
            ++ result;
        }
    }

    return result;
}

    //�R���N�V��������C���X�^���X���擾
Collectable * Collection::getInstance(const type_info & type, const Collectable * predecessor) const throw()
{
    Collectable * result;

    result = 0;
    if(isValid()) {

        list<Element>::const_iterator scope;

            // ��s����C���X�^���X�̏ꏊ��T��
        scope = _findInstance(predecessor);

            // �w�肳�ꂽ�^�������̃C���X�^���X��T��
        while(scope != container.end()) {
            if(typeid(*scope->instance) == type) {
                result = scope->instance;
                break;
            }
            ++ scope;
        }
    }

    return result;
}

    //�R���N�V��������C���X�^���X�����O (�j���͂��Ȃ�)
bool Collection::removeInstance(const Collectable * instance) throw()
{
    bool result = false;

    if(isValid() && instance != 0) {
        list<Element>::iterator scope;

        scope = container.begin();
        while(scope != container.end()) {
            if(scope->instance == instance) {
                    //�v�f�̍폜
                container.erase(scope);
                result = true;
                break;
            }
            ++ scope;
        }
    }

    return result;
}

    //�S�v�f�̔j��
void Collection::clear(void)
{
    if(isValid()) {
        list<Element>::iterator scope;
        list<Element>::iterator next;

            //�j���t���O�����Ă���C���X�^���X��j��
        scope = container.begin();
        while(scope != container.end()) {

            next = scope;       //ROT�n��delete����Ǝ����������ɂ�����̂ŁA�C�e���[�^��ۑ����邽�߂ɐ�Ɏ����擾���Ă���
            ++ next;

            if(scope->destruction)
                delete scope->instance;

            scope = next;
        }

        container.clear();
    }
}

/************************************************* �e�X�g�X�B�[�g *************************************************/

#ifdef TESTSUITE
#include "coverage_undefs.h"

class TestCollectable : public Collectable
{};

class TestCollectable2 : public Collectable
{   public: ~TestCollectable2(void) throw() { TestSuite::check("TestCollectable2::~TestCollectable2"); }   };

#ifdef _MSC_VER
class TestCollectable3 : public Collectable
{   public: ~TestCollectable3(void) throw(int) { throw 0; }   };
#endif

class TestCollectable4 : public TestCollectable2
{   public: ~TestCollectable4(void) throw() { TestSuite::check("TestCollectable4::~TestCollectable4"); }   };

TESTSUITE(main, Collection)
{
    BEGIN_CASE("addInstance","addInstance") {
        BEGIN_CASE("1","�C���X�^���X�͐������o�^�ł���") {
            Collection col;
            TestCollectable test;
            TestCollectable2 test2;

            BEGIN_CASE("1","�o�^�ł�TRUE���Ԃ� (1��)") {
                if(!col.addInstance(&test,  false))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�o�^�ł�true���Ԃ� (2��)") {
                if(!col.addInstance(&test2, false))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("3","���������Ă�") {
                if(col.container.size() != 2)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("4","���Ԃ������Ă�") {
            list<Element>::iterator scope;
                scope = col.container.begin();
                if(scope->instance != &test || scope->destruction != false)
                    TEST_FAIL;
                ++ scope;
                if(scope->instance != &test2 || scope->destruction != false)
                    TEST_FAIL;
                ++ scope;
                if(scope != col.container.end())
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("2","NULL�C���X�^���X�͓o�^����Ȃ�") {
            Collection col;

            BEGIN_CASE("1","NULL�C���X�^���X��n����false���Ԃ�") {
                if(col.addInstance(0))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�����o�^����Ă��Ȃ�") {
                if(col.container.size() != 0)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("3","�����ȃC���X�^���X�ɑ΂��鑀���false���Ԃ�") {
            Collection col;

            if(col.addInstance(0))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","����̃C���X�^���X��2��o�^���Ă�1���������o�^����Ȃ�") {
            Collection col;
            TestCollectable test;

            TEST_CASE("0","[�O��] ���ڂ͐�������������", col.addInstance(&test, false));

            TEST_CASE("1","�֐��͐������I������", col.addInstance(&test, false));
            TEST_CASE("2","�C���X�^���X���͑����Ă��Ȃ�", col.container.size() == 1);

        } END_CASE;

    } END_CASE;

    BEGIN_CASE("getInstance(type_info)","getInstance(type_info)") {
        Collection col;
        TestCollectable test;
        TestCollectable test_2;
        TestCollectable test_3;
        TestCollectable2 test2;
        TestCollectable2 test2_2;
        TestCollectable2 test2_3;

        col.addInstance(test);
        col.addInstance(test2);
        col.addInstance(test_2);
        col.addInstance(test2_2);
        col.addInstance(test_3);
        col.addInstance(test2_3);

        Collectable * instance = 0;

        BEGIN_CASE("1","�ŏ��̗v�f���擾�ł���") {
            instance = col.getInstance(typeid(TestCollectable));
            if(instance != &test)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","���̗v�f���擾�ł���") {
            instance = col.getInstance(typeid(TestCollectable), instance);
            if(instance != &test_2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","����Ɏ��̗v�f���擾�ł���") {
            instance = col.getInstance(typeid(TestCollectable), instance);
            if(instance != &test_3)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","���̂܂����̗v�f���擾������NULL���Ԃ�") {
            instance = col.getInstance(typeid(TestCollectable), instance);
            if(instance != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("5","�ŏ��̗v�f���擾�ł���") {
            instance = col.getInstance(typeid(TestCollectable2));
            if(instance != &test2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("6","���̗v�f���擾�ł���") {
            instance = col.getInstance(typeid(TestCollectable2), instance);
            if(instance != &test2_2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("7","����Ɏ��̗v�f���擾�ł���") {
            instance = col.getInstance(typeid(TestCollectable2), instance);
            if(instance != &test2_3)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("8","���̂܂����̗v�f���擾������NULL���Ԃ�") {
            instance = col.getInstance(typeid(TestCollectable), instance);
            if(instance != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("9","���N���X�ł͂Ђ�������Ȃ�") {
            instance = col.getInstance(typeid(Collectable));
            if(instance != 0)
                TEST_FAIL;
        } END_CASE;

        TEST_CASE("10","NULL�ɑ΂��Ď��s�����NULL���Ԃ�", ((Collection *)0)->getInstance(typeid(Collectable)) == 0);
    } END_CASE;

    BEGIN_CASE("getInstance<T>()","getInstance<T>()") {
        Collection col;
        TestCollectable test;
        TestCollectable test_2;
        TestCollectable test_3;
        TestCollectable2 test2;
        TestCollectable2 test2_2;
        TestCollectable2 test2_3;

        col.addInstance(test);
        col.addInstance(test2);
        col.addInstance(test_2);
        col.addInstance(test2_2);
        col.addInstance(test_3);
        col.addInstance(test2_3);

        Collectable * instance = 0;

        BEGIN_CASE("1","�ŏ��̗v�f���擾�ł���") {
            instance = col.getInstance<TestCollectable>();
            if(instance != &test)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","���̗v�f���擾�ł���") {
            instance = col.getInstance<TestCollectable>(instance);
            if(instance != &test_2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","����Ɏ��̗v�f���擾�ł���") {
            instance = col.getInstance<TestCollectable>(instance);
            if(instance != &test_3)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","���̂܂����̗v�f���擾������NULL���Ԃ�") {
            instance = col.getInstance<TestCollectable>(instance);
            if(instance != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("5","�ŏ��̗v�f���擾�ł���") {
            instance = col.getInstance<TestCollectable2>();
            if(instance != &test2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("6","���̗v�f���擾�ł���") {
            instance = col.getInstance<TestCollectable2>(instance);
            if(instance != &test2_2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("7","����Ɏ��̗v�f���擾�ł���") {
            instance = col.getInstance<TestCollectable2>(instance);
            if(instance != &test2_3)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("8","���̂܂����̗v�f���擾������NULL���Ԃ�") {
            instance = col.getInstance<TestCollectable2>(instance);
            if(instance != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("9","���N���X�ň����|���� ����1") {
            instance = col.getInstance<Collectable>();
            if(instance != &test)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("10","���N���X�ň����|���� ����2") {
            instance = col.getInstance<Collectable>(instance);
            if(instance != &test2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("11","���N���X�ň����|���� ����3") {
            instance = col.getInstance<Collectable>(instance);
            if(instance != &test_2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("12","���N���X�ň����|���� ����4") {
            instance = col.getInstance<Collectable>(instance);
            if(instance != &test2_2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("13","���N���X�ň����|���� ����5") {
            instance = col.getInstance<Collectable>(instance);
            if(instance != &test_3)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("14","���N���X�ň����|���� ����6") {
            instance = col.getInstance<Collectable>(instance);
            if(instance != &test2_3)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("15","���N���X�ň����|���� ����7") {
            instance = col.getInstance<Collectable>(instance);
            if(instance != 0)
                TEST_FAIL;
        } END_CASE;

        TEST_CASE("16","NULL�ɑ΂��Ď��s�����NULL���Ԃ�", ((Collection *)0)->getInstance<Collectable>() == 0);

    } END_CASE;

    BEGIN_CASE("removeInstance","removeInstance") {

        BEGIN_CASE("1","����ɍ폜�ł���") {
            Collection col;
            TestCollectable test;
            TestCollectable test2;

            col.addInstance(test);
            col.addInstance(test2);

            BEGIN_CASE("1","���݂���v�f��remove������true") {
                if(!col.removeInstance(&test))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�����Ə����Ă���") {
                if(col.container.size() != 1 || col.container.begin()->instance != &test2)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("2","NULL�C���X�^���X�Ɏ��s�����false") {
            if(((Collection *)0)->removeInstance(0))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","�o�^���Ă��Ȃ��C���X�^���X���w�肷��Ǝ��s����") {
            Collection col;
            TestCollectable test;
            TestCollectable test2;

            col.addInstance(test);

            if(col.removeInstance(&test2))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","NULL�C���X�^���X��n���Ǝ��s����") {
            Collection col;
            TestCollectable test;
            col.addInstance(test);

            if(col.removeInstance(0))
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("clear","clear") {
        BEGIN_CASE("1","���̂�o�^����clear") {
            Collection col;
            TestCollectable2 test2;

            TestSuite::clearCheckpoints();
            col.addInstance(test2);
            col.clear();

            BEGIN_CASE("1","�v�f���Ȃ��Ȃ��Ă���") {
                if(col.container.size() != 0)
                    TEST_FAIL;
            } END_CASE;

            TEST_CASE("2","test2�͔j������Ȃ�", !TestSuite::isReached("TestCollectable2::~TestCollectable2"));
        } END_CASE;

        BEGIN_CASE("2","�|�C���^��o�^����clear") {
            Collection col;
            TestCollectable2 * test2 = new TestCollectable2;
            
            TestSuite::clearCheckpoints();
            col.addInstance(test2);
            col.clear();

            BEGIN_CASE("1","�v�f���Ȃ��Ȃ��Ă���") {
                if(col.container.size() != 0)
                    TEST_FAIL;
            } END_CASE;

            TEST_CASE("2","test2�͔j�������", TestSuite::isReached("TestCollectable2::~TestCollectable2"));
        } END_CASE;

        BEGIN_CASE("3","NULL�I�u�W�F�N�g�ɑ΂��Ď��s���Ă��\�����Ȃ�") {
            ((Collection *)0)->clear();
        } END_CASE;

#ifdef _MSC_VER
        BEGIN_CASE("4","��O���o��悤�ȃf�X�g���N�^�����C���X�^���X��j������Ɨ�O���R���") {
            Collection col;
            bool result = false;
            TestCollectable3 * test = new TestCollectable3;

            col.addInstance(test);
            try {
                col.clear();
            }
            catch(...) {
                result = true;
            }


            if(!result)
                TEST_FAIL;
        } END_CASE;
#endif
    } END_CASE;

    BEGIN_CASE("destructor","destructor") {
        BEGIN_CASE("1","���̂�o�^���Ĕj��") {
            Collection * col = new Collection;
            TestCollectable2 test2;

            TestSuite::clearCheckpoints();
            col->addInstance(test2);
            delete col;

            TEST_CASE("1","test2�͔j������Ȃ�", !TestSuite::isReached("TestCollectable2::~TestCollectable2"));
        } END_CASE;

        BEGIN_CASE("2","�|�C���^��o�^����clear") {
            Collection * col = new Collection;
            TestCollectable2 * test2 = new TestCollectable2;

            TestSuite::clearCheckpoints();
            col->addInstance(test2);
            delete col;

            TEST_CASE("1","test2�͔j�������", TestSuite::isReached("TestCollectable2::~TestCollectable2"));
        } END_CASE;

#ifdef _MSC_VER
        BEGIN_CASE("3","��O���o��悤�ȃf�X�g���N�^�����C���X�^���X��j�����Ă���O���R��Ȃ�") {
            Collection * col = new Collection;
            TestCollectable3 * test2 = new TestCollectable3;
            bool result = true;
            
            TestSuite::clearCheckpoints();
            col->addInstance(test2);

            try {
                delete col;
            }
            catch(...) {
                result = false;
            }

            if(!result)
                TEST_FAIL;
        } END_CASE;
#endif
    } END_CASE;

    BEGIN_CASE("deleteInstance","deleteInstance") {
        BEGIN_CASE("1","�C���X�^���X���폜�ł���") {
            Collection col;
            TestCollectable2 * test = new TestCollectable2;

            TestSuite::clearCheckpoints();
            col.addInstance(test);

            TEST_CASE("0","[�O��] �����Ɠo�^����Ă���", col.getInstance<TestCollectable2>() != 0);

            col.deleteInstance<TestCollectable2>();
            TEST_CASE("1","�C���X�^���X�������Ă���", col.getInstance<TestCollectable2>() == 0);
            TEST_CASE("2","�f�X�g���N�^�����s����Ă���", TestSuite::isReached("TestCollectable2::~TestCollectable2"));
        }END_CASE;

        BEGIN_CASE("2","�֌W�Ȃ��N���X���w�肵����폜����Ȃ�") {
            Collection col;
            TestCollectable2 * test = new TestCollectable2;

            TestSuite::clearCheckpoints();
            col.addInstance(test);

            TEST_CASE("0","[�O��] �����Ɠo�^����Ă���", col.getInstance<TestCollectable2>() != 0);

            col.deleteInstance<TestCollectable>();
            TEST_CASE("1","�C���X�^���X�������Ă��Ȃ�", col.getInstance<TestCollectable2>() != 0);
            TEST_CASE("2","�f�X�g���N�^�����s����Ă��Ȃ�", !TestSuite::isReached("TestCollectable2::~TestCollectable2"));
            delete test;
        }END_CASE;

        BEGIN_CASE("3","�����N���X�����łȂ��h�����������") {
            Collection col;
            TestCollectable2 * test = new TestCollectable2;
            TestCollectable4 * test2 = new TestCollectable4;

            TestSuite::clearCheckpoints();
            col.addInstance(test);
            col.addInstance(test2);

            TEST_CASE("0","[�O��] �����Ɠo�^����Ă���", col.getInstance(typeid(TestCollectable2)) != 0);
            TEST_CASE("0","[�O��] �����Ɠo�^����Ă���", col.getInstance(typeid(TestCollectable4)) != 0);

            col.deleteInstance<TestCollectable2>();
            TEST_CASE("1","�C���X�^���X�����ׂď����Ă���", col.getInstance<TestCollectable2>() == 0);
            TEST_CASE("2","TestCollectable2�̃f�X�g���N�^�����s����Ă���", TestSuite::isReached("TestCollectable2::~TestCollectable2"));
            TEST_CASE("3","TestCollectable4�̃f�X�g���N�^�����s����Ă���", TestSuite::isReached("TestCollectable4::~TestCollectable4"));
        }END_CASE;

        BEGIN_CASE("4","���͔̂j���ΏۂɂȂ�Ȃ�") {
            Collection col;
            TestCollectable2 test;

            TestSuite::clearCheckpoints();
            col.addInstance(test);

            TEST_CASE("0","[�O��] �����Ɠo�^����Ă���", col.getInstance<TestCollectable2>() != 0);

            col.deleteInstance<TestCollectable2>();
            TEST_CASE("1","�C���X�^���X�������Ă���", col.getInstance<TestCollectable2>() == 0);
            TEST_CASE("2","�f�X�g���N�^�����s����Ă��Ȃ�", !TestSuite::isReached("TestCollectable2::~TestCollectable2"));
        }END_CASE;

        BEGIN_CASE("5","NULL�I�u�W�F�N�g�ɑ΂��Ĕ��s���Ă��\�����Ȃ�") {
            ((Collection *)0)->deleteInstance<TestCollectable>();
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("replaceInstance","replaceInstance") {
        BEGIN_CASE("1","�o�^�ς݂̃C���X�^���X�����ւ���") {
            Collection col;
            TestCollectable2 test;
            TestCollectable2 test2;

            TestSuite::clearCheckpoints();
            col.addInstance(test);

            TEST_CASE("0","[�O��] �����Ɠo�^����Ă���", col.getInstance(typeid(TestCollectable2)) != 0);
            
            TEST_CASE("1", "�֐��͐�������", col.replaceInstance<TestCollectable2>(test2));
            TEST_CASE("2", "�C���X�^���X�͓���ւ���Ă���", col.getInstance(typeid(TestCollectable2)) == &test2);
            TEST_CASE("3", "test2�ȊO�ɃC���X�^���X�͂Ȃ�", col.getInstance(typeid(TestCollectable2), &test2) == 0);
            TEST_CASE("4", "�f�X�g���N�^�͎��s����ĂȂ�", !TestSuite::isReached("TestCollectable2::~TestCollectable2"));
        } END_CASE;

        BEGIN_CASE("2","�o�^�ς݂̃C���X�^���X��h���N���X�̃C���X�^���X�œ���ւ���") {
            Collection col;
            TestCollectable2 test;
            TestCollectable4 test2;

            TestSuite::clearCheckpoints();
            col.addInstance(test);

            TEST_CASE("0","[�O��] �����Ɠo�^����Ă���", col.getInstance(typeid(TestCollectable2)) != 0);
            
            TEST_CASE("1", "�֐��͐�������", col.replaceInstance<TestCollectable2>(test2));
            TEST_CASE("2", "�C���X�^���X�͓���ւ���Ă���", col.getInstance<TestCollectable2>() == &test2);
            TEST_CASE("3", "test2�ȊO�ɃC���X�^���X�͂Ȃ�", col.getInstance(typeid(TestCollectable2)) == 0);
            TEST_CASE("4", "�f�X�g���N�^�͎��s����ĂȂ�", !TestSuite::isReached("TestCollectable2::~TestCollectable2"));
        } END_CASE;

        BEGIN_CASE("3","���֌W�ȃN���X���w�肵�ē���ւ���") {
            Collection col;
            TestCollectable2 test;
            TestCollectable4 test2;

            TestSuite::clearCheckpoints();
            col.addInstance(test);

            TEST_CASE("0","[�O��] �����Ɠo�^����Ă���", col.getInstance(typeid(TestCollectable2)) != 0);
            
            TEST_CASE("1", "�֐��͎��s����", !col.replaceInstance<TestCollectable>(test2));
            TEST_CASE("2", "�C���X�^���X�͎c���Ă���", col.getInstance<TestCollectable2>() == &test);
        } END_CASE;

        BEGIN_CASE("4","�o�^�ς݂̃C���X�^���X�����ւ��� (���I�m��)") {
            Collection col;
            TestCollectable2 * test = new TestCollectable2;
            TestCollectable2 test2;

            TestSuite::clearCheckpoints();
            col.addInstance(test);

            TEST_CASE("0","[�O��] �����Ɠo�^����Ă���", col.getInstance(typeid(TestCollectable2)) != 0);
            
            TEST_CASE("1", "�֐��͐�������", col.replaceInstance<TestCollectable2>(test2));
            TEST_CASE("2", "�C���X�^���X�͓���ւ���Ă���", col.getInstance(typeid(TestCollectable2)) == &test2);
            TEST_CASE("3", "test2�ȊO�ɃC���X�^���X�͂Ȃ�", col.getInstance(typeid(TestCollectable2), &test2) == 0);
            TEST_CASE("4", "�f�X�g���N�^�͎��s����Ă�", TestSuite::isReached("TestCollectable2::~TestCollectable2"));
        } END_CASE;

    } END_CASE;
}


class TestRuntimeObject : public RuntimeObject
{
public:
    TestRuntimeObject(void) { CHECKPOINT("TestRuntimeObject::TestRuntimeObject"); }
    ~TestRuntimeObject(void) { CHECKPOINT("TestRuntimeObject::~TestRuntimeObject"); }
};

class TestRuntimeObject2 : public RuntimeObject
{
public:
    TestRuntimeObject2(void) : RuntimeObject(true) { CHECKPOINT("TestRuntimeObject2::TestRuntimeObject2"); }
    ~TestRuntimeObject2(void) { CHECKPOINT("TestRuntimeObject2::~TestRuntimeObject2"); }
};

TESTSUITE(main, RuntimeObjectTable)
{
    Singleton<RuntimeObjectTable>::Context context;
    Singleton<RuntimeObjectTable>::saveContext(context);

    BEGIN_CASE("getInstance","getInstance") {
        BEGIN_CASE("1","getInstance�͐������@�\����") {
            Singleton<RuntimeObjectTable>::renewInstance();
            TestCollectable test;

            Singleton<RuntimeObjectTable>::getInstance()->addInstance(test);

            BEGIN_CASE("1","getInstance(typeid)") {
                if(RuntimeObjectTable::getInstance(typeid(TestCollectable)) != &test)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","getInstance<T>()") {
                if(RuntimeObjectTable::getInstance<TestCollectable>() != &test)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("RuntimeObject","RuntimeObject") {
        BEGIN_CASE("1","��������Ɠo�^����A�j���ŏ��ł���") {
            TestRuntimeObject * ro;

            TestSuite::clearCheckpoints();

            TEST_CASE("0","[�O��] �o�^����Ă��Ȃ�", RuntimeObjectTable::getInstance<TestRuntimeObject>() == 0);

            ro = new TestRuntimeObject;

            TEST_CASE("1","�R���X�g���N�^�����s����Ă���", TestSuite::isReached("TestRuntimeObject::TestRuntimeObject"));
            TEST_CASE("2","�o�^����Ă���", RuntimeObjectTable::getInstance<TestRuntimeObject>() == ro);

            delete ro;

            TEST_CASE("3","�f�X�g���N�^�����s����Ă���", TestSuite::isReached("TestRuntimeObject::~TestRuntimeObject"));
            TEST_CASE("4","�o�^����������Ă���", RuntimeObjectTable::getInstance<TestRuntimeObject>() == 0);

        } END_CASE;

        BEGIN_CASE("2","�����j���̃`�F�b�N") {
            TestRuntimeObject * ro;
            TestRuntimeObject2 * ro2;

            TestSuite::clearCheckpoints();

            TEST_CASE("0","[�O��] �o�^����Ă��Ȃ�", RuntimeObjectTable::getInstance<TestRuntimeObject>() == 0);
            TEST_CASE("0","[�O��] �o�^����Ă��Ȃ�", RuntimeObjectTable::getInstance<TestRuntimeObject2>() == 0);

            ro = new TestRuntimeObject;
            ro2 = new TestRuntimeObject2;

            TEST_CASE("1","�R���X�g���N�^�����s����Ă���(ro)", TestSuite::isReached("TestRuntimeObject::TestRuntimeObject"));
            TEST_CASE("2","�R���X�g���N�^�����s����Ă���(ro2)", TestSuite::isReached("TestRuntimeObject2::TestRuntimeObject2"));
            TEST_CASE("3","�o�^����Ă���(ro)", RuntimeObjectTable::getInstance<TestRuntimeObject>() == ro);
            TEST_CASE("4","�o�^����Ă���(ro2)", RuntimeObjectTable::getInstance<TestRuntimeObject2>() == ro2);

            Singleton<RuntimeObjectTable>::getInstance()->clear();

            TEST_CASE("5","�f�X�g���N�^�͎��s����Ă��Ȃ� (ro)", !TestSuite::isReached("TestRuntimeObject::~TestRuntimeObject"));
            TEST_CASE("6","�f�X�g���N�^�͎��s����Ă��� (ro2)", TestSuite::isReached("TestRuntimeObject2::~TestRuntimeObject2"));
            TEST_CASE("7","�o�^����������Ă���", RuntimeObjectTable::getInstance<TestRuntimeObject>() == 0);
            TEST_CASE("8","�o�^����������Ă���", RuntimeObjectTable::getInstance<TestRuntimeObject2>() == 0);

            delete ro;
        } END_CASE;

    } END_CASE;

    Singleton<RuntimeObjectTable>::restoreContext(context);
}

#endif

