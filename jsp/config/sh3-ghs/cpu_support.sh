/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *                     2003         by Advanced Data Controls, Corp
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
 *  @(#) $Id: cpu_support.sh,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */


#define _MACRO_ONLY
#include "jsp_kernel.h"
#include "offset.h"
#include <t_config.h>
 			

/*GHS �A�Z���u���[�����ߕϊ�*/
#define	long	data.l
#define	org	offset

/*GHS ROM���j�^���荞�݃G���g���[�A�h���X*/
#ifdef 	GHS_STUB
#define	_CpuExceptionHandler	0xa0000848
#endif


/*
 *  ��O/���荞�ݏo������������[�`��
 *  SH3�̓x�N�^�e�[�u�����������A��O,TRAPA�����������VBR+0x100�Ԓn���A
 *  ����/�O��/NMI���荞�݂���������ƁAVBR+0x600�Ԓn�����s����B
 */
        
/*
 *	VBR �ɐݒ肷��l
 */
    .section .text
    .align 2        
    .global _BASE_VBR
_BASE_VBR:
     bra _start
     nop
     nop
     nop

/*
 *  Exception 100 vector
 *  �A�h���X�G���[,�X���b�g�s�����ߗ�O�ATrapa��O������������Ǝ��s�����B
 *
 *  CPU��O�n���h���́A��^�X�N�R���e�L�X�g�Ŏ��s����A���̂��߁ACPU��O�n��
 *  �h�����Ăяo���O�ɗ�O/���荞�݂��������W�X�^�o���N1�� r7 ���W�X�^���C��
 *  �N�����g���A���^�[�����Ă�����Ƀf�N�������g����BCPU��O���^�X�N�R���e�L
 *  �X�g�Ŕ������Aregflg �� TRUE �ɂȂ������ɁA ret_exc �֕��򂷂�B
 *  regflg ���`�F�b�N����O�Ɋ��荞�݂��֎~���Ȃ��ƁAreqflg ���`�F�b�N��ɋN
 *  �����ꂽ���荞�݃n���h�����Ńf�B�X�p�b�`���v�����ꂽ�ꍇ�ɁA�f�B�X�p�b�`
 *  ����Ȃ��B
 *
 *		
 *  ��O����������ƁA��O�������̃R���e�L�X�g�ł���spc,pr,ssr,r0�`r7��ޔ�
 *  ����B��O�������������_�ł̃R���e�L�X�g�𒲂ה�^�X�N�R���e�L�X�g�Ȃ�
 *  _exception_from_int������s���J�n����B��O�̗v����EXPEVT���W�X�^�ǂ݁A
 *  exc_table����CPU��O�n���h���̊J�n�Ԓn��ǂݍ��ށB����������O�ɑ΂���
 *  CPU��O�n���h�����o�^����Ă��Ȃ���΁A_no_reg_exception�Ƀu�����`���āA
 *  ssr,sr,spc,pr�̓��e���o�͂��Ē�~����BCPU��O�n���h�����烊�^�[������
 *  ������Areqflg�𒲂�0�ȊO�Ȃ�rec_exc()�ɔ�сA0�Ȃ猳�̏����Ƀ��^�[����
 *  ��B
 *
 *
 *  BL�r�b�g�̈����ɂ���
 *  ssr,spc �ɖ߂��̃R���e�L�X�g��߂��� rte �𔭍s����ۂɂ́C�����݁iNMI 
 *  ���܂ށj���󂯕t���Ȃ��悤�� BL �r�b�g��1�ɂ���K�v������D��O/�����݃n
 *  ���h���I�����ɂ� BL ���r�b�g��1�ɂ��� IPM �� MAX_IPM �ɐݒ肷��D����́C
 *  BL �r�b�g��1�̏ꍇ�ɗ�O����������� CPU �����Z�b�g����邱�Ƃ��l�����āC
 *  ���S�̂��߁Cssr,spc�𕜋A���钼�O��BL��1�ɐݒ肵�Ă���D
 *       
 */	
			

    .org   0x0100              /*  _BASE_VBR + 0x0100�Ԓn�ɔz�u   */
    .align 2
    .global _general_exception
_general_exception:
#ifdef GHS_STUB /* GHS */
	mov.l	r0,@-r15
	mov.l	r1,@-r15
	mov.l   _expevt,r0
	mov.l   @r0,r1     
	shlr2   r1           
	shlr    r1
	mov.l   _exc_table_exc,r0
	mov.l   @(r0,r1),r0        
	tst     r0,r0
	mov.l	@r15+,r1	
	mov.l	@r15+,r0
	bt      _rom_exception   /* _rom_exception�փW�����v             */
#endif
 /* spc,pr,ssr ���X�^�b�N�ɕۑ����� */
    stc.l  spc,@-r15          
    sts.l  pr,@-r15               
    stc.l  ssr,@-r15
    stc.l  gbr,@-r15					
    sts.l  macl,@-r15					
    sts.l  mach,@-r15
    stc.l  r0_bank,@-r15 /* ��O��������r0�`r7��ۑ�        */    
    stc.l  r1_bank,@-r15
    stc.l  r2_bank,@-r15
    stc.l  r3_bank,@-r15
    stc.l  r4_bank,@-r15
    stc.l  r5_bank,@-r15
    stc.l  r6_bank,@-r15    
    stc.l  r7_bank,@-r15
    tst    r7,r7               /* ��O�������̃R���e�L�X�g�𔻒�            */
    bf/s   _exception_from_exc /* ����������O/���荞�݃n���h���Ȃ�W�����v */
     add    #0x01,r7	       /* ��O/���荞�݃l�X�g�񐔂��C���N�������g   */
    mov    r15,r1              /* �߂�悪���荞�݃n���h���łȂ��̂ŃX�^�b  */
    mov.l  _stacktop_exc,r15   /* �N�����ւ����̃X�^�b�N�|�C���^��ۑ�    */ 
    mov.l r1,@-r15            
#ifdef GHS_HOOK
	mov.l   r1,@-r15
	mov.l   r7,@-r15
	stc     spc,r0
	mov.l   r0,r5
	mov.l   _expevt,r0        /* ���荞�݋�����Ə����郌�W�X�^��ۑ�    */
	mov.l   _exception_hook_dis,r2
	jsr     @r2
	mov.l   @r0,r4            /* EXPEVT���W�X�^���擾		              */
	mov.l   @r15+,r7
	mov.l   @r15+,r1
#endif

    mov.l  _expevt,r0          /* ��O��������Ə����郌�W�X�^��ۑ�      */
    mov.l  @r0,r5              /* EXPEVT���W�X�^���擾                      */
    ldc    r1,r4_bank          /* CPU��O�n���h���ւ̈���                   */
    ldc    r5,r5_bank	     
    mov.l  _unmak_rb_bl_exc,r2 /* BL�r�b�g��0�ɁC���W�X�^�o���N��؂�ւ�   */
    stc    sr,r3               
    and    r3,r2			
    ldc    r2,sr               
    shlr2  r5                  /* EXPEVT��3�r�b�g�E�V�t�g                   */
    shlr   r5                
    mov.l  _exc_table_exc,r0   /* exc_table�̃A�h���X��r0��                 */
    mov.l  @(r0,r5),r2         /* �n���h���̃A�h���X���擾                  */
    tst    r2,r2               /* �n���h�����o�^����Ă��Ȃ���O�Ȃ�        */
    bt     _no_reg_exception   /* no_reg_exception�փW�����v                */
    jsr    @r2                 /* CPU��O�n���h����                         */
     nop
    mov.l  _mask_md_ipm_exc,r0
    ldc    r0,sr               /* ���荞�݋֎~                              */
    stc    r7_bank,r7          /* ��O/���荞�݂̃l�X�g�񐔂��f�N�������g   */
    dt     r7
    ldc    r7,r7_bank
    mov.l  _reqflg_exc,r2      /* reqflg�̃`�F�b�N                          */
    mov.l  @r2,r1
    tst    r1,r1               /* reqflg��FALSE�Ȃ�ret_to_task_exc�ɔ��    */
    bt/s   _ret_to_task_exc    /* �^�X�N�ɖ߂�                              */
     mov.l  @r15,r15           /* �߂�悪�^�X�N�Ȃ̂ŃX�^�b�N��߂�        */
    xor    r0,r0               
    bra    ret_exc
     mov.l  r0,@r2             /* reqflg���N���A                            */


/*
 *   exception_from_int
 *   CPU��O�������̃R���e�L�X�g����^�X�N�R���e�L�X�g�̏ꍇ�̏���
 *   �^�X�N�R���e�L�X�g�̏ꍇ�Ƃ̏����̈Ⴂ�́A��CPU��O�n���h����
 *   �������I������ƕK�����̏����ɖ߂邱�Ƃł���B
 */
	
_exception_from_exc:
#ifdef GHS_HOOK
	mov.l   r7,@-r15
	stc     spc,r0
	mov.l   r0,r5
	mov.l   _expevt,r0       /* ���荞�݋�����Ə����郌�W�X�^��ۑ�    */
	mov.l   _exception_hook_dis,r2
	jsr     @r2
	mov.l   @r0,r4           /* EXPEVT���W�X�^���擾                      */
	mov.l   @r15+,r7
	
#endif
    mov.l   _expevt,r0        /* ��O��������Ə����郌�W�X�^��ۑ�      */
    mov.l   @r0,r5            /* EXPEVT���W�X�^���擾                      */
    ldc     r15,r4_bank       /* CPU��O�n���h���ւ̈���                   */
    ldc     r5,r5_bank	     
    mov.l   _unmak_rb_bl_exc,r2 /* BL�r�b�g��0�ɁC���W�X�^�o���N��؂�ւ� */
    stc     sr,r3
    and     r3,r2			
    ldc     r2,sr               
    shlr2   r5                /* EXPECT��3�r�b�g�E�V�t�g                   */
    shlr    r5                	
    mov.l   _exc_table_exc,r0 /* exc_table�̃A�h���X��r0��                 */
    mov.l   @(r0,r5),r2       /* �n���h���̃A�h���X���擾                  */
    tst     r2,r2             /* �n���h�����o�^����Ă��Ȃ���O�Ȃ�        */
    bt      _no_reg_exception /* no_reg_exception�փW�����v                */
    jsr     @r2               /* CPU��O�n���h����                         */
     nop
    mov.l  _mask_md_ipm_exc,r0
    ldc    r0,sr              /* BL=1,���荞�݋֎~                         */
    stc    r7_bank,r7         /* ��O/���荞�݂̃l�X�g�񐔂��f�N�������g   */
    dt     r7
    ldc    r7,r7_bank
_ret_to_task_exc:
    mov.l  @r15+,r7           /* r0�`r1,ssr,pr,spc�𕜋A���^�X�N�ɖ߂�     */
    mov.l  @r15+,r6
    mov.l  @r15+,r5
    mov.l  @r15+,r4
    mov.l  @r15+,r3
    mov.l  @r15+,r2
    mov.l  @r15+,r1        
    mov.l  _mask_md_bl_exc,r0 
    ldc    r0,sr             /* BL��1��                                   */
    mov.l  @r15+,r0
    lds.l  @r15+,mach                
    lds.l  @r15+,macl        
    ldc.l  @r15+,gbr               
    ldc.l  @r15+,ssr            
    lds.l  @r15+,pr
    ldc.l  @r15+,spc
    rte
     nop

#ifdef GHS_STUB /* GHS */
_rom_exception:
	stc.l	ssr,@-r15
	stc.l	spc,@-r15
	mov.l	r0,@-r15
	mov.l	r1,@-r15
	mov.l	L._CpuException1,r1
	jmp	@r1
	mov	#1,r0

	.align	4
L._CpuException1:
	.data.l	_CpuExceptionHandler
#endif

/*	
 *  no_reg_exception()
 *  CPU��O�Ƃ��ēo�^����Ă��Ȃ���O����������ƌĂяo�����
 *  ��O�R�[�h�A��O�������������_��pc,sr,pr���o�͂��ăJ�[�l��
 *  ���~����B
 */					
_no_reg_exception:
    mov.l  _expevt,r5
    mov.l  @r5,r4
    stc    spc,r5
    stc    ssr,r6
    sts    pr,r7
    mov.l  _cpu_expevt_k,r1
    jsr    @r1
     nop

	.align  4
_stacktop_exc:
    .long  STACKTOP            /* �^�X�N�Ɨ����̃X�^�b�N�̏����l  */
_expevt:	
    .long  EXPEVT
_exc_table_exc:	
    .long  _exc_table
_unmak_rb_bl_exc:		
    .long  0x4fffffff
_mask_md_ipm_exc:	
    .long  0x40000000 + MAX_IPM << 4	
_reqflg_exc:
    .long  _reqflg
_cpu_expevt_k:	
    .long  _cpu_expevt	
_mask_md_bl_exc:	
    .long  0x50000000 + MAX_IPM << 4	

#ifdef GHS_HOOK
	.global _exception_hook
_exception_hook_dis:
	.long   _exception_hook
#endif


	
/*
 *  �^�X�N�f�B�X�p�b�`��
 *
 *  _dispatch �́Ar7_bank1 = 0,�����݋֎~��ԂŌĂяo���Ȃ���΂Ȃ��
 *  ���D_exit_and_dispatch ���Cr7_bank1 = 0�E�����݋֎~��ԂŌĂяo��
 *  �̂������ł��邪�C�J�[�l���N�����ɑΉ����邽�߁Cr7_bank1 = 1�ŌĂ�
 *  �o�����ꍇ�ɂ��Ή����Ă���D
 */

    .text
    .align 2
    .global _dispatch
_dispatch:
    sts.l  pr,@-r15         /* pr,r8�`r15 ���X�^�b�N�ɕۑ�           */
    mov.l  r14,@-r15        /* r0�`r7�͌Ăяo�����ŕۑ����Ă��邽��  */    
    mov.l  r13,@-r15        /* �ۑ�����K�v������                    */    
    mov.l  r12,@-r15
    mov.l  r11,@-r15
    mov.l  r10,@-r15
    mov.l  r9, @-r15
    mov.l  r8, @-r15
    mov.l  _runtsk_dis,r2   /* r0 <- runtsk                          */
    mov.l  @r2,r0
    mov.l  r15,@(TCB_sp,r0) /* �^�X�N�X�^�b�N��TCB�ɕۑ� 60�ȉ��Ȃ�OK*/		
    mov.l  dispatch_r_k,r1  /* ���s�ĊJ�Ԓn��ۑ�                    */
    mov.l  r1,@(TCB_pc,r0)  /* ���s�ĊJ�Ԓn��TCB�ɕۑ�  60�ȉ��Ȃ�OK */
    bra    dispatcher
     nop

dispatch_r:	
    mov.l  @r15+,r8         /* ���W�X�^�𕜋A                       */
    mov.l  @r15+,r9
    mov.l  @r15+,r10
    mov.l  @r15+,r11
    mov.l  @r15+,r12
    mov.l  @r15+,r13
    mov.l  @r15+,r14
    lds.l  @r15+,pr
    /*
     *  �^�X�N��O�������[�`���̋N��
     *  dispatch_r��dispatcher����Ăяo����邽�߁C
     *  tcb�̃A�h���X��r0�ɓ����Ă���D      
     */
    mov.l  @(TCB_enatex,r0),r1
    mov.l  _enatex_mask_dis,r2
    tst    r1,r2
    bt     dispatch_r_1         /* enatex �� FALSE �Ȃ烊�^�[�� */
    mov.l  @(TCB_texptn,r0),r1  /* texptn�����[�h               */
    tst    r1,r1
    bt     dispatch_r_1         /* texptn �� 0�Ŗ������        */
    mov.l  _call_texrtn_dis,r1  /* �^�X�N��O���[�`���̌Ăяo�� */
    jmp    @r1        
     nop                          
dispatch_r_1:   
    rts
     nop                

    .global _exit_and_dispatch
_exit_and_dispatch:
    xor    r1,r1                 /* r7_bank1��0�N���A             */
    ldc    r1,r7_bank
dispatcher:
    /*
     * �����ɂ͊��荞�݋֎~�ŗ��邱��
     */
    mov.l  _schedtsk_dis,r12    /* r0 <- schedtsk                   */
    mov.l  @r12,r0             
    cmp/eq #0,r0                /* schedtsk �����邩�H              */
    bt     dispatcher_1         /* ������΃W�����v                 */
#ifdef GHS_HOOK 
	mov.l   _dispatch_hook_dis,r2
	jsr     @r2
	mov     r0,r4
	mov.l   @r12,r0
#endif

    mov.l  _runtsk_dis,r2
    mov.l  r0,@r2               /* schedtsk��runtsk��               */
    mov.l  @(TCB_sp,r0),r15     /* TCB����^�X�N�X�^�b�N�𕜋A      */
    mov.l  @(TCB_pc,r0),r1      /* TCB������s�ĊJ�Ԓn�𕜋A        */
    jmp    @r1 
     nop
dispatcher_1:
    /* �C�~�f�B�G�C�g�l�𖈉�ǂݍ��ނ̂͌����������̂Ŏ��O�ɗp�ӂ���
     * r8  : ���荞�݋֎~�̂��߂�SR�̒l   
     * r9  : ���荞�ݑ҂�����SR�̒l
     * r10 : reqflg�̔Ԓn
     * r11 : 0x01
     * r12 : 0x00
     * r13 : sleep����SR�̏��       
     */
    mov.l  _mask_md_ipm_dis,r8  /* ���荞�݋֎~��SR�̒l             */
#ifdef NO_SLEEP
    mov.l  _mask_md_dis,r9      /* ���荞�ݑ҂�����SR�̒l           */        
#else
    mov.l  _mask_bl_md_dis,r9   /* ���荞�ݑ҂�����SR�̒l           */
#endif                          
#ifdef SUPPORT_CHG_IPM
    mov.l  _task_intmask_k,r2
    mov.l  @r2,r3
    or     r3,r9
#endif
    mov.l  _reqflg_dis,r10
    mov    #0x01,r11
    xor    r12,r12
    mov.l  _stacktop_dis,r15   /* �X�^�b�N�����荞�݃X�^�b�N��     */
    ldc    r11,r7_bank         /* r7_bank1 ��1�ɂ��Ċ��荞�ݏ�Ԃ� */        
dispatcher_2:        
    /*
     *  �����Ŋ����݃��[�h�ɐ؂芷����̂́C�����Ŕ������銄���ݏ���
     *  �ɂǂ̃X�^�b�N���g�����Ƃ������̉����ƁC�����݃n���h������
     *  �̃^�X�N�f�B�X�p�b�`�̖h�~�Ƃ�����̈Ӗ�������D
     */
     /*
      *  �����݋����sleep���߂����s����ƁC�����݋����߂̎��s�O��
      *  �����ݗv���������Ă���ꍇ�C�����݋����߂̎��s�Ƌ��Ɋ����݂�
      *  �󂯕t����ꂻ�̕��A��ɁCreqflg�̃`�F�b�N�ł͂Ȃ� sleep ���
      *  �ɓ����Ă��܂��D
      *  ���̖��́C�����݂̋��� sleep ��Ԃւ̈ڍs���A�g�~�b�N�Ɏ�
      *  �s�ł��Ȃ����ƂɋN������D
      *  ���̂��߁Csleep ���s���O�� SR �ύX�ł� BL �r�b�g��'1'�ɐݒ肷
      *  �邱�ƂŁC�����݂̋��� sleep ��Ԃւ̈ȍ~���A�g�~�b�N�Ɏ��s
      *  ����D
      *  ldc r9,sr �ł�BL�r�b�g���Z�b�g����邽�߁C�����݂͎󂯕t�����X
      *  ���[�v���[�h�Ɉڍs����D�X���[�v���[�h���́CBL�r�b�g��1�ł���
      *  ���݂��󂯕t���邽��(SH7709�n�[�h�E�F�A�}�j���A�� 8-10)�C�X���[
      *  �v���[�h�ւ̈ڍs����Ɋ����݂���t�X���[�v���[�h���畜�A����D
      */
               
    ldc    r9,sr               /* ���荞�݂̋���                   */
#ifndef NO_SLEEP
    sleep                      /* �����ݑ҂�                       */
#endif /* NO_SLEEP */                
    ldc    r8,sr               /* ���荞�݋֎~                     */  
    mov.l  @r10,r7             /* r7 <- reqflg                     */
    tst    r7,r7               /* reqflg �� FALSE�Ȃ�              */
    bt     dispatcher_2        /* dispatcher_2 ��                  */
    ldc    r12,r7_bank         /* r7_bank1 ���N���A                */        
    mov.l  r12,@r10            /* reqflg �� FALSE��                */
    bra    dispatcher
     nop	
    .align 4
_runtsk_dis:	
    .long _runtsk
_schedtsk_dis:	
    .long _schedtsk
_enatex_mask_dis:    
    .long TCB_enatex_mask
_call_texrtn_dis:	
    .long _call_texrtn
_mask_md_ipm_dis:	
    .long 0x40000000 + MAX_IPM << 4
_mask_md_dis:	
    .long 0x40000000
_mask_bl_md_dis:	
    .long 0x50000000	        
dispatch_r_k:	
    .long dispatch_r
_stacktop_dis:
    .long STACKTOP           /* �^�X�N�Ɨ����̃X�^�b�N�̏����l	*/
_reqflg_dis:
    .long  _reqflg
#ifdef GHS_HOOK
	.global _dispatch_hook
_dispatch_hook_dis:
	.long   _dispatch_hook
#endif


/* 
 *  ���荞�݃n���h��/CPU��O�n���h���o������
 *
 * �߂�悪�^�X�N��reqflg���Z�b�g����Ă���ꍇ�݂̂����ɂ���B
 * r7_bank1 = 0,���荞�݋֎~���,�X�N���b�`���W�X�^��ۑ�����
 * ��ԂŌĂяo�����ƁB 
 *	
 */
    .text
    .align 2
    .globl ret_int
    .globl ret_exc
ret_exc:
ret_int:
    mov.l  _runtsk_ret,r1     /* r0 <- runtsk                  */
    mov.l  @r1,r0           
    mov.l  _enadsp_ret,r2     /* enadsp�̃`�F�b�N              */
    mov.l  @r2,r3
    tst    r3,r3           
    bt     ret_int_1           
    mov.l  _schedtsk_ret,r4   /* r5 <- schedtsk                */ 
    mov.l  @r4,r5
    cmp/eq r0,r5              /* runtsk �� schedtsk ���r     */
    bt     ret_int_1
    mov.l  r14,@-r15          /* �c��̃��W�X�^��ۑ�          */
    mov.l  r13,@-r15					
    mov.l  r12,@-r15					
    mov.l  r11,@-r15					
    mov.l  r10,@-r15					
    mov.l  r9,@-r15					
    mov.l  r8,@-r15
    mov    #TCB_sp,r1        /* �^�X�N�X�^�b�N��ۑ�           */
    mov.l  r15,@(r0,r1)    
    mov.l  ret_int_r_k,r1    /* ���s�ĊJ�Ԓn��ۑ�             */
    mov    #TCB_pc,r2	
    mov.l  r1,@(r0,r2)  
    bra    dispatcher
     nop
    
ret_int_r:
    mov.l  @r15+,r8		
    mov.l  @r15+,r9		
    mov.l  @r15+,r10		
    mov.l  @r15+,r11		
    mov.l  @r15+,r12		
    mov.l  @r15+,r13		
    mov.l  @r15+,r14		
ret_int_1:
    /*
     *  �^�X�N��O�������[�`���̋N��
     *  ret_int_r �� dispatcher ����Ăяo����邽�߁Ctcb�̃A�h���X��r0��
     *  �����Ă���D
     *  �Ȃ��C�����݂̏o���Ń^�X�N�X�C�b�`���������Ȃ��ꍇ�̓f�B�X�p�b�`��
     *  ��ʂ炸�� ret_int ���璼�� ret_int_1 �ɔ��       
     */
    mov.l  @(TCB_enatex,r0),r1
    mov.l  _enatex_mask_ret,r2
    tst    r1,r2
    bt     ret_int_2            /* enatex �� FALSE �Ȃ烊�^�[��  */
    mov.l  @(TCB_texptn,r0),r1  /* texptn�����[�h                */
    tst    r1,r1
    bt     ret_int_2            /* texptn �� 0�Ŗ������T<= 0    */
    mov.l _call_texrtn_ret,r1   /* �^�X�N��O���[�`���̌Ăяo��  */
    jsr   @r1        
     nop       
ret_int_2:               
#ifdef SUPPORT_CHG_IPM
    mov    #32,r0
    mov.l  @(r0,r15),r1
    mov.l  _unmask_ipm,r2
    and    r2,r1
    mov.l  _task_intmask_k,r2
    mov.l  @r2,r3
    or     r3,r1
    mov.l  r1,@(r0,r15)
#endif /* SUPPORT_CHG_IMP */
    mov.l  @r15+,r7            /* spc,pr,ssr,�X�N���b�`���W�X�^�𕜋A */
    mov.l  @r15+,r6        
    mov.l  @r15+,r5
    mov.l  @r15+,r4
    mov.l  @r15+,r3
    mov.l  @r15+,r2
    mov.l  @r15+,r1
    mov.l  _mask_md_bl_ret,r0
    ldc    r0,sr               /* BL��1��                               */
    mov.l  @r15+,r0
    lds.l  @r15+,mach                
    lds.l  @r15+,macl        
    ldc.l  @r15+,gbr       
    ldc.l  @r15+,ssr    
    lds.l  @r15+,pr
    ldc.l  @r15+,spc
    rte
     nop
        
    .align 4
_runtsk_ret:
    .long _runtsk
_schedtsk_ret:	
    .long _schedtsk
_enadsp_ret:	
    .long _enadsp
ret_int_r_k:
    .long ret_int_r
_enatex_mask_ret:    
    .long TCB_enatex_mask        
_call_texrtn_ret:	
    .long _call_texrtn
_mask_md_bl_ret:	
    .long  0x50000000

/*
 *  �^�X�N�N������
 */ 
    .text
    .align 2
    .globl _activate_r
_activate_r:
    stc    sr,r0               /* ���荞�݋��� */
    mov.l  _unmask_ipm,r1
    and    r1,r0	
#ifdef SUPPORT_CHG_IPM
    mov.l  _task_intmask_k,r1
    mov.l  @r1,r2
    or     r2,r0
#endif /* SUPPORT_CHG_IPM */
    ldc    r0,sr
    mov.l  @r15+,r1
    lds.l  @r15+,pr
    mov.l  @r15+,r4
    jmp    @r1
     nop
    .align 4
_unmask_ipm:
    .long  0xffffff0f
#ifdef SUPPORT_CHG_IPM		
_task_intmask_k:
    .long _task_intmask
#endif /* SUPPORT_CHG_IPM */
		
		
/*
 *  Exception 600 vector
 *  ���荞�݂���������Ǝ��s�����B		
 *
 *
 *  SH3�͊��荞�݂���������Ƃ��ׂ�VBR+0x600�Ԓn����v���O���������s���邽�߁A
 *  �����ɔz�u���郋�[�`���ł܂��X�^�b�N�̐؂�ւ��A���W�X�^�̕ۑ�,IPM�̐ݒ�,
 *  ���荞�ݗv���̔�����s�����̌�BL�r�b�g��0�ɂ��Ċ��荞�݃n���h�����ĂԕK�v
 *  ������B
 *  ���荞�ݗv���ɑΉ��������荞�݃n���h���̊J�n�Ԓn�͔z��int_table[]�ɓo�^��
 *  �ČĂяo���B�I�t�Z�b�g�̌v�Z�́A���荞�ݗv�����W�X�^���E��2�r�b�g�V�t�g��
 *  �čs���B���荞�ݗv�����W�X�^��SH7708�ł�INTEVT���W�X�^�ɃZ�b�g����邪�A
 *  SH7709�����SH7709A�ł�INTEVT2�ɃZ�b�g����邽�߁Aifdef�ɂ��؂蕪���Ă�
 *  ��B�܂��A�ꕔ�̃f�B�o�C�X�ɂ��Ċ��荞�ݗv�����W�X�^�œn�����l��IPM��
 *  �̊Ԃɂ͊֌W���Ȃ����߁A�e���荞�ݗv���ɑΉ�����IPM������SR�̓��e��z��
 *  int_plevel_table[]�ɓo�^���Ă����ǂݏo���B
 *
 *  reqflg ���`�F�b�N����O�Ɋ����݂��֎~���Ȃ��ƁCreqflg ���`�F�b�N��
 *  �ɋN�����ꂽ�����݃n���h�����Ńf�B�X�p�b�`���v�����ꂽ�ꍇ�ɁC�f�B
 *  �X�p�b�`����Ȃ��D
 *
 */

    .org    0x0600        /* _BASE_VBR + 0x0600�Ԓn�ɔz�u */
    .align 2
    .global _interrupt
_interrupt:    
#ifdef GHS_STUB
	mov.l	r0,@-r15
	mov.l	r1,@-r15
	mov.l   _intevt,r0 
	mov.l   @r0,r1     
	shlr2   r1           
	shlr    r1
/*	mov.l   _int_table_k,r0
	mov.l   @(r0,r1),r0
*/	
	mov.l	@r15+,r1
	mov.l	@r15+,r0
	bt      _rom_interrupt   
#endif
    stc.l  spc,@-r15       /* ���d���荞�݂�����Ə����Ă��܂��̂�        */
    sts.l  pr,@-r15        /* spc,pr,ssr,gbr,macl,mach                    */
    stc.l  ssr,@-r15    
    stc.l  gbr,@-r15                    
    sts.l  macl,@-r15                    
    sts.l  mach,@-r15                                                    
    stc.l  r0_bank,@-r15   /* ,r0�`r7���X�^�b�N�ɕۑ�   */ 
    stc.l  r1_bank,@-r15
    stc.l  r2_bank,@-r15
    stc.l  r3_bank,@-r15
    stc.l  r4_bank,@-r15
    stc.l  r5_bank,@-r15
    stc.l  r6_bank,@-r15    
    stc.l  r7_bank,@-r15
    tst    r7,r7                 /* ���荞�ݔ������̃R���e�L�X�g�𔻒�  */  
    bf/s    _interrupt_from_int  /* ��O/���荞�݃n���h���Ȃ�W�����v   */
     add    #0x01,r7             /* ���荞�݂̃l�X�g�񐔂��C���N�������g*/
    mov    r15,r1                /* �X�^�b�N�����ւ����̃X�^�b�N�|�C  */
    mov.l  _stacktop_k,r15       /* ���^��ۑ�                          */
    mov.l  r1,@-r15            
#ifdef GHS_HOOK
	mov.l   r7,@-r15
	stc     spc,r0
	mov.l   r0,r5
	mov.l   _intevt,r0          /* ��O�v�����W�X�^���擾              */
	mov.l   _interrupt_hook_dis,r2
	jsr     @r2
	mov.l   @r0,r4              
	mov.l   @r15+,r7
#endif
    mov.l  _intevt,r0            /* ��O�v�����W�X�^���擾              */
    mov.l  @r0,r4              
    shlr2  r4                    /* 3�r�b�g�E�V�t�g���I�t�Z�b�g�����߂� */
    shlr   r4                  
    mov.l  _int_plevel_table_k,r0 
    mov.l  @(r0,r4),r5           /* ���荞�݂̗D��x���擾               */
    mov.l  _int_table_k,r0    
    mov.l  @(r0,r4),r2           /* ���荞�݃n���h���̃A�h���X���擾    */
    ldc    r2,r2_bank            /* �o���N0�ɐ؂�ւ��邽�߃R�s�[       */    
    ldc    r5,sr                 /* ����ȍ~���荞�݂��󂯕t����B      */
    jsr    @r2                   /* ���荞�݃n���h����                  */
     nop
    mov.l  _mask_md_ipm_ret,r0
    ldc    r0,sr                 /* ���荞�݋֎~                           */
    stc    r7_bank,r7            /* ��O/���荞�݂̃l�X�g�񐔂��f�N�������g*/
    dt     r7
    ldc    r7,r7_bank
    mov.l  _reqflg_k,r4          /* reqflg�̃`�F�b�N                       */
    mov.l  @r4,r1
    tst    r1,r1                 /* reqflg��FALSE�Ȃ�ret_to_task_int�ɔ�� */
    bt/s   _ret_to_task_int      /* �^�X�N�ɖ߂�                           */
     mov.l  @r15,r15             /* �߂�悪�^�X�N�Ȃ̂ŃX�^�b�N��߂�     */
    xor    r0,r0
    bra    ret_int
     mov.l  r0,@r4               /* reqflg���N���A                   */
_interrupt_from_int:
#ifdef GHS_HOOK
	mov.l   r7,@-r15
	stc     spc,r0
	mov.l   r0,r5
	mov.l   _intevt,r0             /* ��O�v��INTEVT2���W�X�^���擾    */
	mov.l   _interrupt_hook_dis,r2
	jsr     @r2
	mov.l   @r0,r4
	mov.l   @r15+,r7
#endif
    mov.l   _intevt,r0           /* ��O�v�����W�X�^���擾           */
    mov.l   @r0,r4
    shlr2   r4                   /* �I�t�Z�b�g�����߂�               */
    shlr    r4                   /* �I�t�Z�b�g�����߂�               */    
    mov.l   _int_plevel_table_k,r0 
    mov.l   @(r0,r4),r5            /* ���荞�݂̗D��x���擾           */
    mov.l   _int_table_k,r0        
    mov.l   @(r0,r4),r2            /* ���荞�݃n���h���̃A�h���X���擾 */
    ldc     r2,r2_bank             /* �o���N0�ɐ؂�ւ��邽�߃R�s�[    */
    ldc     r5,sr                  /* ����ȍ~���荞�݂��󂯕t����B   */
    jsr     @r2                    /* ���荞�݃n���h����               */ 
     nop
    mov.l  _mask_md_ipm_ret,r0
    ldc    r0,sr                   /* ���荞�݋֎~                     */
    stc    r7_bank,r7              /* ��O/���荞�݂̃l�X�g�񐔂��f�N�������g*/
    dt     r7
    ldc    r7,r7_bank
_ret_to_task_int:
    mov.l  @r15+,r7                /* ���荞�݌��ɖ߂�                 */
    mov.l  @r15+,r6
    mov.l  @r15+,r5
    mov.l  @r15+,r4
    mov.l  @r15+,r3
    mov.l  @r15+,r2
    mov.l  @r15+,r1
    mov.l  _mask_md_bl_int,r0 
    ldc    r0,sr                   /* BL ��1��                         */
    mov.l  @r15+,r0
    lds.l  @r15+,mach                
    lds.l  @r15+,macl        
    ldc.l  @r15+,gbr                       
    ldc.l  @r15+,ssr
    lds.l  @r15+,pr
    ldc.l  @r15+,spc
    rte
     nop
#ifdef GHS_STUB
_rom_interrupt:
	stc.l	ssr,@-r15
	stc.l	spc,@-r15
	mov.l	r0,@-r15
	mov.l	r1,@-r15
	mov.l	L._CpuException6,r1
	jmp	@r1
	mov	#6,r0

	.align	4
L._CpuException6:
	.data.l	_CpuExceptionHandler
#endif
    /*
     * ���o�^�̊����݂���������ƁC���̎��� INTEVT,INTEVT2,SR,PC ��
     * ������cpu_interrupt()���Ăяo���D
     */   
    .global _no_reg_interrupt
_no_reg_interrupt:
    mov.l _intevt1,r0
    mov.l @r0,r4
#if defined(SH7709) || defined(SH7709A) || defined(SH7729R) || defined(SH7727) 
    mov.l _intevt2,r0    
    mov.l @r0,r5
#endif 
    stc   spc,r6
    stc   ssr,r7
    mov.l _cpu_interrupt_k,r1
    jsr   @r1
     nop
    .align  4
_stacktop_k:
    .long  STACKTOP            /* ��^�X�N�Ɨ����̃X�^�b�N�̏����l  */
_intevt:        
#if defined(SH7708) || defined(SH7750)    
    .long  INTEVT
#else
    .long  INTEVT2
#endif    
_int_table_k:    
    .long    _int_table       
_int_plevel_table_k:    
    .long    _int_plevel_table 
_reqflg_k:
    .long  _reqflg
_mask_md_ipm_ret:    
    .long  0x40000000 + MAX_IPM << 4
_mask_md_bl_int:    
    .long  0x50000000
_intevt1:        
    .long  INTEVT
#if defined(SH7709) || defined(SH7709A) || defined(SH7729R) || defined(SH7727) 
_intevt2:        
    .long  INTEVT2
#endif 
_cpu_interrupt_k:
    .long  _cpu_interrupt   
#ifdef GHS_HOOK
_interrupt_hook_dis:
	.long   _exception_hook
#endif

   
/*
 *  �������ԑ҂�
 */
	.globl _sil_dly_nse
_sil_dly_nse:
    mov.l  _sil_dly_tim1, r1
    add    r1, r4
    cmp/pl r4
    bt     _sil_dly_nse1
    rts
     nop
_sil_dly_nse1:            
    mov.l  _sil_dly_tim2, r1
    add    r1, r4
    cmp/pl r4
    bt     _sil_dly_nse1
    rts
     nop   
    .align 4
_sil_dly_tim1:
    .long  -SIL_DLY_TIM1    
_sil_dly_tim2:                         
    .long  -SIL_DLY_TIM2
