/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2005 by Embedded and Real-Time Systems Laboratory
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
 */

/*
 *      �v���Z�b�T�ˑ����W���[�� �A�Z���u�����ꕔ�iXstormy16�p�j
 */

#define _MACRO_ONLY
#include <offset.h>
#include <cpu_sfrs.h>

/*
 *  �^�X�N�E���荞�݁E��O�Ǘ��pRAM�̈�
 */
        .section .data_0,"aw"

                                /*
                                 *  ���荞�݁E��O�l�X�g�J�E���^
                                 *  (�J�[�l���N�������^�X�N�R���e�L�X�g��
                                 *  ���Ĉ������ߏ����l��1�Ƃ���)
                                 */
        .global _kernel_intnest
_kernel_intnest:
        .hword 1

                                /*
                                 *  ���荞�݃n���h���e�[�u��
                                 *  (UART���荞�݂��܂�17��)
                                 */
        .global _kernel_ih_table
_kernel_ih_table:
        .hword 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

                                /*
                                 *  ��O�n���h���e�[�u��
                                 *  (����`����/��Ԓn���[�h�A�N�Z�X/
                                 *  �������O/reserved)
                                 */
        .global _kernel_eh_table
_kernel_eh_table:
        .hword 0,0,0,0

/*
 *  ���荞�݃x�N�g��
 *  (����section��8000h-8083h�Ƀ����N�����)
 */
        .section .int_vec,"ax"
        .global _start
        .align 1
_start:
	clr1 psw,#7
        br _kernel_int_irq_0
	clr1 psw,#7
        br _kernel_int_irq_1
	clr1 psw,#7
        br _kernel_int_irq_2
	clr1 psw,#7
        br _kernel_int_irq_3
	clr1 psw,#7
        br _kernel_int_irq_4
	clr1 psw,#7
        br _kernel_int_irq_5
	clr1 psw,#7
        br _kernel_int_irq_6
	clr1 psw,#7
        br _kernel_int_irq_7
	clr1 psw,#7
        br _kernel_int_irq_8
	clr1 psw,#7
        br _kernel_int_irq_9
	clr1 psw,#7
        br _kernel_int_irq_a
	clr1 psw,#7
        br _kernel_int_irq_b
	clr1 psw,#7
        br _kernel_int_irq_c
	clr1 psw,#7
        br _kernel_int_irq_d
	clr1 psw,#7
        br _kernel_int_irq_e
	clr1 psw,#7
        br _kernel_int_irq_f
        .org 0x80
        jmpf _kernel_int_irq_ex

/*
 *  ���荞�݃n���h�������
 */
_kernel_int_irq_0:
                                /*
                                 *  ���b�`�h�b�O�^�C�}���荞�݂�RESET���̔��f
                                 */
        bn __WDTCR,#4,_after_reset
        bp __WDTCR,#5,_after_reset
        push r0
        mov r0,#_kernel_ih_table+0
        br _int_common
_after_reset:
	jmpf _int_reset
_kernel_int_irq_1:
        push r0
        mov r0,#_kernel_ih_table+2
        br _int_common
_kernel_int_irq_2:
        push r0
        mov r0,#_kernel_ih_table+4
        br _int_common
_kernel_int_irq_3:
        push r0
        mov r0,#_kernel_ih_table+6
        br _int_common
_kernel_int_irq_4:
        push r0
        mov r0,#_kernel_ih_table+8
        br _int_common
_kernel_int_irq_5:
        push r0
        mov r0,#_kernel_ih_table+10
        br _int_common
_kernel_int_irq_6:
        push r0
        mov r0,#_kernel_ih_table+12
        br _int_common
_kernel_int_irq_7:
        push r0
        mov r0,#_kernel_ih_table+14
        br _int_common
_kernel_int_irq_8:
        push r0
        mov r0,#_kernel_ih_table+16
        br _int_common
_kernel_int_irq_9:
        push r0
        mov r0,#_kernel_ih_table+18
        br _int_common
_kernel_int_irq_a:
        push r0
        mov r0,#_kernel_ih_table+20
        br _int_common
_kernel_int_irq_b:
        push r0
        mov r0,#_kernel_ih_table+22
        br _int_common
_kernel_int_irq_c:
        push r0
        mov r0,#_kernel_ih_table+24
        br _int_common
_kernel_int_irq_d:
        push r0
        mov r0,#_kernel_ih_table+26
        br _int_common
