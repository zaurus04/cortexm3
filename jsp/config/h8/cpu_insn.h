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
 *  @(#) $Id: cpu_insn.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

/*
 *	�v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`�iH8�p�j
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  ���䃌�W�X�^�̑���֐�
 */

/*
 *  �R���f�V�����R�[�h���W�X�^�iCCR�j�̌��ݒl�̓Ǐo��
 */
Inline UB
current_ccr(void)
{
    UB	ccr;
    Asm("stc.b ccr,%0l" : "=r"(ccr));
    return(ccr);
}

/*
 *  �R���f�V�����R�[�h���W�X�^�iCCR�j�̌��ݒl�̕ύX
 */
Inline void
set_ccr(UB ccr)
{
	Asm("ldc.b %0l, ccr" : : "r"(ccr) );
}

/*
 *  NMI���������ׂĂ̊����݂��֎~
 */
Inline void
disint(void)
{
    Asm("orc #"str_H8INT_DIS_ALL",ccr");
}

/*
 *  ���ׂĂ̊����݂�����
 */
Inline void
enaint(void)
{
    Asm("andc #"str_H8INT_ENA_ALL",ccr");
}

/*
 * �r�b�g���N���A
 */
Inline void
bitclr (UB *addr, UB bit)
{
    Asm("bclr %1l, @%0" : : "r"(addr), "r"(bit));
}

/*
 * �r�b�g���Z�b�g
 */
Inline void
bitset (UB *addr, UB bit)
{
    Asm("bset %1l, @%0" : : "r"(addr), "r"(bit));
}

#endif /* _CPU_INSN_H_ */
