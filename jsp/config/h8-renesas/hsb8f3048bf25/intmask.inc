;
;  TOPPERS/JSP Kernel
;      Toyohashi Open Platform for Embedded Real-Time Systems/
;      Just Standard Profile Kernel
;
;  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
;                              Toyohashi Univ. of Technology, JAPAN
;  Copyright (C) 2001-2007 by Industrial Technology Institute,
;                              Miyagi Prefectural Government, JAPAN
;  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
;                   Tomakomai National College of Technology, JAPAN
;
;  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation
;  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
;  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
;  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
;  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
;  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
;      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
;      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
;  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
;      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
;      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
;      �̖��ۏ؋K����f�ڂ��邱�ƁD
;  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
;      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
;      �ƁD
;    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
;        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
;    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
;        �񍐂��邱�ƁD
;  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
;      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
;
;  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
;  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
;  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
;  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
;
;  @(#) $Id: intmask.inc,v 1.4 2007/03/23 07:58:33 honda Exp $
;

;
;  �����݃}�X�N�̒�`
;
;�@�@���̃t�@�C����vecter.src����C���N���[�h����A�����݂̓���������
;�@�@�����̗p������B
;�@�@�����݃n���h����ǉ�����ۂ́A���̃t�@�C����ҏW����B
;
;�@�@�����݃n���h���iC���ꃋ�[�`���j�Ăяo�����O�ɐݒ肷�銄���݋���
;�@�@�̊����݃}�X�N�̒l���`����B
;�@�@IPM_LEVEL1�AIPM_LEVEL2�̂����ꂩ�ɂ��邱�ƁB
;�@�@C���ꃋ�[�`����xxxx�ɑ΂��āA�����݃}�X�N����xxxx_intmask�Ƃ���B
;
;�@�@����
;�@�@�@�󂯕t���������݂Ɠ������x���̊����݂��}�X�N���邽�߁AIPM�ɂ�
;�@�@�@�P��̃��x����ݒ肷��B
;

; �^�C�}�n���h��
timer_handler_intmask:         .DEFINE         "IPM_LEVEL2"

; �V���A���n���h��
SCI_MASK:                      .DEFINE         "IPM_LEVEL1"
; �V���A�� 1ch��
sio_err_handler_intmask:       .DEFINE         "SCI_MASK"
sio_in_handler_intmask:        .DEFINE         "SCI_MASK"
sio_out_handler_intmask:       .DEFINE         "SCI_MASK"
; �V���A�� 2ch��
sio_err2_handler_intmask:      .DEFINE         "SCI_MASK"
sio_in2_handler_intmask:       .DEFINE         "SCI_MASK"
sio_out2_handler_intmask:      .DEFINE         "SCI_MASK"
