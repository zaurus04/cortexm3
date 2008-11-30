/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2003 by Industrial Technology Institute,
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
 *  @(#) $Id: smc.c,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *   �V���A���h���C�o�̃T���v��
 *
 *�@�@�@�@smc.{c,h}��hw_serial.h�̕����̊
 *�@�@�@�@�@�@�Esmc.{c,h}�F�V���A���f�o�C�X�Ɉˑ����镔���̂݋L�q
 *�@�@�@�@�@�@�Ehw_serial.h�F�����݃R���g���[���ˑ�
 */

#include <s_services.h>
#include <smc.h>

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 *  �@2ch�T�|�[�g�Ɋg������ꍇ�͏����l�p�̃f�[�^���܂߂�
 */
struct sio_port_control_block {
	VP_INT		exinf;		/* �g����� */
	BOOL		openflag;	/* �I�[�v���ς݃t���O */
};

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 *  �@�@ID = 1 ��SMC1�ɑΉ������Ă���D
 */
static SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))


/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
smc_getready(SIOPCB *siopcb)
{
	return(TRUE);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
smc_putready(SIOPCB *siopcb)
{
	return(TRUE);
}

/*
 *  ��M���������̎�o��
 */
Inline char
smc_getchar(SIOPCB *siopcb)
{
    	return((char)0);
}

/*
 *  ���M���镶���̏�����
 */
Inline void
smc_putchar(SIOPCB *siopcb, char c)
{
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
smc_initialize()
{
}


/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
smc_openflag(void)
{
	return(TRUE);
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
smc_opn_por(ID siopid, VP_INT exinf)
{
	return((SIOPCB *)0);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
smc_cls_por(SIOPCB *siopcb)
{
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
smc_snd_chr(SIOPCB *siopcb, char c)
{
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
smc_rcv_chr(SIOPCB *siopcb)
{
	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
smc_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
smc_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�����ݏ���
 */
Inline void
smc_isr_siop_out(SIOPCB *siopcb)
{
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�����ݏ���
 */
Inline void
smc_isr_siop_in(SIOPCB *siopcb)
{
}

/*
 *  SIO���M�����݃T�[�r�X���[�`��
 *  
 *  �@����M����
 *  
 */
void
smc_isr()
{
}

/*
 * �|�[�����O�ɂ�镶���̑��M
 */
void
smc_putc_pol(char c)
{
}

/*  end of file  */