_kernel_int_irq_e:
        push r0
        mov r0,#_kernel_ih_table+28
        br _int_common
_kernel_int_irq_f:
        push r0
        mov r0,#_kernel_ih_table+30
        br _int_common

/*
 *  ���荞�݃n���h�����������
 */
_int_common:
                                /*
                                 *  r1/r2�̑ޔ�(r0�͑ޔ��ς�)
                                 */
        push r1
        push r2
                                /*
                                 *  �l�X�g�������荞�݂��ǂ����`�F�b�N
                                 */
        mov r1,_kernel_intnest
        bz interrupt_from_task

/*
 *  �l�X�g�������荞�݂̏���
 */
                                /*
                                 *  �l�X�g�J�E���^���C���N�������g���A
                                 *  ��ʂ̊��荞�݂�����
                                 */
        inc r1
        mov _kernel_intnest,r1
        set1 psw,#7
                                /*
                                 *  r3-r9(caller saved register)�̑ޔ�
                                 */
        push r3
        push r4
        push r5
        push r6
        push r7
        push r8
        push r9
                                /*
                                 *  ���荞�݃n���h���̌Ăяo��
                                 */
        mov r1,(r0)
        bz 1f
        mov r8,#0
        call r8,r1
1:
                                /*
                                 *  r1-r9�̕���
                                 */
        pop r9
        pop r8
        pop r7
        pop r6
        pop r5
        pop r4
        pop r3
        pop r2
        pop r1
                                /*
                                 *  �l�X�g�J�E���^���f�N�������g���A
                                 *  ���荞�܂ꂽ���̊��荞�݃n���h���֖߂�
                                 */
        clr1 psw,#7
        mov r0,_kernel_intnest
        dec r0
        mov _kernel_intnest,r0
        pop r0
        iret

/*
 *  �l�X�g���Ă��Ȃ����荞�݂̏���
 */
interrupt_from_task:
                                /*
                                 *  �l�X�g�J�E���^���C���N�������g
                                 */
        mov _kernel_intnest,#1
                                /*
                                 *  �X�^�b�N���^�X�N�p�ɐ؂�ւ��A���
                                 *  ���荞�݂�����
                                 */
        mov r1,sp
        mov sp,#__stack
        set1 psw,#7
                                /*
                                 *  r3-r9(caller saved register)��
                                 *  �^�X�N���X�^�b�N�ɑޔ�
                                 */
        mov (r1++),r3
        mov (r1++),r4
        mov (r1++),r5
        mov (r1++),r6
        mov (r1++),r7
        mov r3,r8
        mov (r1++),r3
        mov r3,r9
        mov (r1++),r3
                                /*
                                 *  �^�X�N���X�^�b�N�|�C���^�����荞�ݗp
                                 *  �X�^�b�N�ɑޔ�
                                 */
        push r1
                                /*
                                 *  ���荞�݃n���h���̌Ăяo��
                                 */
        mov r1,(r0)
        bz 1f
        mov r8,#0
        call r8,r1
1:
                                /*
                                 *  ���荞�݂��֎~
                                 */
        clr1 psw,#7

/*
 *  ���荞�݁A��O���ʂ̏o������
 */
ret_int_and_exc:
                                /*
                                 *  �^�X�N�p�X�^�b�N�ɖ߂�
                                 */
        pop r1
        mov sp,r1
                                /*
                                 *  �l�X�g�J�E���^���f�N�������g
                                 */
        mov _kernel_intnest,#0
                                /*
                                 *  reqflg���`�F�b�N���AFALSE�Ȃ�A����
                                 *  �^�X�N�ɖ߂鏈���ɃW�����v
                                 */
        mov r0,#_kernel_reqflg
        mov r1,(r0)
        bz ret_to_task_int

/*
 *  ���荞�ݒ��Ƀ^�X�N�̐؂�ւ��v�������������ꍇ�̏���
 */
                                /*
                                 *  reqflg���N���A
                                 */
        mov r1,#0
        mov (r0),r1
                                /*
                                 *  �f�B�X�p�b�`�֎~���Aruntsk=schedtsk
                                 *  �Ȃ�A���̃^�X�N�ɖ߂鏈����
                                 */
        mov r0,#_kernel_enadsp
        mov r1,(r0)
        bz ret_int_1
        mov r0,#_kernel_runtsk
        mov r1,(r0)
        mov r2,#_kernel_schedtsk
        mov r3,(r2)
        bz r1,r3,ret_int_1
                                /*
                                 *  �^�X�N�̐؂�ւ��̂��߁Ar10-13/sp��ޔ�
                                 */
        push r10
        push r11
        push r12
        push r13
        mov r7,sp
        mov (r1,+TCB_sp),r7             /* r1 points runtsk */
                                /*
                                 *  mode=1(ret_int_r�ɖ߂�)��ݒ肵
                                 *  �f�B�X�p�b�`����
                                 */
        mov r7,#1
        mov (r1,+TCB_mode),r7
        br dispatcher

