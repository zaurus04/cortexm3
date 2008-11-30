
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
 *  @(#) $Id: sh4.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *  SH4(SH7750)�̓������W�X�^��`
 */

#ifndef _SH4_H_
#define _SH4_H_

/*
 *  ��O�C�x���g���W�X�^
 */
#define TRA	        0xff000020
#define EXPEVT	    0xff000024
#define INTEVT	    0xff000028


/*
 *   �o�X�X�e�[�g�R���g���[���֘A
 */
#define	RFCR	    0xff800028   /* H */

#define RFCR_CLEAR  0xa400

/*
 * ���荞�݂ɂ���� INTEVT ���W�X�^�ɐݒ肳���l
 */
#define    TMU0_INTEVT        0x400
#define    SCI_RXI_INTEVT     0x500
#define    SCI_TXI_INTEVT     0x520
#define    SCI_ERI_INTEVT     0x4e0
#define    SCIF_RXI_INTEVT    0x720
#define    SCIF_TXI_INTEVT    0x760
#define    SCIF_BRI_INTEVT    0x740


        
/*
 * �����݃R���g���[�����W�X�^
 */
#define	ICR   0xffd00000    /* H */
#define	IPRA  0xffd00004    /* H */
#define	IPRB  0xffd00008    /* H */
#define	IPRC  0xffd0000c    /* H */
#define	IPRD  0xffd00010    /* H */


/*
 * �^�C�}�[���W�X�^
 */
#define TMU_TOCR   0xffd80000  /* B */
#define TMU_TSTR   0xffd80004  /* B */
#define TMU_TCOR0  0xffd80008  /* W */
#define TMU_TCNT0  0xffd8000c  /* W */
#define TMU_TCR0   0xffd80010  /* H */
#define TMU_TCOR1  0xffd80014  /* W */
#define TMU_TCNT1  0xffd80018  /* W */
#define TMU_TCR1   0xffd8001c  /* H */
#define TMU_TCOR2  0xffd80020  /* W */
#define TMU_TCNT2  0xffd80024  /* W */
#define TMU_TCR2   0xffd80028  /* H */

#define	TMU_STR0	0x01
#define	TMU_STR1	0x02
#define	TMU_STR2	0x04
#define TCR_UNF     0x0100    

/*
 *
 *  �V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X(SCI)
 *
 */
#define SCI_SCSMR1  0xffe00000    /* B */
#define SCI_SCBRR1  0xffe00004    /* B */
#define SCI_SCSCR1  0xffe00008    /* B */
#define SCI_SCTDR1  0xffe0000c    /* B */
#define SCI_SCSSR1  0xffe00010    /* B */
#define SCI_SCRDR1  0xffe00014    /* B */
#define SCI_SCSPTR1 0xffe0001c    /* B */


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
 *
 *  FIFO�t���V���A���R�~���j�P�[�V�����C���^�[�t�F�[�X(SCIF)���W�X�^
 *
 */
#define SCIF_SCSMR2    0xffe80000   /* H */
#define SCIF_SCBRR2    0xffe80004   /* B */
#define SCIF_SCSCR2    0xffe80008   /* H */
#define SCIF_SCFTDR2   0xffe8000c   /* B */
#define SCIF_SCFSR2    0xffe80010   /* H */
#define SCIF_SCFRDR2   0xffe80014   /* B */
#define SCIF_SCFCR2    0xffe80018   /* H */
#define SCIF_SCFDR2    0xffe8001c   /* H */
#define	SCIF_SCSPTR2   0xffe80020   /* H */
#define	SCIF_SCLSR2	   0xffe80024   /* H */

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

#define SCFSR2_ER	  0x0080
#define SCFSR2_TEND	  0x0040
#define SCFSR2_TDFE	  0x0020
#define SCFSR2_BRK	  0x0010
#define SCFSR2_FER	  0x0008
#define SCFSR2_PER	  0x0004
#define SCFSR2_RDF	  0x0002
#define SCFSR2_DR	  0x0001

#define SCFCR2_RTRG1  0x0080
#define SCFCR2_RTRG0  0x0040
#define SCFCR2_TTRG1  0x0020
#define SCFCR2_TTRG0  0x0010
#define SCFCR2_MCE	  0x0008
#define SCFCR2_TFRST  0x0004
#define SCFCR2_RFRST  0x0002
#define SCFCR2_LOOP	  0x0001

#define SCSPTR2_RTSIO  0x0080
#define SCSPTR2_RTSDT  0x0040
#define SCSPTR2_CTSIO  0x0020
#define SCSPTR2_CTSDT  0x0010
#define SCSPTR2_SPB2IO 0x0002
#define SCSPTR2_SPB2DT 0x0001


/*
 * �L���b�V�����䃌�W�X�^
 */
#define	CCR	0xff00001c   /* W */
#define CCR_DISABLE   0x00000808  /* �L���b�V������ */


#endif /* _SH4_H_ */






