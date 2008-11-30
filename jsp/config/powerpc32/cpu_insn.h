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
 *  @(#) $Id: cpu_insn.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *	�v���Z�b�T�̓��ꖽ�߂̃C�����C���֐���`�iPowerPC�p�j
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  ���䃌�W�X�^�̑���֐�
 */

/*
 *  �}�V���X�e�[�^�X���W�X�^�iMSR�j�̌��ݒl�̓Ǐo��
 */
Inline UW
current_msr(void)
{
	UW msr;
	Asm("mfmsr %0" : "=r"(msr));
	return(msr);
}


/*
 *  �}�V���X�e�[�^�X���W�X�^�iMSR�j�̌��ݒl�̕ύX
 */
Inline void
set_msr(UW msr)
{
	Asm("mtmsr %0" : : "r"(msr) );
}


/*
 *  NMI���������ׂĂ̊����݂��֎~
 */
Inline void
disint(void)
{
#if !defined(IBM_PPC_EMB_ENV)
	/*  
	 *   �I���W�i����PowerPC�A�[�L�e�N�`���̏ꍇ
	 *   �@�@���g���[��MPC�V���[�Y�AIPM PowerPC6xx/7xx�V���[�Y��
	 *   �@�@������ɊY������B
	 */   
	UW msr;
	
	msr = current_msr();
	msr |= MSR_EE;
	msr ^= MSR_EE;
	set_msr(msr);

#else	/*  IBM_PPC_EMB_ENV  */
	/*  
	 *   The IBM PowerPC Embedded Environment�̏ꍇ
	 *   �@IBM�nPowerPC40x�V���[�Y�Ή�
	 *   �@�@wrteei���߂Œ���EE�r�b�g���N���A�ł���B
	 */   
	Asm("wrteei 0" : );	/*  MSR.EE��0  */

#endif	/*  IBM_PPC_EMB_ENV  */
}


/*
 *  �����݂�����
 */
Inline void
enaint()
{
#if !defined(IBM_PPC_EMB_ENV)
	/*  
	 *   �I���W�i����PowerPC�A�[�L�e�N�`���̏ꍇ
	 *   �@�@���g���[��MPC�V���[�Y�AIPM PowerPC6xx/7xx�V���[�Y��
	 *   �@�@������ɊY������B
	 */   
	UW msr;
	
	msr = current_msr();
	msr |= MSR_EE;
	set_msr(msr);

#else	/*  IBM_PPC_EMB_ENV  */
	/*  
	 *   The IBM PowerPC Embedded Environment�̏ꍇ
	 *   �@IBM�nPowerPC40x�V���[�Y�Ή�
	 *   �@�@wrteei���߂Œ���EE�r�b�g���Z�b�g�ł���B
	 */   
	Asm("wrteei 1" : );	/*  MSR.EE��1  */

#endif	/*  IBM_PPC_EMB_ENV  */
}


/*
 *  �X�y�V�����E�p�[�p�X�E�X���W�X�^�iSPR�j�̌��ݒl�̓Ǐo��
 *     no :���W�X�^�ԍ�
 *     dst:�ǂݏo�����l���i�[����ϐ�
 */

#define _current_spr(no, dst)	Asm("mfspr %0," #no : "=r"(dst))
#define current_spr(no, dst)	_current_spr(no, dst)


/*
 *  �X�y�V�����E�p�[�p�X�E�X���W�X�^�iSPR�j�̌��ݒl�̕ύX
 *     no :���W�X�^�ԍ�
 *     src:�ݒ肷��l
 */
#define set_spr(no, src)	_set_spr(no, src)
#define _set_spr(no, src)	Asm("mtspr "#no", %1" : : "r"(src) )

/*
 *  SPRG0�̌��ݒl�̓Ǐo��
 */
Inline UW
current_sprg0()
{
    UW sprg0;
    
    current_spr(SPRG0, sprg0);	/*  sprg0 �� SPRG0  */
    return(sprg0);
}



/*
 *  ���f�B�L���[�T�[�`�̂��߂̃r�b�g�}�b�v�T�[�`�֐�
 *
 *�@�@�@���ˑ����ŗp�ӂ���֐��𗘗p����̂�
 *�@�@CPU_BITMAP_SEARCH�}�N���͒�`���Ȃ�
 */


#endif /* _CPU_INSN_H_ */
/*  end of file  */
