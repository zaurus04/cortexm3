/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *
 *  Copyright (C) 2004 by SEIKO EPSON Corp, JAPAN
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
 *  �J�[�l���p�̃X�^�[�g�A�b�v���W���[��(S1C33�p)
 */

#include "jsp_kernel.h"
#include "sys_config.h"
#include "cpu_config.h"

/*
 *  �O���֐��̎Q��
 */
extern void init_lib(void);
extern void init_sys(void);

extern void INT_ENTRY(timer_handler)(void);
extern void INT_ENTRY(sio_in_handler)(void);
extern void INT_ENTRY(sio_out_handler)(void);

/*
 *  �v���g�^�C�v�錾
 */
void start(void);
static void undef_handler(void);
static void hardware_init_hook(void);
static void software_init_hook(void);

/*
 *  �x�N�^�[�e�[�u��
 */
VP tps_VectorTable[] = {		/* offset   number */
	(VP) start,			/* 00  Reset			*/
	(VP) undef_handler,		/* 01  				*/
	(VP) undef_handler,		/* 02  				*/
	(VP) undef_handler,		/* 03                           */
	(VP) undef_handler,		/* 04  Zero division            */
	(VP) undef_handler,		/* 05                           */
	(VP) undef_handler,		/* 06  Address error exception  */
	(VP) undef_handler,		/* 07  debug                    */
	(VP) undef_handler,		/* 08  NMI                      */
	(VP) undef_handler,		/* 09                           */
	(VP) undef_handler,		/* 10                           */
	(VP) undef_handler,		/* 11                           */
	(VP) undef_handler,		/* 12  Software exception 0     */
	(VP) undef_handler,		/* 13  Software exception 1     */
	(VP) undef_handler,		/* 14  Software exception 2     */
	(VP) undef_handler,		/* 15  Software exception 3     */
	(VP) undef_handler,		/* 16 (00)                      */
	(VP) undef_handler,		/* 17 (01)                      */
	(VP) undef_handler,		/* 18 (02)                      */
	(VP) undef_handler,		/* 19 (03)                      */
	(VP) undef_handler,		/* 20 (04)                      */
	(VP) undef_handler,		/* 21 (05)                      */
	(VP) undef_handler,		/* 22 (06)                      */
	(VP) undef_handler,		/* 23 (07)                      */
	(VP) undef_handler,		/* 24 (08)                      */
	(VP) undef_handler,		/* 25 (09)                      */
	(VP) undef_handler,		/* 26 (10)                      */
	(VP) undef_handler,		/* 27 (11)                      */
	(VP) undef_handler,		/* 28 (12)                      */
	(VP) undef_handler,		/* 29 (13)                      */
	(VP) undef_handler,		/* 30 (14)                      */
	(VP) undef_handler,		/* 31 (15)                      */
	(VP) undef_handler,		/* 32 (16)                      */
	(VP) undef_handler,		/* 33 (17)                      */
	(VP) INT_ENTRY(timer_handler),	/* 34 (18) 16 bit programable timer 1-b */
	(VP) undef_handler,		/* 35 (19)                      */
	(VP) undef_handler,		/* 36 (20)                      */
	(VP) undef_handler,		/* 37 (21)                      */
	(VP) undef_handler,		/* 38 (22)                      */
	(VP) undef_handler,		/* 39 (23)                      */
	(VP) undef_handler,		/* 40 (24)                      */
	(VP) undef_handler,		/* 41 (25)                      */
	(VP) undef_handler,		/* 42 (26)                      */
	(VP) undef_handler,		/* 43 (27)                      */
	(VP) undef_handler,		/* 44 (28)                      */
	(VP) undef_handler,		/* 45 (29)                      */
	(VP) undef_handler,		/* 46 (30)                      */
	(VP) undef_handler,		/* 47 (31)                      */
	(VP) undef_handler,		/* 48 (32)                      */
	(VP) undef_handler,		/* 49 (33)                      */
	(VP) undef_handler,		/* 50 (34)                      */
	(VP) undef_handler,		/* 51 (35)                      */
	(VP) undef_handler,		/* 52 (36)                      */
	(VP) undef_handler,		/* 53 (37)                      */
	(VP) undef_handler,		/* 54 (38)                      */
	(VP) undef_handler,		/* 55 (39)                      */
	(VP) undef_handler,		/* 56 (40) Serial interface Ch.0 (error) */
	(VP) INT_ENTRY(sio_in_handler),	/* 57 (41) Serial interface Ch.0 (rx) */
	(VP) INT_ENTRY(sio_out_handler),/* 58 (42) Serial interface Ch.0 (tx) */
	(VP) undef_handler,		/* 59 (43)                      */
	(VP) undef_handler,		/* 60 (44)                      */
	(VP) undef_handler,		/* 61 (45)                      */
	(VP) undef_handler,		/* 62 (46)                      */
	(VP) undef_handler,		/* 63 (47)                      */
	(VP) undef_handler,		/* 64 (48)                      */
	(VP) undef_handler,		/* 65 (49)                      */
	(VP) undef_handler,		/* 66 (50)                      */
	(VP) undef_handler,		/* 67 (51)                      */
	(VP) undef_handler,		/* 68 (52)                      */
	(VP) undef_handler,		/* 69 (53)                      */
	(VP) undef_handler,		/* 70 (54)                      */
	(VP) undef_handler		/* 71 (55)                      */
};

/*
 *  �u�[�g���[�`��
 */
void start(void)
{
	/*
	 *  �f�t�H���g�f�[�^�G���A�A�h���X��ݒ肷��
	 */
	Asm("xld.w %r15, __dp");

	/*
	 *  ��^�X�N�R���e�X�g�̃X�^�b�N��STACKTOP�ɏ���������
	 *  STACKTOP�́Asys_config.h�Œ�`
	 */
	set_sp(STACKTOP);

	/*
	 * PSR�����������A���荞�݂��֎~����
	 */
	set_psr(0x00000000);


	/*
	 *  hardware_init_hook ���Ăяo���B(0�łȂ��ꍇ)
	 *
	 *  �n�[�h�E�F�A�ˑ��ɕK�v�ȏ���������������ꍇ�́C
	 *  hardware_init_hook �Ƃ����֐���p�ӂ���΂悢�D
	 *  ��̓I�ɂ�ROM���̍ہARAM���g�p�\�ɂ��邽�߂�
	 *  �o�X�R���g���[���̏����������s���B
	 *  sys_config.c ���� hardware_init_hook ���`���Ă���D
	 */
	if (hardware_init_hook != (VP) 0) {
		hardware_init_hook();
	}

	/*
	 *  data�Z�N�V����������������iROM���Ή��j�D
	 */
	memcpy(VECTOR_START, IVECTOR_START, (UW)IVECTOR_END - (UW)IVECTOR_START);
	memcpy(DATA_START, IDATA_START, (UW)IDATA_END - (UW)IDATA_START);

	/*
	 *  bss�Z�N�V������0�N���A����B
	 */
	 memset(BSS_START, 0x00, BSS_END - BSS_START);

	/*
	 *  software_init_hook ���Ăяo���i0 �łȂ��ꍇ�j
	 *
	 *  �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ�������
	 *  ��������ꍇ�́Csoftware_init_hook �Ƃ����֐���p�ӂ����
	 *  �悢�D
	 */
	if (software_init_hook != (VP) 0) {
		software_init_hook();
	}

	/*
	 *  �J�[�l�����N������
	 */
	Asm("xjp kernel_start");

	do {
		Asm("halt");
	} while (TRUE);
}

/*
 *  �_�~�[���[�`��
 */
static void undef_handler(void)
{
	while(1){
		;
	}
}

/*
 *  �V�X�e���ˑ��̏���������
 */
static	void	hardware_init_hook(void)
{
	(*(s1c33Bcu_t *) S1C33_BCU_BASE).bTtbrProt = (IOREG)0x59;
	(*(s1c33Bcu_t *) S1C33_BCU_BASE).ulTtbr = (LIOREG)tps_VectorTable;

	(*(s1c33Bcu_t *) S1C33_BCU_BASE).uwBus = 0x0008;
	(*(s1c33Bcu_t *) S1C33_BCU_BASE).uwDram = 0x0c00;

	return;
}


/*
 *  �\�t�g�E�F�A�ˑ��̏���������
 */
static	void	software_init_hook(void)
{
	init_lib();
	init_sys();
}
