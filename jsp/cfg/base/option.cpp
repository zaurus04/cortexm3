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
 *  @(#) $Id: option.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/option.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/option.h"
#include <assert.h>
#include <algorithm>

using namespace std;

    //�ʂ�OptionItem�����p�����[�^�������ɒǉ�����
void OptionParameter::OptionItem::mergeItem(const OptionItem & src)
{
    vector<string>::const_iterator scope;

        //�S�Ẵp�����[�^�������̌��ɒǉ�
    scope = src.param.begin();
    while(scope != src.param.end()) {
        param.push_back(*scope);
        ++ scope;
    }
}

    //������̐擪�ɂ���󔒕�������菜��
namespace {
    void TrimString(string & src)
    {
        string::size_type pos;

        pos = src.find_first_not_of(" \t\r\n");
        if(pos != 0)
            src.erase(0, pos);
    }
}

    //�I�v�V�����p�����[�^����͂���OptionItem�𐶐�����
bool OptionParameter::OptionItem::createItem(OptionItem & _dest, string & argv)
{
    bool              result;
    string            param;
    string::size_type pos;
    OptionItem        dest;

    result = true;

    TrimString(argv);
    if(argv.empty())
        result = false;     //���g�������
    else {
            //�I�v�V�����̃`�F�b�N
        if(argv[0] == '-') {
            pos = argv.find_first_of(" =");

            if(argv.substr(0,pos).compare("-") == 0) {  // - �����̃I�v�V�����͎󂯕t���Ȃ�
                result = false;
            }
            else {
                if(pos != 1) {
                    if(pos != string::npos) {
                        dest = argv.substr(1, pos - 1);
                        argv.erase(0, pos + 1);
                    }
                    else {
                        dest = argv.substr(1);
                        argv.erase();
                    }
                }
            }
        }

        TrimString(argv);
        while(!argv.empty() && argv[0] != '-') {
            if(argv[0] == '"') {

                    //�΂ɂȂ�_�u���N�H�[�g��T��
                pos = argv.find_first_of('"',1);
                if(pos == string::npos) {
                    result = false;
                    break;
                }

                    //�_�u���N�H�[�g�̒��g�����
                param = argv.substr(1, pos - 1);

                    //�_�u���N�H�[�g������
                ++ pos;
            }
            else {

                    //���̋�؂��T��
                pos = argv.find_first_of(" \t\r\n");
                if(pos == string::npos)
                    param = argv;
                else
                    param = argv.substr(0,pos);
            }

            dest.addParameter(param);
            argv.erase(0, pos);
            
            TrimString(argv);
        }
    }

    if(result)
        _dest = dest;

    return result;
}

    //�����ȃI�v�V�����A�C�e���̐���
OptionParameter::OptionItem OptionParameter::OptionItem::createInvalidItem(void) throw()
{
    OptionItem result;

    result.assign("");
    return result;
}


    //�S�Ẵp�����[�^�����������̂��擾
string OptionParameter::OptionItem::getParameters(string punctuator) const throw()
{
    string result;

    vector<string>::const_iterator scope;

    if(isValid()) {
        scope = param.begin();
        while(scope != param.end()) {
            result += punctuator;
            result += *scope;
            ++ scope;
        }

        if(!result.empty())
            result.erase(0, punctuator.size()); //�擪�̋�؂�q���폜
    }

    return result;
}

    //�I�v�V�����̌��̃`�F�b�N
bool OptionParameter::OptionItem::checkParameterCount(size_t required, bool allow_zero) const throw()
{
    bool result = true;
    if(isValid()) {
        size_t count = countParameter();
        if(count != required || (!allow_zero && count == 0))
            result = false;
    }
    else
        result = false;
    return result;
}

        //�I�v�V�����p�����[�^�̃p�[�X
bool OptionParameter::parseOption(int _argc, char const * const * _argv, char const * _default) throw()
{
    bool        result;
    string      arguments;
    OptionItem  work;
    int         i;

    map<string, OptionItem>::iterator scope;

        //�v���O�������̎擾
    if(_argc > 0)
        program_name.assign(_argv[0]);

        //�S�ĂȂ���
    for(i=1;i<_argc;++i) {
        arguments += _argv[i];
        arguments += ' ';
    }

    if(arguments.empty() && _default != 0)
        arguments.assign(_default);

    cmdline += arguments;

    result = true;

        //�e�I�v�V�����̉��
    while(!arguments.empty()) {

        if(!OptionItem::createItem(work, arguments)) {
            result = false;
            break;
        }

            //����̃I�v�V������������}�[�W����
        scope = container.find(work);
        if(scope != container.end())
            scope->second.mergeItem(work);
        else
            container.insert(std::map<std::string, OptionItem>::value_type(work, work));
    }

    return result;
}

    //�v�f�̌��o
map<string, OptionParameter::OptionItem>::iterator OptionParameter::_find(const std::string & name, bool check) throw()
{
    map<string, OptionParameter::OptionItem>::iterator scope;

    scope = container.find(name);

        //�v�f���g�p�������Ƃ��L�^���Ă���
    if(check && scope != container.end())
        scope->second._check();

    return scope;
}


    //�I�v�V�����A�C�e���̎Q��
OptionParameter::OptionItem OptionParameter::get(const std::string & name, bool check) throw()
{
    OptionItem                        result;
    map<string, OptionItem>::iterator scope;

    scope = _find(name, check);
    if(scope != container.end())
        result = scope->second;
    else
        result = OptionItem::createInvalidItem();

    return result;
}


    //�S�ẴI�v�V�������g�p���ꂽ���ǂ����̊m�F
bool OptionParameter::validateOption(void) const throw()
{
    map<string, OptionItem>::const_iterator scope;
    bool result = true;

        //�S�ẴI�v�V�������`�F�b�N�ς݂ł��邱�Ƃ��m�F
    scope = container.begin();
    while(scope != container.end()) {
        if(!scope->second.isChecked()) {
            result = false;
            break;
        }
        ++ scope;
    }

    return result;
}


    //�g�p����Ȃ������I�v�V��������擾
string OptionParameter::getInvalidOptions(void) const throw()
{
    map<string, OptionItem>::const_iterator scope;
    string result;

        //�g�p����Ȃ������S�ẴI�v�V�����ɑ΂���
    scope = container.begin();
    while(scope != container.end()) {
        const OptionItem & item = scope->second;
        if(!item.isChecked()) {
            result += " -";
            result += item;

                //�I�v�V�����p�����[�^�̗�
            size_t params = item.countParameter();
            for(size_t i=0; i<params; ++i) {
                result += " \"";
                result += item[i];
                result += '\"';
            }
        }
        ++ scope;
    }

        //�擪�̋󔒂���菜��
    if(!result.empty())
        result = result.substr(1);

    return result;
}

/***************** �e�X�g�X�B�[�g *****************/

#ifdef TESTSUITE
#include "coverage_undefs.h"


TESTSUITE_(main,OptionItem,OptionParameter)
{
    BEGIN_CASE("01","�f�t�H���g�p�����[�^��" DEFAULT_PARAMETER "�ɂȂ��Ă���") {
        OptionItem work;
        if(work.compare(DEFAULT_PARAMETER) != 0)
            TEST_FAIL;
    } END_CASE;

    //----

    BEGIN_CASE("02","�R���X�g���N�^�`�F�b�N (checked == false, �p�����[�^��)") {

        BEGIN_CASE("1","OptionItem(void)") {
            OptionItem work;
            if(work.checked != false)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","OptionItem(const string &)") {
            OptionItem work("test");
            if(work.compare("test") != 0 || work.checked != false)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","OptionItem(const OptionItem &)") {
            OptionItem dummy("test");
            OptionItem work(dummy);
            if(work.compare("test") != 0 || work.checked != false)
                TEST_FAIL;
        } END_CASE;

    } END_CASE;

    //----

    BEGIN_CASE("03", "addParameter / countParameter / operator []") {
        const char * container[] = { "first", "second", "third", "forth", "fifth", NULL };
        const char ** param = container;
        int i;

        OptionItem work;

        BEGIN_CASE("1", "����������countParameter��0") {
            if(work.countParameter() != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2", "addParameter���邽�т�1��������͂�") {
            while(*param != NULL) {
                size_t count = work.countParameter();

                work.addParameter(*param);

                if(work.countParameter() != count + 1)
                    TEST_FAIL;

                ++ param;
            }
        } END_CASE;

        BEGIN_CASE("3", "���ꂽ���̂͂����Ɠ����Ă�") {
            i = 0;
            param = container;
            while(*param != NULL) {
                if(work[i].compare(*param) != 0)
                    TEST_FAIL;

                ++ i;
                ++ param;
            }
        } END_CASE;

        BEGIN_CASE("4", "operator[]�ɔ͈͊O�̃p�����[�^������Ƌ󕶎����Ԃ�") {
            if(!work[10000].empty())
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    //----

    BEGIN_CASE("04", "hasParameter") {
        OptionItem work;

        BEGIN_CASE("1", "���g���Ȃ��Ƃ���false���Ԃ�") {
            if(work.hasParameter())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2", "���g������Ƃ���true���Ԃ�") {
            work.addParameter("dummy");
            if(!work.hasParameter())
                TEST_FAIL;
        } END_CASE;
    } END_CASE;
        
    //----

    BEGIN_CASE("mergeItem", "mergeItem") {
        OptionItem work;
        OptionItem work2;

        work.addParameter("one");
        work2.addParameter("two");
        
        work.mergeItem(work2);

        BEGIN_CASE("1","�}�[�W����Ă���") {
            if(work[0].compare("one") != 0 || work[1].compare("two") != 0 || work.countParameter() != 2)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�ύX���͕ω��Ȃ�") {
            if(work2[0].compare("two") != 0 || work2.countParameter() != 1)
                TEST_FAIL;
        } END_CASE;

    } END_CASE;
        
    //----

    BEGIN_CASE("isChecked/checked", "isChecked/check") {
        OptionItem work;

        BEGIN_CASE("1","�ŏ���unchecked���") {
            if(work.isChecked() != false)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","check������") {
            work._check();
            if(work.isChecked() != true)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","����������Ă��g�O���ɂȂ�Ȃ�") {
            work._check();
            if(work.isChecked() != true)
                TEST_FAIL;
        } END_CASE;

    } END_CASE;

    //----

    BEGIN_CASE("CopyConstructor", "�R�s�[�R���X�g���N�^�Ńp�����[�^���ڂ邩") {
        OptionItem src;
        src.addParameter("one");

        OptionItem dest(src);

        if(dest.countParameter() != 1 || dest[0].compare("one") != 0)
            TEST_FAIL;
    } END_CASE;

    //----

    BEGIN_CASE("TrimString", "TrinString�������Ɠ�����") {
        BEGIN_CASE("1","�擪�̋󔒕�����������") {
            string work(" \r\n\ttest");
            TrimString(work);
            if(work.compare("test") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�󔒕����������琬�镶����") {
            string work("     ");
            TrimString(work);
            if(!work.empty())
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    //----

    BEGIN_CASE("createItem", "createItem�֐��̓��쌟��") {
        BEGIN_CASE("1", "����ۂ̕�����������Ǝ��s����") {
            OptionItem work;
            string param("");
            if(OptionItem::createItem(work, param))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2", "�����Ȃ��I�v�V����") {
            OptionItem work;
            string     arg("-test");
            if(!OptionItem::createItem(work, arg))
                TEST_FAIL;
            if(work.compare("test") != 0 || work.hasParameter())
                TEST_FAIL;
            if(!arg.empty())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3", "�A����������Ȃ��I�v�V����") {
            OptionItem work;
            string     arg("-test -test2");
            if(!OptionItem::createItem(work, arg))
                TEST_FAIL;
            if(arg.compare("-test2") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4", "�������I�v�V����(-test param)") {
            OptionItem work;
            string     arg("-test param");
            if(!OptionItem::createItem(work, arg))
                TEST_FAIL;
            if(work.compare("test") != 0)
                TEST_FAIL;
            if(work.countParameter() != 1 || work[0].compare("param") != 0)
                TEST_FAIL;
            if(!arg.empty())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("5", "�������I�v�V����(-test=param)") {
            OptionItem work;
            string     arg("-test=param");
            if(!OptionItem::createItem(work, arg))
                TEST_FAIL;
            if(work.compare("test") != 0)
                TEST_FAIL;
            if(work.countParameter() != 1 || work[0].compare("param") != 0)
                TEST_FAIL;
            if(!arg.empty())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("6", "�������I�v�V����(-test=\"a b c\")") {
            OptionItem work;
            string     arg("-test=\"a b c\"");
            if(!OptionItem::createItem(work, arg))
                TEST_FAIL;
            if(work.compare("test") != 0)
                TEST_FAIL;
            if(work.countParameter() != 1 || work[0].compare("a b c") != 0)
                TEST_FAIL;
            if(!arg.empty())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("7", "�A�������������I�v�V����(-test one two)") {
            OptionItem work;
            string     arg("-test one two");
            if(!OptionItem::createItem(work, arg))
                TEST_FAIL;
            if(work.compare("test") != 0)
                TEST_FAIL;
            if(work.countParameter() != 2 || work[0].compare("one") != 0 || work[1].compare("two") != 0)
                TEST_FAIL;
            if(!arg.empty())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("8", "�n�C�t��") {
            BEGIN_CASE("1", "�n�C�t�������̈����͎󂯕t���Ȃ�") {
                OptionItem work;
                string     arg("-");
                if(OptionItem::createItem(work, arg))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2", "�n�C�t�������̈����͎󂯕t���Ȃ�(�A��)") {
                OptionItem work;
                string     arg("- - -");
                if(OptionItem::createItem(work, arg))
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("3", "�_�u���N�H�[�g�ł�����ꂽ�n�C�t���͎󂯕t����") {
                OptionItem work;
                string     arg("\"-\"");
                if(!OptionItem::createItem(work, arg))
                    TEST_FAIL;
                if(work.compare(DEFAULT_PARAMETER) != 0 || work.countParameter() != 1 || work[0].compare("-") != 0)
                    TEST_FAIL;
            } END_CASE;
    
        } END_CASE;

        BEGIN_CASE("9", "�΂ɂȂ�_�u���N�H�[�g�������������͎󂯕t���Ȃ�") {
            OptionItem work;
            string     arg("-test=\"a b c");
            if(OptionItem::createItem(work, arg))
                TEST_FAIL;
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("isValid/createInvalidItem", "�����������C���X�^���X�𐶐��ł��A����𔻒�ł���") {
        OptionItem work;

        BEGIN_CASE("1","�f�t�H���g�R���X�g���N�^�Ő��������I�u�W�F�N�g�͗L��") {
            if(!work.isValid())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�����C���X�^���X�͓��R����") {
            work = OptionItem::createInvalidItem();
            if(work.isValid())
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("getParameters","getParameters") {
        BEGIN_CASE("1","�������I�v�V�����������ł���") {
            OptionItem work;
            string     arg("-test a b c d e f g");

            TEST_CASE("0","[�O��]�I�v�V������͂ɐ�������", OptionItem::createItem(work,arg));
            TEST_CASE("1","�����ł���", work.getParameters().compare("a b c d e f g") == 0);
            TEST_CASE("2","��؂莁���w�肵�Č����ł���", work.getParameters(",").compare("a,b,c,d,e,f,g") == 0);
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("checkParameterCount","checkParameterCount") {
        BEGIN_CASE("1","�I�v�V�����̐��������Ă����true") {
            OptionItem work;
            string     arg("-test a b c d e f g");

            TEST_CASE("0","[�O��]�I�v�V������͂ɐ�������", OptionItem::createItem(work,arg));

            if(!work.checkParameterCount(7))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�I�v�V�����̐����Ԉ���Ă����false") {
            OptionItem work;
            string     arg("-test a b c d e f g");

            TEST_CASE("0","[�O��]�I�v�V������͂ɐ�������", OptionItem::createItem(work,arg));

            if(work.checkParameterCount(2))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","�I�v�V�������Ȃ��āA!allow_zero�Ȃ�false") {
            OptionItem work;
            string     arg("-test");

            TEST_CASE("0","[�O��]�I�v�V������͂ɐ�������", OptionItem::createItem(work,arg));

            if(work.checkParameterCount(1,false))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","�I�v�V�������Ȃ��āAallow_zero�Ȃ�true") {
            OptionItem work;
            string     arg("-test");

            TEST_CASE("0","[�O��]�I�v�V������͂ɐ�������", OptionItem::createItem(work,arg));

            if(work.checkParameterCount(1,true))
                TEST_FAIL;
        } END_CASE;

    } END_CASE;
}

/********************************* �e�X�g�X�B�[�g *********************************/

TESTSUITE(main,OptionParameter)
{
    SINGLETON(OptionParameter);

    BEGIN_CASE("countItem","�I�v�V�����A�C�e���̐����������擾�ł���") {
        OptionParameter param;
        if(param.countItem() != 0)
            TEST_FAIL;

        param.container.insert(pair<string, OptionItem>(DEFAULT_PARAMETER, OptionItem()));
        if(param.countItem() != 1)
            TEST_FAIL;
    } END_CASE;

    BEGIN_CASE("opeator []","operator []�ŗv�f�ɃA�N�Z�X�ł���") {
        OptionParameter param;
        OptionItem work;
        string arg("-test param");

        OptionItem::createItem(work, arg);
        param.container.insert(pair<string, OptionItem>(work, work));

        BEGIN_CASE("1", "operator [] (const string &)�ő��c�ɃA�N�Z�X�ł���") {
            if(param[string("test")][0].compare("param") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2", "operator [] (const char *)�ő��c�ɃA�N�Z�X�ł���") {
            if(param["test"][0].compare("param") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3", "operator []�ŐG��ƁAcheck������") {
            if(!param["test"].isChecked())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4", "operator []�ɖ����ȃL�[������ƁA�����ȃf�[�^���Ԃ��Ă���") {
            if(param["nonexist"].isValid())
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("get","�v�f�ւ̃A�N�Z�X") {
        OptionParameter param;
        OptionItem work;

        OptionItem::createItem(work, string("-test param"));
        param.container.insert(pair<string, OptionItem>(work, work));
        OptionItem::createItem(work, string("-test2 param2"));
        param.container.insert(pair<string, OptionItem>(work, work));

        BEGIN_CASE("1","get(test)�ŗv�f���擾�ł��A�`�F�b�N������") {
            TEST_CASE("1","�v�f�����݂���", (work = param.get("test")).isValid());
            TEST_CASE("2","�`�F�b�N�������Ă���", work.isChecked() );
            TEST_CASE("3","�v�f�̓p�����[�^������", work.hasParameter() );
        } END_CASE;

        BEGIN_CASE("2","get(test2,false)�ŗv�f���擾�ł��A�`�F�b�N�͂��Ȃ�") {
            TEST_CASE("1","�v�f�����݂���", (work = param.get("test2",false)).isValid());
            TEST_CASE("2","�`�F�b�N�������Ă��Ȃ�", !work.isChecked() );
        } END_CASE;

        BEGIN_CASE("3","���łɃ`�F�b�N�̂���test�ɑ΂��Aget(test,false)�ŗv�f���擾�ł��A�`�F�b�N�ς�") {
            TEST_CASE("1","�v�f�����݂���", (work = param.get("test",false)).isValid());
            TEST_CASE("2","�`�F�b�N�������Ă��Ȃ�", work.isChecked() );
        } END_CASE;

        BEGIN_CASE("4","get(�����Ȗ��O)�Ŗ����ȗv�f���Ԃ�") {
            TEST_CASE("1","�v�f�����݂���", !param.get("unknown").isValid());
        } END_CASE;
    } END_CASE;


    BEGIN_CASE("parseOption","�p�����[�^�̃p�[�X������ɂł��邩") {
        BEGIN_CASE("01","���g�������Ȃ��p�����[�^��^���Ă���������") {
            OptionParameter param;
            char ** argv = { NULL };

            if(!param.parseOption(0, argv))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("02","�v���O�������̓I�v�V�����Ƃ��ĉ�͂���Ȃ�") {
            OptionParameter param;
            char * argv[] = { "test.exe", NULL };

            if(!param.parseOption(1, argv))
                TEST_FAIL;
            if(param.countItem() != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("03","�p�����[�^������Ȃ�ɉ�͂����") {
            OptionParameter param;
            char * argv[] = { "test.exe", "-test", "param", "-test2=\"dummy\"", NULL };

            if(!param.parseOption(4, argv))
                TEST_FAIL;
            if(param.countItem() != 2)
                TEST_FAIL;
            
            if(param[string("test")][0].compare("param") != 0)
                TEST_FAIL;

            if(param["test2"][0].compare("dummy") != 0)
                TEST_FAIL;

            if(param.getProgramName().compare("test.exe") != 0)
                TEST_FAIL;

        } END_CASE;

        BEGIN_CASE("04","�����񂪎���") {
            OptionParameter param;
            char * argv[] = { "test.exe", "-test", "param", "-test2=\"dummy\"", NULL };

            if(!param.parseOption(4, argv))
                TEST_FAIL;

            if(param.getCommandLine().compare("-test param -test2=\"dummy\" ") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("05","���������������Ƃ��ɂ̓f�t�H���g�������Ђ��Ă���") {
            OptionParameter param;
            char * argv[] = { "test.exe", NULL };

            if(!param.parseOption(1, argv, "-default=parameter"))
                TEST_FAIL;

            if(param.getCommandLine().compare("-default=parameter ") != 0)
                TEST_FAIL;
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("04","�Q�ƃ}�[�N������") {
        OptionParameter param;
        char * argv[] = { "test.exe", "-test", "param", "-test2=\"dummy\"", NULL };

        if(!param.parseOption(4, argv))
            TEST_FAIL;

        if(param.container.find(string("test"))->second.isChecked())
            TEST_FAIL;

        param.check("test");
        if(!param.container.find(string("test"))->second.isChecked())
            TEST_FAIL;
    } END_CASE;

    BEGIN_CASE("05","validateOption") {
        OptionParameter param;
        char * argv[] = { "test.exe", "-test", "param", "-test2=\"dummy\"", NULL };

        if(!param.parseOption(4, argv))
            TEST_FAIL;

        BEGIN_CASE("1","�����g�p���Ă��Ȃ��Ƃ��ɂ�false") {
            if(param.validateOption())
                TEST_FAIL;
        } END_CASE;

        param["test"]._check();
        BEGIN_CASE("2","�ق��Ƀ`�F�b�N���Ă��Ȃ��I�v�V�����������false") {
            if(param.validateOption())
                TEST_FAIL;
        } END_CASE;

        param["test2"]._check();
        BEGIN_CASE("3","�S�Ďg�p������true") {
            if(!param.validateOption())
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("06","getInvalidOptions") {
        OptionParameter param;
        char * argv[] = { "test.exe", "-test", "param", "-test2=\"dummy\"", NULL };

        if(!param.parseOption(4, argv))
            TEST_FAIL;

        BEGIN_CASE("1","�����g�p���Ă��Ȃ��Ƃ��ɂ͑S�ẴI�v�V����������") {
            if(param.getInvalidOptions().compare("-test \"param\" -test2 \"dummy\"") != 0)
                TEST_FAIL;
        } END_CASE;

        param["test"]._check();
        BEGIN_CASE("2","�ق��Ƀ`�F�b�N���Ă��Ȃ��I�v�V����������΂��ꂪ����") {
            if(param.getInvalidOptions().compare("-test2 \"dummy\"") != 0)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("07","find") {
        OptionParameter param;
        char * argv[] = { "test.exe", "-test", "param", "-test2=\"dummy\"", NULL };

        if(!param.parseOption(4, argv))
            TEST_FAIL;

        BEGIN_CASE("1","���݂���I�v�V�����ɑ΂���true���Ԃ�") {
            if(!param.find("test") || !param.find("test2"))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","���݂��Ȃ��I�v�V�����ɑ΂���false���Ԃ�") {
            if(param.find("unknown"))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","�󕶎��ɑ΂���false���Ԃ�") {
            if(param.find(""))
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    Singleton<OptionParameter>::restoreContext(context);
}

#endif


