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
 *  @(#) $Id: tb6102s.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *  �^���o�b�N�@MPC860T CPU�{�[�hTB6102S
 *  �̃n�[�h�E�F�A�����̒�`
 */

#ifndef _TB6102S_H_
#define _TB6102S_H_


/*
 *  �����݊֘A�̒�`
 */

/*  ����`�̊����݂ɑ΂���IPM�̃f�t�H���g�l  */
#define DEFAULT_IPM	0x00	/*  ���ׂĂ̊����݂��֎~  */

/*  CPM����SIU�ւ̊����ݗv�����x��  */
	/*  CICR.IRL0�̐ݒ�l�i�r�b�g16-18��2�i���j  */
#define CICR_IRL0	(CPM_INT_LEVEL << (31 - 18))

/*  SIU���猩��CPM�̊����ݔԍ�  */
#define INHNO_CPM		LEVEL_TO_INHNO(CPM_INT_LEVEL)

/*  SIU���猩��CPM�̊����݋��r�b�g  */
#define ENABLE_CPM		LEVEL_TO_ENABLE_BIT(CPM_INT_LEVEL)

/*  CPM�����݂�IPM  */
#define IPM_CPM			LEVEL_TO_IPM(CPM_INT_LEVEL)


/*
 *  �^�C�}�֘A�̐ݒ�
 *
 */
/* �^�C�}�̊��荞�݃��x���iSIU�̓������x���j */
#define INTLVL_PIT	INTLVL_TIMER


/*
 *  GDB STUB�ďo�����[�`���i�������j
 */
#ifndef _MACRO_ONLY
#ifdef GDB_STUB

#define tb6102s_exit	stub_exit
#define tb6102s_putc	stub_putc

Inline void
stub_exit(void)
{
}

Inline void
stub_putc(char c)
{
}

/*
 *  GDB stub���g��Ȃ��ꍇ�iROM���p�j
 */
#else /* GDB_STUB */

extern void	smc_putc_pol(char c);	/*  mpc860_smc.c  */

/*
 *  SIL�̃A�N�Z�X�E���O�@�\��L���ɂ����ꍇ
 */
#ifdef SIL_DEBUG

#define SIL_BUFFER_SIZE	10000
char sil_buffer[SIL_BUFFER_SIZE];
int sil_pos;
BOOL sil_debug_on;

Inline void
tb6102s_exit()
{
	int i;

	sil_debug_on = FALSE;
	
	/*  �����O�o�b�t�@����Â����Ƀf�[�^��\������  */
	for(i=sil_pos; i<SIL_BUFFER_SIZE; i++) {
		smc_putc_pol(sil_buffer[i]);
	}
	for(i=0; i<sil_pos; i++) {
		smc_putc_pol(sil_buffer[i]);
	}
	while(1);
}

Inline void 
tb6102s_putc(char c)
{
	++sil_pos;
	sil_pos %= SIL_BUFFER_SIZE;
	sil_buffer[sil_pos] = c;
}

#else	/* SIL_DEBUG */

Inline void
tb6102s_exit()
{
	while(1);
}

Inline void 
tb6102s_putc(char c)
{
	smc_putc_pol(c);
}

#endif	/* SIL_DEBUG */

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _TB6102S_H_ */
/*  end of file  */
