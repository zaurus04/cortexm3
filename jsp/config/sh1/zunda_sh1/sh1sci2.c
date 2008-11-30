/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2003-2004 by CHUO ELECTRIC WORKS Co.,LTD.
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
 *   (��)�������쏊����ITRON����SH1CPU�{�[�h�p
 *�@�@�@�@
 *   SCI0(RS232C)/SCI1(RS485)�T�|�[�g
 *
 *�@�@�@�@sh1sci.{c,h}��hw_serial.h�̕����̊
 *�@�@�@�@�@�@�Esh1sci.{c,h}�F�V���A���f�o�C�X�Ɉˑ����镔���̂݋L�q
 *�@�@�@�@�@�@�Ehw_serial.h�F�����݃R���g���[���ˑ�
 *�@�@�@�@�@�@
 *�@�@�@�@�@�@�E�N���b�N���g���ˑ��ɂ���
 *�@�@�@�@�@�@�@�@�E�f�o�C�X�ˑ��̃p�����[�^��sh1sci.c���ŗp�ӂ���B
 *�@�@�@�@�@�@�@�@�E�匳�̃N���b�N���g���̓R���p�C���I�v�V�����Ƃ��ė^����
 */

#include <s_services.h>
#include <sh1sci2.h>

/*
 *  �R���g���[�����W�X�^�̃A�h���X �i���ׂ�1�o�C�g�T�C�Y�j
 */
	/*  �`���l��0  */
#define SCI_SMR0 (VB *)0x5fffec0	/*  �V���A�����[�h���W�X�^ */
#define SCI_BRR0 (VB *)0x5fffec1	/*  �r�b�g���[�g���W�X�^  */
#define SCI_SCR0 (VB *)0x5fffec2	/*  �V���A���R���g���[�����W�X�^ */
#define SCI_TDR0 (VB *)0x5fffec3	/*  �g�����X�~�b�g�f�[�^���W�X�^ */
#define SCI_SSR0 (VB *)0x5fffec4	/*  �V���A���X�e�[�^�X���W�X�^ */
#define SCI_RDR0 (VB *)0x5fffec5	/*  ���V�[�u�f�[�^���W�X�^ */

	/*  �`���l��1  */
#define SCI_SMR1 (VB *)0x5fffec8	/*  �V���A�����[�h���W�X�^ */
#define SCI_BRR1 (VB *)0x5fffec9	/*  �r�b�g���[�g���W�X�^  */
#define SCI_SCR1 (VB *)0x5fffeca	/*  �V���A���R���g���[�����W�X�^ */
#define SCI_TDR1 (VB *)0x5fffecb	/*  �g�����X�~�b�g�f�[�^���W�X�^ */
#define SCI_SSR1 (VB *)0x5fffecc	/*  �V���A���X�e�[�^�X���W�X�^ */
#define SCI_RDR1 (VB *)0x5fffecd	/*  ���V�[�u�f�[�^���W�X�^ */

/*
 *  �R���g���[�����W�X�^�̐ݒ�l
 */
/*  �V���A���X�e�[�^�X���W�X�^SSR�̊e�r�b�g  */
#define SSR_TDRE	0x80u	/* �g�����X�~�b�g�f�[�^���W�X�^�G���v�e�B */
#define SSR_RDRF	0x40u	/* ���V�[�u�f�[�^���W�X�^�t�� 		*/
#define SSR_ORER	0x20u	/* �I�[�o�[�����G���[ 			*/
#define SSR_FER		0x10u	/* �t���[�~���O�G���[ 			*/
#define SSR_PER		0x08u	/* �p���e�B�G���[ 			*/
#define SSR_TEND	0x04u	/* �g�����X�~�b�g�G���h 		*/
#define SSR_MPB		0x02u	/* �}���`�v���Z�b�T�r�b�g 		*/
#define SSR_MPBT	0x01u	/* �}���`�v���Z�b�T�r�b�g�g�����X�t�@ 	*/

/*  �V���A���R���g���[�����W�X�^SCR�̊e�r�b�g  */
#define SCR_TIE		0x80u	/* �g�����X�~�b�g�C���^���v�g�C�l�[�u�� */
#define SCR_RIE		0x40u	/* ���V�[�u�C���^���v�g�C�l�[�u�� 	*/
#define SCR_TE		0x20u	/* �g�����X�~�b�g�C�l�[�u�� 		*/
#define SCR_RE		0x10u	/* ���V�[�u�C�l�[�u�� 			*/
#define SCR_MPIE	0x08u	/* �}���`�v���Z�b�T�C���^���v�g�C�l�[�u�� */
				/* �g�����X�~�b�g�G���h�C���^���v�g	*/
#define SCR_TEIE	0x04u	/* �C�l�[�u�� 				*/
#define SCR_CKE_MASK	0x03u	/* �N���b�N�\�[�X�I��p�}�X�N		*/
#define SCR_CKE		0x00u	/* �N���b�N�C�l�[�u��			*/
				/*   �����������̂Ƃ�  			*/
				/*   	�����N���b�N�g�p  		*/
				/*   	�o�͂Ȃ�  			*/

/*  �V���A�����[�h�W�X�^SMR�̊e�r�b�g  */
				/* �R�~���j�P�[�V�������[�h 	*/
#define SMR_CA_CLOCK	0x80u	/* 	�N���b�N������ 		*/
#define SMR_CA_ASYNC	0x00u	/* 	������������ 		*/
	/*  �����������ʐM���FAsynchronous Communication method */
				/* �L�����N�^�����O�X 		*/
#define SMR_CHR8	0x00u	/* 	8�r�b�g 		*/
#define SMR_CHR7	0x40u	/* 	7�r�b�g 		*/
				/* �p���e�B�C�l�[�u�� 		*/
#define SMR_PE		0x20u	/* 	�p���e�B���� 		*/
#define SMR_PE_NON	0x00u	/* 	�p���e�B�Ȃ� 		*/
#define SMR_OE_ODD	0x10u	/* �p���e�B���[�h�i��p���e�B�j*/
#define SMR_STOP2	0x08u	/* �X�g�b�v�r�b�g�����O�X�F2 	*/
#define SMR_STOP1	0x00u	/* �X�g�b�v�r�b�g�����O�X�F1 	*/
#define SMR_MP		0x04u	/* �}���`�v���Z�b�T���[�h 	*/

/*
 *  �V���A���R���g���[�����W�X�^�̃x�[�X����̃I�t�Z�b�g
 */
#define SMR (VB *)0x0	/*  �V���A�����[�h���W�X�^ */
#define BRR (VB *)0x1	/*  �r�b�g���[�g���W�X�^  */
#define SCR (VB *)0x2	/*  �V���A���R���g���[�����W�X�^ */
#define TDR (VB *)0x3	/*  �g�����X�~�b�g�f�[�^���W�X�^ */
#define SSR (VB *)0x4	/*  �V���A���X�e�[�^�X���W�X�^ */
#define RDR (VB *)0x5	/*  ���V�[�u�f�[�^���W�X�^ */

/*
 *  �N���b�N���g���ˑ�
 *  �N���b�N���g����19.6608MHz
 */
/*
 *  �`���l��0:������ƃr�b�g���[�g�̐ݒ�
 */
#if CONFIG_BAUD == 9600
/*
 *  �N���b�N	�@19.6608MHz
 *  �r�b�g���[�g�@9600bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=63�Ō덷0%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=63
 */
#define SMR_CKS_0 	0x0u	/*  ������  		*/
#define SCI_BRR_0 	63u	/*  �r�b�g���[�g  	*/
/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=9600bps�̏ꍇ
 *  �@t = 1 / BPS = 104,167 = 105,000[nsec]
 */
#define SH1SCI_DELAY0 	105000

#elif CONFIG_BAUD == 19200
/*
 *  �N���b�N	�@19.6608MHz
 *  �r�b�g���[�g�@19200bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=31�Ō덷0%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=31
 */
#define SMR_CKS_0 	0x0u	/*  ������  		*/
#define SCI_BRR_0 	31u	/*  �r�b�g���[�g  	*/
/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=19200bps�̏ꍇ
 *  �@t = 1 / BPS = 52,083 = 53,000[nsec]
 */
#define SH1SCI_DELAY0 	53000

#elif CONFIG_BAUD == 38400
/*
 *  �N���b�N	�@19.6608MHz
 *  �r�b�g���[�g�@38400bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=15�Ō덷0%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=15
 */
#define SMR_CKS_0 	0x0u	/*  ������  		*/
#define SCI_BRR_0 	15u	/*  �r�b�g���[�g  	*/
/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=38400bps�̏ꍇ
 *  �@t = 1 / BPS = 26,042 = 27,000[nsec]
 */
#define SH1SCI_DELAY0 	27000

#else	/*  CONFIG_BAUD  */
#error chanel0 is unsupported baud rate.

#endif 	/*  CONFIG_BAUD  */


/*
 *  �`���l��1:������ƃr�b�g���[�g�̐ݒ�
 */
#if CONFIG_BAUD_2 == 9600
/*
 *  �N���b�N	�@19.6608MHz
 *  �r�b�g���[�g�@9600bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=63�Ō덷0%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=63
 */
#define SMR_CKS_1 	0x0u	/*  ������  		*/
#define SCI_BRR_1 	63u	/*  �r�b�g���[�g  	*/
/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=9600bps�̏ꍇ
 *  �@t = 1 / BPS = 104,167 = 105,000[nsec]
 */
#define SH1SCI_DELAY1 	105000

#elif CONFIG_BAUD_2 == 19200
/*
 *  �N���b�N	�@19.6608MHz
 *  �r�b�g���[�g�@19200bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=31�Ō덷0%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=31
 */
#define SMR_CKS_1 	0x0u	/*  ������  		*/
#define SCI_BRR_1 	31u	/*  �r�b�g���[�g  	*/
/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=19200bps�̏ꍇ
 *  �@t = 1 / BPS = 52,083 = 53,000[nsec]
 */
#define SH1SCI_DELAY1 	53000

#elif CONFIG_BAUD_2 == 38400
/*
 *  �N���b�N	�@19.6608MHz
 *  �r�b�g���[�g�@38400bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=15�Ō덷0%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=15
 */
#define SMR_CKS_1 	0x0u	/*  ������  		*/
#define SCI_BRR_1 	15u	/*  �r�b�g���[�g  	*/
/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=38400bps�̏ꍇ
 *  �@t = 1 / BPS = 26,042 = 27,000[nsec]
 */
#define SH1SCI_DELAY1 	27000

#else	/*  CONFIG_BAUD  */
#error chanel1 is unsupported baud rate.

#endif 	/*  CONFIG_BAUD  */

/*
 *  �V���A���|�[�g�̏������u���b�N
 */
static const SIOPINIB siopinib_table[TNUM_PORT] = 
{

#if TNUM_PORT == 1

	{
		(UW)SCI_SMR0,
		SCI_BRR_0,
		IPRD,
		0,
		(SMR_CA_ASYNC | SMR_CHR8 | SMR_PE_NON | SMR_STOP1 | SMR_CKS_0),
		SH1SCI_DELAY0,
		RS232C_INTERFACE,
	},

#elif TNUM_PORT == 2	/* of #if TNUM_PORT == 1 */

	{
		(UW)SCI_SMR0,
		SCI_BRR_0,
		IPRD,
		0,
		(SMR_CA_ASYNC | SMR_CHR8 | SMR_PE_NON | SMR_STOP1 | SMR_CKS_0),
		SH1SCI_DELAY0,
		RS232C_INTERFACE,
	},
	{
		(UW)SCI_SMR1,
		SCI_BRR_1,
		IPRE,
		12,
		(SMR_CA_ASYNC | SMR_CHR8 | SMR_PE_NON | SMR_STOP1 | SMR_CKS_1),
		SH1SCI_DELAY1,
		RS485_INTERFACE,
	},

#endif	/* of #if TNUM_PORT == 1 */

};

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 *  �@�@ID = 1 ��SCI0�ɑΉ������Ă���D
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
sh1sci_getready(SIOPCB *siopcb)
{
	VB ssr = sil_reb_mem(siopcb->inib->base + SSR);
	return(ssr & SSR_RDRF);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
sh1sci_putready(SIOPCB *siopcb)
{
	VB ssr = sil_reb_mem(siopcb->inib->base + SSR);
	return(ssr & SSR_TDRE);
}

/*
 *  ��M���������̎�o��
 */
Inline char
sh1sci_getchar(SIOPCB *siopcb)
{
	char data;

	data = sil_reb_mem(siopcb->inib->base + RDR);
	
	/*  ���V�[�u�f�[�^���W�X�^�t���E�t���O�̃N���A  */
	sh1_anb_reg(siopcb->inib->base + SSR, (VB)~SSR_RDRF);
	return data;
}

/*
 *  ���M���镶���̏�����
 */
Inline void
sh1sci_putchar(SIOPCB *siopcb, char c)
{
	if (siopcb->inib->rs485if) {
		if (!(sil_reh_mem(PB_DR) & PB_TXE1)) {
			sh1_orh_reg(PB_DR, PB_TXE1);	/* TXENA ON 		*/
			sil_dly_nse(5000);		/* 5us �ی쎞��		*/
		}
		sil_wrb_mem(siopcb->inib->base + TDR ,c);
		/*  �g�����X�~�b�g�f�[�^���W�X�^�G���v�e�B�E�t���O�̃N���A*/
		sh1_anb_reg(siopcb->inib->base + SSR, (VB)~SSR_TDRE);
		/*  TXENA OFF����̂��߁A�̃R�[���o�b�N�̋��� */
		sh1sci_ena_cbr(siopcb, SIO_ERDY_SND);
	} else {
#ifdef GDB_STUB
		gdb_stub_putc( c );
#else
		sil_wrb_mem(siopcb->inib->base + TDR ,c);

		/*  �g�����X�~�b�g�f�[�^���W�X�^�G���v�e�B�E�t���O�̃N���A*/
		sh1_anb_reg(siopcb->inib->base + SSR, (VB)~SSR_TDRE);
#endif
	}
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
sh1sci_initialize(void)
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->inib     = &siopinib_table[i];
		siopcb->openflag = FALSE;
	}
}

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
sh1sci_openflag(ID siopid)
{
	SIOPCB *siopcb;

	siopcb = get_siopcb(siopid);
	return (siopcb->openflag);
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
sh1sci_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb = get_siopcb(siopid);
	VB scr, smr;
	VH pbcr1;

#ifdef GDB_STUB
	if (siopid == PORT1) {
		siopcb->exinf = exinf;
		siopcb->openflag = TRUE;
		return(siopcb);
	}
#endif	/*  GDB_STUB  */

	sh1_anb_reg(siopcb->inib->base + SCR, (VB)~(SCR_TE | SCR_RE));	/*  ����M��~  */

	/*  �s���A�T�C��
	 *     �V���A���f�o�C�X���̂̎����ł͂Ȃ��̂�
	 *     �{���͂��̃t�@�C���ɋL�q����̂͂ӂ��킵���Ȃ����A
	 *     hw_serial.c��p�ӂ���̂��ώG�Ȃ̂Ŏb��I�ɂ����ɓ���Ă���B
	 */
	pbcr1 = sil_reh_mem((VP)PBCR1);
	if (siopid == PORT1) {	/* PB08:RxD0 PB09:TxD0  */
		pbcr1 = (pbcr1 & PBCR1_TD0_RD0_MASK) | PBCR1_TD0 | PBCR1_RD0;
	} else {		/* PB10:RxD1 PB11:TxD1  */
		pbcr1 = (pbcr1 & PBCR1_TD1_RD1_MASK) | PBCR1_TD1 | PBCR1_RD1;
	}
	sil_wrh_mem((VP)PBCR1, pbcr1);
	
						/*  ����M�t�H�[�}�b�g  */
	smr = siopcb->inib->smr_init;

	sil_wrb_mem(siopcb->inib->base + SMR, smr);
	
	sil_wrb_mem(siopcb->inib->base + BRR, (UB)siopcb->inib->baudrate);	/*  �{�[���[�g�ݒ�  	*/

					/*  �����݋֎~�ƃN���b�N�\�[�X�̑I�� */
	scr = (VB)(~(SCR_TIE | SCR_RIE | SCR_TE | SCR_RE |
			  SCR_MPIE | SCR_TEIE | SCR_CKE_MASK) | SCR_CKE);
	sil_wrb_mem(siopcb->inib->base + SCR, scr);
	
	/*
	 * �{�[���[�g�̐ݒ��A1�J�E���g���҂��Ȃ���΂Ȃ�Ȃ��B
	 */
	sil_dly_nse(siopcb->inib->delay);

					/* �G���[�t���O���N���A	*/
	sh1_anb_reg(siopcb->inib->base + SSR, (VB)~(SSR_ORER | SSR_FER | SSR_PER));
					/* ��M���荞�݋���   	*/
					/* ����M����  		*/
	sh1_orb_reg(siopcb->inib->base + SCR, (SCR_RIE | SCR_TE | SCR_RE));
			/*  ���M�����݂̋��͑��M����֐��ōs��  */

	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
sh1sci_cls_por(SIOPCB *siopcb)
{
				/*  ����M��~�A�����݋֎~ 	*/
	sh1_anb_reg(siopcb->inib->base + SCR, (VB)~(SCR_TIE | SCR_RIE | SCR_TE | SCR_RE));
	
	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
sh1sci_snd_chr(SIOPCB *siopcb, char c)
{
	if (sh1sci_putready(siopcb)) {
		sh1sci_putchar(siopcb, c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
sh1sci_rcv_chr(SIOPCB *siopcb)
{
	if (sh1sci_getready(siopcb)) {
		return((INT)(UB) sh1sci_getchar(siopcb));
		/*  (UB)�ŃL���X�g����̂̓[���g���ɂ��邽��  */
	}
	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
sh1sci_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:	/* ���M���荞�ݗv�������� */
		sh1_orb_reg(siopcb->inib->base + SCR, SCR_TIE);
		break;
	case SIO_ERDY_RCV:	/* ��M���荞�ݗv�������� */
		sh1_orb_reg(siopcb->inib->base + SCR, SCR_RIE);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
sh1sci_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	switch (cbrtn) {
	case SIO_ERDY_SND:	/* ���M���荞�ݗv�����֎~ */
		sh1_anb_reg(siopcb->inib->base + SCR, (VB)~SCR_TIE);
		if (siopcb->inib->rs485if) {
				/* ���M�I�����荞�݋��� */
			sh1_orb_reg(siopcb->inib->base + SCR, SSR_TEND);
		}
		break;
	case SIO_ERDY_RCV:	/* ��M���荞�ݗv�����֎~ */
		sh1_anb_reg(siopcb->inib->base + SCR, (VB)~SCR_RIE);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�����ݏ���
 */
Inline void
sh1sci_isr_siop_out(SIOPCB *siopcb)
{
	VB scr = sil_reb_mem(siopcb->inib->base + SCR);
	
	if ((scr & SCR_TIE) != 0 && sh1sci_putready(siopcb)) {
		/*
		 *  ���M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sh1sci_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�I�������ݏ���
 */
Inline void
sh1sci_isr_siop_tend(SIOPCB *siopcb)
{
	/*
 	 * RS485 ���M�֎~����
 	 */
	sh1_anb_reg(siopcb->inib->base + SCR, (VB)~SSR_TEND);
	sh1_anh_reg(PB_DR, ~PB_TXE1);	/* txena�|�[�g�֎~ */
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�����ݏ���
 */
Inline void
sh1sci_isr_siop_in(SIOPCB *siopcb)
{
	VB scr = sil_reb_mem(siopcb->inib->base + SCR);

	if ((scr & SCR_RIE) != 0 && sh1sci_getready(siopcb)) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sh1sci_ierdy_rcv(siopcb->exinf);
	}
}

/*
 *  SIO���M�����݃T�[�r�X���[�`��
 *  
 *  �@SH1������SCI�ł͊����ݔԍ�������M�ʁA�`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI0�̑��M�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  
 */
void
sh1sci_isr_out(void)
{
	if (siopcb_table[0].openflag) {
		sh1sci_isr_siop_out(&(siopcb_table[0]));
	}
}

/*
 *  SIO��M�����݃T�[�r�X���[�`��
 *  
 *  �@SH1������SCI�ł͊����ݔԍ�������M�ʁA�`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI0�̎�M�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  
 */
void
sh1sci_isr_in(void)
{
	if (siopcb_table[0].openflag) {
		sh1sci_isr_siop_in(&(siopcb_table[0]));
	}
}

/*
 *  SIO��M�G���[�����݃T�[�r�X���[�`��
 *  
 *  �@SH1������SCI�ł͊����ݔԍ����`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI0�̎�M�G���[�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  �@
 *  �@�G���[�������̂̓G���[�t���O�̃N���A�݂̂ɂƂǂ߂Ă���B
 *  �@�@�@�E�I�[�o�[�����G���[
 *  �@�@�@�E�t���[�~���O�G���[
 *  �@�@�@�E�p���e�B�G���[
 */
void
sh1sci_isr_error(void)
{
	VB ssr0;
	
	if (siopcb_table[0].openflag) {
		ssr0 = sil_reb_mem(SCI_SSR0);	/*  1�x�ǂݏo����  */
		ssr0 &= ~(SSR_RDRF | SSR_ORER | SSR_FER | SSR_PER);
		sil_wrb_mem(SCI_SSR0, ssr0);	/*  �G���[�t���O�N���A  */
	}
}

/*
 * �|�[�����O�ɂ�镶���̑��M
 */
void
sh1sci_putc_pol(char c)
{
	while(!sh1sci_putready(&siopcb_table[0]));
	sh1sci_putchar(&siopcb_table[0], c);
}

/* �V���A���Q������	*/
#if TNUM_SIOP >= 2
/*
 *  SIO���M�����݃T�[�r�X���[�`��
 *  
 *  �@SH1������SCI�ł͊����ݔԍ�������M�ʁA�`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI1�̑��M�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  
 */
void
sh1sci2_isr_out(void)
{
	if (siopcb_table[1].openflag) {
		sh1sci_isr_siop_out(&(siopcb_table[1]));
	}
}

/*
 *  SIO���M�I�������݃T�[�r�X���[�`��
 *  
 *  �@SH1������SCI�ł͊����ݔԍ�������M�ʁA�`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI1�̑��M�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  
 */
void
sh1sci2_isr_tend(void)
{
	if (siopcb_table[1].openflag) {
		sh1sci_isr_siop_tend(&(siopcb_table[1]));
	}
}

/*
 *  SIO��M�����݃T�[�r�X���[�`��
 *  
 *  �@SH1������SCI�ł͊����ݔԍ�������M�ʁA�`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI0�̎�M�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  
 */
void
sh1sci2_isr_in(void)
{
	if (siopcb_table[1].openflag) {
		sh1sci_isr_siop_in(&(siopcb_table[1]));
	}
}

/*
 *  SIO��M�G���[�����݃T�[�r�X���[�`��
 *  
 *  �@SH1������SCI�ł͊����ݔԍ����`���l���ʂɕ�����Ă���̂ŁA
 *  �@SCI0�̎�M�G���[�����݈ȊO�ł��̃��[�`�����Ă΂�邱�Ƃ͂Ȃ�
 *  �@
 *  �@�G���[�������̂̓G���[�t���O�̃N���A�݂̂ɂƂǂ߂Ă���B
 *  �@�@�@�E�I�[�o�[�����G���[
 *  �@�@�@�E�t���[�~���O�G���[
 *  �@�@�@�E�p���e�B�G���[
 */
void
sh1sci2_isr_error(void)
{
	VB ssr1;
	
	if (siopcb_table[1].openflag) {
		ssr1 = sil_reb_mem(SCI_SSR1);	/*  1�x�ǂݏo����  */
		ssr1 &= ~(SSR_RDRF | SSR_ORER | SSR_FER | SSR_PER);
		sil_wrb_mem(SCI_SSR1, ssr1);	/*  �G���[�t���O�N���A  */
	}
}

/*
 * �|�[�����O�ɂ�镶���̑��M
 */
void
sh1sci2_putc_pol(char c)
{
	while(!sh1sci_putready(&siopcb_table[1]));
	sh1sci_putchar(&siopcb_table[1], c);
}

#endif /* TNUM_SIOP = 2 */
