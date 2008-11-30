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
 *  @(#) $Id: jsp_common.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/jsp/jsp_common.h,v 1.1 2008/06/17 00:04:45 suikan Exp $


#ifndef JSP_COMMON_H
#define JSP_COMMON_H

#include "base/testsuite.h"

#include "base/mpstrstream.h"
#include "base/collection.h"
#include "base/except.h"
#include "base/event.h"

#include <string>


namespace ToppersJsp {

        //�J�[�l���\���t�@�C��
    class SpecialtyFile : public MultipartStream, public RuntimeObject
    {
    protected:
        SpecialtyFile(void) throw();

        template<class T>
        static T * createInstance(std::string filename) throw(Exception)
        {
            T * old;
            T * result = 0;

                //ROT�o�^���� �I�u�W�F�N�g�폜 (�B�ꐫ�̕ۏ� (�����ǃV���O���g���ł͂Ȃ�) )
            old = dynamic_cast<T *>(RuntimeObjectTable::getInstance(typeid(T)));
            if(old != 0)
                delete old;

            result = new(std::nothrow) T;
            if(result == 0)
                ExceptionMessage("Internal error : Object creation failure [ToppersJsp::KernelCfg::createKernelCfg]","�����G���[ : �I�u�W�F�N�g�������G���[ [createKernelCfg]") << throwException;

            try {
                result->setFilename(filename);
            }
            catch(...) {
                if(result != 0)
                    delete result;
                throw;
            }
            return result;
        }

    };


    /*
     *  Visual C++ 6.0 : fatal error C1001: INTERNAL COMPILER ERROR (msc1.cpp:1794) �΍� 
     *    (�Ƃ������A���d�o�^���Ă��Â��C���X�^���X�̓o�^�`�F�b�N�����Ȃ�)
     */
#if defined(_MSC_VER) && (_MSC_VER < 1300)
#  define SPECIALTY_FILE(x)                                                             \
    class x : public SpecialtyFile {                                                    \
        public:                                                                         \
            struct CreationEvent { class x * file; };                                   \
            static inline x * createInstance(std::string filename) throw(Exception)     \
            {                                                                           \
                x * instance = new(std::nothrow) x;                                     \
                if(instance != 0)                                                       \
                    instance->setFilename(filename);                                    \
                return instance;                                                        \
            }                                                                           \
    }
#else
#  define SPECIALTY_FILE(x)                                                             \
    class x : public SpecialtyFile {                                                    \
        public:                                                                         \
            struct CreationEvent { class x * file; };                                   \
            static inline x * createInstance(std::string filename) throw(Exception)     \
            {   return SpecialtyFile::createInstance<x>(filename);   }                  \
    }
#endif

        //TOPPERS/JSP�̃R���t�B�M�����[�V�����ŏo�Ă������ȃt�@�C��
    SPECIALTY_FILE(KernelCfg);
    SPECIALTY_FILE(KernelID);

        //�o�[�W�����Ԃ��z�����ϊ��Ȃ�
    std::string conv_includefile(std::string file) throw(); //�C���N���[�h�t�@�C����
    std::string conv_kernelobject(std::string obj) throw(); //�J�[�l���̕ϐ���

        //�萔�Ȃ�
//  std::string get_agreement(std::string filename = "") throw();   //�����̎擾
}

#endif

