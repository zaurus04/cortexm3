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
 *  @(#) $Id: coverage.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#include "base/coverage_defs.h"
#include "base/coverage_undefs.h"

#include <iostream>
#include <iomanip>

using namespace std;

#if defined(COVERAGE)
/*
 *   �ȒP�ȃJ�o���b�W�`�F�b�N
 */

    //�t�H�[�}�b�g�ς݃t�@�C���ʒu���̎擾
string Coverage::Location::getDetails(void) const
{
    string result;

    result = string(filename) + ":" + String(lineno);
    if(*additional != '\x0')
        result += string("(") + additional + ")";

    return result;
}



    //�v�f�̑S�폜
Coverage::BranchMap::~BranchMap(void) throw()
{
    iterator scope;

    scope = begin();
    while(scope != end()) {
        delete scope->second;
        ++ scope;
    }

    clear();
}

    //�v�f�̓o�^
Coverage::BranchBase::BranchBase(const Location & location) throw()
{
    BranchMap * bmap = Singleton<BranchMap>::getInstance();
    NewBranchList * blist = Singleton<NewBranchList>::getInstance();

    (*bmap)[location] = this;
    blist->push_back(this);
}

    //location�Ɉ�v����v�f�̎擾
Coverage::BranchBase * Coverage::BranchBase::find(const Location & location) throw()
{
    BranchMap * bmap = Singleton<BranchMap>::getInstance();
    BranchMap::iterator scope;
    BranchBase * result = 0;

    scope = bmap->find(location);
    if(scope != bmap->end())
        result = scope->second;

    return result;
}

    //BranchIf�R���X�g���N�^
Coverage::If::If(const Location & location) throw() : BranchBase(location), true_case(false), false_case(false)
{}

    //if�̐��������� (����/�s�����̗������N���Ă���)
bool Coverage::If::checkValidity(void) const throw()
{   return true_case && false_case;   }

    //�ʉߏ��̎擾
string Coverage::If::getDetails(void) const throw()
{
    string result;

    if(true_case)
        result += "true";

    if(false_case) {
        if(true_case)
            result += "/";
        result += "false";
    }

    return result;
}

    //if����̃`�F�b�N
bool Coverage::If::branch(const Location & location, bool expression) throw()
{
    If * node = dynamic_cast<If *>(find(location));
    if(node == 0)
        node = new(nothrow) If(location);

    if(node != 0) {
        if(expression)
            node->true_case = true;
        else
            node->false_case = true;
    }
    else
        cerr << "[Coverage::Branch] Memory allocation error!\n";

    return expression;
}


    //While�R���X�g���N�^
Coverage::While::While(const Location & location) throw() : BranchBase(location), valid(false)
{}

    //While�̐��������� (���Ȃ��Ƃ����̓��[�v�̒����܂���Ă���)
bool Coverage::While::checkValidity(void) const throw()
{   return valid;   }

    //�ʉߏ��̎擾
string Coverage::While::getDetails(void) const throw()
{
    string result;

    if(valid)
        result = "valid";
    else
        result = "invalid";

    return result;
}

    //while����̃`�F�b�N (���Ȃ��Ƃ����̓��[�v�̒����܂���Ă���)
bool Coverage::While::branch(const Location & location, bool expression) throw()
{
    While * node = dynamic_cast<While *>(find(location));
    if(node == 0)
        node = new(nothrow) While(location);

    if(node != 0) {
        if(expression)
            node->valid = true;
    }
    else
        cerr << "[Coverage::Branch] Memory allocation error!\n";

    return expression;
}


    //Switch�R���X�g���N�^
Coverage::Switch::Switch(const Location & location) throw() : BranchBase(location)
{}

    //Switch�̐��������� (�ʉ߂����v�f�������o���Ă��� (��X��������ꂽ��))
bool Coverage::Switch::checkValidity(void) const throw()
{   return true;   }

    //�ʉߏ��̎擾
string Coverage::Switch::getDetails(void) const throw()
{
    stringstream buf;
    set<int>::const_iterator scope;

    scope = checkpoint.begin();
    while(scope != checkpoint.end()) {
        buf << *scope;

        ++ scope;
        if(scope != checkpoint.end())
            buf << ", ";
    }
        
    return buf.str();
}

    //Switch����̃`�F�b�N
void Coverage::Switch::_branch(const Location & location, int expression) throw()
{
    Switch * node = dynamic_cast<Switch *>(find(location));
    if(node == 0)
        node = new(nothrow) Switch(location);

    if(node != 0) {
        if(expression)
            node->checkpoint.insert(expression);
    }
    else
        cerr << "[Coverage::Branch] Memory allocation error!\n";
}

    //�S�Ă̍��ڂ�\��
void Coverage::printCoverage(ostream & out)
{
    BranchMap * bmap = Singleton<BranchMap>::getInstance();
    BranchMap::iterator scope;

    unsigned long cases = 0;
    unsigned long fails = 0;

    scope = bmap->begin();
    while(scope != bmap->end()) {
        ++ cases;

        if(scope->second->checkValidity())
            out << "Success : ";
        else {
            out << "Failure : ";
            ++ fails;
        }
        out << scope->first.getDetails() << ' ' << scope->second->getDetails() << '\n';

        ++ scope;
    }

    out << fails << " fails in " << cases << " cases (" << setprecision(2) << (fails * 100.0 / cases) << "%)\n";
}

    //�S�Ēʉ߂������ǂ����̃`�F�b�N
bool Coverage::checkValidity(void)
{
    bool result = true;

    NewBranchList * blist = Singleton<NewBranchList>::getInstance();
    NewBranchList::iterator scope;

    scope = blist->begin();
    while(scope != blist->end()) {
        if(!(*scope)->checkValidity())
            result = false;
        ++ scope;
    }

    blist->clear();
    return result;
}
    //���̂̎擾
string Coverage::getBranchName(BranchBase * node)
{
        //��v����v�f�̌���
    BranchMap * bmap = Singleton<BranchMap>::getInstance();
    BranchMap::iterator scope;

    scope = bmap->begin();
    while(scope != bmap->end()) {
        if(scope->second == node)
            break;
        ++ scope;
    }

    //assert(scope != bmap->end());
    
    return scope->first.getDetails();
}

#endif /* COVERAGE */

