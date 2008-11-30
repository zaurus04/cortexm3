; *
; *  TOPPERS/JSP Kernel
; *      Toyohashi Open Platform for Embedded Real-Time Systems/
; *      Just Standard Profile Kernel
; * 
; *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
; *                              Toyohashi Univ. of Technology, JAPAN
; * 
; *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
; *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
; *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
; *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
; *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
; *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
; *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
; *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
; *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
; *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
; *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
; *      �̖��ۏ؋K����f�ڂ��邱�ƁD
; *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
; *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
; *      �ƁD
; *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
; *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
; *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
; *        �񍐂��邱�ƁD
; *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
; *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
; * 
; *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
; *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
; *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
; *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
; * 
; *  @(#) $Id: start.S,v 1.1 2008/06/17 00:04:35 suikan Exp $
; *

        .c_mode
        .mmregs
        .include  "c5402dsk.h"
        .global   _main
        .align    1
;�X�^�b�N�̈�ɂ̓f�[�^�̈�̍Ō�̗]�����̈�����蓖�Ă�B
;__stack:.usect ".stack",0
        .text
_start:
        ;******************************************
        ;      �X�e�[�^�X���W�X�^�̏�����
        ;******************************************
        SSBX   INTM                    ;���ׂẴ}�X�J�u�����荞�݂��֎~
        STM    #0x0FFFF,IFR            ;IFR�̃N���A

        SSBX   SXM                     ;�����r�b�g�Z�b�g
        SSBX   CPL                     ;�R���p�C���݊����[�h
        RSBX   OVM                     ;��O�a���[�h
        LD     #0,ARP                  ;�⏕���W�X�^�|�C���^
        RSBX   CMPT
        RSBX   C16
        RSBX   FRCT
        
        ;******************************************
        ;     �X�^�b�N�|�C���^�̏�����
        ;******************************************
        STM    #STACKTOP,SP
        ANDM   #0x0fffe,*(SP)          ;SP�������A�h���X�ɃA���C��
        
        ;******************************************
        ;     _hardware_init_hook �̌Ăяo��
        ;******************************************
start_0:
        LD     #_hardware_init_hook,A
        CC     _hardware_init_hook,ANEQ
        
        ;******************************************
        ;     bss�Z�N�V�����̏�����
        ;******************************************
start_1:
        STM    #___bss__,AR2
        RPTZ  A,#___end__-___bss__-1
        STL    A,*AR2+

        LD     #cinit,A                ;cinit=-1�Ȃ�cinit�͖���
        ADD    #1,A,B
        BC     start_4,BEQ

        
        RSBX   SXM                     ;�����r�b�g�N���A
        NOP
        LD     #cinit,A
        B      start_2
start_3:
        READA  *(AR2)                  ;AR2 = �ϐ��̃A�h���X
        ADD    #1,A                    ;�������f�[�^�ւ̃|�C���^�����߂�
        RPT    *(AR1)                  ;length+1 �J��Ԃ� 
        READA  *AR2+                   ;�ϐ���������
        ADD    *(AR1),A                ;
        ADD    #1,A                    ;�f�[�^���������|�C���^��i�߂�
start_2:
        READA  *(AR1)                  ;AR1 = length
        ADD    #1,A                    ;A += 1
        BANZ   start_3,*AR1-           ;if (length != 0) length--�A�W�����v
        
        ;*****************************************
        ;    software_init_hook���Ăяo��
        ;*****************************************
start_4:
        LD     #_software_init_hook,A
        CC     _software_init_hook,ANEQ

;        ST     #1,*(_nest)
        CALL   _kernel_start
        
        
        
          