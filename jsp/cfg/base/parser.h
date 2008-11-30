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
 *  @(#) $Id: parser.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/parser.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef PARSER_H
#define PARSER_H

#include "base/defs.h"

#include "base/message.h"

#include "base/directorymap.h"
#include "base/component.h"

#include <stdarg.h>
#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

#define PARSERESULT         "/parse_result"

#ifndef  ERROR
#undef   ERROR   /* MinGW������wingdi.h��ERROR����`����� */
#endif

class Token : public std::string
{
        //�����o�̉B���͂��Ȃ�
public:
    enum tagTokenType
    {
        IDENTIFIER      = 0x01,
        INTEGER         = 0x02,
        STRINGLITERAL   = 0x03,
        STRING          = 0x04,
        OPERATOR        = 0x05,
        PUNCTUATOR      = 0x06,
        RESERVEDWORD    = 0x07,
        SPECIAL         = 0x80,
        SPACE           = 0x81,
        UNKNOWN         = 0xfd,
        ERROR           = 0xfe,
        EOS             = 0xff      //End of Stream
    };

    enum tagTokenType   type;
    long                value;
    unsigned int        line;

    Token(void)                 { type = UNKNOWN;  value = 0;   };
    Token(const Token & src)    { (*this) = src; };
    Token(enum tagTokenType, const char *);

    operator const enum tagTokenType (void) const { return type; };

    Token & operator =(const Token & src);
    bool operator == (const Token & src) const;

    Token & trim(void);
    Token & chopLiteral(void);
    void    confirm(const char *) const;
};

class Parser
{
public:
    enum tagFunctionarities
    {   UNKNOWN = 0, DIRECTIVE = 1, LOGGING = 2 };

    struct tagFile
    {
        std::string    identifier;
        std::istream * stream;
        unsigned int   line;
    };

protected:
    static const char * Punctuator;
    static const char * Operator;
    static Token        lastErrorToken;
    
    std::string *       LogBuffer;
    unsigned int        PutBackCount;
    bool                isHeadofLine;

    Directory *         Container;

    tagFile *             current;
    std::list<Token>      TokenStack;
    std::list<tagFile *>  fileStack;
    int                   functionalities;

    std::string           preprocessname;   //�v���v���Z�b�T��ʂ��Ƃ��Ɏg�������O
    std::string           originalname;     //�{���̖��O

    bool parseDirectives(Token &, int, bool);

    bool getIdentifier(Token &, int);
    bool getWhitespace(Token &, int, bool);
    bool getInteger(Token &, int);
    bool getStringLiteral(Token &, int);
    bool getOperator(Token &, int);

    int  getChar(void);
    void putBack(int);

    void initialize(void) { current = 0; functionalities = DIRECTIVE|LOGGING; PutBackCount = 0; LogBuffer = 0; isHeadofLine = true; };

    bool isenabled(enum tagFunctionarities func)  { return (functionalities & (int)func) != 0; };

public:
    Parser(Directory & cnt) : Container(&cnt) { initialize(); };
    Parser(Directory * cnt) : Container(cnt)  { initialize(); };
    ~Parser(void);

    void pushStream(const std::string & filename, std::string = "");
    void pushStdStream(std::string = "Standard Input");

    void setStreamIdentifier(const std::string & id);
    void setCurrentLine(unsigned int pos) { current->line = pos; };
    unsigned int getCurrentLine(void);
    const char * getStreamIdentifier(void);
    std::string getStreamLocation(void);

    enum Token::tagTokenType getToken(Token &,bool = false);
    void getToken(Token &,enum Token::tagTokenType, const char * = NULL);
    void getToken(const char *) throw(Exception);
    void getToken(const char *, const char * , const char * = 0, const char * = 0) throw(Exception);

    void putBack(Token &);

    static const Token & getLastErrorToken(void) { return lastErrorToken; };

    void enable(enum tagFunctionarities func)  { functionalities |=  (int)func; };
    void disable(enum tagFunctionarities func) { functionalities &= ~(int)func; };

    std::string *  setLogBuffer(std::string * buffer);
    std::streampos getLogBufferPos(int offset = 0);

    void doPreProcess(const char * cmd);
};


//---

class ParseUnit
{
protected:
    static Token & parseParameter(Parser &);
    static int     parseParameters(Parser &, Directory *, int, int=0);
    static int     parseParameters(Parser &, Directory *, const char *);

public:
    ParseUnit(void *, const char *);
    virtual ~ParseUnit(void) {};

    const char * getIdentifier(void) const;
    virtual void body(const std::string &, Directory &, Parser &, const std::string &) =0;

    static void printList(void * container);
};

#define __DECLARE_PARSEUNIT(x,y,z) class x##_##y : public x { public: x##_##y(void) : x(z) {}; protected: virtual void body(const std::string &, Directory &, Parser &, const std::string &); } instance_of_##x##_##y; void x##_##y::body(const std::string & identifier, Directory & container, Parser & p, const std::string & domain)

//---

class StaticAPI : public ParseUnit
{
protected:
    static Directory * last;
    Directory * allocate(Parser & p, Directory &, const Token &, const char *, bool = true);
    Directory * allocate(Directory &, const Token &, const char *, bool = true);
    Directory * find    (Directory &, const Token &, const char *);

public:
    StaticAPI(const char * name) : ParseUnit(&(container()), name) {};

    static void printList(void)         { ParseUnit::printList(&(container())); };
    static void clearLastObject(void)   { last = NULL; };
    static void dropLastObject(void);

    static std::map<std::string, class ParseUnit *> & container(void);
};

#define DECLARE_API(x,y) __DECLARE_PARSEUNIT(StaticAPI,x,y)

//---

class Directive : public ParseUnit
{
public:
    static std::map<std::string, class ParseUnit *> & container(void);

    Directive(const char * name) : ParseUnit(&(container()), name) {};
    static void printList(void) { ParseUnit::printList(&(container())); }
};

#define DECLARE_DIRECTIVE(x,y) __DECLARE_PARSEUNIT(Directive,x,y)

//---

class ParserComponent : public Component
{
protected:
    int  failCount;
    bool ignoreUnknownAPI;

    static void throughConfigurationFile(std::string & log, Directory & container);

    virtual void parseOption(Directory &);    
    virtual void body(Directory &);

    bool         parseStaticAPI(Parser & p, Directory & container, Token token, const std::string = "");

    virtual bool parse(Parser & p, Directory & container) = 0;

public:
    ParserComponent(void) throw();
    virtual ~ParserComponent(void) throw();
};

//---

namespace Common {
    
    enum tagAssignmentOrder { UNKNOWN, ALPHABETIC, FCFS, REVERSE=0x80, REVERSE_ALPHABETIC, REVERSE_FCFS };

    enum tagAssignmentOrder parseOrder(Directory * order_option_node);
    enum tagAssignmentOrder parseOrder(OptionParameter::OptionItem order_option_node);
    int assignID(Directory & container, const char * category, const char * top, enum tagAssignmentOrder = FCFS);
}

//---

inline Token::Token(enum tagTokenType type, const char * term)
{
    type = type;
    value = 0;
    assign(term);
}

inline Token & Token::operator =(const Token & src)
{   
    type = src.type; 
    value = src.value; 
    line = src.line;
    assign(src); 
    return *this;   
}

inline bool Token::operator ==(const Token & src) const
{
    if(type != src.type)
        return false;
    if(type == Token::INTEGER && value != src.value)
        return false;
    else
        if(compare(src) != 0)
            return false;

    return true;
}

inline void Token::confirm(const char * str) const
{
    if(compare(str) != 0)
        ExceptionMessage("Illegal token (%) appears during parse process.","�����͂̓r���ŕs���ȃg�[�N��(%)���o�����܂���") << str << throwException;
}

inline void Parser::getToken(Token & token, enum Token::tagTokenType type, const char * term)
{
    getToken(token, type == Token::SPACE);

    if(type == Token::STRING && token == Token::STRINGLITERAL)
        token.chopLiteral();

    if((type != token) || (term != NULL && token.compare(term) != 0))
    {
        lastErrorToken = token;
        ExceptionMessage("Parse error on reading [%]","�����͂̃G���[ [%]") << token << throwException;
    }
}

inline void Parser::putBack(Token & token)
{   TokenStack.push_front(token);   }

inline Directory * StaticAPI::find(Directory & container, const Token & token, const char * id)
{
    Directory * node;

    node = container.findChild(id,token.c_str(),NULL);
    if(node == 0)
        ExceptionMessage("The object %(%) does not exist.","�I�u�W�F�N�g%(%)�͖���`�ł�") << token << throwException;

    return node;
}

inline void StaticAPI::dropLastObject(void)
{
    if(last != NULL)
    {
        last->erase();
        last = NULL;
    }
}

inline Directory * StaticAPI::allocate(Parser & p, Directory & container, const Token & token, const char * category, bool regist)
{
    Directory * node = allocate(container, token, category, regist);
    if(node != 0)
        (*node)["position"] = p.getStreamLocation();
    return node;
}

inline void Parser::setStreamIdentifier(const std::string & id)
{
    if(preprocessname.compare(id) != 0)
        current->identifier = id;
    else
        current->identifier = originalname;
}

#endif
