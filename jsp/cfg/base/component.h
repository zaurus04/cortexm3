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
 *  @(#) $Id: component.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/component.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/testsuite.h"
#include "base/singleton.h"
#include "base/except.h"
#include "base/message.h"
#include "base/option.h"
#include "base/collection.h"
#include "base/directorymap.h"

#include <list>
#include <map>

#ifndef COMPONENT_H
#define COMPONENT_H

class Component : public RuntimeObject
{
public:
        //�R���|�[�l���g�̋N���D��x
    enum tagProcessStage {
        INITIALIZE,                 //�Ƃɂ����^����ɓ�����������

        BEFORE_PARSE,               //�p�[�X�O
        PARSER,                     //�p�[�T
        AFTER_PARSE,                //�p�[�X��

        PREDECESSOR,                //�ėp�̑O
        GENERAL_PURPOSE,            //�ėp
        SUCCESSOR,                  //�ėp�̌�

        BEFORE_CODEGENERATION,      //�R�[�h�����O
        CODEGENERATOR,              //�R�[�h����
        AFTER_CODEGENERATION,       //�R�[�h������

        FINALIZE
    };

        //�R���|�[�l���g�ɋ��ʂ̃f�[�^������/���삷��N���X
    class ComponentInfo
    {
    protected:
        std::string                     banner;
        std::multimap<int, Component *> componentList;
        std::list<Component *>          activatedComponentList;

            //�R���X�g���N�^ (�e�X�g�p)
        ComponentInfo(void) throw() {}
    public:
            //�R���X�g���N�^
        SINGLETON_CONSTRUCTOR(ComponentInfo) {}

            //�R���|�[�l���g�̒ǉ�
        bool addComponent(Component * component, int order) throw();

            //�R���|�[�l���g�̓o�^����
        void removeComponent(Component * component, int order) throw();     //����̗D��x����������
        void removeComponent(Component * component) throw();                //�S�ĉ���

            //�R���|�[�l���g�̋N���v��
        bool activateComponent(Component * component) throw();

            //�I�v�V�����̃p�[�X
        void parseOption(OptionParameter & option);

            //�R���|�[�l���g�̋N��
        void activateComponent(void);

            //�ُ폈���n���h���̋N��
        void onFatalExit(void);

            //�R���|�[�l���gT���N�����Ă��邩�𔻒�
        template<class T>
        bool isActive(void) const throw()
        {
            std::list<Component *>::const_iterator scope;

            scope = activatedComponentList.begin();
            while(scope != activatedComponentList.end()) {
                if(dynamic_cast<T *>(*scope) != 0)
                    return true;
                ++ scope;
            }
            return false;
        }

            //�o�i�[�ϐ��ւ̃A�N�Z�T
        inline void setBanner(std::string src)
        {   banner = src;    }
        inline std::string getBanner(void) const
        {   return banner;   }


        TESTSUITE_PROTOTYPE(main)
    };


protected:
    static bool is_valid;       //�R���|�[�l���g�̏������ɐ����������ǂ��������t���O

    /*
     *   ��Ɗ֐�
     */

        //�R���|�[�l���g�̋N��
    inline bool activateComponent(void) throw()
    {   return Singleton<ComponentInfo>::getInstance()->activateComponent(this);   }

        //��ʓI�ȃI�v�V�����̏���
    static void _parseCommonOption(OptionParameter & option) throw();


        //�����ɐ�s����R���|�[�l���g�̋N������
    template<class T>
    static bool isActive(void) throw()
    {   
        bool result = false;
        ComponentInfo * info = Singleton<ComponentInfo>::getInstance(std::nothrow);
        if(info != 0)
            result = info->isActive<T>();
        return result;
    }


        /*
         *   �ߋ��Ƃ̌݊����̂��߂̃p�����[�^����API
         */

    static bool findOption (const char * key1, const char * key2 = 0, std::string * = 0) throw();
    static bool checkOption(const char * key1, const char * key2 = 0) throw();
    static OptionParameter::OptionItem getOption  (const char * key1, const char * key2 = 0, bool dirty = true) throw();
    static OptionParameter::OptionItem mergeOption(const char * key1, const char * key2 = 0) throw();

public:
        //�R���X�g���N�^
    Component(int order = GENERAL_PURPOSE) throw();

        //�f�X�g���N�^
    virtual ~Component(void) throw();

        //�L������
    static bool isValid(void) throw()
    {   return is_valid && SingletonBase::isValid();   }

        //�R���|�[�l���g�̎��s
    static void executeComponents(OptionParameter & option);
    static void executeComponents(int argc, char * argv []);

        //�o�i�[�A�N�Z�T
    static void        setBanner(std::string) throw(std::bad_alloc);
    static std::string getBanner(void)        throw(std::bad_alloc);

    /*
     *   �C�x���g�n���h��
     */

        //�I�v�V�����̃p�[�X
    virtual void parseOption(OptionParameter &)
    { parseOption(*Singleton<Directory>::getInstance()); }
    
    virtual void parseOption(Directory &) {}

        //�R���|�[�l���g�̖{��
    virtual void body(void)        { body(*Singleton<Directory>::getInstance()); }
    virtual void body(Directory &) {}

        //�ُ�I���n���h��
    virtual void onFatalExit(void) {}



    TESTSUITE_PROTOTYPE(main)
};


#endif



