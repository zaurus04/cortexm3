
/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                                  Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: sh3.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *  SH3(SH7729R,SH7709A,SH7709,SH7708)�̓������W�X�^��`
 */

#ifndef _SH3_H_
#define _SH3_H_

#ifndef _MACRO_ONLY
#include <itron.h>
#include <sil.h>
#endif /* _MACRO_ONLY */

/*
 *  ��O�C�x���g���W�X�^
 */
#define TRA	        0xFFFFFFD0		
#define EXPEVT	    0xFFFFFFD4		
#define INTEVT	    0xFFFFFFD8		
#define INTEVT2	    0xA4000000		

/*
 * INTEVT(2) �̍ő�l
 */ 
#ifdef SH7709A

#define MAX_INTIVT (0x980)

#elif defined(SH7727)

#define MAX_INTIVT (0xB80)

#elif defined(SH7729R)

#define MAX_INTIVT (0x980)

#elif defined(SH7750)

#define MAX_INTIVT (0x7E0)

#else

#define MAX_INTIVT (0xB80)

#endif 



/*
 *   �o�X�X�e�[�g�R���g���[���֘A
 */
#define	RFCR	0xffffff74	/* H */

#define    RFCR_CLEAR         0xa400


/*
 * ���荞�݂ɂ����INTEVT2���W�X�^�ɐݒ肳���l
 */
#define    TMU0_INTEVT        0x400
#define    IRQ0_INTEVT        0x600
#define    SCI_RXI_INTEVT     0x500
#define    SCI_TXI_INTEVT     0x520
#define    SCI_BRI_INTEVT     0x4ed
#define    PINT0_7_INTEVT     0x700
#define    PINT8_15_INTEVT    0x720
#define    SCI1_RXI_INTEVT    0x8a0
#define    SCI1_TXI_INTEVT    0x8e0
#define    SCI1_BRI_INTEVT    0x8c0
#define    SCIF_RXI_INTEVT    0x920
#define    SCIF_TXI_INTEVT    0x960
#define    SCIF_BRI_INTEVT    0x940

        
/*
 * ���荞�݃R���g���[���[���W�X�^�[
 */
#define	ICR0	0xfffffee0    /* H */
#define	ICR1	0xa4000010    /* H */
#define	ICR2	0xa4000012    /* H */
#define	PINTER	0xa4000014    /* H */
#define	IPRA	0xfffffee2    /* H */
#define	IPRB	0xfffffee4    /* H */
#define	IPRC	0xa4000016    /* H */
#define	IPRD	0xa4000018    /* H */
#define	IPRE	0xa400001a    /* H */
#define	IRR0	0xa4000004    /* B */
#define	IRR1	0xa4000006    /* B */
#define	IRR2	0xa4000008    /* B */

#define ICR2_PINT7S     0x80
#define ICR2_PINT6S     0x40
#define PINTER_PINT7E   0x80
#define PINTER_PINT6E   0x40

/*
 * �^�C�}�[���W�X�^
 */
#define TMU_TOCR   0xfffffe90  /* B */
#define TMU_TSTR   0xfffffe92  /* B */
#define TMU_TCOR0  0xfffffe94  /* W */
#define TMU_TCNT0  0xfffffe98  /* W */
#define TMU_TCR0   0xfffffe9c  /* H */
#define TMU_TCOR1  0xfffffea0  /* W */
#define TMU_TCNT1  0xfffffea4  /* W */
#define TMU_TCR1   0xfffffea8  /* H */
#define TMU_TCOR2  0xfffffeac  /* W */
#define TMU_TCNT2  0xfffffeb0  /* W */
#define TMU_TCR2   0xfffffeb4  /* H */

#define	TMU_STR0	0x01
#define	TMU_STR1	0x02
#define	TMU_STR2	0x04
#define TCR_UNF     0x0100    


/*
 *  �V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X(SCI)
 */
#define   SCI_SCSMR    0xfffffe80  /* B */
#define   SCI_SCBRR    0xfffffe82  /* B */
#define   SCI_SCSCR    0xfffffe84  /* B */
#define   SCI_SCTDR    0xfffffe86  /* B */
#define   SCI_SCSSR    0xfffffe88  /* B */
#define   SCI_SCRDR    0xfffffe8a  /* B */

/*
 *  �V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X(SCI)��
 *  �|�[�gSC�R���g���[��/�f�[�^���W�X�^
 *  SH7709�y��SH7709A�̂�
 */
#define	SCPDR     0xa4000136   /* B */
#define	SCPCR	  0xa4000116   /* H */


/*
 *  �V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X(SCI)��
 *  �V���A���|�[�g���W�X�^
 *  SH7708�̂�
 */
#define	SCSPTR	  0xffffff7c  /* H */

#define	SCSMR_CHR	  0x0040
#define	SCSMR_PE	  0x0020
#define	SCSMR_OE	  0x0010
#define	SCSMR_STOP	  0x0008
#define	SCSMR_CKS1	  0x0002
#define	SCSMR_CKS0	  0x0001

#define SCSCR_TIE	  0x0080
#define SCSCR_RIE	  0x0040
#define SCSCR_TE	  0x0020
#define SCSCR_RE	  0x0010
#define SCSCR_CKE1	  0x0002
#define SCSCR_CKE0	  0x0001

#define SCSSR_TDRE	  0x80
#define SCSSR_RDRF	  0x40
#define SCSSR_ORER	  0x20
#define SCSSR_FER	  0x10
#define SCSSR_PER	  0x08
#define SCSSR_TEND	  0x04
#define SCSSR_MPB	  0x02
#define SCSSR_MPBT	  0x01


/*
 *  FIFO�t���V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X(SCIF)���W�X�^
 *  SH7709�y��SH7709A�̂�
 */
#define  SCIF_SCSMR2     0xa4000150  /* B */
#define  SCIF_SCBRR2     0xa4000152  /* B */
#define  SCIF_SCSCR2     0xa4000154  /* B */
#define  SCIF_SCFTDR2    0xa4000156  /* B */
#define  SCIF_SCSSR2     0xa4000158  /* H */
#define  SCIF_SCFRDR2    0xa400015a  /* B */
#define  SCIF_SCFCR2     0xa400015c  /* B */
#define  SCIF_SCFDR2     0xa400015e  /* H */

#define	SCSMR2_CHR	  0x0040
#define	SCSMR2_PE	  0x0020
#define	SCSMR2_OE	  0x0010
#define	SCSMR2_STOP	  0x0008
#define	SCSMR2_CKS1	  0x0002
#define	SCSMR2_CKS0	  0x0001

#define SCSCR2_TIE	  0x0080
#define SCSCR2_RIE	  0x0040
#define SCSCR2_TE	  0x0020
#define SCSCR2_RE	  0x0010
#define SCSCR2_CKE1	  0x0002
#define SCSCR2_CKE0	  0x0001

#define SCSSR2_ER	  0x0080
#define SCSSR2_TEND	  0x0040
#define SCSSR2_TDFE	  0x0020
#define SCSSR2_BRK	  0x0010
#define SCSSR2_FER	  0x0008
#define SCSSR2_PER	  0x0004
#define SCSSR2_RDF	  0x0002
#define SCSSR2_DR	  0x0001


#define SCFCR2_RTRG1  0x0080
#define SCFCR2_RTRG0  0x0040
#define SCFCR2_TTRG1  0x0020
#define SCFCR2_TTRG0  0x0010
#define SCFCR2_MCE	  0x0008
#define SCFCR2_TFRST  0x0004
#define SCFCR2_RFRST  0x0002
#define SCFCR2_LOOP	  0x0001


/*
 *  IrDA (SCI1)���W�X�^
 *  SH7709�y��SH7709A�̂�
 */
#define  SCI1_SCSMR1    0xa4000140   /* B */ 
#define  SCI1_SCBRR1    0xa4000142   /* B */ 
#define  SCI1_SCSCR1    0xa4000144   /* B */ 
#define  SCI1_SCFTDR1   0xa4000146   /* B */ 
#define  SCI1_SCSSR1    0xa4000148   /* H */ 
#define  SCI1_SCFRDR1   0xa400014a   /* B */ 
#define  SCI1_SCFCR1    0xa400014c   /* B */ 
#define  SCI1_SCFDR1    0xa400014e   /* H */ 

#define	SCSMR1_IRMOD    0x0080
#define	SCSMR1_CHR	    0x0040
#define	SCSMR1_PE	    0x0020
#define	SCSMR1_OE	    0x0010
#define	SCSMR1_STOP	    0x0008
#define	SCSMR1_CKS1	    0x0002
#define	SCSMR1_CKS0	    0x0001

#define SCSCR1_TIE      0x0080
#define SCSCR1_RIE      0x0040
#define SCSCR1_TE       0x0020
#define SCSCR1_RE       0x0010
#define SCSCR1_CKE1     0x0002
#define SCSCR1_CKE0     0x0001

#define SCSSR1_ER	0x0080
#define SCSSR1_TEND	0x0040
#define SCSSR1_TDFE	0x0020
#define SCSSR1_BRK	0x0010
#define SCSSR1_FER	0x0008
#define SCSSR1_PER	0x0004
#define SCSSR1_RDF	0x0002
#define SCSSR1_DR	0x0001


#define SCFCR1_RTRG1    0x0080
#define SCFCR1_RTRG0    0x0040
#define SCFCR1_TTRG1    0x0020
#define SCFCR1_TTRG0    0x0010
#define SCFCR1_MCE      0x0008
#define SCFCR1_TFRST    0x0004
#define SCFCR1_RFRST    0x0002
#define SCFCR1_LOOP     0x0001



/*
 * �L���b�V�����䃌�W�X�^
 */
#define	CCR	   0xffffffec   /* W */

#define CCR_DISABLE   0x00000008     /* �L���b�V���̖����� */

#ifndef _MACRO_ONLY

/*
 *   SH7709A�y��SH7709��SCIF�ւ̃|�[�����O�ł̏o��
 */
Inline int
scif_putc(int c)
{
    /* Wait TDRD = 1 */
    while((sil_reb_mem((VP)SCIF_SCSSR2) & SCSSR2_TDFE)==0);

    sil_wrb_mem((VP)SCIF_SCFTDR2, c);
    sil_wrh_mem((VP)SCIF_SCSSR2,
                (sil_reh_mem((VP)SCIF_SCSSR2) & ~SCSSR2_TDFE));
    return(c);
}

    
/*
 *  SCI�ɂ��o��
 */
Inline int
sci_putc(int c)
{

    /* Wait TDRD = 1 */
    while((sil_reb_mem((VP)SCI_SCSSR) & SCSSR_TDRE) == 0);

    sil_wrb_mem((VP)SCI_SCTDR, c);
    sil_wrb_mem((VP)SCI_SCSSR,
                (sil_reb_mem((VP)SCI_SCSSR) & ~SCSSR_TDRE));
    return(c);
}

#endif /* _MACRO_ONLY */
#endif /* _SH3_H_ */
