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
 *  @(#) $Id: except.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/except.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef EXCEPT_H
#define EXCEPT_H

#ifdef _MSC_VER
#  pragma warning(disable:4290) //C++ �̗�O�̎w��͖�������܂��B�֐��� __declspec(nothrow) �łȂ����Ƃ̂ݕ\������܂��B
#endif

//#include "testsuite.h"

#include <string>
#include <typeinfo>

    //��O���N���X
class Exception
{
private:
    static bool is_throwable;

protected:
    int         code;       //��O�R�[�h
    std::string classname;  //���̗�O�𐶐������N���X�̖��O (���ʗp)
    std::string details;    //��O�̐���

        //�R���X�g���N�^
    Exception(std::string classname = "Exception", int code = 0, std::string details = "") throw();
    Exception(std::string classname, std::string details) throw();

        //�f�X�g���N�^
public:
    Exception(const Exception & src) throw();

    virtual ~Exception(void) throw();

        //is-an-instance-of�֌W�̕]��
    inline bool isInstanceOf(const char * _classname) const throw()
    {   return classname.compare(_classname) == 0;   }

        //��O�R�[�h���擾����
    inline int getCode(void) const throw()
    {   return code;   }

        //��O�̐������擾����
    inline std::string getDetails(void) const throw()
    {   return details;   }

        //���݂̗�O����t���O�̏�Ԃɏ]���ė�O�𔭍s����
    inline bool throwException(void)
    {
        if(is_throwable)
            throw *this;
        return is_throwable;
    }

        //is_throwable�̃A�N�Z�T
    static void setThrowControl(bool _throwable) throw()
    {   is_throwable = _throwable;   }

    static bool getThrowControl(void) throw()
    {   return is_throwable;   }


//  TESTSUITE_PROTOTYPE(main)
};


#define EXCEPTION(x)       class x : public Exception { public: x(void) throw() : Exception(#x)       {} };
#define EXCEPTION_(x,y)    class x : public Exception { public: x(void) throw() : Exception(#x, y)    {} };
#define EXCEPTION__(x,y,z) class x : public Exception { public: x(void) throw() : Exception(#x, y, z) {} };

#endif



