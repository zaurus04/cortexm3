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
 *  @(#) $Id: clause.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/clause.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef CLAUSE_H
#define CLAUSE_H

#include "base/testsuite.h"
#include "base/parser.h"
#include "base/singleton.h"
#include "base/except.h"

#include <map>
#include <string>

#define INTEGER_CLAUSE_IDENTIFIER   "##INTEGER" //2�A��#�Ǝ��ʎq����C�Ɏ��o�����Ƃ͂ł��Ȃ��̂Ŗ��O���d�Ȃ邱�Ƃ͂Ȃ�
#define LITERAL_CLAUSE_IDENTIFIER   "##STRING"
#define OPERATOR_CLAUSE_IDENTIFIER  "##OPERATOR"

    //�\����̈�߂���������N���X
class Clause
{
public:
        //���閼�O��Ԃɑ�����߂̃}�b�v
    typedef std::map<std::string, Clause *> map_type;

        //���O���
    class Namespace : public std::map<std::string, map_type>
    { public: SINGLETON_CONSTRUCTOR(Namespace) throw() {} };

protected:
    static map_type * getClauseMap(std::string ns) throw();

        //�g�[�N�����环�ʖ��𐶐�����
    static std::string getClauseIdentifier(Token token) throw();

        //���g��o�^����
    void   addClause(std::string ns, std::string identifier) throw();

        //�����𕡐���leading identifier�ɑΉ��t����
    void   addMultipleClauses(std::string ns, std::string identifier_list) throw();

protected:  /* �C���^�t�F�[�X */

        //�p�[�T�{��
    virtual void before(const Token & first, Parser & p);
    virtual void body  (const Token & first, Parser & p) = 0;
    virtual void after (const Token & first, Parser & p);

        //�p�[�X���s���̉񕜏���
    virtual void onFail(const Token & first, Parser & p) throw();

public:
    Clause(void) throw() {}
    virtual ~Clause(void) throw() {}

        //�L������
    inline bool isValid(void) const throw()
    {   return (this != 0);   }

        //�߂̉��
    static bool parseClause(std::string ns, Parser & p);

        //first�Ŏn�܂�߂����邩
    static bool hasClause(std::string ns, std::string first) throw();

        //[�w���v�p] �o�^����Ă���߂̈ꗗ���쐬����
    static std::string makeClauseList(std::string ns, int width = 80) throw();

    TESTSUITE_PROTOTYPE(main)
};


    /*
     *   �ÓIAPI
     */
#define NAMESPACE_STATICAPI "StaticAPI"

class StaticAPI : public Clause
{
protected:

    virtual void before(const Token & first, Parser & p);
    virtual void after (const Token & first, Parser & p);

        //�p�[�X���s���̉񕜏���
    virtual void onFail(const Token & first, Parser & p) throw();

public:
        //�f�t�H���g�R���X�g���N�^ (�������Ȃ�)
    StaticAPI(void) throw() {}      
        //API�����w�肵�Đ��� (regist�����)
    StaticAPI(std::string apinamelist) throw()
    {   addMultipleClauses(NAMESPACE_STATICAPI, apinamelist);   }

    inline void regist(std::string apinamelist) throw()
    {   addMultipleClauses(NAMESPACE_STATICAPI, apinamelist);   }

        //�߂̉��
    static bool parseStaticAPI(Parser & p)
    {   return Clause::parseClause(NAMESPACE_STATICAPI, p);   }

        //first�Ŏn�܂�߂����邩
    inline static bool hasStaticAPI(std::string first) throw()
    {   return Clause::hasClause(NAMESPACE_STATICAPI, first);   }

        //[�w���v�p] �o�^����Ă���߂̈ꗗ���쐬����
    inline static std::string makeClauseList(int width = 80) throw()
    {   return Clause::makeClauseList(NAMESPACE_STATICAPI, width);   }

        //�X�L�b�v
    static void skip(Parser & p, bool invalid_api = true) throw();

    TESTSUITE_PROTOTYPE(main)
};


    /*
     *   �v���v���Z�X�f�B���N�e�B�u
     */
#define NAMESPACE_DIRECTIVES "Directives"

class Directives : public Clause
{
protected:

    virtual void after(const Token & first, Parser & p) throw(Exception);

        //�p�[�X���s���̉񕜏���
    virtual void onFail(const Token & first, Parser & p) throw();

public:
        //�f�t�H���g�R���X�g���N�^ (�������Ȃ�)
    Directives(void) throw() {}      
        //API�����w�肵�Đ��� (regist�����)
    Directives(std::string apinamelist) throw()
    {   addMultipleClauses(NAMESPACE_DIRECTIVES, apinamelist);   }

    inline void regist(std::string apinamelist) throw()
    {   addMultipleClauses(NAMESPACE_DIRECTIVES, apinamelist);   }

        //�߂̉��
    inline static bool parseDirectives(Parser & p)
    {   return Clause::parseClause(NAMESPACE_DIRECTIVES, p);   }

        //first�Ŏn�܂�߂����邩
    inline static bool hasDirectives(std::string first) throw()
    {   return Clause::hasClause(NAMESPACE_DIRECTIVES, first);   }

        //[�w���v�p] �o�^����Ă���߂̈ꗗ���쐬����
    inline static std::string makeClauseList(int width = 80) throw()
    {   return Clause::makeClauseList(NAMESPACE_DIRECTIVES, width);   }

    TESTSUITE_PROTOTYPE(main)
};

#endif



