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
 *  @(#) $Id: component.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/component.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/component.h"

#include <iostream>

using namespace std;

    //�R���|�[�l���g�S�̂��g�p�ł���Ȃ�true
bool Component::is_valid = true;

    //�R���|�[�l���g�̓o�^
bool Component::ComponentInfo::addComponent(Component * component, int order) throw()
{
    bool result = false;

    if(this != 0 && component != 0) {
        componentList.insert(multimap<int, Component *>::value_type(order, component));
        result = true;
    }

    return result;
}

    //�R���|�[�l���g�̓o�^����
void Component::ComponentInfo::removeComponent(Component * component, int order) throw()
{
    if(this != 0 && component != 0) {
        multimap<int, Component *>::iterator scope;

        scope = componentList.lower_bound(order);
        while(scope != componentList.end()) {
                //�����w�肳�ꂽ�D��x�͂��ׂČ���
            if(scope->first != order)
                break;
        
                //�w�肳�ꂽ�R���|�[�l���g�Ɉ�v������폜
            if(scope->second == component) {
                multimap<int, Component *>::iterator target = scope;
                ++ scope;
                componentList.erase(target);
            }
            else
                ++ scope;
        }
    }
}

    //�R���|�[�l���g�̓o�^����
void Component::ComponentInfo::removeComponent(Component * component) throw()
{
    if(this != 0 && component != 0) {
        multimap<int, Component *>::iterator scope;

            //�w�肳�ꂽ�R���|�[�l���g�Ɉ�v������̂�S�č폜
        scope = componentList.begin();
        while(scope != componentList.end()) {
            if(scope->second == component) {
                multimap<int, Component *>::iterator target = scope;
                ++ scope;
                componentList.erase(target);
            }
            else
                ++ scope;
        }

    }
}

    //�R���|�[�l���g�̋N���v���̔��s
bool Component::ComponentInfo::activateComponent(Component * component) throw()
{
    bool result = false;

    if(this != 0 && component != 0) {
            //�N���v���̖����ɉ�����
        activatedComponentList.push_back(component);
        result = true;
    }

    return result;
}

    //�I�v�V�����̃p�[�X
void Component::ComponentInfo::parseOption(OptionParameter & option)
{
    if(this != 0) {
        multimap<int, Component *>::iterator scope;

            //�S�ẴR���|�[�l���g��parseOption�����s
        scope = componentList.begin();
        while(scope != componentList.end()) {
            DebugMessage("Component::parseOption start  - %\n") << typeid(*scope->second).name();
            scope->second->parseOption(option);
            DebugMessage("Component::parseOption finish - %\n") << typeid(*scope->second).name();
            ++ scope;
        }
    }
}

    //�R���|�[�l���g�̋N��
void Component::ComponentInfo::activateComponent(void)
{
    if(this != 0) {
        list<Component *>::iterator scope;

        try {
                //�N���v���̂������S�ẴR���|�[�l���g���N��
            scope = activatedComponentList.begin();
            while(scope != activatedComponentList.end()) {
                DebugMessage("Component::body start  - %\n") << typeid(**scope).name();
                (*scope)->body();
                DebugMessage("Component::body finish - %\n") << typeid(**scope).name();
                ++ scope;
            }
                //�v�����X�g���N���A
            activatedComponentList.clear();
        }
        catch(...) {
                //onFatalExit�p�ɁAactivatedComponentList���N�����������R���|�[�l���g�����ɍi��
            ++ scope;
            if(scope != activatedComponentList.end())
                activatedComponentList.erase(scope, activatedComponentList.end());
        
            throw;
        }
    }
}

    //�ُ폈���n���h���̋N��
void Component::ComponentInfo::onFatalExit(void)
{
    if(this != 0) {
        Component * handler;

            //�N���v���̂������S�ẴR���|�[�l���g���N��
        while(!activatedComponentList.empty()) {
            handler = *activatedComponentList.begin();
            activatedComponentList.pop_front();

                //�n���h�����N��
            DebugMessage("Component::onFatalExit start  - %\n") << typeid(*handler).name();
            handler->onFatalExit();
            DebugMessage("Component::onFatalExit fihish - %\n") << typeid(*handler).name();
        }
            //�v�����X�g���N���A
        activatedComponentList.clear();
    }
}


/*
 *   Component : �R���|�[�l���g
 */

    //�R���X�g���N�^
Component::Component(int order) throw() : RuntimeObject()
{
        //�����ŏ��߂ăV���O���g���C���X�^���X�ɃA�N�Z�X����̂ŁAbad_alloc����������\��������
    try {
        Singleton<ComponentInfo>::getInstance()->addComponent(this, order);
    }
    catch(bad_alloc) {
        is_valid = false;
    }
}

    //�f�X�g���N�^
Component::~Component(void) throw()
{   Singleton<ComponentInfo>::getInstance()->removeComponent(this);   }

    //�R���|�[�l���g�̎��s
void Component::executeComponents(int argc, char * argv [])
{
    OptionParameter & option = getOptionParameter();

    option.parseOption(argc, argv);
    executeComponents(option);
}

    //�R���|�[�l���g�̎��s
void Component::executeComponents(OptionParameter & option)
{
    if(isValid()) {

        _parseCommonOption(option);

        try {
                //�I�v�V�����̃p�[�X
            Singleton<ComponentInfo>::getInstance()->parseOption(option);

                //�S�ẴI�v�V�������g�p�ς݂łȂ���΃G���[
            if(!option.validateOption()) {
                CHECKPOINT("Exception_UnknownOption");
                ExceptionMessage("Unknown option [%] found.","�s���ȃI�v�V�������w�肳�ꂽ : %") << option.getInvalidOptions() << throwException;
            }
            else {
                    //�R���|�[�l���g�̎��s
                Singleton<ComponentInfo>::getInstance()->activateComponent(); 
            }
        }

            //��O�̔��� -> �ُ�I���n���h���̋N��
        catch(...) {
            bool continuation;
            do {
                try {
                    continuation = true;
                    Singleton<ComponentInfo>::getInstance()->onFatalExit();
                    continuation = false;
                }
                catch(Exception & e) {
                    CHECKPOINT("Exception_onFatalExit");
                    cerr << Message("[Internal error] onFatalExit threw an exception! : ","[�����G���[] onFatalExit���̗�O! : ") << e.getDetails() << '\n';
                }
            } while(continuation);

            throw;
        }
    }
}


    //��ʓI�ȃI�v�V�����̏���
void Component::_parseCommonOption(OptionParameter & option) throw()
{
        //�f�o�b�O����
    if(option.find("debug")) {
        DebugMessage::setStream(&cerr);
        DebugMessage::setVerbose(true);
    }

        //����I��
    if(option.find("lj") || option.find("-japanese"))
        Message::selectLanguage(Message::JAPANESE);
    if(option.find("le") || option.find("-english"))
        Message::selectLanguage(Message::ENGLISH);

        //�璷���b�Z�[�W
    if(option.find("v") || option.find("-verbose")) {
        VerboseMessage::setStream(&cout);
        VerboseMessage::setVerbose(true);
    }

        //�o�i�[�\��
    if(!getBanner().empty() && option.find("v") || option.find("-verbose") || option.find("h") || option.find("-help"))
        cout << getBanner() << endl;

        //�w���v�\��
    if(option.find("h") || option.find("-help"))
        cout << '\n' << Message(
            "Global option\n"
            " -lj, --japanese : Use Japanese as default language\n"
            " -le, --english  : Use English as default language\n"
            " -v,  --verbose  : Verbose Message\n",
            "�S�̂̃I�v�V����\n"
            " -lj, --japanese : ���{��ŕ\�����܂�\n"
            " -le, --english  : �p��ŕ\�����܂�\n"
            " -v,  --verbose  : �璷���b�Z�[�W���o�͂��܂�\n");
}

    //�o�i�[�A�N�Z�T
void Component::setBanner(string src) throw(bad_alloc)
{
    ComponentInfo * info = Singleton<ComponentInfo>::getInstance();
    info->setBanner(src);
}

string Component::getBanner(void) throw(bad_alloc)
{
    ComponentInfo * info = Singleton<ComponentInfo>::getInstance();
    return info->getBanner();
}

/*
 *   �ߋ��Ƃ̌݊����̂��߂̃p�����[�^����API
 */

    /* �w�肳�ꂽ�I�v�V�����̑��݂��m�F���A�K�v�ł���΂��̃p�����[�^���擾���� */
bool Component::findOption(const char * key1, const char * key2, std::string * element) throw()
{
    OptionParameter::OptionItem item;

    item = getOption(key1, key2, true);
    if(item.isValid() && element != 0 && item.hasParameter())
        *element = item[0];

    return item.isValid();
}

    /* ���݊m�F + �`�F�b�N������ */
bool Component::checkOption(const char * key1, const char * key2) throw()
{   return getOption(key1, key2, true).isValid();   }

    /* �w�肳�ꂽ���O�̃I�v�V�����p�����[�^���擾 */
OptionParameter::OptionItem Component::getOption(const char * key1, const char * key2, bool dirty) throw()
{
    OptionParameter::OptionItem item;
        
    if(key1 != 0)
        item = getOptionParameter().get(key1, dirty);
        
    if(key2 != 0) {
        if(item.isValid())
            item.mergeItem(getOptionParameter().get(string("-") + key2, dirty));
        else
            item = getOptionParameter().get(string("-") + key2, dirty);
    }

    return item;
}

    /* 2�̃I�v�V�������ڂ��}�[�W���� (�����Ă����Ă��}�[�W�����̂ŋC�ɂ��Ȃ�) */
OptionParameter::OptionItem Component::mergeOption(const char * key1, const char * key2) throw()
{   return getOption(key1, key2);   }



/****************************************************** �e�X�g�X�B�[�g ******************************************************/

#ifdef TESTSUITE
#include "coverage_undefs.h"

namespace {
    int counter = 0;

    class TestComponent : public Component
    {
    public:
        bool         check_parseOption;
        bool         check_body;
        bool         check_onFatalExit;
        bool         activation;
        bool         throw_parseOption;
        bool         throw_body;
        bool         throw_onFatalExit;
        int          actcnt;

        TestComponent(int order = GENERAL_PURPOSE) : Component(order)
        {
            check_parseOption = false;
            check_body        = false;
            check_onFatalExit = false;
            activation        = false;
            throw_parseOption = false;
            throw_body        = false;
            throw_onFatalExit = false;
        }

        void parseOption(OptionParameter & option) throw(Exception)
        {
            actcnt = ++counter;
            check_parseOption = true;
            if(activation)
                activateComponent();
            if(throw_parseOption)
                ExceptionMessage("exception","exception").throwException();
        }

        void body(void) throw(Exception)
        {
            actcnt = ++counter;
            check_body = true;
            if(throw_body)
                ExceptionMessage("exception","exception").throwException();
        }

        void onFatalExit(void) throw(Exception)
        {
            actcnt = ++counter;
            check_onFatalExit = true;
            if(throw_onFatalExit)
                ExceptionMessage("exception","exception").throwException();
        }
    };

    class DerivedTestComponent : public TestComponent
    {};
}


TESTSUITE_(main,ComponentInfo,Component)
{
    Singleton<ComponentInfo>::Context context;
    Singleton<ComponentInfo>::saveContext(context);
    Singleton<ComponentInfo>::renewInstance();

    BEGIN_CASE("addComponent","addComponent") {

        BEGIN_CASE("1","�������ǉ��ł���") {
            ComponentInfo info;

            BEGIN_CASE("1","�֐��͐�������") {
                if(!info.addComponent((Component *)0x1234, 10))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�ǉ�����Ă���") {
                if(info.componentList.size() != 1)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("3", "���e��������") {
                if(info.componentList.begin()->first != 10 || info.componentList.begin()->second != (Component *)0x1234)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("2","NULL�C���X�^���X�͓o�^�ł��Ȃ�") {
            ComponentInfo info;

            BEGIN_CASE("1","�֐��͎��s����") {
                if(info.addComponent(0, 10))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�v�f�͒ǉ�����Ă��Ȃ�") {
                if(info.componentList.size() != 0)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("3","NULL�C���X�^���X�ɑ��삷���false���Ԃ�") {
            if(((ComponentInfo *)0)->addComponent((Component *)0x1234, 10))
                TEST_FAIL;
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("removeComponent(Component *, int)","removeComponent(Component *, int)") {
        BEGIN_CASE("1", "�����������ł���") {
            ComponentInfo info;

            info.addComponent((Component *)0x0123, 10); //38�s�ڂ�if��else�����s�����邽�߂̃_�~�[
            info.addComponent((Component *)0x1234, 10);
            info.addComponent((Component *)0x1234, 20);

            info.removeComponent((Component *)0x1234, 10);
            info.removeComponent((Component *)0x0123, 10);

            BEGIN_CASE("1","�v�f����1") {
                if(info.componentList.size() != 1)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�c�����v�f��order��20") {
                if(info.componentList.begin()->first != 20)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("2", "NULL�I�u�W�F�N�g������s���Ă����v") {
            ((ComponentInfo *)0)->removeComponent(0, 0);
        } END_CASE;
    } END_CASE;
            
    BEGIN_CASE("removeComponent(Component *)","removeComponent(Component *)") {
        BEGIN_CASE("1", "�����������ł���") {
            ComponentInfo info;
            multimap<int, Component *>::iterator scope;

            info.addComponent((Component *)0x1234, 10);
            info.addComponent((Component *)0x1235, 10);
            info.addComponent((Component *)0x1234, 20);
            info.addComponent((Component *)0x1235, 20);

            info.removeComponent((Component *)0x1234);

            BEGIN_CASE("1","�v�f����2") {
                if(info.componentList.size() != 2)
                    TEST_FAIL;
            } END_CASE;

            scope = info.componentList.begin();
            BEGIN_CASE("2","�c�����v�f�̓��e�͐�����") {
                if(scope->first != 10 || scope->second != (Component *)0x1235)
                    TEST_FAIL;
                ++ scope;
                if(scope->first != 20 || scope->second != (Component *)0x1235)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("2", "NULL�I�u�W�F�N�g������s���Ă����v") {
            ((ComponentInfo *)0)->removeComponent(0);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("activateComponent","activateComponent") {
        BEGIN_CASE("1","����ɒǉ��ł���") {
            ComponentInfo info;

            BEGIN_CASE("1","�֐��͐�������") {
                if(!info.activateComponent((Component *)0x1234))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�N���v�����X�g�ɐ������ǉ�����Ă���") {
                if(info.activatedComponentList.size() != 1)
                    TEST_FAIL;
                if(*info.activatedComponentList.begin() != (Component *)0x1234)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("3","NULL�I�u�W�F�N�g���甭�s���Ă��\�����Ȃ�") {
                ((ComponentInfo *)0)->activateComponent();
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("1","NULL�C���X�^���X�͒ǉ�����Ȃ�") {
            ComponentInfo info;

            BEGIN_CASE("1","�֐��͎��s����") {
                if(info.activateComponent((Component *)0))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�N���v�����X�g�͋�̂܂�") {
                if(!info.activatedComponentList.empty())
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("Component::Component","Component::Component") {
        Singleton<ComponentInfo>::renewInstance();
        TestComponent * test = 0;

        BEGIN_CASE("0","�O������𖞂���") {
            if(Singleton<ComponentInfo>::getInstance()->componentList.size() != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("1","Component���C���X�^���X������ƁA����ɓo�^�����") {
            test = new TestComponent;
            if(Singleton<ComponentInfo>::getInstance()->componentList.size() != 1)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�o�^����Ă�����e�͐�����") {
            if(Singleton<ComponentInfo>::getInstance()->componentList.begin()->second != test)
                TEST_FAIL;
        } END_CASE;
            
        BEGIN_CASE("3","�j������ƃG���g����������") {
            delete test;
            if(Singleton<ComponentInfo>::getInstance()->componentList.size() != 0)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("parseOption","parseOption") {

        BEGIN_CASE("1","parseOption�����s����Ɠo�^���ꂽ�R���|�[�l���g��parseOption�����s�����") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;

            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());

            if(!test.check_parseOption || !test2.check_parseOption)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�N�������������� (���ꃌ�x���Ȃ�o�^��)") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;

            counter = 0;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());

            if(test.actcnt != 1 || test2.actcnt != 2 )
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","�N�������������� (�D��x��)") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test(10);
            TestComponent test2(1);

            counter = 0;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());

            if(test.actcnt != 2 || test2.actcnt != 1 )
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","activate���������activateList�ɓo�^�����") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            list<Component *>::iterator scope;

            test.activation = true;
            test2.activation = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());

            if(Singleton<ComponentInfo>::getInstance()->activatedComponentList.size() != 2)
                TEST_FAIL;
            scope = Singleton<ComponentInfo>::getInstance()->activatedComponentList.begin();
            if(*scope != &test)
                TEST_FAIL;
            ++ scope;
            if(*scope != &test2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("5","��O�͔����Ă���") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            list<Component *>::iterator scope;
            bool result = false;

            Exception::setThrowControl(true);
            test.throw_parseOption = true;
            try {
                Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            }
            catch(...) {
                result = true;
            }

            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("6","��O�O�ɓo�^���ꂽactivate�͎c��") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            list<Component *>::iterator scope;
            bool result = false;

            Exception::setThrowControl(true);
            test.activation = true;
            test2.throw_parseOption = true;
            try {
                Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            }
            catch(...) {
                result = true;
            }

            if(!result)
                TEST_FAIL;

            if(Singleton<ComponentInfo>::getInstance()->activatedComponentList.size() != 1)
                TEST_FAIL;

            if(*Singleton<ComponentInfo>::getInstance()->activatedComponentList.begin() != &test)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("7","NULL�C���X�^���X����̃R�[���ɑς���") {
            ((ComponentInfo *)0)->parseOption(getOptionParameter());
        } END_CASE;
    }END_CASE;

    BEGIN_CASE("activateCompoent/Component::body","activateCompoent/Component::body") {
        BEGIN_CASE("1","activateComponent������ƁA�N���v�����o�����R���|�[�l���g���N�������") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;

            test.activation = true;
            test2.activation = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            Singleton<ComponentInfo>::getInstance()->activateComponent();

            if(!test.check_body || !test2.check_body)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�N���v�����o���Ȃ��R���|�[�l���g�͋N������Ȃ�") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;

            test.activation = false;
            test2.activation = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            Singleton<ComponentInfo>::getInstance()->activateComponent();

            if(test.check_body || !test2.check_body)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","�N�������������� (���ꃌ�x���Ȃ�o�^��)") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            counter = 0;

            test.activation = test2.activation = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            Singleton<ComponentInfo>::getInstance()->activateComponent();

            if(test.actcnt != 3 || test2.actcnt != 4 )
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","�N�������������� (�D��x��)") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test(10);
            TestComponent test2(4);
            counter = 0;

            test.activation = test2.activation = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            Singleton<ComponentInfo>::getInstance()->activateComponent();

            if(test.actcnt != 4 || test2.actcnt != 3 )
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("5","��O�͔����Ă���") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            list<Component *>::iterator scope;
            bool result = false;

            Exception::setThrowControl(true);
            test.activation = test2.activation = true;
            test.throw_body = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            try {
                Singleton<ComponentInfo>::getInstance()->activateComponent();
            }
            catch(...) {
                result = true;
            }

            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("6","��O���N��������A����܂łɋN�������R���|�[�l���g��activatedComponentList�Ɏc��") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            bool result = false;

            Exception::setThrowControl(true);
            test.activation = test2.activation = true;
            test.throw_body = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            try {
                Singleton<ComponentInfo>::getInstance()->activateComponent();
            }
            catch(...) {
                result = true;
            }

            if(!result)
                TEST_FAIL;

            if(Singleton<ComponentInfo>::getInstance()->activatedComponentList.size() != 1)
                TEST_FAIL;

            if(*Singleton<ComponentInfo>::getInstance()->activatedComponentList.begin() != &test)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("8","��O���N��������A����܂łɋN�������R���|�[�l���g��activatedComponentList�Ɏc��(2��)") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            list<Component *>::iterator scope;
            bool result = false;

            Exception::setThrowControl(true);
            test.activation = test2.activation = true;
            test2.throw_body = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            try {
                Singleton<ComponentInfo>::getInstance()->activateComponent();
            }
            catch(...) {
                result = true;
            }

            if(!result)
                TEST_FAIL;

            if(Singleton<ComponentInfo>::getInstance()->activatedComponentList.size() != 2)
                TEST_FAIL;
            scope = Singleton<ComponentInfo>::getInstance()->activatedComponentList.begin();
            if(*scope != &test)
                TEST_FAIL;
            ++ scope;
            if(*scope != &test2)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("onFatalExit","onFatalExit") {
        BEGIN_CASE("1","OnFatalExit������ƋN���v�����X�g�ɂ���R���|�[�l���g���Ă΂��") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;

            test.activation = test2.activation = true;
            test2.throw_body = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            try{ Singleton<ComponentInfo>::getInstance()->activateComponent(); } catch(...) {}
            Singleton<ComponentInfo>::getInstance()->onFatalExit();

            if(!test.check_onFatalExit || !test2.check_onFatalExit)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�N���v�����o���Ȃ��R���|�[�l���g�͋N������Ȃ�") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;

            test.activation = false;
            test2.activation = true;
            test2.throw_body = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            try{ Singleton<ComponentInfo>::getInstance()->activateComponent(); } catch(...) {}
            Singleton<ComponentInfo>::getInstance()->onFatalExit();

            if(test.check_onFatalExit || !test2.check_onFatalExit)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","�N�������������� (���ꃌ�x���Ȃ�o�^��)") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            counter = 0;

            test2.throw_body = true;
            test.activation = test2.activation = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            try{ Singleton<ComponentInfo>::getInstance()->activateComponent(); } catch(...) {}
            Singleton<ComponentInfo>::getInstance()->onFatalExit();

            if(test.actcnt != 5 || test2.actcnt != 6 )
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("5","�N�������������� (�D��x��)") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test(10);
            TestComponent test2(4);
            counter = 0;

            test.activation = test2.activation = true;
            test.throw_body = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            try{ Singleton<ComponentInfo>::getInstance()->activateComponent(); } catch(...) {}
            Singleton<ComponentInfo>::getInstance()->onFatalExit();

            if(test.actcnt != 6 || test2.actcnt != 5 )
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("6","��O�͔����Ă���") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            list<Component *>::iterator scope;
            bool result = false;

            Exception::setThrowControl(true);
            test.activation = test2.activation = true;
            test2.throw_body = true;
            test.throw_onFatalExit = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            try{ Singleton<ComponentInfo>::getInstance()->activateComponent(); } catch(...) {}
            try {
                Singleton<ComponentInfo>::getInstance()->onFatalExit();
            }
            catch(...) {
                result = true;
            }

            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("7","��O���N�����Ƃ��A�܂����s����Ă��Ȃ��R���|�[�l���g�̃n���h���N���v���͎c��") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;
            TestComponent test2;
            list<Component *>::iterator scope;
            bool result = false;

            Exception::setThrowControl(true);
            test.activation = test2.activation = true;
            test2.throw_body = true;
            test.throw_onFatalExit = true;
            Singleton<ComponentInfo>::getInstance()->parseOption(getOptionParameter());
            try{ Singleton<ComponentInfo>::getInstance()->activateComponent(); } catch(...) {}
            try{
                Singleton<ComponentInfo>::getInstance()->onFatalExit();
            }
            catch(...) {
                result = true;
            }

            if(!result)
                TEST_FAIL;

            if(Singleton<ComponentInfo>::getInstance()->activatedComponentList.size() != 1)
                TEST_FAIL;

            if(*Singleton<ComponentInfo>::getInstance()->activatedComponentList.begin() != &test2)
                TEST_FAIL;

        } END_CASE;

        BEGIN_CASE("8","NULL�I�u�W�F�N�g���甭�s���Ă����v") {
            ((ComponentInfo *)0)->onFatalExit();
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("isActive","isActive") {
        BEGIN_CASE("1","�N�������R���|�[�l���g�𔻒�ł���") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;         
            Singleton<ComponentInfo>::getInstance()->activateComponent(&test);

            if(!Singleton<ComponentInfo>::getInstance()->isActive<TestComponent>())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�N�����Ă��Ȃ��R���|�[�l���g�ɂ͔������Ȃ�") {
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;

            if(Singleton<ComponentInfo>::getInstance()->isActive<TestComponent>())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","�h�������R���|�[�l���g�̃C���X�^���X�ɂ͔�������") {
            Singleton<ComponentInfo>::renewInstance();

            DerivedTestComponent test;
            Singleton<ComponentInfo>::getInstance()->activateComponent(&test);

            if(!Singleton<ComponentInfo>::getInstance()->isActive<TestComponent>())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","�����N�����Ă��Ă��v���ɍ��������̂�T����") {   //isActive��if(dynamic_cast<T *>(iterator->instance) != 0)��else�߂����s������̂��ړI
            Singleton<ComponentInfo>::renewInstance();

            TestComponent test;         
            Singleton<ComponentInfo>::getInstance()->activateComponent(&test);
            DerivedTestComponent test2;
            Singleton<ComponentInfo>::getInstance()->activateComponent(&test2);

            if(!Singleton<ComponentInfo>::getInstance()->isActive<DerivedTestComponent>())
                TEST_FAIL;
        } END_CASE;
    } END_CASE;


    Singleton<ComponentInfo>::restoreContext(context);
}

//--------


TESTSUITE(main,Component)
{
    SingletonBase::ContextChain chain;

    chain.saveContext<ComponentInfo>();
    chain.saveContext<OptionParameter>();
    chain.saveContext<VerboseMessage::VerboseControl>();
    chain.saveContext<Message::MessageControl>();
    chain.saveContext<DebugMessage::DebugControl>();

    BEGIN_CASE("executeComponent","executeComponent") {
        BEGIN_CASE("1","���ɉ����Ȃ���parseOption/body�����s�����") {
            chain.renewInstance();

            bool result = true;
            TestComponent test;
            test.activation = true;

            Exception::setThrowControl(true);
            try { executeComponents(getOptionParameter()); }
            catch(...) { result = false; }

            BEGIN_CASE("1","��O�͋N����Ȃ�") {
                if(!result)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","parseOption/body�͎��s�����") {
                 if(!test.check_parseOption || !test.check_body || test.check_onFatalExit)
                     TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("2","�������ĂȂ��I�v�V����������") {
            TestSuite::clearCheckpoints();
            chain.renewInstance();

            char * argv[] = { "test.exe", "-test" };
            bool result = false;
            TestComponent test;
            test.activation = true;

            getOptionParameter().parseOption(2, argv);
            Exception::setThrowControl(true);
            try { executeComponents(getOptionParameter()); }
            catch(...) { result = true; }

            BEGIN_CASE("1","��O���N����") {
                if(!result)
                    TEST_FAIL;
                if(!TestSuite::isReached("Exception_UnknownOption"))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","parseOption/onFatalExit�͎��s����邪body�͎��s����Ȃ�") {
                 if(!test.check_parseOption || test.check_body || !test.check_onFatalExit)
                     TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("3","�I�v�V�����p�[�X���ɗ�O (activate�Ȃ�)") {
            chain.renewInstance();

            bool result = false;
            TestComponent test;
            test.throw_parseOption = true;

            Exception::setThrowControl(true);
            try { executeComponents(getOptionParameter()); }
            catch(...) { result = true; }

            BEGIN_CASE("1","��O���N����") {
                if(!result)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","parseOption�͎��s����邪body/onFatalExit�͎��s����Ȃ�") {
                 if(!test.check_parseOption || test.check_body || test.check_onFatalExit)
                     TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("4","�I�v�V�����p�[�X���ɗ�O (activate����)") {
            chain.renewInstance();

            bool result = false;
            TestComponent test;
            test.throw_parseOption = true;
            test.activation = true;

            Exception::setThrowControl(true);
            try { executeComponents(getOptionParameter()); }
            catch(...) { result = true; }

            BEGIN_CASE("1","��O���N����") {
                if(!result)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","parseOption/onFatalExit�͎��s����邪body�͎��s����Ȃ�") {
                 if(!test.check_parseOption || test.check_body || !test.check_onFatalExit)
                     TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("5","body�ŗ�O") {
            chain.renewInstance();

            bool result = false;
            TestComponent test;
            test.throw_body = true;
            test.activation = true;

            Exception::setThrowControl(true);
            try { executeComponents(getOptionParameter()); }
            catch(...) { result = true; }

            BEGIN_CASE("1","��O���N����") {
                if(!result)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","parseOption/body/onFatalExit�Ƃ����s�����") {
                 if(!test.check_parseOption || !test.check_body || !test.check_onFatalExit)
                     TEST_FAIL;
            } END_CASE;
        } END_CASE;


        BEGIN_CASE("6","onFatalExit�ŗ�O") {
            TestSuite::clearCheckpoints();
            chain.renewInstance();

            bool result = false;
            TestComponent test;
            test.throw_onFatalExit = true;
            test.activation = true;
            TestComponent test2;
            test2.throw_body = true;
            test2.activation = true;

            Exception::setThrowControl(true);
            try { executeComponents(getOptionParameter()); }
            catch(...) { result = true; }

            BEGIN_CASE("1","��O���N����") {
                if(!result)
                    TEST_FAIL;
                if(!TestSuite::isReached("Exception_onFatalExit"))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�ŏ��̃R���|�[�l���g��parseOption/body/onFatalExit�Ƃ����s�����") {
                 if(!test.check_parseOption || !test.check_body || !test.check_onFatalExit)
                     TEST_FAIL;
            } END_CASE;
            BEGIN_CASE("3","���̃R���|�[�l���g��parseOption/body/onFatalExit�Ƃ����s�����") {
                 if(!test2.check_parseOption || !test2.check_body || !test2.check_onFatalExit)
                     TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("7","Component::is_valid��false�̂Ƃ��͎��s����Ȃ�") {
            chain.renewInstance();

            bool result = true;
            TestComponent test;
            test.activation = true;

            Component::is_valid = false;
            Exception::setThrowControl(true);
            try { executeComponents(getOptionParameter()); }
            catch(...) { result = false; }

            BEGIN_CASE("1","��O�͋N����Ȃ�") {
                if(!result)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","parseOption/body�͎��s����Ȃ�") {
                 if(test.check_parseOption || test.check_body || test.check_onFatalExit)
                     TEST_FAIL;
            } END_CASE;

            Component::is_valid = true;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("_parseCommonOption","_parseCommonOption") {

        BEGIN_CASE("1", "-debug��DebugMessage���L���ɂȂ�") {
            chain.renewInstance();

            char * argv[] = { "test.exe", "-debug" };
            OptionParameter & param = getOptionParameter();

            param.parseOption(2, argv);
            Component::_parseCommonOption(param);

            if(!DebugMessage::getVerbose())
                TEST_FAIL;

        } END_CASE;

        BEGIN_CASE("2", "-v ��VerboseMessage���L���ɂȂ�") {
            chain.renewInstance();

            char * argv[] = { "test.exe", "-v" };
            OptionParameter & param = getOptionParameter();

            param.parseOption(2, argv);
            Component::_parseCommonOption(param);

            if(!VerboseMessage::getVerbose())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3", "--verbose��VerboseMessage���L���ɂȂ�") {
            chain.renewInstance();

            char * argv[] = { "test.exe", "--verbose" };
            OptionParameter & param = getOptionParameter();

            param.parseOption(2, argv);
            Component::_parseCommonOption(param);

            if(!VerboseMessage::getVerbose())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4", "-lj ��Message�����{��ɂȂ�") {
            chain.renewInstance();

            char * argv[] = { "test.exe", "-lj" };
            OptionParameter & param = getOptionParameter();

            param.parseOption(2, argv);
            Component::_parseCommonOption(param);

            if(Message::getCurrentLanguage() != Message::JAPANESE)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("5", "--japanese ��Message�����{��ɂȂ�") {
            chain.renewInstance();

            char * argv[] = { "test.exe", "--japanese" };
            OptionParameter & param = getOptionParameter();

            param.parseOption(2, argv);
            Component::_parseCommonOption(param);

            if(Message::getCurrentLanguage() != Message::JAPANESE)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("6", "-le ��Message���p��ɂȂ�") {
            chain.renewInstance();

            char * argv[] = { "test.exe", "-le" };
            OptionParameter & param = getOptionParameter();

            param.parseOption(2, argv);
            Component::_parseCommonOption(param);

            if(Message::getCurrentLanguage() != Message::ENGLISH)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("7", "--english ��Message���p��ɂȂ�") {
            chain.renewInstance();

            char * argv[] = { "test.exe", "--english" };
            OptionParameter & param = getOptionParameter();

            param.parseOption(2, argv);
            Component::_parseCommonOption(param);

            if(Message::getCurrentLanguage() != Message::ENGLISH)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("8","�w���v���ł� (-h)") {
            chain.renewInstance();

            char * argv[] = { "test.exe", "-h" };
            OptionParameter & param = getOptionParameter();

            param.parseOption(2, argv);
            cout.str("");
            Component::_parseCommonOption(param);

                //�Ƃ肠���������o�͂���Ă��邱�Ƃ����m�F���Ă���
            if(cout.str().empty())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("9","�w���v���ł� (--help)") {
            chain.renewInstance();

            char * argv[] = { "test.exe", "--help" };
            OptionParameter & param = getOptionParameter();

            param.parseOption(2, argv);
            cout.str("");
            Component::_parseCommonOption(param);

                //�Ƃ肠���������o�͂���Ă��邱�Ƃ����m�F���Ă���
            if(cout.str().empty())
                TEST_FAIL;
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("getOption","�I�v�V�����p�����[�^�̎擾") {
        chain.renewInstance();

        char * argv[] = { "test.exe","-test","param","-test2","param2", "--test","param3","--test2","param4" };
        getOptionParameter().parseOption(9, argv);

        BEGIN_CASE("1","getOption(test)��param������") {
            OptionParameter::OptionItem item;

            item = getOption("test");
            TEST_CASE("1","�L���Ȓl���Ԃ�", item.isValid());
            TEST_CASE("2","�`�F�b�N�ς݂ł���", item.isChecked());
            TEST_CASE("3","1�̃p�����[�^������", item.countParameter() == 1);
            TEST_CASE("4","�p�����[�^�̓��e�������Ă���", item[0].compare("param") == 0);
        } END_CASE;

        BEGIN_CASE("2","getOption(test,test)��2�̘A��������") {
            OptionParameter::OptionItem item;

            TEST_CASE("0","[�O��] --test�Ƀ`�F�b�N�͂��Ă��Ȃ�", !getOptionParameter().get("-test",false).isChecked());

            item = getOption("test","test");

            TEST_CASE("1","�L���Ȓl���Ԃ�", item.isValid());
            TEST_CASE("2","�`�F�b�N�ς݂ł���", item.isChecked());
            TEST_CASE("3","�`�F�b�N�ς݂ł��� (test)", getOptionParameter().get("test",false).isChecked());
            TEST_CASE("4","�`�F�b�N�ς݂ł��� (-test)", getOptionParameter().get("-test",false).isChecked());
            TEST_CASE("5","2�̃p�����[�^������", item.countParameter() == 2);
            TEST_CASE("6","1�߂̃p�����[�^�̒l�͐�����", item[0].compare("param") == 0);
            TEST_CASE("7","2�߂̃p�����[�^�̒l�͐�����", item[1].compare("param3") == 0);
        } END_CASE;

        BEGIN_CASE("3","getOption(test,unknown)��test�̃p�����[�^������") {
            OptionParameter::OptionItem item;

            item = getOption("test","unknown");

            TEST_CASE("1","�L���Ȓl���Ԃ�", item.isValid());
            TEST_CASE("2","1�̃p�����[�^������", item.countParameter() == 1);
            TEST_CASE("3","�p�����[�^�̒l�͐�����", item[0].compare("param") == 0);
        } END_CASE;

        BEGIN_CASE("4","getOption(unknown,test)�� -test�̃p�����[�^������") {
            OptionParameter::OptionItem item;

            item = getOption("unknown","test");

            TEST_CASE("1","�L���Ȓl���Ԃ�", item.isValid());
            TEST_CASE("2","1�̃p�����[�^������", item.countParameter() == 1);
            TEST_CASE("3","�p�����[�^�̒l�͐�����", item[0].compare("param3") == 0);
        } END_CASE;

        BEGIN_CASE("5","getOption(unknown,unknown)�Ŗ����ȃA�C�e�����Ԃ�") {
            OptionParameter::OptionItem item;

            item = getOption("unknown","unknown");

            TEST_CASE("1","�����Ȓl���Ԃ�", !item.isValid());
        } END_CASE;

        BEGIN_CASE("6","getOption(test2,test2,false)�Ń`�F�b�N�����Ȃ�") {
            OptionParameter::OptionItem item;

            TEST_CASE("0","[�O��] -test2�Ƀ`�F�b�N�͂��Ă��Ȃ�", !getOptionParameter().get("test2",false).isChecked());
            TEST_CASE("0","[�O��] --test2�Ƀ`�F�b�N�͂��Ă��Ȃ�", !getOptionParameter().get("-test2",false).isChecked());

            item = getOption("test2","test2",false);

            TEST_CASE("1","�L���Ȓl���Ԃ�", item.isValid());
            TEST_CASE("2","�`�F�b�N�ς݂łȂ�", !item.isChecked());
            TEST_CASE("3","�`�F�b�N�ς݂łȂ� (test2)", !getOptionParameter().get("test2",false).isChecked());
            TEST_CASE("4","�`�F�b�N�ς݂łȂ� (-test2)", !getOptionParameter().get("-test2",false).isChecked());
            TEST_CASE("5","2�̃p�����[�^������", item.countParameter() == 2);
            TEST_CASE("6","1�߂̃p�����[�^�̒l�͐�����", item[0].compare("param2") == 0);
            TEST_CASE("7","2�߂̃p�����[�^�̒l�͐�����", item[1].compare("param4") == 0);
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("findOption","�I�v�V�����p�����[�^�̎擾") {
        chain.renewInstance();

        char * argv[] = { "test.exe","-test","param","--test","param3", "-noparam"};
        getOptionParameter().parseOption(6, argv);

        BEGIN_CASE("1","findOption(test,test)��param������") {
            string result;

            TEST_CASE("0","[�O��] �`�F�b�N�ς݂ł͂Ȃ� (test)", !getOptionParameter().get("test",false).isChecked());
            TEST_CASE("0","[�O��] �`�F�b�N�ς݂ł͂Ȃ� (-test)", !getOptionParameter().get("-test",false).isChecked());
            TEST_CASE("1","�֐��͐�������", findOption("test","test",&result));
            TEST_CASE("2","�������param���Ԃ�", result.compare("param") == 0);
            TEST_CASE("3","�`�F�b�N�ς� (test)", getOptionParameter().get("test",false).isChecked());
            TEST_CASE("3","�`�F�b�N�ς� (-test)", getOptionParameter().get("-test",false).isChecked());
        } END_CASE;

        BEGIN_CASE("2","findOption(test,unknown)��param������") {
            string result;

            TEST_CASE("1","�֐��͐�������", findOption("test","unknown",&result));
            TEST_CASE("2","�������param���Ԃ�", result.compare("param") == 0);
        } END_CASE;

        BEGIN_CASE("3","findOption(unknown,test)��param3������") {
            string result;

            TEST_CASE("1","�֐��͐�������", findOption("unknown","test",&result));
            TEST_CASE("2","�������param���Ԃ�", result.compare("param3") == 0);
        } END_CASE;

        BEGIN_CASE("4","findOption(unknown,unknown)�Ŗ����ȃA�C�e�����Ԃ�") {
            string result;

            result.assign("dummy");

            TEST_CASE("1","�֐��͎��s����", !findOption("unknown","unknown",&result));
            TEST_CASE("2","������͏��������Ȃ�", result.compare("dummy") == 0);
        } END_CASE;

        BEGIN_CASE("5","findOption(noparam,NULL,&result)") {
            string result;
            result.assign("dummy");

            TEST_CASE("1","�֐��͐�������", findOption("noparam", 0, &result));
            TEST_CASE("2","������͒u�������Ȃ�", result.compare("dummy") == 0);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("checkOption","�I�v�V�����p�����[�^�̑��݊m�F + �`�F�b�N") {
        chain.renewInstance();

        char * argv[] = { "test.exe","-test","param","--test","param3", "-test2", "--test3"};
        getOptionParameter().parseOption(7, argv);

        BEGIN_CASE("1","checkOption(test,test)��param������") {
            string result;

            TEST_CASE("0","[�O��] �`�F�b�N�ς݂ł͂Ȃ� (test)", !getOptionParameter().get("test",false).isChecked());
            TEST_CASE("0","[�O��] �`�F�b�N�ς݂ł͂Ȃ� (-test)", !getOptionParameter().get("-test",false).isChecked());
            TEST_CASE("1","�֐��͐�������", checkOption("test","test"));
            TEST_CASE("2","�`�F�b�N�ς� (test)", getOptionParameter().get("test",false).isChecked());
            TEST_CASE("3","�`�F�b�N�ς� (-test)", getOptionParameter().get("-test",false).isChecked());
        } END_CASE;

        BEGIN_CASE("2","checkOption(test2,unknown)��param������") {
            string result;

            TEST_CASE("0","[�O��] �`�F�b�N�ς݂ł͂Ȃ� (test2)", !getOptionParameter().get("test2",false).isChecked());
            TEST_CASE("1","�֐��͐�������", checkOption("test2","unknown"));
            TEST_CASE("2","�`�F�b�N�ς� (test2)", getOptionParameter().get("test2",false).isChecked());
        } END_CASE;

        BEGIN_CASE("3","checkOption(unknown,test3)��param3������") {
            string result;

            TEST_CASE("0","[�O��] �`�F�b�N�ς݂ł͂Ȃ� (test3)", !getOptionParameter().get("-test3",false).isChecked());
            TEST_CASE("1","�֐��͐�������", checkOption("unknown","test3"));
            TEST_CASE("2","�`�F�b�N�ς� (test3)", getOptionParameter().get("-test3",false).isChecked());
        } END_CASE;

        BEGIN_CASE("4","checkOption(unknown,unknown)�Ŗ����ȃA�C�e�����Ԃ�") {
            string result;

            result.assign("dummy");

            TEST_CASE("1","�֐��͎��s����", !checkOption("unknown","unknown"));
        } END_CASE;
    } END_CASE;

        /* mergeOption�̃`�F�b�N���ڂ́AgetOption�Ƃقړ��� */
    BEGIN_CASE("mergeOption","�I�v�V�����p�����[�^�̌���") {
        chain.renewInstance();

        char * argv[] = { "test.exe","-test","param","-test2","param2", "--test","param3","--test2","param4" };
        getOptionParameter().parseOption(9, argv);

        BEGIN_CASE("1","mergeOption(test)��param������") {
            OptionParameter::OptionItem item;

            item = mergeOption("test");
            TEST_CASE("1","�L���Ȓl���Ԃ�", item.isValid());
            TEST_CASE("2","�`�F�b�N�ς݂ł���", item.isChecked());
            TEST_CASE("3","1�̃p�����[�^������", item.countParameter() == 1);
            TEST_CASE("4","�p�����[�^�̓��e�������Ă���", item[0].compare("param") == 0);
        } END_CASE;

        BEGIN_CASE("2","mergeOption(test,test)��2�̘A��������") {
            OptionParameter::OptionItem item;

            TEST_CASE("0","[�O��] --test�Ƀ`�F�b�N�͂��Ă��Ȃ�", !getOptionParameter().get("-test",false).isChecked());

            item = mergeOption("test","test");

            TEST_CASE("1","�L���Ȓl���Ԃ�", item.isValid());
            TEST_CASE("2","�`�F�b�N�ς݂ł���", item.isChecked());
            TEST_CASE("3","�`�F�b�N�ς݂ł��� (test)", getOptionParameter().get("test",false).isChecked());
            TEST_CASE("4","�`�F�b�N�ς݂ł��� (-test)", getOptionParameter().get("-test",false).isChecked());
            TEST_CASE("5","2�̃p�����[�^������", item.countParameter() == 2);
            TEST_CASE("6","1�߂̃p�����[�^�̒l�͐�����", item[0].compare("param") == 0);
            TEST_CASE("7","2�߂̃p�����[�^�̒l�͐�����", item[1].compare("param3") == 0);
        } END_CASE;

        BEGIN_CASE("3","mergeOption(test,unknown)��test�̃p�����[�^������") {
            OptionParameter::OptionItem item;

            item = mergeOption("test","unknown");

            TEST_CASE("1","�L���Ȓl���Ԃ�", item.isValid());
            TEST_CASE("2","1�̃p�����[�^������", item.countParameter() == 1);
            TEST_CASE("3","�p�����[�^�̒l�͐�����", item[0].compare("param") == 0);
        } END_CASE;

        BEGIN_CASE("4","mergeOption(unknown,test)�� -test�̃p�����[�^������") {
            OptionParameter::OptionItem item;

            item = mergeOption("unknown","test");

            TEST_CASE("1","�L���Ȓl���Ԃ�", item.isValid());
            TEST_CASE("2","1�̃p�����[�^������", item.countParameter() == 1);
            TEST_CASE("3","�p�����[�^�̒l�͐�����", item[0].compare("param3") == 0);
        } END_CASE;

        BEGIN_CASE("5","mergeOption(unknown,unknown)�Ŗ����ȃA�C�e�����Ԃ�") {
            OptionParameter::OptionItem item;

            item = mergeOption("unknown","unknown");

            TEST_CASE("1","�����Ȓl���Ԃ�", !item.isValid());
        } END_CASE;

    } END_CASE;

    chain.restoreContext();
}
#endif


