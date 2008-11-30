/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *  @(#) $Id: cpu_insn.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *	�v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`�iTLCS-900L1�p�j
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̌��ݒl�̓Ǐo��
 */
#pragma inline current_sr
UH
current_sr()
{
	Asm("	push	sr");
	Asm("	pop		hl");
	return(__HL);
}

/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̌��ݒl�̕ύX
 */
#pragma inline set_sr
void
set_sr(UH sr)
{
	__HL = sr;
	Asm("	push	hl");
	Asm("	pop		sr");
}

/*
 *  NMI���������ׂĂ̊����݂��֎~
 */
/*
 *  �uei #7�v�Ɓudi�v�͓����̋@�\�ł��邪ei���߂͎��s�㒼���ɗL����
 *  �Ȃ邽��ei���߂��̗p����
 */
#pragma inline disint
void
disint()
{
	Asm("	ei	7	");
}

/*
 *  ���ׂĂ̊����݂�����
 */
#pragma inline enaint
void
enaint()
{
	Asm("	ei	0	");
}

/*
 *  ���f�B�L���[�T�[�`�̂��߂̃r�b�g�}�b�v�T�[�`�֐�
 *
 *  �r�b�g�}�b�v�̉���16�r�b�g���g�p���C�ŉ��ʃr�b�g���Œ�D��x�ɑΉ�
 *  ������D
 */
#define	CPU_BITMAP_SEARCH

#pragma inline bitmap_search
UINT
bitmap_search(UINT bitmap)
{
	/*
	 *  ���̃R�[�h�́Cbitmap�iUINT�^�j��16�r�b�g�ł��邱�Ƃ����肵
	 *  �Ă���D
	 */
	__HL = bitmap;
	Asm("	bs1f	a, hl");
	return (UINT)__A;
}

#endif /* _CPU_INSN_H_ */
