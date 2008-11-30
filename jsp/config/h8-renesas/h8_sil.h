/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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
 *  @(#) $Id: h8_sil.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *  H8����SIL�̊g���i�r�b�g���Z�j
 *
 *  h8.h�ɋL�q����̂��G���K���g�����Asil.h�Ƃ̃C���N���[�h��
 *  ���Ԃ̊֌W�œƗ������t�@�C���Ƃ���
 *  t_config.h�𒼐ڃC���N���[�h�����Ƃ���sil.h����ɂ���
 *  �t�@�C�����C���N���[�h�����\��������B
 *
 *  �R���p�C���̌^�`�F�b�N�@�\��L���ɂ��邽�߁A�|�C���^�^��
 *  UB *�AUH *�AUW *��p���Ă���B
 *
 */

#ifndef _SIL_H8_H_
#define _SIL_H8_H_

#ifndef _MACRO_ONLY

#include <sil.h>
#include <cpu_insn.h>	/*  bitset(), bitclr()  */

/*
 *  8�r�b�g���W�X�^��AND���Z
 */
Inline void
h8_anb_reg(UB *mem, UB data)
{
        UB reg = sil_reb_mem((VP)mem);
        reg &= data;
        sil_wrb_mem((VP)mem, (VB)reg);
}

/*
 *  8�r�b�g���W�X�^��OR���Z
 */
Inline void
h8_orb_reg(UB *mem, UB data)
{
        UB reg = sil_reb_mem((VP)mem);
        reg |= data;
        sil_wrb_mem((VP)mem, (VB)reg);
}


/*
 *  16�r�b�g���W�X�^��AND���Z
 */
Inline void
h8_anh_reg(UH *mem, UH data)
{
        UH reg = sil_reh_mem((VP)mem);
        reg &= data;
        sil_wrh_mem((VP)mem, (VH)reg);
}

/*
 *  16�r�b�g���W�X�^��OR���Z
 */
Inline void
h8_orh_reg(UH *mem, UH data)
{
        UH reg = sil_reh_mem((VP)mem);
        reg |= data;
        sil_wrh_mem((VP)mem, (VH)reg);
}

/*
 *  32�r�b�g���W�X�^��AND���Z
 */
Inline void
h8_anw_reg(UW *mem, UW data)
{
        UW reg = sil_rew_mem((VP)mem);
        reg &= data;
        sil_wrw_mem((VP)mem, (VW)reg);
}

/*
 *  32�r�b�g���W�X�^��OR���Z
 */
Inline void
h8_orw_reg(UW *mem, UW data)
{
        UW reg = sil_rew_mem((VP)mem);
        reg |= data;
        sil_wrw_mem((VP)mem, (VW)reg);
}

/*
 *  �����݃��x���̐ݒ�
 *
 *  �@irc  �FIRC�f�[�^�̐擪�A�h���X
 *
 *  �@�@UB *ipr�F�ݒ肷��IPR���W�X�^�̔Ԓn
 *  �@�@UB bit �FIPR���W�X�^�̊Y������r�b�g�ԍ�
 *  �@�@IPM ipm�F�ݒ肷�銄���݃��x��
 *  �@�@�@�@�@�@�@IPM_LEVEL0,IPM_LEVEL1�̂����ꂩ
 */
Inline void
define_int_plevel(const IRC *irc)
{
        UB *ipr = irc->ipr;
        UB bit = irc->bit;
        IPM ipm = irc->ipm;

        switch(ipm) {
                case IPM_LEVEL0:        /*  �v���C�I���e�B���x��0�ɐݒ�  */
                        bitclr(ipr, bit);
                        break;
                case IPM_LEVEL1:        /*  �v���C�I���e�B���x��1�ɐݒ�  */
                        bitset(ipr, bit);
                        break;
                default:
                        assert(FALSE);
        }
}

/*
 *�@I/O�|�[�g�̃f�[�^�E�f�B���N�V�����E���W�X�^DDR�ւ̃A�N�Z�X
 *�@
 *�@�@H8��DDR�͏������ݐ�p�ł���A���̂܂܂ł͏��]�̃r�b�g������
 *�@�@�ύX���邱�Ƃ��ł��Ȃ��B�ibset,bclr���߂ł����s�j
 *�@�@���̂��߁A�{�����ł́A��������Ƀe���|������p�ӂ��āADDR��
 *�@�@���ݒl��ێ�������@���̂��Ă���B
 */
/*
 *�@DDR�̔ԍ���`
 *�@
 *�@�@�z��̃C���f�b�N�X�ɗp����B
 *�@�@�|�[�g7�͓��͐�p�̂��߁A�ȗ����Ă���B
 */
typedef enum {
	IO_PORT1,
	IO_PORT2,
	IO_PORT3,
	IO_PORT4,
	IO_PORT5,
	IO_PORT6,
	IO_PORT8,
	IO_PORT9,
	IO_PORTA,
	IO_PORTB
} IO_PORT;

extern UB sil_reb_ddr(IO_PORT port) throw();
extern void sil_wrb_ddr(IO_PORT port, UB data) throw();
extern void sil_anb_ddr(IO_PORT port, UB data) throw();
extern void sil_orb_ddr(IO_PORT port, UB data) throw();

#endif /* _MACRO_ONLY */
#endif  /*  _SIL_H8_H_  */
