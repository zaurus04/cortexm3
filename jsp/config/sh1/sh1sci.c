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
 *  @(#) $Id: sh1sci.c,v 1.1 2008/06/17 00:04:54 suikan Exp $
 */

/*
 *   SH1�����V���A���R�~���j�P�[�V�����C���^�t�F�[�XSCI�p �ȈՃh���C�o
 *�@�@�@�@
 *�@�@�@�@SCI0�݂̂̃T�|�[�g�����A2ch�ւ̊g�����͎c���Ă���B
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
#include <sh1sci.h>

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
#define SMR_CA_ASYNC	0x00u	/* 	���������� 		*/
	/*  �����������ʐM�FAsynchronous Communication method	*/
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
 *  �N���b�N���g���ˑ�
 *  	���s�}�C�N���R���s���[�^KZ-SH1-01�̃N���b�N���g����20MHz
 *  	CQ�o�� RISC�]���L�b�g SH-1�̃N���b�N���g����19.6608MHz
 *  	��Տ��sSH1/CPUB�̃N���b�N���g����16MHz
 */

/*
 *  ������ƃr�b�g���[�g�̐ݒ�
 */
#if CONFIG_BAUD == 9600
/*
 *
 *  �N���b�N	�@20MHz�̏ꍇ
 *  �r�b�g���[�g�@9600bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=64�Ō덷0.16%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=64
 */
#ifdef CONFIG_20MHZ
#define SMR_CKS 	0x0u	/*  ������  		*/
#define SCI_BRR 	64u	/*  �r�b�g���[�g  	*/
#endif

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
#ifdef CONFIG_19MHZ
#define SMR_CKS 	0x0u	/*  ������  		*/
#define SCI_BRR 	63u	/*  �r�b�g���[�g  	*/
#endif

/*
 *  �N���b�N	�@16MHz
 *  �r�b�g���[�g�@9600bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=51�Ō덷0.16%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=51
 */
#ifdef CONFIG_16MHZ
#define SMR_CKS 	0x0u	/*  ������  		*/
#define SCI_BRR 	51u	/*  �r�b�g���[�g  	*/
#endif

/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=9600bps�̏ꍇ
 *  �@t = 1 / BPS = 104,167 = 105,000[nsec]
 */
#define SH1SCI_DELAY 	105000


#elif CONFIG_BAUD == 19200


/*
 *
 *  �N���b�N	�@20MHz�̏ꍇ
 *  �r�b�g���[�g�@19200bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=32�Ō덷 -1.36%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=32
 */
#ifdef CONFIG_20MHZ
#define SMR_CKS 	0x0u	/*  ������  		*/
#define SCI_BRR 	32u	/*  �r�b�g���[�g  	*/
#endif

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
#ifdef CONFIG_19MHZ
#define SMR_CKS 	0x0u	/*  ������  		*/
#define SCI_BRR 	31u	/*  �r�b�g���[�g  	*/
#endif

/*
 *  �N���b�N	�@16MHz
 *  �r�b�g���[�g�@19200bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=25�Ō덷0.16%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=25
 */
#ifdef CONFIG_16MHZ
#define SMR_CKS 	0x0u	/*  ������  		*/
#define SCI_BRR 	25u	/*  �r�b�g���[�g  	*/
#endif

/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=19200bps�̏ꍇ
 *  �@t = 1 / BPS = 52,083 = 53,000[nsec]
 */
#define SH1SCI_DELAY 	53000


#elif CONFIG_BAUD == 38400


/*
 *
 *  �N���b�N	�@20MHz�̏ꍇ
 *  �r�b�g���[�g�@38400bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=15�Ō덷1.73%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=15
 */
#ifdef CONFIG_20MHZ
#define SMR_CKS 	0x0u	/*  ������  		*/
#define SCI_BRR 	15u	/*  �r�b�g���[�g  	*/
#endif

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
#ifdef CONFIG_19MHZ
#define SMR_CKS 	0x0u	/*  ������  		*/
#define SCI_BRR 	15u	/*  �r�b�g���[�g  	*/
#endif

/*
 *  �N���b�N	�@16MHz
 *  �r�b�g���[�g�@38400bps
 *
 *  �@n=0(�������Ȃ��̂ł��̂܂�)
 *  �@N=12�Ō덷0.16%
 *  ����āA
 *  �@�V���A�����[�h���W�X�^SMR�̃N���b�N�Z���N�g�r�b�gCKS=00
 *  �@�r�b�g���[�g���W�X�^BRR=16
 */
#ifdef CONFIG_16MHZ
#define SMR_CKS 	0x0u	/*  ������  		*/
#define SCI_BRR 	16u	/*  �r�b�g���[�g  	*/
#endif

/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=38400bps�̏ꍇ
 *  �@t = 1 / BPS = 26,042 = 27,000[nsec]
 */
#define SH1SCI_DELAY 	27000

#else	/*  CONFIG_BAUD  */

#error unsupported baud rate.

#endif 	/*  CONFIG_BAUD  */


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
 *  �@�@ID = 1 ��SCI0�ɑΉ������Ă���D
 */
static SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
				/*  �|�[�gID����f�o�C�X�ԍ������߂�}�N��  */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))

