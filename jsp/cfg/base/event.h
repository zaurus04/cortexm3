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
 *  @(#) $Id: event.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/event.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef EVENT_H
#define EVENT_H

#include "base/testsuite.h"
#include "base/singleton.h"

#include <list>

    //�C�x���g�t�b�N�̎��܂Ƃߖ�
template<typename T>
class Event
{
public:
    typedef void (*handler_type)(T &);

    class handler_list_type : public std::list<handler_type>
    {   public: SINGLETON_CONSTRUCTOR(handler_list_type) throw() {}   };

    /*
     *   �N���X�̒��̃n���h���p
     */

    class Handler
    {
    friend class Event;
    public:
        class instance_list_type : public std::list<Handler *>
        {   public: SINGLETON_CONSTRUCTOR(instance_list_type) throw() {}   };

        virtual void handler(T & ev) = 0;

    protected:
            //�o�^
        Handler(void) throw()
        {   Singleton<instance_list_type>::getInstance()->push_back(this);   }
        
            //�o�^����
        virtual ~Handler(void) throw()
        {
            typename Event<T>::Handler::instance_list_type * list = Singleton<instance_list_type>::getInstance(std::nothrow);
            typename Event<T>::Handler::instance_list_type::iterator scope;

            if(list != 0) {
                scope = list->begin();
                while(scope != list->end()) {
                    if(*scope == this) {
                        typename Event<T>::Handler::instance_list_type::iterator target = scope;
                        ++ scope;
                        list->erase(target);
                    }
                    else
                        ++ scope;
                }
            }
        }
    };

public:
    typedef T value_type;

    Event(void) {}
    virtual ~Event(void) {}

    /*
     *  �X�^�e�B�b�N�ȃn���h���p
     */

        //�C�x���g�Ƀn���h����ǉ�
    inline static void add(handler_type func) throw(std::bad_alloc)
    {   Singleton<handler_list_type>::getInstance()->push_back(func);   }

        //�C�x���g����n���h�����폜
    static void remove(handler_type func) throw()
    {
        typename Event<T>::handler_list_type * list;
        typename Event<T>::handler_list_type::iterator scope;

        list = Singleton<handler_list_type>::getInstance(std::nothrow);
        if(list != 0) {
            scope = list->begin();
            while(scope != list->end()) {
                if(*scope == func) {
                    typename handler_list_type::iterator target = scope;
                    ++ scope;
                    list->erase(target);
                }
                else
                    ++ scope;
            }
        }
    }

    /*
     *  ���ʑ���
     */
        //�C�x���g�̔���
    static void raise(T & ev)
    {
            typedef typename Event<T>::handler_list_type handler_list_type_t; 
            typedef typename Event<T>::Handler::instance_list_type instance_list_type_t;

        /* �o�^���ꂽ�ÓI�Ȋ֐��ɃC�x���g�𔭍s */ {
           handler_list_type_t * list;
            typename handler_list_type_t::iterator scope;

            list = Singleton<handler_list_type_t>::getInstance();   //throw(bad_cast)

            scope = list->begin();
            while(scope != list->end()) {
                (**scope)(ev);
                ++ scope;
            }
        }

        /* �o�^���ꂽ�N���X�C���X�^���X�ɃC�x���g�𔭍s */ {
            instance_list_type_t * list;
            typename instance_list_type_t::iterator scope;

            list = Singleton<instance_list_type_t>::getInstance();  //throw(bad_cast)

            scope = list->begin();
            while(scope != list->end()) {
                (*scope)->handler(ev);
                ++ scope;
            }
        }
    }

        //�C�x���g�̔��� (�����Ȃ�)
    inline static void raise(void)
    {
        T ev;
        raise(ev);
    }
};


    /*
     *  �ėp�C�x���g
     */

    //�R���X�g���N�^���N�����I��������ƁA�^����ɋN��C�x���g
class StartupEvent {};


    //�������s���킸�A�v���O�������I���Ƃ��ɋN��C�x���g
struct ShutdownEvent
{
    int exit_code;
};

#endif



