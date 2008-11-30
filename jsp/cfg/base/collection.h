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
 *  @(#) $Id: collection.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/collection.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef COLLECTION_H
#define COLLECTION_H

#include "base/testsuite.h"
#include "base/singleton.h"

#include <typeinfo>
#include <list>

    //Collection�ɓo�^�������I�u�W�F�N�g�̃N���X�̊��N���X
class Collectable
{
public:
             Collectable(void) throw() {}   //���ɉ������Ȃ�
    virtual ~Collectable(void) throw() {}   //���ɉ������Ȃ�
};



    //����^�̃C���X�^���X��o�^���ĕێ����邽�߂̃N���X
class Collection
{
public:
    struct Element
    {
        Collectable * instance;
        bool          destruction;
    };

protected:
    std::list<Element> container;

        //predecessor�̎����w���C�e���[�^�𓾂� (getInstance)
    std::list<Element>::const_iterator _findInstance(const Collectable * predecesor) const throw();

public:
        //�R���X�g���N�^ & �f�X�g���N�^
             Collection(void)  throw();
    virtual ~Collection(void) throw();

        //�L������
    inline bool isValid(void) const throw()
    {   return this != 0;   }

        //�R���N�V�����ւ̒ǉ� (�|�C���^�p)
    bool addInstance(Collectable * instance, bool destruction = true)  throw();
    
        //�R���N�V�����ւ̒ǉ� (���̗p)
    inline bool addInstance(Collectable & instance, bool destruction = false) throw()
    {   return addInstance(&instance, destruction);   }

        //�R���N�V��������̎擾 (���S��v)
    Collectable * getInstance(const std::type_info & type, const Collectable * predecessor = 0) const throw();

        //�R���N�V��������̎擾 (�h���������̂��T�[�`)
    template<class T> T * getInstance(const Collectable * predecessor = 0) const throw()
    {
        T * result = 0;

        if(isValid()) {
            std::list<Element>::const_iterator iterator = _findInstance(predecessor);

            while(iterator != container.end()) {
                result = dynamic_cast<T *>(iterator->instance);
                if(result != 0)
                    break;
                ++ iterator;
            }
        }
        return result;
    }

        //�R���N�V��������h������܂ޑS�ẴN���X�C���X�^���X���폜 (�j���Ώۂ̏ꍇ�͔j�����s��)
    template<class T> void deleteInstance(void) throw()
    {
        if(isValid()) {
            std::list<Element>::iterator iterator;

            iterator = container.begin();
            while(iterator != container.end()) {
                if(dynamic_cast<T *>(iterator->instance) != 0) {

                        //�폜�ΏۂȂ�C���X�^���X���폜
                    if(iterator->destruction)
                        delete iterator->instance;

                        //���X�g���珜�O
                    std::list<Element>::iterator target = iterator;
                    ++ iterator;
                    container.erase(target);
                }
                else
                    ++ iterator;
            }
        }
    }

        //�֘A�t����ꂽ�C���X�^���X�����ւ���
    template<class T> inline bool replaceInstance(Collectable * instance, bool destruction = true) throw()
    {
            //�����Ɩ��֌W�ȃN���X�̓C���f�b�N�X�Ƃ��Ďw��ł��Ȃ�
        if(dynamic_cast<T *>(instance) == 0)
            return false;

        deleteInstance<T>();
        return addInstance(instance, destruction);
    }

        //�֘A�t����ꂽ�C���X�^���X�����ւ���
    template<class T> inline bool replaceInstance(Collectable & instance, bool destruction = false) throw()
    {
            //�����Ɩ��֌W�ȃN���X�̓C���f�b�N�X�Ƃ��Ďw��ł��Ȃ�
        if(dynamic_cast<T *>(&instance) == 0)
            return false;

        deleteInstance<T>();
        return addInstance(&instance, destruction);
    }


        //�R���N�V��������C���X�^���X�����O (�j���͂��Ȃ�)
    bool removeInstance(const Collectable * instance) throw();

        //�S�v�f�̔j��
    void clear(void);

    TESTSUITE_PROTOTYPE(main)
};


    //���s���I�u�W�F�N�g�Q�ƃe�[�u��
class RuntimeObjectTable : protected Collection
{
friend class RuntimeObject;
public:
    SINGLETON_CONSTRUCTOR(RuntimeObjectTable) throw() {}

    static Collectable * getInstance(const std::type_info & type, const Collectable * predecessor = 0) throw()
    {
        RuntimeObjectTable * table = Singleton<RuntimeObjectTable>::getInstance(std::nothrow);
        Collectable * result = 0;

        if(table != 0)
            result = table->Collection::getInstance(type, predecessor);
        return result;
    }

        //�R���N�V��������̎擾 (�h���������̂��T�[�`)
    template<class T> static T * getInstance(const Collectable * predecessor = 0) throw()
    {
        RuntimeObjectTable * table = Singleton<RuntimeObjectTable>::getInstance();
        T * result = 0;

        if(table != 0) {
            std::list<Element>::const_iterator iterator = table->_findInstance(predecessor);

            while(iterator != table->container.end()) {
                result = dynamic_cast<T *>(iterator->instance);
                if(result != 0)
                    break;
                ++ iterator;
            }
        }
        return result;
    }

        /* Visual C++ 6.0 Fatal error C1001�΍� */
    template<class T> static T * getInstance(T ** dest, const Collectable * predecessor = 0) throw()
    {
        RuntimeObjectTable * table = Singleton<RuntimeObjectTable>::getInstance();
        T * result = 0;

        if(table != 0) {
            std::list<Element>::const_iterator iterator = table->_findInstance(predecessor);

            while(iterator != table->container.end()) {
                result = dynamic_cast<T *>(iterator->instance);
                if(result != 0)
                    break;
                ++ iterator;
            }
        }
        if(dest != 0)
            *dest = result;

        return result;
    }

    TESTSUITE_PROTOTYPE(main)
};

    //���s���I�u�W�F�N�g
class RuntimeObject : public Collectable
{
public:
    RuntimeObject(bool destruction = false) throw()
    {
        RuntimeObjectTable * table = Singleton<RuntimeObjectTable>::getInstance();
        if(table != 0)
            table->addInstance(this, destruction);
    }

    virtual ~RuntimeObject(void) throw()
    {
        RuntimeObjectTable * table = Singleton<RuntimeObjectTable>::getInstance();
        if(table != 0)
            table->removeInstance(this);
    }
};

    /* �� fatal error C1001: INTERNAL COMPILER ERROR (msc1.cpp:1794) */
#if _MSC_VER < 1300 
#  define getRuntimeObjectInstance(x) (dynamic_cast<x *>(RuntimeObjectTable::getInstance(typeid(x))))       //���m�ɂ͓��߂ł͂Ȃ����A����œ����邵���Ȃ�
#else
#  define getRuntimeObjectInstance(x) (RuntimeObjectTable::getInstance<x>())
#endif


#endif



