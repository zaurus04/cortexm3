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
 *  @(#) $Id: vea_oea_emb.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*  
 *   PowerPC�A�[�L�e�N�`��VEA,OEA�ˑ��̒�`
 *   �@The IBM PowerPC Embedded Environment�̏ꍇ
 *   �@�@IBM�nPowerPC40x�t�@�~��������ɊY������B
 *   �@
 *   �@PowerPC�A�[�L�e�N�`���̒�`�͈ȉ��̂R�̃��x�����琬��
 *   �@�EUSIA:User Instruction Set Architecture
 *   �@�EVEA: Virtual Environment Architecture
 *   �@�EOEA: Operating Environment Architecture
 *   �@
 *   �@USIA�ɂ��Ă͑S�@�틤�ʂł��邪�AVEA��OEA�ɂ��Ă�
 *   �@�I���W�i����PowerPC�A�[�L�e�N�`����The IBM PowerPC 
 *   �@Embedded Environment���ꂼ��ʂɒ�`����Ă��邽�߁A
 *   �@VEA��OEA�̒�`�̓t�@�C���𕪂��āA������C���N���[�h
 *   �@���Ă���B
 */   


#ifndef _VEA_OEA_EMB_H_
#define _VEA_OEA_EMB_H_

/*  
 *  ���W�X�^�ԍ��̒�`
 */   

/*
 *  Special Purpose Register�̃��W�X�^�ԍ�
 *  �@�@(*)��F����PowerPC�A�[�L�e�N�`���ł͒�`����Ă��Ȃ����W�X�^
 */

/*
 *  ��O�����Ɋւ��郌�W�X�^
 */
#define SRR0	  26	/* Save/Restore Register0  */
#define SRR1	  27	/* Save/Restore Register1  */
#define SRR2	 990	/* Save/Restore Register2(*)  */
#define SRR3	 991	/* Save/Restore Register3(*)  */
#define ESR	 980	/* Exception Syndrome Register(*)  */
#define DEAR	 981	/* Data Exception Address Register(*)  */
#define EVPR	 982	/* Exception Vector Prefix Register(*)  */

#define SPRG0	 272	/* SPR General 0  */
#define SPRG1	 273	/* SPR General 1  */
#define SPRG2	 274	/* SPR General 2  */
#define SPRG3	 275	/* SPR General 3  */

/*
 *  ���̑��̃��W�X�^
 */
#define DAC	1014	/* Data Address Compare(*) */
#define DBCR	1010	/* Debug Control Register(*) */
#define DBSR	1008	/* Debug Status Register(*) */
#define DCCR	1018	/* Data Cache Cacheability Register(*) */
#define DCWR	 954	/* Data Cache Write-thru Register(*) */

#define IAC	1012	/* Instruction Address Compare(*) */
#define ICCR	1019	/* Instruction Cache Cacheability Register(*) */

#define PID	 945	/* Process ID Register  */
#define PIT	 987	/* Programmable Interval Timer(*) */
#define PVR	 287	/* Processor Version Register  */

#define SGR	 953	/* Storage Guarded Register(*) */
#define SLER	 955	/* Storage Little-Endian Register(*) */
#define SMR	 952	/* Storage Memory-Coherent Register(*) */

/*  VEA  */
#define TBL	 268	/* Time Base Lower(for read)  */
#define TBU	 269	/* Time Base Upper(for read)  */
/*  OEA  */
#define TBLw	 284	/* Time Base Lower(for write)  */
#define TBUw	 285	/* Time Base Upper(for write)  */

#define TCR	 986	/* Timer Control Registe(*) */
#define TSR	 984	/* Timer Status Register(*) */
#define ZPR	 944	/* Zone Protection Register(*) */

/*
 *  MSR�̃r�b�g�z��
 */
/*  0-10:Reserved  */
#define MSR_APE	BIT11_32	/* Auxiliary Processor Exception Enable */
#define MSR_APA	BIT12_32	/* Auxiliary Processor Available */
#define MSR_WE	BIT13_32	/* Wait State Enable */
#define MSR_CE	BIT14_32	/* Critical Enable */
#define MSR_ILE	BIT15_32	/* Interrupt Little Endian */
#define MSR_EE	BIT16_32	/* External Enable */
#define MSR_PR	BIT17_32	/* Problem State */
#define MSR_FP	BIT18_32	/* Floating Point Available */
#define MSR_ME	BIT19_32	/* Machine Check Enable */
#define MSR_FE0	BIT20_32	/* Floating Point Exception Mode 0 */
/*  21:Reserved  */
#define MSR_DE	BIT22_32	/* Debug Interrupts Enable */
#define MSR_FE1	BIT23_32	/* Floating Point Exception Mode 1 */
/*  23-25:Reserved  */
#define MSR_IR	BIT26_32	/* Instruction Relocate */
#define MSR_DR	BIT27_32	/* Data Relocate */
/*  28-30:Reserved  */
#define MSR_LE	BIT31_32	/* Little Endian */


/*
 *  ESR(Exception Syndrome Register)�̃r�b�g�z��
 */
#define ESR_PIL	BIT4_32	 /* Program - Illegal Instruction exception */
#define ESR_PPR	BIT5_32	 /* Program - Privileged Instruction exception */
#define ESR_PTR	BIT6_32	 /* Program - Trap exception */
#define ESR_PFE	BIT7_32	 /* Program - Floating Point Enabled exception */
#define ESR_DST	BIT8_32	 /* Data Storage / Data TLB Miss - Store Operations */
#define ESR_DIZ	BIT9_32	 /* Data / Instruction Storage - Zone exception */
	/* Program - Auxiliary Processor Unavailable exception */
#define ESR_PAU	BIT12_32
	/* Program - Floating Point Enabled but Unimplemented exception */
#define ESR_PFEU BIT13_32
	/* Program - Auxiliary Processor Enabled exception */
#define ESR_PAE	BIT14_32


/*  
 *   CPU��O�v���̒�`
 *   �@�ԍ����s�A���Ȃ̂�CPU��O�[���x�N�^�e�[�u���Ɉꕔ���ʂ����邪�A
 *   �@PowerPC�A�[�L�e�N�`���̒�`�ɍ��킹�����D�悵���B
 */   
#define EXC_NO_CRITICAL_INPUT           	0x1
#define EXC_NO_MACHINE_CHECK            	0x2
#define EXC_NO_DATA_STORAGE             	0x3
#define EXC_NO_INSTRUCTION_STORAGE      	0x4
#define EXC_NO_EXTERNAL_INTERRUPT       	0x5   /*  �O��������  */
#define EXC_NO_ALIGNMENT                	0x6
			/*  �v���O������O�i�v���V��j*/
#define EXC_NO_PROGRAM                  	0x7
#define EXC_NO_FLOATING_POINT_UNAVAILABLE 	0x8
/*  �iAPU������PowerPC405�A440�̂݁j  */

/*  0x900�FReserved  */
/*  0xa00�FReserved  */
/*  0xb00�FReserved  */
#define EXC_NO_SYSTEM_CALL              	0xc	/*  �V�X�e���R�[��  */
/*  0xd00�FReserved  */
/*  0xe00�FReserved  */
/*  0xe10-0xff0�FReserved  */
/* 0x1000�FProgrammable Interval Timer  */
/* 0x1010�FFixed Interval Timer  */
/* 0x1020�FWatchdog Timer  */
/* 0x1030-0x10f0�FReserved  */
/* 0x1100�FData TLB miss  */
/* 0x1110-0x11f0�FReserved  */
/* 0x1200�FInstruction TLB miss  */
/* 0x1210-0x1ff0�FReserved  */
/* 0x2000�FDebug�i�v���V��j   */
/* 0x2010-0x2ff0�FImplementation Specific  */

/*  
 *   ��O�̎�ʐ�
 *   �@�O�������݂��P�Ɛ�����
 *   �@�@0�Ԃ͖��g�p
 *   �@�@�@�E��O�x�N�^�̃I�t�Z�b�g�ƑΉ�
 *   �@�@�@�E�O�����荞�݂��P�Ɛ�����
 *   �@�@�@�E�z��錾�̂��߁A+1���Ă���
 */   

#define TMAX_EXCNO       ( 0x20 + 1 + NUM_IMPLEMENT_EXCEPTION )


/*
 *  DCR�ւ̃A�N�Z�X
 *     DCR:Device Control Register
 *     �ȉ��̃��[�`���̓f�o�C�X�h���C�o�����ɍ쐬���Ă���B
 *     DCR�̋�̓I�Ȗ��̂�@�\�̓f�o�C�X�ˑ��ł���B
 *     
 *     ���l
 *     �@mfdcr,mtdcr���߂�DCR�̔ԍ���ėp���W�X�^�ł͂Ȃ��A
 *     �@���l�Ŏw�肷�邽�߁A�C�����C���֐��ɂł��Ȃ��B
 */

/*
 *  DCR�̌��ݒl�̓Ǐo��
 *     reg:���W�X�^�ԍ��i�����萔�j
 *     val:�ǂݏo�����l���i�[����ϐ��iUW�^�j
 */
#define _sil_rew_dcr(reg, val)	Asm("mfdcr %0," #reg : "=r"(val))
#define sil_rew_dcr(reg, val)	_sil_rew_dcr(reg, val)

/*
 *  DCR�̌��ݒl�̕ύX
 *     reg:���W�X�^�ԍ��i�����萔�j
 *     val:�ݒ肷��l���i�[���ꂽ�ϐ��iUW�^�j
 */
#define _sil_wrw_dcr(reg, val)	Asm("mtdcr "#reg",%0" : : "r"(val) )
#define sil_wrw_dcr(reg, val)	_sil_wrw_dcr(reg, val)


#endif /* _VEA_OEA_EMB_H_ */
/*  end of file  */
