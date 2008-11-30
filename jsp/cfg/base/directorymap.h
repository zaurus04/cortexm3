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
 *  @(#) $Id: directorymap.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/directorymap.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef DIRECTORYMAP_H
#define DIRECTORYMAP_H

#ifdef _MSC_VER
    #pragma warning(disable:4786)
#endif

#include "base/message.h"
#include "base/garbage.h"
#include "base/singleton.h"

  //MSVC6.0�� <cstdio> ���Ă�std�ɓ���Ă���Ȃ��̂�
#include <stdio.h>

#include <string>
#include <map>
#include <iostream>

class Directory : public std::map<std::string, Directory *>
{
private:
    /*
     * Directory�N���X : �݌v����
     *
     *   �E�e�q�m�[�h�Ԃ̊֌W
     *      ���� : �e�� �q�𒼐ڂ������ă����N�𒣂�
     *      �j�� : �q�� �e����̓Ɨ����˗����� (�e�������I�Ɋ������Ȃ�)
     *
     *   �ENULL�Z�[�t����
     *      �ꕔ�̊֐��� this != NULL �����肵�Ȃ��Ŏ������� (�����ւ̗��֐�����)
     *        - addChild
     *        - findChild, openChild (findNode()
     *        - erase(void)
     *        - getFirstChild, getLastChild, getNext, getPrev
     */

public:
    enum tagtype
    {
        UNKNOWN,
        POINTER,
        INTEGER,
        LITERAL,
        CONSTLITERAL,
        OBJECT
    };

    enum tagflag
    {
        NOTHING  = 0,
        DESTRUCT = 1,
        UNSIGNED = 2
    };

    enum tagmode
    {
        PTRPREFIX = 1
    };

protected:
    static int defaultflag;

    enum tagtype type;
    int flag;

    Directory * parent;
    std::map<std::string, Directory *>::iterator myself;

    union
    {
        void * pointer;
        long value;
        const char * const_literal;
        std::string * literal;
        class Garbage * instance;
    } content;

    Directory(const Directory &);
    void initialize(void);
    void clearContent(void);

    Directory * findNode(bool, const std::string &);
    Directory * findNode(bool automatic_creation, const char * key, va_list vl);

public:
    SINGLETON_CONSTRUCTOR(Directory) { initialize(); }

    Directory(void);
    Directory(int);
    Directory(long);
    Directory(const std::string &);
    Directory(void *);
    explicit Directory(const char *);
    explicit Directory(Garbage *);
    ~Directory(void);

    Directory & operator =(void *);
    Directory & operator =(long);
    Directory & operator =(const char *);
    Directory & operator =(const std::string &);
    Directory & operator =(Garbage *);

    bool operator == (enum tagtype cmptype)
    {   return type == cmptype;   };

    Directory * operator ()(const std::string & src)
    {   return findChild(src);  };
    Directory * operator ()(const char * src)
    {   return findChild(src);  };

    Directory & operator [](const std::string & src)
    {   return *openChild(src); };
    Directory & operator [](const char * src)
    {   return *openChild(std::string(src));    };

    enum tagtype getType(void) const { return type; };
    Directory *  getParent(void) const { return parent; };
    Directory *  getParent(int) const;
    Directory *  getNext(void) const;
    Directory *  getPrev(void) const;
    Directory *  getFirstChild(void) const;
    Directory *  getLastChild(void) const;
    Directory *  findChild(const std::string &);
    Directory *  findChild(const char *);
    Directory *  findChild(const char *, const char * , ... );
    Directory *  findDescandant(const std::string &, unsigned int = 0xffffffff) const;
    Directory *  openChild(const std::string &);
    Directory *  openChild(const char *);
    Directory *  openChild(const char *, const char *, ... );

    void * operator new(size_t);
    void * operator new(size_t, std::nothrow_t);
    void * operator * (void) const;

    operator const long (void) const;
    operator const unsigned long (void) const;
    operator const int (void) const;
    operator const unsigned int (void) const;
    operator const char (void) const;
    operator const unsigned char (void) const;
    operator const char * (void);
    operator const std::string & (void) const;
    operator const Garbage * (void) const;
    operator const void * (void) const;

    void * toPointer(const void * default_value = 0) const;
    long toInteger(const long default_value = 0) const;
    std::string toString(const std::string & default_value = "") const;

    bool operator == (int) const;
    bool operator == (const std::string &) const;
    bool operator == (const char *) const;

    template<class T>
    bool operator != (T src) const
    {   return !(this->operator ==(src));   };


    Directory * addChild(const std::string &, Directory * = 0);
    Directory * addChild(const char *, Directory * = 0);
    Directory * addChild(const std::string &, Directory &);
    Directory * addChild(const char *, Directory &);
    Directory * addChild(Directory &);
    Directory * addChild(Directory * = 0);

    void erase(void);
    iterator erase(iterator);
    void disconnect(void);
    void copyTo(Directory *, int = 0x7fffffff);
    void dropValue(void);
    std::map<std::string, Directory *>::size_type size(std::map<std::string, Directory *>::size_type = 0) const;

    const std::string getKey(void) const;
    bool changeKey(const std::string &);
    bool changeKey(const char *);

    void Load(std::istream *);
    void Store(std::ostream *);

    void drawTree(std::ostream * = &std::cerr, int = 0, std::string * = 0);
    void drawTree_byXML(std::ostream * = &std::cerr, int = 0);

    std::string format(const char *, int mode = 0);
    std::string format(const std::string &, int mode = 0);
};


//------

inline void Directory::initialize(void)
{
    parent = 0;
    type = UNKNOWN;
    flag = defaultflag;
    content.pointer = 0;
    defaultflag &= ~DESTRUCT;
}

inline Directory::Directory(void)
{   initialize();    }

inline Directory::Directory(long val)
{
    initialize();
    *this = val;
}

inline Directory::Directory(int val)
{
    initialize();
    *this = (long)val;
}

inline Directory::Directory(void * val)
{
    initialize();
    *this = val;
}

inline Directory::Directory(const std::string & val)
{
    initialize();
    *this = val;
}

inline Directory::Directory(const char * val)
{
    initialize();
    *this = val;
}

inline Directory::Directory(Garbage * val)
{
    initialize();
    *this = val;
}

inline Directory * Directory::addChild(const char * key, Directory * node)
{   return addChild(std::string(key), node);    }

inline Directory * Directory::addChild(const std::string & key, Directory & node)
{   return addChild(key, &node);    }

inline Directory * Directory::addChild(const char * key, Directory & node)
{   return addChild(std::string(key), &node);   }

inline Directory * Directory::addChild(Directory & node)
{   return addChild(&node); }

    //����addChild�Œǉ������v�f�́A�ꊇ�폜���邩�A�����Ă͂����Ȃ�
inline Directory * Directory::addChild(Directory * node)
{
    char buffer[32];
    sprintf(buffer,"%03d", (int)size());
    return addChild(buffer, node);
}

inline bool Directory::changeKey(const char * key)
{   return changeKey(std::string(key)); }

inline const std::string Directory::getKey(void) const
{
    if(parent == 0)
        return std::string("/");
    return (*myself).first;
}

inline Directory::operator const unsigned long (void) const
{   return static_cast<const unsigned long>(this->operator const long());  }

inline Directory::operator const int (void) const
{   return static_cast<const int>(this->operator const long());  }

inline Directory::operator const unsigned int (void) const
{   return static_cast<const unsigned int>(this->operator const long());  }

inline Directory::operator const char (void) const
{   return static_cast<const char>(this->operator const long());  }

inline Directory::operator const unsigned char (void) const
{   return static_cast<const unsigned char>(this->operator const long());  }

inline Directory::operator const char * (void)
{
    if(type == CONSTLITERAL)
        return content.const_literal;
    if(type == LITERAL)
        return content.literal->c_str();
    ExceptionMessage("Bad cast exception raised","�s���L���X�g��O").throwException();
    return 0;
}

inline Directory::operator const std::string &(void) const
{
    if(type == LITERAL)
        return *content.literal;
    ExceptionMessage("Bad cast exception raised","�s���L���X�g��O").throwException();
    return *(std::string *)0;
}

inline Directory::operator const Garbage * (void) const
{
    if(type == OBJECT)
        return content.instance;
    ExceptionMessage("Bad cast exception raised","�s���L���X�g��O").throwException();
    return 0;
}

inline Directory::operator const void * (void) const
{   return **this;  }

inline Directory * Directory::findChild(const std::string & path)
{   return findNode(false, path);  }

inline Directory * Directory::openChild(const std::string & path)
{   return findNode(true, path);  }

inline Directory * Directory::getParent(int level) const
{
    const Directory * node = this;
    while(level-- > 0 && node != 0)
        node = node->parent;
    return const_cast<Directory *>(node);
}

inline Directory * Directory::getFirstChild(void) const
{
    if(this == 0 || size()== 0)
        return 0;
    return (*begin()).second;
}

inline Directory * Directory::getLastChild(void) const
{
    if(this == 0 || size()== 0)
        return 0;
    return (*rbegin()).second;
}

inline bool Directory::operator == (int src) const
{   return type == INTEGER && content.value == src; }

inline bool Directory::operator == (const std::string & src) const
{   return (type == LITERAL && src.compare(*content.literal) == 0) || (type == CONSTLITERAL && src.compare(content.const_literal) == 0);    }

inline bool Directory::operator == (const char * src) const
{   return (type == LITERAL && content.literal->compare(src) == 0) || (type == CONSTLITERAL && strcmp(content.const_literal, src)== 0); }

inline std::string Directory::format(const char * src, int mode)
{   return format(std::string(src), mode);  }

inline void Directory::dropValue(void)
{   clearContent();   }

#endif

