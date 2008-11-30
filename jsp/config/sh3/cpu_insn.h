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
 *  @(#) $Id: cpu_insn.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *  �v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`�iSH3/4�p�j
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_


/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̌��ݒl�̓Ǐo��
 */
Inline UW
current_sr(void)
{
    UW	sr;
    Asm("stc  sr,%0" : "=r"(sr));
    return(sr);
}


/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̌��ݒl�̕ύX
 */
Inline void
set_sr(UW sr)
{
	Asm("ldc %0, sr" : : "r"(sr) );
}


/*
 *  NMI���������ׂĂ̊����݂��֎~
 */
Inline void
disint(void)
{
    set_sr((current_sr() & ~0x000000f0) |  MAX_IPM << 4 );
}


/*
 *  ���ׂĂ̊����݂�����
 */
Inline void
enaint()
{
    set_sr(current_sr() & ~0x000000f0);
}

/*
 *  �x�N�^�x�[�X���W�X�^�iVBR�j�̌��ݒl�̓Ǐo��
 */
Inline VP
current_vbr(void)
{
    VP	vbr;
	Asm("stc vbr,%0" : "=r"(vbr));
	return(vbr);
}


/*
 *  �x�N�^�x�[�X���W�X�^�iVBR�j�̐ݒ�
 */
Inline void
set_vbr(VP vbr)
{
    Asm("ldc  %0, vbr" : : "r"(vbr) );
}


#endif /* _CPU_INSN_H_ */



