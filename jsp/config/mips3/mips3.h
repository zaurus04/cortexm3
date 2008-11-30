/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2000-2003 by Industrial Technology Institute,
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
 */

#ifndef _MIPS3_H_
#define _MIPS3_H_

#include <util.h>

/*
 *  MIPS3 �p��`
 */

/* CPU�R�A�̓������W�X�^�̖��� */
#define zero    $0      /* �펞�[�� */
#define at      $1      /* �A�Z���u���̃e���|���� */
#define v0      $2      /* �֐��̖߂�l */
#define v1      $3
#define a0      $4      /* �֐��̈��� */
#define a1      $5
#define a2      $6
#define a3      $7
#define t0      $8      /* �e���|�������W�X�^ tx (x=0-9)�F�֐��Ăяo���Ŕj�� */
#define t1      $9
#define t2      $10
#define t3      $11
#define t4      $12
#define t5      $13
#define t6      $14
#define t7      $15
#define s0      $16     /* sx (x=0-7) : �֐��Ăяo���ŕs�ςȃ��W�X�^ */
#define s1      $17
#define s2      $18
#define s3      $19
#define s4      $20
#define s5      $21
#define s6      $22
#define s7      $23
#define t8      $24     /* �e���|�������W�X�^ tx (x=0-9)�F�֐��Ăяo���Ŕj�� */
#define t9      $25
#define k0      $26     /* OS�p�ɗ\��ς� */
#define kt0     $26
#define k1      $27
#define kt1     $27
#define gp      $28     /* ���ϐ��̈�̃x�[�X�A�h���X */
#define sp      $29     /* �X�^�b�N�|�C���^ */
#define fp      $30     /* �t���[���|�C���^ */
/* �������� */
#define s8      $30     /* s8 : �֐��Ăяo���ŕs�ςȃ��W�X�^ */
#define ra      $31     /* �֐�����̖߂�A�h���X */

/* CP0�̓������W�X�^�̖��� */
#define Index           $0
#define Random          $1
#define EntryLo0        $2
#define EntryLo1        $3
#define Context         $4
#define PageMask        $5
#define Wired           $6
#define Error           $7
#define BadVAddr        $8
#define Count           $9
#define EntryHi         $10
#define Compare         $11
#define Status          $12
#define Cause           $13
#define EPC             $14
#define PRId            $15
#define Config          $16
#define LLAddr          $17
#define WatchLo         $18
#define WatchHi         $19
#define XContext        $20
/* $21-$24 - �\�� */
#define Performance     $25
#define ParityErr       $26
#define CacheErr        $27
#define TagLo           $28
#define TagHi           $29
#define ErrorEPC        $30
/* $31 - �\�� */

/*  �C�����C���A�Z���u�����Ŏg���ꍇ�̒�`  */
#define str_k0		"$26"
#define str_Status	"$12"

/*  �X�e�[�^�X���W�X�^�֌W  */
#define SR_IE		BIT0			/*  IE�r�b�g  */
#define SR_EXL		BIT1			/*  EXL�r�b�g  */
#define SR_ERL		BIT2			/*  ERL�r�b�g  */

#define SR_EXL_IE	(SR_EXL | SR_IE)	/*  EXL,IE�r�b�g  */
#define SR_ERL_EXL	(SR_ERL | SR_EXL)	/*  ERL,EXL�r�b�g  */
#define SR_ERL_EXL_IE	(SR_ERL_EXL | SR_IE)	/*  ERL,EXL,IE�r�b�g  */
#define SR_IM		0xff00			/*  IM�r�b�g�����o���}�X�N  */

#define SR_UX		BIT5			/*  UX�r�b�g  */
#define SR_SX		BIT6			/*  SX�r�b�g  */
#define SR_KX		BIT7			/*  SX�r�b�g  */
#define SR_DE		BIT16			/*  DE�r�b�g  */
#define SR_SR		BIT20			/*  SR�r�b�g  */
#define SR_BEV		BIT22			/*  BEV�r�b�g  */
#define SR_RE		BIT25			/*  RE�r�b�g  */
#define SR_CU0		BIT28			/*  CU0�r�b�g  */
#define SR_CU1		BIT29			/*  CU1�r�b�g  */
#define SR_CU2		BIT30			/*  CU2�r�b�g  */
#define SR_XX		BIT31			/*  XX�r�b�g  */