/*
 *  ���荞�ݒ��̃f�B�X�p�b�`����̕��A����
 */
ret_int_r:

                                /*
                                 *  r10-13�𕜌�
                                 */
        pop r13
        pop r12
        pop r11
        pop r10

/*
 *  ���̃^�X�N�ɖ߂鏈��
 */
ret_int_1:
        mov r0,#_kernel_runtsk
        mov r1,(r0)
                                /*
                                 *  �^�X�N��O�n���h�����̃`�F�b�N
                                 */
        mov.b r7,(r1,+TCB_enatex)
        bn r7,#TCB_enatex_bit,ret_to_task_int
                                /*
                                 *  �^�X�N��O�����̃`�F�b�N
                                 */
        mov r7,(r1,+TCB_texptn)
        bz ret_to_task_int
                                /*
                                 *  �^�X�N��O�n���h���̌Ăяo��
                                 */
        callf _kernel_call_texrtn
                                /*
                                 *  r0-r9�𕜌����A���̃^�X�N�ɖ߂�
                                 */
ret_to_task_int:
        pop r9
        pop r8
        pop r7
        pop r6
        pop r5
        pop r4
        pop r3
        pop r2
        pop r1
        pop r0
        iret

/*
 *  ��O�n���h�������
 */
        .global _kernel_int_irq_ex
_kernel_int_irq_ex:
        push r0
                                /*
                                 *  UART��O�͊��荞�݂Ƃ��ď���
                                 */
        bn __U0CR,#0,1f                 /* UART0 RxRdy */
        bn __U0CR,#1,1f
        mov r0,#_kernel_ih_table+32
        br _int_common
1:
        bn __U0CR,#2,2f                 /* UART0 TxEmpty */
        bn __U0CR,#3,2f
        mov r0,#_kernel_ih_table+32
        br _int_common
2:
        bn __U1CR,#0,3f                 /* UART1 RxRdy */
        bn __U1CR,#1,3f
        mov r0,#_kernel_ih_table+32
        br _int_common
3:
        bn __U1CR,#2,4f                 /* UART1 TxEmpty */
        bn __U1CR,#3,4f
        mov r0,#_kernel_ih_table+32
        br _int_common
4:
                                /*
                                 *  r1,r2��ޔ����Ar2�ɗ�O��������SP��ݒ�
                                 *  (��O�n���h���ւ̈���)
                                 */
        push r1
        push r2
        mov r2,sp
        sub r2,#6
                                /*
                                 *  ����������O�𔻒�/�N���A����
                                 */
        bn __EXCPL,#1,5f                /* undefined instruction */
        set1 psw,#11
        clr1 __EXCPL,#1
        clr1 psw,#11
        mov r0,#_kernel_eh_table+0
        br _exc_common
5:
        bn __EXCPL,#3,6f                /* word access to odd address */
        set1 psw,#11
        clr1 __EXCPL,#3
        clr1 psw,#11
        mov r0,#_kernel_eh_table+2
        br _exc_common
6:
        bn __EXCPL,#5,7f                /* acccess out of mamoey range */
        set1 psw,#11
        clr1 __EXCPL,#5
        clr1 psw,#11
        mov r0,#_kernel_eh_table+4
        br _exc_common
7:
        mov r0,#_kernel_eh_table+6      /* unknown exception */
        br _exc_common

/*
 *  ��O�n���h�����������
 */
_exc_common:
                                /*
                                 *  �l�X�g������O���ǂ����`�F�b�N
                                 *  (��O�́A���̊��荞�݂Ƀl�X�g�����
                                 *  ���Ƃ͖����̂ŁA���荞�݋֎~������
                                 *  �s�v)
                                 */
        mov r1,_kernel_intnest
        bz exception_from_task

