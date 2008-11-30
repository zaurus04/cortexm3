/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 *  @(#) $Id: sys_support.S,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[�� �A�Z���u�����ꕔ
 *�@�@�@�@�@�J�[�l�������Ŏg�p�����`�iMPC860T TB6102S�p�j
 *  
 *  �@�@�{�[�h�ˑ��𕪗�����ƁA���̃t�@�C���͂قƂ�ǋ�ɂȂ���
 *  �@�@���܂��̂ŁA���̂܂܂ɂ��Ă���B
 *  
 */

#define _MACRO_ONLY
#include "jsp_kernel.h"

/*
 *  �������R�}���h���W�X�^MCR�ɐݒ肷��WRITE�I�y�R�[�h
 *
 *  �@�@�@�@OP=00�FWRITE
 *  �@�@�@�@UM=0�FUPMA
 *  �@�@�@�@MB=000�FRUN�R�}���h�̂ݗL��
 *  �@�@�@�@MCLF=0�FRUN�R�}���h�̂ݗL��
 *  �@�@�@�@MAD=0�F�������A���C�C���f�b�N�X
 *  �@�@�@�@�@�@�@�@�i��ɂ��Ă����āA�ʂ̃f�[�^������j
 *  
 */
#define MCR_WRITE_OP	0

/*
 *  �჌�x���̃^�[�Q�b�g�V�X�e���ˑ��̏�����
 *
 *  �X�^�[�g�A�b�v���W���[���̒��ŁC�������̏������̑O�ɌĂяo�����D
 *  
 *  ���W�X�^���蓖��
 *  �@�@r10�F�������W�X�^�̈�̐擪�A�h���X
 *  
 */
    .text
    .globl hardware_init_hook
hardware_init_hook: 
    /*  ipm_table��SPRG3�ɃR�s�[  */
    LI32(r4, ipm_table)
    mtspr   SPRG3, r4

    /*  �����������}�b�v���W�X�^IMMR�̏�����  */
    /* �@�������W�X�^�̈�̐擪�A�h���X�̐ݒ� */  
    lis     r10, IMMR_UPPER_2BYTE /*  ���2�o�C�g  */
    mtspr   IMMR, r10   /*  ����2�o�C�g�͏㏑�����Ă��j�󂳂�Ȃ�  */
    
#ifdef DOWNLOAD_TO_RAM      /*  �f�o�b�O�p  */
    
    /*
     *  RAM��Ƀ_�E�����[�h����ꍇ
     *
     *  �@�@��O�x�N�^�̃I�t�Z�b�g��0x000x,xxxx�ɂ���B
     */
    li      r5, 0
    mtmsr   r5		/*  MSR.IP��0  */
    blr
    
#else /* DOWNLOAD_TO_RAM */ /*  ROM��  */
    

    /*  �o�X�R���g���[���̏�����  */    

    /*
     *  �\�t�g�E�F�A�E�E�H�b�`�h�b�N�^�C�}�̏�����
     */

    /*  �E�H�b�`�h�b�N�^�C�}���N���A  */
    li      r6, SWSR_CLEAR1
    sth     r6, TADR_SIU_SWSR(r10)
    ori     r6, r0, SWSR_CLEAR2
    sth     r6, TADR_SIU_SWSR(r10)
    
    /*
     *  �@�E�H�b�`�h�b�N�^�C�}���f�B�Z�[�u���ɂ���
     *  �@  SYPCR.SWE��0
     */
    lwz     r5, TADR_SIU_SYPCR(r10)
    ori	    r5, r5, SYPCR_SWE
    xori    r5, r5, SYPCR_SWE
    stw     r5, TADR_SIU_SYPCR(r10)


    /*
     *  FlashROM�o�X�R���g���[���̏�����
     *  �@2MB
     *  �@�A�h���X�}�b�v�F0x1000,0000-0x101f,ffff
     *  �@�`�b�v�Z���N�g�M���FCS0
     *  �@�������R���g���[���F�ėp�`�b�v�E�Z���N�g�E�}�V��GPCM
     *  �@16�r�b�g�A�N�Z�X
     *  �@
     *  �@�u�[�g�`�b�v�Z���N�gCS0�Ɋւ��Ă�
     *  �@BR0��OR0�̏��ɐݒ肵�Ȃ���΂Ȃ�Ȃ�
     *  �@
     */

    /*
     *  �O���o�X�����W���̐ݒ�
     *  �@SCCR.EBDF=00�FCLKOUT��GCLK2��1�̕�����
     */
    LI32(r4, UNLOCK_KEY)
    stw     r4, TADR_SCCRK(r10)     /* SCCR�A�����b�N */
    lwz     r5, TADR_SCCR(r10)
    oris    r6, r5, (SCCR_EBDF>>16)
    xoris   r7, r6, (SCCR_EBDF>>16)
    stw     r7, TADR_SCCR(r10)
    li      r0, 0
    stw     r0, TADR_SCCRK(r10)     /* SCCR���b�N */


    /*
     *  �x�[�X���W�X�^BR0 = 0x1000,0801
     *  �@�@BA=0x1000(0b)�F�A�N�Z�X�͈� 0x1000,0000�`
     *  �@�@PS=10�F�|�[�g�T�C�Y 16�r�b�g
     *  �@�@PARE=0�F�p���e�B�E�f�B�Z�[�u��
     *  �@�@WP=0�F���[�h�^���C�g���i�ی�Ȃ��j�@�v����
     *  �@�@MS=00�FUPMA���g�p
     *  �@�@V=1�FBR0,OR0���L��
     *
     *�@�@�@�n�[�h�E�F�A�E�}�j���A���ɂ�BR0�̓��[�h�I�����[��
     *�@�@�@���邪�A���炵��
     */
    LI32(r3, 0x10000801)
    stw     r3, TADR_BR0(r10)

    /*
     *  �I�v�V�����E���W�X�^OR0 = 0xffe0,0936
     *  �@�@MA=0xffe0(0b)�F�A�N�Z�X�͈�21�r�b�g�i��2MB�j
     *  �@�@CSNT=1�F�`�b�v�E�Z���N�g�E�l�Q�[�g����
     *  �@�@ACS=00�FCS���A�h���X���C���Ɠ����ɏo��
     *  �@�@BIH=1�F�o�[�X�g�֎~�iGPCM�Ȃ�Z�b�g���Ȃ���΂Ȃ�Ȃ��j
     *  �@�@SYC=3�F�T�C�N����
     *  �@�@SETA=0�F�����^�O���̓]���A�N�m���b�W�͍ŏ��̃A�N�Z�X��F��
     *  �@�@TRLX=1�F�^�C�~���O�ɘa
     *  �@�@EHTR=1�F���[�h���̃z�[���h���ԉ���
     */
    LI32(r4, 0xffe00936)
    stw     r4, TADR_OR0(r10)

    /*  MSR.IP=0(A20=L)�̏ꍇ�̐�ΔԒn�ɃW�����v  */
    LI32(r5, activate_A20_line)
    mtctr   r5
    bctr
    
    /*  A20�M���̊�����  */
activate_A20_line:
    /*  �ėpI/O�@�\�I���FPBPAR.DD27��0  */
    lhz     r6, (TADR_PBPAR + 2)(r10)
    andi.   r6, r6, (~PBPAR_DD27 & 0xffff)
    sth     r6, (TADR_PBPAR + 2)(r10)

    /*  ���o�͕����I���i�o�́j�FPBDIR.DR27��1  */
    lhz     r7, (TADR_PBDIR + 2)(r10)
    ori     r7, r7, PBDIR_DR27
    sth     r7, (TADR_PBDIR + 2)(r10)
    
    /*  �A�N�e�B�u�Ƀh���C�u�FPBODR.OD27��0  */
    lhz     r8, (TADR_PBODR + 2)(r10)
    andi.   r8, r8, (~PBODR_OD27 & 0xffff)
    sth     r8, (TADR_PBODR + 2)(r10)
    
    /*  A20=1���o�́FPBDAT.D27��1  */
    lhz     r9, (TADR_PBDAT + 2)(r10)
    ori     r9, r9, PBDAT_D27
    sth     r9, (TADR_PBDAT + 2)(r10)
    nop
    nop
    nop


    /*
     *  SDRAM�o�X�R���g���[���̏�����
     *  �@50MHz
     *  �@16MB
     *  �@�A�h���X�}�b�v�F0x0000,0000-0x00ff,ffff
     *  �@�`�b�v�Z���N�g�M���FCS2
     *  �@�������R���g���[���F���[�U�E�v���O���}�u���E�}�V��UPMA
     *  �@32�r�b�g�A�N�Z�X
     *  �@
     *  �@���W�X�^���蓖��
     *  �@�@r10�F�������W�X�^�̈�̐擪�A�h���X
     *  �@
     *  �@���l
     *  �@�@�@UPM���W�X�^��ORx��BRx�̏��ɐݒ肷��
     *  �@
     *  �@
     */

    /*
     *  �������R���g���[��UPMA�̐ݒ背�W�X�^������
     *  �@
     *  �@���t���b�V��������1CLK�����~�v���X�P�[���l�~�^�C�}����
     *  �@�@�@�@�@�@�@�@�@��20nsec�@�~�@�@ 32 �@�@�@�~�@24
     *  �@�@�@�@�@�@�@�@�@��15.36��sec
     */

    /*
     *  �����������^�C�}�E�v���X�P�[���E���W�X�^MPTPR = 0x0200
     *  �@�@PTP=0x2�F32�ɂ�镪��
     */
    ori     r3, r0, 0x0200
    sth     r3, TADR_MPTPR(r10)

    /*
     *  �}�V��A���[�h�E���W�X�^MAMR = 0x1880,2111
     *  �@�@PTx=24�F���t���b�V������
     *  �@�@PTxE=1�F�����^�C�}�C�l�[�u��
     *  �@�@AMx=0�F�A�h���X���d�T�C�Y
     *  �@�@DSx=00�F�f�B�Z�[�u������ 1�T�C�N��
     *  �@�@G0CLx=001�FGPL0�ɑ΂���A�h���X���C���o�͂�A11
     *  �@�@GPLx4DIS=0�FUPWAIT/GPL_x4��GPL_x4�ɒ�`
     *  �@�@RLFx=0001�F���[�h�T�C�N���̃��[�v 1��
     *  �@�@WLFx=0001�F���C�g�T�C�N���̃��[�v 1��
     *  �@�@TLFx=0001�F�����^�C�}�T�[�r�X�T�C�N���̃��[�v 1��
     */
    LI32(r4, 0x18802111)
    stw     r4, TADR_MAMR(r10)

    /*
     *  �I�v�V�����E���W�X�^OR2 = 0xff00,0600
     *  �@�@MA=0xff00(0b)�F�A�N�Z�X�͈�24�r�b�g�i��16MB�j
     *  �@�@SAM=0�F���d���A�h���X�Ȃ�
     *  �@�@G5LA=1�FGPL_A5�œ���GPL5�M�����o��
     *  �@�@G5LS=1�FGPL5��GCLK1_50�̗����オ��G�b�W��H�Ƀh���C�u
     *  �@�@BIH=0�F�o�[�X�g�A�N�Z�X���T�|�[�g
     */
    LI32(r5, 0xff000600)
    stw     r5, TADR_OR2(r10)

    /*
     *  �x�[�X�E���W�X�^BR2 = 0x0000,0081
     *  �@�@BA=0x0000(0b)�F�A�N�Z�X�͈� 0x0000,0000�`
     *  �@�@PS=00�F�|�[�g�T�C�Y 32�r�b�g
     *  �@�@PARE=0�F�p���e�B�E�f�B�Z�[�u��
     *  �@�@WP=0�F���[�h�^���C�g���i�ی�Ȃ��j
     *  �@�@MS=10�FUPMA���g�p
     *  �@�@V=1�FBR2,OR2���L��
     */
    ori     r6, r0, 0x0081
    stw     r6, TADR_BR2(r10)
    
    /*
     *  RAM�A���C�̏�����
     *  �@RAM�A���C��MPC860�̓����������ł���A�O���������ɃA�N�Z�X
     *  �@����ۂ̊e�T�C�N���ɂ�����s���̏�Ԃ��K�肷��B
     *  �@
     *  �@���W�X�^���蓖��
     *  �@�@r3�F�|�C���^�e�[�u���ւ̃|�C���^
     *  �@�@r4�F�������ރ��[�h���i�c�萔�j
     *  �@�@r5�F���f�[�^�̃A�h���X
     *  �@�@r6�F�]����̃C���f�b�N�X
     *  �@�@r10�F�������W�X�^�̈�̐擪�A�h���X
     */
	    /*  �@lwzu���߂��g���₷���Ȃ�悤  */
	    /*  �@�A�h���X��-4���Ă���  */
    LI32(r3, (RAM_array_index-4))

    /*  �u���b�N�f�[�^�������݃��[�v  */
RAM_array_block_init_loop:
    lwzu    r4, 4(r3)       /*  ���[�h��  */
    			    /*    r3���C���N�������g�����_�ɒ��� */
    cmpwi   crf0, r4, 0     /*  �e�[�u���Ɏw�肳�ꂽ���[�h����  */
    beq     SDRAM_init      /*  �[���Ȃ�΁A�f�o�C�X�̏�������  */
    lwzu    r5, 4(r3)       /*  ���f�[�^�̃A�h���X  */
    			    /*  �@lwzu���߂��g���₷���Ȃ�悤  */
    			    /*  �@�A�h���X��-4����Ċi�[����Ă���  */
    lwzu    r6, 4(r3)       /*  �]����̃C���f�b�N�X  */
    			    /*    r3���C���N�������g�����_�ɒ��� */

    /*
     *  ���[�h�f�[�^�������݃��[�v
     *  �@�������f�[�^���W�X�^MDR�ɏ������񂾃f�[�^��
     *  �@WRITE�I�y�R�[�h�ɂ��RAM�A���C�ɓ]�������
     */
RAM_array_word_init_loop:
    lwzu    r8, 4(r5)   /*  ���f�[�^  */
			/*    r5���C���N�������g�����_�ɒ��� */
    stw     r8, TADR_MDR(r10)   /*  �������݃f�[�^����  */
    ori     r9, r6, MCR_WRITE_OP
    stw     r9, TADR_MCR(r10)   /*  WRITE�R�}���h���s  */
    subi    r4, r4, 1
    addi    r6, r6, 1
    cmpwi   crf0, r4, 0         /*  �������ނׂ��f�[�^���c���Ă����  */
    bne     RAM_array_word_init_loop    /*  ���̃��[�h�f�[�^�̏�����  */
                    /*  �f�[�^���c���Ă��Ȃ���΁A���̃u���b�N�̏�����  */
    b       RAM_array_block_init_loop


    /*  SDRAM�i�f�o�C�X���́j�̏�����  */
SDRAM_init: 
    /*
     *  �S�o���N�E�v���`���[�W
     *  
     *  �@�@�������R�}���h���W�X�^MCR = 0x8000,4105
     *  �@�@�@�@OP=10�FRUN
     *  �@�@�@�@UM=0�FUPMA
     *  �@�@�@�@MB=010�FCS2
     *  �@�@�@�@MCLF=1�F���[�v1��
     *  �@�@�@�@MAD=5�F�������A���C�C���f�b�N�X
     *  �@�@�@�@�@�@�@�@�i�S�o���N�v���`���[�W�̖��߂������Ă���j
     */
    LI32(r3, 0x80004105)
    stw     r3, TADR_MCR(r10)
        
    /*
     *  �I�[�g���t���b�V�� 8��
     *  
     *  �@�@�������R�}���h���W�X�^MCR = 0x8000,4830
     *  �@�@�@�@OP=10�FRUN
     *  �@�@�@�@UM=0�FUPMA
     *  �@�@�@�@MB=010�FCS2
     *  �@�@�@�@MCLF=8�F���[�v 8�� �i���t���b�V���񐔁j
     *  �@�@�@�@MAD=0x30�F�������A���C�C���f�b�N�X
     *  �@�@�@�@�@�@�@�@�i�I�[�g���t���b�V���̖��߂������Ă���j
     */
    LI32(r4, 0x80004830)
    stw     r4, TADR_MCR(r10)
    
    
    /*
     *  ���샂�[�h�ݒ�
     *  �@CAS���C�e���V�F2
     *  �@�o�[�X�g���@ �F4
     *  
     *  �@�@�������A�h���X���W�X�^MAR = 0x0000,0088
     *  �@�@�@�@�A�h���X�o�X�ɏo�͂���ASDRAM�ւ̖��߂ƂȂ�
     *  
     *  �@�@�������R�}���h���W�X�^MCR = 0x8000,4106
     *  �@�@�@�@OP=10�FRUN
     *  �@�@�@�@UM=0�FUPMA
     *  �@�@�@�@MB=010�FCS2
     *  �@�@�@�@MCLF=1�F���[�v 1�� 
     *  �@�@�@�@MAD=6�F�������A���C�C���f�b�N�X
     *  �@�@�@�@�@�@�@�@�i���샂�[�h�ݒ�̖��߂������Ă���j
     */
    ori     r5, r0, 0x0088
    stw     r5, TADR_MAR(r10)
    LI32(r6, 0x80004106)
    stw     r6, TADR_MCR(r10)
    

/*
 *  ��O�x�N�^�̃R�s�[
 */
copy_exception_vector:
	/*  lwzu���߂��g������-4���Ă���  */
	LI32(r7, EXCEPTION_VECTOR_START_SRC - 4)
	LI32(r8, EXCEPTION_VECTOR_END_SRC - 4)
	LI32(r9, EXCEPTION_VECTOR_START_DST - 4)
copy_exception_vector_1:
	lwzu	r10, 4(r7)	/*  r7�̍X�V��1���߂Ŏ��s�����  */
	stwu	r10, 4(r9)	/*  r9�̍X�V��1���߂Ŏ��s�����  */
	cmpw	crf0, r7, r8
	blt	copy_exception_vector_1
	
        /*
         *  MSR.IP��0
         *�@�@��O�v���t�B�b�N�X�F0x000n,nnnn
         */
	li	r3, MSR_IP
	mfmsr	r4
	or	r4, r4, r3
	xor	r4, r4, r3
	mtmsr	r4
	
	LI32(r10, start_1)
	mtctr	r10
	bctr
	nop
	nop
	nop
	nop

/*
 *  RAM�A���C�̏������Ɏg�p����f�[�^�ւ̃|�C���^�e�[�u��
 *  �@���[�h���A���f�[�^�̃A�h���X�A�]����̃C���f�b�N�X��
 *  �@1�Z�b�g�i1�u���b�N���j
 *  �@���f�[�^�̃A�h���X��lwzu���߂��g���₷���Ȃ�悤
 *  �@-4���Ă���B
 *  �@
 *  �@�Ō�̓��[�h���O�̃f�[�^��z�u���A���[�v�I���̔���ɗp����
 */
RAM_array_index:    
    /*
     *  ���[�h�E�V���O���E�r�[�g�v���i�v 16���[�h�j
     *  �@�@�E���[�h�E�V���O���E�r�[�g�v���i5���[�h�j
     *  �@�@�E�S�o���N�v���`���[�W�i1���[�h�j
     *  �@�@�E���[�h�ݒ�i2���[�h�j
     *  �@�@�E���[�h�E�o�[�X�g�v���i8���[�h�j
     */
    .int    16                  /*  ���[�h��  */
    .int    RAM_array_RSS - 4   /*  ���f�[�^�̃A�h���X  */
    .int    0x0                 /*  �]����̃C���f�b�N�X  */

    /*
     *  ���C�g�E�V���O���E�r�[�g�v��
     */
    .int    4                   /*  ���[�h��  */
    .int    RAM_array_WSS - 4   /*  ���f�[�^�̃A�h���X  */
    .int    0x18                /*  �]����̃C���f�b�N�X  */

    /*
     *  ���C�g�E�o�[�X�g�v��
     */
    .int    7                   /*  ���[�h��  */
    .int    RAM_array_WBS - 4   /*  ���f�[�^�̃A�h���X  */
    .int    0x20                /*  �]����̃C���f�b�N�X  */

    /*
     *  �����^�C�}�v���i�I�[�g���t���b�V���j
     */
    .int    5                   /*  ���[�h��  */
    .int    RAM_array_TPS - 4   /*  ���f�[�^�̃A�h���X  */
    .int    0x30                /*  �]����̃C���f�b�N�X  */

    /*
     *  ��O�����v��
     */
    .int    1                   /*  ���[�h��  */
    .int    RAM_array_EXS - 4   /*  ���f�[�^�̃A�h���X  */
    .int    0x3c                /*  �]����̃C���f�b�N�X  */

    /*
     *  ���[�v�I������p�f�[�^
     */
    .int    0                   /*  ���[�h��  */
    

/*
 *  RAM�A���C�ɃR�s�[����f�[�^
 */

    /*
     *  �ȉ��̂S�̖��ߌQ��A�������̈�ɔz�u�i�v 16���[�h�j
     *  �@�@�E���[�h�E�V���O���E�r�[�g�v���i5���[�h�j
     *  �@�@�E�S�o���N�v���`���[�W�i1���[�h�j
     *  �@�@�E���[�h�ݒ�i2���[�h�j
     *  �@�@�E���[�h�E�o�[�X�g�v���i8���[�h�j
     */
RAM_array_RSS:  
    /*  ���[�h�E�V���O���E�r�[�g�v��  */
    .int    0x1f07fc04                      /*  0  */
    .int    0xeeaef004                      /*  1  */
    .int    0x11adf004                      /*  2  */
    .int    0xefbbbc00                      /*  3  */
    .int    0x1ff77c47                      /*  4  */
    /*  �S�o���N�v���`���[�W  */
    .int    0x1ff77c07                      /*  5  */
    /*  ���[�h�ݒ�p�f�[�^  */
    .int    0xefcab034                      /*  6  */
    .int    0x1f357405                      /*  7  */
    /*  ���[�h�E�o�[�X�g�v��  */
    .int    0x1f07fc04                      /*  8  */
    .int    0xeeaef004                      /*  9  */
    .int    0x10adf004                      /*  a  */
    .int    0xf0affc00                      /*  b  */
    .int    0xf0affc00                      /*  c  */
    .int    0xf1affc00                      /*  d  */
    .int    0xefbbbc00                      /*  e  */
    .int    0x1ff77c47                      /*  f  */

    /*
     *  ���C�g�E�V���O���E�r�[�g�v��
     */
RAM_array_WSS:
    .int    0x1f07fc04                      /*  0x18 + 0  */
    .int    0xeeaeb000                      /*  0x18 + 1  */
    .int    0x01b93004                      /*  0x18 + 2  */
    .int    0x1ff77c47                      /*  0x18 + 3  */

    /*
     *  ���C�g�E�o�[�X�g�v��
     */
RAM_array_WBS:
    .int    0x1f07fc04                      /*  0x20 + 0  */
    .int    0xeeaeb000                      /*  0x20 + 1  */
    .int    0x10ad7000                      /*  0x20 + 2  */
    .int    0xf0affc00                      /*  0x20 + 3  */
    .int    0xf0affc00                      /*  0x20 + 4  */
    .int    0xe1bbbc04                      /*  0x20 + 5  */
    .int    0x1ff77c47                      /*  0x20 + 6  */

    /*
     *  �����^�C�}�v���i�I�[�g���t���b�V���j
     */
RAM_array_TPS:
    .int    0x1ff5fc84                      /*  0x30 + 0  */
    .int    0xfffffc04                      /*  0x30 + 1  */
    .int    0xfffffc04                      /*  0x30 + 2  */
    .int    0xfffffc84                      /*  0x30 + 3  */
    .int    0xfffffc05                      /*  0x30 + 4  */

    /*
     *  ��O�����v��
     */
RAM_array_EXS:
    .int    0xfffffc07                      /*  0x3c + 0  */


#endif  /*  DOWNLOAD_TO_RAM  */
/*  end of file  */