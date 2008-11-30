/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Kunihiko Ohnaka
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
 *  @(#) $Id: sys_config.c,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[��
 */

#include "jsp_kernel.h"
#include <sil.h>

/*
 *  �^�[�Q�b�g�V�X�e���ˑ� ���������[�`��
 */

void
sys_initialize(void)
{
}

/*
 *  �^�[�Q�b�g�V�X�e���̏I�����[�`��
 */

void
sys_exit(void)
{
  while (1)
  	;
}

#ifdef REDBOOT
/*
 *  Redboot���g�p���銄���݃x�N�^�̑ޔ��ƕ���
 */
/*  �����݃x�N�^�̑ޔ�  */
void
load_vector(TMP_VECTOR *p) {
	UW *redboot_trap_vector = (UW *)VECTOR_TABLE_ADDR + TRAP8;
	UW *pirq5 = (UW *)VECTOR_TABLE_ADDR + IRQ_EXT5;
	
	/* �x�N�^�e�[�u���̓��Atrapa���ߕ���ޔ� */
	memcpy(&(p->trap_vector), redboot_trap_vector, TRAP_VECTOR_SIZE*4);

	/*  IRQ5:Ethernet�����݂̐擪�A�h���X��ޔ�  */
	p->irq5 = sil_rew_mem((VP)pirq5);		
}

/*  �����݃x�N�^�̕���  */
void
save_vector(TMP_VECTOR *p) {
	UW *redboot_trap_vector = (UW *)VECTOR_TABLE_ADDR + TRAP8;
	UW *pirq5 = (UW *)VECTOR_TABLE_ADDR + IRQ_EXT5;
	
	/*  IRQ5:Ethernet�����݂̐擪�A�h���X�𕜌�  */
	sil_wrw_mem((VP)pirq5, p->irq5);		

	/* �x�N�^�e�[�u���̓��Atrapa���ߕ��𕜌� */
	memcpy(redboot_trap_vector, &(p->trap_vector), TRAP_VECTOR_SIZE*4);
}

#endif	/* of #ifdef REDBOOT */

