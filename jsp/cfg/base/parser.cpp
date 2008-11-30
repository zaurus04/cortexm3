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
 *  @(#) $Id: parser.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */



// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/parser.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/defs.h"
#include "base/parser.h"
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

/*
 *  �擪�Ɩ����ɂ���󔒕�������菜��
 */
Token & Token::trim(void)
{
    string::iterator scope;

        /* ������ */
    scope = begin();
    while(*scope == ' ' || *scope == '\t' || *scope == '\r' || *scope == '\n')
        ++ scope;
    erase(begin(), scope);

    if(!empty())
    {
            /* ������ */
        scope = end();
        do {
            -- scope;
        } while(*scope == ' ' || *scope == '\t' || *scope == '\r' || *scope == '\n');
        ++ scope;
        erase(scope, end());
    }
    return *this;
}


 /*
  *  �����񃊃e�����̓W�J (�_�u���N�H�[�g�̎�菜�� + �G�X�P�[�v�V�[�P���X�̓W�J)
  */
Token & Token::chopLiteral(void)
{
    if(type != STRINGLITERAL)
        return *this;

    string::iterator scope;

        //�G���[�����̂��߂ɔ�j�󏈗�������
    string src(*this);
    string work;

    if(src[0] != '"' || src[src.length()-1] != '"')
        return *this;

    src = src.substr(1, src.length()-2);

    scope = src.begin();
    while(scope != src.end())
    {
        if(*scope == '\\')
        {
                //���e�����̖�����\�ŏI��邱�Ƃ͂Ȃ��̂Ń`�F�b�N���Ȃ�
            ++ scope;
            switch(*scope)
            {
            case '"':   work += '"';   break;
            case 't':   work += '\t';  break;
            case 'r':   work += '\r';  break;
            case 'n':   work += '\n';  break;
            case 'b':   work += '\b';  break;
            case '\\':   work += '\\';  break;
            default:
                ExceptionMessage("Illegal escape sequence [\\%]","�G�X�P�[�v�V�[�P���X[\\%]�͕s���ł�") << *scope << throwException;
            }
        }else
            work += *scope;

        ++ scope;
    }

    type = STRING;
    assign(work);
    value = this->length();

    return *this;
}

    /* ��؂蕶�� (�ꕶ�������ňӖ��𐬂�����) */
const char * Parser::Punctuator =
    ",;(){}";

    /* ���Z�q (���ꕶ������Ȃ镶��) */
const char * Parser::Operator =
    "+-*/&|%^~!?[]=:.#";

Token Parser::lastErrorToken;


 /*
  *  �X�g���[������ꕶ�������؂�o��
  */
inline int Parser::getChar(void)
{
    int work = current->stream->get();

        /* �s�ԍ��̏��� */
    if(work == '\n')
        current->line ++;
    
        /* �X�g���[�����O�̂��߂̏��� */
    if(PutBackCount == 0)
    {
        if(LogBuffer != 0 && isenabled(LOGGING))
            *LogBuffer += static_cast<char>(work);
    }else
        PutBackCount --;    //���łɓǂݍ���ł���

    return work;
}

 /*
  *  ���o���������������X�g���[���ɕԂ�
  */
inline void Parser::putBack(int ch)
{
        /* �s�ԍ��̂��߂̏��� */
    if(ch == '\n')
        current->line --;

        /* �X�g���[�����O�̂��߂̏��� */
    PutBackCount ++;

    current->stream->putback(ch);
}

 /*
  *  Parser�N���X�̃f�X�g���N�^
  */
Parser::~Parser(void)
{
    list<tagFile *>::iterator scope;

        /* �Ō�܂Ńp�[�X���ĂȂ��Ȃ�A�Ƃ肠�����X�^�b�N�ɓ���Ă��� */
    if(current != 0)
        fileStack.push_front(current);

        /* �X�^�b�N�̒��g�S����j�� */
    scope = fileStack.begin();
    while(scope != fileStack.end())
    {
        if((*scope)->stream != 0 && (*scope)->stream != &cin)
            delete (*scope)->stream;        //�X�g���[���̔j��
        delete (*scope);                    //�\���̂̃f�[�^�̈�̔j��

        ++ scope;
    }

        /* �O�̂��� */
    fileStack.clear();
    TokenStack.clear();
}


 /*
  *  ���ʎq�̐؏o�� (���ʎq = [a-zA-Z_][0-9a-zA-Z_]*)
  */
bool Parser::getIdentifier(Token & token,int ch)
{
    token.value = 0;

    do {
        token.value ++;
        token += static_cast<char>(ch);
        ch = getChar();
    } while( (ch >='a' && ch <= 'z') || (ch >='A' && ch <= 'Z') || (ch == '_') || (ch >= '0' && ch <= '9') );

    if(ch != -1)
        putBack(static_cast<char>(ch));

    token.type = Token::IDENTIFIER;
    return true;
}


 /*
  *  �f�B���N�e�B�u�̐؏o���Ə���
  */
bool Parser::parseDirectives(Token & token, int ch, bool allow_space)
{
    Token directive;
    map<string, ParseUnit *>::iterator scope;

        //�󔒓ǂݔ�΂�
    do {
        token += static_cast<char>(ch);
        ch = getChar();
    } while(ch == ' ' || ch == '\t');
    
    if(ch >= '0' && ch <= '9')
    {
            //GNU-cpp line�f�B���N�e�B�u �΍�
        directive.assign("line");
        this->putBack(ch);
    }else
    {
            //�f�B���N�e�B�u�̓ǂݏo��
        putBack(ch);
        getToken(directive);
        token += directive;
    }

        //line�f�B���N�e�B�u�̉��
    if(directive.compare("line") == 0)
    {
        Token token;

        getToken(token, Token::INTEGER);
        setCurrentLine(token.value -1);

        getToken(token, Token::STRINGLITERAL);
        try {
            token.chopLiteral();
        }
        catch(Exception &) {
            token.assign("Unknown");
        }
        setStreamIdentifier(token);

        return true;
    }

        //pragma�f�B���N�e�B�u�̉��
    if(directive.compare("pragma") == 0)    
    {
        getToken(directive);
        token += " ";
        token += directive;

        if((scope = Directive::container().find(directive)) != Directive::container().end())
        {
            (*scope).second->body(directive, *Container, *this, string(""));

                //�]���ȃg�[�N���̓ǂݔ�΂�
            if(!TokenStack.empty())
            {
                do {
                    token = TokenStack.front();
                    TokenStack.pop_front();
                } while(!TokenStack.empty() && !allow_space && token.type == Token::SPACE);

                return true;
            }
        }
    }

        //include�f�B���N�e�B�u�̉��
    if(directive.compare("include") == 0)
    {
        cerr << getStreamLocation() << Message(": Configurator found 'include' directive\nKernel configuration file must be preprocessed.\n",": #include�f�B���N�e�B�u�𔭌����܂���\n �J�[�l���\���t�@�C����C�v���v���Z�b�T��ʉ߂�����K�v������܂�\n");
        ExceptionMessage("Illegal kernel configuration file","�s���ȃJ�[�l���\���t�@�C��").throwException();
    }

    putBack(directive);
    return false;
}


 /*
  *  �󔒕����̐؏o��
  *    �E�X�y�[�X, �^�u   �E#�Ŏn�܂��ĉ��s�܂�    �EC����̃R�����g�u���b�N
  *    �E2�A�̃X���b�V��(//)������s�܂�
  *    �E���4��g�ݍ��킹������
  */
bool Parser::getWhitespace(Token & token, int ch, bool allow_space)
{
    int prev;

    token.type = Token::SPACE;
    switch(ch)
    {
    case '/':
        ch = getChar();

        switch(ch)
        {
            /* �R�����g�u���b�N */
        case '*':
            token += "/*";
            prev = '\x0';
            while( ((ch = getChar()) != '/') || (prev!='*'))
            {
                token += static_cast<char>(ch);
                prev = ch;
            }
            token += static_cast<char>(ch);
            break;

            /* �_�u���X���b�V�� */
        case '/':
            token += '/';
            do {
                token += static_cast<char>(ch);
            } while( (ch = getChar()) != '\n' );
            break;

            /* ����'/'�Ŏn�܂��������ł��� */
        default:
            putBack(ch);
            return getOperator(token, '/');;
        }
        break;

        /* # �Ŏn�܂�s */
    case '#':
            /* �f�B���N�e�B�u������ or ����ȃf�B���N�e�B�u�͒m��Ȃ� */
        if(! (isenabled(DIRECTIVE) && parseDirectives(token, ch, allow_space)) )
        {
                //���s�܂œǂݔ�΂�
            TokenStack.clear();
            do {
                token += static_cast<char>(ch);
                ch = getChar();
            } while(ch != '\n');
            putBack(ch);
        }
        break;

        /* ���Ɍ����󔒕��� */
    case ' ':
    case '\t':
    case '\n':
    case '\r':
        do {
            token += static_cast<char>(ch);
            ch = getChar();
        } while((ch == ' ') || (ch == '\n') || (ch == '\r') || (ch == '\t'));
        putBack(static_cast<char>(ch));
        break;
    }
    return true;
}

 /*
  *  �����l�̐؏o�� (8/10/16�i, ����/����)
  *   �E2�i�͕s�]�������̂ł�߂܂���
  */
bool Parser::getInteger(Token & token, int ch)
{
    bool minus = false; 

    if(ch == '-')
    {
        minus = true;
        ch = getChar();
        if(ch < '0' || ch >'9')
        {
            putBack(static_cast<char>(ch));
            return false;
        }
        token += "-";
    }

    token.type = Token::INTEGER;
    token.value = 0;

    if(ch == '0')
    {
        token += static_cast<char>(ch);
        ch = getChar();
        if(ch == 'x' || ch == 'X')
        {
            token += static_cast<char>(ch);
            ch = getChar();
            while((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))
            {
                token += static_cast<char>(ch);
                if((ch -= '0') >= 10)
                {
                    ch = ch + '0' - 'A' + 10;
                    if(ch >= 16)
                        ch = ch - ('a' - 'A');
                }
                token.value = token.value * 16 + ch;
                ch = getChar();
            }
        }else
        {
            while(ch >= '0' && ch <= '7')
            {
                token += static_cast<char>(ch);
                token.value = token.value * 8 + ch - '0';
                ch = getChar();
            }
        }
    }else
    {
        do {
            token += static_cast<char>(ch);
            token.value = token.value * 10 + ch - '0';
            ch = getChar();
        } while(ch >= '0' && ch <= '9');
    }

        /* integer-suffix */
    if(ch != -1)
    {
        bool unsigned_suffix = false;
        bool long_suffix     = false;

        int  first_longsuffix;

        if(ch == 'u' || ch == 'U')
        {
            unsigned_suffix = true;
            token += static_cast<char>(ch);
            ch = getChar();
        }

        if(ch == 'i' || ch == 'I')  //i8, i16, i32, i64
        {
            int  first, second;
            bool accept = false;
            const signed char suffix_list[10] = { -1, '6', -1, '2', -1, -1, '4', -1, 0, -1};    //8, 16, 32, 64�݂̂���

            first  = getChar();
            second = -1;
            if(first >= '0' && first <= '9')
            {
                if(suffix_list[first - '0'] > 0)
                {
                    second = getChar();
                    if(second == suffix_list[first - '0'])
                        accept = true;
                }else
                    if(suffix_list[first - '0'] == 0)
                        accept = true;
            }

            if(!accept)
            {
                if(second != -1)
                    putBack(second);
                putBack(first);
            } else
            {
                token += static_cast<char>(ch);
                token += static_cast<char>(first);
                if(second != -1)
                    token += static_cast<char>(second);
                ch = getChar();
            }
        } else
        {
            if(ch == 'l' || ch == 'L')
            {
                first_longsuffix = ch;
                long_suffix = true;

                token += static_cast<char>(ch);
                ch = getChar();
                if(ch == first_longsuffix)
                {
                    token += static_cast<char>(ch);
                    ch = getChar();
                }
            }

            if(!unsigned_suffix && (ch == 'u' || ch == 'U'))
            {
                token += static_cast<char>(ch);
                ch = getChar();
            }
        }
    }

    if(minus)
        token.value = - token.value;

    if(ch != -1)
        putBack(static_cast<char>(ch));

    return true;
}


 /*
  *  �I�y���[�^(���ꕶ���̑g��������Ȃ�g�[�N��)�̐؏o��
  */
bool Parser::getOperator(Token & token, int ch)
{
    const char * work;

        /* ch���I�y���[�^�����ł��邩�ǂ����m���߂� */
    for(work = Operator;*work != '\x0' && *work != ch;work++);
    if(*work == '\x0')
        return false;

        /* �㑱���镶�����I�y���[�^�����ł��邩�ǂ����m���߂� */
    do {
        token += static_cast<char>(ch);
        ch = getChar();
        for(work = Operator;*work != '\x0' && *work != ch;work++);
    } while(*work != '\x0');

    putBack(ch);
    token.type = Token::OPERATOR;
    return true;
}


 /*
  *  �����񃊃e���� (�_�u���N�H�[�g�Ŋ���ꂽ����)
  *    �E�V���O���N�H�[�g�������悤�ɂ���
  *
  *    VisualStudio6.0�ŃR���p�C�������ꍇ�A���s��LF�̃t�@�C���ɑ΂���tellg���
  *    get�����EOF���Ԃ邽�߁A���������R�����g�A�E�g���Ă����B
  */
bool Parser::getStringLiteral(Token & token, int delimitor)
{
    int ch;
    int prev;

    ch = delimitor;

    token.value = 1;
    token.type = Token::STRINGLITERAL;
    token.assign("");
    token += static_cast<char>(ch);

    while(!current->stream->bad() && !current->stream->eof())
    {
        prev = ch;
        ch = getChar();
        token += static_cast<char>(ch);
        token.value ++;

        if(ch == delimitor && prev != '\\')
            return true;
    }

        //����������čăI�[�v�����āA���e�����J�n�� " �̎��Ɉړ�
    
    ExceptionMessage(ExceptionMessage::FATAL, "Unterminated string literal appeared.","�����Ă��Ȃ��������e���������o���܂���").throwException();
    return false;
}


 /*
  *  �g�[�N���̐؏o��
  */
enum Token::tagTokenType Parser::getToken(Token & token, bool allow_space)
{
    int ch;
    const char * work;

    do {
        token.erase();
        token.type = Token::ERROR;
        token.value = 0;

            //�g�[�N���X�^�b�N����؂�o��
        if(!TokenStack.empty())
        {
            do {
                token = TokenStack.front();
                TokenStack.pop_front();
            } while(!TokenStack.empty() && !allow_space && token.type == Token::SPACE);

            if(!allow_space && token.type != Token::SPACE)
                return token.type;
        }

            //�X�g���[������؂�o��
        if(current == NULL || current->stream == NULL || current->stream->bad())
        {
            token.assign("<End of stream>");
            return (token.type = Token::EOS);
        }

            //�J�����g�̃X�g���[������ɂȂ���
        if(current->stream->eof())
        {
                //�t�@�C���X�^�b�N���玟�̃X�g���[�������
            if(!fileStack.empty())
            {
                if(current->stream != &cin)
                    delete current->stream;
                delete current;
                
                current = *fileStack.begin();
                fileStack.pop_front();
            }else
            {
                token.assign("<End of stream>");
                return (token.type = Token::EOS);
            }
        }

        ch = getChar();

            //First(whitespaces) is [ \n\t\r/#]
        if( (ch == ' ') || (ch == '\t') || (ch == '\n') || (ch == '\r') || (ch == '/') || (isHeadofLine && ch == '#'))
        {
            if(ch == '\n')
                isHeadofLine = true;

            if(getWhitespace(token, ch, allow_space))
                if((token == Token::SPACE && allow_space) || !(token == Token::SPACE || token == Token::ERROR))
                    return token.type;

            continue;
        }else
            break;
    }while(true);

    isHeadofLine = false;

    token.line = current->line;

        //First(identifier) is [a-zA-Z_]
    if( (ch >='a' && ch <= 'z') || (ch >='A' && ch <= 'Z') || (ch == '_') )
        if(getIdentifier(token, ch))
            return Token::IDENTIFIER;

        //First(integer) is [\-0-9]
    if( (ch >='0' && ch <='9') || (ch == '-') )
        if(getInteger(token,ch))
            return Token::INTEGER;

        //First(string) is ["']
    if( ch == '"' || ch == '\'')
        if(getStringLiteral(token,ch))
            return Token::STRINGLITERAL;

        //Operator
    if(getOperator(token,ch))
        return Token::OPERATOR;

        //Punctuator
    work = Punctuator;
    while(*work != '\x0')
        if( *(work++) == ch )
        {
            token += static_cast<char>(ch);
            return (token.type = Token::PUNCTUATOR);
        }

    token += static_cast<char>(ch);
    token.type = Token::UNKNOWN;
    return Token::UNKNOWN;
}


 /*
  *  �g�[�N���p �X�g���[���I�y���[�^ (��Ƀe�X�g�ړI)
  */
ostream & operator << (ostream & out, Token & src)
{
    switch(src.type)
    {
    case Token::IDENTIFIER:
        out << "<IDENTIFIER:["; break;
    case Token::INTEGER:
        out << "<INTEGER:["; break;
    case Token::STRINGLITERAL:
        out << "<STRINGLITERAL:["; break;
    case Token::STRING:
        out << "<STRING:["; break;
    case Token::OPERATOR:
        out << "<OPERATOR:["; break;
    case Token::PUNCTUATOR:
        out << "<PUNCTUATOR:["; break;
    case Token::RESERVEDWORD:
        out << "<RESERVEDWORD:["; break;
    case Token::SPECIAL:
        out << "<SPECIAL:["; break;
    case Token::SPACE:
        out << "<SPACE:["; break;
    case Token::UNKNOWN:
        out << "<UNKNOWN>"; return out;
    case Token::ERROR:
        out << "<ERROR>"; return out;
    default:
        out << "<???:[";
    }

    return out << static_cast<string &>(src) << "]("<<src.value<<")>";
}

 /*
  *  �\���̐؏o��(�Ƃ��������m�F)
  */
void Parser::getToken(const char * term) throw(Exception)
{
    Token token;

    if(term == NULL)
        ExceptionMessage("Internal: GetToken received an empty string as reserved word.","�����G���[: GetToken�ɋ󕶎��񂪓n����܂���").throwException();

    getToken(token, false);
    if(token.compare(term) != 0) {
        lastErrorToken = token;
        ExceptionMessage("Token [%] should be replaced by [%]","����[%]��[%]�ł���ׂ��ł�") << token << term << throwException;
    }
}

void Parser::getToken(const char * first, const char * second, const char * third, const char * fourth) throw(Exception)
{
    getToken(first);
    if(second != NULL)
        getToken(second);
    if(third != NULL)
        getToken(third);
    if(fourth != NULL)
        getToken(fourth);
}

string Parser::getStreamLocation(void)
{
    list<tagFile *>::iterator scope;

    string location;
    char buffer[16];

    if(current == 0)
        return string("");

    ::sprintf(buffer, ":%d", current->line);
    location += current->identifier;
    location += buffer;

    if(!fileStack.empty())
    {
        location += " (included at ";

        scope = fileStack.begin();
        while(scope != fileStack.end())
        {
            ::sprintf(buffer, ":%d, ", (*scope)->line);
            location += (*scope)->identifier;
            location += buffer;

            ++ scope;

        }

        location.erase(location.size()-2);
        location += ")";
    }

    return location;
}

void Parser::pushStream(const std::string & filename, std::string strid)
{
    fstream * fin;

    if(current != 0)
        fileStack.push_front(current);
        
    fin = new fstream(filename.c_str(),ios::in);

    if(fin->is_open())
    {
        if(strid.size() == 0)
            strid = filename;

        current = new tagFile;
        current->stream     = fin;
        current->identifier = strid;
        current->line       = 1;
    }else
    {       
        ExceptionMessage("File operation failure : [%]","�t�@�C������Ɏ��s���܂��� [%]") << filename << throwException;
        delete fin;
    }
}

void Parser::pushStdStream(std::string strid)
{
    stringstream * work = new stringstream;
    char buffer[1024];
    int  count;

        //�W�����͂̏������ׂĎ�荞�� (�G���[�Ώ��p�� seekg/tellg ���g������)
    do {
        cin.read(buffer, 1024);
        count = cin.gcount();
        work->write(buffer, count);
    } while(count != 0);

    if(current != 0)
        fileStack.push_front(current);

    current = new tagFile;
    current->stream     = work;
    current->identifier = strid;
    current->line       = 1;
}

string * Parser::setLogBuffer(string * buffer)
{
    string * old = LogBuffer;
    LogBuffer = buffer;
    PutBackCount = 0;
    return old;
}

streampos Parser::getLogBufferPos(int offset)
{
    streampos pos;
    
    pos = 0;
    if(LogBuffer != 0)
        pos = LogBuffer->size();
    pos += static_cast<streampos>(offset - PutBackCount);
    return pos;
}

#ifdef CALL_EXTERNAL_PROGRAM 
void Parser::doPreProcess(const char * cmd)
{
    string         tempfilename;
    char           buffer[1024];
    int            count;
    fstream        tempfile;
    string         work;
    stringstream * stream;

    if(current == NULL || current->stream == NULL)
        ExceptionMessage("No stream specified for processing","�����ΏۂƂȂ�X�g���[�����ݒ肳��Ă��܂���").throwException();


        /* ���̃X�g���[���̓��e�����ׂăe���|�����ɏ����o�� */

    strcpy(buffer,"cfgXXXXXX");
    mktemp(buffer);

    tempfilename.assign(buffer);
    tempfile.open(tempfilename.c_str(),ios::out);

    if(!tempfile.is_open())
        ExceptionMessage("Failed to open a temporary file","�e���|�����t�@�C���̍쐬�Ɏ��s���܂���").throwException();

    do {
        current->stream->read(buffer, 1024);
        count = current->stream->gcount();
        tempfile.write(buffer, count);
    } while(count != 0);
    tempfile.close();


        /* �X�g���[�������ւ� */

    preprocessname = tempfilename;
    originalname   = current->identifier;

    if(current->stream != &cin)
        delete current->stream;
    stream = new stringstream;
    current->stream = stream;


        /* �v���v���Z�b�T�̋N�� & �o�͂̎�荞�� */

    work  = string(cmd) + " " + tempfilename;
    VerboseMessage(" Start the external preprocessor [%]\n"," �O���v���O�������N�����܂� [%]\n") << work;

    FILE * pipe = popen(work.c_str(),"r");
    while(feof(pipe) == 0)
        stream->put((char)fgetc(pipe));

    pclose(pipe);
    remove(tempfilename.c_str());
    isHeadofLine = true;
}
#else
void Parser::doPreProcess(const char * cmd)
{}
#endif /* CALL_EXTERNAL_PROGRAM */


ParseUnit::ParseUnit(void * _container, const char * name)
{
    map<string, ParseUnit *> * container;
    string work(name);
    string apiname;
    string::size_type i,j;

    i = 0;
    container = reinterpret_cast<map<string, ParseUnit *> *>(_container);
    
    do {
        j = work.find_first_of(',', i);
        apiname = work.substr(i, j-i);

        if(container->find(apiname) != container->end())
            ExceptionMessage("Multiple registration of [%]\n","[%]���d�����ēo�^����悤�Ƃ��Ă��܂�") << apiname << throwException;
        (*container)[apiname] = this;
        i = j + 1;
    }while(j != string::npos);
}

void ParseUnit::printList(void * _container)
{
    int i;
    map<string, ParseUnit *> * container;
    map<string, ParseUnit *>::iterator scope;

    container = reinterpret_cast<map<string, ParseUnit *> *>(_container);
    if(container->empty())
    {
        cerr << "  " << Message("None of element registed\n", "�o�^����Ă���v�f�͂���܂���\n");
        return;
    }

    i = 0;
    scope = container->begin();
    while(scope != container->end())
    {
        cerr << '[' << (*scope).first << "] ";

        if(i++ >= 6)
        {
            i = 0;
            cerr << '\n';
        }

        ++ scope;
    }

    if(i != 0)
        cerr << '\n';
}

Token & ParseUnit::parseParameter(Parser & p)
{
    static Token result;
    Token token;
    int nest = 0;

    result.type = Token::ERROR;
    result.value = 0;
    result.assign("");

    do
    {
        p.getToken(token);
        if(token == Token::PUNCTUATOR)
        {
            if(token.compare("(") == 0)
                nest ++;
            else if(token.compare(")") == 0)
                nest --;
            else if(nest == 0)
                break;
            if(nest < 0)
                ExceptionMessage("')' appeared before '('.","�Ή����Ȃ������ʂ�����܂�").throwException();
        }

        if(result == Token::ERROR)
            result = token;
        else
        {
            result.type = Token::STRING;
            result += ' ';
            result += token;
        }

    }while(true);

    p.putBack(token);
    result.trim();
    return result;
}

int ParseUnit::parseParameters(Parser & p, Directory * container, int min, int max)
{
    Token work;
    int count = 0;

    if(max == 0)
        max = min;

    do
    {
        Token & token = parseParameter(p);
        if(token.type == Token::ERROR)
            break;

        if(token == Token::INTEGER)
            container->addChild(new Directory(token.value));
        else
            container->addChild(new Directory((string &)token));

        count ++;
        p.getToken(work);
    }while(work.compare(",")==0 && count < max);

    if(count < min)
        ExceptionMessage("Too few parameters [%/%]","�p�����[�^�̐������Ȃ����܂� [%/%]") << count << min << throwException;

    p.putBack(work);
    return count;
}

int ParseUnit::parseParameters(Parser & p, Directory * container, const char * paramlist)
{
    Token work;
    int count;
    string list;
    string key;
    string::size_type head,tail;

    list.assign(paramlist);

    count = 0;
    head = 0;
    tail = list.find_first_of(',');
    key = list.substr(head,tail-head);

    do
    {
        if(head == string::npos)
            ExceptionMessage("Too many parameters","�p�����[�^�̐����������܂�").throwException();

        Token & token = parseParameter(p);
        if(token.type == Token::ERROR)
            break;

        if(token == Token::INTEGER)
            container->addChild(key,new Directory(token.value));
        else
            container->addChild(key,new Directory((string &)token));

        if(tail != string::npos)
        {
            head = tail + 1;
            tail = list.find_first_of(',',head);
            key = list.substr(head,tail != string::npos ? tail-head : string::npos);
            count ++;
            p.getToken(work);
        }else
            break;
    }while(work.compare(",")==0);

    if(tail != string::npos)
        ExceptionMessage("Too few parameters","�p�����[�^�̐������Ȃ����܂�").throwException();

    return count;
}

//------

Directory * StaticAPI::last = NULL;

map<std::string, class ParseUnit *> & StaticAPI::container(void)
{
    static map<std::string, class ParseUnit *> _container;
    return _container;
}

Directory * StaticAPI::allocate(Directory & container, const Token & token, const char * id, bool regist)
{
    static unsigned int assignment_count = 0;
    Directory * node;

    if(!(token == Token::IDENTIFIER || token == Token::INTEGER))
        ExceptionMessage("Given token(%) is not suitable for an object identifier.","�I�u�W�F�N�g�̎��ʖ��Ƃ��ė��p�ł��Ȃ�����(%)���w�肳��܂���") << token << throwException;

    if(regist && (token == Token::INTEGER && token.value <= 0))
        ExceptionMessage("Cannot assign an ID number less or equal to 0.","0�ȉ���ID�ԍ���ݒ肷�邱�Ƃ͂ł��܂���").throwException();


    node = container.findChild(id);
    if(node != 0)
    {
        Directory::iterator scope;

        scope = node->begin();
        while(scope != node->end())
        {
            if((*scope).first.compare(token) == 0)
                ExceptionMessage("Identifier % is already used.","���ʖ�%�͂��łɗ��p����Ă��܂�") << token << throwException;
            ++ scope;
        }
    }else
        node = container.addChild(id);

    node = node->addChild(token);
    (*node)["#order"] = assignment_count++;

    if(token == Token::IDENTIFIER)
    {
        if(regist)
        {
            Directory * scope = container.openChild("/","identifier",token.c_str(),NULL);
            if(*scope == Directory::INTEGER)
                *node = scope->toInteger();
        }
    }else
        *node = token.value;

    last = node;
    return node;
}

//------

map<std::string, class ParseUnit *> & Directive::container(void)
{
    static map<std::string, class ParseUnit *> _container;
    return _container;
}

//------

ParserComponent::ParserComponent(void) throw() : Component(PARSER)
{}

ParserComponent::~ParserComponent(void) throw()
{}

void ParserComponent::parseOption(Directory & container)
{
    if(findOption("h", "help"))
    {
        cerr << Message(
            "Static API parser\n"
            "  -s, --source=filename     : Specify the source file\n"
            "  -idir ,--ignore-directive : Ignore directives\n"
            "  -iapi ,--ignore-api       : Ignore unknown static api\n"
            "  -t, --through             : Get unprocessed APIs through\n"
            "  --print-api               : Show registered static api list\n", 
            "�ÓIAPI�p�[�T\n"
            "  -s, --source=�t�@�C����   : ���̓t�@�C�������w�肵�܂�\n"
            "  -idir ,--ignore-directive : �f�B���N�e�B�u�̉�͂��s���܂���\n"
            "  -iapi, --ignore-api       : �o�^����Ă��Ȃ�API�𖳎����܂�\n"
            "  -t, --through             : �������Ȃ�����API��ʉ߂����܂�\n"
            "  --print-api               : �o�^����Ă���API�̈ꗗ��\�����܂�\n");
        return;
    }

    if(findOption("-print-api"))
    {
        cerr << Message("List of Registerd Static API\n","�ÓIAPI �ꗗ\n");
        StaticAPI::printList();
        return;
    }

    checkOption("idir", "ignore-directive");
    checkOption("iapi", "ignore-api");
    checkOption("t", "through");

    if(checkOption("s","source") || checkOption(DEFAULT_PARAMETER))
        activateComponent();
}

bool ParserComponent::parseStaticAPI(Parser & p, Directory & container, Token token, const string domain)
{
    bool isParseErrorOccured = false;
    map<string, ParseUnit *>::iterator api;
    Directory * node = NULL;

    if(token.type != Token::IDENTIFIER)
        return false;

    StaticAPI::clearLastObject();
    node = container[PARSERESULT].addChild();

    try {
        node->addChild("api",new Directory(token));
        node->addChild("begin",new Directory((long)p.getLogBufferPos(-(int)token.size()-1)));
        if(!domain.empty())
            node->addChild("domain", new Directory(domain));

        api = StaticAPI::container().find(token);
        if(api == StaticAPI::container().end())
        {
            if(ignoreUnknownAPI)
            {
                cerr << Message("%: Unknown static api % was ignored. (skipped)\n","%: ��o�^��API % �͖�������܂�\n") << p.getStreamLocation() << token;
                do {
                    p.getToken(token);
                }while(token.compare(";") != 0);
                node->addChild("end",new Directory((long)p.getLogBufferPos()));
                (*node) = (long)0;
                return true;
            }
            ExceptionMessage("Static API [%] is not registered in the configurator", "�ÓIAPI[%]�͖��o�^�ł�") << token << throwException;
        }

        DebugMessage("  StaticAPI [%]\n") << (*api).first;

        p.getToken("(");

        (*api).second->body(token, container, p, domain);

        p.getToken(")");
        p.getToken(";");

        node->addChild("end",new Directory((long)p.getLogBufferPos()));
        (*node) = (long)1;
    }
    catch(Exception & e)
    {
        int offset;
        string work;
        work = p.getStreamLocation() + Message(":[Error] ",":[�G���[] ").str() + e.getDetails();
        isParseErrorOccured = true;

        StaticAPI::dropLastObject();
        failCount ++;

        offset = 0;
        token = p.getLastErrorToken();
        while (token != Token::ERROR && token != Token::EOS)
        {
            if( token == ";" )
                break;

                //�ǂݏo�����g�[�N�����ÓIAPI�Ɠ������O�Ȃ� �����ƃZ�~�R�����Y��
            api = StaticAPI::container().find(token);
            if(api != StaticAPI::container().end())
            {
                cerr << Message("<The following error must be occured by lack of ';' at the end of previous line>\n","<���̃G���[�͒��O�s��';'�Y��ɂ��\���������ł�>\n");
                offset = -(int)token.size();
                p.putBack(token);
                break;
            }

            p.getToken(token);
        }

        node->addChild("end",new Directory((long)p.getLogBufferPos(offset)));
        (*node) = (long)0;

        cerr << work << '\n';

        ExceptionMessage("Fatal error on Static API parsing","�ÓIAPI�̍\����͂Ɏ��s���܂���").throwException();
    }

    return true;
}

/*
 *  �����ł��Ȃ�����API��W���o�͂ɓf���o��
 */
void ParserComponent::throughConfigurationFile(string & log, Directory & container)
{
    Directory *        node;
    string::size_type  pos;
    string::size_type  begin;
    string::size_type  end;

    pos = 0;
    end = 0;

    node = container[PARSERESULT].getFirstChild();
    while(node != NULL)
    {
        begin = static_cast<string::size_type>((*node)["begin"].toInteger());
        end   = static_cast<string::size_type>((*node)["end"].toInteger());

        if(pos < begin)
            cout << log.substr(pos, begin - pos);

        if(node->toInteger() == 0)
        {
            cout << log.substr(begin, end - begin);
        }else
        {
            for(pos = begin; pos < end; ++pos)
                if( log.at(pos) == '\n' )
                    cout << '\n';
        }
        node = node->getNext();
    }

    if(end < log.size())
        cout << log.substr(end);

    ExceptionMessage("","").throwException();
}


void ParserComponent::body(Directory & container)
{
    Token token;
    Parser p(container);
    string logbuffer;
    OptionParameter::OptionItem item;
    unsigned int itemcount = 0;

    failCount = 0;
    
        //idir�I�v�V�����̏���
    if(findOption("idir","ignore-directive"))
        p.disable(Parser::DIRECTIVE);

    ignoreUnknownAPI = findOption("iapi", "ignore-api");

    if(findOption("t","through"))
    {
        p.setLogBuffer(&logbuffer);
        ignoreUnknownAPI = true;
    }

        //���̓\�[�X
    item = getOption("s", "source");
    item.mergeItem(getOption(DEFAULT_PARAMETER));
    if(item.countParameter() == 0)
    {
        p.pushStdStream(Message("Standard Input","�W������").str());
        VerboseMessage("Starting parse with standard input\n","�W�����͂���̎����͂��J�n���܂���\n");
    }

    try{
        do {
            if(item.hasParameter())
            {
                VerboseMessage("Starting parse with file[%]\n","�t�@�C��[%]�̎����͂��J�n���܂���\n") << item[itemcount];
                p.pushStream(item[itemcount]);
            }

            this->parse(p, container);

            if(p.getToken(token) != Token::EOS)
                ExceptionMessage("Buffer has remaining tokens, parsing is not yet finished", "�p�[�X�����f����܂���").throwException();

            if(failCount != 0)
                ExceptionMessage("Total % failures found in this configuration.","%�̏�Q������܂�") << failCount << throwException;

            VerboseMessage("Parse finished\n","�����͂͐���ɏI�����܂���\n");

        } while(++itemcount < item.countParameter());

        if(findOption("t","through"))
            throughConfigurationFile(logbuffer,container);

        container[PARSERESULT].erase();
    }
    catch(Exception & e)
    {
        string work;

        work = p.getStreamLocation() + Message(":[Error] ",":[�G���[] ").str() + e.getDetails();
        ExceptionMessage(work.c_str()).throwException();
    }
}

    // �I�v�V�����m�[�h���犄�t���@���擾����
enum Common::tagAssignmentOrder Common::parseOrder(Directory * node)
{
    Directory * scope;
    int         i;

        //�����p�����[�^���
    i = FCFS;
    if(node != 0)
    {
        scope = node->getFirstChild();
        while(scope != 0)
        {
            string param = scope->toString();
            if(param.compare("alphabetic") == 0 || param.compare("ALPHABETIC") == 0)
                i = (i & 0xf0) | ALPHABETIC;
            else if(param.compare("fcfs") == 0 || param.compare("FCFS") == 0)
                i = (i & 0xf0) | FCFS;
            else if(param.compare("reverse") == 0 || param.compare("REVERSE") == 0)
                i |= REVERSE;

            scope = scope->getNext();
        }
    }

    return static_cast<enum tagAssignmentOrder>(i);
}

    // �I�v�V�����m�[�h���犄�t���@���擾����
enum Common::tagAssignmentOrder Common::parseOrder(OptionParameter::OptionItem item)
{
    Directory node;
    unsigned int i;

    for(i=0;i<item.countParameter();++i)
        node.addChild(item[i]);

    return parseOrder(&node);
}

    //ID�l�̃A�T�C�������g
    //  (���̏ꏊ������g���̂ł����Ɉړ�)
int Common::assignID(Directory & container, const char * category, const char * top, enum tagAssignmentOrder order)
{
    Directory * node  = 0;
    Directory * scope = 0;
    Directory * work  = 0;
    set<int> idpool;
    map<int, Directory *> sorter;
    map<int, Directory *>::iterator p_sorter;
    int i;

        //������
    node = container.findChild(top,category,NULL);
    if(node == 0)
        return 0;

    for(i=1;i< (signed int) node->size() + 32; i++)
        idpool.insert(i);

        //���t���̌���ƁC�����ς�ID�̍폜
    i = 0;
    scope = node->getFirstChild();
    while(scope != 0)
    {
        if( *scope == Directory::INTEGER )
            idpool.erase(*scope);
        else
        {
                //�d�����̂̑��݃`�F�b�N
            work = container.openChild("/","identifier",scope->getKey().c_str(),NULL);
            if( *work == Directory::INTEGER)
            {
                VerboseMessage("Assigning the same ID (%) since the name (%[%]) is duplicated\n","ID�ԍ�(%)���َ퓯���̃I�u�W�F�N�g(%[%])�Ɋ��蓖�Ă܂��D\n") << work->toInteger() << scope->getKey() << category;
                idpool.erase(*scope = work->toInteger());
            } else
            {
                    //�������@�ɏ]���Ċ������ɒǉ�
                switch(order)
                {
                case ALPHABETIC:
                    sorter[i++] = scope;
                    break;
                case REVERSE_ALPHABETIC:
                    sorter[i--] = scope;
                    break;
                case FCFS:
                default:
                    sorter[scope->openChild("#order")->toInteger()] = scope;
                    break;
                case REVERSE_FCFS:
                    sorter[-scope->openChild("#order")->toInteger()] = scope;
                    break;
                }
            }
        }
        scope = scope->getNext();
    }

        //ID����
    p_sorter = sorter.begin();
    while(p_sorter != sorter.end())
    {
        scope = (*p_sorter).second;
        if( !(*scope == Directory::INTEGER) )
        {
            i = *(idpool.begin());
            idpool.erase(idpool.begin());

            work = container.openChild("/","identifier",scope->getKey().c_str(),NULL);
            *work = i;
            *scope = i;
        }
        ++ p_sorter;
    }

        //�����\�쐬
    if(node->size() != 0 && VerboseMessage::getVerbose())
    {
        VerboseMessage("Object ID assignment list [%]\n","�I�u�W�F�N�gID���t�\ [%]\n") << category;

        sorter.clear();
        scope = node->getFirstChild();
        while(scope != 0)
        {
            sorter[scope->toInteger()] = scope;
            scope = scope->getNext();
        }

        p_sorter = sorter.begin();
        while(p_sorter != sorter.end())
        {
            VerboseMessage("  % : %\n") << setw(3) << (*p_sorter).first << (*p_sorter).second->getKey();
            ++ p_sorter;
        }
    }

        //�Ó����̔���
    if((signed)node->size()+1 != *(idpool.begin()))
        ExceptionMessage("Discontinuous % ID assignment occured","�s�A���ȃI�u�W�F�N�gID(%)") << category << throwException;

    return node->size();
}

