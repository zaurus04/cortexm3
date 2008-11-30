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
 *  @(#) $Id: jsp_check.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

// $Header: /cvsroot/jsp4cm3/jsp/cfg/jsp/jsp_check.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $

#include "base/defs.h"
#include "jsp/jsp_defs.h"
#include "base/message.h"
#include "base/component.h"
#include "base/filecontainer.h"

#include <fstream>
#include <iomanip>

class ConfigurationChecker : public Component
{
public:

    enum tagCheckLevel
    {
        UNKNOWN    = 0,
        LAZY       = 1,     /* �v���I (�s���߂������h�~�p)  */
        STANDARD   = 2,     /* ITRON�d�l�͈̔� (���������e) */
        TOPPERS    = 4,     /* TOPPERS/JSP�͈͓̔�          */
        RESTRICTED = 8,     /* �Ђ��[����߂܂���           */

        NORMAL     = 8
    };

protected:
    enum tagCheckLevel current_level;

    unsigned int error_count;
    std::string banner;

    void set_banner(Directory &, Formatter , const char *, int);
    void notify(enum tagCheckLevel, Formatter , bool = true);

    bool check_taskblock(Directory &, FileContainer *);
    bool check_semaphoreblock(Directory &, FileContainer *);
    bool check_eventflagblock(Directory &, FileContainer *);
    bool check_dataqueueblock(Directory &, FileContainer *);
    bool check_mailboxblock(Directory &, FileContainer *);
    bool check_fixed_memorypoolblock(Directory &, FileContainer *);
    bool check_cyclic_handlerblock(Directory &, FileContainer *);
    bool check_interrupt_handlerblock(Directory &, FileContainer *);
    bool check_exception_handlerblock(Directory &, FileContainer *);

    virtual void parseOption(Directory &);
    virtual void body(Directory &);

public:
    ConfigurationChecker(void) throw();
    ~ConfigurationChecker(void) throw() {}
};

//------------------------------------------------------
using namespace std;

static ConfigurationChecker  instance_of_ConfigurationChecker;

//------------------------------------------------------
    //�^�[�Q�b�g�̓����̌^�����傫�Ȍ^�̒�`
    // (��) �l��r, ���Z���\�Ȍ^�ł��邱��

typedef          int  DT_INT;
typedef unsigned int  DT_UINT;
typedef unsigned long DT_FP;
typedef unsigned long DT_VP_INT;
typedef unsigned long DT_VP;
typedef          long DT_RELTIM;

//------------------------------------------------------

ConfigurationChecker::ConfigurationChecker(void) throw()
{
    setBanner("--- TOPPERS/JSP Configuration Checker (ver 2.4) ---");
}

void ConfigurationChecker::set_banner(Directory & container, Formatter object, const char * type, int id)
{
    Directory * node;
    char buffer[32];

    banner = string("    ") + object.str() + " : ";

    sprintf(buffer, "id = %d", id);

    node = container.findChild(OBJECTTREE, type, NULL)->getFirstChild();
    while(node != 0 && node->toInteger() != id)
        node = node->getNext();

    if( node != 0 ) {
        banner += node->getKey() + " (" + buffer + ") ";

        node = node->findChild("position");
        if(node != 0)
            banner += string("at ") + node->toString();
    }
    else
        banner += buffer;

    if(VerboseMessage::getVerbose())
    {
        cout << banner << endl;
        banner.erase();
    }
}

void ConfigurationChecker::notify(enum tagCheckLevel level, Formatter msg, bool error)
{
    if((level & current_level) != 0)
    {

        if(!banner.empty())
        {
            cout << banner << endl;
            banner.erase();
        }

        cout << "      ";

        if(error)
        {
            cout << Message("[ Error ] ","[�G���[] ");
            error_count ++;
        }else
            cout << Message("[Warning] ","[ �x�� ] ");
        cout << msg << endl;
    }
}

    /*
     * �^�X�N�I�u�W�F�N�g�Ɋւ���G���[���o
     */

bool ConfigurationChecker::check_taskblock(Directory & parameter, FileContainer * container)
{
    unsigned int id;
    unsigned int maxpri;
    unsigned int minpri;
    unsigned int old_error_count = error_count;

    TargetVariable<unsigned int> _kernel_tmax_tskid("_kernel_tmax_tskid");

    Message object("Task","�^�X�N");

    if(!_kernel_tmax_tskid.isValid())
        ExceptionMessage(
            "Internal error: Unknown symbol (Probably, Symbol table was stripped)",
            "�����G���[: �s���ȃV���{���� (���s�`�����V���{���e�[�u�����܂�łȂ��\��������܂�)").throwException();

    if(*_kernel_tmax_tskid < 1)
    {
        notify(RESTRICTED,
            Message("  [Task] : No tasks created\n","  [�^�X�N] : �^�X�N�I�u�W�F�N�g������܂���\n"));
        return true;
    }

    TargetVariable<DT_UINT> tskatr("_kernel_tinib_table", "task_initialization_block::tskatr");
    TargetVariable<DT_FP>   task("_kernel_tinib_table", "task_initialization_block::task");
    TargetVariable<DT_INT>  ipriority("_kernel_tinib_table", "task_initialization_block::ipriority");
    TargetVariable<DT_UINT> texatr("_kernel_tinib_table", "task_initialization_block::texatr");
    TargetVariable<DT_UINT> stksz("_kernel_tinib_table", "task_initialization_block::stksz");

    maxpri = container->getVariableInfo("TMAX_TPRI").value;
    minpri = container->getVariableInfo("TMIN_TPRI").value;

    VerboseMessage("% object : % items\n","%�I�u�W�F�N�g : % ��\n") << object << *_kernel_tmax_tskid;
    for(id = 1; id <= *_kernel_tmax_tskid; id++)
    {
        set_banner(parameter, object, TASK, id);

            /*
             *  �����`�F�b�N
             */

            // �����l�� TA_HLNG|TA_ASM|TA_ACT �ȊO�̒l���Ƃ��Ă���
        if((*tskatr & ~0x3) != 0)
            notify( STANDARD,
                Message("Illegal task attribute (It should be ((TA_HLNG||TA_ASM)|TA_ACT))",
                        "�s���ȃ^�X�N���� ((TA_HLNG||TA_ASM)|TA_ACT)�ȊO"));

            // �����l�� TA_ASM ���܂܂�Ă���
        if((*tskatr & 0x1) != 0)
            notify( RESTRICTED,
                Message("TA_ASM specified as task attribute takes no effect.",
                        "�^�X�N������TA_ASM���w�肳��Ă���"));

            /* �N���Ԓn��0 */
        if(*task == 0)
            notify(RESTRICTED,
                Message("The address of task routine is equal to zero.",
                        "�J�n�Ԓn��0���ݒ肳��Ă��܂�"));

            /*
             *  �D��x�`�F�b�N
             */

            // �ő�D��x�ƍŏ��D��x�̐ݒ肪��������
        if(maxpri < minpri)
            notify(LAZY,
                Message("Illegal Priority Settings found (TMAX_TPRI(%) < TMIN_TPRI).",
                        "�����D��x���Œ�D��x(%)�𒴂��Ă���") << minpri);

            // �D��x�͈̔͂�[�ŏ��D��x, �ő�D��x]�͈̔͂𒴂��Ă���
        if(*ipriority > (signed)(maxpri - minpri))
            notify(TOPPERS,
                Message("Initial priority is greater than maximum priority (%).",
                        "�����D��x���ő�D��x(%)�𒴂��Ă���") << maxpri);
        if(*ipriority < 0)
            notify(STANDARD,
                Message("Initial priority is less than the minimum priority (%).",
                        "�����D��x���Œ�D��x(%)�������") << minpri);

            /*
             *   �^�X�N��O�����`�F�b�N
             */

            // �����l��TA_HLNG or TA_ASM�łȂ�
        if((*texatr & ~0x3) != 0)
            notify(STANDARD,
                Message("Task exception routine has an illegal attribute specifier.",
                        "�^�X�N��O�ɖ����ȑ���(TA_HLNG,TA_ASM�ȊO) ���ݒ肳��Ă��܂�"));

            // �����l�� TA_ASM ���܂܂�Ă���
        if((*texatr & 0x1) != 0)
            notify( RESTRICTED,
                Message("TA_ASM, specified as texatr, does not always take effect.",
                        "�^�X�N��O��TA_ASM���w�肳��Ă��܂�"));

            /*
             *   �X�^�b�N�`�F�b�N
             */

            // �X�^�b�N�T�C�Y��0
        if(*stksz == 0)
            notify(RESTRICTED,
                Message("Stack size is equal to zero.",
                        "�X�^�b�N�T�C�Y��0���ݒ肳��Ă��܂�"));

            // �X�^�b�N�̔Ԓn��0
        if(*stksz == 0)
            notify(RESTRICTED,
                Message("The address of task stack is equal to zero.",
                        "�X�^�b�N�J�n�Ԓn��0���ݒ肳��Ă��܂�"));

        ++ tskatr, ++ task, ++ ipriority, ++ texatr, ++ stksz;
    }

    return old_error_count == error_count;
}

bool ConfigurationChecker::check_semaphoreblock(Directory & parameter, FileContainer * container)
{
    unsigned int id;
    unsigned int old_error_count = error_count;

    Message object("Semaphore","�Z�}�t�H");

    TargetVariable<DT_UINT> _kernel_tmax_semid("_kernel_tmax_semid");
    if(*_kernel_tmax_semid < 1)
        return true;

    TargetVariable<DT_UINT> sematr("_kernel_seminib_table","semaphore_initialization_block::sematr");
    TargetVariable<DT_UINT> maxsem("_kernel_seminib_table","semaphore_initialization_block::maxsem");
    TargetVariable<DT_UINT> isemcnt("_kernel_seminib_table","semaphore_initialization_block::isemcnt");

    VerboseMessage("% object : % items\n","%�I�u�W�F�N�g : % ��\n")
        << object << *_kernel_tmax_semid;

    for(id = 1; id <= *_kernel_tmax_semid; id++)
    {
        set_banner(parameter, object, SEMAPHORE, id);

            //attribute validation check
        if((*sematr & ~0x1) != 0)
            notify(STANDARD,
                Message("Illegal attribute (It should be (TA_TFIFO||TA_TPRI)).",
                        "(TA_TFIFO||TA_TPRI)�ȊO�̑������w�肳��Ă���"));

            //maxcnt < isemcnt
        if(*maxsem < *isemcnt)
            notify(STANDARD,
                Message("Initial count[%] is greater than the maximum count[%] of this semaphore",
                        "�����l[%]���ő�l[%]�𒴂��Ă���") << *isemcnt << *maxsem);

        if(*maxsem == 0)
            notify(STANDARD,
                Message("Maximum count must be greater than zero.",
                        "�Z�}�t�H�̍ő�J�E���g��1�ȏ�łȂ���΂����܂���"));

        ++ sematr, ++ maxsem, ++ isemcnt;
    }

    return old_error_count == error_count;
}


bool ConfigurationChecker::check_eventflagblock(Directory & parameter, FileContainer * container)
{
    unsigned int id;
    unsigned int old_error_count = error_count;

    Message object("Event flag","�C�x���g�t���O");

    TargetVariable<DT_UINT> _kernel_tmax_flgid("_kernel_tmax_flgid");
    if(*_kernel_tmax_flgid < 1)
        return true;

    TargetVariable<DT_UINT> flgatr("_kernel_flginib_table","eventflag_initialization_block::flgatr");

    VerboseMessage("% object : % items\n","%�I�u�W�F�N�g : % ��\n")
         << object << *_kernel_tmax_flgid;

    for(id = 1; id <= *_kernel_tmax_flgid; id++)
    {
        set_banner(parameter, object, EVENTFLAG, id);
            
            //attribute validation check
        if((*flgatr & ~0x7) != 0)
            notify(STANDARD,
                Message("Illegal attribute value [0x%]",
                        "�������ȑ����l [0x%]") << setbase(16) << (*flgatr & ~0x7));

        if((*flgatr & 0x2) != 0)
            notify(TOPPERS,     //�ˑ����Œ���Ȃ��̂�RESTRICTED�ɂ��Ȃ�
                Message("Attribute TA_WMUL is not supported in current version.",
                        "TA_WMUL�̓T�|�[�g�O"));
    
        ++ flgatr;
    }

    return old_error_count == error_count;
}


bool ConfigurationChecker::check_dataqueueblock(Directory & parameter, FileContainer * container)
{
    unsigned int id;
    unsigned int old_error_count = error_count;

    Message object("Data queue","�f�[�^�L���[");

    TargetVariable<DT_UINT> _kernel_tmax_dtqid("_kernel_tmax_dtqid");
    if(*_kernel_tmax_dtqid < 1)
        return true;

    TargetVariable<DT_UINT> dtqatr("_kernel_dtqinib_table", "dataqueue_initialization_block::dtqatr");
    TargetVariable<DT_UINT> dtqcnt("_kernel_dtqinib_table", "dataqueue_initialization_block::dtqcnt");
    TargetVariable<DT_VP_INT> dtq("_kernel_dtqinib_table", "dataqueue_initialization_block::dtq");

    VerboseMessage("% object : % items\n","%�I�u�W�F�N�g : % ��\n")
        << object << *_kernel_tmax_dtqid;

    for(id = 1; id <= *_kernel_tmax_dtqid; id++)
    {
        set_banner(parameter, object, DATAQUEUE, id);

            //attribute validation check
        if((*dtqatr & ~0x1) != 0)
            notify(STANDARD,
                Message("Illegal attribute value [0x%]",
                        "�������ȑ����l [0x%]") << setbase(16) << (*dtqatr & ~0x1));

        if(*dtqcnt != 0 && *dtq == 0)
            notify(TOPPERS,
                Message("Dataqueue buffer should not be NULL", "�f�[�^�L���[�̃o�b�t�@��NULL�l"));

        ++ dtqatr, ++ dtqcnt, ++ dtq;
    }

    return old_error_count == error_count;
}


bool ConfigurationChecker::check_mailboxblock(Directory & parameter, FileContainer * container)
{
    unsigned int id;
    unsigned int old_error_count = error_count;

    Message object("Mailbox","���[���{�b�N�X");

    TargetVariable<DT_UINT> _kernel_tmax_mbxid("_kernel_tmax_mbxid");
    if(*_kernel_tmax_mbxid < 1)
        return true;
    
    TargetVariable<DT_UINT> mbxatr("_kernel_mbxinib_table","mailbox_initialization_block::mbxatr");
    TargetVariable<DT_INT>  maxmpri("_kernel_mbxinib_table","mailbox_initialization_block::maxmpri");

    DT_INT maxpri = container->getVariableInfo("TMAX_MPRI").value;
    DT_INT minpri = container->getVariableInfo("TMIN_MPRI").value;

    VerboseMessage("% object : % items\n","%�I�u�W�F�N�g : % ��\n") << object << *_kernel_tmax_mbxid;
    for(id = 1; id <= *_kernel_tmax_mbxid; id++)
    {
        set_banner(parameter, object, MAILBOX, id);

            //attribute validation check
        if((*mbxatr & ~0x3) != 0)
            notify(STANDARD,
                Message("Illegal attribute value [0x%]",
                        "�������ȑ����l [0x%]") << setbase(16) << (*mbxatr & ~0x3));
    
            //mailbox message priority check
        if(*maxmpri < 0)
            notify(STANDARD,
                Message("Priority must not be a negative number.","�D��x�����l"));

        if(*maxmpri < minpri)
            notify(STANDARD,
                Message("Message priority should be greater than or equal to %.",
                        "���b�Z�[�W�D��x��%�ȏ�łȂ���΂����܂���") << minpri);

        if(*maxmpri > maxpri)
            notify(STANDARD,
                Message("Message priority should be less than or equal to %.",
                        "���b�Z�[�W�D��x��%�ȉ��łȂ���΂����܂���") << maxpri);

        ++ mbxatr, ++ maxmpri;
    }

    return old_error_count == error_count;
}

bool ConfigurationChecker::check_fixed_memorypoolblock(Directory & parameter, FileContainer * container)
{
    unsigned int id;
    unsigned int old_error_count = error_count;

    Message object("Fixed size memory pool","�Œ蒷�������v�[��");

    TargetVariable<DT_UINT> _kernel_tmax_mpfid("_kernel_tmax_mpfid");
    if(*_kernel_tmax_mpfid < 1)
        return true;

    TargetVariable<DT_UINT> mpfatr("_kernel_mpfinib_table", "fixed_memorypool_initialization_block::mpfatr");
    TargetVariable<DT_UINT> limit ("_kernel_mpfinib_table", "fixed_memorypool_initialization_block::limit");
    TargetVariable<DT_VP>   mpf   ("_kernel_mpfinib_table", "fixed_memorypool_initialization_block::mpf");
    TargetVariable<DT_UINT> blksz ("_kernel_mpfinib_table", "fixed_memorypool_initialization_block::blksz");

    VerboseMessage("% object : % items\n","%�I�u�W�F�N�g : % ��\n") << object << *_kernel_tmax_mpfid;
    for(id = 1; id <= *_kernel_tmax_mpfid; id++)
    {
        set_banner(parameter, object, FIXEDSIZEMEMORYPOOL, id);

            //attribute validation check
        if((*mpfatr & ~0x1) != 0)
            notify(STANDARD,
                Message("Illegal attribute value [0x%]","�������ȑ����l [0x%]") << (*mpfatr & ~0x1));

            //�u���b�N����0
        if(*mpf == *limit)
            notify(STANDARD,
                Message("blkcnt should be a non-zero value.","�u���b�N����0�ł�"));

            //�u���b�N�T�C�Y��0
        if(*blksz == 0)
            notify(STANDARD,
                Message("blksz should be a non-zero value.","�u���b�N�T�C�Y��0�ł�"));

            //�o�b�t�@�A�h���X��0
        if(*mpf == 0)
            notify(TOPPERS,
                Message("buffer address is a NULL pointer.","�o�b�t�@�A�h���X��NULL�|�C���^�ɂȂ��Ă��܂�"));

        ++ mpfatr, ++ limit, ++ mpf, ++ blksz;
    }

    return old_error_count == error_count;
}


bool ConfigurationChecker::check_cyclic_handlerblock(Directory & parameter, FileContainer * container)
{
    unsigned int id;
    unsigned int old_error_count = error_count;

    Message object("Cyclic handler","�����n���h��");

    TargetVariable<DT_UINT> _kernel_tmax_cycid("_kernel_tmax_cycid");
    if(*_kernel_tmax_cycid < 1)
        return true;

    DT_RELTIM maxreltim = container->getVariableInfo("TMAX_RELTIM").value;
    TargetVariable<DT_UINT> cycatr("_kernel_cycinib_table", "cyclic_handler_initialization_block::cycatr");
    TargetVariable<DT_RELTIM> cyctim("_kernel_cycinib_table", "cyclic_handler_initialization_block::cyctim");
    TargetVariable<DT_RELTIM> cycphs("_kernel_cycinib_table", "cyclic_handler_initialization_block::cycphs");

    VerboseMessage("% object : % items\n","%�I�u�W�F�N�g : % ��\n") << object << *_kernel_tmax_cycid;
    for(id = 1; id <= *_kernel_tmax_cycid; id++)
    {
        set_banner(parameter, object, CYCLICHANDLER, id);

            //attribute validation check
        if((*cycatr & ~0x7) != 0)
            notify(STANDARD,
                Message("Illegal attribute value [0x%]","�������ȑ����l [0x%]") << (*cycatr & ~0x1));

        if((*cycatr & 0x4) != 0)
            notify(TOPPERS,     //��ˑ����Ȃ̂�RESTRICTED�ɂ��Ȃ�
                Message("TA_PHS is not supported in this kernel.","TA_PHS�̓T�|�[�g�O"));

            // �����l�� TA_ASM ���܂܂�Ă���
        if((*cycatr & 0x1) != 0)
            notify( RESTRICTED,
                Message("TOPPERS/JSP Kernel never minds the flag 'TA_ASM'.",
                        "TOPPERS/JSP�J�[�l���̑S�Ă̋@��ˑ�����TA_ASM���T�|�[�g����Ƃ͌���Ȃ�"));

            //RELTIM�ł̕\���͈͓��ɂ��邩�ǂ����̃`�F�b�N
        if(*cyctim > maxreltim)
            notify(STANDARD,
                Message("The cyclic object has a period (%) that exceeds the maximum period (%)",
                        "�N������(%)���\���\�ȑ��Ύ��Ԃ͈̔�(%)�𒴂��Ă��܂�") << *cyctim << maxreltim);

            //�N��������0�łȂ����Ƃ̃`�F�b�N
        if(*cyctim == 0)
            notify(STANDARD,
                Message("The cyclic object has a ZERO period.",
                        "�N��������0�ɂȂ��Ă��܂�"));

        if(*cycphs > maxreltim)
            notify(STANDARD,
                Message("The cyclic object has a initial delay (%) that exceeds the maximum period (%)",
                        "�N���ʑ�(%)���\���\�ȑ��Ύ��Ԃ͈̔�(%)�𒴂��Ă��܂�") << *cycphs << maxreltim);

        ++ cycatr, ++ cyctim, ++ cycphs;
    }

    return old_error_count == error_count;
}

bool ConfigurationChecker::check_interrupt_handlerblock(Directory & parameter, FileContainer * container)
{
    unsigned int id;
    unsigned int old_error_count = error_count;

    Message object("Interrupt handler","�����݃n���h��");

    TargetVariable<DT_UINT> _kernel_tnum_inhno("_kernel_tnum_inhno");
    if(*_kernel_tnum_inhno == 0)
        return true;

    TargetVariable<DT_UINT> inhatr("_kernel_inhinib_table", "interrupt_handler_initialization_block::inhatr");
    TargetVariable<DT_FP>   inthdr("_kernel_inhinib_table", "interrupt_handler_initialization_block::inthdr");

    VerboseMessage("% object : % items\n","%�I�u�W�F�N�g : % ��\n") << object << *_kernel_tnum_inhno;
    for(id = 0; id < *_kernel_tnum_inhno; id++)
    {
        set_banner(parameter, object, INTERRUPTHANDLER, id);

            //attribute validation check
        if((*inhatr & 0x1) != 0)
            notify(STANDARD,
                Message("The attribute can take only TA_HLNG|TA_ASM",
                        "TA_HLNG|TA_ASM�ȊO�̑����͐ݒ�ł��܂���"));

            // �����l�� TA_ASM ���܂܂�Ă���
        if((*inhatr & 0x1) != 0)
            notify(RESTRICTED,
                Message("TOPPERS/JSP Kernel never minds the flag 'TA_ASM'.",
                        "TA_ASM���g�p����Ă���"));

            // �N���Ԓn�`�F�b�N
        if(*inthdr == 0)
            notify(RESTRICTED,
                Message("NULL pointer is specified as an inthdr address.",
                        "�����݃n���h���̔Ԓn��NULL�ł�"));

        ++ inhatr, ++ inthdr;
    }

    return old_error_count == error_count;
}

bool ConfigurationChecker::check_exception_handlerblock(Directory & parameter, FileContainer * container)
{
    unsigned int id;
    unsigned int old_error_count = error_count;

    Message object("Exception handler","��O�n���h��");

    TargetVariable<DT_UINT> _kernel_tnum_excno("_kernel_tnum_excno");
    if(*_kernel_tnum_excno == 0)
        return true;

    TargetVariable<DT_UINT> excatr("_kernel_excinib_table", "cpu_exception_handler_initialization_block::excatr");
    TargetVariable<DT_FP>   exchdr("_kernel_excinib_table", "cpu_exception_handler_initialization_block::exchdr");

    VerboseMessage("% object : % items\n","%�I�u�W�F�N�g : % ��\n") << object << *_kernel_tnum_excno;
    for(id = 0; id < *_kernel_tnum_excno; id++)
    {
        set_banner(parameter, object, EXCEPTIONHANDLER, id);

            //attribute validation check
        if((*excatr & 0x1) != 0)
            notify(STANDARD,
                Message("The attribute can take only TA_HLNG|TA_ASM",
                        "TA_HLNG|TA_ASM�ȊO�̑����͐ݒ�ł��܂���"));

            // �����l�� TA_ASM ���܂܂�Ă���
        if((*excatr & 0x1) != 0)
            notify(RESTRICTED,
                Message("TOPPERS/JSP Kernel never minds the flag 'TA_ASM'.",
                        "TOPPERS/JSP�J�[�l���̑S�Ă̋@��ˑ�����TA_ASM���T�|�[�g����Ƃ͌���Ȃ�"));

            // �N���Ԓn�`�F�b�N
        if(*exchdr == 0)
            notify(RESTRICTED,
                Message("NULL pointer is specified as an exchdr address.",
                        "��O�n���h���̔Ԓn��NULL�ł�"));

        ++ excatr, ++ exchdr;
    }

    return old_error_count == error_count;
}

//------------------------------------------------------

void ConfigurationChecker::parseOption(Directory & parameter)
{
    string loadmodule;
    string work;

    if(findOption("h","help"))
    {
        cout << endl << Message(
            "Configuration checker - option\n"
            "  -m, --module=filename : Specify the load module (essential option)\n"
            "  -cs, --script=filename  : Specify the checker script file\n"
            "  -cl, --checklevel=level : Specify one of the check levels below \n"
            "    l(azy)       : Minimum check will be performed.\n"
            "    s(tandard)   : includes some ITRON Standard check items.\n"
            "    t(oppers)    : checks whether it meets TOPPERS/JSP restrictions\n"
            "    r(estricted) : All of check items will be performed.\n",
            "�R���t�B�M�����[�V�����`�F�b�J - �I�v�V����\n"
            "  -m, --module=�t�@�C���� : ���[�h���W���[�������w�肵�܂� (�K�{����)\n"
            "  -cs, --script=�t�@�C����  : �`�F�b�J�X�N���v�g���w�肵�܂�\n"
            "  -cl, --checklevel=level : Specify one of the check levels below \n"
            "    l(azy)       : �ŏ����̃`�F�b�N�݂̂��s���܂�\n"
            "    s(tandard)   : ITRON�d�l�͈̔͂Ń`�F�b�N���s���܂�\n"
            "    t(oppers)    : TOPPERS/JSP�J�[�l���̐����𖞂������Ƃ��m�F���܂�\n"
            "    r(estricted) : �@��ˑ������܂ߑS�Ẵ`�F�b�N���ڂ����{���܂�\n");
        cout << endl 
             << Message("Supported architecture : ", "�Ή��A�[�L�e�N�`�� : ")
             << FileContainer::getInstance()->getArchitecture()
             << endl;
        return;
    }

    if(findOption("m","module",&loadmodule) || findOption(DEFAULT_PARAMETER,NULL,&loadmodule))
    {
        if(findOption("s","source"))
            ExceptionMessage("Configuration checker can not execute while Configurator executes","�R���t�B�M�����[�^�ƃ`�F�b�J�͓����ɋN���ł��܂���").throwException();

        parameter["/file/loadmodule"] = loadmodule;
        activateComponent();
    }

    if(!findOption("cs","script",&work))
        work = loadmodule.substr(0,loadmodule.find_last_of('.')) + ".chk";
    parameter["/file/checkerscript"] = work;

    work.erase();
    if(findOption("obj","load-object",&work))
    {
        if(work.empty())
            work.assign("kernel_obj.dat");

        fstream f(work.c_str(), ios::in|ios::binary);
        if(f.is_open())
        {
            parameter["/object"].Load(&f);
            f.close();
        }else
            ExceptionMessage(" Failed to open the file '%' for storing object definitions"," �I�u�W�F�N�g�����i�[���邽�߂̃t�@�C��(%)���J���܂���") << work << throwException;
    }

    if(findOption("cl","checklevel",&work))
    {
        current_level = UNKNOWN;

        if(work.compare("lazy") == 0 || work[0] == 'l')
            current_level = LAZY;
        if(work.compare("standard") == 0 || work[0] == 's')
            current_level = STANDARD;
        if(work.compare("toppers") == 0 || work[0] == 't')
            current_level = TOPPERS;
        if(work.compare("restricted") == 0 || work[0] == 'r')
            current_level = RESTRICTED;

        if(current_level == UNKNOWN)
            ExceptionMessage(" Unknown check level [%] specified"," �����ȃ`�F�b�N���x���w�� [%]") << work << throwException;
    }else
        current_level = NORMAL;

    checkOption("cpu", "cpu");
    checkOption("system", "system");
}

void ConfigurationChecker::body(Directory & parameter)
{
    FileContainer * container;
    bool result = true;

        /* ���D��x�̍����G���[���Ώۂ� */
    current_level = static_cast<enum tagCheckLevel>(static_cast<int>(current_level) * 2 - 1);

    container = FileContainer::getInstance();
    container->attachInfo(parameter["/file/checkerscript"].toString());
    container->attachModule(parameter["/file/loadmodule"].toString());

    if(VerboseMessage::getVerbose())
    {
        cout << Message("  Target architecture : ","  �^�[�Q�b�g�A�[�L�e�N�`�� : ")
             << container->getArchitecture() << endl;
    }

    error_count = 0;
    result &= check_taskblock(parameter,container);
    result &= check_semaphoreblock(parameter,container);
    result &= check_eventflagblock(parameter,container);
    result &= check_dataqueueblock(parameter,container);
    result &= check_mailboxblock(parameter,container);
    result &= check_fixed_memorypoolblock(parameter,container);
    result &= check_cyclic_handlerblock(parameter,container);
    result &= check_interrupt_handlerblock(parameter,container);
    result &= check_exception_handlerblock(parameter,container);

    if(!result)
        ExceptionMessage("Total % errors found in current configuration.\n","�S����%�̃G���[�����o����܂���\n") << error_count << throwException;

    VerboseMessage("No error found in current configuration\n","�\���Ɉُ�͂���܂���ł���\n");
}

