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
 *  @(#) $Id: message.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/message.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef MESSAGE_H
#define MESSAGE_H

#ifdef _MSC_VER
#  pragma warning(disable:4290) //C++ �̗�O�̎w��͖�������܂��B�֐��� __declspec(nothrow) �łȂ����Ƃ̂ݕ\������܂��B
#  pragma warning(disable:4786) //�f�o�b�O���Ŏ��ʎq��255�����ɐ؂�̂Ă��܂����B
#endif

#include <string>
#include <sstream>
#include <stdarg.h>
#include <stdexcept>

//#include "base/testsuite.h"
#include "base/singleton.h"
#include "base/except.h"

    /*
     *   �����񐮌`�w���p�[�N���X
     */
class Formatter
{
protected:
    std::string       templatestring;    //�e���v���[�g������
    std::stringstream content;           //�����񐮌`�Ə����ςݕ�����\�ꏊ�p�X�g���[��
    bool              accept;            //����������\���ǂ���

        //���̈����̑}����ւƈړ�
    void shift(void) throw();

        //���ݒ�̈����� (null) �Œu��
    void shift_all(void) throw();

public:
        //�f�t�H���g�R���X�g���N�^
    Formatter(void) throw();

        //�R���X�g���N�^
    Formatter(std::string src) throw();

        //�R�s�[�R���X�g���N�^
    Formatter(const Formatter & src) throw();

        //�e���v���[�g������̐ݒ� (���g�͏�����)
    void assign(std::string src) throw();

        //���e�̃N���A
    void clear(void) throw();

        //������Z�q
    Formatter & operator =(const Formatter & src) throw();

        //�����̐ݒ�
    template<class T>
    Formatter & operator << (const T & src) throw()
    {
        std::string::size_type pos;

            //����������\�Ȃ�
        if(accept) {
            pos = content.str().size();
            content << src;

                /* �󕶎��łȂ���Ύ��̑}���ꏊ�Ɉړ� */
            if(pos != content.str().size())
                shift();
        }
        return *this;
    }

        //�������b�Z�[�W�̎��o��
    std::string str(void) throw();

        //�W���o�̓X�g���[���ւ̏o�͗p operator << ��`
    friend inline std::ostream & operator << (std::ostream & out, Formatter msg) throw()
    {
        out << msg.content.str();
        return out;
    }

//    TESTSUITE_PROTOTYPE(main)
};

    /*
     *   ���b�Z�[�W�o�͗p��2����Ή����s���������񐮌`�w���p�[�N���X
     */
class Message : public Formatter
{
public:
    enum tagLanguage
    {
        ENGLISH  = 0,
        JAPANESE = 1,

        LAST_LANG,              //�Ō�̈ʒu
        NEUTRAL  = ENGLISH,     //�W������
    };

        /* �o�̓��b�Z�[�W���ꐧ��N���X */
    class MessageControl
    {
    protected:
        int language;   //�ǂ̌�����g�p����̂�

    public:
            //�R���X�g���N�^
        SINGLETON_CONSTRUCTOR(MessageControl) throw() : language(NEUTRAL) {};

            //�A�N�Z�T
        inline void setLanguage(int _language) throw()  { language = _language; }
        inline int  getLanguage(void) const    throw()  { return language; }

        const char * select(const char * msg1, const char * msg2, va_list vl ) throw();
    };

protected:

        //�h���N���X�p�R���X�g���N�^
    void _initialize(const char * src1, const char * src2, va_list vl) throw();

public:
        //�f�t�H���g�R���X�g���N�^
    Message(void) throw();

        //�R���X�g���N�^ (�P�ꌾ��)
    Message(std::string src) throw();

        //�R���X�g���N�^ (��������)
    Message(const char * src1, const char * src2, ... ) throw();

        //�R�s�[�R���X�g���N�^
    Message(const Message & src) throw();

        //�e���v���[�g������̐ݒ� (���g�͏�����)
    void assign(std::string src) throw() { Formatter::assign(src); }
    void assign(const char * src1, const char * src2, ... ) throw();

        //����I��
    static void selectLanguage(enum tagLanguage lang = NEUTRAL) throw();
        
        //����̎擾
    static enum tagLanguage getCurrentLanguage(void) throw()
    {   return static_cast<enum tagLanguage>(Singleton<MessageControl>::getInstance()->getLanguage());   }

    //TESTSUITE_PROTOTYPE(main)
};


    /*
     *   �璷�o�͗p�����񐮌`�w���p�[�N���X
     */
class VerboseMessage : public Message
{
public:
        //���ʂ̏璷�o�͏������N���X
    class VerboseControl
    {
    public:
        bool           verbose;     //�璷�o�͂��s�����ǂ���
        std::ostream * out;         //�o�͐�

            //�R���X�g���N�^
        SINGLETON_CONSTRUCTOR(VerboseControl) throw() : verbose(false), out(0)
        {}

            //�璷�o�͐���
        template<class T>
        inline const VerboseControl & operator << (const T & src) const throw()
        {
            if(verbose && out != 0)
                (*out) << src;
            return *this;
        }

            //verbose�A�N�Z�T
        void setVerbose(bool _verbose) throw()
        {   verbose = _verbose;   }
        bool getVerbose(void) const throw()
        {   return verbose;   }

            //out�A�N�Z�T
        void setStream(std::ostream * _out) throw()
        {   out = _out;   }
        std::ostream * getStream(void) throw()
        {   return out;   }
    };

        //�璷�o�̓X�g���[�� (�P���ȗ}�~�@�\�����b�p�[�N���X)
    class VerboseStream
    {
    protected:
        std::ostream * out;

    public:
        VerboseStream(std::ostream * _out = 0) throw() : out(_out) {};

        template<class T>
        VerboseStream & operator << (const T & src) throw()
        {
            if(out != 0)
                (*out) << src;
            return *this;
        }
    };

protected:
        //�f�t�H���g�R���X�g���N�^ (�e�X�g�p)
    VerboseMessage(void) throw();

public:

        //�R���X�g���N�^
    VerboseMessage(const char * src) throw();
    VerboseMessage(const std::string & src) throw();
    VerboseMessage(const char * src1, const char * src2, ... ) throw();

        //�f�X�g���N�^
    ~VerboseMessage(void) throw();

        //�璷�o�͐��� (�A�N�Z�T��)
    inline static void setVerbose(bool _verbose) throw()
    {   Singleton<VerboseControl>::getInstance()->setVerbose(_verbose);   }

        //�璷�o�͐�X�g���[���ݒ� (�A�N�Z�T��)
    inline static void setStream(std::ostream * _stream) throw()
    {   Singleton<VerboseControl>::getInstance()->setStream(_stream);   }

        //�璷�o�͐���̏�Ԏ擾
    inline static bool getVerbose(void) throw()
    {   return Singleton<VerboseControl>::getInstance()->getVerbose();   }

        //�璷�o�͐�X�g���[���̎擾 (�ݒ肵�����̂Ɠ������̂͏o�Ă��Ȃ�)
    inline static VerboseStream getStream(void) throw()
    {   return VerboseStream(getVerbose() ? Singleton<VerboseControl>::getInstance()->getStream() : 0);   }

    //TESTSUITE_PROTOTYPE(main)
};

    /*
     *   ��O���b�Z�[�W�p�����񐮌`�w���p�[�N���X
     */
class ExceptionMessage : public Message
{
public:
        //��O�̊댯�x���x��
    enum tagLevel {
        DEFAULT = 0,
        FATAL   = 1,
        WARNING = 2
    };

#ifdef EXCEPT_H
    class ExceptionMessageException : public Exception
    {
    friend class ExceptionMessage;
    protected:
        ExceptionMessageException(int _code, std::string _details) throw() : Exception("ExceptionMessage", _code, _details) {}
    };
#endif

protected:
    enum tagLevel level;

public:
        //�R���X�g���N�^
    ExceptionMessage(const char * src) throw();
    ExceptionMessage(const std::string & src) throw();
    ExceptionMessage(const char * src1, const char * src2, ...) throw();

    ExceptionMessage(enum tagLevel level = DEFAULT) throw();
    ExceptionMessage(enum tagLevel level, const char * src) throw();
    ExceptionMessage(enum tagLevel level, const std::string & src) throw();
    ExceptionMessage(enum tagLevel level, const char * src1, const char * src2, ...) throw();

    ExceptionMessage(const ExceptionMessage & src) throw();


        //�댯�x���x���Q��
    inline bool operator == (enum tagLevel _level) const throw()
    {   return level == _level;   }

        //�댯�x���x���Q��
    inline bool operator != (enum tagLevel _level) const throw()
    {   return !(operator ==(_level));   }

        //�����̐ݒ� (�ԋp�l�̌^��Message & ���� ExceptionMessage & �ɂ��邽�߂̏��׍H)
    template<class T>
    inline ExceptionMessage & operator << (const T & src) throw()
    {
        Message::operator << ( src );
        return *this;
    }

#ifdef EXCEPT_H     //Exception�N���X���g�p����ꍇ
        //��O�̔���
    bool throwException(void) throw(Exception)
    {
        ExceptionMessageException exc(level, str());
        return exc.throwException();
    }
        //�}�j�s�����[�^
    inline ExceptionMessage & operator << ( ExceptionMessage & (* func)(ExceptionMessage &) ) throw(Exception)
    {   return (*func)(*this);   }

#else               //stdexcept���g�p����ꍇ
        //��O�̔���
    template<class T>
    bool throwException(void) throw(T)
    {
        throw T(str());
        return true;
    }
        //�}�j�s�����[�^
    inline ExceptionMessage & operator << ( ExceptionMessage & (* func)(ExceptionMessage &) ) throw(T)
    {   return (*func)(*this);   }
#endif

    //TESTSUITE_PROTOTYPE(main)
};

#ifdef EXCEPT_H     //Exception�N���X���g�p����ꍇ

        //��O���X���[���邽�߂̃}�j�s�����[�^
    inline ExceptionMessage & throwException(ExceptionMessage & excmsg) throw(Exception)
    {
        excmsg.throwException();
        return excmsg;
    }

#else
        //��O���X���[���邽�߂̃}�j�s�����[�^
    template<class T>
    inline ExceptionMessage & throwException(ExceptionMessage & excmsg) throw(T)
    {
        excmsg.throwException<T>();
        return excmsg;
    }

#endif



    /*
     *   �f�o�b�O���o�͗p�����񐮌`�w���p�[�N���X
     */
class DebugMessage : public Formatter
{
public:
        //���ʂ̏璷�o�͏������N���X (�V���O���g���ɂ���̂�VerboseControl�𓯂����̂��N���X������)
    class DebugControl : public VerboseMessage::VerboseControl
    { public: SINGLETON_CONSTRUCTOR_(DebugControl) throw() : VerboseMessage::VerboseControl(_singleton) {} };


protected:
        //�f�t�H���g�R���X�g���N�^ (�e�X�g�p)
    DebugMessage(void) throw();

public:

        //�R���X�g���N�^
    DebugMessage(std::string src) throw();

        //�f�X�g���N�^
    ~DebugMessage(void) throw();

        //�璷�o�͐��� (�A�N�Z�T��)
    inline static void setVerbose(bool _verbose) throw()
    {   Singleton<DebugControl>::getInstance()->setVerbose(_verbose);   }

        //�璷�o�͐�X�g���[���ݒ� (�A�N�Z�T��)
    inline static void setStream(std::ostream * _stream) throw()
    {   Singleton<DebugControl>::getInstance()->setStream(_stream);   }

        //�璷�o�͐���̏�Ԏ擾
    inline static bool getVerbose(void) throw()
    {   return Singleton<DebugControl>::getInstance()->getVerbose();   }

        //�璷�o�͐�X�g���[���̎擾 (�ݒ肵�����̂Ɠ������̂͏o�Ă��Ȃ�)
    inline static VerboseMessage::VerboseStream getStream(void) throw()
    {   return VerboseMessage::VerboseStream(getVerbose() ? Singleton<DebugControl>::getInstance()->getStream() : 0);   }

//  TESTSUITE_PROTOTYPE(main)
};


#endif  //MESSAGE_H


