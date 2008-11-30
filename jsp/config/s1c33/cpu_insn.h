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

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  ���䃌�W�X�^�̑���֐�
 */

/*
 *  �X�e�[�^�X���W�X�^(PSR)�̌��ݒl�̓Ǐo��
 */
Inline UW
get_psr(void)
{
	UW psr;

	Asm("ld.w %0, %%psr": "=r"(psr));

	return psr;
}

/*
 *  �X�e�[�^�X���W�X�^(PSR)�̌��ݒl�̕ύX
 */
Inline void
set_psr(register UW psr)
{
	Asm("ld.w %%psr, %0": : "r"(psr));
}

/*
 *  �X�^�b�N�|�C���^(SP)�̌��ݒl�̓Ǐo��
 */
Inline VP
get_sp(void)
{
	VP sp;

	Asm("ld.w %0, %%sp": "=r"(sp));

	return sp;
}

/*
 *  �X�^�b�N�|�C���^(SP)�̌��ݒl�̕ύX
 */
Inline void
set_sp(VP sp)
{
	Asm("ld.w %%sp, %0": : "r"(sp));
}

/*
 *  �v���O�����J�E���^(PC)�̌��ݒl�̕ύX
 */
Inline void
set_pc(VP pc)
{
	Asm("jp %0": "=r"(pc) : "0"(pc));
}

/*
 *  �g���b�v�x�[�X���W�X�^(TTBR)�̌��ݒl�̓Ǐo��
 */
Inline VP
get_ttbr(void)
{
#ifdef __c33std
	return (VP) ((volatile s1c33Bcu_t *) S1C33_BCU_BASE)->ulTtbr;
#else
	VP ttbr;

	Asm("ld.w %0, %%ttbr": "=r"(ttbr));

	return ttbr;
#endif /* __c33std */
}

/*
 *  ���f�B�L���[�T�[�`�̂��߂̃r�b�g�}�b�v�T�[�`�֐�
 *  �r�b�g�}�b�v�̉���16�r�b�g���g�p���C�ŉ��ʃr�b�g���Œ�D��x�ɑΉ�������
 */
#ifdef CPU_BITMAP_SEARCH
Inline UINT
bitmap_search(UINT bitmap)
{
	INT offset;
	INT bit;

	Asm("swap %0, %1": "=r"(bitmap): "r"(bitmap));
	Asm("mirror %0, %1": "=r"(bitmap): "r"(bitmap));
	Asm("scan1 %0, %1": "=r"(bit): "r"(bitmap));
	if(bit != 8){
		return bit;
	}

	Asm("sll %0, %1": "=r"(bitmap): "r"(bit));
	offset = bit;
	Asm("scan1 %0, %1": "=r"(bit): "r"(bitmap));

	return offset + bit;
}
#endif	/* CPU_BITMAP_SEARCH */

#endif /* _CPU_INSN_H_ */
