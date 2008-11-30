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
; *  @(#) $Id: vectors.S,v 1.1 2008/06/17 00:04:35 suikan Exp $
; *

       .include "c5402dsk.h"
       .sect   "vectors"
       .align  0x80
       .mmregs

RESET: B _start
       NOP
       NOP

NMI:   RETE
       NOP
       NOP
       NOP

; �\�t�g�E�F�A���荞��(TRAP,INTM)
sint17 .space 4*16
sint18 .space 4*16
sint19 .space 4*16
sint20 .space 4*16
sint21 .space 4*16
sint22 .space 4*16
sint23 .space 4*16
sint24 .space 4*16
sint25 .space 4*16
sint26 .space 4*16
sint27 .space 4*16
sint28 .space 4*16
sint29 .space 4*16
sint30 .space 4*16

int0:  BD   _interrupt
       STM  #16,_INT_VECNO

int1:  BD   _interrupt
       STM  #17,_INT_VECNO

int2:  BD   _interrupt
       STM  #18,_INT_VECNO

tint0: BD  _interrupt
       STM  #19,_INT_VECNO

rint0: BD  _interrupt
       STM  #20,_INT_VECNO

xint0: BD  _interrupt
       STM  #21,_INT_VECNO

dma0:  BD  _interrupt
       STM  #22,_INT_VECNO

tint1: BD  _interrupt
       STM  #23,_INT_VECNO

int3:  BD  _interrupt
       STM  #24,_INT_VECNO

hpi:   BD  _interrupt
       STM  #25,_INT_VECNO

rint1: BD  _interrupt
       STM  #26,_INT_VECNO

xint1: BD  _interrupt
       STM  #27,_INT_VECNO

dma4:  BD  _interrupt
       STM  #28,_INT_VECNO

dma5:  BD  _interrupt
       STM  #29,_INT_VECNO