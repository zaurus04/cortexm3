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
 *  @(#) $Id: mpstrstream.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/mpstrstream.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef MPSTRSTREAM_H
#define MPSTRSTREAM_H

#ifdef _MSC_VER
#  pragma warning(disable:4290) //C++ �̗�O�̎w��͖�������܂��B�֐��� __declspec(nothrow) �łȂ����Ƃ̂ݕ\������܂��B
#  pragma warning(disable:4786) //�f�o�b�O���Ŏ��ʎq��255�����ɐ؂�̂Ă��܂����B
#endif

#include "testsuite.h"
#include "base/except.h"
#include "base/message.h"
#include "base/event.h"

#include <fstream>
#include <sstream>
#include <string>
#include <list>


    //�������ʂ���Ȃ�o�͗p�X�g���[���̃N���X
class MultipartStream : public Event<ShutdownEvent>::Handler
{
public:

        //�������ʂ���Ȃ�o�͗p�X�g���[���̈ꕔ�ʂɑ�������N���X
    class Part
    {
    protected:
        std::string       name;
        std::stringstream stream;

    public:
            //�R���X�g���N�^
        Part(std::string name) throw();
        Part(const Part & src) throw();

            //����������
        inline bool isValid(void) const throw()
        {   return (this != 0) && !name.empty() && stream.good();   }

            //�X�g���[���ւ̏�����
        template<class T>
        Part & operator << ( T src ) throw(Exception)
        {
            if(isValid())
                stream << src;
            else
                ExceptionMessage("Operation was performed against an invalid stream.","�����ȃX�g���[���ɑ΂��đ��삪�s���܂���").throwException();

            return *this;
        }

            //�X�g���[���ɏ��������e���󂯎��
        std::string getContents(void) const throw(Exception);

            //�X�g���[���̓��e�𒼐ڐݒ肷��
        void setContents(std::string contents) throw(Exception);

            //�X�g���[�����̎Q��
        inline const std::string & getName(void) const throw(Exception)
        {
            if(!isValid())
                ExceptionMessage("Operation was performed against an invalid stream.","�����ȃX�g���[���ɑ΂��đ��삪�s���܂���").throwException();
            return name;
        }

            //������Z�q
        inline Part & operator = (const Part & src) throw()
        {
            name = src.name;
            stream.clear();
            stream << src.stream.str();
        
            return *this;
        }

        TESTSUITE_PROTOTYPE(main)
    };


protected:
    std::string         filename;       //�֘A�t����ꂽ�t�@�C����
    std::list<Part>     parts;          //���ʏW��(������)
    Part *              current;        //�����Ă��镔��
    bool                dirty;          //�t�@�C���ɏo�͂���v�����true (�����������񂾂�... �ł͂Ȃ��A�܂��o�͂��ĂȂ����ǂ���)
    bool                output;         //�o�͂��Ă��ǂ��Ȃ�true

    virtual void handler(ShutdownEvent & evt)
    {   serialize();    }
  
public:
        //�R���X�g���N�^
    MultipartStream(std::string filename = "") throw();

        //�f�X�g���N�^
    virtual ~MultipartStream(void) throw();

        //����������
    inline bool isValid(void) const throw()
    {   return (this != 0) && !filename.empty();   }

        //�t�@�C����
    std::string setFilename(std::string filename) throw(Exception);
    std::string getFilename(void) const throw() { return filename; };

        //�X�g���[���̓��e���t�@�C���ɏo��
    bool serialize(void) throw(Exception);

        //���ʂ̐���
    MultipartStream & createPart(std::string name, bool precedence = false) throw(Exception);

        //���ʂ̑I��
    MultipartStream & movePart(std::string name) throw(Exception);

        //�o�͂��邩�ǂ����̐ݒ�
    inline void enableOutput(void) throw()
    {   if(isValid()) output = true;   }
    inline void disableOutput(void) throw()
    {   if(isValid()) output = false;   }

        //�_�[�e�B�r�b�g�̐ݒ�
    inline void setDirty(bool _dirty = true) throw()
    {   dirty = _dirty;   }

        //�o��
    template <class T>
    inline MultipartStream & operator << ( T src ) throw(Exception)
    {
        if(this != 0 && current != 0) {
            setDirty();
            (*current) << src;
        }
        else
            ExceptionMessage("Invalid operation against an invalid object","�����ȃI�u�W�F�N�g�ɑ΂���v��").throwException();
        return *this;
    }

        //���ʂ̑I�� (Synonym)
    inline MultipartStream & operator[] (std::string name) throw(Exception)
    {   return movePart(name);   }

    TESTSUITE_PROTOTYPE(main)
};

#endif


