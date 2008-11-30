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
 *  @(#) $Id: mpstrstream.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/mpstrstream.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $

#include "base/mpstrstream.h"

using namespace std;

/*
 *   �������ʂ���Ȃ�X�g���[���̈ꕔ�ʂɑ�������N���X
 */

    //�R���X�g���N�^
MultipartStream::Part::Part(string _name) throw() : name(_name)
{}

    //�R�s�[�R���X�g���N�^
MultipartStream::Part::Part(const MultipartStream::Part & src) throw() : name("")
{
    if(src.isValid()) {
        name.assign(src.name);
        setContents(src.getContents());
    }
}

    //�X�g���[���ɏ��������e���󂯎��
string MultipartStream::Part::getContents(void) const throw(Exception)
{
    string result;

    if(isValid())
        result = stream.str();
    else
        ExceptionMessage("Operation was performed against an invalid stream.","�����ȃX�g���[���ɑ΂��đ��삪�s���܂���").throwException();

    return result;
}

    //�X�g���[���̓��e�𒼐ڐݒ肷��
void MultipartStream::Part::setContents(string contents) throw(Exception)
{
    if(isValid()) {
        stream.clear();
        stream << contents;
    }
    else
        ExceptionMessage("Operation was performed against an invalid stream.","�����ȃX�g���[���ɑ΂��đ��삪�s���܂���").throwException();
}



/*
 *   �������ʂ���Ȃ�X�g���[���̈ꕔ�ʂɑ�������N���X
 */

    //�R���X�g���N�^
MultipartStream::MultipartStream(string _filename) throw() : filename(_filename), current(0), dirty(false), output(true)
{
    dirty = isValid();  //��ł����Ă��t�@�C�������Ȃ��Ƃ����Ȃ��̂�...   
}

MultipartStream::~MultipartStream(void) throw()
{
    if(isValid() && dirty) {
            //�W
        try { serialize(); }
        catch(...) {}
    }
}

    //�t�@�C�����̊֘A�t��
string MultipartStream::setFilename(string _filename) throw(Exception)
{
    string result;

    if(this != 0) {
        if(!_filename.empty()) {
            result   = filename;
            filename = _filename;
            dirty    = isValid();
        }
        else
            ExceptionMessage("Empty filename should not be allowed.","��̃t�@�C�����͎g�p�ł��Ȃ�").throwException();
    }
    else
        ExceptionMessage("Invalid object can not perform the request.","�����ȃI�u�W�F�N�g�ɑ΂���v���͎��s�ł��Ȃ�").throwException();

    return result;
}

    //�t�@�C���o�� (�{���Ƀt�@�C���ɏo�͂����Ƃ�����true)
bool MultipartStream::serialize(void) throw(Exception)
{
    bool result = false;

    if(isValid() && dirty && output) {

        fstream file(filename.c_str(), ios::out);
        if(file.is_open()) {
            list<Part>::iterator scope;

                //�S�Ă̕��ʂ̓��e���o��
            scope = parts.begin();
            while(scope != parts.end()) {
                file << scope->getContents();
                ++ scope;
            }

            file.close();
            dirty  = false;
            result = true;
        }
        else {
            ExceptionMessage("File could not open [%]","�t�@�C�����J���Ȃ� [%]") << filename << throwException;
            disableOutput();    //�f�X�g���N�^��������x���킷��̂�
        }
    }
    else {
        if(!isValid())
            ExceptionMessage("Invalid object can not perform the request.","�����ȃI�u�W�F�N�g�ɑ΂���v���͎��s�ł��Ȃ�").throwException();
    }

    return result;
}

    //���ʂ̍쐬
MultipartStream & MultipartStream::createPart(string name, bool precedence) throw(Exception)
{
    if(this != 0) {
        list<Part>::iterator scope;
        list<Part>::iterator newnode;

            //�������O���Ȃ����Ƃ��m�F
        scope = parts.begin();
        while(scope != parts.end()) {
            if(scope->getName().compare(name) == 0) {
                ExceptionMessage("The part \"%\" is already created.","���ʖ�[%]�͂��łɗ��p����Ă���") << name << throwException;
                break;
            }
            ++ scope;
        }

            //�������O���Ȃ��Ȃ�v�f��ǉ�
        if(scope == parts.end()) {
            
                //�}���ʒu�̌���
            if(current != 0) {
                scope = parts.begin();
                while(scope != parts.end() && &(*scope) != current)
                    ++ scope;

                    //�}���ʒu�̒��� (���݈ʒu�����ɂ��炷 when precedence = false; )
                if(scope != parts.end() && !precedence)
                    ++ scope;
            }
            else
                scope = parts.end();

                //�v�f�̑}��
            newnode = parts.insert(scope, Part(name));
            current = &(*newnode);
        }
    }else
        ExceptionMessage("Invalid object can not perform the request.","�����ȃI�u�W�F�N�g�ɑ΂���v���͎��s�ł��Ȃ�").throwException();

    return *this;
}

    //���ʂ̑I��
MultipartStream & MultipartStream::movePart(string name) throw(Exception)
{
    list<Part>::iterator scope;

    if(this != 0 && !name.empty()) {

            //���O����v������̂�T��
        scope = parts.begin();
        while(scope != parts.end()) {
            if(scope->getName() == name) {
                current = &(*scope);
                break;
            }
            ++ scope;
        }

            //������Ȃ�����
        if(scope == parts.end())
            ExceptionMessage("Unknown part [%] specified.","�����Ȏ��ʖ� [%]") << name << throwException;
    }
    else{
        if(this == 0)
            ExceptionMessage("Invalid object can not perform the request.","�����ȃI�u�W�F�N�g�ɑ΂���v���͎��s�ł��Ȃ�").throwException();
        else //if(name.empty()) //��O��if�̏������A����if�͏�ɐ^
            ExceptionMessage("Empty identifier was passed as a name of part.","�󕶎����n���ꂽ").throwException();
    }

    return *this;
}


/********************************** �e�X�g�X�B�[�g **********************************/

#ifdef TESTSUITE

#include "coverage_undefs.h"

#include <iomanip>
#include <cstdio>

#ifdef _MSC_VER
#  pragma warning(disable:4101)   //���[�J���ϐ��͈�x���g���Ă��܂���
#endif

TESTSUITE_(main,Part, MultipartStream)
{
    BEGIN_CASE("constructor/isValid","�R���X�g���N�^ / ����������") {
        BEGIN_CASE("1","���O���ō쐬������L���ȃp�[�g������") {
            Part part("test");
            if(!part.isValid())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","���O�Ȃ��ō쐬�����疳���ȃp�[�g�ɂȂ�") {
            Part part("");
            if(part.isValid())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","NULL�͖����ȃp�[�g") {
            if(((Part *)0)->isValid())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","NULL�I�u�W�F�N�g�ŃR�s�[�R���X�g���N�^���N�����Ă����s���Ȃ�") {
            Part * part = 0;
            Part work(*part);
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("operator <<","operator <<") {
        BEGIN_CASE("1", "�o�͂ł���") {
            Part part("test");

            part << "test";

            if(part.stream.str().compare("test") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2", "iomanip���g����") {
            Part part("test");

            part << setw(8) << setbase(16) << setfill('0') << 0x1234567;

            if(part.stream.str().compare("01234567") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3", "�����ȃX�g���[���ɏ��������O���N��") {
            Part part("");
            bool result = false;

            if(part.isValid())
                TEST_FAIL;

            Exception::setThrowControl(true);
            try {
                Message::selectLanguage(Message::NEUTRAL);
                part << setw(8) << setbase(16) << setfill('0') << 0x1234567;
            }
            catch(Exception & e) {
                if(e.getDetails().compare("Operation was performed against an invalid stream.") == 0)
                    result = true;
            }
            if(!result)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("getContents","getContents") {
        BEGIN_CASE("1", "���������e���擾�ł���") {
            Part part("test");

            part << "test";

            if(part.getContents().compare("test") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2", "�����ēǂ�ł܂������ēǂ߂�") {
            Part part("test");

            part << "abc";
            if(part.getContents().compare("abc") != 0)
                TEST_FAIL;

            part << "def";
            if(part.getContents().compare("abcdef") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3", "�����ȃX�g���[������ǂ񂾂��O���N��") {
            Part part("");
            bool result = false;

            if(part.isValid())
                TEST_FAIL;

            Exception::setThrowControl(true);
            try {
                string work = part.getContents();
            }
            catch(Exception & e) {
                if(e.getDetails().compare("Operation was performed against an invalid stream.") == 0)
                    result = true;
            }
            if(!result)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("setContents","setContents") {
        BEGIN_CASE("1", "�ݒ肵�����e���擾�ł���") {
            Part part("test");

            part.setContents("test");

            if(part.getContents().compare("test") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2", "setContents�Őݒ肵�����ƂɒǋL�ł���") {
            Part part("test");

            part.setContents("abc");
            part << "def";
            if(part.getContents().compare("abcdef") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3", "�����ȃX�g���[���ɐݒ肵�����O���N��") {
            Part part("");
            bool result = false;

            if(part.isValid())
                TEST_FAIL;

            Exception::setThrowControl(true);
            try {
                part.setContents("test");
            }
            catch(Exception & e) {
                if(e.getDetails().compare("Operation was performed against an invalid stream.") == 0)
                    result = true;
            }
            if(!result)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("getName","getName") {
        BEGIN_CASE("1", "�p�[�g�����������擾�ł���") {
            Part part("name_of_stream");

            if(part.getName().compare("name_of_stream") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2", "�s���ȃp�[�g�̖��O�����Ɨ�O���N��") {
            Part part("");
            bool result = false;

            Exception::setThrowControl(true);
            try { string work = part.getName(); }
            catch(Exception & e) {
                if(e.getDetails().compare("Operation was performed against an invalid stream.") == 0)
                    result = true;
            }
            if(!result)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("CopyConstructor","�R�s�[�R���X�g���N�^") {
        Part source("test");
        source << "abcdefg";

        Part dest(source);
        BEGIN_CASE("1","�X�g���[���̓��e���������R�s�[�ł��Ă���") {
            if(dest.getContents().compare("abcdefg") != 0)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","���ʖ����������R�s�[�ł��Ă���") {
            if(dest.getName() != source.getName())
                TEST_FAIL;
        } END_CASE;
    } END_CASE;
}

TESTSUITE(main,MultipartStream)
{
    BEGIN_CASE("constructor/isValid","constructor/isValid") {
        BEGIN_CASE("1","�t�@�C�������w�肵�Đ��������I�u�W�F�N�g�͗L��") {
            MultipartStream mps("test.dat");

            if(!mps.isValid())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2","�t�@�C�����������Ȃ��I�u�W�F�N�g�͖���") {
            MultipartStream mps;

            if(mps.isValid())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","��̃t�@�C���������I�u�W�F�N�g�͖���") {
            MultipartStream mps("");

            if(mps.isValid())
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","NULL�I�u�W�F�N�g�͖���") {
            if(((MultipartStream *)0)->isValid())
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("setFilename","setFilename") {
        BEGIN_CASE("1","�t�@�C�������w�肹���ɐ��������t�@�C���ɖ��O������") {
            MultipartStream mps;
            if(mps.isValid())
                TEST_FAIL;

            BEGIN_CASE("1","�X�g���[���͗L���ɂȂ�") {
                mps.setFilename("test");
                if(!mps.isValid())
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�X�g���[���̖��O���ύX����Ă���") {
                if(mps.filename.compare("test") != 0)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("2","�t�@�C�������w�肵�Đ��������t�@�C���ɖ��O������") {
            MultipartStream mps("initialname");
            if(!mps.isValid())
                TEST_FAIL;

            BEGIN_CASE("1","�X�g���[���͗L���ɂȂ�") {
                mps.setFilename("test");
                if(!mps.isValid())
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�X�g���[���̖��O���ύX����Ă���") {
                if(mps.filename.compare("test") != 0)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("3","�󕶎���n���Ɨ�O") {
            MultipartStream mps;
            bool result = false;

            Exception::setThrowControl(true);
            try { mps.setFilename(""); }
            catch(Exception & e)
            {   result = true;   }
            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","NULL�I�u�W�F�N�g�ɖ��O������Ɨ�O") {
            bool result = false;

            Exception::setThrowControl(true);
            try { ((MultipartStream *)0)->setFilename("test"); }
            catch(Exception & e)
            {   result = true;   }
            if(!result)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("serialize","serialize") {

        BEGIN_CASE("1", "NULL�I�u�W�F�N�g�ɑ΂���V���A���C�Y�͗�O") {
            bool result = false;

            Exception::setThrowControl(true);
            try 
            {   ((MultipartStream *)0)->serialize();   }
            catch(Exception & e)
            {   result = true;   }

            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("2", "�����ȃI�u�W�F�N�g�ɑ΂���V���A���C�Y����O") {
            bool result = false;
            MultipartStream mps;

            Exception::setThrowControl(true);
            try
            {   mps.serialize();   }
            catch(Exception & e)
            {   result = true;   }

            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3", "����ɃV���A���C�Y�ł���") {
            MultipartStream mps("debug.out");
            Part part("abc");

            part << "abcdefg";
            mps.parts.push_back(part);
            mps.dirty = true;

            ::remove("debug.out");
            BEGIN_CASE("1", "�V���A���C�Y��true��Ԃ�") {
                if(!mps.serialize())
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2", "�o�͂����t�@�C���̓��e��������") {
                if(!TestSuite::compareFileContents("debug.out","abcdefg"))
                    TEST_FAIL;
            } END_CASE;
            
        } END_CASE;

        BEGIN_CASE("4", "���e�������Ă�dirty=false�Ȃ�o�͂���Ȃ�") {
            MultipartStream mps("debug.out");
            Part part("abc");

            part << "abcdefg";
            mps.parts.push_back(part);
            mps.dirty = false;

            ::remove("debug.out");
            BEGIN_CASE("1", "�V���A���C�Y��false��Ԃ�") {
                if(mps.serialize())
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2", "�t�@�C���͏o�͂���Ă��Ȃ�") {
                fstream file("debug.out",ios::in);
                if(file.is_open())
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("5", "���e�������Ă��o�͋֎~�Ȃ�o�͂���Ȃ�") {
            MultipartStream mps("debug.out");
            Part part("abc");

            part << "abcdefg";
            mps.parts.push_back(part);
            mps.dirty = true;

            mps.disableOutput();

            ::remove("debug.out");
            BEGIN_CASE("1", "�V���A���C�Y��false��Ԃ�") {
                if(mps.serialize())
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2", "�t�@�C���͏o�͂���Ă��Ȃ�") {
                fstream file("debug.out",ios::in);
                if(file.is_open())
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("Destructor","Destructor") {
        BEGIN_CASE("1","����ĉ�") {
            MultipartStream mps("debug.out");
            Part part("abc");

            part << "abcdefg";
            mps.parts.push_back(part);
            mps.dirty = true;

            ::remove("debug.out");
        } END_CASE;

        BEGIN_CASE("2","���e���t�@�C���Ɋi�[����Ă���") {
            if(!TestSuite::compareFileContents("debug.out","abcdefg"))
                TEST_FAIL;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("createPart","createPart") {
        BEGIN_CASE("1","�p�[�g��o�^����") {
            MultipartStream mps("debug.out");
            mps.disableOutput();

            BEGIN_CASE("1","��O�Ȃ��o�^�ł���") {
                Exception::setThrowControl(true);
                mps .createPart("abc")
                    .createPart("def")
                    .createPart("ghi");
            } END_CASE;

            BEGIN_CASE("2","���g���o�^���ŕ���ł���") {
                list<Part>::iterator scope;
                scope = mps.parts.begin();
                if(scope->getName().compare("abc") != 0)
                    TEST_FAIL;
                ++ scope;
                if(scope->getName().compare("def") != 0)
                    TEST_FAIL;
                ++ scope;
                if(scope->getName().compare("ghi") != 0)
                    TEST_FAIL;
                ++ scope;
                if(scope != mps.parts.end())
                    TEST_FAIL;
            } END_CASE;

        } END_CASE;

        BEGIN_CASE("2","�p�[�g���t���œo�^����") {
            MultipartStream mps("debug.out");
            mps.disableOutput();

            BEGIN_CASE("1","��O�Ȃ��o�^�ł���") {
                Exception::setThrowControl(true);
                mps .createPart("abc",true)
                    .createPart("def",true)
                    .createPart("ghi",true);
            } END_CASE;

            BEGIN_CASE("2","���g���o�^�����t���ŕ���ł���") {
                list<Part>::iterator scope;
                scope = mps.parts.begin();
                if(scope->getName().compare("ghi") != 0)
                    TEST_FAIL;
                ++ scope;
                if(scope->getName().compare("def") != 0)
                    TEST_FAIL;
                ++ scope;
                if(scope->getName().compare("abc") != 0)
                    TEST_FAIL;
                ++ scope;
                if(scope != mps.parts.end())
                    TEST_FAIL;
            } END_CASE;

        } END_CASE;

        BEGIN_CASE("3","NULL�ɑ΂��鑀��ŗ�O����������") {
            bool result = false;
            Exception::setThrowControl(true);
            try {
                ((MultipartStream *)0)->createPart("test");
            }
            catch(...)
            {   result = true;   }
            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","�������O�̃p�[�g�����Ɨ�O���N��") {
            BEGIN_CASE("1","�������O�̃p�[�g�����Ɨ�O���N��") {
                bool result = false;
                MultipartStream mps("debug.out");
                Exception::setThrowControl(true);

                try {
                    mps .createPart("abc")
                        .createPart("def")
                        .createPart("abc");
                }
                catch(...)
                {   result = true;   }

                if(!result)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","��O�𕕂��Ă�����������") {
                bool result = true;
                MultipartStream mps("debug.out");
                Exception::setThrowControl(false);

                BEGIN_CASE("1","��O�̓X���[����Ȃ�") {
                try {
                        mps .createPart("abc")
                            .createPart("def")
                            .createPart("abc");
                    }
                    catch(...)
                    {   result = false;   }

                    if(!result)
                        TEST_FAIL;
                } END_CASE;

                BEGIN_CASE("2","���݈ʒu�͕ω����Ȃ�") {
                    if(mps.current == 0 || mps.current->getName().compare("def") != 0)
                        TEST_FAIL;
                } END_CASE;
            } END_CASE;
        } END_CASE;

        Exception::setThrowControl(true);

        BEGIN_CASE("5","�o�^����ƌ��݈ʒu���ω�����") {
            MultipartStream mps("debug.out");
            mps.disableOutput();

            BEGIN_CASE("1","�o�^����ƈʒu���ω����� (1)") {
                mps.createPart("abc");
                if(mps.current == 0 || mps.current->getName().compare("abc") != 0)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�o�^����ƈʒu���ω����� (2)") {
                mps.createPart("def");
                if(mps.current == 0 || mps.current->getName().compare("def") != 0)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("3","�o�^����ƈʒu���ω����� (3)") {
                mps.createPart("ghi");
                if(mps.current == 0 || mps.current->getName().compare("ghi") != 0)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;
    } END_CASE;

    BEGIN_CASE("opeator <<","operator <<") {

        BEGIN_CASE("1","operator <<���g����") {
            MultipartStream mps("debug.out");

            mps.createPart("test");

            mps << "abcdefghijklmn";
        } END_CASE;

        BEGIN_CASE("2","�o�͂��ꂽ���g��������") {
            if(!TestSuite::compareFileContents("debug.out","abcdefghijklmn"))
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("3","NULL�I�u�W�F�N�g�ɏo�͂���Ɨ�O") {
            bool result = false;
            Exception::setThrowControl(true);
            try {
                *((MultipartStream *)0) << "test";
            }
            catch(...)
            {   result = true;   }
            if(!result)
                TEST_FAIL;
        } END_CASE;

        BEGIN_CASE("4","�p�[�g��S������Ă��Ȃ��I�u�W�F�N�g�ɏo�͂���Ɨ�O") {
            bool result = false;
            Exception::setThrowControl(true);
            try {
                MultipartStream mps("debug.out");
                mps.disableOutput();
                *((MultipartStream *)0) << "test";
            }
            catch(...)
            {   result = true;   }
            if(!result)
                TEST_FAIL;
        } END_CASE;

    } END_CASE;

    BEGIN_CASE("movePart/operator []","movePart/operator []") {
        BEGIN_CASE("1","���ʂɈړ�����") {
            MultipartStream mps("debug.out");
            mps.disableOutput();

            mps .createPart("abc")
                .createPart("def")
                .createPart("ghi");

            BEGIN_CASE("1","�ړ��ł���") {
                mps.movePart("def");

                if(mps.current->getName().compare("def") != 0)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("2","�����Ȗ��O������Ɨ�O") {
                bool result = false;
                Exception::setThrowControl(true);

                try {
                    mps.movePart("unknwon");
                }
                catch(...)
                {   result = true;   }
                if(!result)
                    TEST_FAIL;
            } END_CASE;

            BEGIN_CASE("3","�󕶎�������Ɨ�O") {
                bool result = false;
                Exception::setThrowControl(true);

                try {
                    mps.movePart("");
                }
                catch(...)
                {   result = true;   }
                if(!result)
                    TEST_FAIL;
            } END_CASE;
        } END_CASE;

        BEGIN_CASE("2", "NULL�I�u�W�F�N�g����ɑ��삷��Ɨ�O") {
            bool result = false;
            Exception::setThrowControl(true);

            try {
                ((MultipartStream *)0)->movePart("");
            }
            catch(...)
            {   result = true;   }
            if(!result)
                TEST_FAIL;
        } END_CASE;
    } END_CASE;
}


#endif




