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
 *  @(#) $Id: jsp_checkscript.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/jsp/jsp_checkscript.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $

#include "jsp/jsp_defs.h"
#include "jsp/jsp_common.h"

#include <string>
#include <iostream>

#include "base/component.h"
#include "base/mpstrstream.h"

using namespace std;
using namespace ToppersJsp;

class CheckScriptGenerator : public Component
{
protected:
    virtual void parseOption(Directory & container);
    virtual void body(Directory & container);
    
    void insertMagic(void) throw(Exception);

public:
    CheckScriptGenerator(void) : Component(FINALIZE) {};
} instance_of_CheckScriptGenerator;

void CheckScriptGenerator::parseOption(Directory & container)
{
    MultipartStream * stream;
    string work;

    if(findOption("h","help"))
    {
        cerr << '\n' << Message(
            "Configuration Checker Script Generation Option\n"
            "  -c, --check  : Generate a checker script\n",
            "�J�[�l���\���`�F�b�N�X�N���v�g�����p�I�v�V����\n"
            "  -c, --check  : �`�F�b�N�X�N���v�g�𐶐����܂�\n");
        return;
    }

    if(findOption("c","check",&work))
    {
        if(work.empty())
            work.assign("kernel_chk.c");

        stream = new MultipartStream(work);
        stream->createPart("header")
               .createPart("body")
               .createPart("footer");

        container["/file/kernel_chk"] = stream;

        checkOption("ci","checker-macro");
        activateComponent();
    }
}

static void createScriptEntry(Directory & container, MultipartStream * out, const char * objname, const char * member, bool mode = true)
{
    string work;
    string inib;
    Directory * scope;
    int i, j;
    
    (*out) << container.format("\n\t\t/* $@ */\n\n");

    if(mode)
    {
        scope = container.getFirstChild();
        while(scope != 0)
        {
            work = scope->getKey();
            if(work[0] < '0' || work[1] > '9')
                (*out) << "\tOBJECT(" << container.getKey() << '_' << scope->toInteger() << ',' << work << ");\n";

            scope = scope->getNext();
        }

        (*out) << container.format("\tEVAR(ID,_kernel_tmax_$(/prefix/$@/id)id);\n");
    }else
    {
        i = 0;
        scope = container.getFirstChild();
        while(scope != 0)
        {
            work = scope->getKey();
            (*out) << "\tOBJECT(" << container.getKey() << '_' << (i++) << ',' << scope->getKey() << ");\n";
            scope = scope->getNext();
        }

        (*out) << container.format("\tEVAR(ID,_kernel_tnum_$(/prefix/$@/id)no);\n");
    }

    (*out) << container.format("\tEVAR($(/prefix/$@/SID)INIB,_kernel_$(/prefix/$@/sid)inib_table);\n");

    work.assign(member);
    i = 0;
    j = work.find_first_of(',');
    if(objname == NULL)
        inib = container.getKey();
    else
        inib = objname;
    
    do {
        (*out) << "\tMEMBER(" << inib << "_initialization_block," << work.substr(i, j-i) << ");\n";

        i = j + 1;
        j = work.find_first_of(',', i);
    } while(i != string::npos+1);
    (*out) << '\n';
}

inline void createScriptEntry(Directory & container, MultipartStream * out, const char * member)
{   createScriptEntry(container, out, NULL, member, true);  }

void CheckScriptGenerator::insertMagic(void) throw(Exception)
{
    KernelCfg * out = dynamic_cast<KernelCfg *>(RuntimeObjectTable::getInstance(typeid(KernelCfg)));
    if(out != 0) {
        out->movePart("others");
        out->createPart("checkscript");
        (*out) << Message("\t/* Variables for kernel checker */\n", "\t/* �J�[�l���`�F�b�J�p�ϐ� */\n");
        (*out) << "const UW _checker_magic_number = 0x01234567;\n\n";
    }
}

void CheckScriptGenerator::body(Directory & container)
{
    MultipartStream * out;

    out = reinterpret_cast<MultipartStream *>(container["/file/kernel_chk"].toPointer());

    out->movePart("header") <<
        "#include \"jsp_kernel.h\"\n"
        "#include \"logtask.h\"\n"
        "#include \"timer.h\"\n\n";


	string work;
	if(findOption("ci","checker-macro",&work)) {

			/* ���g����łȂ�������include�����邪�C��Ȃ�include����f���Ȃ� */
		if(!work.empty())
			(*out) << "#include \"" << work << "\"\n\n";
	}
	else {
		(*out) <<	"#define OBJECT(x,y) __asm(\"d\" #x \",\" #y \"@\");\n"
			        "#define MEMBER(x,y) __asm(\"s\" #x \"::\" #y \",(%0),(%1)@\" ::\\\n"
			        "     \"i\"(sizeof(((struct x *)0)->y)), \"i\"(&((struct x *)0)->y));\n"
			        "#define VAR(x) __asm(\"s\" #x \",(%0),(0)@\" :: \"i\"(sizeof(x)));\n"
			        "#define EVAR(x,y) __asm(\"s\" #y \",(%0),(0)@\" :: \"i\"(sizeof(x)));\n"
			        "#define SVAR(x) __asm(\"s\" #x \",(%0),(0)@\" :: \"i\"(sizeof(x[0])));\n"
			        "#define DEFS(x) __asm(\"s\" #x \",(%0),(0)@\" :: \"i\"((unsigned long)x));\n\n";
	}

    (*out) <<	"#include \"queue.h\"\n\n"
		        "#include \"task.h\"\n"
		        "#include \"semaphore.h\"\n"
		        "#include \"eventflag.h\"\n"
		        "#include \"dataqueue.h\"\n"
		        "#include \"mailbox.h\"\n"
		        "#include \"mempfix.h\"\n"
		        "#include \"cyclic.h\"\n"
		        "#include \"../kernel/exception.h\"\n"
		        "#include \"interrupt.h\"\n"
		        "#include \"wait.h\"\n\n"
		        "void checker_function(void)\n{\n";

    out->movePart("footer") << "}\n";

    out->movePart("body") <<
        "\tDEFS(TMAX_TPRI);\n\tDEFS(TMIN_TPRI);\n\n"
        "\tDEFS(TMAX_MPRI);\n\tDEFS(TMIN_MPRI);\n\n"
//      "\tDEFS(TMAX_MAXSEM);\n\n"
        "\tDEFS(TMAX_RELTIM);\n\n"
        "\tMEMBER(queue,next);\n\tMEMBER(queue,prev);\n\n";

    createScriptEntry(container[OBJECTTREE "/" TASK],      out, "tskatr,exinf,task,ipriority,stksz,stk,texatr,texrtn");
    createScriptEntry(container[OBJECTTREE "/" SEMAPHORE], out, "sematr,isemcnt,maxsem");
    createScriptEntry(container[OBJECTTREE "/" EVENTFLAG], out, "flgatr,iflgptn");
    createScriptEntry(container[OBJECTTREE "/" DATAQUEUE], out, "dtqatr,dtqcnt,dtq");
    createScriptEntry(container[OBJECTTREE "/" MAILBOX], out, "mbxatr,maxmpri");
    createScriptEntry(container[OBJECTTREE "/" FIXEDSIZEMEMORYPOOL], out, "fixed_memorypool", "mpfatr,blksz,mpf,limit");
    createScriptEntry(container[OBJECTTREE "/" CYCLICHANDLER], out, "cyclic_handler", "cycatr,exinf,cychdr,cyctim,cycphs");
    createScriptEntry(container[OBJECTTREE "/" INTERRUPTHANDLER], out, "interrupt_handler", "inhno,inhatr,inthdr", false);
    createScriptEntry(container[OBJECTTREE "/" EXCEPTIONHANDLER], out, "cpu_exception_handler", "excno,excatr,exchdr", false);

    insertMagic();

    VerboseMessage("Configuration check script generation was finished successfully.\n","�J�[�l���\���`�F�b�N�X�N���v�g�t�@�C�����o�͂��܂���\n");
}

