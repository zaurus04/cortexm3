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
 *  @(#) $Id: jsp_staticapi.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/jsp/jsp_staticapi.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $

#include "jsp/jsp_defs.h"

#include "base/parser.h"
#include "base/mpstrstream.h"
#include <iostream>

using namespace std;

DECLARE_API(INCLUDE,"INCLUDE")
{
    Token token;
    Directory * node;
    Directory * scope;

    last = NULL;
    p.getToken(token, Token::STRINGLITERAL);
    token.chopLiteral();

    if( (token[0] != '\"' || token[token.size()-1] != '\"') &&
        (token[0] != '<' || token[token.size()-1] != '>') )
        ExceptionMessage("An include filename must be enclosed with \"...\" or <...>","�t�@�C������ \"...\" �� <...> �̌`�łȂ���΂Ȃ�܂���").throwException();

    node = container.openChild(OBJECTTREE,INCLUDEFILE,NULL);
    last = node;

        //�d���`�F�b�N
    scope = node->getFirstChild();
    while(scope != 0)
    {
        if(token.compare((*scope).toString()) == 0)
        {
            cerr << p.getStreamLocation() << ' ' << (Message("Include file % was already specified (ignored).","�C���N���[�h�t�@�C��%��������w�肳��܂��� (�������܂�)") << token) << endl;
            return;
        }
        scope = scope->getNext();
    }
    
    node->addChild(new Directory(token));
}

DECLARE_API(CRE_TSK,"CRE_TSK")
{
    Token token;
    string work;
    Directory * node;

    p.getToken(token);
    node = allocate(container[OBJECTTREE], token, TASK);
    (*node)["position"] = p.getStreamLocation();

    p.getToken(",","{",NULL);
    parseParameters(p,node,"tskatr,exinf,task,itskpri,stksz");
    p.getToken(",","NULL","}",NULL);

    (*node)["texatr"] = "TA_NULL";
    (*node)["texrtn"] = "NULL";

    if(container["/cpu"].toString().compare("nios32") == 0) 
    {
        (*node)["hi_limit"] = "TSK_HI_LIMIT";
        (*node)["lo_limit"] = "TSK_LO_LIMIT";
    }
}

DECLARE_API(VATT_TRW,"VATT_TRW")
{
    Token token;
    Directory * node;

    if(container["/cpu"].toString().compare("nios32") != 0)
        ExceptionMessage("VATT_TRW is not supported except for the processor 'nios32'.","VATT_TRW��nios32�v���Z�b�T�ł̂݃T�|�[�g����܂�").throwException();

    p.getToken(token);
    node = find(container[OBJECTTREE], token, TASK);

    p.getToken(",","{",NULL);
    parseParameters(p, node, "hi_limit,lo_limit");
    p.getToken("}");
}

DECLARE_API(DEF_TEX,"DEF_TEX")
{
    Token token;
    Directory * node;

    p.getToken(token);
    node = find(container[OBJECTTREE], token, TASK);

    p.getToken(",","{",NULL);
    parseParameters(p, node, "texatr,texrtn");
    p.getToken("}");
}

DECLARE_API(CRE_SEM,"CRE_SEM")
{
    Token token;
    Directory * node;

    p.getToken(token);
    node = allocate(container[OBJECTTREE], token, SEMAPHORE);
    (*node)["position"] = p.getStreamLocation();

    p.getToken(",","{",NULL);
    parseParameters(p,node,"sematr,isemcnt,maxsem");
    p.getToken("}");
}

DECLARE_API(CRE_FLG,"CRE_FLG")
{
    Token token;
    Directory * node;

    p.getToken(token);
    node = allocate(container[OBJECTTREE], token, EVENTFLAG);
    (*node)["position"] = p.getStreamLocation();

    p.getToken(",","{",NULL);
    parseParameters(p,node,"flgatr,iflgptn");
    p.getToken("}");
}

DECLARE_API(CRE_DTQ,"CRE_DTQ")
{
    Token token;
    Directory * node;

    p.getToken(token);
    node = allocate(container[OBJECTTREE], token, DATAQUEUE);
    (*node)["position"] = p.getStreamLocation();

    p.getToken(",","{",NULL);
    parseParameters(p,node,"dtqatr,dtqcnt");
    p.getToken(",","NULL","}",NULL);
}

DECLARE_API(CRE_MBX,"CRE_MBX")
{
    Token token;
    Directory * node;

    p.getToken(token);
    node = allocate(container[OBJECTTREE], token, MAILBOX);
    (*node)["position"] = p.getStreamLocation();

    p.getToken(",","{",NULL);
    parseParameters(p,node,"mbxatr,maxmpri");
    p.getToken(",","NULL","}",NULL);
}

DECLARE_API(CRE_MPF,"CRE_MPF")
{
    Token token;
    Directory * node;

    p.getToken(token);
    node = allocate(container[OBJECTTREE], token, FIXEDSIZEMEMORYPOOL);
    (*node)["position"] = p.getStreamLocation();

    p.getToken(",","{",NULL);
    parseParameters(p,node,"mpfatr,blkcnt,blksz");
    p.getToken(",","NULL","}",NULL);
}

DECLARE_API(CRE_CYC,"CRE_CYC")
{
    Token token;
    Directory * node;

    p.getToken(token);
    node = allocate(container[OBJECTTREE], token, CYCLICHANDLER);
    (*node)["position"] = p.getStreamLocation();

    p.getToken(",","{",NULL);
    parseParameters(p,node,"cycatr,exinf,cychdr,cyctim,cycphs");
    p.getToken("}");
}

DECLARE_API(DEF_INH,"DEF_INH")
{
    Token token;
    Directory * node;

    p.getToken(token);
    node = allocate(container[OBJECTTREE], token, INTERRUPTHANDLER, false);
    (*node)["position"] = p.getStreamLocation();

    p.getToken(",","{",NULL);
    parseParameters(p,node,"inhatr,inthdr");
    p.getToken("}");
}

DECLARE_API(DEF_EXC,"DEF_EXC")
{
    Token token;
    Directory * node;

    p.getToken(token);
    node = allocate(container[OBJECTTREE], token, EXCEPTIONHANDLER, false);
    (*node)["position"] = p.getStreamLocation();

    p.getToken(",","{",NULL);
    parseParameters(p,node,"excatr,exchdr");
    p.getToken("}");
}

DECLARE_API(ATT_INI,"ATT_INI")
{
    Token token;
    Directory * node;

    node = container.openChild(OBJECTTREE,INITIALIZER,NULL)->addChild();
    last = node;

    (*node)["position"] = p.getStreamLocation();

    p.getToken("{",NULL);
    parseParameters(p,node,"iniatr,exinf,inirtn");
    p.getToken("}");
}

DECLARE_API(ATT_FIN, "VATT_TER")
{
    Token token;
    Directory * node;

    node = container.openChild(OBJECTTREE,TERMINATOR,NULL)->addChild();
    last = node;

    (*node)["position"] = p.getStreamLocation();

    p.getToken("{",NULL);
    parseParameters(p,node,"teratr,exinf,terrtn");
    p.getToken("}");
}


