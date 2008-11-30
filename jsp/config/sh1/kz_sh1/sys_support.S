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
 *  @(#) $Id: sys_support.S,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[�� �A�Z���u�����ꕔ�iKZ-SH1�p�j
 */

#define	_MACRO_ONLY
#include "jsp_kernel.h"

#ifndef GDB_STUB
/*
 *   �o�X�X�e�[�g�R���g���[��
 */
#define	WCR1	0x5ffffa2	/*  �E�F�C�g�R���g���[�����W�X�^1 */
#define	WCR2	0x5ffffa4	/*  �E�F�C�g�R���g���[�����W�X�^2 */
#define	WCR3	0x5ffffa6	/*  �E�F�C�g�R���g���[�����W�X�^3 */

		/*  �G���A7�F���[�h�T�C�N����WAIT�M���ɂ��  	*/
		/*  �E�F�[�g�X�e�[�g�}������  			*/
#define    WCR1_RW7	0x8000
		/*  �G���A3�F���[�h�T�C�N����WAIT�M���ɂ��  	*/
		/*  �E�F�[�g�X�e�[�g�}������  			*/
#define    WCR1_RW3	0x800
		/*  �G���A0�F���[�h�T�C�N����WAIT�M���ɂ��  	*/
		/*  �E�F�[�g�X�e�[�g�}������  			*/
#define    WCR1_RW0	0x100
		/*  �G���A0,2�F1�X�e�[�g�����O�E�F�C�g  	*/
#define    WCR3_A02LW	0x6000



/*
 *  �჌�x���̃^�[�Q�b�g�V�X�e���ˑ��̏����� _hardware_init_hook
 *
 *  �X�^�[�g�A�b�v���W���[���̒��ŁC�������̏������̑O�ɌĂяo�����D
 */
	.text
	.align 2
	.global _hardware_init_hook
_hardware_init_hook:
	/*
	 *  �o�X�X�e�[�g�R���g���[���̏�����
	 *  
	 */

	/*
	 *  �E�F�C�g�X�e�[�g�R���g���[�����W�X�^WCR1
	 *  �@RW3 = 0
	 *  �@�@�@�G���A3�F���[�h�T�C�N���͂P�X�e�[�g�ŏI��
	 *  
	 *  �@RW0 = 0
	 *  �@�@�@�G���A0�F���[�h�T�C�N����WAIT�M���ɂ��
	 *  �@�@�@�E�F�[�g�X�e�[�g�}���Ȃ�
	 */

			/* *WCR1 &= ~(WCR1_RW3 | WCR1_RW0); */
	mov.l	_hw_hook_wcr1, r0
	mov.w	@r0, r1			/*  r1��WCR1  */
	mov.w	_hw_hook_wcr1_data, r2
	and	r2, r1
	mov.w	r1, @r0			/*  WCR1��r1  */
	
	
	/*
	 *  �E�F�C�g�X�e�[�g�R���g���[�����W�X�^WCR3
	 *  
	 *  �@A02LW = 00
	 *  �@�@�@�G���A0,2�F1�X�e�[�g�����O�E�F�C�g
	 */
	
	mov.l	_hw_hook_wcr3, r3
	mov.w	@r3, r4			/*  r4��WCR3  */
	mov.w	_hw_hook_wcr3_a02lw, r5
	and	r5, r4
	rts
	mov.w	r4, @r3			/*  WCR3��r4  */

			/*  �G���A0,2�F1�X�e�[�g�����O�E�F�C�g  	*/
			/* *WCR3 &= WCR3_A02LW_MASK; */
	
	
	
	.align 2
_hw_hook_wcr1:
	.long	WCR1
_hw_hook_wcr3:
	.long	WCR3
_hw_hook_wcr1_data:	
	.word	~(WCR1_RW3 | WCR1_RW0) & 0xffff
_hw_hook_wcr3_a02lw:	
	.word	~WCR3_A02LW & 0xffff
	
#endif /* GDB_STUB */