/*  �������W�X�^�֌W  */
#define Cause_IP0       BIT8    /*  IP0�r�b�g  */
#define Cause_IP1       BIT9    /*  IP1�r�b�g  */
#define Cause_IP2       BIT10   /*  IP2�r�b�g  */
#define Cause_IP3       BIT11   /*  IP3�r�b�g  */
#define Cause_IP4       BIT12   /*  IP4�r�b�g  */
#define Cause_IP5       BIT13   /*  IP5�r�b�g  */
#define Cause_IP6       BIT14   /*  IP6�r�b�g  */
#define Cause_IP7       BIT15   /*  IP7�r�b�g  */

/*  �O�����荞�݂ɑ΂���IP�r�b�g�̕ʖ�  */
#define Cause_Int0	Cause_IP2  /*  Int0�v���r�b�g  */
#define Cause_Int1	Cause_IP3  /*  Int1�v���r�b�g  */
#define Cause_Int2	Cause_IP4  /*  Int2�v���r�b�g  */
#define Cause_Int3	Cause_IP5  /*  Int3�v���r�b�g  */
#define Cause_Int4	Cause_IP6  /*  Int4�v���r�b�g  */

/*  �������W�X�^���猴���R�[�h�����o���}�X�N  */
#define ExcCode_mask    0x7c

/* ��O�R�[�h */
#define Int     0       /* ���荞�ݗ�O */
#define Mod     1       /* TLB�ύX��O */
#define TLBL    2       /* TLB�s��v��O (���[�h�܂��͖��߃t�F�b�`) */
#define TLBS    3       /* TLB�s��v��O (�X�g�A) */
#define AdEL    4       /* �A�h���X�G���[��O (���[�h�܂��͖��߃t�F�b�`) */
#define AdES    5       /* �A�h���X�G���[��O (�X�g�A) */
#define IBE     6       /* �o�X�G���[��O (���߃t�F�b�`) */
#define DBE     7       /* �o�X�G���[��O (�f�[�^�̃��[�h�܂��̓X�g�A) */
#define Sys     8       /* �V�X�e���R�[����O */
#define Bp      9       /* �u���C�N�|�C���g��O */
#define RI      10      /* �\�񖽗ߗ�O */
#define CpU     11      /* �R�v���Z�b�T�g�p�s��O */
#define Ov      12      /* ���Z�I�[�o�[�t���[��O */
#define Tr      13      /* �g���b�v��O */
/* 14 - �\�� */
#define FPE     15      /* ���������_��O */
/* 16-22 - �\�� */
#define WATCH   23      /* �E�H�b�`��O */
/* 24-31 - �\�� */

/*  �����ݗv���ԍ�  */
#define INTNO_IP0               0
#define INTNO_IP1               1
#define INTNO_IP2               2
#define INTNO_IP3               3
#define INTNO_IP4               4
#define INTNO_IP5               5
#define INTNO_IP6               6
#define INTNO_IP7               7

/*  �R�A�̊����݂̖{���i�\�t�g�E�F�A�����݂��܂ށj */
#define TMAX_CORE_INTNO		8

/*
 *  MIPS3�R�A�̃X�e�[�^�X���W�X�^�ɐݒ�\�ȍō������݋��r�b�g�p�^�[��
 */
#define MAX_IPM  0xff

/*
 *  MIPS3�R�A�ɐݒ肷�銄���݃}�X�N�̃`�F�b�N
 */
#define CHECK_CORE_IPM(ipm)  CHECK_PAR(0 <= (ipm) && (ipm) <= MAX_IPM)

/*
 *  CPU��O�̎�ސ�
 */
#define TMAX_CORE_EXCNO	32u

/*
 *  ���O�o�͎��̃X�^�b�N�\���̒�`
 *    cpu_config.h�ɂ�����cpu_experr�֐��Acpu_support.S���Q�Ƃ̂��ƁB
 */
#ifndef _MACRO_ONLY

typedef struct exc_stack {

	/*  ���W�X�^�Q�̒�`  */
	UW	sp;
	UW	at;
	UW	v0;
	UW	v1;
	UW	a0;
	UW	a1;
	UW	a2;
	UW	a3;
	UW	t0;
	UW	t1;
	UW	t2;
	UW	t3;
	UW	t4;
	UW	t5;
	UW	t6;
	UW	t7;
	UW	t8;
	UW	t9;
	UW	gp;
	UW	fp;
	UW	ra;

	UW	CP0_Status;
	UW	CP0_EPC;

	UW	hi;
	UW	lo;

} EXCSTACK;

#endif /* _MACRO_ONLY */

#endif /* _MIPS3_H_ */
