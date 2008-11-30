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
 *  @(#) $Id: start.S,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#define _MACRO_ONLY
#include <microblaze_asm.inc>
#include <t_config.h>
#include <sys_defs.h>
/*
 *  # 0x00 #		Imm instr for reset address     [Hi halfword]
 *  # 0x04 #		Jump to _start                  [Lo halfword]
 *  # 0x08 #		Imm instr for exception address [Hi halfword]
 *  # 0x0c #		Jump to Exception handler       [Lo halfword]
 *  # 0x10 #		Imm instr for interrupt address [Hi halfword]
 *  # 0x14 #		Jump to interrupt handler       [Lo halfword]
 */

        
	.text
	.global _start
	.align  2
    .ent _start
_start:
    /*
     *  msr��������
     */
    la   r1, r0, MSR_CACHE_SETTING         
    mts  rmsr,r1 
                
    /*
     *  opb_mdm ���g���� msr ��BIP�r�b�g��'1'�Ŏ��s����邽�߁C
     *  rtbd���߂ɂ��'0'�ɏ���������D
     *  stub ���g���ꍇ�͕K�v�Ȃ������ɕ���p���Ȃ����߁C�������Ɏ��s����D
     */
    la    r1, r0, _start_
    rtbd  r1,0
_start_:        
               
    /*
     * R2��R3�̐ݒ�
     *�ER2  : Read-only small data area anchor
     *   _SDA2_BASE_ .sdata2�̒��S
     *�ER13 : Read-write small data area anchor
     *   .sdata��sbss��A�����Ēu���C���̒��Ԃ�_SDA_BASE_ ��ݒ肷��
     */
	la	r13, r0, _SDA_BASE_
	la	r2,  r0, _SDA2_BASE_

	/*
	 * �X�^�b�N�|�C���^�̏�����
	 */
	la	r1, r0, STACKTOP - 4

   /*
	* �x�N�^�e�[�u���̏�����
	*/
	/*
     *  brai ���߂̏�������
     */
	la  r3,  r0,  0xb8080000  /* brai �̃I�y�R�[�h      */
	swi r3,  r0,  0xc         /* exception�x�N�^�֓o�^  */
	swi r3,  r0,  0x14        /* interrrupt�x�N�^�֓o�^ */
	/*
     * imm ���߂̏�������
     */
	la  r4,  r0,  0xb0000000  /* imm �̃I�y�R�[�h       */
	swi r4,  r0,  0x8         /* exception�x�N�^�֓o�^  */
    swi r4,  r0,  0x10        /* interrrupt�x�N�^�֓o�^ */

	/*
     *  ��O�n���h���̓o�^
     */
	la   r5,  r0,  exception_entry
	sw	 r5,  r1,  r0
	lhu  r6,  r1,  r0
	shi	 r5,  r0,  0xe       /* �����݃n���h������16bit */
	shi	 r6,  r0,  0xa       /* �����݃n���h�����16bit */

	/*
	 *  �����݃n���h���̓o�^
	 */
	la   r5,  r0,  interrupt_entry
	sw	 r5,  r1,  r0
	lhu  r6,  r1,  r0
	shi	 r5,  r0,  0x16      /* �����݃n���h������16bit */
	shi	 r6,  r0,  0x12      /* �����݃n���h�����16bit */


	/*
	 *  _hardware_init_hook ���Ăяo���B(0�łȂ��ꍇ)
	 *
	 *  �n�[�h�E�F�A�ˑ��ɕK�v�ȏ���������������ꍇ�́C
	 *  hardware_init_hook �Ƃ����֐���p�ӂ���΂悢�D
	 *  ��̓I�ɂ�ROM���̍ہARAM���g�p�\�ɂ��邽�߂�
	 *  �o�X�R���g���[���̏����������s���B
	 *  sys_support.S ���� _hardware_init_hook ���`���Ă�
	 *  ��D
	 */
start_0:
	la    r3,  r0,  _hardware_init_hook
	beqi  r3,  start_1
	brald r15, r3
	nop


	/*
     *  bss�Z�N�V�������N���A
     */
start_1:
	la    r3,  r0,  __bss_start
	la    r4,  r0,  _end
	sub   r5,  r4,  r3
	beqi  r5,  start_3
start_2:
	sb    r0,  r0,  r3
	addi  r3,  r3,  1
	sub   r5,  r4,  r3
	bgti  r5,  start_2

	/*
	 *  data�Z�N�V�����̏������iROM���Ή��j
	 *
	 *  __idata_start ���� __idata_end �܂ł��C__data_start �ȍ~��
	 *  �R�s�[����D
     *  Microblaze�͓���RAM�����������ƂƁCBRAM�̓��e��
     *  ���R���t�B�M�����[�V��������Ə���������邽��
     *  data�Z�N�V�����̏������͍s��Ȃ�
     *  �������ꍇ�ɂ���Ă͎������邱�Ƃ��l���ă��x���̂ݒ�`���Ă���
	 */
start_3:
	la    r3,  r0,  __idata_start
	la    r4,  r0,  __idata_end
	sub   r5,  r4,  r3     /* �T�C�Y���`�F�b�N */
	beqi  r5,  start_5
	la    r6,  r0,  __data_start
start_4:
	lbu   r7,  r0,  r3
    sb    r7,  r0,  r6
	addi  r3,  r3,  1
	addi  r6,  r6,  1
	sub   r5,  r4,  r3
	bgti  r5,  start_4


start_5:
	la    r3,  r0,  __isdata2_start
	la    r4,  r0,  __isdata2_end
	sub   r5,  r4,  r3     /* �T�C�Y���`�F�b�N */
	beqi  r5,  start_7
	la    r6,  r0,  __sdata2_start
start_6:
	lbu   r7,  r0,  r3
    sb    r7,  r0,  r6
	addi  r3,  r3,  1
	addi  r6,  r6,  1
	sub   r5,  r4,  r3
	bgti  r5,  start_6


start_7:
	la    r3,  r0,  __isdata_start
	la    r4,  r0,  __isdata_end
	sub   r5,  r4,  r3     /* �T�C�Y���`�F�b�N */
	beqi  r5,  start_9
	la    r6,  r0,  __sdata_start
start_8:
	lbu   r7,  r0,  r3
    sb    r7,  r0,  r6
	addi  r3,  r3,  1
	addi  r6,  r6,  1
	sub   r5,  r4,  r3
	bgti  r5,  start_8


	/*
	 *  _software_init_hook ���Ăяo���i0 �łȂ��ꍇ�j�D
	 *
	 *  �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ�������
	 *  ��������ꍇ�́Csoftware_init_hook �Ƃ����֐���p�ӂ����
	 *  �悢�D
	 */
start_9:
	la    r3,  r0,  _software_init_hook
	beqi  r3,  start_10
	brald r15, r3
	nop

start_10:
	brlid	r15, kernel_start
    addik r1,r1,4            /* �X�^�b�N�����ɖ߂� */