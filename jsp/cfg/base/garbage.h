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
 *  @(#) $Id: garbage.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/garbage.h,v 1.1 2008/06/17 00:04:36 suikan Exp $


#ifndef GARBAGE_H
#define GARBAGE_H

#ifdef _MSC_VER
#  pragma warning(disable:4290) //C++ �̗�O�̎w��͖�������܂��B�֐��� __declspec(nothrow) �łȂ����Ƃ̂ݕ\������܂��B
#  pragma warning(disable:4786) //�f�o�b�O���Ŏ��ʎq��255�����ɐ؂�̂Ă��܂����B
#endif

#include "base/testsuite.h"
#include <list>


    //���I�ɐ��������I�u�W�F�N�g�������Ɣj�����邽�߂̃S�~�����[�`��
class TrashBox
{
public:
    typedef std::list<class Garbage *>::iterator Cookie;

protected:
    static TrashBox *    current_box;   //���ݎg�p���Ă���S�~��
    TrashBox *           previous_box;  //���̃S�~���̐e
    
    std::list<class Garbage *> garbage; //����

public:
        //�����q �� ���Ŏq
    TrashBox(void)  throw();
    ~TrashBox(void) throw();

    inline bool isValid(void) const throw()
    {   return (this != 0);   }

        //�S�~���ɓ����Ă���S�~��j��
    void cleanup(void);

        //���g���Ă���S�~�����擾
    inline static TrashBox * getCurrentTrashBox(void) throw()
    {   return current_box;   }

        //�S�~����
    inline Cookie addGarbage(class Garbage * _garbage) throw()
    {   return garbage.insert(garbage.begin(), _garbage);   }

        //�S�~���
    void recoverGarbage(Cookie cookie) throw();


        //���I�Ɋm�ۂ��������Ȃ�
    void * operator new (size_t) throw(std::bad_alloc)
    {   throw std::bad_alloc();   }
    void * operator new (size_t, std::nothrow_t) throw()
    {   return 0;   }

    TESTSUITE_PROTOTYPE(main)
};


    //�S�~���ɓ����S�~�I�u�W�F�N�g�̊��
class Garbage
{
private:
    class TrashBox *  assigned_box;
    TrashBox::Cookie  cookie;

public:
        //�����q �� ���Ŏq
    Garbage(void)  throw();
    virtual ~Garbage(void) throw();

        //�������S�~���E���グ��
    void rescue(void) throw();
};


#endif


