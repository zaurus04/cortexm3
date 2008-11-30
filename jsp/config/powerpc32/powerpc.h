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
 *  @(#) $Id: powerpc.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*  
 *   PowerPC�A�[�L�e�N�`���ˑ��̒�`
 *   �@���ӁF�ꕔ�A32�r�b�g�E�C���v�������g��p�ɂȂ��Ă���
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

#ifndef _POWERPC_H_
#define _POWERPC_H_

#include <util.h>


/*  
 *   VEA��OEA�̒�`
 */   

#ifndef IBM_PPC_EMB_ENV
/*  
 *   �I���W�i����PowerPC�A�[�L�e�N�`���̏ꍇ
 *   �@�@���g���[��MPC�V���[�Y�AIPM PowerPC6xx/7xx�V���[�Y��
 *   �@�@������ɊY������B
 */   
#include <vea_oea.h>

#else	/*  IBM_PPC_EMB_ENV  */
/*  
 *   The IBM PowerPC Embedded Environment�̏ꍇ
 *   �@IBM�nPowerPC40x�V���[�Y�Ή�
 */   
#include <vea_oea_emb.h>

#endif	/*  IBM_PPC_EMB_ENV  */


/*  
 *   UISA�̒�`
 */   

/*  
 *  ���W�X�^�ԍ��̒�`
 *  �@�@C����̕ϐ����ƂԂ��肻���Ȃ̂ŁA�A�Z���u�����Ɍ��肷��
 */   
#ifdef _MACRO_ONLY

/* CPU�R�A�̓������W�X�^�̖��� */

/*  �ėp���W�X�^  */
#define r0       0      /*  zero�܂��͔ėp���W�X�^  */
#define r1       1
#define sp       r1     /*  �X�^�b�N�|�C���^  */

#define r2       2      /*  TOC�FTable of Contents  */
#define r3       3      /*  r3-4�F�����A�߂�l  */
#define r4       4
#define r5       5      /*  r5-10�F����  */
#define r6       6
#define r7       7
#define r8       8
#define r9       9
#define r10     10
#define r11     11
#define r12     12
#define r13     13      /*  r13�Fsmall data  */
#define r14     14      /*  r14-30�F���[�J���ϐ�  */
#define r15     15
#define r16     16
#define r17     17
#define r18     18
#define r19     19
#define r20     20
#define r21     21
#define r22     22
#define r23     23
#define r24     24
#define r25     25
#define r26     26
#define r27     27
#define r28     28
#define r29     29
#define r30     30
#define r31     31
#define fp      r31     /*  �t���[���|�C���^  */

/*  ���������_���W�X�^  */
#define f0       0
#define f1       1      /*  f1�F�����A�߂�l  */
#define f2       2      /*  f2-13�F����  */
#define f3       3
#define f4       4
#define f5       5
#define f6       6
#define f7       7
#define f8       8
#define f9       9
#define f10     10
#define f11     11
#define f12     12
#define f13     13
#define f14     14      /*  f14-31�F���[�J���ϐ�  */
#define f15     15
#define f16     16
#define f17     17
#define f18     18
#define f19     19
#define f20     20
#define f21     21
#define f22     22
#define f23     23
#define f24     24
#define f25     25
#define f26     26
#define f27     27
#define f28     28
#define f29     29
#define f30     30
#define f31     31

/*  ���ꃌ�W�X�^  */
#define XER      1      /* Fixed Point Exception Register  */
			/*  �����I�y���[�V�����̏������ʃ��W�X�^ */
			/*  �i�L�����[��I�[�o�t���[�Ȃǁj  */
#define LR       8      /*  �����N�E���W�X�^  */
#define CTR      9      /*  �J�E���g�E���W�X�^  */

#endif  /* _MACRO_ONLY */

#define crf0        0   /*  �R���f�B�V�������W�X�^CR�̃t�B�[���h�w��  */

#endif /* _POWERPC_H_ */
/*  end of file  */
