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
 *  @(#) $Id: filecontainer.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/filecontainer.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef FILECONTAINER_H
#define FILECONTAINER_H

#ifdef _MSC_VER
#pragma warning(disable:4786) //�f�o�b�O����255�����ɐ؂�l�߂܂���
#endif

#include "testsuite.h"

#include <string>
#include <map>

#include "base/except.h"
#include "base/message.h"
#include "base/collection.h"

class FileContainer : public RuntimeObject
{
public:
    typedef unsigned long address_t;

    struct tagVariableInfo {
        address_t  address;
        union {
            size_t     size;
            int        value;
        };
    };

    enum tagByteOrder { LITTLE, BIG, HOSTORDER=LITTLE, UNKNOWN };   /* UNKNOWN�̓e�X�g�p */

protected:
    enum tagByteOrder byteorder;

    std::map<std::string, struct tagVariableInfo> variableinfo;

    FileContainer(void) throw() : byteorder(HOSTORDER) {}
    virtual ~FileContainer(void) throw() {}

public:
        /* �C���^�t�F�[�X�� */
    virtual void                    attachModule(const std::string & filename) throw(Exception) = 0;
    virtual void                    loadContents(void * dest, address_t address, size_t size) throw(Exception) = 0;
    virtual address_t               getSymbolAddress(const std::string & symbol) throw(Exception) = 0;
    virtual std::string             getArchitecture(void) throw(Exception) = 0;

    virtual struct tagVariableInfo  getVariableInfo(const std::string & name) throw(Exception);
    virtual void                    attachInfo(const std::string & filename) throw(Exception);

        /* �o�^����Ă���R���e�i�̌Ăяo�� */
    static inline FileContainer * getInstance(void) throw(Exception)
    {
        FileContainer * result;
        RuntimeObjectTable::getInstance(&result);
        if(result == 0)
            ExceptionMessage("[Internal error] Filecontainer has no instance.","[�����G���[] FileContainer�̃C���X�^���X������܂���").throwException();
        return result;
    }

    enum tagByteOrder getByteOrder(void) const
    {   return byteorder;   }
};

class TargetVariableBase
{
protected:
    FileContainer::address_t address;               //�ϐ��̃A�h���X
    size_t                   size;                  //�ϐ��̃T�C�Y
    size_t                   offset;                //������\���̂̐擪����̃I�t�Z�b�g
    size_t                   structure_size;        //������\���̂̑傫��
    bool                     loaded;                //�l���Ǐo���ς݂ł��邱�Ƃ�ێ�����t���O

    inline TargetVariableBase(FileContainer::address_t _address, size_t _size) throw()
        : address(_address), size(_size), offset(0), structure_size(_size), loaded(false)
    {}

    inline TargetVariableBase(FileContainer::address_t addr, size_t sz, size_t ofs, size_t ssz) throw()
        : address(addr), size(sz), offset(ofs), structure_size(ssz), loaded(false)
    {}
    
    TargetVariableBase(const std::string & sym) throw();
    TargetVariableBase(const std::string & sym, size_t _size) throw();
    TargetVariableBase(const std::string & sym, const std::string & sz) throw();
    TargetVariableBase(const TargetVariableBase & src) throw();

    virtual ~TargetVariableBase(void) throw() {}

        /* ���e�̎擾 */
    void loadContent(void * dest, size_t dest_size) throw(Exception);

        /* �G���f�B�A���ϊ� */
    void changeEndian(char * buffer, size_t size) throw();

        /* �A�h���X�̈ړ� (���ł�loaded��������) */
    inline void setAddress(int offset) throw()
    {
        if(isValid()) {
            address += offset;
            loaded   = false;
        }
    }

public:
    inline bool isValid(void) const throw()
    {   return this != 0 && address != 0 && size != 0 && structure_size != 0;   }

    inline size_t getSize(void) const throw()
    {   return this != 0 ? size : 0;   }

    inline size_t getOffset(void) const throw()
    {   return this != 0 ? offset : 0;   }

    inline size_t getStructureSize(void) const throw()
    {   return this != 0 ? structure_size : 0;   }

    inline FileContainer::address_t getAddress(void) const throw()
    {   return this != 0 ? address : 0;   }

    inline bool isLoaded(void) const throw()
    {   return this != 0 ? loaded : false;   }

        /* ��{�I�ȑ��� */
    inline bool operator == (const TargetVariableBase & right) const throw()
    {   return isValid() && right.isValid() && address == right.address;   }

    inline bool operator != (const TargetVariableBase & right) const throw()
    {   return ! operator ==(right);   }

    inline FileContainer::address_t operator & (void) const throw()
    {   return isValid() ? address + offset : 0;   }

    inline size_t sizeOf(void) const throw()
    {   return isValid() ? size : 0;   }
};

template<class T>
class TargetVariable : public TargetVariableBase
{
protected:
    T    entity;

public:
        /*
         * �R���X�g���N�^ (TargetVariableBase�ɉ�)
         */
    inline TargetVariable(FileContainer::address_t addr) throw()
        : TargetVariableBase(addr, sizeof(T)), entity() 
    {}

    inline TargetVariable(FileContainer::address_t addr, size_t sz) throw()
        : TargetVariableBase(addr, sz), entity() 
    {}

    inline TargetVariable(FileContainer::address_t addr, size_t sz, size_t ofs, size_t ssz) throw()
        : TargetVariableBase(addr, sz, ofs, ssz), entity() 
    {}

    inline TargetVariable(const std::string & sym) throw()
        : TargetVariableBase(sym), entity()
    {}

    inline TargetVariable(const std::string & sym, const std::string & sz) throw()
        : TargetVariableBase(sym, sz), entity() 
    {}

    inline TargetVariable(const TargetVariable<T> & src) throw()
        : TargetVariableBase(src), entity()
    {
        if(isValid() && src.isValid()) {
            loaded = src.loaded;
            entity = src.entity;
        }
    }

        /* �f�X�g���N�^ (���ɉ������Ȃ�) */
    virtual ~TargetVariable(void) throw() 
    {}

        /* ��������Ɋi�[�ɏ\���ȃT�C�Y�����邩�ǂ�����ǉ����Ă��� */
    inline bool isValid(void) const
    {   return TargetVariableBase::isValid() && (sizeof(T) >= getSize());   }

        /*
         * �|�C���^���̓��������I�y���[�^�Q
         */
    inline TargetVariable<T> offsetInBytes(int offset) const throw()
    {   return TargetVariable<T>(getAddress() + offset, getSize(), getOffset(), getStructureSize());   }

    inline TargetVariable<T> operator + (int index) const throw()
    {   return offsetInBytes(index * static_cast<int>(getStructureSize()));   }

    inline TargetVariable<T> operator - (int index) const throw()
    {   return offsetInBytes(- index * static_cast<int>(getStructureSize()));   }

    inline TargetVariable<T> operator ++ (int) throw()
    {
        TargetVariable<T> result(*this);
        ++ (*this);
        return result;
    }

    inline TargetVariable<T> operator -- (int) throw()
    {
        TargetVariable<T> result(*this);
        -- (*this);
        return result;
    }

    inline TargetVariable<T> & operator ++ (void) throw()
    {
        setAddress(static_cast<int>(getStructureSize()));
        return *this;
    }

    inline TargetVariable<T> & operator -- (void) throw()
    {  
        setAddress(-static_cast<int>(getStructureSize()));   
        return *this;
    }

    inline TargetVariable<T> & operator += (int sz) throw()
    {   
        setAddress(static_cast<int>(getStructureSize()) * sz);   
        return *this;
    }

    inline TargetVariable<T> & operator -= (int sz) throw()
    {   
        setAddress(-static_cast<int>(getStructureSize()) * sz);   
        return *this;
    }

    inline const T & operator * (void) throw(Exception)
    {
        if(!isLoaded())
            loadContent(&entity, sizeof(T));
        return entity;
    }

    inline T operator [] (int index) const throw(Exception)
    {   return * TargetVariable<T>(getAddress() + index * getStructureSize(), getSize(), getOffset(), getStructureSize());   }
};

#endif

