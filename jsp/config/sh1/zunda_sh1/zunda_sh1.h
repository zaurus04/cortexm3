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
 *  (��)�������쏊����ITRON����SH1CPU�{�[�h�p
 *  �n�[�h�E�F�A�����̒�`
 */

#ifndef _ZUNDA_SH1_H_
#define _ZUNDA_SH1_H_

/* �r�b�h�`���l���O */
#if 0 /* sh1sci2.c�ɒ�`����Ă��� */
#define SCI_SMR0	((VH *)0x5fffec0)	/* �V���A������[�h����W�X�^ */
#define SCI_BRR0	((VH *)0x5fffec1)	/* �r�b�g���[�g����W�X�^ */
#define SCI_SCR0	((VH *)0x5fffec2)	/* �V���A����R���g���[������W�X�^ */
#define SCI_TDR0	((VH *)0x5fffec3)	/* �g�����X�~�b�g��f�[�^����W�X�^ */
#define SCI_SSR0	((VH *)0x5fffec4)	/* �V���A����X�e�[�^�X����W�X�^ */
#define SCI_RDR0	((VH *)0x5fffec5)	/* ���V�[�u��f�[�^����W�X�^ */

/* �r�b�h�`���l���P */
#define SCI_SMR1	((VH *)0x5fffec8)	/* �V���A������[�h����W�X�^ */
#define SCI_BRR1	((VH *)0x5fffec9)	/* �r�b�g���[�g����W�X�^ */
#define SCI_SCR1	((VH *)0x5fffeca)	/* �V���A����R���g���[������W�X�^ */
#define SCI_TDR1	((VH *)0x5fffecb)	/* �g�����X�~�b�g��f�[�^����W�X�^ */
#define SCI_SSR1	((VH *)0x5fffecc)	/* �V���A����X�e�[�^�X����W�X�^ */
#define SCI_RDR1	((VH *)0x5fffecd)	/* ���V�[�u��f�[�^����W�X�^ */
#endif	/* sh1sci2.c */

#define PBCR1_TD1_RD1_MASK	~0xf0u		/*  TxD1,RxD1�[�q�ݒ�p�}�X�N	*/
#define PBCR1_TD1 		0x80u		/*  TxD1�[�q�ݒ�p�}�N��  	*/
#define PBCR1_RD1 		0x20u		/*  RxD1�[�q�ݒ�p�}�N��  	*/

/* �`�^�c */
#define AD_DRAH		((VH *)0x5fffee0)	/* A/D �f�[�^����W�X�^�` H�i�ޯ�9�`2�j*/
#define AD_DRAL		((VH *)0x5fffee1)	/* A/D �f�[�^����W�X�^�` L�i�ޯ�1�`0�j*/
#define AD_DRBH		((VH *)0x5fffee2)	/* A/D �f�[�^����W�X�^�a H�i�ޯ�9�`2�j*/
#define AD_DRBL		((VH *)0x5fffee3)	/* A/D �f�[�^����W�X�^�a L�i�ޯ�1�`0�j*/
#define AD_DRCH		((VH *)0x5fffee4)	/* A/D �f�[�^����W�X�^�b H�i�ޯ�9�`2�j*/
#define AD_DRCL		((VH *)0x5fffee5)	/* A/D �f�[�^����W�X�^�b L�i�ޯ�1�`0�j*/
#define AD_DRDH		((VH *)0x5fffee6)	/* A/D �f�[�^����W�X�^�c H�i�ޯ�9�`2�j*/
#define AD_DRDL		((VH *)0x5fffee7)	/* A/D �f�[�^����W�X�^�c L�i�ޯ�1�`0�j*/
#define AD_CSR		((VH *)0x5fffee8)	/* A/D �R���g���[���^�X�e�[�^�X����W�X�^ */
#define AD_CR		((VH *)0x5fffee9)	/* A/D �R���g���[������W�X�^ 		 */
#define	ADF			0x80		/* ADF				*/
#define	ADST			0x20		/* A/D start			*/

#if 0 /* sh1itu.h�ɒ�`����Ă��� */
/* �h�s�t���� */
#define ITU_TSTR	((VH *)0x5ffff00)	/* �^�C�}��X�^�[�g����W�X�^ */
#define ITU_TSNC	((VH *)0x5ffff01)	/* �^�C�}��V���N������W�X�^ */
#define ITU_TMDR	((VH *)0x5ffff02)	/* �^�C�}����[�h����W�X�^ 	*/
#define ITU_TFCR	((VH *)0x5ffff03)	/* �^�C�}��t�@���N�V������R���g���[������W�X�^ */
#define ITU_TOER	((VH *)0x5ffff31)	/* �^�C�}��A�E�g�v�b�g��}�X�^�C�l�[�u������W�X�^ */

/* �h�s�t�`���l���O */
#define ITU_TCR0	((VH *)0x5ffff04)	/* �^�C�}��R���g���[������W�X�^0 		*/
#define ITU_TIOR0	((VH *)0x5ffff05)	/* �^�C�}�h�^�n�R���g���[������W�X�^0 	*/
#define ITU_TIER0	((VH *)0x5ffff06)	/* �^�C�}��C���^���v�g��C�l�[�u������W�X�^0 */
#define ITU_TSR0	((VH *)0x5ffff07)	/* �^�C�}��X�e�[�^�X����W�X�^0 */
#define ITU_TCNT0	((VH *)0x5ffff08)	/* �^�C�}��J�E���^0 */
#define ITU_GRA0	((VH *)0x5ffff0a)	/* �W�F�l��������W�X�^�`0 */
#define ITU_GRB0	((VH *)0x5ffff0c)	/* �W�F�l��������W�X�^�a0 */
#endif /* sh1itu.h */

/* �h�s�t�`���l���P */
#define ITU_TCR1	((VH *)0x5ffff0e)	/* �^�C�}��R���g���[������W�X�^1 */
#define ITU_TIOR1	((VH *)0x5ffff0f)	/* �^�C�}�h�^�n�R���g���[������W�X�^1 */
#define ITU_TIER1	((VH *)0x5ffff10)	/* �^�C�}��C���^���v�g��C�l�[�u������W�X�^1 */
#define ITU_TSR1	((VH *)0x5ffff11)	/* �^�C�}��X�e�[�^�X����W�X�^1 */
#define ITU_TCNT1	((VH *)0x5ffff12)	/* �^�C�}��J�E���^1 */
#define ITU_GRA1	((VH *)0x5ffff14)	/* �W�F�l��������W�X�^�`1 */
#define ITU_GRB1	((VH *)0x5ffff16)	/* �W�F�l��������W�X�^�a1 */

/* �h�s�t�`���l���Q */
#define ITU_TCR2	((VH *)0x5ffff18)	/* �^�C�}��R���g���[������W�X�^2  */
#define ITU_TIOR2	((VH *)0x5ffff19)	/* �^�C�}�h�^�n�R���g���[������W�X�^2  */
#define ITU_TIER2	((VH *)0x5ffff1a)	/* �^�C�}��C���^���v�g��C�l�[�u������W�X�^2  */
#define ITU_TSR2	((VH *)0x5ffff1b)	/* �^�C�}��X�e�[�^�X����W�X�^2  */
#define ITU_TCNT2	((VH *)0x5ffff1c)	/* �^�C�}��J�E���^2  */
#define ITU_GRA2	((VH *)0x5ffff1e)	/* �W�F�l��������W�X�^�`2 */
#define ITU_GRB2	((VH *)0x5ffff20)	/* �W�F�l��������W�X�^�a2 */

/* �h�s�t�`���l���R */
#define ITU_TCR3	((VH *)0x5ffff22)	/* �^�C�}��R���g���[������W�X�^3 */
#define ITU_TIOR3	((VH *)0x5ffff23)	/* �^�C�}�h�^�n�R���g���[������W�X�^3 */
#define ITU_TIER3	((VH *)0x5ffff24)	/* �^�C�}��C���^���v�g��C�l�[�u������W�X�^3 */
#define ITU_TSR3	((VH *)0x5ffff25)	/* �^�C�}��X�e�[�^�X����W�X�^3 */
#define ITU_TCNT3	((VH *)0x5ffff26)	/* �^�C�}��J�E���^3 */
#define ITU_GRA3	((VH *)0x5ffff28)	/* �W�F�l��������W�X�^�`3 */
#define ITU_GRB3	((VH *)0x5ffff2a)	/* �W�F�l��������W�X�^�a3 */
#define ITU_BRA3	((VH *)0x5ffff2c)	/* �o�b�t�@����W�X�^�`3 */
#define ITU_BRB3	((VH *)0x5ffff2e)	/* �o�b�t�@����W�X�^�a3 */

/* �h�s�t�`���l���S */
#define ITU_TCR4	((VH *)0x5ffff32)	/* �^�C�}��R���g���[������W�X�^4 */
#define ITU_TIOR4	((VH *)0x5ffff33)	/* �^�C�}�h�^�n�R���g���[������W�X�^4 */
#define ITU_TIER4	((VH *)0x5ffff34)	/* �^�C�}��C���^���v�g��C�l�[�u������W�X�^4 */
#define ITU_TSR4	((VH *)0x5ffff35)	/* �^�C�}��X�e�[�^�X����W�X�^4 */
#define ITU_TCNT4	((VH *)0x5ffff36)	/* �^�C�}��J�E���^4 */
#define ITU_GRA4	((VH *)0x5ffff38)	/* �W�F�l��������W�X�^�`4 */
#define ITU_GRB4	((VH *)0x5ffff3a)	/* �W�F�l��������W�X�^�a4 */
#define ITU_BRA4	((VH *)0x5ffff3c)	/* �o�b�t�@����W�X�^�`4 */
#define ITU_BRB4	((VH *)0x5ffff3e)	/* �o�b�t�@����W�X�^�a4 */

/* �h�s�t */
#if 0 /* sh1itu.h�ɒ�`����Ă��� */
#ifndef	TSR_IMFA
#define TSR_IMFA	0x0001			/* GRA���߱ϯ�/���߯ķ������׸�A */
#endif
#endif /* sh1itu.h */

#ifndef	TSR_IMFB
#define TSR_IMFB	0x0002			/* GRB���߱ϯ�/���߯ķ������׸�B */
#endif
#define TSR_OVF	 	0x0004				/* ���ް�۰�׸� */

/* �c�l�`�b���� */
#define DMAC_DMAOR	((VH *)0x5ffff48)		/* DMA �I�y���[�V��������W�X�^ */

/* �c�l�`�b�`���l���O */
#define DMAC_SAR0	((VH *)0x5ffff40)	/* DMA �\�[�X��A�h���X����W�X�^0 */
#define DMAC_DAR0	((VH *)0x5ffff44)	/* DMA �f�X�e�B�l�[�V������A�h���X����W�X�^0 */
#define DMAC_TCR0	((VH *)0x5ffff4a)	/* DMA �g�����X�t�@��J�E���g����W�X�^0 */
#define DMAC_CHCR0	((VH *)0x5ffff4e)		/* DMA �`���l����R���g���[������W�X�^0 */

/* �c�l�`�b�`���l���P */
#define DMAC_SAR1	((VH *)0x5ffff50)	/* DMA �\�[�X��A�h���X����W�X�^1 */
#define DMAC_DAR1	((VH *)0x5ffff54)	/* DMA �f�X�e�B�l�[�V������A�h���X����W�X�^1 */
#define DMAC_TCR1	((VH *)0x5ffff5a)	/* DMA �g�����X�t�@��J�E���g����W�X�^1 */
#define DMAC_CHCR1	((VH *)0x5ffff5e)		/* DMA �`���l����R���g���[������W�X�^1 */
/* �c�l�`�b�`���l���Q */

#define DMAC_SAR2	((VH *)0x5ffff60)	/* DMA �\�[�X��A�h���X����W�X�^2 */
#define DMAC_DAR2	((VH *)0x5ffff64)	/* DMA �f�X�e�B�l�[�V������A�h���X����W�X�^2 */
#define DMAC_TCR2	((VH *)0x5ffff6a)	/* DMA �g�����X�t�@��J�E���g����W�X�^2 */
#define DMAC_CHCR2	((VH *)0x5ffff6e)		/* DMA �`���l����R���g���[������W�X�^2 */

/* �c�l�`�b�`���l���R */
#define DMAC_SAR3	((VH *)0x5ffff70)	/* DMA �\�[�X��A�h���X����W�X�^3 */
#define DMAC_DAR3	((VH *)0x5ffff74)	/* DMA �f�X�e�B�l�[�V������A�h���X����W�X�^3 */
#define DMAC_TCR3	((VH *)0x5ffff7a)	/* DMA �g�����X�t�@��J�E���g����W�X�^3 */
#define DMAC_CHCR3	((VH *)0x5ffff7e)		/* DMA �`���l����R���g���[������W�X�^3 */

/* �����݃R���g���[�� */
#define INTC_IPRA	((VH *)0x5ffff84)	/* �����ݗD�惌�x���ݒ背�W�X�^�` */
#define INTC_IPRB	((VH *)0x5ffff86)	/* �����ݗD�惌�x���ݒ背�W�X�^�a */
#define INTC_IPRC	((VH *)0x5ffff88)	/* �����ݗD�惌�x���ݒ背�W�X�^�b */
#define INTC_IPRD	((VH *)0x5ffff8a)	/* �����ݗD�惌�x���ݒ背�W�X�^�c */
#define INTC_IPRE	((VH *)0x5ffff8c)	/* �����ݗD�惌�x���ݒ背�W�X�^�d */
#define INTC_ICR	((VH *)0x5ffff8e)	/* �����݃R���g���[�����W�X�^ */

/* ���[�U�u���[�N��R���g���[�� */
#define UBC_BARH	((VH *)0x5ffff90)	/* �u���[�N��A�h���X����W�X�^�g */
#define UBC_BARL	((VH *)0x5ffff92)	/* �u���[�N��A�h���X����W�X�^�k */
#define UBC_BAMRH	((VH *)0x5ffff94)	/* �u���[�N��A�h���X��}�X�N����W�X�^�g */
#define UBC_BAMRL	((VH *)0x5ffff96)	/* �u���[�N��A�h���X��}�X�N����W�X�^�k */
#define UBC_BBR		((VH *)0x5ffff98)	/* �u���[�N��o�X�T�C�N������W�X�^ */

/* �o�X��R���g���[�� */
#define BSC_BCR		((VH *)0x5ffffa0)	/* �o�X��R���g���[������W�X�^ */
#define BSC_WCR1	((VH *)0x5ffffa2)	/* �E�F�C�g��X�e�[�g���䃌�W�X�^1 */
#define BSC_WCR2	((VH *)0x5ffffa4)	/* �E�F�C�g��X�e�[�g���䃌�W�X�^2 */
#define BSC_WCR3	((VH *)0x5ffffa6)	/* �E�F�C�g��X�e�[�g���䃌�W�X�^3 */
#define BSC_DCR		((VH *)0x5ffffa8)	/* DRAM �G���A��R���g���[������W�X�^ */
#define BSC_PCR		((VH *)0x5ffffaa)	/* DRAM �p���e�B��R���g���[������W�X�^ */
#define BSC_RCR		((VH *)0x5ffffac)	/* ���t����V����R���g���[������W�X�^ */
#define BSC_RTCSR	((VH *)0x5ffffae)	/* ���t����V���^�C�}��R���g�����/�X�e��^�����W�� */
#define BSC_RTCNT	((VH *)0x5ffffb0)	/* ���t����V����^�C�}��J�E���^ */
#define BSC_RTCOR	((VH *)0x5ffffb2)	/* ���t����V����^�C���R���X�^���g����W�X�^ */

/* �v�c�s */
#define WDT_TCSR	((VH *)0x5ffffb8)	/* �^�C�}��R���g���[���^�X�e�[�^�X����W�X�^ */
#define WDT_TCNT	((VH *)0x5ffffb8)	/* �^�C�}��J�E���^�iײāj*/
#define WDT_TCNT_R	((VH *)0x5ffffb9)	/* �^�C�}��J�E���^�iذ�ށj*/
#define WDT_RSTCSR	((VH *)0x5ffffba)	/* ���Z��g��R���g�����/�X�e��^�X����W�X�^�iײāj*/
#define WDT_RSTCSR_R	((VH *)0x5ffffbb)		/* ���Z��g��R���g�����/�X�e��^�X����W�X�^�iذ�ށj*/

/* �����d�� */
#define SYS_SBYCR	((VH *)0x5ffffbc)	/* �X�^���o�C��R���g���[������W�X�^ */

/* �|�[�g�`�`�b */
#define PA_DR		((VH *)0x5ffffc0)	/* �|�[�g�` �f�[�^����W�X�^ */
#define PB_DR		((VH *)0x5ffffc2)	/* �|�[�g�a �f�[�^����W�X�^ */
#define PC_DR		((VH *)0x5ffffd0)	/* �|�[�g�b �f�[�^����W�X�^ */

#define PB_RTS0		(1<<2)  		/* RTS0 ���͒[�q�iPB2�j*/
#define PB_CTS0		(1<<3)  		/* CTS0 �o�͒[�q�iPB3�j*/
#define PB_TXE1		(1<<5)  		/* TXE1 �o�͒[�q�iPB5�j*/
#define PB_RXD0		(1<<8)  		/* RxD0 ���͒[�q�iPB8�j*/
#define PB_TXD0		(1<<9)  		/* TxD0 �o�͒[�q�iPB9�j*/
#define PB_RXD1		(1<<10) 		/* RxD1 ���͒[�q�iPB10�j*/
#define PB_TXD1		(1<<11)			/* TxD1 �o�͒[�q�iPB11�j*/

/* �s����t�@���N�V������R���g���[�� */
#define PFC_PAIOR	((VH *)0x5ffffc4)	/* �|�[�g�` �h�n���W�X�^ */
#define PFC_PBIOR	((VH *)0x5ffffc6)	/* �|�[�g�a �h�n���W�X�^ */
#define PFC_PACR1	((VH *)0x5ffffc8)	/* �|�[�g�` �R���g���[������W�X�^1 */
#define PFC_PACR2	((VH *)0x5ffffca)	/* �|�[�g�` �R���g���[������W�X�^2 */
#define PFC_PBCR1	((VH *)0x5ffffcc)	/* �|�[�g�a �R���g���[������W�X�^1 */
#define PFC_PBCR2	((VH *)0x5ffffce)	/* �|�[�g�a �R���g���[������W�X�^2 */
#define PFC_CASCR	((VH *)0x5ffffee)	/* �J�����A�h���X��X�g����u��s����R���۰٥���W�� */

/* �s�o�b */
#define TPC_TPMR	((VH *)0x5fffff0)	/* TPC �o�̓��[�h����W�X�^ */
#define TPC_TPCR	((VH *)0x5fffff1)	/* TPC �o�̓R���g���[������W�X�^ */
#define TPC_NDERB	((VH *)0x5fffff2)	/* �l�N�X�g��f�[�^��C�l�[�u������W�X�^�a */
#define TPC_NDERA	((VH *)0x5fffff3)	/* �l�N�X�g��f�[�^��C�l�[�u������W�X�^�` */
#define TPC_NDRB	((VH *)0x5fffff4)	/* �l�N�X�g��f�[�^����W�X�^�a */
#define TPC_NDRA	((VH *)0x5fffff5)	/* �l�N�X�g��f�[�^����W�X�^�` */
#define TPC_NDRB_2	((VH *)0x5fffff6)	/* �l�N�X�g��f�[�^����W�X�^�a�i�o���ضވقȂ鎞�j*/
#define TPC_NDRA_2	((VH *)0x5fffff7)	/* �l�N�X�g��f�[�^����W�X�^�`�i�o���ضވقȂ鎞�j*/

/* �����݃x�N�^�ԍ� */
#define INT_NMI		11		/* NMI */
#define INT_UB		12		/* ���[�U�u���[�N */
#define INT_IRQ0	64		/* �O���[�q IRQ0 */
#define INT_IRQ1	65		/* �O���[�q IRQ1 */
#define INT_IRQ2	66		/* �O���[�q IRQ2 */
#define INT_IRQ3	67		/* �O���[�q IRQ3 */
#define INT_IRQ4	68		/* �O���[�q IRQ4 */
#define INT_IRQ5	69		/* �O���[�q IRQ5 */
#define INT_IRQ6	70		/* �O���[�q IRQ6 */
#define INT_IRQ7	71		/* �O���[�q IRQ7 */
#define INT_DEI0	72		/* DMAC �`���l��0 */
#define INT_DEI1	74		/* DMAC �`���l��1 */
#define INT_DEI2	76		/* DMAC �`���l��2 */
#define INT_DEI3	78		/* DMAC �`���l��3 */
#define INT_IMIA0	80		/* ITU �`��l��0 �R���y�A�}��`/�C���v�ăL��v�`�A0 */
#define INT_IMIB0	81		/* ITU �`��l��0 �R���y�A�}��`/�C���v�ăL��v�`�B0 */
#define INT_OVI0	82		/* ITU �`��l��0 �I�[�o�t���[0 */
#define INT_IMIA1	84		/* ITU �`��l��1 �R���y�A�}��`/�C���v�ăL��v�`�A1 */
#define INT_IMIB1	85		/* ITU �`��l��1 �R���y�A�}��`/�C���v�ăL��v�`�B1 */
#define INT_OVI1	86		/* ITU �`��l��1 �I�[�o�t���[1 */
#define INT_IMIA2	88		/* ITU �`��l��2 �R���y�A�}��`/�C���v�ăL��v�`�A2 */
#define INT_IMIB2	89		/* ITU �`��l��2 �R���y�A�}��`/�C���v�ăL��v�`�B2 */
#define INT_OVI2	90		/* ITU �`��l��2 �I�[�o�t���[2 */
#define INT_IMIA3	92		/* ITU �`��l��3 �R���y�A�}��`/�C���v�ăL��v�`�A3 */
#define INT_IMIB3	93		/* ITU �`��l��3 �R���y�A�}��`/�C���v�ăL��v�`�B3 */
#define INT_OVI3	94		/* ITU �`��l��3 �I�[�o�t���[3 */
#define INT_IMIA4	96		/* ITU �`��l��4 �R���y�A�}��`/�C���v�ăL��v�`�A4 */
#define INT_IMIB4	97		/* ITU �`��l��4 �R���y�A�}��`/�C���v�ăL��v�`�B4 */
#define INT_OVI4	98		/* ITU �`��l��4 �I�[�o�t���[4 */
#define INT_ERI0	100		/* SCI �`���l��0 ��M�G���[ */
#define INT_RXI0	101	 	/* SCI �`���l��0 ��M���� */
#define INT_TXI0	102		/* SCI �`���l��0 ���M�f�[�^��G���v�e�B */
#define INT_TEI0	103		/* SCI �`���l��0 ���M�I�� */
#define INT_ERI1	104		/* SCI �`���l��1 ��M�G���[ */
#define INT_RXI1	105		/* SCI �`���l��1 ��M���� */
#define INT_TXI1	106		/* SCI �`���l��1 ���M�f�[�^��G���v�e�B */
#define INT_TEI1	107		/* SCI �`���l��1 ���M�I�� */
#define INT_PEI		108		/* �p���e�B */
#define INT_ADI		109		/* A/D �G���h */
#define INT_ITI		112		/* �E�H�b�`�h�b�N��^�C�}�i�C���^�[�o����^�C�}�j*/
#define INT_CMI		113		/* ���t���b�V���R����g���[����R���y�A�}�b�` */

/*
 *  GDB STUB�ďo�����[�`��
 */
#ifndef _MACRO_ONLY
#ifdef GDB_STUB

#define zunda_sh1_exit	gdb_stub_exit
#define zunda_sh1_putc	gdb_stub_putc

Inline void
gdb_stub_exit(void)
{
	Asm("trapa #0xff"::);		/*  ������  */
}

/*
 *  gdb stub�ɂ��o��
 */
Inline int
gdb_stub_putc(int c)
{
	Asm("mov   #0x00,r0
	     mov   %0,r4
	     trapa #0x21"
               : /* no output */
               : "r"(c)
               : "r0","r4");
	return(c);
}

/*
 *  ROM���̏ꍇ
 */
#else /* GDB_STUB */

Inline void
zunda_sh1_exit(void)
{
	while(1);
}

extern void	sh1sci_putc_pol(char c);	/*  sh1sci2.c  */

Inline void 
zunda_sh1_putc(char c)
{
	sh1sci_putc_pol(c);
}

#endif /* GDB_STUB */
#endif /* _MACRO_ONLY */
#endif /* _ZUNDA_SH1_H_ */
