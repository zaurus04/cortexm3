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
 *  @(#) $Id: fc_bfd.cpp,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


#include "base/filecontainer.h"

#include "base/message.h"

#include "bfd.h"
#include "libiberty.h"

#include <string>
#include <map>

using namespace std;


/*
 *  BFD���g�����t�@�C���R���e�i�N���X
 */
class filecontainer_BFD : public filecontainer
{
protected:
    bfd * object;                           //�I�u�W�F�N�g
    map<string, asymbol *> symbol_table;    //�����p�n�b�V�����ǂ�
    asymbol ** symbol_container;

public:
    filecontainer_BFD(void)  throw();
    ~filecontainer_BFD(void) throw();

    virtual bool attach_module(const char *);
    virtual bool change_endian(void * target, unsigned int size);
    virtual bool load_contents(void * dest, unsigned long address, unsigned int size);
    virtual unsigned long get_symbol_address(const char *);
    virtual const char * get_architecture(void);

} Instance_of_filecontainer_BFD;

filecontainer_BFD::filecontainer_BFD(void) throw()
{
    bfd_init();

    object = NULL;
    symbol_table.clear();
    symbol_container = NULL;
    instance = this;
}

filecontainer_BFD::~filecontainer_BFD(void) throw()
{
    if(object != NULL)
        bfd_close(object);
}

/*
 *  attach_module : �Ώۃ��W���[�����A�^�b�`����
 */
bool filecontainer_BFD::attach_module(const char * filename)
{
    char ** target_list;
    asymbol ** symbols;
    asymbol *  sym;
    int num_syms;
    boolean result;
    int i;

    if(object != NULL)
        bfd_close(object);
    symbol_table.clear();

        //���W���[���I�[�v�� (�Ǎ��p)
    object = bfd_openr(filename, "default");

        //�^�[�Q�b�g����
    target_list = (char **)bfd_target_list();
    result = bfd_check_format_matches(object, bfd_object, &target_list);
    if(result == 0)
        ExceptionMessage("Internel error: BFD could not recognize the target file format.","�����G���[: BFD�̓t�@�C���̓ǂݏo���Ɏ��s���܂���").throwException();

        //�V���{���̃n�b�V�����ǂ��쐬
    symbols = (asymbol **)xmalloc( bfd_get_symtab_upper_bound(object) );
    num_syms = bfd_canonicalize_symtab(object, symbols);

    for(i=0;i<num_syms;i++)
    {
        sym = *(symbols+i);
        if(sym != NULL && sym->name != NULL && *(sym->name) != '\x0')
            symbol_table[string(sym->name)] = sym;
    }

    symbol_container = symbols;
    return true;
}

bool filecontainer_BFD::change_endian(void * target, unsigned int size)
{
        //�z�X�g�̓��g���Ɖ���
    enum bfd_endian host_endian = BFD_ENDIAN_LITTLE;

    char * top, * tail;

    if(object == NULL)
        return false;

    if(object->xvec->byteorder == BFD_ENDIAN_UNKNOWN)
        return false;

/*
    unsigned int __work = 0x1;
    if( *(char *)__work == 0)
        host_endian = BFD_ENDIAN_BIG;
*/

    if(object->xvec->byteorder == host_endian)
        return true;

    /*
     *  ���C�����[�v : bswap���Ȃ��ŁA�f���ɏ���
     */

    top  = (char *)target;
    tail = (char *)target+size -1;

    while(top < tail)
    {
        *top ^= *tail, *tail ^= *top, *top ^= *tail;
        top ++;
        tail --;
    }

    return true;
}


bool filecontainer_BFD::load_contents(void * dest, unsigned long address, unsigned int size)
{
    struct sec * section;

    if(object == 0)
        return false;

        //�ΏۃA�h���X��ۗL����Z�N�V������T��
    section = object->sections;
    while(section != 0)
    {
        if(address - (unsigned long)section->vma <= section->_raw_size 
            && (section->flags & (SEC_ALLOC|SEC_HAS_CONTENTS)) == (SEC_ALLOC|SEC_HAS_CONTENTS))
        {
                //�ǂݏo��
            bfd_get_section_contents(object, section, dest, address - (unsigned long)section->vma, size);
            return true;
        }
        section = section->next;
    }

        //�ǂ��ɂ��Ȃ�
    ExceptionMessage("Internel error: Memory read with unmapped address","�����G���[; �}�b�v����ĂȂ��A�h���X���g���ă��������[�h���s���܂���").throwException();

    return false;
}


/*
 * get_symbol_address : �V���{��������A�h���X�l���擾����
 */
unsigned long filecontainer_BFD::get_symbol_address(const char * symbol)
{
    map<string, asymbol *>::iterator scope;
    string symbol_name;

    if(object == 0)
        ExceptionMessage("Not initialized","����������Ă܂���").throwException();

        //�V���{�����𐶐����� ("_"�Ƃ��̏���)
    if(object->xvec->symbol_leading_char != '\x0')
        symbol_name += object->xvec->symbol_leading_char;
    symbol_name += symbol;

    scope = symbol_table.find(symbol_name);
    if(scope == symbol_table.end())
        return 0;
        //Exception("Internal error: Unknown symbol [%s]","�����G���[: �s���ȃV���{�� [%s]").format(symbol_name.c_str());

        //Address = �Z�N�V�������I�t�Z�b�g�l + �Z�N�V������VMA
    return (*scope).second->value + (*scope).second->section->vma;
}

/*
 * get_architecture : �A�[�L�e�N�`�����̎擾
 */
const char * filecontainer_BFD::get_architecture(void)
{
    if(object == NULL)
        return "Unknown";

        //�Ƃ肠�����^�[�Q�b�g���������ăA�[�L�e�N�`�����ɂ��Ă����B
        // #�ǂ����o�i�[�ɂ����g���ĂȂ����� ���̂Ƃ���
    return object->xvec->name;
}

