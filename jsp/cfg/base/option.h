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
 *  @(#) $Id: option.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/option.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef OPTION_H
#define OPTION_H

#include "base/testsuite.h"
#include "base/singleton.h"

#include <string>
#include <vector>
#include <map>

#define DEFAULT_PARAMETER "#default"

using namespace std;

/*
 *   �I�v�V�����p�����[�^���Ǘ�����N���X
 */
class OptionParameter
{
public:
    class OptionItem : public std::string
    {
    protected:
        bool                      checked;  //�g�p�������ǂ���
        std::vector<std::string>  param;    //�I�v�V����

    public:
            //�R���X�g���N�^
        OptionItem(void) throw() : string(DEFAULT_PARAMETER), checked(false) {}
        OptionItem(const std::string & name) throw() : string(name), checked(false) {}
        OptionItem(const OptionItem & src) throw() : string(src), checked(src.checked), param(src.param) {}

            //�I�v�V�����p�����[�^����͂���OptionItem�𐶐�����
        static bool createItem(OptionItem & item, string & argv);

            //�ʂ�OptionItem�����p�����[�^�������ɒǉ�����
        void mergeItem(const OptionItem & src);

            //�p�����[�^�̒ǉ�
        inline void addParameter(const std::string & src) throw()
        {   param.push_back(src);   }

            //�p�����[�^���̎擾
        inline size_t countParameter(void) const throw()
        {   return param.size();    }

            //�p�����[�^�������Ă��邩�ǂ���
        inline bool hasParameter(void) const throw()
        {   return countParameter() != 0;   }

            //�ʒu���w�肵�ăp�����[�^���Q�� (�����Ȉʒu���Ƌ󕶎�)
        inline std::string operator[](std::vector<std::string>::size_type offset) const throw()
        {
            string result;

            if(offset < countParameter())
                result = param[offset];

            return result;
        }

            //���̃I�v�V�������g�p�������Ƃ��L�� (OptionParameter����Ă̗��p�݂̂Ȃ̂� "_" �����Ă���)
        inline void _check(void) throw()
        {   checked = true;   }

            //���̃I�v�V�����ɐG�������ǂ���
        inline bool isChecked(void) const throw()
        {   return checked;   }

            //�L�����ǂ��� (�ȂȂ��͖���)
        inline bool isValid(void) const throw()
        {   return !empty();   }

            //�����ȃI�v�V�����A�C�e���̐���
        static OptionItem createInvalidItem(void) throw();

            //�S�Ẵp�����[�^�����������̂��擾
        std::string getParameters(std::string punctuator = " ") const throw();

            //�p�����[�^�̌����`�F�b�N
        bool checkParameterCount(size_t count, bool allow_zero = false) const throw();

        TESTSUITE_PROTOTYPE(main)
    };

protected:
        //�I�v�V�������i�[����ϐ�
    std::map<std::string, OptionItem> container;    //set::begin()��const_iterator�����Ԃ��Ȃ��̂Ŏd���Ȃ�map�ɕς��� (�������l����Γ��R��...)

        //�v���O��������
    std::string program_name;

        //�R�}���h���C���ɓn���ꂽ�������̂���
    std::string cmdline;    

        //�f�t�H���g�R���X�g���N�^ (�e�X�g�p)
    OptionParameter(void) throw() {}

        //�v�f�̌��o
    std::map<std::string, OptionItem>::iterator _find(const std::string & name, bool check = true) throw();

public:

        //�V���O���g���R���X�g���N�^
    SINGLETON_CONSTRUCTOR(OptionParameter) throw() {}

        //�I�v�V�����p�����[�^�̃p�[�X
    bool parseOption(int _argc, char const * const * _argv, char const * _default = NULL) throw();

        //�S�ẴI�v�V�������g�p���ꂽ���ǂ����̊m�F
    bool validateOption(void) const throw();

        //�g�p����Ȃ������I�v�V��������擾
    std::string getInvalidOptions(void) const throw();

        //�A�C�e���̐��𐔂���
    inline size_t countItem(void) const throw()
    {   return container.size();   }

        //�I�v�V�����A�C�e���̎Q��
    OptionItem get(const std::string & name, bool check = true) throw();
    
    inline OptionItem operator [] (const std::string & name) throw()
    {   return get(name);   }
    
    inline OptionItem operator [] (const char * name) throw()
    {   return get(string(name));   }

        //�I�v�V�����̗L���̌��o
    inline bool find(std::string name) throw()
    {   return get(name).isValid(); }


        //�Q�ƃ}�[�N������
    inline bool check(const std::string & name) throw()
    {   return _find(name) != container.end();   }

    inline bool check(const char * name) throw()
    {   return check(string(name));   }

        //�v���O���������擾����
    inline const std::string & getProgramName(void) const throw()
    {   return program_name;    }

        //����������̂܂܎擾���� (�v���O�������͊܂܂�)
    inline const std::string & getCommandLine(void) const throw()
    {   return cmdline;   }

    TESTSUITE_PROTOTYPE(main)
};

    /* �V�X�e�����ŒP���OptionParameter����邽�߂̊֐� */
inline OptionParameter & getOptionParameter(void) throw()
{   return *Singleton<OptionParameter>::getInstance();   }

#endif


