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
 *  @(#) $Id: testsuite.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/testsuite.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/testsuite.h"

#include "base/coverage_defs.h"
#include "base/coverage_undefs.h"

#ifdef TESTSUITE

#undef  main           //�e�X�g�X�B�[�g�p��main���`����̂�undef����
#undef  cin
#undef  cout
#undef  cerr

#include <stdlib.h>     //EXIT_SUCCESS|EXIT_FAILURE�p
#include <fstream>      //��Ɗ֐��p
#include <cstdio>
#include <iomanip>

using namespace std;

/* �X�g���[���������p�̕ϐ���` */
namespace std {
    stringstream _cin;
    stringstream _cout;
    stringstream _cerr;
}

/*
 *  �e�X�g�X�B�[�g�̎��s����N���X ; class TestSuiteControl
 */


    //�R���X�g���N�^
TestSuiteControl::TestSuiteControl(ostream & _out, const char * _pattern) : target_session(_pattern), out(&_out), fail(false), verbose(false), case_count(0), fail_count(0)
{}

    //�V�i���I���̎擾
string TestSuiteControl::get_suitename(const char * name) const
{
    string result;
    list<string>::const_iterator scope;

    scope = session.begin();
    while(scope != session.end()) {
        result += *scope;
        result += '.';
        ++ scope;
    }

    if(name != NULL)
        result += name;

    return result;
}


    //�e�X�g�V�i���I�̕\��ݒ� (�ԋp�l : ���s����K�v�����邩�ǂ���)
bool TestSuiteControl::_enter_case(const char * session, const char * description, const char * filename, long lineno)
{
    bool         result;
    stringstream buf;

        //�\��̐ݒ�
    current_session.assign(get_suitename(session));

        //�ڍ׏��̐ݒ�
    if(description != 0)
        buf << description;

        //�t�@�C���� (filename:lineno) �̐���
    if(filename != 0) {
        string            work(filename);
        string::size_type pos;

            //�t���p�X�ŗ�����Z���؂�
        pos = work.find_last_of("/\\");
        if(pos != string::npos)
            work.erase(0, pos + 1);

        buf << '(' << work;
        if(lineno != -1)
            buf << ':' << lineno;
        buf << ')';
    }
    current_description = buf.str();
    
        //���s����K�v�̗L���̊m�F
    result = (target_session.empty() || current_session.find(target_session) != string::npos);

    if(result) {
        if(verbose) {
            string indent;
            indent.assign(2 * this->session.size(), ' ');
            (*out) << indent << '[' << session << "] " << current_description << endl;

            //(*out) << '[' << current_session << "] " << current_description << endl;
        }

        enter_session(session);
        ++ case_count;
    }

    return result;
}

    //�e�X�g�Z�b�V������ (�V�i���I�v���t�B�N�X) �̐ݒ�
void TestSuiteControl::enter_session(const string & _session)
{   session.push_back(_session);   }

    //�e�X�g�Z�b�V������ (�V�i���I�v���t�B�N�X) �̉���
void TestSuiteControl::leave_session(void)
{   session.pop_back();   }

    //�e�X�g�V�i���I�̎��s��
void TestSuiteControl::fail_in_suite(string msg)
{
    fail = true;
    (*out) << "Failed : [" << current_session << "]\n   " << current_description << endl;
    if(!msg.empty())
        (*out) << "     #" << msg << endl;
    ++ fail_count;
}


    //�X�B�[�g���R���X�g���N�^
TestSuite::SuiteContainerNode::SuiteContainerNode(const char * _session, SuiteFunction _suite) : session(_session), suite(_suite)
{}

    //�X�B�[�g���R���X�g���N�^
TestSuite::SuiteContainerNode::SuiteContainerNode(const SuiteContainerNode & src) : session(src.session), suite(src.suite)
{}

    //�X�B�[�g�̎��s
bool TestSuite::SuiteContainerNode::invoke(TestSuiteControl & suite_control)
{
    if(suite != 0) {
        suite_control.enter_session(session);
        (*suite)(suite_control);
        suite_control.leave_session();
    }

    return !suite_control.is_failed();
}

/*
 *  �e�X�g�X�B�[�g���s�N���X
 */

    //�R���X�g���N�^
TestSuite::TestSuite(const char * session, SuiteFunction suite) : fail(false)
{   Singleton<SuiteContainer>::getInstance()->push_back(SuiteContainerNode(session, suite));   }


    //�f�X�g���N�^
TestSuite::~TestSuite(void)
{}


    //�e�X�g�X�B�[�g�̎��s  (�ԋp�l:�X�B�[�g�����s�������ǂ���)
bool TestSuite::performTestSuite(int flags, const char * pattern)
{
    bool                        result;
    TestSuiteControl            suite_control(cerr, pattern);
    SuiteContainer *            container;
    SuiteContainer::iterator    scope;

        //���s�X�B�[�g���X�g�̎Q��
    container = Singleton<SuiteContainer>::getInstance();

        //�璷�o�͐ݒ�
    if( (flags & VERBOSE) != 0 )
        suite_control.set_verbose();

        //�S�o�^�X�B�[�g�̎��s
    scope = container->begin();
    while(scope != container->end()) {

        result = scope->invoke(suite_control);

            //���������~�߂� or �ʂ��Ŏ��s
        if( !result && (flags & THROUGH) == 0)
            break;

        ++ scope;
    }

        //�G���[���Ȃ����OK�\��
    if(!suite_control.is_failed())
        cerr << "OK (" << suite_control.countCases() << " passed)" << endl;
    else
        cerr << "Failed (" << suite_control.countFails() << '/' << suite_control.countCases() << ')' << endl;

    return !suite_control.is_failed();    //�X�B�[�g�𐳏�Ɏ��s�ł�����true
}


    //�o�^����Ă���g�b�v���x���X�B�[�g�̈ꗗ�\��
void TestSuite::listTestSuite(void)
{
    SuiteContainer::iterator  scope;
    int                       count;
    SuiteContainer *          container;

    count     = 0;
    container = Singleton<SuiteContainer>::getInstance();
    
    scope = container->begin();
    while(scope != container->end()) {
        cout << "  ";
        cout.width(3);
        cout << count << ':' << scope->getName() << endl;

        ++ count;
        ++ scope;
    }
    cout << "Total " << count << " sets of suite exist.\n";
}



/*
 *   �`�F�b�N�|�C���g�p�֐�
 */

bool TestSuite::isReached(std::string checkname)
{
    set<string>::iterator scope;

    scope = Singleton<Checkpoint>::getInstance()->find(checkname);

    return scope != Singleton<Checkpoint>::getInstance()->end();
}


/*
 *   �e�X�g�X�B�[�g���s�p��Ɗ֐�
 */

    //�t�@�C�����e��r
bool TestSuite::compareFileContents(const char * filename, const char * filecontents, bool _remove)
{
    fstream file(filename,ios::in);
    int     ch;
    bool    result = true;

        //���e�`�F�b�N
    while(result && *filecontents != '\x0' && file.good()) {
        ch = file.get();

        if(ch != (int)*filecontents)
            result = false;

        ++ filecontents;
    }

        //EOF�ɒB���Ă��邩
    if(result) {
        if(!file.good() || file.get() != EOF)
            result = false;
    }

    file.close();

    if(_remove)
        ::remove(filename);

    return result;
}

    
/*
    *   �e�X�g�X�B�[�g���s�pmain�֐�
    */
int main(int argc, char ** argv)
{
    int    result;
    int    pos;
    int    flags;
    string category;

    flags = TestSuite::DEFAULT;

    for(pos = 1; pos < argc; ++ pos) {
        if(*argv[pos] == '-') {
            switch(argv[pos][1]) {
            case 'v': 
                flags |= TestSuite::VERBOSE;
                break;
            case 'V': 
                flags &= ~TestSuite::VERBOSE;
                break;
            case 't': 
                flags |= TestSuite::THROUGH;
                break;
            case 'T': 
                flags &= ~TestSuite::THROUGH;
                break;
            case 'l': 
                TestSuite::listTestSuite();
                return EXIT_SUCCESS;
            case 'h':
                cerr << "Usage : program (option) (suite)\n"
                            " -v, -V  : Verbose output on(-v) / off(-V)\n"
                            " -t, -T  : Go through with the suite, on(-t) / off(-T)\n"
                            " -l      : List the top level suites\n";
                return EXIT_SUCCESS;
            default:
                cerr << "Unknown option [" << argv[pos] << "]\n";
                return EXIT_FAILURE;
            }
        }
        else {
            if(!category.empty()) {
                cerr << "Two or more category specified.\n";
                return EXIT_FAILURE;
            }
            category.assign(argv[pos]);
        }
    }

    result = EXIT_FAILURE;
    if(TestSuite::performTestSuite(flags, category.c_str()))
        result = EXIT_SUCCESS;

#ifdef COVERAGE
    fstream fout("coverage.txt",ios::out);
    if(fout.is_open()) {
        Coverage::printCoverage(fout);
        fout.close();
    }
#endif

    return result;
}

#endif //TESTSUITE

