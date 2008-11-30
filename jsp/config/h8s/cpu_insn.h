/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/* ���L�ɂė��p���Ă���AMAX_IPM �� cpu_config.h �Œ�` */

#ifndef _MACRO_ONLY

/*
 *  ���䃌�W�X�^�̑���֐�
 */

/* �R���f�V�����R�[�h���W�X�^�iCCR�j�̌��ݒl�̓Ǐo�� */
Inline UB current_ccr(void)
{
	UB	ccr;

	Asm( "stc.b	ccr, %0l" : "=r"(ccr) );

	return(ccr);
}

/* �R���f�B�V�����R�[�h���W�X�^�iCCR�j�̌��ݒl�̕ύX */
Inline void set_ccr(UB ccr)
{
	Asm( "ldc.b	%0l, ccr" ::"r"(ccr) );
}

/* �G�N�X�e���h���W�X�^�iEXR�j�̌��ݒl�̓Ǐo�� */
Inline UB current_exr(void)
{
	UB	exr;

	Asm( "stc.b	exr, %0l" : "=r"(exr) );

	return(exr);
}

/* �R���f�V�����R�[�h���W�X�^�iEXR�j�̌��ݒl�̕ύX */
Inline void set_exr(UB exr)
{
	Asm( "ldc.b	%0l, exr" :: "r"(exr) );
}

/*
 *  �����݃}�X�N���색�C�u���� (�����݃��[�h�Q�p)
 */

/* ���݂̊����݃}�X�N�̓Ǐo�� */
Inline IPM current_intmask(void)
{
	return(  (IPM)  (current_exr() &  EXR_I_MASK) );
}

/* �����݃}�X�N�̐ݒ� */
Inline void set_intmask(IPM intmask)
{
	set_exr( (IPM) ((current_exr() & ~EXR_I_MASK) | intmask ) );
}

/* �J�[�l���Ǘ����̂��ׂĂ̊����� �� �����݃��x����MAX_IPM �ȉ��̊����� */

/* �J�[�l���Ǘ����̂��ׂĂ̊����݂��֎~ (NMI������)  */
Inline void disint(void)
{
	/* set_intmask( (IPM) MAX_IPM ); */
	set_exr( (IPM) ((current_exr() & ~EXR_I_MASK) | MAX_IPM ) );
}

/* �J�[�l���Ǘ����̂��ׂĂ̊����݂����� (NMI������) */
/*   ���̏����́A������A�J�[�l���Ǘ����̗L�����킸�A���ׂĂ̊����݂�
     �����邱�ƂɂȂ��Ă���B */
Inline void enaint()
{
	/* set_intmask( (IPM) 0 ); */
	set_exr( (IPM)  (current_exr() & ~EXR_I_MASK) );
}

/*
 *  �����݃��b�N��Ԃ̐���p�֐�
 */

/* ���ׂĂ̊����݂��֎~ (NMI������) */
Inline void _disint_()
{
	/* set_intmask( (IPM) 7 ); */
	set_exr( (IPM) (current_exr() | EXR_I_MASK) );
}

/*
 *  �r�b�g����p�֐�
 */

/* �r�b�g�N���A */
Inline void bitclr(UW addr, UB bit)
{
	Asm( "bclr %1l, @%0" :: "r"(addr), "r"(bit) );
}

/* �r�b�g�Z�b�g */
Inline void bitset(UW addr, UB bit)
{
	Asm( "bset %1l, @%0" :: "r"(addr), "r"(bit) );
}

#endif /* _MACRO_ONLY */

#endif /* _CPU_INSN_H_ */