/*
 *  �l�X�g������O�̏���
 */
                                /*
                                 *  �l�X�g�J�E���^���C���N�������g
                                 */
        inc r1
        mov _kernel_intnest,r1
                                /*
                                 *  r3-r9(caller saved register)�̑ޔ�
                                 */
        push r3
        push r4
        push r5
        push r6
        push r7
        push r8
        push r9
                                /*
                                 *  ��O�n���h���̌Ăяo��
                                 */
        mov r1,(r0)
        bz 1f
        mov r8,#0
        call r8,r1
1:
                                /*
                                 *  r1-r9�̕���
                                 */
        pop r9
        pop r8
        pop r7
        pop r6
        pop r5
        pop r4
        pop r3
        pop r2
        pop r1
                                /*
                                 *  �l�X�g�J�E���^���f�N�������g���A
                                 *  ���荞�܂ꂽ���̊��荞�݃n���h���֖߂�
                                 */
        mov r0,_kernel_intnest
        dec r0
        mov _kernel_intnest,r0
        pop r0
        iret

/*
 *  �l�X�g���Ă��Ȃ���O�̏���
 */
exception_from_task:
                                /*
                                 *  �l�X�g�J�E���^���C���N�������g
                                 */
        mov _kernel_intnest,#1
                                /*
                                 *  �X�^�b�N���^�X�N�p�ɐ؂�ւ���
                                 */
        mov r1,sp
        mov sp,#__stack
                                /*
                                 *  r3-r9(caller saved register)��
                                 *  �^�X�N���X�^�b�N�ɑޔ�
                                 */
        mov (r1++),r3
        mov (r1++),r4
        mov (r1++),r5
        mov (r1++),r6
        mov (r1++),r7
        mov r3,r8
        mov (r1++),r3
        mov r3,r9
        mov (r1++),r3
                                /*
                                 *  �^�X�N���X�^�b�N�|�C���^�����荞�ݗp
                                 *  �X�^�b�N�ɑޔ�
                                 */
        push r1
                                /*
                                 *  ��O�n���h���̌Ăяo��
                                 */
        mov r1,(r0)
        bz 1f
        mov r8,#0
        call r8,r1
1:
                                /*
                                 *  ���荞�݁E��O���ʏo��������
                                 */
        br ret_int_and_exc

/*
 *  exit_and_dispatch()
 *  ���̃R���e�L�X�g��ۑ������V�����^�X�N�֐؂�ւ���
 *  (�J�[�l���J�n��ŏ��̃^�X�N�̋N�����܂�)
 */
        .global _kernel_exit_and_dispatch
_kernel_exit_and_dispatch:
                                /*
                                 *  �l�X�g�J�E���^���N���A
                                 *  (�J�[�l���J�n���㓙�A�O�Ɏ��s����Ă���
                                 *  �^�X�N�������ꍇ�A��^�X�N�R���e�L�X�g
                                 *  ���s�����������߁A�l�X�g�J�E���^��1��
                                 *  �Ȃ��Ă���B������N���A)
                                 */
        mov _kernel_intnest,#0
                                /*
                                 *  �f�B�X�p�b�`���ŃW�����v
                                 */
        br dispatcher

/*
 *  dispatch()
 *  ���̃R���e�L�X�g��ۑ����V�����^�X�N�֐؂�ւ���
 */
        .global _kernel_dispatch
_kernel_dispatch:
                                /*
                                 *  r10-r14(callee-saved egister)��ۑ�
                                 */
        push r10
        push r11
        push r12
        push r13
        push psw
                                /*
                                 *  SP��runtsk->tskctxb.sp�ɕۑ�
                                 */
        mov r0,#_kernel_runtsk
        mov r1,(r0)
        mov r7,sp
        mov (r1,+TCB_sp),r7
                                /*
                                 *  mode=0(dispatch_r�ɖ߂�)��ݒ肵
                                 *  �f�B�X�p�b�`����
                                 */
        mov r7,#0
        mov (r1,+TCB_mode),r7
        br dispatcher

/*
 *  dispatch()����̖߂菈��
 *  (r3��TCB������)
 */
dispatch_r:
                                /*
                                 *  r10-r14(callee-saved egister)�𕜌�
                                 */
        pop psw
        pop r13
        pop r12
        pop r11
        pop r10
                                /*
                                 *  �^�X�N��O���`�F�b�N���A����&
                                 *  ��O����Ȃ�Ăяo��
                                 */
        mov.b r7,(r3,+TCB_enatex)
        bn r7,#TCB_enatex_bit,1f
        mov r7,(r3,+TCB_texptn)
        bz 1f
        jmpf _kernel_call_texrtn
