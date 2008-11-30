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
 *  @(#) $Id: message.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/message.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/message.h"

using namespace std;


/*****************************************************************************/

/*
 *   ���b�Z�[�W�o�͗p�����񐮌`�w���p�[�N���X
 */

    //�f�t�H���g�R���X�g���N�^
Formatter::Formatter(void) throw() : templatestring(""), accept(false)
{}

    //�R���X�g���N�^
Formatter::Formatter(string src) throw() : templatestring(src)
{   shift();   }

    //�R�s�[�R���X�g���N�^
Formatter::Formatter(const Formatter & src) throw() : templatestring(src.templatestring), accept(src.accept)
{
    string work;

    work = src.content.str();
    content << work;
}

    //���̈����̑}����ւƈړ�
void Formatter::shift(void) throw()
{
    string::size_type pos;

    accept = false;
    if(!templatestring.empty()) {

        do {
            pos = templatestring.find_first_of("%");

            if(pos != string::npos) {

                    /* %�������Ă��ꂪ\%�Ƃ����`�Ȃ�A%�����̂܂܏o�� */
                if(pos != string::npos && pos != 0 && templatestring.at(pos - 1) == '\\') {

                    if(pos > 1)
                        content << templatestring.substr(0, pos - 2);
                    content << '%';

                    templatestring = templatestring.substr(pos + 1);

                    continue;
                }
                else {
                        /* %���܂����� */
                    if(pos != string::npos)
                        accept = true;
                    break;
                }
            }
        } while(pos != string::npos);

        if(pos != string::npos) {
            if(pos != 0)
                content << templatestring.substr(0, pos);
            templatestring = templatestring.substr(pos + 1);
        }
        else {
            content << templatestring;
            templatestring.erase();
        }
    }
}


    //���ݒ�̈����� (null) �Œu��
void Formatter::shift_all(void) throw()
{
    while(accept)
        *this << "(null)";
}

    //�������b�Z�[�W�̎��o��
string Formatter::str(void) throw()
{
    shift_all();
    return content.str();
}

    //�e���v���[�g������̐ݒ� (���g�͏�����)
void Formatter::assign(string src) throw()
{
    clear();
    templatestring.assign(src);
    shift();
}

    //���e�̏���
void Formatter::clear(void) throw()
{
    if(!templatestring.empty())
        templatestring.erase();
    content.str(string(""));
    accept = false;
}

    //������Z�q
Formatter & Formatter::operator =(const Formatter & src) throw()
{
    string work;

    templatestring = src.templatestring;
    accept         = src.accept;

    work = src.content.str();
    content << work;

    return *this;
}


/*****************************************************************************/

/*
 *   ���b�Z�[�W�o�͗p�����񐮌`�w���p�[�N���X
 */

const char * Message::MessageControl::select(const char * msg1, const char * msg2, va_list vl) throw()
{
    const char * msg = msg1;
    int i = language;

    if(i > 0) {
        msg = msg2;

        while(--i > 0)
            msg = va_arg(vl, const char *);
    }

    return msg;
}

    //�f�t�H���g�R���X�g���N�^ (�e�X�g�p)
Message::Message(void) throw()
{}

    //�R���X�g���N�^
Message::Message(string src) throw() : Formatter(src)
{}

    //�R���X�g���N�^ (��������)
Message::Message(const char * src1, const char * src2, ...) throw()
{
    va_list vl;

    va_start(vl, src2);
    templatestring.assign(Singleton<MessageControl>::getInstance()->select(src1, src2, vl));
    shift();
}

    //�R�s�[�R���X�g���N�^
Message::Message(const Message & src) throw() : Formatter(src)
{}

    //�h���N���X�̏������p�֐� (��������)
void Message::_initialize(const char * src1, const char * src2, va_list vl) throw()
{
    content.clear();
    accept = false;
    templatestring.assign(Singleton<MessageControl>::getInstance()->select(src1, src2, vl));
    shift();
}

    //����I��
void Message::selectLanguage(enum tagLanguage lang) throw()
{
    if(lang >= 0 && lang < LAST_LANG)
        Singleton<Message::MessageControl>::getInstance()->setLanguage(lang);
}

    //�e���v���[�g������̐ݒ� (���g�͏�����)
void Message::assign(const char * src1, const char * src2, ... ) throw()
{
    va_list vl;

    clear();

    va_start(vl, src2);
    templatestring.assign(Singleton<MessageControl>::getInstance()->select(src1, src2, vl));
    shift();
}

/*****************************************************************************/

/*
 *   �璷�o�͗p�����񐮌`�w���p�[�N���X
 */

    //�f�t�H���g�R���X�g���N�^
VerboseMessage::VerboseMessage(void) throw() : Message()
{}

    //�R���X�g���N�^
VerboseMessage::VerboseMessage(const char * src) throw() : Message(src)
{}

    //�R���X�g���N�^
VerboseMessage::VerboseMessage(const string & src) throw() : Message(src)
{}

    //�R���X�g���N�^
VerboseMessage::VerboseMessage(const char * src1, const char * src2, ... ) throw() : Message()
{
    va_list vl;

    va_start(vl, src2);
    _initialize(src1, src2, vl);
}

    //�f�X�g���N�^
VerboseMessage::~VerboseMessage(void) throw()
{   Singleton< VerboseControl >::getInstance()->operator << (str());    }

/*****************************************************************************/

/*
 *   ��O���b�Z�[�W�p�����񐮌`�w���p�[�N���X
 */

    //�R���X�g���N�^
ExceptionMessage::ExceptionMessage(const char * src) throw() : Message(src), level(DEFAULT)
{}

    //�R���X�g���N�^
ExceptionMessage::ExceptionMessage(const std::string & src) throw() : Message(src), level(DEFAULT)
{}

    //�R���X�g���N�^
ExceptionMessage::ExceptionMessage(const char * src1, const char * src2, ...) throw() : Message(), level(DEFAULT)
{
    va_list vl;
    
    va_start(vl, src2);
    _initialize(src1, src2, vl);
}

    //�R���X�g���N�^
ExceptionMessage::ExceptionMessage(enum tagLevel _level) throw() : Message(), level(_level)
{}

    //�R���X�g���N�^
ExceptionMessage::ExceptionMessage(enum tagLevel _level, const char * src) throw() : Message(src), level(_level)
{}

    //�R���X�g���N�^
ExceptionMessage::ExceptionMessage(enum tagLevel _level, const std::string & src) throw() : Message(src), level(_level)
{}

    //�R���X�g���N�^
ExceptionMessage::ExceptionMessage(enum tagLevel _level, const char * src1, const char * src2, ...) throw() : Message(), level(_level)
{
    va_list vl;
    
    va_start(vl, src2);
    _initialize(src1, src2, vl);
}

    //�R�s�[�R���X�g���N�^
ExceptionMessage::ExceptionMessage(const ExceptionMessage & src) throw() : Message(src), level(src.level)
{}


/*****************************************************************************/

/*
 *   �f�o�b�O���b�Z�[�W�p�����񐮌`�w���p�[�N���X
 */

    //�R���X�g���N�^
DebugMessage::DebugMessage(string src) throw() : Formatter(src)
{}

    //�f�X�g���N�^
DebugMessage::~DebugMessage(void) throw()
{   Singleton<DebugControl>::getInstance()->operator << (str());    }

