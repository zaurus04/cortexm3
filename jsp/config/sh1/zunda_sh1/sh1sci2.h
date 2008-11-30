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
 *   SH1�����V���A���R�~���j�P�[�V�����C���^�t�F�[�XSCI�p �ȈՃh���C�o
 *
 *�@�@�@�@SCI0/1�T�|�[�g
 *
 *�@�@�@�@sh1sci.{c,h}��hw_serial.h�̕����̊
 *�@�@�@�@�@�@�Esh1sci.{c,h}�F�V���A���f�o�C�X�Ɉˑ����镔���̂݋L�q
 *�@�@�@�@�@�@�Ehw_serial.h�F�V���A���f�o�C�X�ȊO�ɋN�����鎖����
 *�@�@�@�@ �@�@�@�@�@�@�@�@�@hw_serial.h�ɋL�q����
 *�@�@�@�@�@�@�@�@�@�@�@�@�@�@�����݃R���g���[���ˑ��Ȃ�
 */

#ifndef _SH1SCI2_H_
#define _SH1SCI2_H_

#include <t_services.h>
#include <sh1_sil.h>

/*
 *  �V���A���|�[�g�C���^�[�t�F�[�X
 */
#define	PORT1			1
#define	PORT2			2

#define RS232C_INTERFACE	0	/* RS232C I/F�̏ꍇ�A���M������ */
#define RS485_INTERFACE		1	/* RS485 I/F�̏ꍇ�A���M������ */

/*
 *  �V���A���|�[�g�̏������u���b�N
 */
typedef struct sio_port_initialization_block {
	UW 	base;		/* SCI �̃x�[�X�A�h���X		*/
	UW	baudrate;	/* �{�[���C�g			*/	
	VH  	*ipr;		/* ���荞�݃R���g���[���A�h���X */
	UH	shift;		/* ���荞�݃R���g���[���V�t�g	*/
	UB	smr_init;	/* SMR �̐ݒ�l			*/
	UINT	delay;		/* �{�[���[�g�̐ݒ��҂�	*/
	UB	rs485if;	/* RS232C | RS485		*/
} SIOPINIB;

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 *  �@2ch�Ɋg��
 */
typedef struct sio_port_control_block {
	const SIOPINIB	*inib;		/* �����l�p�̃f�[�^ 	*/
	VP_INT		exinf;		/* �g����� 		*/
	BOOL		openflag;	/* �I�[�v���ς݃t���O 	*/
} SIOPCB;

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND	1u		/* ���M�\�R�[���o�b�N */
#define SIO_ERDY_RCV	2u		/* ��M�ʒm�R�[���o�b�N */

/*
 *  SIO�h���C�o�̏��������[�`��
 */
extern void	sh1sci_initialize(void);

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
extern BOOL	sh1sci_openflag(ID siopid);

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
extern SIOPCB	*sh1sci_opn_por(ID siopid, VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
extern void	sh1sci_cls_por(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
extern BOOL	sh1sci_snd_chr(SIOPCB *siopcb, char c);

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
extern INT	sh1sci_rcv_chr(SIOPCB *siopcb);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
extern void	sh1sci_ena_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
extern void	sh1sci_dis_cbr(SIOPCB *siopcb, UINT cbrtn);

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
extern void	sh1sci_isr_in(void);
extern void	sh1sci_isr_out(void);

/*
 *  SIO�̎�M�G���[�����݃T�[�r�X���[�`��
 */
extern void	sh1sci_isr_error(void);

/*
 *  �V���A��I/O�|�[�g����̑��M�\�R�[���o�b�N
 */
extern void	sh1sci_ierdy_snd(VP_INT exinf);

/*
 *  �V���A��I/O�|�[�g����̎�M�ʒm�R�[���o�b�N
 */
extern void	sh1sci_ierdy_rcv(VP_INT exinf);



#endif /* _SH1SCI2_H_ */
