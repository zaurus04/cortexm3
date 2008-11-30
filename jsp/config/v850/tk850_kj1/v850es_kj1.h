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
 *  @(#) $Id: v850es_kj1.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#ifndef	_V850ES_KJ1_H_
#define	_V850ES_KJ1_H_
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
#define	IRAM_TOP	0x03FFB000		/* ����RAM�̐擪�A�h���X */
#define IRAM_SIZE	0x4000			/* ����RAM�̑傫�� 16Kbyte(uPD70F3318Y) */
/*
 * ����FlashROM
 */
#define	IROM_TOP	0x0000000		/* ����FlashROM�̐擪�A�h���X */
#define IROM_SIZE	0x40000			/* ����FlashROM�̑傫�� 256Kbyte(uPD70F3318Y) */

/* 
 * V850ES/KJ1��IO���W�X�^��`
 */
#define	PDL			0xFFFFF004		/* �|�[�gDL���W�X�^(0x0000) */
#define	PDLL		0xFFFFF004		/* �|�[�gDL���W�X�^L(0x00) */
#define	PDLH		0xFFFFF005		/* �|�[�gDL���W�X�^(0x00) */
#define	PDH			0xFFFFF006		/* �|�[�gDH���W�X�^(0x00) */
#define	PCS			0xFFFFF008		/* �|�[�gCS���W�X�^(0x00) */
#define	PCT			0xFFFFF00A		/* �|�[�gCT���W�X�^(0x00) */
#define	PCM			0xFFFFF00C		/* �|�[�gCM���W�X�^(0x00) */
#define	PCD			0xFFFFF00E		/* �|�[�gCD���W�X�^(0x00) */
#define	PMDL		0xFFFFF024		/* �|�[�gDL���[�h�E���W�X�^(0xFFFF) */
#define	PMDLL		0xFFFFF024		/* �|�[�gDL���[�h�E���W�X�^(0xFF) */
#define	PMDLH		0xFFFFF025		/* �|�[�gDL���[�h�E���W�X�^(0xFF) */
#define	PMDH		0xFFFFF026		/* �|�[�gDH���[�h�E���W�X�^(0xFF) */
#define	PMCS		0xFFFFF028		/* �|�[�gCS���[�h�E���W�X�^(0xFF) */
#define	PMCT		0xFFFFF02A		/* �|�[�gCT���[�h�E���W�X�^(0xFF) */
#define	PMCM		0xFFFFF02C		/* �|�[�gCM���[�h�E���W�X�^(0xFF) */
#define	PMCD		0xFFFFF02E		/* �|�[�gCD���[�h�E���W�X�^(0xFF) */
#define	PMCDL		0xFFFFF044		/* �|�[�gDL���[�h�E�R���g���[���E���W�X�^(0x0000) */
#define	PMCDLL		0xFFFFF044		/* �|�[�gDL���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMCDLH		0xFFFFF045		/* �|�[�gDL���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMCDH		0xFFFFF046		/* �|�[�gDH���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMCCS		0xFFFFF048		/* �|�[�gCS���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMCCT		0xFFFFF04A		/* �|�[�gCT���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMCCM		0xFFFFF04C		/* �|�[�gCM���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	BSC			0xFFFFF066		/* �o�X�E�T�C�Y�E�R���t�B�M�����[�V�����E���W�X�^(0x5555) */
#define	VSWC		0xFFFFF06E		/* �V�X�e���E�E�G�C�g�E�R���g���[���E���W�X�^(0x77) */
#define	IMR0		0xFFFFF100		/* ���荞�݃}�X�N���W�X�^(0xFFFF) */
#define	IMR0L		0xFFFFF100		/* ���荞�݃}�X�N�E���W�X�^0(0xFF) */
#define	IMR0H		0xFFFFF101		/* ���荞�݃}�X�N�E���W�X�^0(0xFF) */
#define	IMR1		0xFFFFF102		/* ���荞�݃}�X�N�E���W�X�^(0xFFFF) */
#define	IMR1L		0xFFFFF102		/* ���荞�݃}�X�N�E���W�X�^1(0xFF) */
#define	IMR1H		0xFFFFF103		/* ���荞�݃}�X�N�E���W�X�^1(0xFF) */
#define	IMR2		0xFFFFF104		/* ���荞�݃}�X�N�E���W�X�^(0xFFFF) */
#define	IMR2L		0xFFFFF104		/* ���荞�݃}�X�N�E���W�X�^2(0xFF) */
#define	IMR2H		0xFFFFF105		/* ���荞�݃}�X�N�E���W�X�^2(0xFF) */
#define	IMR3		0xFFFFF106		/* ���荞�݃}�X�N�E���W�X�^(0xFFFF) */
#define	IMR3L		0xFFFFF106		/* ���荞�݃}�X�N�E���W�X�^3(0xFF) */
#define	WDT1IC		0xFFFFF110		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	PIC0		0xFFFFF112		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	PIC1		0xFFFFF114		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	PIC2		0xFFFFF116		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	PIC3		0xFFFFF118		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	PIC4		0xFFFFF11A		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	PIC5		0xFFFFF11C		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	PIC6		0xFFFFF11E		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC00		0xFFFFF120		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC01		0xFFFFF122		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC10		0xFFFFF124		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC11		0xFFFFF126		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM5IC0		0xFFFFF128		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM5IC1		0xFFFFF12A		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	CSI0IC0		0xFFFFF12C		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	CSI0IC1		0xFFFFF12E		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	SREIC0		0xFFFFF130		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	SRIC0		0xFFFFF132		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	STIC0		0xFFFFF134		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	SREIC1		0xFFFFF136		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	SRIC1		0xFFFFF138		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	STIC1		0xFFFFF13A		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TMHIC0		0xFFFFF13C		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TMHIC1		0xFFFFF13E		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	CSIAIC0		0xFFFFF140		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	IICIC0		0xFFFFF142		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	ADIC		0xFFFFF144		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	KRIC		0xFFFFF146		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	WTIIC		0xFFFFF148		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	WTIC		0xFFFFF14A		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	BRGIC		0xFFFFF14C		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC20		0xFFFFF14E		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC21		0xFFFFF150		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC30		0xFFFFF152		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC31		0xFFFFF154		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	CSIAIC1		0xFFFFF156		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC40		0xFFFFF158		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC41		0xFFFFF15A		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC50		0xFFFFF15C		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TM0IC51		0xFFFFF15E		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	CSI0IC2		0xFFFFF160		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	SREIC2		0xFFFFF162		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	SRIC2		0xFFFFF164		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	STIC2		0xFFFFF166		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	IICIC1		0xFFFFF168		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TP0OVIC		0xFFFFF174		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TP0CCIC0	0xFFFFF176		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	TP0CCIC1	0xFFFFF178		/* ���荞�ݐ��䃌�W�X�^(0x47) */
#define	ISPR		0xFFFFF1FA		/* �C���T�[�r�X�E�v���C�I���e�B�E���W�X�^(0x00) */
#define	PRCMD		0xFFFFF1FC		/* �R�}���h�E���W�X�^(�s��) */
#define	PSC			0xFFFFF1FE		/* �p���[�E�Z�[�u�E�R���g���[���E���W�X�^(0x00) */
#define	ADM			0xFFFFF200		/* A/D�R���o�[�^�E���[�h�E���W�X�^(0x00) */
#define	ADS			0xFFFFF201		/* �A�i���O���̓`���l���w�背�W�X�^(0x00) */
#define	PFM			0xFFFFF202		/* �p���[�E�t�F�C����r���[�h�E���W�X�^(0x00) */
#define	PFT			0xFFFFF203		/* �p���[�E�t�F�C����r�������l���W�X�^(0x00) */
#define	ADCR		0xFFFFF204		/* A/D�ϊ����ʃ��W�X�^(�s��) */
#define	ADCRH		0xFFFFF205		/* A/D�ϊ����ʃ��W�X�^(�s��) */
#define	DACS0		0xFFFFF280		/* D/A�ϊ��l�ݒ背�W�X�^(0x00) */
#define	DACS1		0xFFFFF282		/* D/A�ϊ��l�ݒ背�W�X�^(0x00) */
#define	DAM			0xFFFFF284		/* D/A�R���o�[�^�E���[�h�E���W�X�^(0x00) */
#define	KRM			0xFFFFF300		/* �L�[�E���^�[���E���[�h�E���W�X�^(0x00) */
#define	P0			0xFFFFF400		/* �|�[�g0���W�X�^(0x00) */
#define	P1			0xFFFFF402		/* �|�[�g1���W�X�^(0x00) */
#define	P3			0xFFFFF406		/* �|�[�g3���W�X�^(0x0000) */
#define	P3L			0xFFFFF406		/* �|�[�g3���W�X�^(0x00) */
#define	P3H			0xFFFFF407		/* �|�[�g3���W�X�^(0x00) */
#define	P4			0xFFFFF408		/* �|�[�g4���W�X�^(0x00) */
#define	P5			0xFFFFF40A		/* �|�[�g5���W�X�^(0x00) */
#define	P6			0xFFFFF40C		/* �|�[�g6���W�X�^(0x0000) */
#define	P6L			0xFFFFF40C		/* �|�[�g6���W�X�^(0x00) */
#define	P6H			0xFFFFF40D		/* �|�[�g6���W�X�^(0x00) */
#define	P7			0xFFFFF40E		/* �|�[�g7���W�X�^(�s��) */
#define	P7L			0xFFFFF40E		/* �|�[�g7���W�X�^(�s��) */
#define	P7H			0xFFFFF40F		/* �|�[�g7���W�X�^(�s��) */
#define	P8			0xFFFFF410		/* �|�[�g8���W�X�^(0x00) */
#define	P9			0xFFFFF412		/* �|�[�g9���W�X�^(0x0000) */
#define	P9L			0xFFFFF412		/* �|�[�g9���W�X�^(0x00) */
#define	P9H			0xFFFFF413		/* �|�[�g9���W�X�^(0x00) */
#define	PM0			0xFFFFF420		/* �|�[�g0���[�h�E���W�X�^(0xFF) */
#define	PM1			0xFFFFF422		/* �|�[�g1���[�h�E���W�X�^(0xFF) */
#define	PM3			0xFFFFF426		/* �|�[�g3���[�h�E���W�X�^(0xFFFF) */
#define	PM3L		0xFFFFF426		/* �|�[�g3���[�h�E���W�X�^(0xFF) */
#define	PM3H		0xFFFFF427		/* �|�[�g3���[�h�E���W�X�^(0xFF) */
#define	PM4			0xFFFFF428		/* �|�[�g4���[�h�E���W�X�^(0xFF) */
#define	PM5			0xFFFFF42A		/* �|�[�g5���[�h�E���W�X�^(0xFF) */
#define	PM6			0xFFFFF42C		/* �|�[�g6���[�h�E���W�X�^(0xFFFF) */
#define	PM6L		0xFFFFF42C		/* �|�[�g6���[�h�E���W�X�^(0xFF) */
#define	PM6H		0xFFFFF42D		/* �|�[�g6���[�h�E���W�X�^(0xFF) */
#define	PM8			0xFFFFF430		/* �|�[�g8���[�h�E���W�X�^(0xFF) */
#define	PM9			0xFFFFF432		/* �|�[�g9���[�h�E���W�X�^(0xFFFF) */
#define	PM9L		0xFFFFF432		/* �|�[�g9���[�h�E���W�X�^(0xFF) */
#define	PM9H		0xFFFFF433		/* �|�[�g9���[�h�E���W�X�^(0xFF) */
#define	PMC0		0xFFFFF440		/* �|�[�g0���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMC3		0xFFFFF446		/* �|�[�g3���[�h�E�R���g���[���E���W�X�^(0x0000) */
#define	PMC3L		0xFFFFF446		/* �|�[�g3���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMC3H		0xFFFFF447		/* �|�[�g3���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMC4		0xFFFFF448		/* �|�[�g4���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMC5		0xFFFFF44A		/* �|�[�g5���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMC6		0xFFFFF44C		/* �|�[�g6���[�h�E�R���g���[���E���W�X�^(0x0000) */
#define	PMC6L		0xFFFFF44C		/* �|�[�g6���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMC6H		0xFFFFF44D		/* �|�[�g6���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMC8		0xFFFFF450		/* �|�[�g8���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMC9		0xFFFFF452		/* �|�[�g9���[�h�E�R���g���[���E���W�X�^(0x0000) */
#define	PMC9L		0xFFFFF452		/* �|�[�g9���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PMC9H		0xFFFFF453		/* �|�[�g9���[�h�E�R���g���[���E���W�X�^(0x00) */
#define	PFC3		0xFFFFF466		/* �|�[�g3�t�@���N�V�����E�R���g���[���E���W�X�^(0x00) */
#define	PFC5		0xFFFFF46A		/* �|�[�g5�t�@���N�V�����E�R���g���[���E���W�X�^(0x00) */
#define	PFC6H		0xFFFFF46D		/* �|�[�g6�t�@���N�V�����E�R���g���[���E���W�X�^(0x00) */
#define	PFC8		0xFFFFF470		/* �|�[�g8�t�@���N�V�����E�R���g���[���E���W�X�^(0x00) */
#define	PFC9		0xFFFFF472		/* �|�[�g9�t�@���N�V�����E�R���g���[���E���W�X�^(0x0000) */
#define	PFC9L		0xFFFFF472		/* �|�[�g9�t�@���N�V�����E�R���g���[���E���W�X�^(0x00) */
#define	PFC9H		0xFFFFF473		/* �|�[�g9�t�@���N�V�����E�R���g���[���E���W�X�^(0x00) */
#define	DWC0		0xFFFFF484		/* �f�[�^�E�E�G�C�g���䃌�W�X�^(0x7777) */
#define	AWC			0xFFFFF488		/* �A�h���X�E�E�G�C�g���䃌�W�X�^(0xFFFF) */
#define	BCC			0xFFFFF48A		/* �o�X�E�T�C�N�����䃌�W�X�^(0xAAAA) */
#define	TMHMD0		0xFFFFF580		/* 8�r�b�g�E�^�C�}H���[�h�E���W�X�^(0x00) */
#define	TMCYC0		0xFFFFF581		/* 8�r�b�g�E�^�C�}H�L�����A�E�R���g���[���E���W�X�^(0x00) */
#define	CMP00		0xFFFFF582		/* 8�r�b�g�E�^�C�}H�R���y�A�E���W�X�^0(0x00) */
#define	CMP01		0xFFFFF583		/* 8�r�b�g�E�^�C�}H�R���y�A�E���W�X�^0(0x00) */
#define	TMHMD1		0xFFFFF590		/* 8�r�b�g�E�^�C�}H���[�h�E���W�X�^(0x00) */
#define	TMCYC1		0xFFFFF591		/* 8�r�b�g�E�^�C�}H�L�����A�E�R���g���[���E���W�X�^(0x00) */
#define	CMP10		0xFFFFF592		/* 8�r�b�g�E�^�C�}H�R���y�A�E���W�X�^1(0x00) */
#define	CMP11		0xFFFFF593		/* 8�r�b�g�E�^�C�}H�R���y�A�E���W�X�^1(0x00) */
#define	TP0CTL0		0xFFFFF5A0		/* TMP0���䃌�W�X�^(0x00) */
#define	TP0CTL1		0xFFFFF5A1		/* TMP0���䃌�W�X�^(0x00) */
#define	TP0IOC0		0xFFFFF5A2		/* TMP0I/O���䃌�W�X�^(0x00) */
#define	TP0IOC1		0xFFFFF5A3		/* TMP0I/O���䃌�W�X�^(0x00) */
#define	TP0IOC2		0xFFFFF5A4		/* TMP0I/O���䃌�W�X�^(0x00) */
#define	TP0OPT0		0xFFFFF5A5		/* TMP0�I�v�V�����E���W�X�^(0x00) */
#define	TP0CCR0		0xFFFFF5A6		/* TMP0�L���v�`���^�R���y�A�E���W�X�^(0x0000) */
#define	TP0CCR1		0xFFFFF5A8		/* TMP0�L���v�`���^�R���y�A�E���W�X�^(0x0000) */
#define	TP0CNT		0xFFFFF5AA		/* TMP0�J�E���^�E���[�h�E�o�b�t�@�E���W�X�^(0x0000) */
#define	TM5			0xFFFFF5C0		/* 16�r�b�g�E�^�C�}�E�J�E���^(0x0000) */
#define	TM50		0xFFFFF5C0		/* 8�r�b�g�E�^�C�}�E�J�E���^5(0x00) */
#define	TM51		0xFFFFF5C1		/* 8�r�b�g�E�^�C�}�E�J�E���^5(0x00) */
#define	CR5			0xFFFFF5C2		/* 16�r�b�g�E�^�C�}�E�R���y�A�E���W�X�^(0x0000) */
#define	CR50		0xFFFFF5C2		/* 8�r�b�g�E�^�C�}�E�R���y�A�E���W�X�^5(0x00) */
#define	CR51		0xFFFFF5C3		/* 8�r�b�g�E�^�C�}�E�R���y�A�E���W�X�^5(0x00) */
#define	TCL5		0xFFFFF5C4		/* �^�C�}�E�N���b�N�I�����W�X�^(0x0000) */
#define	TCL50		0xFFFFF5C4		/* �^�C�}�E�N���b�N�I�����W�X�^5(0x00) */
#define	TCL51		0xFFFFF5C5		/* �^�C�}�E�N���b�N�I�����W�X�^5(0x00) */
#define	TMC5		0xFFFFF5C6		/* 16�r�b�g�E�^�C�}�E���[�h�E�R���g���[���E���W�X�^(0x0000) */
#define	TMC50		0xFFFFF5C6		/* 8�r�b�g�E�^�C�}�E���[�h�E�R���g���[���E���W�X�^5(0x00) */
#define	TMC51		0xFFFFF5C7		/* 8�r�b�g�E�^�C�}�E���[�h�E�R���g���[���E���W�X�^5(0x00) */
#define	TM00		0xFFFFF600		/* 16�r�b�g�E�^�C�}�E�J�E���^0(0x0000) */
#define	CR000		0xFFFFF602		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^00(0x0000) */
#define	CR001		0xFFFFF604		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^00(0x0000) */
#define	TMC00		0xFFFFF606		/* 16�r�b�g�E�^�C�}�E���[�h�E�R���g���[���E���W�X�^0(0x00) */
#define	PRM00		0xFFFFF607		/* �v���X�P�[���E���[�h�E���W�X�^0(0x00) */
#define	CRC00		0xFFFFF608		/* �L���v�`���^�R���y�A�E�R���g���[���E���W�X�^0(0x00) */
#define	TOC00		0xFFFFF609		/* 16�r�b�g�E�^�C�}�o�̓R���g���[���E���W�X�^0(0x00) */
#define	TM01		0xFFFFF610		/* 16�r�b�g�E�^�C�}�E�J�E���^0(0x0000) */
#define	CR010		0xFFFFF612		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^01(0x0000) */
#define	CR011		0xFFFFF614		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^01(0x0000) */
#define	TMC01		0xFFFFF616		/* 16�r�b�g�E�^�C�}�E���[�h�E�R���g���[���E���W�X�^0(0x00) */
#define	PRM01		0xFFFFF617		/* �v���X�P�[���E���[�h�E���W�X�^0(0x00) */
#define	CRC01		0xFFFFF618		/* �L���v�`���^�R���y�A�E�R���g���[���E���W�X�^0(0x00) */
#define	TOC01		0xFFFFF619		/* 16�r�b�g�E�^�C�}�o�̓R���g���[���E���W�X�^0(0x00) */
#define	TM02		0xFFFFF620		/* 16�r�b�g�E�^�C�}�E�J�E���^0(0x0000) */
#define	CR020		0xFFFFF622		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^02(0x0000) */
#define	CR021		0xFFFFF624		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^02(0x0000) */
#define	TMC02		0xFFFFF626		/* 16�r�b�g�E�^�C�}�E���[�h�E�R���g���[���E���W�X�^0(0x00) */
#define	PRM02		0xFFFFF627		/* �v���X�P�[���E���[�h�E���W�X�^0(0x00) */
#define	CRC02		0xFFFFF628		/* �L���v�`���^�R���y�A�E�R���g���[���E���W�X�^0(0x00) */
#define	TOC02		0xFFFFF629		/* 16�r�b�g�E�^�C�}�o�̓R���g���[���E���W�X�^0(0x00) */
#define	TM03		0xFFFFF630		/* 16�r�b�g�E�^�C�}�E�J�E���^0(0x0000) */
#define	CR030		0xFFFFF632		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^03(0x0000) */
#define	CR031		0xFFFFF634		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^03(0x0000) */
#define	TMC03		0xFFFFF636		/* 16�r�b�g�E�^�C�}�E���[�h�E�R���g���[���E���W�X�^0(0x00) */
#define	PRM03		0xFFFFF637		/* �v���X�P�[���E���[�h�E���W�X�^0(0x00) */
#define	CRC03		0xFFFFF638		/* �L���v�`���^�R���y�A�E�R���g���[���E���W�X�^0(0x00) */
#define	TOC03		0xFFFFF639		/* 16�r�b�g�E�^�C�}�o�̓R���g���[���E���W�X�^0(0x00) */
#define	TM04		0xFFFFF640		/* 16�r�b�g�E�^�C�}�E�J�E���^0(0x0000) */
#define	CR040		0xFFFFF642		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^04(0x0000) */
#define	CR041		0xFFFFF644		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^04(0x0000) */
#define	TMC04		0xFFFFF646		/* 16�r�b�g�E�^�C�}�E���[�h�E�R���g���[���E���W�X�^0(0x00) */
#define	PRM04		0xFFFFF647		/* �v���X�P�[���E���[�h�E���W�X�^0(0x00) */
#define	CRC04		0xFFFFF648		/* �L���v�`���^�R���y�A�E�R���g���[���E���W�X�^0(0x00) */
#define	TOC04		0xFFFFF649		/* 16�r�b�g�E�^�C�}�o�̓R���g���[���E���W�X�^0(0x00) */
#define	TM05		0xFFFFF650		/* 16�r�b�g�E�^�C�}�E�J�E���^0(0x0000) */
#define	CR050		0xFFFFF652		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^05(0x0000) */
#define	CR051		0xFFFFF654		/* 16�r�b�g�E�^�C�}�E�L���v�`���^�R���y�A�E���W�X�^05(0x0000) */
#define	TMC05		0xFFFFF656		/* 16�r�b�g�E�^�C�}�E���[�h�E�R���g���[���E���W�X�^0(0x00) */
#define	PRM05		0xFFFFF657		/* �v���X�P�[���E���[�h�E���W�X�^0(0x00) */
#define	CRC05		0xFFFFF658		/* �L���v�`���^�R���y�A�E�R���g���[���E���W�X�^0(0x00) */
#define	TOC05		0xFFFFF659		/* 16�r�b�g�E�^�C�}�o�̓R���g���[���E���W�X�^0(0x00) */
#define	WTM			0xFFFFF680		/* ���v�^�C�}���샂�[�h�E���W�X�^(0x00) */
#define	OSTS		0xFFFFF6C0		/* ���U���莞�ԑI�����W�X�^(0x01) */
#define	WDCS		0xFFFFF6C1		/* �E�H�b�`�h�b�O�E�^�C�}�E�N���b�N�I�����W�X�^(0x00) */
#define	WDTM1		0xFFFFF6C2		/* �E�H�b�`�h�b�O�E�^�C�}�E���[�h�E���W�X�^(0x00) */
#define	WDTM2		0xFFFFF6D0		/* �E�H�b�`�h�b�O�E�^�C�}�E���[�h�E���W�X�^(0x67) */
#define	WDTE		0xFFFFF6D1		/* �E�H�b�`�h�b�O�E�^�C�}�E�C�l�[�u���E���W�X�^(0x9A) */
#define	RTBL0		0xFFFFF6E0		/* ���A���^�C���o�̓o�b�t�@�E���W�X�^L(0x00) */
#define	RTBH0		0xFFFFF6E2		/* ���A���^�C���o�̓o�b�t�@�E���W�X�^H(0x00) */
#define	RTPM0		0xFFFFF6E4		/* ���A���^�C���o�̓|�[�g�E���[�h�E���W�X�^(0x00) */
#define	RTPC0		0xFFFFF6E5		/* ���A���^�C���o�̓|�[�g�E�R���g���[���E���W�X�^(0x00) */
#define	RTBL1		0xFFFFF6F0		/* ���A���^�C���o�̓o�b�t�@�E���W�X�^L(0x00) */
#define	RTBH1		0xFFFFF6F2		/* ���A���^�C���o�̓o�b�t�@�E���W�X�^H(0x00) */
#define	RTPM1		0xFFFFF6F4		/* ���A���^�C���o�̓|�[�g�E���[�h�E���W�X�^(0x00) */
#define	RTPC1		0xFFFFF6F5		/* ���A���^�C���o�̓|�[�g�E�R���g���[���E���W�X�^(0x00) */
#define	PFCE3		0xFFFFF706		/* �|�[�g3�t�@���N�V�����E�R���g���[���g�����W�X�^(0x00) */
#define	SYS			0xFFFFF802		/* �V�X�e���E�X�e�[�^�X�E���W�X�^(0x00) */
#define	PLLCTL		0xFFFFF806		/* PLL�R���g���[���E���W�X�^(0x01) */
#define	PSMR		0xFFFFF820		/* �p���[�E�Z�[�u�E���[�h�E���W�X�^(0x00) */
#define	PCC			0xFFFFF828		/* �v���Z�b�T�E�N���b�N�E�R���g���[���E���W�X�^(0x03) */
#define	CORAD0		0xFFFFF840		/* �R���N�V�����E�A�h���X�E���W�X�^(0x00000000) */
#define	CORAD0L		0xFFFFF840		/* �R���N�V�����E�A�h���X�E���W�X�^0(0x0000) */
#define	CORAD0H		0xFFFFF842		/* �R���N�V�����E�A�h���X�E���W�X�^0(0x0000) */
#define	CORAD1		0xFFFFF844		/* �R���N�V�����E�A�h���X�E���W�X�^(0x00000000) */
#define	CORAD1L		0xFFFFF844		/* �R���N�V�����E�A�h���X�E���W�X�^1(0x0000) */
#define	CORAD1H		0xFFFFF846		/* �R���N�V�����E�A�h���X�E���W�X�^1(0x0000) */
#define	CORAD2		0xFFFFF848		/* �R���N�V�����E�A�h���X�E���W�X�^(0x00000000) */
#define	CORAD2L		0xFFFFF848		/* �R���N�V�����E�A�h���X�E���W�X�^2(0x0000) */
#define	CORAD2H		0xFFFFF84A		/* �R���N�V�����E�A�h���X�E���W�X�^2(0x0000) */
#define	CORAD3		0xFFFFF84C		/* �R���N�V�����E�A�h���X�E���W�X�^(0x00000000) */
#define	CORAD3L		0xFFFFF84C		/* �R���N�V�����E�A�h���X�E���W�X�^3(0x0000) */
#define	CORAD3H		0xFFFFF84E		/* �R���N�V�����E�A�h���X�E���W�X�^3(0x0000) */
#define	CORCN		0xFFFFF880		/* �R���N�V�����E�R���g���[���E���W�X�^(0x00) */
#define	PRSM		0xFFFFF8B0		/* �C���^�[�o���E�^�C�}BRG���[�h�E���W�X�^(0x00) */
#define	PRSCM		0xFFFFF8B1		/* �C���^�[�o���E�^�C�}BRG�R���y�A�E���W�X�^(0x00) */
#define	OCDM		0xFFFFF9FC		/* �I���`�b�v�E�f�B�o�O�E���[�h�E���W�X�^(0x01) */
#define	ASIM0		0xFFFFFA00		/* �A�V���N���i�X�E�V���A���E�C���^�t�F�[�X�E���[�h�E���W�X�^(0x01) */
#define	RXB0		0xFFFFFA02		/* ��M�o�b�t�@�E���W�X�^(0xFF) */
#define	ASIS0		0xFFFFFA03		/* �A�V���N���i�X�E�V���A���E�C���^�t�F�[�X�E�X�e�[�^�X�E���W�X�^(0x00) */
#define	TXB0		0xFFFFFA04		/* ���M�o�b�t�@�E���W�X�^(0xFF) */
#define	ASIF0		0xFFFFFA05		/* �A�V���N���i�X�E�V���A���E�C���^�t�F�[�X���M�X�e�[�^�X�E���W�X�^(0x00) */
#define	CKSR0		0xFFFFFA06		/* �N���b�N�I�����W�X�^(0x00) */
#define	BRGC0		0xFFFFFA07		/* �{�[�E���[�g�E�W�F�l���[�^�E�R���g���[���E���W�X�^(0xFF) */
#define	ASIM1		0xFFFFFA10		/* �A�V���N���i�X�E�V���A���E�C���^�t�F�[�X�E���[�h�E���W�X�^(0x01) */
#define	RXB1		0xFFFFFA12		/* ��M�o�b�t�@�E���W�X�^(0xFF) */
#define	ASIS1		0xFFFFFA13		/* �A�V���N���i�X�E�V���A���E�C���^�t�F�[�X�E�X�e�[�^�X�E���W�X�^(0x00) */
#define	TXB1		0xFFFFFA14		/* ���M�o�b�t�@�E���W�X�^(0xFF) */
#define	ASIF1		0xFFFFFA15		/* �A�V���N���i�X�E�V���A���E�C���^�t�F�[�X���M�X�e�[�^�X�E���W�X�^(0x00) */
#define	CKSR1		0xFFFFFA16		/* �N���b�N�I�����W�X�^(0x00) */
#define	BRGC1		0xFFFFFA17		/* �{�[�E���[�g�E�W�F�l���[�^�E�R���g���[���E���W�X�^(0xFF) */
#define	ASIM2		0xFFFFFA20		/* �A�V���N���i�X�E�V���A���E�C���^�t�F�[�X�E���[�h�E���W�X�^(0x01) */
#define	RXB2		0xFFFFFA22		/* ��M�o�b�t�@�E���W�X�^(0xFF) */
#define	ASIS2		0xFFFFFA23		/* �A�V���N���i�X�E�V���A���E�C���^�t�F�[�X�E�X�e�[�^�X�E���W�X�^(0x00) */
#define	TXB2		0xFFFFFA24		/* ���M�o�b�t�@�E���W�X�^(0xFF) */
#define	ASIF2		0xFFFFFA25		/* �A�V���N���i�X�E�V���A���E�C���^�t�F�[�X���M�X�e�[�^�X�E���W�X�^(0x00) */
#define	CKSR2		0xFFFFFA26		/* �N���b�N�I�����W�X�^(0x00) */
#define	BRGC2		0xFFFFFA27		/* �{�[�E���[�g�E�W�F�l���[�^�E�R���g���[���E���W�X�^(0xFF) */
#define	P0NFC		0xFFFFFB00		/* TIP00�m�C�Y�������䃌�W�X�^(0x00) */
#define	P1NFC		0xFFFFFB04		/* TIP01�m�C�Y�������䃌�W�X�^(0x00) */
#define	INTF0		0xFFFFFC00		/* �O�����荞�ݗ���������G�b�W�w�背�W�X�^(0x00) */
#define	INTF9H		0xFFFFFC13		/* �O�����荞�ݗ���������G�b�W�w�背�W�X�^9(0x00) */
#define	INTR0		0xFFFFFC20		/* �O�����荞�ݗ����オ��G�b�W�w�背�W�X�^(0x00) */
#define	INTR9H		0xFFFFFC33		/* �O�����荞�ݗ����オ��G�b�W�w�背�W�X�^9(0x00) */
#define	PU0			0xFFFFFC40		/* �v���A�b�v��R�I�v�V�����E���W�X�^(0x00) */
#define	PU1			0xFFFFFC42		/* �v���A�b�v��R�I�v�V�����E���W�X�^(0x00) */
#define	PU3			0xFFFFFC46		/* �v���A�b�v��R�I�v�V�����E���W�X�^(0x00) */
#define	PU4			0xFFFFFC48		/* �v���A�b�v��R�I�v�V�����E���W�X�^(0x00) */
#define	PU5			0xFFFFFC4A		/* �v���A�b�v��R�I�v�V�����E���W�X�^(0x00) */
#define	PU6			0xFFFFFC4C		/* �v���A�b�v��R�I�v�V�����E���W�X�^(0x0000) */
#define	PU6L		0xFFFFFC4C		/* �v���A�b�v��R�I�v�V�����E���W�X�^6(0x00) */
#define	PU6H		0xFFFFFC4D		/* �v���A�b�v��R�I�v�V�����E���W�X�^6(0x00) */
#define	PU8			0xFFFFFC50		/* �v���A�b�v��R�I�v�V�����E���W�X�^(0x00) */
#define	PU9			0xFFFFFC52		/* �v���A�b�v��R�I�v�V�����E���W�X�^(0x0000) */
#define	PU9L		0xFFFFFC52		/* �v���A�b�v��R�I�v�V�����E���W�X�^9(0x00) */
#define	PU9H		0xFFFFFC53		/* �v���A�b�v��R�I�v�V�����E���W�X�^9(0x00) */
#define	PF3H		0xFFFFFC67		/* �|�[�g3�t�@���N�V�����E���W�X�^(0x00) */
#define	PF4			0xFFFFFC68		/* �|�[�g4�t�@���N�V�����E���W�X�^(0x00) */
#define	PF5			0xFFFFFC6A		/* �|�[�g5�t�@���N�V�����E���W�X�^(0x00) */
#define	PF6			0xFFFFFC6C		/* �|�[�g6�t�@���N�V�����E���W�X�^(0x0000) */
#define	PF6L		0xFFFFFC6C		/* �|�[�g6�t�@���N�V�����E���W�X�^(0x00) */
#define	PF6H		0xFFFFFC6D		/* �|�[�g6�t�@���N�V�����E���W�X�^(0x00) */
#define	PF8			0xFFFFFC70		/* �|�[�g8�t�@���N�V�����E���W�X�^(0x00) */
#define	PF9H		0xFFFFFC73		/* �|�[�g9�t�@���N�V�����E���W�X�^(0x00) */
#define	CSIM00		0xFFFFFD00		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E���[�h�E���W�X�^0(0x00) */
#define	CSIC0		0xFFFFFD01		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E�N���b�N�I�����W�X�^(0x00) */
#define	SIRB0		0xFFFFFD02		/* �N���b�N�������V���A���E�C���^�t�F�[�X��M�o�b�t�@�E���W�X�^(0x0000) */
#define	SIRB0L		0xFFFFFD02		/* �N���b�N�������V���A���E�C���^�t�F�[�X��M�o�b�t�@�E���W�X�^0(0x00) */
#define	SOTB0		0xFFFFFD04		/* �N���b�N�������V���A���E�C���^�t�F�[�X���M�o�b�t�@�E���W�X�^(0x0000) */
#define	SOTB0L		0xFFFFFD04		/* �N���b�N�������V���A���E�C���^�t�F�[�X���M�o�b�t�@�E���W�X�^0(0x00) */
#define	SIRBE0		0xFFFFFD06		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E���[�h��p��M�o�b�t�@�E���W�X�^(0x0000) */
#define	SIRBE0L		0xFFFFFD06		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E���[�h��p��M�o�b�t�@�E���W�X�^0(0x00) */
#define	SOTBF0		0xFFFFFD08		/* �N���b�N�������V���A���E�C���^�t�F�[�X���i���M�o�b�t�@�E���W�X�^(0x0000) */
#define	SOTBF0L		0xFFFFFD08		/* �N���b�N�������V���A���E�C���^�t�F�[�X���i���M�o�b�t�@�E���W�X�^0(0x00) */
#define	SIO00		0xFFFFFD0A		/* �V���A��I/O�V�t�g�E���W�X�^(0x00) */
#define	SIO00L		0xFFFFFD0A		/* �V���A��I/O�V�t�g�E���W�X�^0(0x0000) */
#define	CSIM01		0xFFFFFD10		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E���[�h�E���W�X�^0(0x00) */
#define	CSIC1		0xFFFFFD11		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E�N���b�N�I�����W�X�^(0x00) */
#define	SIRB1		0xFFFFFD12		/* �N���b�N�������V���A���E�C���^�t�F�[�X��M�o�b�t�@�E���W�X�^(0x0000) */
#define	SIRB1L		0xFFFFFD12		/* �N���b�N�������V���A���E�C���^�t�F�[�X��M�o�b�t�@�E���W�X�^1(0x00) */
#define	SOTB1		0xFFFFFD14		/* �N���b�N�������V���A���E�C���^�t�F�[�X���M�o�b�t�@�E���W�X�^(0x0000) */
#define	SOTB1L		0xFFFFFD14		/* �N���b�N�������V���A���E�C���^�t�F�[�X���M�o�b�t�@�E���W�X�^1(0x00) */
#define	SIRBE1		0xFFFFFD16		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E���[�h��p��M�o�b�t�@�E���W�X�^(0x0000) */
#define	SIRBE1L		0xFFFFFD16		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E���[�h��p��M�o�b�t�@�E���W�X�^1(0x00) */
#define	SOTBF1		0xFFFFFD18		/* �N���b�N�������V���A���E�C���^�t�F�[�X���i���M�o�b�t�@�E���W�X�^(0x0000) */
#define	SOTBF1L		0xFFFFFD18		/* �N���b�N�������V���A���E�C���^�t�F�[�X���i���M�o�b�t�@�E���W�X�^1(0x00) */
#define	SIO01		0xFFFFFD1A		/* �V���A��I/O�V�t�g�E���W�X�^(0x00) */
#define	SIO01L		0xFFFFFD1A		/* �V���A��I/O�V�t�g�E���W�X�^1(0x0000) */
#define	CSIM02		0xFFFFFD20		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E���[�h�E���W�X�^0(0x00) */
#define	CSIC2		0xFFFFFD21		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E�N���b�N�I�����W�X�^(0x00) */
#define	SIRB2		0xFFFFFD22		/* �N���b�N�������V���A���E�C���^�t�F�[�X��M�o�b�t�@�E���W�X�^(0x0000) */
#define	SIRB2L		0xFFFFFD22		/* �N���b�N�������V���A���E�C���^�t�F�[�X��M�o�b�t�@�E���W�X�^2(0x00) */
#define	SOTB2		0xFFFFFD24		/* �N���b�N�������V���A���E�C���^�t�F�[�X���M�o�b�t�@�E���W�X�^(0x0000) */
#define	SOTB2L		0xFFFFFD24		/* �N���b�N�������V���A���E�C���^�t�F�[�X���M�o�b�t�@�E���W�X�^2(0x00) */
#define	SIRBE2		0xFFFFFD26		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E���[�h��p��M�o�b�t�@�E���W�X�^(0x0000) */
#define	SIRBE2L		0xFFFFFD26		/* �N���b�N�������V���A���E�C���^�t�F�[�X�E���[�h��p��M�o�b�t�@�E���W�X�^2(0x00) */
#define	SOTBF2		0xFFFFFD28		/* �N���b�N�������V���A���E�C���^�t�F�[�X���i���M�o�b�t�@�E���W�X�^(0x0000) */
#define	SOTBF2L		0xFFFFFD28		/* �N���b�N�������V���A���E�C���^�t�F�[�X���i���M�o�b�t�@�E���W�X�^2(0x00) */
#define	SIO02		0xFFFFFD2A		/* �V���A��I/O�V�t�g�E���W�X�^(0x00) */
#define	SIO02L		0xFFFFFD2A		/* �V���A��I/O�V�t�g�E���W�X�^2(0x0000) */
#define	CSIMA0		0xFFFFFD40		/* �V���A�����샂�[�h�w�背�W�X�^(0x00) */
#define	CSIS0		0xFFFFFD41		/* �V���A���E�X�e�[�^�X�E���W�X�^(0x00) */
#define	CSIT0		0xFFFFFD42		/* �V���A���E�g���K�E���W�X�^(0x00) */
#define	BRGCA0		0xFFFFFD43		/* �����l�I�����W�X�^(0x03) */
#define	ADTP0		0xFFFFFD44		/* �����f�[�^�]���A�h���X�E�|�C���g�w�背�W�X�^(0x00) */
#define	ADTI0		0xFFFFFD45		/* �����f�[�^�]���Ԋu�w�背�W�X�^(0x00) */
#define	SIOA0		0xFFFFFD46		/* �V���A��I/O�V�t�g�E���W�X�^A(0x00) */
#define	ADTC0		0xFFFFFD47		/* �����f�[�^�]���A�h���X�E�J�E���g�E���W�X�^(0x00) */
#define	CSIMA1		0xFFFFFD50		/* �V���A�����샂�[�h�w�背�W�X�^(0x00) */
#define	CSIS1		0xFFFFFD51		/* �V���A���E�X�e�[�^�X�E���W�X�^(0x00) */
#define	CSIT1		0xFFFFFD52		/* �V���A���E�g���K�E���W�X�^(0x00) */
#define	BRGCA1		0xFFFFFD53		/* �����l�I�����W�X�^(0x03) */
#define	ADTP1		0xFFFFFD54		/* �����f�[�^�]���A�h���X�E�|�C���g�w�背�W�X�^(0x00) */
#define	ADTI1		0xFFFFFD55		/* �����f�[�^�]���Ԋu�w�背�W�X�^(0x00) */
#define	SIOA1		0xFFFFFD56		/* �V���A��I/O�V�t�g�E���W�X�^A(0x00) */
#define	ADTC1		0xFFFFFD57		/* �����f�[�^�]���A�h���X�E�J�E���g�E���W�X�^(0x00) */
#define	IIC0		0xFFFFFD80		/* IIC�V�t�g�E���W�X�^(0x00) */
#define	IICC0		0xFFFFFD82		/* IIC�R���g���[���E���W�X�^(0x00) */
#define	SVA0		0xFFFFFD83		/* �X���[�u�E�A�h���X�E���W�X�^(0x00) */
#define	IICCL0		0xFFFFFD84		/* IIC�N���b�N�I�����W�X�^(0x00) */
#define	IICX0		0xFFFFFD85		/* IIC�@�\�g�����W�X�^(0x00) */
#define	IICS0		0xFFFFFD86		/* IIC��ԃ��W�X�^(0x00) */
#define	IICF0		0xFFFFFD8A		/* IIC�t���O�E���W�X�^(0x00) */
#define	IIC1		0xFFFFFD90		/* IIC�V�t�g�E���W�X�^(0x00) */
#define	IICC01		0xFFFFFD92		/* IIC�R���g���[���E���W�X�^(0x00) */
#define	SVA01		0xFFFFFD93		/* �X���[�u�E�A�h���X�E���W�X�^(0x00) */
#define	IICCL01		0xFFFFFD94		/* IIC�N���b�N�I�����W�X�^(0x00) */
#define	IICX1		0xFFFFFD95		/* IIC�@�\�g�����W�X�^(0x00) */
#define	IICS01		0xFFFFFD96		/* IIC��ԃ��W�X�^(0x00) */
#define	IICF1		0xFFFFFD9A		/* IIC�t���O�E���W�X�^(0x00) */
#define	CSIA0B0		0xFFFFFE00		/* CSIA0�o�b�t�@RAM0(�s��) */
#define	CSIA0B0L	0xFFFFFE00		/* CSIA0�o�b�t�@RAM0L(�s��) */
#define	CSIA0B0H	0xFFFFFE01		/* CSIA0�o�b�t�@RAM0H(�s��) */
#define	CSIA0B1		0xFFFFFE02		/* CSIA0�o�b�t�@RAM1(�s��) */
#define	CSIA0B1L	0xFFFFFE02		/* CSIA0�o�b�t�@RAM1L(�s��) */
#define	CSIA0B1H	0xFFFFFE03		/* CSIA0�o�b�t�@RAM1H(�s��) */
#define	CSIA0B2		0xFFFFFE04		/* CSIA0�o�b�t�@RAM2(�s��) */
#define	CSIA0B2L	0xFFFFFE04		/* CSIA0�o�b�t�@RAM2L(�s��) */
#define	CSIA0B2H	0xFFFFFE05		/* CSIA0�o�b�t�@RAM2H(�s��) */
#define	CSIA0B3		0xFFFFFE06		/* CSIA0�o�b�t�@RAM3(�s��) */
#define	CSIA0B3L	0xFFFFFE06		/* CSIA0�o�b�t�@RAM3L(�s��) */
#define	CSIA0B3H	0xFFFFFE07		/* CSIA0�o�b�t�@RAM3H(�s��) */
#define	CSIA0B4		0xFFFFFE08		/* CSIA0�o�b�t�@RAM4(�s��) */
#define	CSIA0B4L	0xFFFFFE08		/* CSIA0�o�b�t�@RAM4L(�s��) */
#define	CSIA0B4H	0xFFFFFE09		/* CSIA0�o�b�t�@RAM4H(�s��) */
#define	CSIA0B5		0xFFFFFE0A		/* CSIA0�o�b�t�@RAM5(�s��) */
#define	CSIA0B5L	0xFFFFFE0A		/* CSIA0�o�b�t�@RAM5L(�s��) */
#define	CSIA0B5H	0xFFFFFE0B		/* CSIA0�o�b�t�@RAM5H(�s��) */
#define	CSIA0B6		0xFFFFFE0C		/* CSIA0�o�b�t�@RAM6(�s��) */
#define	CSIA0B6L	0xFFFFFE0C		/* CSIA0�o�b�t�@RAM6L(�s��) */
#define	CSIA0B6H	0xFFFFFE0D		/* CSIA0�o�b�t�@RAM6H(�s��) */
#define	CSIA0B7		0xFFFFFE0E		/* CSIA0�o�b�t�@RAM7(�s��) */
#define	CSIA0B7L	0xFFFFFE0E		/* CSIA0�o�b�t�@RAM7L(�s��) */
#define	CSIA0B7H	0xFFFFFE0F		/* CSIA0�o�b�t�@RAM7H(�s��) */
#define	CSIA0B8		0xFFFFFE10		/* CSIA0�o�b�t�@RAM8(�s��) */
#define	CSIA0B8L	0xFFFFFE10		/* CSIA0�o�b�t�@RAM8L(�s��) */
#define	CSIA0B8H	0xFFFFFE11		/* CSIA0�o�b�t�@RAM8H(�s��) */
#define	CSIA0B9		0xFFFFFE12		/* CSIA0�o�b�t�@RAM9(�s��) */
#define	CSIA0B9L	0xFFFFFE12		/* CSIA0�o�b�t�@RAM9L(�s��) */
#define	CSIA0B9H	0xFFFFFE13		/* CSIA0�o�b�t�@RAM9H(�s��) */
#define	CSIA0BA		0xFFFFFE14		/* CSIA0�o�b�t�@RAMA(�s��) */
#define	CSIA0BAL	0xFFFFFE14		/* CSIA0�o�b�t�@RAMAL(�s��) */
#define	CSIA0BAH	0xFFFFFE15		/* CSIA0�o�b�t�@RAMAH(�s��) */
#define	CSIA0BB		0xFFFFFE16		/* CSIA0�o�b�t�@RAMB(�s��) */
#define	CSIA0BBL	0xFFFFFE16		/* CSIA0�o�b�t�@RAMBL(�s��) */
#define	CSIA0BBH	0xFFFFFE17		/* CSIA0�o�b�t�@RAMBH(�s��) */
#define	CSIA0BC		0xFFFFFE18		/* CSIA0�o�b�t�@RAMC(�s��) */
#define	CSIA0BCL	0xFFFFFE18		/* CSIA0�o�b�t�@RAMCL(�s��) */
#define	CSIA0BCH	0xFFFFFE19		/* CSIA0�o�b�t�@RAMCH(�s��) */
#define	CSIA0BD		0xFFFFFE1A		/* CSIA0�o�b�t�@RAMD(�s��) */
#define	CSIA0BDL	0xFFFFFE1A		/* CSIA0�o�b�t�@RAMDL(�s��) */
#define	CSIA0BDH	0xFFFFFE1B		/* CSIA0�o�b�t�@RAMDH(�s��) */
#define	CSIA0BE		0xFFFFFE1C		/* CSIA0�o�b�t�@RAME(�s��) */
#define	CSIA0BEL	0xFFFFFE1C		/* CSIA0�o�b�t�@RAMEL(�s��) */
#define	CSIA0BEH	0xFFFFFE1D		/* CSIA0�o�b�t�@RAMEH(�s��) */
#define	CSIA0BF		0xFFFFFE1E		/* CSIA0�o�b�t�@RAMF(�s��) */
#define	CSIA0BFL	0xFFFFFE1E		/* CSIA0�o�b�t�@RAMFL(�s��) */
#define	CSIA0BFH	0xFFFFFE1F		/* CSIA0�o�b�t�@RAMFH(�s��) */
#define	CSIA1B0		0xFFFFFE20		/* CSIA1�o�b�t�@RAM0(�s��) */
#define	CSIA1B0L	0xFFFFFE20		/* CSIA1�o�b�t�@RAM0L(�s��) */
#define	CSIA1B0H	0xFFFFFE21		/* CSIA1�o�b�t�@RAM0H(�s��) */
#define	CSIA1B1		0xFFFFFE22		/* CSIA1�o�b�t�@RAM1(�s��) */
#define	CSIA1B1L	0xFFFFFE22		/* CSIA1�o�b�t�@RAM1L(�s��) */
#define	CSIA1B1H	0xFFFFFE23		/* CSIA1�o�b�t�@RAM1H(�s��) */
#define	CSIA1B2		0xFFFFFE24		/* CSIA1�o�b�t�@RAM2(�s��) */
#define	CSIA1B2L	0xFFFFFE24		/* CSIA1�o�b�t�@RAM2L(�s��) */
#define	CSIA1B2H	0xFFFFFE25		/* CSIA1�o�b�t�@RAM2H(�s��) */
#define	CSIA1B3		0xFFFFFE26		/* CSIA1�o�b�t�@RAM3(�s��) */
#define	CSIA1B3L	0xFFFFFE26		/* CSIA1�o�b�t�@RAM3L(�s��) */
#define	CSIA1B3H	0xFFFFFE27		/* CSIA1�o�b�t�@RAM3H(�s��) */
#define	CSIA1B4		0xFFFFFE28		/* CSIA1�o�b�t�@RAM4(�s��) */
#define	CSIA1B4L	0xFFFFFE28		/* CSIA1�o�b�t�@RAM4L(�s��) */
#define	CSIA1B4H	0xFFFFFE29		/* CSIA1�o�b�t�@RAM4H(�s��) */
#define	CSIA1B5		0xFFFFFE2A		/* CSIA1�o�b�t�@RAM5(�s��) */
#define	CSIA1B5L	0xFFFFFE2A		/* CSIA1�o�b�t�@RAM5L(�s��) */
#define	CSIA1B5H	0xFFFFFE2B		/* CSIA1�o�b�t�@RAM5H(�s��) */
#define	CSIA1B6		0xFFFFFE2C		/* CSIA1�o�b�t�@RAM6(�s��) */
#define	CSIA1B6L	0xFFFFFE2C		/* CSIA1�o�b�t�@RAM6L(�s��) */
#define	CSIA1B6H	0xFFFFFE2D		/* CSIA1�o�b�t�@RAM6H(�s��) */
#define	CSIA1B7		0xFFFFFE2E		/* CSIA1�o�b�t�@RAM7(�s��) */
#define	CSIA1B7L	0xFFFFFE2E		/* CSIA1�o�b�t�@RAM7L(�s��) */
#define	CSIA1B7H	0xFFFFFE2F		/* CSIA1�o�b�t�@RAM7H(�s��) */
#define	CSIA1B8		0xFFFFFE30		/* CSIA1�o�b�t�@RAM8(�s��) */
#define	CSIA1B8L	0xFFFFFE30		/* CSIA1�o�b�t�@RAM8L(�s��) */
#define	CSIA1B8H	0xFFFFFE31		/* CSIA1�o�b�t�@RAM8H(�s��) */
#define	CSIA1B9		0xFFFFFE32		/* CSIA1�o�b�t�@RAM9(�s��) */
#define	CSIA1B9L	0xFFFFFE32		/* CSIA1�o�b�t�@RAM9L(�s��) */
#define	CSIA1B9H	0xFFFFFE33		/* CSIA1�o�b�t�@RAM9H(�s��) */
#define	CSIA1BA		0xFFFFFE34		/* CSIA1�o�b�t�@RAMA(�s��) */
#define	CSIA1BAL	0xFFFFFE34		/* CSIA1�o�b�t�@RAMAL(�s��) */
#define	CSIA1BAH	0xFFFFFE35		/* CSIA1�o�b�t�@RAMAH(�s��) */
#define	CSIA1BB		0xFFFFFE36		/* CSIA1�o�b�t�@RAMB(�s��) */
#define	CSIA1BBL	0xFFFFFE36		/* CSIA1�o�b�t�@RAMBL(�s��) */
#define	CSIA1BBH	0xFFFFFE37		/* CSIA1�o�b�t�@RAMBH(�s��) */
#define	CSIA1BC		0xFFFFFE38		/* CSIA1�o�b�t�@RAMC(�s��) */
#define	CSIA1BCL	0xFFFFFE38		/* CSIA1�o�b�t�@RAMCL(�s��) */
#define	CSIA1BCH	0xFFFFFE39		/* CSIA1�o�b�t�@RAMCH(�s��) */
#define	CSIA1BD		0xFFFFFE3A		/* CSIA1�o�b�t�@RAMD(�s��) */
#define	CSIA1BDL	0xFFFFFE3A		/* CSIA1�o�b�t�@RAMDL(�s��) */
#define	CSIA1BDH	0xFFFFFE3B		/* CSIA1�o�b�t�@RAMDH(�s��) */
#define	CSIA1BE		0xFFFFFE3C		/* CSIA1�o�b�t�@RAME(�s��) */
#define	CSIA1BEL	0xFFFFFE3C		/* CSIA1�o�b�t�@RAMEL(�s��) */
#define	CSIA1BEH	0xFFFFFE3D		/* CSIA1�o�b�t�@RAMEH(�s��) */
#define	CSIA1BF		0xFFFFFE3E		/* CSIA1�o�b�t�@RAMF(�s��) */
#define	CSIA1BFL	0xFFFFFE3E		/* CSIA1�o�b�t�@RAMFL(�s��) */
#define	CSIA1BFH	0xFFFFFE3F		/* CSIA1�o�b�t�@RAMFH(�s��) */
#define	EXIMC		0xFFFFFFBE		/* �O���o�X�E�C���^�t�F�[�X�E���[�h�E�R���g���[���E���W�X�^(0x00) */

#endif	/* _V850ES_KJ1_H_ */
