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
 *  @(#) $Id: singleton.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/singleton.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/testsuite.h"

#ifndef SINGLETON_H
#define SINGLETON_H

#ifdef _MSC_VER
#  pragma warning(disable:4290) //C++ �̗�O�̎w��͖�������܂��B�֐��� __declspec(nothrow) �łȂ����Ƃ̂ݕ\������܂��B
#  pragma warning(disable:4291) //�������R�|�h����O���X���|����ƁA'new' ���Z�q���g�p���Ă���ƃ�������������܂���B
#  pragma warning(disable:4786) //�f�o�b�O���Ŏ��ʎq�� 255 �����ɐ؂�̂Ă��܂����B
#endif

#include <new>
#include <stdexcept>

/*
 *  �V���O���g���p�^�[�� ����
 */

    //�V���O���g�����N���X
    //  #gcc��friend class Singleton��H���Ă���Ȃ��̂Ŋ������
class SingletonBase {
public:
        //�f�X�g���N�^�̃`�F�[��
    struct chain {
        struct chain * next;
        void (*destructor)(void);
    };

        //�V���O���g���ŃC���X�^���X�𐶐��������Ƃ��������߂̃N���X
        //    ���̃N���X��Singleton���炵�����̉��ł��Ȃ��̂ŁA
        //    �ق��̃N���X���炱��������ɂ��R���X�g���N�^���g�p���邱�Ƃ͂ł��Ȃ�
    class SingletonConstructionLocker
    {
    friend class SingletonBase;
    protected:
        SingletonConstructionLocker() {}
    };

private:
    static bool   initialize;       //�������ς݂� (atexit���Ă񂾂��ǂ���)
    static bool   is_valid;         //�����Ɏ��s�����V���O���g���K���邩�ǂ���
    static struct chain * top;      //�f�X�g���N�^�`�F�[��

        //�f�X�g���N�^�̋N��
    static void final_release(void) throw()
    {
            //�擪����폜 (������o��)
        while(top != 0) {
            struct chain * node = top;
            top = node->next;

            (*node->destructor)();

            delete node;
        }
    }

protected:
        //�`�F�[���Ƀf�X�g���N�^��ǉ�
    static bool addDestructor(void (* destructor)(void)) throw()
    {
        bool result = false;
        struct SingletonBase::chain * node = new(std::nothrow) struct SingletonBase::chain;
        if(node != 0) {

                //�V�����v�f��擪�ɒǉ�
            node->next       = top;
            node->destructor = destructor;
            
            top = node;

            result = true;

                //�v�f�j���̂��߂ɍŌ�ɔj�����[�`�����N��������
            if(!initialize) {
                atexit(final_release);
                initialize = true;
            }
        }
        return result;
    }

        //SingletonConstructionLocker�t�@�N�g��
    inline static SingletonConstructionLocker getLocker(void)
    {   return SingletonConstructionLocker();   }

public:
        //�����Ɏ��s�����V���O���g�����Ȃ����Ƃ��擾
    static bool isValid(void) throw()
    {   return is_valid;   }

#ifdef TESTSUITE
        /*
         *   �R���e�L�X�g�`�F�[�� (�e�X�g�p�V���O���g���R���e�L�X�g�ޔ��`�F�[��)
         */
    class ContextChain {
    protected:
        struct chain {
            struct chain * next;
            void * context;
            void (*restore)(void * & context) throw();
            void (*renew)(void) throw();
            void (*clear)(void);
        } * top;

    public:
        ContextChain(void) throw() : top(0)
        {}

        ~ContextChain(void) throw()
        {   restoreContext();   }

            /* �R���e�L�X�g�̕��A */
        void restoreContext(void) throw()
        {
            while(top != 0) {
                struct chain * node = top;
                top = top->next;

                (*node->restore)(node->context);
                delete node;
            }
        }

            /* �S�ẴC���X�^���X���Đ��� */
        void renewInstance(void) throw(std::bad_alloc)
        {
            struct chain * node = top;
            while(node != 0) {
                (*node->renew)();
                node = node->next;
            }
        }
            
            /* �S�ẴC���X�^���X��j�� */
        void clearInstance(void) throw(std::bad_alloc)
        {
            struct chain * node = top;
            while(node != 0) {
                (*node->clear)();
                node = node->next;
            }
        }
            
            /* �R���e�L�X�g�̑ޔ� */
        template<class T> void saveContext(void) throw(std::bad_alloc)
        {
            struct chain * node = new struct chain;

            node->next = top;
            node->restore = reinterpret_cast<void(*)(void*&)>(Singleton<T>::restoreContext);
            node->renew   = Singleton<T>::renewInstance;
            node->clear   = Singleton<T>::clearInstance;

            Singleton<T>::saveContext(reinterpret_cast<Singleton<T>::Context &>(node->context));

            top = node;
        }
    };
#endif


    TESTSUITE_PROTOTYPE(main)
};


template<class T>
class Singleton : SingletonBase
{
protected:
    Singleton(void);
    ~Singleton(void);

    static T * instance;

        //�f�X�g���N�^
    static void destructor(void) throw()
    {
        if(instance != 0) {
            try{ delete instance; } catch(...) {}
            instance = 0;
        }
    }

        //�C���X�^���X�̐��� (�C���X�^���X���� + �f�X�g���N�^�o�^ + �G���[����)
    static T * createInstance(std::nothrow_t) throw()
    {
        T * instance = 0;
        try {
            instance = new(std::nothrow) T(getLocker());

            if(instance != 0) {
                if(!addDestructor(destructor))
                    throw false;    //catch�߂����s��������
            }
        }
        catch(...) {
            if(instance != 0) {
                try { delete instance; } catch(...) {}
                instance = 0;
            }
        }
        return instance;
    }

        //�C���X�^���X���� (bad_alloc��O���X���[�������)
    static T * createInstance(void) throw(std::bad_alloc)
    {
        instance = createInstance(std::nothrow);
        if(instance == 0)
            throw std::bad_alloc();
        return instance;
    }

public:
        //�C���X�^���X�̎擾
    inline static T * getInstance(void) throw(std::bad_alloc)
    {
        if(instance == 0)
            instance = createInstance();
        return instance;
    }

        //�C���X�^���X�̎擾
    inline static T * getInstance(std::nothrow_t) throw()
    {
        if(instance == 0)
            instance = createInstance(std::nothrow);
        return instance;
    }

#ifdef TESTSUITE    /* �e�X�g�p */

    typedef T * Context;    //�ޔ�p

        //�V�����C���X�^���X�̐���
    static void renewInstance(void) throw(std::bad_alloc)
    {
        destructor();                     //���̃C���X�^���X��j��
        instance = new T(getLocker());    //�V�����C���X�^���X�𐶐� (�f�X�g���N�^���o�^����Ă��܂��̂�createInstance���Ă�ł͂����Ȃ�)
    }

        //�C���X�^���X�j��
    static void clearInstance(void) throw()
    {   destructor();   }

        //�R���e�L�X�g�ޔ�
    static void saveContext(Context & context) throw()
    {
        context  = instance;
        instance = 0;
    }

        //�R���e�L�X�g���A
    static void restoreContext(Context & context) throw()
    {
        destructor();           //���̃C���X�^���X��j��
        instance = context;     //�ޔ������C���X�^���X�𕜋A
    }

#endif /* TESTSUITE */

};



    //Singleton �ÓI�ϐ�
template<class T> T * Singleton<T>::instance = 0;

#define SINGLETON_CONSTRUCTOR(x)  explicit x(const SingletonBase::SingletonConstructionLocker &)
#define SINGLETON_CONSTRUCTOR_(x) explicit x(const SingletonBase::SingletonConstructionLocker & _singleton)

#define SINGLETON_WRAPPER(derived, base) class derived : public base { public: SINGLETON_CONSTRUCTOR_(derived) throw() : base(_singleton) {} };

#endif /* SINGLETON_H */

