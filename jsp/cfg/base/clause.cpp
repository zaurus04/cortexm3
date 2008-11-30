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
 *  @(#) $Id: clause.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/clause.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/clause.h"
#include "base/message.h"

using namespace std;

/*
 *   �\����̈�߂���������N���X
 */

    //�w�肵�����O��Ԃ̐߃}�b�v���擾
Clause::map_type * Clause::getClauseMap(string name) throw()
{
    map_type * result = NULL;
    Namespace::iterator scope;

    Namespace * const ns = Singleton<Namespace>::getInstance(nothrow);
    if(ns!= 0) {
        scope = ns->find(name);
        if(scope != ns->end())
            result = &(scope->second);
    }

    return result;
}

    //�߂̓o�^
void Clause::addClause(string _namespace, string _identifier) throw()
{
    if(isValid()) {
        Namespace * const ns = Singleton<Namespace>::getInstance(nothrow);
        if(ns != 0)
            (*ns)[_namespace][_identifier] = this;
//          ns->operator [](_namespace).insert(map_type::value_type(_identifier, this));        //�㏑�������Ȃ��ꍇ
    }
}

    //�g�[�N���ɑ΂��Đߎ��ʖ��𐶐�����
string Clause::getClauseIdentifier(Token token) throw()
{
    string result;

    switch(token.getType()) {
        case Token::IDENTIFIER:
        case Token::PUNCTUATOR:
            result = token.getLiteral();    
            break;
        case Token::INTEGER:
            result.assign(INTEGER_CLAUSE_IDENTIFIER);
            break;
        case Token::LITERAL:
            result.assign(LITERAL_CLAUSE_IDENTIFIER);
            break;
        case Token::OPERATOR:
            result.assign(OPERATOR_CLAUSE_IDENTIFIER);
            break;
        default:
            result = string();
    }

    return result;
}

    //�߂̉��
bool Clause::parseClause(string ns, Parser & p)
{
    bool result = false;
    map_type::iterator scope;
    map_type * clause = getClauseMap(ns);

        //�K�[�h��
    if(clause == 0 || p.eof())
        return false;

        //�g�[�N�����环�ʖ������o��
    Token  token;
    string identifier;

    token      = p.getToken();
    identifier = getClauseIdentifier(token);
    
        //�ߏ������̎��s
    scope = clause->find(identifier);
    if(scope != clause->end()) {

            //�f�o�b�O�p���b�Z�[�W�o��
        DebugMessage("Clause::parseClause(%) - %\n") << ns << identifier;

        try {
            scope->second->before(token, p);
            scope->second->body(token, p);  //�q�b�g�������̂����s
            scope->second->after(token, p);
            result = true;
        }
        catch(...) {
            scope->second->onFail(token, p);    //���s�����Ƃ��̌�n�������肢����
            throw;
        }
    }
    else
        p.putback(token);   //���ʎq�Ƀ}�b�`������̂��o�^����Ă��Ȃ�

    return result;
}

    //first�Ŏn�܂�߂����邩
bool Clause::hasClause(string ns, string first) throw()
{
    map_type * clause = getClauseMap(ns);
    if(clause == 0)
        return false;

    return clause->find(first) != clause->end();
}

    //�p�[�X�O����
void Clause::before(const Token &, Parser &)
{}

    //�p�[�X�㏈��
void Clause::after(const Token &, Parser &)
{}

    //�W���̗�O�������̌�n�����[�`��
void Clause::onFail(const Token &, Parser & p) throw()
{
    Token token;

        //�Ō�܂œǂ݂���
    while(!p.eof())
        token = p.getToken();
}

    //�߂𕡐��̎��ʖ��ɑΉ��t����
void Clause::addMultipleClauses(string ns, string id_list) throw()
{
    string            id;
    string::size_type pos;
    string::size_type prev;

        //�J���}�ŋ�؂�ꂽ�v�f����addClause�𔭍s
    if(isValid()) {
        prev = 0;
        do {
            pos = id_list.find_first_of(',', prev);
            id  = id_list.substr(prev, pos - prev);

            addClause(ns, id);

            prev = pos + 1;
        } while(pos != string::npos);
    }
}

    //[�w���v�p] �o�^����Ă���߂̈ꗗ���쐬����
std::string Clause::makeClauseList(string ns, int width) throw()
{
    string result;
    map_type::iterator scope;
    map_type * clause = getClauseMap(ns);
    size_t max_length = 0;

        //�ő�̕����񒷂����߂�
    scope = clause->begin();
    while(scope != clause->end()) {
        size_t i = scope->first.size();
        if(i > max_length)
            max_length = i;
        ++ scope;
    }

        //�ꗗ���쐬
    size_t max_column = width/(max_length+1);
    size_t column = 0;
    scope = clause->begin();
    while(scope != clause->end()) {
        size_t i = scope->first.size();

        result += scope->first;

        ++ column;
        ++ scope;

            //��������
        if(column == max_column || scope == clause->end())
            result += '\n';
        else {
            result += ',';
            result += string(max_length - i, ' ');
        }
    }

    return result;
}


    /*
     *   �ÓIAPI
     */

    //�p�[�X�O����
void StaticAPI::before(const Token & first, Parser & p)
{
    Token token = p.getToken();
    if(token != Token::LPAREN) {
        ExceptionMessage("StaticAPI [%] lacks left-parenthesis '('.","�ÓIAPI[%]�ɂ͊���'('�������Ă���") << first.getLiteral() << throwException;
    }
}

    //�p�[�X�㏈��
void StaticAPI::after(const Token & first, Parser & p)
{
    Token token = p.getToken();
    if(token != Token::RPAREN) {
        ExceptionMessage("StaticAPI [%] lacks right-parenthesis ')'.","�ÓIAPI[%]�ɂ͊���')'�������Ă���") << first.getLiteral() << throwException;
    }
    else {
        token = p.getToken();
        if(token != ";")
            ExceptionMessage("StaticAPI [%] lacks ';' at the end of declaration.","�ÓIAPI[%]�̖�����';'�������Ă���") << first.getLiteral() << throwException;
    }
}

    //���s���̉񕜏���
void StaticAPI::onFail(const Token & , Parser & p) throw()
{   skip(p, false);   }


    //�X�L�b�v
    //   invalid_api : ���ɍŏ��ɓǂݏo�����API�͖���
void StaticAPI::skip(Parser & p, bool invalid_api) throw()
{
        //�Z�~�R���� or ���̐ÓIAPI�̏o���܂�
    Token token;
    bool  condition; //�A���΍�

    if(invalid_api)
        token = p.getToken();   //����API���͓ǂݔ�΂�

    do {
        token = p.getToken(true);

        condition = (!token.isValid()) ||                                                   //�����ȃg�[�N����
                    (token == Token::PUNCTUATOR && token == ";") ||                         //�Z�~�R������
                    (token == Token::IDENTIFIER && hasStaticAPI(token.getLiteral()));       //�ÓIAPI��

    } while(!condition);

    if(token == Token::IDENTIFIER)
        p.putback(token);
}

    /*
     *   �v���v���Z�X�f�B���N�e�B�u
     */

    //�p�[�X�㏈��
void Directives::after(const Token & first, Parser & p) throw(Exception)
{
    Token token = p.getToken(true);
    if(!token.isValid() || !p.isLocatedonHeadofLine())
        ExceptionMessage("Directive [%] has a wrong parameter or misses a new-line.","�f�B���N�e�B�u[%]�ɕs���Ȉ��������邩�A���s���Ȃ�") << first.getLiteral() << throwException;
}

    //�p�[�X���s���̉񕜏���
void Directives::onFail(const Token & , Parser & p) throw()
{
        //���̉��s�܂œǂݔ�΂�
    Token token;

    do {
        token = p.getToken(true);
    } while(token.isValid() && !p.isLocatedonHeadofLine());
}

/************************************************* �e�X�g�X�B�[�g *************************************************/

#ifdef TESTSUITE

#include "coverage_undefs.h"
#include <sstream>

namespace {
    class Clause_test : public Clause
    {
    public:
        Token        first;
        Token        second;
        bool         throw_exception;

        Clause_test(void) throw() : first(Token::ERROR), throw_exception(false) {}

        void body(const Token & _first, Parser & _p)
        {
            TestSuite::check("Clause_test::body");
            first = _first;
            second = _p.getToken();
            if(throw_exception)
                throw 0;
        }

        void before(const Token & , Parser & )
        {
            TestSuite::check("Clause_test::before");
        }

        void after(const Token &, Parser &)
        {
            TestSuite::check("Clause_test::after");
        }

        void onFail(const Token & _first, Parser & p) throw()
        {
            TestSuite::check("Clause_test::onFail");
            first = _first;
        }

        void onFail_super(const Token & _first, Parser & p) throw()
        {   Clause::onFail(_first, p);   }
    };
}

TESTSUITE(main, Clause)
{
    SingletonBase::ContextChain chain;
    chain.saveContext<Namespace>();

    BEGIN_CASE("getClauseIdentifier","getClauseIdentifier") {
        BEGIN_CASE("1","���ʂ̎��ʎq�͂��̂܂܂����g�ɂȂ�") {
            Token token(Token::IDENTIFIER, "test");

            if(getClauseIdentifier(token).compare("test") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","���l�͒��g�Ɋ֌W�Ȃ�" INTEGER_CLAUSE_IDENTIFIER "���Ԃ�") {
            Token token(Token::INTEGER, "", "", 0);

            if(getClauseIdentifier(token).compare(INTEGER_CLAUSE_IDENTIFIER) != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","���e�����͒��g�Ɋ֌W�Ȃ�" LITERAL_CLAUSE_IDENTIFIER "���Ԃ�") {
            Token token(Token::LITERAL, "");

            if(getClauseIdentifier(token).compare(LITERAL_CLAUSE_IDENTIFIER) != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","���Z�q�͒��g�Ɋ֌W�Ȃ�" OPERATOR_CLAUSE_IDENTIFIER "���Ԃ�") {
            Token token(Token::OPERATOR);

            if(getClauseIdentifier(token).compare(OPERATOR_CLAUSE_IDENTIFIER) != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("5","�󔒂̃g�[�N���ɂ͋󕶎�(==���)���Ԃ�") {
            Token token(Token::SPACE);

            if(!getClauseIdentifier(token).empty())
                TEST_FAIL;
        } END_CASE;

        TEST_CASE("6","�G���[�g�[�N���ɂ͋󕶎�(==���)���Ԃ�", getClauseIdentifier(Token(Token::ERROR)).empty());
        TEST_CASE("7","EOS�g�[�N���ɂ͋󕶎�(==���)���Ԃ�",   getClauseIdentifier(Token(Token::END_OF_STREAM)).empty());

    } END_CASE;

    BEGIN_CASE("getClauseMap","getClauseMap") {
        BEGIN_CASE("1","�����o�^���Ă��Ȃ���Ԃɂ�NULL���Ԃ�") {
            chain.renewInstance();
            if(Clause::getClauseMap("unknown") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�v�f������Δ�0���Ԃ�") {
            chain.renewInstance();
            Singleton<Namespace>::getInstance()->operator []("test");

            if(Clause::getClauseMap("test") == 0)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("addClause","addClause") {
        BEGIN_CASE("1","�I�u�W�F�N�g��o�^�ł���") {
            chain.renewInstance();
            Clause_test ct;
            Clause_test ct2;

            BEGIN_CASE("1","���ʂɓo�^����") {
                ct.addClause("test","first_literal");

                TEST_CASE("1","���O��Ԃ������Ă���", Singleton<Namespace>::getInstance()->size() == 1);
                TEST_CASE("2","\"test\"�Ƃ�����Ԃ�����", Singleton<Namespace>::getInstance()->find("test") != Singleton<Namespace>::getInstance()->end());
                TEST_CASE("3","getClause�ŃA�h���X������", Clause::getClauseMap("test") != 0); 
                TEST_CASE("4","���O��Ԃ̐߂̐���1",  Clause::getClauseMap("test")->size() == 1);
                TEST_CASE("5","\"first_literal\"�̃m�[�h������", Clause::getClauseMap("test")->find("first_literal") != Clause::getClauseMap("test")->end());
                TEST_CASE("6","�֘A�t����ꂽ�l��������", (*Clause::getClauseMap("test"))["first_literal"] == &ct);
            } END_CASE;

            BEGIN_CASE("2","2�ڂ�o�^����") {
                ct2.addClause("test","second_literal");

                TEST_CASE("1","���O��Ԃ������Ă��Ȃ�", Singleton<Namespace>::getInstance()->size() == 1);
                TEST_CASE("2","\"test\"�Ƃ�����Ԃ�����", Singleton<Namespace>::getInstance()->find("test") != Singleton<Namespace>::getInstance()->end());
                TEST_CASE("3","���O��Ԃ̐߂̐���2",  Clause::getClauseMap("test")->size() == 2);
                TEST_CASE("4","\"second_literal\"�̃m�[�h������", Clause::getClauseMap("test")->find("second_literal") != Clause::getClauseMap("test")->end());
                TEST_CASE("5","�֘A�t����ꂽ�l��������", (*Clause::getClauseMap("test"))["second_literal"] == &ct2);
            } END_CASE;

            BEGIN_CASE("3","2�ڂ�1�ڂŏ㏑���o�^����") {
                ct.addClause("test","second_literal");
                TEST_CASE("1","�㏑������Ă���", (*Clause::getClauseMap("test"))["second_literal"] == &ct);
            } END_CASE;

            BEGIN_CASE("4","�Ⴄ���O��Ԃɓo�^����") {
                ct.addClause("TEST","first_literal");

                TEST_CASE("1","���O��Ԃ������Ă���", Singleton<Namespace>::getInstance()->size() == 2);
                TEST_CASE("2","\"TEST\"�Ƃ�����Ԃ�����", Singleton<Namespace>::getInstance()->find("TEST") != Singleton<Namespace>::getInstance()->end());
                TEST_CASE("3","getClause�ŃA�h���X������", Clause::getClauseMap("TEST") != 0); 
                TEST_CASE("4","���O��Ԃ̐߂̐���1",  Clause::getClauseMap("TEST")->size() == 1);
                TEST_CASE("5","\"first_literal\"�̃m�[�h������", Clause::getClauseMap("TEST")->find("first_literal") != Clause::getClauseMap("TEST")->end());
                TEST_CASE("6","�֘A�t����ꂽ�l��������", (*Clause::getClauseMap("TEST"))["first_literal"] == &ct);
            } END_CASE;

        } END_CASE;

        BEGIN_CASE("2","�����ȃI�u�W�F�N�g�͓o�^����Ȃ�") {
            chain.renewInstance();

            ((Clause_test *)0)->addClause("test","first_literal");

            TEST_CASE("1","���O��Ԃ������Ă��Ȃ�", Singleton<Namespace>::getInstance()->size() == 0);
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("hasClause","hasClause") {
        Clause_test ct;
        chain.renewInstance();

        TEST_CASE("1","�����v�f���Ȃ��Ƃ��ɂ�����ɓ��삷��", !Clause::hasClause("dummy","null"));

        ct.addClause("test","first_literal");

        TEST_CASE("2","�o�^�����v�f��T���Atrue���Ԃ�", Clause::hasClause("test","first_literal"));
        TEST_CASE("3","���݂��Ȃ��v�f��false���Ԃ�", !Clause::hasClause("dummy","null"));
    } END_CASE;

    BEGIN_CASE("addMultipleClauses","addMultipleClauses") {
        BEGIN_CASE("1","�P��̐߂�o�^�ł���") {
            chain.renewInstance();
            Clause_test ct;

            ct.addMultipleClauses("test","first");

            TEST_CASE("1","�o�^�����߂�����", Clause::hasClause("test","first"));
        } END_CASE;

        BEGIN_CASE("2","�����̐߂�o�^����") {
            chain.renewInstance();
            Clause_test ct;

            ct.addMultipleClauses("test","first,second,third");

            TEST_CASE("1","�o�^�����߂�����", Clause::hasClause("test","first"));
            TEST_CASE("2","�o�^�����߂�����", Clause::hasClause("test","second"));
            TEST_CASE("3","�o�^�����߂�����", Clause::hasClause("test","third"));
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("Clause::onFail","Clause::onFail") {
        stringstream buf;
        Parser p(&buf, "test");
        Token token;
        Clause_test ct;

        buf.str("first second third 4 5 6 siebt acht neunt 0xa");

        ct.onFail_super(token, p);
        TEST_CASE("1","�X�g���[���͍Ō�܂Ői��ł���", p.eof());
    } END_CASE;

    BEGIN_CASE("parseClause","parseClause") {
        chain.renewInstance();
        Clause_test ct;

        ct.addClause("test","first");

        BEGIN_CASE("1","���O��Ԃ�I�����Đ������߂����s�ł���") {
            stringstream buf;
            Parser p(&buf, "test");
            buf.str("first second");

            TestSuite::clearCheckpoints();
            TEST_CASE("1","�֐��͐�������", Clause::parseClause("test", p));
            TEST_CASE("2","Clause::before�����s����Ă���", TestSuite::isReached("Clause_test::before"));
            TEST_CASE("3","Clause::body�����s����Ă���", TestSuite::isReached("Clause_test::body"));
            TEST_CASE("4","body��first��������", ct.first == "first");
            TEST_CASE("5","body�œǂݏo�����g�[�N����������", ct.second == "second");
            TEST_CASE("6","Clause::after�����s����Ă���", TestSuite::isReached("Clause_test::after"));
        } END_CASE;

        BEGIN_CASE("2","�߂̏������ɗ�O���N�����onFail���Ă΂��") {
            stringstream buf;
            Parser p(&buf, "test");
            buf.str("first second");

            ct.throw_exception = true;
            TestSuite::clearCheckpoints();

            bool result = false;
            try { Clause::parseClause("test", p); }
            catch(...){ result = true; }

            TEST_CASE("1","��O���N����", result);
            TEST_CASE("2","Clause::body�����s����Ă���", TestSuite::isReached("Clause_test::body"));
            TEST_CASE("3","Clause::onFail�����s����Ă���", TestSuite::isReached("Clause_test::onFail"));
        } END_CASE;

        BEGIN_CASE("3","���݂��Ȃ����O��Ԃ��w�肷��") {
            stringstream buf;
            Parser p(&buf, "test");
            buf.str("first second");

            TEST_CASE("1","�֐��͎��s����", !Clause::parseClause("unknown", p));
        } END_CASE;

        BEGIN_CASE("4","EOF�ɒB�����X�g���[�����w�肷��") {
            stringstream buf;
            Parser p(&buf, "test");
            buf.str("");
            buf.get();

            TEST_CASE("0","[�O��]�X�g���[���͏I�[�ɒB���Ă���", buf.eof());
            TEST_CASE("1","�֐��͎��s����", !Clause::parseClause("unknown", p));
        } END_CASE;
    } END_CASE;

    chain.restoreContext();
}




namespace {
    class StaticAPI_test : public StaticAPI
    {
    public:
        StaticAPI_test(void) throw() : StaticAPI() {}
        StaticAPI_test(string src) throw() : StaticAPI(src) {}

        void body(const Token & , Parser &) { TestSuite::check("StaticAPI::body"); }
        void onFail_super(const Token & first, Parser & p) throw() { StaticAPI::onFail(first, p); }
    };
}

TESTSUITE(main, StaticAPI)
{
    Singleton<Namespace>::Context context;
    Singleton<Namespace>::saveContext(context);

    Exception::setThrowControl(true);

    BEGIN_CASE("regist","regist") {
        BEGIN_CASE("1","�P��̖��O���w�肵�ēo�^�ł���") {
            Singleton<Namespace>::renewInstance();
            StaticAPI_test api;

            api.regist("VTST_API");

            TEST_CASE("1","API�͐������o�^�ł��Ă���",StaticAPI::hasStaticAPI("VTST_API"));
        } END_CASE;

        BEGIN_CASE("2","�����̖��O���w�肵�ēo�^����") {
            Singleton<Namespace>::renewInstance();
            StaticAPI_test api;

            api.regist("API_1,API_2,API_3");

            TEST_CASE("1","API�͐������o�^�ł��Ă���",StaticAPI::hasStaticAPI("API_1"));
            TEST_CASE("2","API�͐������o�^�ł��Ă���",StaticAPI::hasStaticAPI("API_2"));
            TEST_CASE("3","API�͐������o�^�ł��Ă���",StaticAPI::hasStaticAPI("API_3"));
        } END_CASE;

        BEGIN_CASE("3","�㏑������") {
            Singleton<Namespace>::renewInstance();
            StaticAPI_test api;
            StaticAPI_test api2;
            StaticAPI_test api3;

            api.regist("test");
            TEST_CASE("1","API�͐������o�^�ł��Ă���",StaticAPI::hasStaticAPI("test"));
            TEST_CASE("2","API�n���h����������", (*StaticAPI::getClauseMap(NAMESPACE_STATICAPI))["test"] == &api);

            api2.regist("test");
            TEST_CASE("3","API�n���h�����㏑������Ă���", (*StaticAPI::getClauseMap(NAMESPACE_STATICAPI))["test"] == &api2);

            api3.regist("test");
            TEST_CASE("4","API�n���h�����㏑������Ă���", (*StaticAPI::getClauseMap(NAMESPACE_STATICAPI))["test"] == &api3);
        } END_CASE;

        BEGIN_CASE("4","�R���X�g���N�^�œo�^") {
            Singleton<Namespace>::renewInstance();
            StaticAPI_test api("API1,API2,API3");

            TEST_CASE("1","API�͐������o�^�ł��Ă���",StaticAPI::hasStaticAPI("API1"));
            TEST_CASE("2","API�͐������o�^�ł��Ă���",StaticAPI::hasStaticAPI("API2"));
            TEST_CASE("3","API�͐������o�^�ł��Ă���",StaticAPI::hasStaticAPI("API3"));
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("parseStaticAPI","parseStaticAPI") {
        BEGIN_CASE("1","�ÓIAPI�𐳂��������ł���") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            StaticAPI_test api("API");

            buf.str("API();");
            Parser p(&buf, "test");

            TestSuite::clearCheckpoints();
            bool result = true;
            try { StaticAPI::parseStaticAPI(p); }
            catch(...) { result = false; }

            TEST_CASE("1","��O�͋N��Ȃ�", result);
            TEST_CASE("2","�ÓIAPI�̖{�̂��Ă΂�Ă���", TestSuite::isReached("StaticAPI::body"));
        } END_CASE;

        BEGIN_CASE("2","'('�Y��ŗ�O") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            StaticAPI_test api("API");

            buf.str("API);");
            Parser p(&buf, "test");

            TestSuite::clearCheckpoints();
            bool result = false;
            try { StaticAPI::parseStaticAPI(p); }
            catch(...) { result = true; }

            TEST_CASE("1","��O���N��", result);
            TEST_CASE("2","�ÓIAPI�̖{�̂��Ă΂�Ȃ�", !TestSuite::isReached("StaticAPI::body"));
        } END_CASE;

        BEGIN_CASE("3","')'�Y��ŗ�O") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            StaticAPI_test api("API");

            buf.str("API(; NEXT");
            Parser p(&buf, "test");

            TestSuite::clearCheckpoints();
            bool result = false;
            try { StaticAPI::parseStaticAPI(p); }
            catch(...) { result = true; }

            TEST_CASE("1","��O���N��", result);
            TEST_CASE("2","�ÓIAPI�̖{�̂��Ă΂�Ă���", TestSuite::isReached("StaticAPI::body"));
        } END_CASE;

        BEGIN_CASE("4","';'�Y��ŗ�O") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            StaticAPI_test api("API");

            buf.str("API() NEXT");
            Parser p(&buf, "test");

            TestSuite::clearCheckpoints();
            bool result = false;
            try { StaticAPI::parseStaticAPI(p); }
            catch(...) { result = true; }

            TEST_CASE("1","��O���N��", result);
            TEST_CASE("2","�ÓIAPI�̖{�̂��Ă΂�Ă���", TestSuite::isReached("StaticAPI::body"));
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("onFail","onFail") {
        BEGIN_CASE("1","�Z�~�R�����܂œǂݔ�΂�") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            Parser p(&buf, "test");
            StaticAPI_test api;
            Token token;
            buf.str("api parameter;next_api next_api_parameter;");

            api.onFail_super(Token(), p);

            TEST_CASE("1","�Z�~�R�����̎����ǂ߂�", p.getToken() == "next_api");
        } END_CASE;

        BEGIN_CASE("2","����API�܂œǂݔ�΂�") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            Parser p(&buf, "test");
            StaticAPI_test api("api,next_api");
            buf.str("api parameter_1 parameter_2 next_api next_api_parameter;");

            api.onFail_super(p.getToken(), p);

            TEST_CASE("1","����API�����ǂ߂�", p.getToken() == "next_api");
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("skip","skip") {
        BEGIN_CASE("1","�Z�~�R�����܂œǂݔ�΂�") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            Parser p(&buf, "test");
            StaticAPI_test api;
            Token token;
            buf.str("api parameter;next_api next_api_parameter;");

            StaticAPI::skip(p);

            TEST_CASE("1","�Z�~�R�����̎����ǂ߂�", p.getToken() == "next_api");
        } END_CASE;

        BEGIN_CASE("2","����API�܂œǂݔ�΂�") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            Parser p(&buf, "test");
            StaticAPI_test api("api,next_api");
            buf.str("parameter_1 parameter_2 next_api next_api_parameter;");

            StaticAPI::skip(p);

            TEST_CASE("1","����API�������ǂ߂�", p.getToken() == "next_api");
        } END_CASE;

        BEGIN_CASE("3","�擪��API���ł��ǂݔ�΂��ł���") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            Parser p(&buf, "test");
            StaticAPI_test api("api,next_api");
            buf.str("api parameter_1 parameter_2 next_api next_api_parameter;");

            StaticAPI::skip(p);

            TEST_CASE("1","����API�����ǂ߂�", p.getToken() == "next_api");
        } END_CASE;
    } END_CASE;
    
    Singleton<Namespace>::restoreContext(context);
}


namespace {
    class Directives_test : public Directives
    {
    public:
        bool throws;

        Directives_test(void) throw() : Directives(), throws(false) {}
        Directives_test(string src) throw() : Directives(src), throws(false)  {}

        void body(const Token & , Parser & ) throw(int)
        {
            TestSuite::check("Directives::body");
            if(throws)
                throw 0;
        }
    };
}

TESTSUITE(main, Directives)
{
    Singleton<Namespace>::Context context;
    Singleton<Namespace>::saveContext(context);

    Exception::setThrowControl(true);

    BEGIN_CASE("regist","regist") {
        BEGIN_CASE("1","�P��̖��O���w�肵�ēo�^�ł���") {
            Singleton<Namespace>::renewInstance();
            Directives_test api;

            api.regist("include");

            TEST_CASE("1","API�͐������o�^�ł��Ă���",Directives::hasDirectives("include"));
        } END_CASE;

        BEGIN_CASE("2","�����̖��O���w�肵�ēo�^����") {
            Singleton<Namespace>::renewInstance();
            Directives_test api;

            api.regist("pragma,define,endif");

            TEST_CASE("1","�f�B���N�e�B�u�͐������o�^�ł��Ă���",Directives::hasDirectives("pragma"));
            TEST_CASE("2","�f�B���N�e�B�u�͐������o�^�ł��Ă���",Directives::hasDirectives("define"));
            TEST_CASE("3","�f�B���N�e�B�u�͐������o�^�ł��Ă���",Directives::hasDirectives("endif"));
        } END_CASE;

        BEGIN_CASE("3","�㏑������") {
            Singleton<Namespace>::renewInstance();
            Directives_test api;
            Directives_test api2;
            Directives_test api3;

            api.regist("test");
            TEST_CASE("1","�f�B���N�e�B�u�͐������o�^�ł��Ă���",Directives::hasDirectives("test"));
            TEST_CASE("2","�f�B���N�e�B�u�n���h����������", (*Directives::getClauseMap(NAMESPACE_DIRECTIVES))["test"] == &api);

            api2.regist("test");
            TEST_CASE("3","�f�B���N�e�B�u�n���h�����㏑������Ă���", (*Directives::getClauseMap(NAMESPACE_DIRECTIVES))["test"] == &api2);

            api3.regist("test");
            TEST_CASE("4","�f�B���N�e�B�u�n���h�����㏑������Ă���", (*Directives::getClauseMap(NAMESPACE_DIRECTIVES))["test"] == &api3);
        } END_CASE;

        BEGIN_CASE("4","�R���X�g���N�^�œo�^") {
            Singleton<Namespace>::renewInstance();
            Directives_test api("pragma,define,endif");

            TEST_CASE("1","�f�B���N�e�B�u�͐������o�^�ł��Ă���",Directives::hasDirectives("pragma"));
            TEST_CASE("2","�f�B���N�e�B�u�͐������o�^�ł��Ă���",Directives::hasDirectives("define"));
            TEST_CASE("3","�f�B���N�e�B�u�͐������o�^�ł��Ă���",Directives::hasDirectives("endif"));
        } END_CASE;
    } END_CASE;
    
    BEGIN_CASE("parseDirectives","parseDirectives") {
        BEGIN_CASE("1","�f�B���N�e�B�u�𐳂��������ł���") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            Directives_test api("pragma");

            buf.str("pragma\nnext\n");
            Parser p(&buf, "test");

            TestSuite::clearCheckpoints();
            bool result = true;
            try { Directives::parseDirectives(p); }
            catch(...) { result = false; }

            TEST_CASE("1","��O�͋N��Ȃ�", result);
            TEST_CASE("2","�f�B���N�e�B�u�̖{�̂��Ă΂�Ă���", TestSuite::isReached("Directives::body"));
        } END_CASE;

        BEGIN_CASE("2","���s�Ȃ�(�s���p�����[�^)�ŗ�O") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            Directives_test api("pragma");

            buf.str("pragma next\n");
            Parser p(&buf, "test");

            TestSuite::clearCheckpoints();
            bool result = false;
            try { Directives::parseDirectives(p); }
            catch(...) { result = true; }

            TEST_CASE("1","��O���N��", result);
            TEST_CASE("2","�f�B���N�e�B�u�̖{�̂��Ă΂�Ă���", TestSuite::isReached("Directives::body"));
        } END_CASE;

        BEGIN_CASE("3","���s�Ȃ�(EOF)�ŗ�O") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            Directives_test api("pragma");

            buf.str("pragma");
            Parser p(&buf, "test");

            TestSuite::clearCheckpoints();
            bool result = false;
            try { Directives::parseDirectives(p); }
            catch(...) { result = true; }

            TEST_CASE("1","��O���N��", result);
            TEST_CASE("2","�f�B���N�e�B�u�̖{�̂��Ă΂�Ă���", TestSuite::isReached("Directives::body"));
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("onFail","onFail") {
        BEGIN_CASE("1","body�ŗ�O���N���onFail�����̉��s�܂œǂݔ�΂�") {
            Singleton<Namespace>::renewInstance();
            stringstream buf;
            Directives_test api("pragma");
            buf.str("pragma parameter\nnext\n");
            Parser p(&buf, "test");

            api.throws = true;
            bool result = false;
            try { Directives::parseDirectives(p); }
            catch(...) { result = true; }

            TEST_CASE("1","��O���N��", result);
            TEST_CASE("2","�c�������e��������", p.getToken() == "next");
            TEST_CASE("3","�g�[�N���͍s��", p.isHeadofLine());
        } END_CASE;
    } END_CASE;
            
    Singleton<Namespace>::restoreContext(context);
}

#endif