1:
                                /*
                                 *  dispatch()���Ă񂾃^�X�N�ɖ߂�
                                 */
        ret

/*
 *  create_context()/activate_context()
 *  �V�����^�X�N�̋N������
 *  (r2��TCB������)
 */
        .global _kernel_create_context
_kernel_create_context:
        ret

        .global _kernel_activate_context
_kernel_activate_context:
                                /*
                                 *  �X�^�b�N�|�C���^��������
                                 *  tcb->tskctxb.sp=tcb->tinib->stk
                                 */
        mov r0,(r2,+TCB_tinib)
        mov r1,(r0,+TINIB_stk)
        mov (r2,+TCB_sp),r1
                                /*
                                 *  mode=2(activate_r�ɖ߂�)��ݒ�
                                 */
        mov r1,#2
        mov (r2,+TCB_mode),r1
        ret

/*
 *  activate_context()���ꂽ�^�X�N�̋N������
 *  (r3��TCB������)
 */
activate_r:
                                /*
                                 *  �^�X�N��return�ŏI�������Ƃ��ɁA
                                 *  ext_tsk()���Ă΂��悤�A�����
                                 *  �X�^�b�N�ɐς�
                                 */
        mov r1,#@lo(ext_tsk)
        push r1
        mov r2,#@hi(ext_tsk)
        push r2
                                /*
                                 *  �^�X�N�J�n�A�h���X���X�^�b�N�ɐς�
                                 */
        mov r0,(r3,+TCB_tinib)
        mov r1,(r0,+TINIB_task)
        push r1
        mov r2,#0
        push r2
                                /*
                                 *  PSW�����l���X�^�b�N�ɐς�
                                 */
        mov r1,#0x0080
        push r1
                                /*
                                 *  r2=exinf
                                 */
        mov r2,(r0,+TINIB_exinf)
                                /*
                                 *  �^�X�N�N��
                                 */
        iret

/*
 *  �f�B�X�p�b�`���[
 */
dispatcher:
                                /*
                                 *  runtsk = schedtsk
                                 */
        mov r2,#_kernel_schedtsk
        mov r3,(r2)
        mov r0,#_kernel_runtsk
        mov (r0),r3
                                /*
                                 *  schedtsk = NULL(���s�\�ȃ^�X�N����)
                                 *  �̏ꍇ�A�A�C�h��������
                                 */
        bz dispatcher_1
                                /*
                                 *  SP�𕜌�
                                 */
        mov r7,(r3,+TCB_sp)
        mov sp,r7
                                /*
                                 *  mode�ɂ��������āA
                                 *   =0 : dispatch_r
                                 *   =1 : ret_int_r
                                 *   =2 : activate_r
                                 */
        mov r7,(r3,+TCB_mode)
        bz dispatch_r
        bz r7,#1,ret_int_r
        br activate_r

/*
 *  �A�C�h������(���s�\�^�X�N����)
 */
dispatcher_1:
                                /*
                                 *  �X�^�b�N���^�X�N�p�ɐ؂�ւ���
                                 */
        mov sp,#__stack
                                /*
                                 *  ��^�X�N���������߂�
                                 *  �l�X�g�J�E���^��1���Z�b�g
                                 */
        mov _kernel_intnest,#1
                                /*
                                 *  �^�X�N���s�\�҂��̃��[�v
                                 */
dispatcher_2:
                                /*
                                 *  ���荞�݃��x����0��(IL=0)
                                 */
        mov psw,#0x0000
                                /*
                                 *  �A�C�h�����[�`�����Ăяo��
                                 */
        callf _kernel_idle
                                /*
                                 *  �^�X�N�����s�\�ɂȂ������̃`�F�b�N
                                 *  (reqflg=1?)
                                 */
        mov r0,#_kernel_reqflg
        mov r1,(r0)
        bz dispatcher_2
                                /*
                                 *  reqflg�ƃl�X�g�J�E���^���N���A���A
                                 *  �f�B�X�p�b�`���ɖ߂�
                                 */
        mov r1,#0
        mov (r0),r1
        mov _kernel_intnest,#0
        br dispatcher

/*
 *  �f�t�H���g�̃A�C�h�����[�`��
 */
        .weak _kernel_idle
_kernel_idle:
                                /*
                                 *  ���荞�݂�����
                                 */
        set1 psw,#7
                                /*
                                 *  ���荞�ݑ҂�
                                 */
        halt
                                /*
                                 *  ���荞�݂��֎~
                                 */
        clr1 psw,#7
        ret

        .end
