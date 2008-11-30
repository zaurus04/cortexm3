/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2005 by Freelines CO.,Ltd 
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
 *  @(#) $Id: v850es_sg2.h,v 1.1 2008/06/17 00:04:46 suikan Exp $
 */

#ifndef	_V850ES_SG2_H_
#define	_V850ES_SG2_H_
/*
 *	�v���Z�b�T�Ɉˑ������`�iV850�p�j
 */
#ifndef _MACRO_ONLY
typedef unsigned char   byte;
typedef unsigned short  word;
typedef unsigned long   dword;
typedef volatile byte   IOREG;
typedef volatile word   HIOREG;
typedef volatile dword  LIOREG;
#endif /* _MACRO_ONLY */

/*
 * ����RAM
 */
#define	IRAM_TOP	0x03FF7000		/* ����RAM�̐擪�A�h���X */
#define IRAM_SIZE	0x8000			/* ����RAM�̑傫�� 32Kbyte(uPD70F3281Y) */
/*
 * ����FlashROM
 */
#define	IROM_TOP	0x0000000		/* ����FlashROM�̐擪�A�h���X */
#define IROM_SIZE	0x60000			/* ����FlashROM�̑傫�� 384Kbyte(uPD70F3281Y) */

/* 
 * V850ES/SG2��IO���W�X�^��`
 */
#define	PDL			0xFFFFF004		/* �|�[�gDL���W�X�^ */
#define	PDLL		0xFFFFF004		/* �|�[�gDL���W�X�^L */
#define	PDLH		0xFFFFF005		/* �|�[�gDL���W�X�^H */
#define	PDH			0xFFFFF006		/* �|�[�gDH���W�X�^ */
#define	PCT			0xFFFFF00A		/* �|�[�gCT���W�X�^ */
#define	PCM			0xFFFFF00C		/* �|�[�gCM���W�X�^ */
#define	PMDL		0xFFFFF024		/* �|�[�gDL���[�h�E���W�X�^ */
#define	PMDLL		0xFFFFF024		/* �|�[�gDL���[�h�E���W�X�^L */
#define	PMDLH		0xFFFFF025		/* �|�[�gDL���[�h�E���W�X�^H */
#define	PMDH		0xFFFFF026		/* �|�[�gDH���[�h�E���W�X�^ */
#define	PMCT		0xFFFFF02A		/* �|�[�gCT���[�h�E���W�X�^ */
#define	PMCM		0xFFFFF02C		/* �|�[�gCM���[�h�E���W�X�^ */
#define	PMCDL		0xFFFFF044		/* �|�[�gDL���[�h�E�R���g���[���E���W�X�^ */
#define	PMCDLL		0xFFFFF044		/* �|�[�gDL���[�h�E�R���g���[���E���W�X�^L */
#define	PMCDLH		0xFFFFF045		/* �|�[�gDL���[�h�E�R���g���[���E���W�X�^H */
#define	PMCDH		0xFFFFF046		/* �|�[�gDH���[�h�E�R���g���[���E���W�X�^ */
#define	PMCCT		0xFFFFF04A		/* �|�[�gCT���[�h�E�R���g���[���E���W�X�^ */
#define	PMCCM		0xFFFFF04C		/* �|�[�gCM���[�h�E�R���g���[���E���W�X�^ */
#define	BPC			0xFFFFF064		/* ����I/O�̈�Z���N�g���䃌�W�X�^ */
#define	BSC			0xFFFFF066		/* �o�X�E�T�C�Y�E�R���t�B�M�����[�V�����E���W�X�^�E�o�X */
#define	VSWC		0xFFFFF06E		/* �V�X�e���E�E�G�C�g�E�R���g���[���E���W�X�^ */
#define	DSA0L		0xFFFFF080		/* DMA�\�[�X�E�A�h���X�E���W�X�^0L */
#define	DSA0H		0xFFFFF082		/* DMA�\�[�X�E�A�h���X�E���W�X�^0H */
#define	DDA0L		0xFFFFF084		/* DMA�f�X�e�B�l�[�V�����E�A�h���X�E���W�X�^0L */
#define	DDA0H		0xFFFFF086		/* DMA�f�X�e�B�l�[�V�����E�A�h���X�E���W�X�^0H */
#define	DSA1L		0xFFFFF088		/* DMA�\�[�X�E�A�h���X�E���W�X�^1L */
#define	DSA1H		0xFFFFF08A		/* DMA�\�[�X�E�A�h���X�E���W�X�^1H */
#define	DDA1L		0xFFFFF08C		/* DMA�f�X�e�B�l�[�V�����E�A�h���X�E���W�X�^1L */
#define	DDA1H		0xFFFFF08E		/* DMA�f�X�e�B�l�[�V�����E�A�h���X�E���W�X�^1H */
#define	DSA2L		0xFFFFF090		/* DMA�\�[�X�E�A�h���X�E���W�X�^2L */
#define	DSA2H		0xFFFFF092		/* DMA�\�[�X�E�A�h���X�E���W�X�^2H */
#define	DDA2L		0xFFFFF094		/* DMA�f�X�e�B�l�[�V�����E�A�h���X�E���W�X�^2L */
#define	DDA2H		0xFFFFF096		/* DMA�f�X�e�B�l�[�V�����E�A�h���X�E���W�X�^2H */
#define	DSA3L		0xFFFFF098		/* DMA�\�[�X�E�A�h���X�E���W�X�^3L */
#define	DSA3H		0xFFFFF09A		/* DMA�\�[�X�E�A�h���X�E���W�X�^3H */
#define	DDA3L		0xFFFFF09C		/* DMA�f�X�e�B�l�[�V�����E�A�h���X�E���W�X�^3L */
#define	DDA3H		0xFFFFF09E		/* DMA�f�X�e�B�l�[�V�����E�A�h���X�E���W�X�^3H */
#define	DBC0		0xFFFFF0C0		/* DMA�]���J�E���g�E���W�X�^0 */
#define	DBC1		0xFFFFF0C2		/* DMA�]���J�E���g�E���W�X�^1 */
#define	DBC2		0xFFFFF0C4		/* DMA�]���J�E���g�E���W�X�^2 */
#define	DBC3		0xFFFFF0C6		/* DMA�]���J�E���g�E���W�X�^3 */
#define	DADC0		0xFFFFF0D0		/* DMA�A�h���V���O�E�R���g���[���E���W�X�^0 */
#define	DADC1		0xFFFFF0D2		/* DMA�A�h���V���O�E�R���g���[���E���W�X�^1 */
#define	DADC2		0xFFFFF0D4		/* DMA�A�h���V���O�E�R���g���[���E���W�X�^2 */
#define	DADC3		0xFFFFF0D6		/* DMA�A�h���V���O�E�R���g���[���E���W�X�^3 */
#define	DCHC0		0xFFFFF0E0		/* DMA�`���l���E�R���g���[���E���W�X�^0 */
#define	DCHC1		0xFFFFF0E2		/* DMA�`���l���E�R���g���[���E���W�X�^1 */
#define	DCHC2		0xFFFFF0E4		/* DMA�`���l���E�R���g���[���E���W�X�^2 */
#define	DCHC3		0xFFFFF0E6		/* DMA�`���l���E�R���g���[���E���W�X�^3 */
#define	IMR0		0xFFFFF100		/* ���荞�݃}�X�N�E���W�X�^0 */
#define	IMR0L		0xFFFFF100		/* ���荞�݃}�X�N�E���W�X�^0L */
#define	IMR0H		0xFFFFF101		/* ���荞�݃}�X�N�E���W�X�^0H */
#define	IMR1		0xFFFFF102		/* ���荞�݃}�X�N�E���W�X�^1 */
#define	IMR1L		0xFFFFF102		/* ���荞�݃}�X�N�E���W�X�^1L */
#define	IMR1H		0xFFFFF103		/* ���荞�݃}�X�N�E���W�X�^1H */
#define	IMR2		0xFFFFF104		/* ���荞�݃}�X�N�E���W�X�^2 */
#define	IMR2L		0xFFFFF104		/* ���荞�݃}�X�N�E���W�X�^2L */
#define	IMR2H		0xFFFFF105		/* ���荞�݃}�X�N�E���W�X�^2H */
#define	IMR3		0xFFFFF106		/* ���荞�݃}�X�N�E���W�X�^3 */
#define	IMR3L		0xFFFFF106		/* ���荞�݃}�X�N�E���W�X�^3L */
#define	IMR3H		0xFFFFF107		/* ���荞�݃}�X�N�E���W�X�^3H */
#define	LVIIC		0xFFFFF110		/* ���荞�ݐ��䃌�W�X�^ */
#define	PIC0		0xFFFFF112		/* ���荞�ݐ��䃌�W�X�^ */
#define	PIC1		0xFFFFF114		/* ���荞�ݐ��䃌�W�X�^ */
#define	PIC2		0xFFFFF116		/* ���荞�ݐ��䃌�W�X�^ */
#define	PIC3		0xFFFFF118		/* ���荞�ݐ��䃌�W�X�^ */
#define	PIC4		0xFFFFF11A		/* ���荞�ݐ��䃌�W�X�^ */
#define	PIC5		0xFFFFF11C		/* ���荞�ݐ��䃌�W�X�^ */
#define	PIC6		0xFFFFF11E		/* ���荞�ݐ��䃌�W�X�^ */
#define	PIC7		0xFFFFF120		/* ���荞�ݐ��䃌�W�X�^ */
#define	TQ0OVIC		0xFFFFF122		/* ���荞�ݐ��䃌�W�X�^ */
#define	TQ0CCIC0	0xFFFFF124		/* ���荞�ݐ��䃌�W�X�^ */
#define	TQ0CCIC1	0xFFFFF126		/* ���荞�ݐ��䃌�W�X�^ */
#define	TQ0CCIC2	0xFFFFF128		/* ���荞�ݐ��䃌�W�X�^ */
#define	TQ0CCIC3	0xFFFFF12A		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP0OVIC		0xFFFFF12C		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP0CCIC0	0xFFFFF12E		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP0CCIC1	0xFFFFF130		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP1OVIC		0xFFFFF132		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP1CCIC0	0xFFFFF134		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP1CCIC1	0xFFFFF136		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP2OVIC		0xFFFFF138		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP2CCIC0	0xFFFFF13A		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP2CCIC1	0xFFFFF13C		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP3OVIC		0xFFFFF13E		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP3CCIC0	0xFFFFF140		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP3CCIC1	0xFFFFF142		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP4OVIC		0xFFFFF144		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP4CCIC0	0xFFFFF146		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP4CCIC1	0xFFFFF148		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP5OVIC		0xFFFFF14A		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP5CCIC0	0xFFFFF14C		/* ���荞�ݐ��䃌�W�X�^ */
#define	TP5CCIC1	0xFFFFF14E		/* ���荞�ݐ��䃌�W�X�^ */
#define	TM0EQIC0	0xFFFFF150		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB0RIC		0xFFFFF152		/* ���荞�ݐ��䃌�W�X�^ */
#define	IICIC1		0xFFFFF152		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB0TIC		0xFFFFF154		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB1RIC		0xFFFFF156		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB1TIC		0xFFFFF158		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB2RIC		0xFFFFF15A		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB2TIC		0xFFFFF15C		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB3RIC		0xFFFFF15E		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB3TIC		0xFFFFF160		/* ���荞�ݐ��䃌�W�X�^ */
#define	UA0RIC		0xFFFFF162		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB4RIC		0xFFFFF162		/* ���荞�ݐ��䃌�W�X�^ */
#define	UA0TIC		0xFFFFF164		/* ���荞�ݐ��䃌�W�X�^ */
#define	CB4TIC		0xFFFFF164		/* ���荞�ݐ��䃌�W�X�^ */
#define	UA1RIC		0xFFFFF166		/* ���荞�ݐ��䃌�W�X�^ */
#define	IICIC2		0xFFFFF166		/* ���荞�ݐ��䃌�W�X�^ */
#define	UA1TIC		0xFFFFF168		/* ���荞�ݐ��䃌�W�X�^ */
#define	UA2RIC		0xFFFFF16A		/* ���荞�ݐ��䃌�W�X�^ */
#define	IICIC0		0xFFFFF16A		/* ���荞�ݐ��䃌�W�X�^ */
#define	UA2TIC		0xFFFFF16C		/* ���荞�ݐ��䃌�W�X�^ */
#define	ADIC		0xFFFFF16E		/* ���荞�ݐ��䃌�W�X�^ */
#define	DMAIC0		0xFFFFF170		/* ���荞�ݐ��䃌�W�X�^ */
#define	DMAIC1		0xFFFFF172		/* ���荞�ݐ��䃌�W�X�^ */
#define	DMAIC2		0xFFFFF174		/* ���荞�ݐ��䃌�W�X�^ */
#define	DMAIC3		0xFFFFF176		/* ���荞�ݐ��䃌�W�X�^ */
#define	KRIC		0xFFFFF178		/* ���荞�ݐ��䃌�W�X�^ */
#define	WTIIC		0xFFFFF17A		/* ���荞�ݐ��䃌�W�X�^ */
#define	WTIC		0xFFFFF17C		/* ���荞�ݐ��䃌�W�X�^ */
#define	ERRIC0		0xFFFFF17E		/* ���荞�ݐ��䃌�W�X�^ */
#define	ERRIC		0xFFFFF17E		/* ���荞�ݐ��䃌�W�X�^ */
#define	WUPIC0		0xFFFFF180		/* ���荞�ݐ��䃌�W�X�^ */
#define	STAIC		0xFFFFF180		/* ���荞�ݐ��䃌�W�X�^ */
#define	RECIC0		0xFFFFF182		/* ���荞�ݐ��䃌�W�X�^ */
#define	IEIC1		0xFFFFF182		/* ���荞�ݐ��䃌�W�X�^ */
#define	TRXIC0		0xFFFFF184		/* ���荞�ݐ��䃌�W�X�^ */
#define	IEIC2		0xFFFFF184		/* ���荞�ݐ��䃌�W�X�^ */
#define	ISPR		0xFFFFF1FA		/* �C���T�[�r�X�E�v���C�I���e�B�E���W�X�^ */
#define	PRCMD		0xFFFFF1FC		/* �R�}���h�E���W�X�^ */
#define	PSC			0xFFFFF1FE		/* �p���[�E�Z�[�u�E�R���g���[���E���W�X�^ */
#define	ADA0M0		0xFFFFF200		/* A/D�R���o�[�^�E���[�h�E���W�X�^0 */
#define	ADA0M1		0xFFFFF201		/* A/D�R���o�[�^�E���[�h�E���W�X�^1 */
#define	ADA0S		0xFFFFF202		/* A/D�R���o�[�^�E�`���l���w�背�W�X�^ */
#define	ADA0M2		0xFFFFF203		/* A/D�R���o�[�^�E���[�h�E���W�X�^2 */
#define	ADA0PFM		0xFFFFF204		/* �p���[�E�t�F�C����r���[�h�E���W�X�^ */
#define	ADA0PFT		0xFFFFF205		/* �p���[�E�t�F�C����r�������l���W�X�^ */
#define	ADA0CR0		0xFFFFF210		/* A/D�ϊ����ʃ��W�X�^0 */
#define	ADA0CR0H	0xFFFFF211		/* A/D�ϊ����ʃ��W�X�^0H */
#define	ADA0CR1		0xFFFFF212		/* A/D�ϊ����ʃ��W�X�^1 */
#define	ADA0CR1H	0xFFFFF213		/* A/D�ϊ����ʃ��W�X�^1H */
#define	ADA0CR2		0xFFFFF214		/* A/D�ϊ����ʃ��W�X�^2 */
#define	ADA0CR2H	0xFFFFF215		/* A/D�ϊ����ʃ��W�X�^2H */
#define	ADA0CR3		0xFFFFF216		/* A/D�ϊ����ʃ��W�X�^3 */
#define	ADA0CR3H	0xFFFFF217		/* A/D�ϊ����ʃ��W�X�^3H */
#define	ADA0CR4		0xFFFFF218		/* A/D�ϊ����ʃ��W�X�^4 */
#define	ADA0CR4H	0xFFFFF219		/* A/D�ϊ����ʃ��W�X�^4H */
#define	ADA0CR5		0xFFFFF21A		/* A/D�ϊ����ʃ��W�X�^5 */
#define	ADA0CR5H	0xFFFFF21B		/* A/D�ϊ����ʃ��W�X�^5H */
#define	ADA0CR6		0xFFFFF21C		/* A/D�ϊ����ʃ��W�X�^6 */
#define	ADA0CR6H	0xFFFFF21D		/* A/D�ϊ����ʃ��W�X�^6H */
#define	ADA0CR7		0xFFFFF21E		/* A/D�ϊ����ʃ��W�X�^7 */
#define	ADA0CR7H	0xFFFFF21F		/* A/D�ϊ����ʃ��W�X�^7H */
#define	ADA0CR8		0xFFFFF220		/* A/D�ϊ����ʃ��W�X�^8 */
#define	ADA0CR8H	0xFFFFF221		/* A/D�ϊ����ʃ��W�X�^8H */
#define	ADA0CR9		0xFFFFF222		/* A/D�ϊ����ʃ��W�X�^9 */
#define	ADA0CR9H	0xFFFFF223		/* A/D�ϊ����ʃ��W�X�^9H */
#define	ADA0CR10	0xFFFFF224		/* A/D�ϊ����ʃ��W�X�^10 */
#define	ADA0CR10H	0xFFFFF225		/* A/D�ϊ����ʃ��W�X�^10H */
#define	ADA0CR11	0xFFFFF226		/* A/D�ϊ����ʃ��W�X�^11 */
#define	ADA0CR11H	0xFFFFF227		/* A/D�ϊ����ʃ��W�X�^11H */
#define	DA0CS0		0xFFFFF280		/* D/A�R���o�[�^�ϊ��l�ݒ背�W�X�^0 */
#define	DA0CS1		0xFFFFF281		/* D/A�R���o�[�^�ϊ��l�ݒ背�W�X�^1 */
#define	DA0M		0xFFFFF282		/* D/A�R���o�[�^�E���[�h�E���W�X�^ */
#define	KRM			0xFFFFF300		/* �L�[�E���^�[���E���[�h�E���W�X�^ */
#define	SELCNT0		0xFFFFF308		/* �Z���N�^���쐧�䃌�W�X�^ */
#define	CRCIN		0xFFFFF310		/* CRC�C���v�b�g�E���W�X�^ */
#define	CRCD		0xFFFFF312		/* CRC�f�[�^�E���W�X�^ */
#define	NFC			0xFFFFF318		/* �m�C�Y�������䃌�W�X�^ */
#define	PRSM1		0xFFFFF320		/* BRG1�v���X�P�[���E���[�h�E���W�X�^ */
#define	PRSCM1		0xFFFFF321		/* BRG1�v���X�P�[���E�R���y�A�E���W�X�^ */
#define	PRSM2		0xFFFFF324		/* BRG2�v���X�P�[���E���[�h�E���W�X�^ */
#define	PRSCM2		0xFFFFF325		/* BRG2�v���X�P�[���E�R���y�A�E���W�X�^ */
#define	PRSM3		0xFFFFF328		/* BRG3�v���X�P�[���E���[�h�E���W�X�^ */
#define	PRSCM3		0xFFFFF329		/* BRG3�v���X�P�[���E�R���y�A�E���W�X�^ */
#define	OCKS0		0xFFFFF340		/* IIC�����N���b�N�I�����W�X�^0 */
#define	OCKS1		0xFFFFF344		/* IIC�����N���b�N�I�����W�X�^1 */
#define	OCKS2		0xFFFFF348		/* IEBus�N���b�N�I�����W�X�^ */
#define	BCR			0xFFFFF360		/* IEBus�R���g���[���E���W�X�^ */
#define	PSR			0xFFFFF361		/* IEBus�p���[�E�Z�[�u�E���W�X�^ */
#define	SSR			0xFFFFF362		/* IEBus�X���[�u�E�X�e�[�^�X�E���W�X�^ */
#define	USR			0xFFFFF363		/* IEBus���j�b�g�E�X�e�[�^�X�E���W�X�^ */
#define	ISR			0xFFFFF364		/* IEBus�C���^���v�g�E�X�e�[�^�X�E���W�X�^ */
#define	ESR			0xFFFFF365		/* IEBus�G���[�E�X�e�[�^�X�E���W�X�^ */
#define	UAR			0xFFFFF366		/* IEBus���j�b�g�E�A�h���X�E���W�X�^ */
#define	SAR			0xFFFFF368		/* IEBus�X���[�u�E�A�h���X�E���W�X�^ */
#define	PAR			0xFFFFF36A		/* IEBus�p�[�g�i�E�A�h���X�E���W�X�^ */
#define	RSA			0xFFFFF36C		/* IEBus��M�X���[�u�E�A�h���X�E���W�X�^ */
#define	CDR			0xFFFFF36E		/* IEBus�R���g���[���E�f�[�^�E���W�X�^ */
#define	DLR			0xFFFFF36F		/* IEBus�d�������W�X�^ */
#define	DR			0xFFFFF370		/* IEBus�f�[�^�E���W�X�^ */
#define	FSR			0xFFFFF371		/* IEBus�t�B�[���h�E�X�e�[�^�X�E���W�X�^ */
#define	SCR			0xFFFFF372		/* IEBus�T�N�Z�X�E�J�E���g�E���W�X�^ */
#define	CCR			0xFFFFF373		/* IEBus�R�~���j�P�[�V�����E�J�E���g�E���W�X�^ */
#define	P0			0xFFFFF400		/* �|�[�g0���W�X�^ */
#define	P1			0xFFFFF402		/* �|�[�g1���W�X�^ */
#define	P3			0xFFFFF406		/* �|�[�g3���W�X�^ */
#define	P3L			0xFFFFF406		/* �|�[�g3���W�X�^L */
#define	P3H			0xFFFFF407		/* �|�[�g3���W�X�^H */
#define	P4			0xFFFFF408		/* �|�[�g4���W�X�^ */
#define	P5			0xFFFFF40A		/* �|�[�g5���W�X�^ */
#define	P7L			0xFFFFF40E		/* �|�[�g7���W�X�^L */
#define	P7H			0xFFFFF40F		/* �|�[�g7���W�X�^H */
#define	P9			0xFFFFF412		/* �|�[�g9���W�X�^ */
#define	P9L			0xFFFFF412		/* �|�[�g9���W�X�^L */
#define	P9H			0xFFFFF413		/* �|�[�g9���W�X�^H */
#define	PM0			0xFFFFF420		/* �|�[�g0���[�h�E���W�X�^ */
#define	PM1			0xFFFFF422		/* �|�[�g1���[�h�E���W�X�^ */
#define	PM3			0xFFFFF426		/* �|�[�g3���[�h�E���W�X�^ */
#define	PM3L		0xFFFFF426		/* �|�[�g3���[�h�E���W�X�^L */
#define	PM3H		0xFFFFF427		/* �|�[�g3���[�h�E���W�X�^H */
#define	PM4			0xFFFFF428		/* �|�[�g4���[�h�E���W�X�^ */
#define	PM5			0xFFFFF42A		/* �|�[�g5���[�h�E���W�X�^ */
#define	PM7L		0xFFFFF42E		/* �|�[�g7���[�h�E���W�X�^L */
#define	PM7H		0xFFFFF42F		/* �|�[�g7���[�h�E���W�X�^H */
#define	PM9			0xFFFFF432		/* �|�[�g9���[�h�E���W�X�^ */
#define	PM9L		0xFFFFF432		/* �|�[�g9���[�h�E���W�X�^L */
#define	PM9H		0xFFFFF433		/* �|�[�g9���[�h�E���W�X�^H */
#define	PMC0		0xFFFFF440		/* �|�[�g0���[�h�E�R���g���[���E���W�X�^ */
#define	PMC3		0xFFFFF446		/* �|�[�g3���[�h�E�R���g���[���E���W�X�^ */
#define	PMC3L		0xFFFFF446		/* �|�[�g3���[�h�E�R���g���[���E���W�X�^L */
#define	PMC3H		0xFFFFF447		/* �|�[�g3���[�h�E�R���g���[���E���W�X�^H */
#define	PMC4		0xFFFFF448		/* �|�[�g4���[�h�E�R���g���[���E���W�X�^ */
#define	PMC5		0xFFFFF44A		/* �|�[�g5���[�h�E�R���g���[���E���W�X�^ */
#define	PMC9		0xFFFFF452		/* �|�[�g9���[�h�E�R���g���[���E���W�X�^ */
#define	PMC9L		0xFFFFF452		/* �|�[�g9���[�h�E�R���g���[���E���W�X�^L */
#define	PMC9H		0xFFFFF453		/* �|�[�g9���[�h�E�R���g���[���E���W�X�^H */
#define	PFC0		0xFFFFF460		/* �|�[�g0�t�@���N�V�����E�R���g���[���E���W�X�^ */
#define	PFC3		0xFFFFF466		/* �|�[�g3�t�@���N�V�����E�R���g���[���E���W�X�^ */
#define	PFC3L		0xFFFFF466		/* �|�[�g3�t�@���N�V�����E�R���g���[���E���W�X�^L */
#define	PFC3H		0xFFFFF467		/* �|�[�g3�t�@���N�V�����E�R���g���[���E���W�X�^H */
#define	PFC4		0xFFFFF468		/* �|�[�g4�t�@���N�V�����E�R���g���[���E���W�X�^ */
#define	PFC5		0xFFFFF46A		/* �|�[�g5�t�@���N�V�����E�R���g���[���E���W�X�^ */
#define	PFC9		0xFFFFF472		/* �|�[�g9�t�@���N�V�����E�R���g���[���E���W�X�^ */
#define	PFC9L		0xFFFFF472		/* �|�[�g9�t�@���N�V�����E�R���g���[���E���W�X�^L */
#define	PFC9H		0xFFFFF473		/* �|�[�g9�t�@���N�V�����E�R���g���[���E���W�X�^H */
#define	DWC0		0xFFFFF484		/* �f�[�^�E�E�G�C�g�E�R���g���[���E���W�X�^0 */
#define	AWC			0xFFFFF488		/* �A�h���X�E�E�G�C�g�E�R���g���[���E���W�X�^ */
#define	BCC			0xFFFFF48A		/* �o�X�E�T�C�N���E�R���g���[���E���W�X�^ */
#define	TQ0CTL0		0xFFFFF540		/* TMQ0���䃌�W�X�^0 */
#define	TQ0CTL1		0xFFFFF541		/* TMQ0���䃌�W�X�^1 */
#define	TQ0IOC0		0xFFFFF542		/* TMQ0I/O���䃌�W�X�^0 */
#define	TQ0IOC1		0xFFFFF543		/* TMQ0I/O���䃌�W�X�^1 */
#define	TQ0IOC2		0xFFFFF544		/* TMQ0I/O���䃌�W�X�^2 */
#define	TQ0OPT0		0xFFFFF545		/* TMQ0�I�v�V�����E���W�X�^ */
#define	TQ0CCR0		0xFFFFF546		/* TMQ0�L���v�`���^�R���y�A�E���W�X�^0 */
#define	TQ0CCR1		0xFFFFF548		/* TMQ0�L���v�`���^�R���y�A�E���W�X�^1 */
#define	TQ0CCR2		0xFFFFF54A		/* TMQ0�L���v�`���^�R���y�A�E���W�X�^2 */
#define	TQ0CCR3		0xFFFFF54C		/* TMQ0�L���v�`���^�R���y�A�E���W�X�^3 */
#define	TQ0CNT		0xFFFFF54E		/* TMQ0�J�E���^�E���[�h�E�o�b�t�@�E���W�X�^ */
#define	TP0CTL0		0xFFFFF590		/* TMP0���䃌�W�X�^0 */
#define	TP0CTL1		0xFFFFF591		/* TMP0���䃌�W�X�^1 */
#define	TP0IOC0		0xFFFFF592		/* TMP0I/O���䃌�W�X�^0 */
#define	TP0IOC1		0xFFFFF593		/* TMP0I/O���䃌�W�X�^1 */
#define	TP0IOC2		0xFFFFF594		/* TMP0I/O���䃌�W�X�^2 */
#define	TP0OPT0		0xFFFFF595		/* TMP0�I�v�V�����E���W�X�^ */
#define	TP0CCR0		0xFFFFF596		/* TMP0�L���v�`���^�R���y�A�E���W�X�^0 */
#define	TP0CCR1		0xFFFFF598		/* TMP0�L���v�`���^�R���y�A�E���W�X�^1 */
#define	TP0CNT		0xFFFFF59A		/* TMP0�J�E���^�E���[�h�E�o�b�t�@�E���W�X�^ */
#define	TP1CTL0		0xFFFFF5A0		/* TMP1���䃌�W�X�^0 */
#define	TP1CTL1		0xFFFFF5A1		/* TMP1���䃌�W�X�^1 */
#define	TP1IOC0		0xFFFFF5A2		/* TMP1I/O���䃌�W�X�^0 */
#define	TP1IOC1		0xFFFFF5A3		/* TMP1I/O���䃌�W�X�^1 */
#define	TP1IOC2		0xFFFFF5A4		/* TMP1I/O���䃌�W�X�^2 */
#define	TP1OPT0		0xFFFFF5A5		/* TMP1�I�v�V�����E���W�X�^ */
#define	TP1CCR0		0xFFFFF5A6		/* TMP1�L���v�`���^�R���y�A�E���W�X�^0 */
#define	TP1CCR1		0xFFFFF5A8		/* TMP1�L���v�`���^�R���y�A�E���W�X�^1 */
#define	TP1CNT		0xFFFFF5AA		/* TMP1�J�E���^�E���[�h�E�o�b�t�@�E���W�X�^ */
#define	TP2CTL0		0xFFFFF5B0		/* TMP2���䃌�W�X�^0 */
#define	TP2CTL1		0xFFFFF5B1		/* TMP2���䃌�W�X�^1 */
#define	TP2IOC0		0xFFFFF5B2		/* TMP2I/O���䃌�W�X�^0 */
#define	TP2IOC1		0xFFFFF5B3		/* TMP2I/O���䃌�W�X�^1 */
#define	TP2IOC2		0xFFFFF5B4		/* TMP2I/O���䃌�W�X�^2 */
#define	TP2OPT0		0xFFFFF5B5		/* TMP2�I�v�V�����E���W�X�^ */
#define	TP2CCR0		0xFFFFF5B6		/* TMP2�L���v�`���^�R���y�A�E���W�X�^0 */
#define	TP2CCR1		0xFFFFF5B8		/* TMP2�L���v�`���^�R���y�A�E���W�X�^1 */
#define	TP2CNT		0xFFFFF5BA		/* TMP2�J�E���^�E���[�h�E�o�b�t�@�E���W�X�^ */
#define	TP3CTL0		0xFFFFF5C0		/* TMP3���䃌�W�X�^0 */
#define	TP3CTL1		0xFFFFF5C1		/* TMP3���䃌�W�X�^1 */
#define	TP3IOC0		0xFFFFF5C2		/* TMP3I/O���䃌�W�X�^0 */
#define	TP3IOC1		0xFFFFF5C3		/* TMP3I/O���䃌�W�X�^1 */
#define	TP3IOC2		0xFFFFF5C4		/* TMP3I/O���䃌�W�X�^2 */
#define	TP3OPT0		0xFFFFF5C5		/* TMP3�I�v�V�����E���W�X�^ */
#define	TP3CCR0		0xFFFFF5C6		/* TMP3�L���v�`���^�R���y�A�E���W�X�^0 */
#define	TP3CCR1		0xFFFFF5C8		/* TMP3�L���v�`���^�R���y�A�E���W�X�^1 */
#define	TP3CNT		0xFFFFF5CA		/* TMP3�J�E���^�E���[�h�E�o�b�t�@�E���W�X�^ */
#define	TP4CTL0		0xFFFFF5D0		/* TMP4���䃌�W�X�^0 */
#define	TP4CTL1		0xFFFFF5D1		/* TMP4���䃌�W�X�^1 */
#define	TP4IOC0		0xFFFFF5D2		/* TMP4I/O���䃌�W�X�^0 */
#define	TP4IOC1		0xFFFFF5D3		/* TMP4I/O���䃌�W�X�^1 */
#define	TP4IOC2		0xFFFFF5D4		/* TMP4I/O���䃌�W�X�^2 */
#define	TP4OPT0		0xFFFFF5D5		/* TMP4�I�v�V�����E���W�X�^ */
#define	TP4CCR0		0xFFFFF5D6		/* TMP4�L���v�`���^�R���y�A�E���W�X�^0 */
#define	TP4CCR1		0xFFFFF5D8		/* TMP4�L���v�`���^�R���y�A�E���W�X�^1 */
#define	TP4CNT		0xFFFFF5DA		/* TMP4�J�E���^�E���[�h�E�o�b�t�@�E���W�X�^ */
#define	TP5CTL0		0xFFFFF5E0		/* TMP5���䃌�W�X�^0 */
#define	TP5CTL1		0xFFFFF5E1		/* TMP5���䃌�W�X�^1 */
#define	TP5IOC0		0xFFFFF5E2		/* TMP5I/O���䃌�W�X�^0 */
#define	TP5IOC1		0xFFFFF5E3		/* TMP5I/O���䃌�W�X�^1 */
#define	TP5IOC2		0xFFFFF5E4		/* TMP5I/O���䃌�W�X�^2 */
#define	TP5OPT0		0xFFFFF5E5		/* TMP5�I�v�V�����E���W�X�^ */
#define	TP5CCR0		0xFFFFF5E6		/* TMP5�L���v�`���^�R���y�A�E���W�X�^0 */
#define	TP5CCR1		0xFFFFF5E8		/* TMP5�L���v�`���^�R���y�A�E���W�X�^1 */
#define	TP5CNT		0xFFFFF5EA		/* TMP5�J�E���^�E���[�h�E�o�b�t�@�E���W�X�^ */
#define	WTM			0xFFFFF680		/* ���v�^�C�}���샂�[�h�E���W�X�^ */
#define	TM0CTL0		0xFFFFF690		/* TMM0���䃌�W�X�^0 */
#define	TM0CMP0		0xFFFFF694		/* TMM0�R���y�A�E���W�X�^0 */
#define	OSTS		0xFFFFF6C0		/* ���U���莞�ԑI�����W�X�^ */
#define	PLLS		0xFFFFF6C1		/* PLL���b�N�A�b�v���Ԏw�背�W�X�^ */
#define	WDTM2		0xFFFFF6D0		/* �E�H�b�`�h�b�O�E�^�C�}�E���[�h�E���W�X�^2 */
#define	WDTE		0xFFFFF6D1		/* �E�H�b�`�h�b�O�E�^�C�}�E�C�l�[�u���E���W�X�^ */
#define	RTBL0		0xFFFFF6E0		/* ���A���^�C���o�̓o�b�t�@�E���W�X�^0�k */
#define	RTBH0		0xFFFFF6E2		/* ���A���^�C���o�̓o�b�t�@�E���W�X�^0H */
#define	RTPM0		0xFFFFF6E4		/* ���A���^�C���o�̓|�[�g�E���[�h�E���W�X�^0 */
#define	RTPC0		0xFFFFF6E5		/* ���A���^�C���o�̓|�[�g�E�R���g���[���E���W�X�^0 */
#define	PFCE3L		0xFFFFF706		/* �|�[�g3�t�@���N�V�����E�R���g���[���g�����W�X�^L */
#define	PFCE5		0xFFFFF70A		/* �|�[�g5�t�@���N�V�����E�R���g���[���g�����W�X�^ */
#define	PFCE9		0xFFFFF712		/* �|�[�g9�t�@���N�V�����E�R���g���[���g�����W�X�^ */
#define	PFCE9L		0xFFFFF712		/* �|�[�g9�t�@���N�V�����E�R���g���[���g�����W�X�^L */
#define	PFCE9H		0xFFFFF713		/* �|�[�g9�t�@���N�V�����E�R���g���[���g�����W�X�^H */
#define	SYS			0xFFFFF802		/* �V�X�e���E�X�e�[�^�X�E���W�X�^ */
#define	RCM			0xFFFFF80C		/* �����OOSC���[�h�E���W�X�^ */
#define	DTFR0		0xFFFFF810		/* DMA�g���K�v�����W�X�^0 */
#define	DTFR1		0xFFFFF812		/* DMA�g���K�v�����W�X�^1 */
#define	DTFR2		0xFFFFF814		/* DMA�g���K�v�����W�X�^2 */
#define	DTFR3		0xFFFFF816		/* DMA�g���K�v�����W�X�^3 */
#define	PSMR		0xFFFFF820		/* �p���[�E�Z�[�u�E���[�h�E���W�X�^ */
#define	CKC			0xFFFFF822		/* �N���b�N�E�R���g���[���E���W�X�^ */
#define	LOCKR		0xFFFFF824		/* ���b�N�E���W�X�^ */
#define	PCC			0xFFFFF828		/* �v���Z�b�T�E�N���b�N�E�R���g���[���E���W�X�^ */
#define	PLLCTL		0xFFFFF82C		/* PLL�R���g���[���E���W�X�^ */
#define	CCLS		0xFFFFF82E		/* CPU����N���b�N�E�X�e�[�^�X�E���W�X�^ */
#define	CORAD0		0xFFFFF840		/* �R���N�V�����E�A�h���X�E���W�X�^0 */
#define	CORAD0L		0xFFFFF840		/* �R���N�V�����E�A�h���X�E���W�X�^0L */
#define	CORAD0H		0xFFFFF842		/* �R���N�V�����E�A�h���X�E���W�X�^0H */
#define	CORAD1		0xFFFFF844		/* �R���N�V�����E�A�h���X�E���W�X�^1 */
#define	CORAD1L		0xFFFFF844		/* �R���N�V�����E�A�h���X�E���W�X�^1L */
#define	CORAD1H		0xFFFFF846		/* �R���N�V�����E�A�h���X�E���W�X�^1H */
#define	CORAD2		0xFFFFF848		/* �R���N�V�����E�A�h���X�E���W�X�^2 */
#define	CORAD2L		0xFFFFF848		/* �R���N�V�����E�A�h���X�E���W�X�^2L */
#define	CORAD2H		0xFFFFF84A		/* �R���N�V�����E�A�h���X�E���W�X�^2H */
#define	CORAD3		0xFFFFF84C		/* �R���N�V�����E�A�h���X�E���W�X�^3 */
#define	CORAD3L		0xFFFFF84C		/* �R���N�V�����E�A�h���X�E���W�X�^3L */
#define	CORAD3H		0xFFFFF84E		/* �R���N�V�����E�A�h���X�E���W�X�^3H */
#define	CLM			0xFFFFF870		/* �N���b�N�E���j�^�E���[�h�E���W�X�^ */
#define	CORCN		0xFFFFF880		/* �R���N�V�����E�R���g���[���E���W�X�^ */
#define	RESF		0xFFFFF888		/* ���Z�b�g�v���t���O�E���W�X�^ */
#define	LVIM		0xFFFFF890		/* ��d�����o���W�X�^ */
#define	LVIS		0xFFFFF891		/* ��d�����o���x���I�����W�X�^ */
#define	RAMS		0xFFFFF892		/* ����RAM�f�[�^�E�X�e�[�^�X�E���W�X�^ */
#define	PRSM0		0xFFFFF8B0		/* �v���X�P�[���E���[�h�E���W�X�^ */
#define	PRSCM0		0xFFFFF8B1		/* �v���X�P�[���E�R���y�A�E���W�X�^ */
#define	OCDM		0xFFFFF9FC		/* �I���`�b�v�E�f�B�o�O�E���[�h�E���W�X�^ */
#define	PEMU1		0xFFFFF9FE		/* ���ӃG�~�����[�V�����E���W�X�^1 */
#define	UA0CTL0		0xFFFFFA00		/* UARTA0���䃌�W�X�^0 */
#define	UA0CTL1		0xFFFFFA01		/* UARTA0���䃌�W�X�^1 */
#define	UA0CTL2		0xFFFFFA02		/* UARTA0���䃌�W�X�^2 */
#define	UA0OPT0		0xFFFFFA03		/* UARTA0�I�v�V�������䃌�W�X�^0 */
#define	UA0STR		0xFFFFFA04		/* UARTA0��ԃ��W�X�^ */
#define	UA0RX		0xFFFFFA06		/* UARTA0��M�f�[�^�E���W�X�^ */
#define	UA0TX		0xFFFFFA07		/* UARTA0���M�f�[�^�E���W�X�^ */
#define	UA1CTL0		0xFFFFFA10		/* UARTA1���䃌�W�X�^0 */
#define	UA1CTL1		0xFFFFFA11		/* UARTA1���䃌�W�X�^1 */
#define	UA1CTL2		0xFFFFFA12		/* UARTA1���䃌�W�X�^2 */
#define	UA1OPT0		0xFFFFFA13		/* UARTA1�I�v�V�������䃌�W�X�^0 */
#define	UA1STR		0xFFFFFA14		/* UARTA1��ԃ��W�X�^ */
#define	UA1RX		0xFFFFFA16		/* UARTA1��M�f�[�^�E���W�X�^ */
#define	UA1TX		0xFFFFFA17		/* UARTA1���M�f�[�^�E���W�X�^ */
#define	UA2CTL0		0xFFFFFA20		/* UARTA2���䃌�W�X�^0 */
#define	UA2CTL1		0xFFFFFA21		/* UARTA2���䃌�W�X�^1 */
#define	UA2CTL2		0xFFFFFA22		/* UARTA2���䃌�W�X�^2 */
#define	UA2OPT0		0xFFFFFA23		/* UARTA2�I�v�V�������䃌�W�X�^0 */
#define	UA2STR		0xFFFFFA24		/* UARTA2��ԃ��W�X�^ */
#define	UA2RX		0xFFFFFA26		/* UARTA2��M�f�[�^�E���W�X�^ */
#define	UA2TX		0xFFFFFA27		/* UARTA2���M�f�[�^�E���W�X�^ */
#define	INTF0		0xFFFFFC00		/* �O�����荞�ݗ���������G�b�W�w�背�W�X�^0 */
#define	INTF3		0xFFFFFC06		/* �O�����荞�ݗ���������G�b�W�w�背�W�X�^3 */
#define	INTF9H		0xFFFFFC13		/* �O�����荞�ݗ���������G�b�W�w�背�W�X�^9H */
#define	INTR0		0xFFFFFC20		/* �O�����荞�ݗ����オ��G�b�W�w�背�W�X�^0 */
#define	INTR3		0xFFFFFC26		/* �O�����荞�ݗ����オ��G�b�W�w�背�W�X�^3 */
#define	INTR9H		0xFFFFFC33		/* �O�����荞�ݗ����オ��G�b�W�w�背�W�X�^9H */
#define	PF0			0xFFFFFC60		/* �|�[�g0�t�@���N�V�������䃌�W�X�^ */
#define	PF3			0xFFFFFC66		/* �|�[�g3�t�@���N�V�������䃌�W�X�^ */
#define	PF3L		0xFFFFFC66		/* �|�[�g3�t�@���N�V�������䃌�W�X�^L */
#define	PF3H		0xFFFFFC67		/* �|�[�g3�t�@���N�V�������䃌�W�X�^H */
#define	PF4			0xFFFFFC68		/* �|�[�g4�t�@���N�V�������䃌�W�X�^ */
#define	PF5			0xFFFFFC6A		/* �|�[�g5�t�@���N�V�������䃌�W�X�^ */
#define	PF9			0xFFFFFC72		/* �|�[�g9�t�@���N�V�������䃌�W�X�^ */
#define	PF9L		0xFFFFFC72		/* �|�[�g9�t�@���N�V�������䃌�W�X�^L */
#define	PF9H		0xFFFFFC73		/* �|�[�g9�t�@���N�V�������䃌�W�X�^H */
#define	CB0CTL0		0xFFFFFD00		/* CSIB0���䃌�W�X�^0 */
#define	CB0CTL1		0xFFFFFD01		/* CSIB0���䃌�W�X�^1 */
#define	CB0CTL2		0xFFFFFD02		/* CSIB0���䃌�W�X�^2 */
#define	CB0STR		0xFFFFFD03		/* CSIB0��ԃ��W�X�^ */
#define	CB0RX		0xFFFFFD04		/* CSIB0��M�f�[�^�E���W�X�^ */
#define	CB0RXL		0xFFFFFD04		/* CSIB0��M�f�[�^�E���W�X�^L */
#define	CB0TX		0xFFFFFD06		/* CSIB0���M�f�[�^�E���W�X�^ */
#define	CB0TXL		0xFFFFFD06		/* CSIB0���M�f�[�^�E���W�X�^L */
#define	CB1CTL0		0xFFFFFD10		/* CSIB1���䃌�W�X�^0 */
#define	CB1CTL1		0xFFFFFD11		/* CSIB1���䃌�W�X�^1 */
#define	CB1CTL2		0xFFFFFD12		/* CSIB1���䃌�W�X�^2 */
#define	CB1STR		0xFFFFFD13		/* CSIB1��ԃ��W�X�^ */
#define	CB1RX		0xFFFFFD14		/* CSIB1��M�f�[�^�E���W�X�^ */
#define	CB1RXL		0xFFFFFD14		/* CSIB1��M�f�[�^�E���W�X�^L */
#define	CB1TX		0xFFFFFD16		/* CSIB1���M�f�[�^�E���W�X�^ */
#define	CB1TXL		0xFFFFFD16		/* CSIB1���M�f�[�^�E���W�X�^L */
#define	CB2CTL0		0xFFFFFD20		/* CSIB2���䃌�W�X�^0 */
#define	CB2CTL1		0xFFFFFD21		/* CSIB2���䃌�W�X�^1 */
#define	CB2CTL2		0xFFFFFD22		/* CSIB2���䃌�W�X�^2 */
#define	CB2STR		0xFFFFFD23		/* CSIB2��ԃ��W�X�^ */
#define	CB2RX		0xFFFFFD24		/* CSIB2��M�f�[�^�E���W�X�^ */
#define	CB2RXL		0xFFFFFD24		/* CSIB2��M�f�[�^�E���W�X�^L */
#define	CB2TX		0xFFFFFD26		/* CSIB2���M�f�[�^�E���W�X�^ */
#define	CB2TXL		0xFFFFFD26		/* CSIB2���M�f�[�^�E���W�X�^L */
#define	CB3CTL0		0xFFFFFD30		/* CSIB3���䃌�W�X�^0 */
#define	CB3CTL1		0xFFFFFD31		/* CSIB3���䃌�W�X�^1 */
#define	CB3CTL2		0xFFFFFD32		/* CSIB3���䃌�W�X�^2 */
#define	CB3STR		0xFFFFFD33		/* CSIB3��ԃ��W�X�^ */
#define	CB3RX		0xFFFFFD34		/* CSIB3��M�f�[�^�E���W�X�^ */
#define	CB3RXL		0xFFFFFD34		/* CSIB3��M�f�[�^�E���W�X�^L */
#define	CB3TX		0xFFFFFD36		/* CSIB3���M�f�[�^�E���W�X�^ */
#define	CB3TXL		0xFFFFFD36		/* CSIB3���M�f�[�^�E���W�X�^L */
#define	CB4CTL0		0xFFFFFD40		/* CSIB4���䃌�W�X�^0 */
#define	CB4CTL1		0xFFFFFD41		/* CSIB4���䃌�W�X�^1 */
#define	CB4CTL2		0xFFFFFD42		/* CSIB4���䃌�W�X�^2 */
#define	CB4STR		0xFFFFFD43		/* CSIB4��ԃ��W�X�^ */
#define	CB4RX		0xFFFFFD44		/* CSIB4��M�f�[�^�E���W�X�^ */
#define	CB4RXL		0xFFFFFD44		/* CSIB4��M�f�[�^�E���W�X�^L */
#define	CB4TX		0xFFFFFD46		/* CSIB4���M�f�[�^�E���W�X�^ */
#define	CB4TXL		0xFFFFFD46		/* CSIB4���M�f�[�^�E���W�X�^L */
#define	IIC0		0xFFFFFD80		/* IIC�V�t�g�E���W�X�^0 */
#define	IICC0		0xFFFFFD82		/* IIC�R���g���[���E���W�X�^0 */
#define	SVA0		0xFFFFFD83		/* �X���[�u�E�A�h���X�E���W�X�^0 */
#define	IICCL0		0xFFFFFD84		/* IIC�N���b�N�I�����W�X�^0 */
#define	IICX0		0xFFFFFD85		/* IIC�@�\�g�����W�X�^0 */
#define	IICS0		0xFFFFFD86		/* IIC��ԃ��W�X�^0 */
#define	IICF0		0xFFFFFD8A		/* IIC�t���O�E���W�X�^0 */
#define	IIC1		0xFFFFFD90		/* IIC�V�t�g�E���W�X�^1 */
#define	IICC1		0xFFFFFD92		/* IIC�R���g���[���E���W�X�^1 */
#define	SVA1		0xFFFFFD93		/* IIC�X���[�u�E�A�h���X�E���W�X�^1 */
#define	IICCL1		0xFFFFFD94		/* IIC�N���b�N�I�����W�X�^1 */
#define	IICX1		0xFFFFFD95		/* IIC�@�\�g�����W�X�^1 */
#define	IICS1		0xFFFFFD96		/* IIC��ԃ��W�X�^1 */
#define	IICF1		0xFFFFFD9A		/* IIC�t���O�E���W�X�^1 */
#define	IIC2		0xFFFFFDA0		/* IIC�V�t�g�E���W�X�^2 */
#define	IICC2		0xFFFFFDA2		/* IIC�R���g���[���E���W�X�^2 */
#define	SVA2		0xFFFFFDA3		/* IIC�X���[�u�E�A�h���X�E���W�X�^2 */
#define	IICCL2		0xFFFFFDA4		/* IIC�N���b�N�I�����W�X�^2 */
#define	IICX2		0xFFFFFDA5		/* IIC�@�\�g�����W�X�^2 */
#define	IICS2		0xFFFFFDA6		/* IIC��ԃ��W�X�^2 */
#define	IICF2		0xFFFFFDAA		/* IIC�t���O�E���W�X�^2 */
#define	EXIMC		0xFFFFFFBE		/* �O���o�X�E�C���^�t�F�[�X�E���[�h�E�R���g���[���E���W�X�^ */

#endif	/* _V850ES_SG2_H_ */
