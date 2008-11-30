/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2003-2004 by CHUO ELECTRIC WORKS Co.,LTD. JAPAN
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
/*
 *	�^�[�Q�b�g�V�X�e���ˑ����W���[��
 *	(��)�������쏊����ITRON����SH1CPU�{�[�h�p
 */
 
#include <s_services.h>
#include "kernel_id.h"

#include <sh1.h>
#include "sys_support.h"

/*
 *  TINET�g�p��
 */
#ifdef	SUPPORT_INET4
#include <sh1_sil.h>
#include <tinet_sys_config.h>
/*
 *  NIC (RTL8019AS) �Ɋւ����`
 *  TINET�g�p��tinet_sys_config.h �ֈړ����邱��
 */
/*#define ED_BASE_ADDRESS	0x06000000	*/	/* NIC �̃��W�X�^�x�[�X�A�h���X */
/*#define INHNO_IF_ED		IRQ5		*/	/* IRQ5 */
/*#define ED_PRI		7		*/	/* �D��x=7 */
/*#define ED_LEVEL0		0		*/	/* �����݋֎~  */
/*#define ED_IPR		IPRB		*/	/* �D��x���W�X�^�� */
/*#define ED_IPR_SHIFT		8		*/	/* �D��x���W�X�^���r�b�g�ʒu */
#endif	/* SUPPORT_INET4 */

/*
 *  ROMICE�g�p��NMI�܂ł�ROM�x�N�^�e�[�u���̈�
 */
#define ROMVECT_START	0			/* ROM�̃x�N�^�e�[�u���͂O�Ԓn���� 	*/
#define ROMVECT_SIZE	((NMI+1)*sizeof(FP))	/* ROM�̃x�N�^�e�[�u���T�C�Y 		*/

/*
 *  �჌�x���̃^�[�Q�b�g�V�X�e���ˑ��̏����� _hardware_init_hook
 *
 *  �X�^�[�g�A�b�v���W���[���̒��ŁC�������̏������̑O�ɌĂяo�����D
 */
void
hardware_init_hook(void)
{
	/* WCR3:�E�G�C�g�R���g���[�����W�X�^�R
	 * WPU=1    WAIT�[�q�v���A�b�v
	 * A02LW=00 �G���A0,2��1�ݸ޳���
	 * A6LW=00  �G���A6  ��1�ݸ޳���
	 */
	sil_wrh_mem(BSC_WCR3, 0x8000); 
	
	/* BCR:�o�X�R���g���[�����W�X�^
	 * DRANE=0   �ر1�͊O�����������
	 * IOE=0     �ر6�͊O�����������
	 * WARP=0    ɰ��Ӱ��:�O�������Ɠ��������𓯎��ɍs��Ȃ�
	 * RDDTY=0   RD�M��HI T1��50%
	 * BAS=0     WRH,WRL,A0�M���L��
	 */
	sil_wrh_mem(BSC_BCR, 0x0000);
	
	/* WCR1:�E�G�C�g�R���g���[�����W�X�^�P
	 * read cycle state��
	 * wait�[�q�T���v�����Ȃ�
	 * RWx=0  �G���A1,3,4,5,7 1�ðČŒ�
	 * RWx=0  �G���A0,2,6 1�ð�+�ݸ޳��āi�v3�ðāj
	 * WW1=1  �G���A1�O����� 2�ð�
	 */
	sil_wrh_mem(BSC_WCR1, 0x00ff);
	
	/* WCR2:�E�G�C�g�R���g���[�����W�X�^�Q
	 * DMA�Ȃ��̂ŏ����l�̂܂�
	 */
	sil_wrh_mem(BSC_WCR2, 0xffff); 
	
	/*
	 * �o�`�A�o�a�o�̓o�b�t�@������
	 */
	sil_wrh_mem(PA_DR, VAL_PA_DR);
	sil_wrh_mem(PB_DR, VAL_PB_DR); 

	/*
	 * �o�`���o�͏������isys_support.h�Q�Ɓj
	 */
	sil_wrh_mem(PFC_PACR1, VAL_PFC_PACR1);
	sil_wrh_mem(PFC_PACR2, VAL_PFC_PACR2);
                                        
	sil_wrh_mem(PFC_PAIOR, VAL_PFC_PAIOR);
                    
	sil_wrh_mem(PFC_PBCR1, VAL_PFC_PBCR1);
	sil_wrh_mem(PFC_PBCR2, VAL_PFC_PBCR2);
	sil_wrh_mem(PFC_PBIOR, VAL_PFC_PBIOR);

	sil_wrh_mem(PFC_CASCR, VAL_PFC_CASCR);

}

/*
 *  �\�t�g�E�F�A���i���Ƀ��C�u�����j�Ɉˑ����ĕK�v�ȏ��������� software_init_hook
 *
 *  �X�^�[�g�A�b�v���W���[���̒��ŁC�J�[�l�����N������O�ɌĂяo�����D
 */
#ifdef	PARTNER
void
software_init_hook(void)
{
	/*
	 *  ROMICE�g�p����ROM�x�N�^�e�[�u����]��
	 */
	extern FP vector_table[];
	memcpy(vector_table, ROMVECT_START, ROMVECT_SIZE);
}
#endif

/*
 *  NIC �n�[�h�E�F�A���荞�݋���
 *  TINET�g�p���K�v
 */
#ifdef	SUPPORT_INET4
void
ed_ena_inter(void)
{
	SIL_PRE_LOC;
	SIL_LOC_INT();
	define_int_plevel(ED_IPR, ED_PRI, ED_IPR_SHIFT);// �D��x=ED_PRI
	SIL_UNL_INT();
}

/*
 *  NIC �n�[�h�E�F�A���荞�݋֎~
 *  TINET�g�p���K�v
 */
void
ed_dis_inter(void)
{
	SIL_PRE_LOC;
	SIL_LOC_INT();
	define_int_plevel(ED_IPR, ED_LEVEL0, ED_IPR_SHIFT);// �D��x=0
	SIL_UNL_INT();
}
#endif	/* SUPPORT_INET4 *//* end */

