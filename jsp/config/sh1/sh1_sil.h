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
 *  @(#) $Id: sh1_sil.h,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */

/*
 *  SH1�����̐��䃌�W�X�^�ւ̃A�N�Z�X�E���[�e�B���e�B�i�r�b�g���Z�j
 *  
 *  sh1.h�ɋL�q����̂��G���K���g�����Asil.h�Ƃ̃C���N���[�h��
 *  ���Ԃ̊֌W�œƗ������t�@�C���Ƃ���
 *  t_config.h�𒼐ڃC���N���[�h�����Ƃ���sil.h����ɂ���
 *  �t�@�C�����C���N���[�h�����\��������B
 *  
 *  �R���p�C���̌^�`�F�b�N�@�\��L���ɂ��邽�߁A�|�C���^�^��
 *  VB *�AVH *�AVW *��p���Ă���B
 *  
 */

#ifndef _SIL_SH1_H_
#define _SIL_SH1_H_

#ifndef _MACRO_ONLY

/*
 *  8�r�b�g���W�X�^��AND���Z
 */
Inline void
sh1_anb_reg(VB *mem, VB data)
{
	VB reg = sil_reb_mem((VP)mem);
	reg &= data;
	sil_wrb_mem((VP)mem, reg);
}

/*
 *  8�r�b�g���W�X�^��OR���Z
 */
Inline void
sh1_orb_reg(VB *mem, VB data)
{
	VB reg = sil_reb_mem((VP)mem);
	reg |= data;
	sil_wrb_mem((VP)mem, reg);
}


/*
 *  16�r�b�g���W�X�^��AND���Z
 */
Inline void
sh1_anh_reg(VH *mem, VH data)
{
	VH reg = sil_reh_mem((VP)mem);
	reg &= data;
	sil_wrh_mem((VP)mem, reg);
}

/*
 *  16�r�b�g���W�X�^��OR���Z
 */
Inline void
sh1_orh_reg(VH *mem, VH data)
{
	VH reg = sil_reh_mem((VP)mem);
	reg |= data;
	sil_wrh_mem((VP)mem, reg);
}

/*
 *  32�r�b�g���W�X�^��AND���Z
 */
Inline void
sh1_anw_reg(VW *mem, VW data)
{
	VW reg = sil_rew_mem((VP)mem);
	reg &= data;
	sil_wrw_mem((VP)mem, reg);
}

/*
 *  32�r�b�g���W�X�^��OR���Z
 */
Inline void
sh1_orw_reg(VW *mem, VW data)
{
	VW reg = sil_rew_mem((VP)mem);
	reg |= data;
	sil_wrw_mem((VP)mem, reg);
}


/*
 *  ���荞�݃��x���̐ݒ�
 *  
 *  �@mem  �F�ύX���郌�W�X�^�̔Ԓn
 *  �@level�F�ݒ肷�銄���݃��x��
 *  �@shift�F���r�b�g���V�t�g�����Ƃ��낪�Y���������
 *  
 */
Inline void
define_int_plevel(VH *mem, UW level, UINT shift)
{
	VH reg = sil_reh_mem((VP)mem);
	reg = (VH)((reg & ~(0xfu << shift)) | (level << shift));
	sil_wrh_mem((VP)mem, reg);
}



#endif /* _MACRO_ONLY */
#endif	/*  _SIL_SH1_H_  */
