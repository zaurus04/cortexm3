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
 *  @(#) $Id: vea_oea.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*  
 *   PowerPC�A�[�L�e�N�`��VEA,OEA�ˑ��̒�`
 *   �@�I���W�i����PowerPC�A�[�L�e�N�`���̏ꍇ
 *   �@�@���g���[��MPC�V���[�Y�AIPM PowerPC6xx/7xx�V���[�Y��
 *   �@�@������ɊY������B
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

#ifndef _VEA_OEA_H_
#define _VEA_OEA_H_

/*  
 *  ���W�X�^�ԍ��̒�`
 */   

/*  
 *  Configuration Register
 */   
#define PVR	287	/*  �v���Z�b�T�E�o�[�W�����E���W�X�^  */

/*  
 *  Memory Management Registers
 */   
/*  Instruction BAT Registers  */
#define IBAT0U	528
#define IBAT0L	529
#define IBAT1U	530
#define IBAT1L	531
#define IBAT2U	532
#define IBAT2L	533
#define IBAT3U	534
#define IBAT3L	535

/*  Instruction BAT Registers  */
#define DBAT0U	536
#define DBAT0L	537
#define DBAT1U	538
#define DBAT1L	539
#define DBAT2U	540
#define DBAT2L	541
#define DBAT3U	542
#define DBAT3L	543

#define SDR1	 25
#define ASR	280

/*  
 *  Exception Handling Registers
 */   
#define DAR	 19	/*  Data Address Register  */

#define SPRG0   272     /*  ���ꃌ�W�X�^�FOS�p  */
#define SPRG1   273     /*  ���ꃌ�W�X�^�FOS�p  */
#define SPRG2   274     /*  ���ꃌ�W�X�^�FOS�p  */
#define SPRG3   275     /*  ���ꃌ�W�X�^�FOS�p  */

#define DSISR    18     /*  DSI�X�e�[�^�X�E���W�X�^(*)  */
                        /*  �@DSI�F�f�[�^�E�X�g�A������  */
#define SRR0     26     /*  �Ҕ��^���A���W�X�^0  */
#define SRR1     27     /*  �Ҕ��^���A���W�X�^1  */

#define FPECR	1022	/*  Floating-Point Exception Cause Register  */


/*  
 *  Miscellaneous Registers
 */   
/*  Time Base Facility(OEA:for Writing)  */
#define TBLw	284
#define TBUw	285

/*  Time Base Facility(VEA:for Reading)  */
#define TBL	268
#define TBU	269

#define DEC      22     /*  �f�B�N�������g�E���W�X�^(*)  */

#define PIR	1023	/*  Processor Identification Register  */

#define DABR	1013	/*  DATA Address Breakpint Register(option)  */
#define EAR	 282	/*  Exception Access Register(option)  */



/*  
 *   �r�b�g�ԍ��̒�`
 *   �@���ӁFPowerPC�̃r�b�g�ԍ��͒ʏ�Ƌt�ɂȂ��Ă���
 *   �@�@�@�@�܂��A32�r�b�g���W�X�^��16�r�b�g���W�X�^�ł�
 *   �@�@�@�@�ŉ��ʃr�b�g�̃r�b�g�ԍ����قȂ�_�ɂ�����
 */   

/*  �}�V���X�e�[�^�X���W�X�^�̊e�r�b�g�̒�`  */
/*  �@���ӁF32�r�b�g�E�C���v�������g��p  */
#define MSR_POW BIT13_32    /*  �p���[�}�l�[�W�����g�E�C�l�[�u��  */
#define MSR_ILE BIT15_32    /*  ��O�������̃G���f�B�A�����[�h  */
                            /*  �@��O��t����MSR.LE��MSR.ILE  */
#define MSR_EE  BIT16_32    /*  �O�������݃C�l�[�u��  */
#define MSR_PR  BIT17_32    /*  �������x��  */
                            /*  �@0�F�X�[�p�o�C�U�E���x��  */
                            /*  �@1�F���[�U�E���x��  */
#define MSR_FP  BIT18_32    /*  ���������_�C�l�[�u��  */
#define MSR_ME  BIT19_32    /*  �}�V���`�F�b�N�E�C�l�[�u��  */
#define MSR_FE0 BIT20_32    /*  ���������_��O���[�h0  */
#define MSR_FE1 BIT23_32    /*  ���������_��O���[�h1  */
                            /*  �@���ӁF�ԍ����s�A��  */
#define MSR_SE  BIT21_32    /*  �V���O���X�e�b�v�g���[�X�E�C�l�[�u��  */
#define MSR_BE  BIT22_32    /*  ����g���[�X�E�C�l�[�u��  */
#define MSR_IP  BIT25_32    /*  ��O�v���t�B�b�N�X  */
                            /*  �@0�F0x000n,nnnn  */
                            /*  �@1�F0xfffn,nnnn  */
#define MSR_IR  BIT26_32    /*  ���߃A�h���X�ϊ��C�l�[�u��  */
#define MSR_DR  BIT27_32    /*  �f�[�^�A�h���X�ϊ��C�l�[�u��  */
#define MSR_RI  BIT30_32    /*  �񕜉\�ȗ�O  */
                            /*  �@0:�񕜕s�\  */
                            /*  �@1:�񕜉\  */
#define MSR_LE  BIT31_32    /*  ���g���G���f�B�A���E���[�h  */
                            /*  �@0�F�r�b�O�G���f�B�A��  */
                            /*  �@1�F���g���G���f�B�A��  */
/*  0�ŗ\�񂳂�Ă���r�b�g�̂��߂̃}�X�N  */
#define MSR_MASK    ~(BIT0_32 | BIT1_32 | BIT2_32 | BIT3_32 | BIT4_32 \
                    | BIT5_32 | BIT6_32 | BIT7_32 | BIT8_32 | BIT9_32 \
                    | BIT10_32 | BIT11_32 | BIT12_32 | BIT24_32 \
                    | BIT28_32 | BIT29_32)


/*  
 *   CPU��O�v���̒�`
 *   �@�ԍ����s�A���Ȃ̂�CPU��O�[���x�N�^�e�[�u���Ɉꕔ���ʂ����邪�A
 *   �@PowerPC�A�[�L�e�N�`���̒�`�ɍ��킹�����D�悵���B
 */   
#define EXC_NO_SYSTEM_RESET             0x1   /*  �V�X�e�����Z�b�g��O  */
#define EXC_NO_MACHINE_CHECK            0x2   /*  �}�V���E�`�F�b�N��O  */
#define EXC_NO_DSI                      0x3   /*  DSI��O  */
                                        /*  �i�f�[�^�E�������E�A�N�Z�X�j  */
#define EXC_NO_ISI                      0x4   /*  ISI��O�i���߃t�F�b�`�j  */
#define EXC_NO_EXTERNAL_INTERRUPT       0x5   /*  �O��������  */
#define EXC_NO_ALIGNMENT                0x6   /*  �A���C�����g��O  */
#define EXC_NO_PROGRAM                  0x7   /*  �v���O������O  */
#define EXC_NO_FLOATING_POINT_UNAVAILABLE 0x8   /*  ���������_�g�p�s��  */
#define EXC_NO_DECREMENTER              0x9   /*  �f�N�������^��O  */
                            /*  �C���v�������e�[�V�����ŗL�̗�O0x00a00  */
#define EXC_NO_IMPLEMENT_EXCEPTION_00A00 0xa 
#define EXC_NO_SYSTEM_CALL              0xc /*  �V�X�e���R�[��  */
#define EXC_NO_TRACE                    0xd /*  �g���[�X�i�I�v�V�����j  */
#define EXC_NO_FLOATING_POINT_ASSIST    0xe /*  ���������_�⏕  */
                            /*  �C���v�������e�[�V�����ŗL�̗�O0x01000  */
#define EXC_NO_IMPLEMENT_EXCEPTION_01000 0x10    


/*  
 *   ��O�̎�ʐ�
 *   �@�O�������݂��P�Ɛ�����
 *   �@�@0�Ԃ͖��g�p
 *   �@�@�@�E��O�x�N�^�̃I�t�Z�b�g�ƑΉ�
 *   �@�@�@�E�O�����荞�݂��P�Ɛ�����
 *   �@�@�@�E�z��錾�̂��߁A+1���Ă���
 */   

#ifdef IMPLEMENT_EXCEPTION_01000    /*  ��O�x�N�^0x1000���g�p����ꍇ  */
#define TMAX_EXCNO       ( 0x10 + 1 )

#else /* IMPLEMENT_EXCEPTION_01000 */
#define TMAX_EXCNO       ( 0xe + 1 )

#endif /* IMPLEMENT_EXCEPTION_01000 */




#endif /* _VEA_OEA_H_ */
/*  end of file  */
