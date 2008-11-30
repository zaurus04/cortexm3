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
 *  @(#) $Id: coverage_defs.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
    #ifdef�֌W
    coverage_defs�́Aundefs�ŉ����������Ƃɓǂݍ��ޏꍇ������̂ŁA
        �p�[�g���������ɕ������Ă���.
        - COVERAGE      : �J�o���b�W�@�\���g�p���邩�ǂ���
        - COVERAGE_H    : coverage.cpp�Ɋ֘A���镔���ŁA���d��`����Ă͍������
        - COVERAGE_DEFS : �J�o���b�W�Ɋ֘A���镔���ŁAcoverage_undefs.h��undef�ł��A������xcoverage_defs.h��ǂ�ł����v�Ȃ���
*/


#ifdef COVERAGE

#include "base/singleton.h"

    /* �w�b�_ */
#include <string>
#include <map>
#include <set>
#include <iostream>


#ifndef COVERAGE_H
#define COVERAGE_H
/*
 *   �ȒP�ȃJ�o���b�W�`�F�b�N
 */

class Coverage {
public:
        /* �ꏊ��ێ�����N���X */
    class Location {
    protected:
        const char *  filename;
        unsigned int  lineno;
        const char *  additional;

    public:
        Location(const char * _filename, unsigned int _lineno, const char * _additional = "") : filename(_filename), lineno(_lineno), additional(_additional) {}
        Location(const Location & src) : filename(src.filename), lineno(src.lineno), additional(src.additional) {}

        inline Location & operator = (const Location & right)
        {
            filename   = right.filename;
            lineno     = right.lineno;
            additional = right.additional;

            return *this;
        }

        inline bool operator == (const Location & right) const
        {   return lineno == right.lineno && std::string(filename).compare(right.filename) == 0 && std::string(additional).compare(right.additional) == 0;   }

        inline bool operator < (const Location & right) const
        {
            if(lineno < right.lineno)
                return true;
            if(std::string(filename).compare(right.filename) < 0)
                return true;

            return false;
        }

        inline std::string getFilename(void) const
        {   return std::string(filename);   }

        inline unsigned int getLineno(void) const
        {   return lineno;   }

        inline std::string getAdditional(void) const
        {   return std::string(additional);   }

            //�t�H�[�}�b�g�ς݃t�@�C���ʒu���̎擾 filename:lineno(additional)
        std::string getDetails(void) const;
    };

        //����J�o���b�W����̃x�[�X�N���X
    class BranchBase {
    protected:
        BranchBase(const Location & location) throw();   //�v�f�̓o�^
        static BranchBase * find(const Location & location) throw();     //location�Ɉ�v����v�f�̎擾

    public:
        virtual ~BranchBase(void) throw() {}                        //�f�X�g���N�^
        virtual bool checkValidity(void) const throw(...) = 0;      //����������
        virtual std::string getDetails(void) const throw(...) = 0;  //�f�[�^�\��
    };

        //if-statement�Ɉ���������N���X
    class If : public BranchBase {
    protected:
        bool true_case;
        bool false_case;

        If(const Location & location) throw(); //branch�o�R�Ŗ����Ɛ��������Ȃ�

    public:
        virtual bool checkValidity(void) const throw();         //�������̔���
        virtual std::string getDetails(void) const throw();     //�f�[�^�\��

        static bool branch(const Location & location, bool expression) throw();
    };
    
        //while-statement�Ɉ���������N���X
    class While : public BranchBase {
    protected:
        bool valid;

        While(const Location & location) throw();
    public:
        virtual bool checkValidity(void) const throw();         //�������̔���
        virtual std::string getDetails(void) const throw();     //�f�[�^�\��

        static bool branch(const Location & location, bool expression) throw();
    };

        //switch-statement�Ɉ���������N���X
    class Switch : public BranchBase {
    protected:
        std::set<int> checkpoint;

        Switch(const Location & location) throw();
        static void _branch(const Location & location, int expression) throw();

    public:
        virtual bool checkValidity(void) const throw();         //�������̔���
        virtual std::string getDetails(void) const throw();     //�f�[�^�\��

        template<class T>
        static T branch(const Location & location, T expression) throw()
        {
            _branch(location, (int)expression);
            return expression;
        }
    };


protected:
    class BranchMap : public std::map<Location, BranchBase *> {
    public:
        SINGLETON_CONSTRUCTOR(BranchMap) {}
        ~BranchMap(void) throw();
    
    };
    class NewBranchList : public std::list<BranchBase *>
    {   public: SINGLETON_CONSTRUCTOR(NewBranchList) {}   };

        //���ڂ̕\��
    static std::string getBranchName(BranchBase * node);

public:
        //�S�Ēʉ߂������ǂ����̃`�F�b�N
    static bool checkValidity(void);

        //�S�Ă̍��ڂ�\��
    static void printCoverage(std::ostream & out);

};

#endif /* COVERAGE_H */


#ifndef COVERAGE_DEFS
#define COVERAGE_DEFS

#define if(x)    i##f(Coverage::If::branch(Coverage::Location(__FILE__, __LINE__, "if"), (x) ? true : false))
#define while(x) w##hile(Coverage::While::branch(Coverage::Location(__FILE__, __LINE__, "while"), (x) ? true : false))
#define switch(x) s##witch(Coverage::Switch::branch(Coverage::Location(__FILE__, __LINE__, "switch"), (x)))

#endif  /* COVERAGE_DEFS */

#else

#include <iostream>

#ifndef COVERAGE_H
#define COVERAGE_H
class Coverage {
public:
    static bool checkValidity(void) { return true; }
    static void printCoverage(std::ostream &) {}
};
#endif /* COVERAGE_H */

#endif

