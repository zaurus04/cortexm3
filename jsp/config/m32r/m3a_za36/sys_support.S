/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  @(#) $Id: sys_support.S,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */

/*
 *  �^�[�Q�b�g�V�X�e���ˑ����W���[�� �A�Z���u�����ꕔ�im3a_za36�p�j
 */

#define	_MACRO_ONLY

#include <m32rasm.inc>

/*
 *  �g�p����SFR��`
 */
#define BSEL0CR		0x00ef5000	/* BSEL0���䃌�W�X�^ */
#define SDRF0		0x00ef6000	/* SDRAM���t���b�V�����䃌�W�X�^0 */
#define SDRF1		0x00ef6004	/* SDRAM���t���b�V�����䃌�W�X�^1 */
#define SDIR0		0x00ef6008	/* SDRAM���������W�X�^0 */
#define SDIR1		0x00ef600c	/* SDRAM���������W�X�^1 */
#define SD0ADR		0x00ef6020	/* SDRAM0�A�h���X���W�X�^ */
#define SD0ER		0x00ef6024	/* SDRAM0�A�N�Z�X�C�l�[�u�����W�X�^ */
#define SD0TR		0x00ef6028	/* SDRAM0�^�C�~���O���W�X�^ */
#define SD0MOD		0x00ef602c	/* SDRAM0���[�h���W�X�^ */
#define SD1ADR		0x00ef6040	/* SDRAM1�A�h���X���W�X�^ */
#define SD1ER		0x00ef6044	/* SDRAM1�A�N�Z�X�C�l�[�u�����W�X�^ */
#define SD1TR		0x00ef6048	/* SDRAM1�^�C�~���O���W�X�^ */
#define SD1MOD		0x00ef604c	/* SDRAM1���[�h���W�X�^ */
#define MCCR		0xfffffffc	/* �L���b�V�����䃌�W�X�^ */
#define ICUIMASK	0x00eff01c	/* �����݃}�X�N���W�X�^	*/

/*
 *	SDRAM�ݒ�}�N����`
 */
#define SDRF1_VAL	0x00010017	/* SDRAM���t���b�V�����䃌�W�X�^1�ݒ�l	*/
#define	SDIR0_VAL	0x00000001	/* SDRAM���������W�X�^0�ݒ�l			*/
#define	SD0ADR_VAL	0x04000004	/* SDRAM0�A�h���X���W�X�^�ݒ�l			*/
#define SD0TR_VAL	0x00020102	/* SDRAM0�^�C�~���O���W�X�^�ݒ�l		*/
#define SD0MOD_VAL	0x00000020	/* SDRAM0���[�h���W�X�^�ݒ�l			*/

/*
 *	�u���b�N�Z���N�g�R���g���[���̐ݒ�l
 */
#define BSEL0CR_VAL	0x01011100

/*
 *  �n�[�h�E�F�A����������
 *
 *  data�Cbss�Z�N�V������SDRAM�̈�ɔz�u����ꍇ�ɂ́C�f�o�b�K����
 *  SDRAM������������D���̏ꍇ�́Chardware_init_hook�ł͉������Ȃ��D
 */
#if 0
Function hardware_init_hook

	/*
	 * �u���b�N�Z���N�g�R���g���[���̐ݒ�
	 */
	mLdadr	r2, BSEL0CR_VAL
	ld24	r3, #BSEL0CR
	st		r2, @r3

	/*
	 *  �L���b�V�����[�h�̐ݒ�
	 */
	ldi	r0, #0x00   /* �L���b�V��OFF */
	ldi	r2, #MCCR	/* �����g�������ăA�h���X�����[�h */
	st	r0, @r2		/* ����/�f�[�^�L���b�V�����[�h�I�� */

	/*
	 *  �O��SDRAM�̐ݒ� 
	 */
	/* --- SDRAM������ -- */
	ld24	r2, #SDIR0		/* SDRAM���������W�X�^0 */
	mLdadr	r3, SDIR0_VAL	/* �������v���`���[�W��E�G�C�g(DPC)       3BCLK	*/
							/* �������I�[�g���t���b�V����(DARFC)     8��		*/
							/* �������I�[�g���t���b�V���v���Ԋu(DARFI) 8BCLK	*/
	st		r3, @r2		/* �ݒ�	*/

	ld24	r2, #SDIR1			/* H'00EF600c	*/
	ldi		r3, #0x00000001		/* �������J�n	*/
	st		r3, @r2

	/* --- SDRAM�������V�[�P���X�����҂� -- */
wait_sdram:
	ldh		r3, @r2
	bnez	r3, wait_sdram		/* �������I���H */

	/* -- SDRAM���[�h���W�X�^�Z�b�g�R�}���h���s */
	ld24	r2, #SD0MOD			/* SDRAM0���[�h���W�X�^					*/
	mLdadr	r3, SD0MOD_VAL			/* �o�[�X�g���[�h						*/
								/* CL=2									*/
								/* �o�[�X�g�^�C�v�F�V�[�P���V����		*/
								/* �o�[�X�g��							*/
	st		r3, @r2				/* �ݒ�	*/

	/* ---- SDRAM�^�C�~���O���W�X�^�ݒ� -- */
	ld24	r2, #SD0TR			/* SDRAM�^�C�~���O���W�X�^							*/
	mLdadr	r3, SD0TR_VAL		/* RAS�A�N�e�B�u����(DRAS)             3BCLK		*/
								/* RAS-CAS���[�e���V(DRCD)             1BCLK		*/
								/* RAS�v���`���[�W(DPCG)               1BCLK		*/
								/* ���C�g���J�o������(DWR)             2BCLK		*/
								/* SDRAM�R���g���[��CAS���[�e���V(DCL) 2BCLK		*/
	st      r3, @r2			/* �ݒ�	*/

	/* --- SDRAM�̈�ݒ�(H'04000000����32M�o�C�g,32bitBUS)	*/
	ld24	r2, #SD0ADR		/* SDRAM0�A�h���X���W�X�^							*/
	mLdadr	r3, SD0ADR_VAL		/* �擪�A�h���X(DADR)         H'0400 xxxx			*/
								/* �f�[�^�o�X���I��(DBSZ)     32�r�b�g				*/
								/* �`���l���T�C�Y�ݒ�(DSZ)    64M�o�C�g				*/
	st		r3, @r2			/* �ݒ�	*/

	/* ---- �I�[�g���t���b�V���L���A�v���Ԋu:1344�N���b�N�ɐݒ�	*/
	ld24	r2, #SDRF1		/* SDRAM���t���b�V�����䃌�W�X�^1					*/
	mLdadr	r3, SDRF1_VAL		/* �I�[�g���t���b�V��(DRFEN)	1(�L���j			*/
								/* �I�[�g���t���b�V���E�F�C�g(DREFW) 8BCLK			*/
								/* �I�[�g���t���b�V���v���Ԋu(DRFC)  1344BCLK		*/
	st		r3, @r2

	/* SDRAM�A�N�Z�X�L�� */
	ld24	r2, #SD0ER			/* SDRAM�A�N�Z�X�C�l�[�u�����W�X�^	*/
	ldi		r3, #0x01			/* �ݒ�l�����W�X�^�Ɋi�[			*/
	st		r3, @r2
	rts
#endif
		
Function software_init_hook
	ld24 	r0, ICUIMASK + 1
	ldi 	r1, 7
	stb 	r1, @r0 			/* �����݃}�X�N��S���ɐݒ� */
	rts