/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
sh1sci_getready(SIOPCB *siopcb)
{
	VB ssr0 = sil_reb_mem(SCI_SSR0);
	return(ssr0 & SSR_RDRF);
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
sh1sci_putready(SIOPCB *siopcb)
{
	VB ssr0 = sil_reb_mem(SCI_SSR0);
	return(ssr0 & SSR_TDRE);
}

/*
 *  ��M���������̎�o��
 */
Inline char
sh1sci_getchar(SIOPCB *siopcb)
{
	char data;

	data = sil_reb_mem(SCI_RDR0);
	
	/*  ���V�[�u�f�[�^���W�X�^�t���E�t���O�̃N���A  */
	sh1_anb_reg(SCI_SSR0, (VB)~SSR_RDRF);
	return data;
}

/*
 *  ���M���镶���̏�����
 */
Inline void
sh1sci_putchar(SIOPCB *siopcb, char c)
{
#ifdef GDB_STUB
	gdb_stub_putc( c );
#else
	sil_wrb_mem(SCI_TDR0 ,c);
	
	/*  �g�����X�~�b�g�f�[�^���W�X�^�G���v�e�B�E�t���O�̃N���A*/
	sh1_anb_reg(SCI_SSR0, (VB)~SSR_TDRE);
#endif
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
		siopcb->openflag = FALSE;
	}
}

/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
sh1sci_openflag(void)
{
#if TNUM_SIOP < 2
	return(siopcb_table[0].openflag);
#else /* TNUM_SIOP < 2 */
	return(siopcb_table[0].openflag || siopcb_table[1].openflag);
#endif /* TNUM_SIOP < 2 */
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
sh1sci_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb = get_siopcb(siopid);

#ifndef GDB_STUB
	VB scr0, smr0;
	VH pbcr1;

	sh1_anb_reg(SCI_SCR0, (VB)~(SCR_TE | SCR_RE));	/*  ����M��~  */

	/*  �s���A�T�C��
	 *     �V���A���f�o�C�X���̂̎����ł͂Ȃ��̂�
	 *     �{���͂��̃t�@�C���ɋL�q����̂͂ӂ��킵���Ȃ����A
	 *     hw_serial.c��p�ӂ���̂��ώG�Ȃ̂Ŏb��I�ɂ����ɓ���Ă���B
	 */
	pbcr1 = sil_reh_mem((VP)PBCR1);
						/* PB8:RxD0 PB9:TxD0  */
	pbcr1 = (pbcr1 & PBCR1_TD0_RD0_MASK) |
			PBCR1_TD0 | PBCR1_RD0;
	sil_wrh_mem((VP)PBCR1, pbcr1);
						/*  ����M�t�H�[�}�b�g  */
	smr0 = 	SMR_CA_ASYNC |	/*  ����������  		*/
		SMR_CHR8 |	/*  �L�����N�^�����O�X�F8�r�b�g */
		SMR_PE_NON |	/*  �p���e�B�Ȃ�  		*/
		SMR_STOP1 |	/*  �X�g�b�v�r�b�g�����O�X�F1 	*/
		SMR_CKS;	/*  �N���b�N�Z���N�g�i������j  */
	sil_wrb_mem(SCI_SMR0, smr0);
	
	sil_wrb_mem(SCI_BRR0, SCI_BRR);	/*  �{�[���[�g�ݒ�  	*/

					/*  �����݋֎~�ƃN���b�N�\�[�X�̑I�� */
	scr0 = (VB)(~(SCR_TIE | SCR_RIE | SCR_TE | SCR_RE |
			  SCR_MPIE | SCR_TEIE | SCR_CKE_MASK) | SCR_CKE);
	sil_wrb_mem(SCI_SCR0, scr0);
	
	/*
	 * �{�[���[�g�̐ݒ��A1�J�E���g���҂��Ȃ���΂Ȃ�Ȃ��B
	 */
	sil_dly_nse(SH1SCI_DELAY);

					/* �G���[�t���O���N���A	*/
	sh1_anb_reg(SCI_SSR0, (VB)~(SSR_ORER | SSR_FER | SSR_PER));
					/* ��M���荞�݋���   	*/
					/* ����M����  		*/
	sh1_orb_reg(SCI_SCR0, (SCR_RIE | SCR_TE | SCR_RE));
			/*  ���M�����݂̋��͑��M����֐��ōs��  */

#endif	/*  GDB_STUB  */

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
	sh1_anb_reg(SCI_SCR0, (VB)~(SCR_TIE | SCR_RIE | SCR_TE | SCR_RE));
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
		return((INT)(UB)sh1sci_getchar(siopcb));
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
		sh1_orb_reg(SCI_SCR0, SCR_TIE);
		break;
	case SIO_ERDY_RCV:	/* ��M���荞�ݗv�������� */
		sh1_orb_reg(SCI_SCR0, SCR_RIE);
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
		sh1_anb_reg(SCI_SCR0, (VB)~SCR_TIE);
		break;
	case SIO_ERDY_RCV:	/* ��M���荞�ݗv�����֎~ */
		sh1_anb_reg(SCI_SCR0, (VB)~SCR_RIE);
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�����ݏ���
 */
Inline void
sh1sci_isr_siop_out(SIOPCB *siopcb)
{
	VB scr0 = sil_reb_mem(SCI_SCR0);
	
	if ((scr0 & SCR_TIE) != 0 && sh1sci_putready(siopcb)) {
		/*
		 *  ���M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		sh1sci_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�����ݏ���
 */
Inline void
sh1sci_isr_siop_in(SIOPCB *siopcb)
{
	VB scr0 = sil_reb_mem(SCI_SCR0);

	if ((scr0 & SCR_RIE) != 0 && sh1sci_getready(siopcb)) {
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
		sh1sci_isr_siop_out(get_siopcb(1));
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
		sh1sci_isr_siop_in(get_siopcb(1));
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
