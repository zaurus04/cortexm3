;
;  TOPPERS/JSP Kernel
;      Toyohashi Open Platform for Embedded Real-Time Systems/
;      Just Standard Profile Kernel
;
;  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
;                              Toyohashi Univ. of Technology, JAPAN
;  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
;                   Tomakomai National College of Technology, JAPAN
;  Copyright (C) 2001-2007 by Industrial Technology Institute,
;                              Miyagi Prefectural Government, JAPAN
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
;  @(#) $Id: h8s2339f.inc,v 1.2 2007/03/23 07:59:26 honda Exp $
;

;  H8S/2339F�p��`�i�A�Z���u���p�j

 .AIFDEF _H8S2339F_INC_
 .AELSE

_H8S2339F_INC_: .DEFINE ""

        .INCLUDE "util.inc"

;
;  �������W�X�^�̒�`�i����16�r�b�g�̂݁j
;

;    �o�X�R���g���[��
ABWCR:                   .DEFINE         "H'fed0"
ASTCR:                   .DEFINE         "H'fed1"
WCRH:                    .DEFINE         "H'fed2"
WCRL:                    .DEFINE         "H'fed3"
BCRH:                    .DEFINE         "H'fed4"
BCRL:                    .DEFINE         "H'fed5"

PFCR1:                   .DEFINE         "H'ff45"
PFCR2:                   .DEFINE         "H'ffac"


;    I/O�|�[�g
P1DR:                    .DEFINE         "H'ff60"
P2DR:                    .DEFINE         "H'ff61"
P3DR:                    .DEFINE         "H'ff62"
P4DR:                    .DEFINE         "H'ff63"
P5DR:                    .DEFINE         "H'ff64"
P6DR:                    .DEFINE         "H'ff65"
P7DR:                    .DEFINE         "H'ff66"
P8DR:                    .DEFINE         "H'ff67"
P9DR:                    .DEFINE         "H'ff68"
PADR:                    .DEFINE         "H'ff69"
PBDR:                    .DEFINE         "H'ff6a"
PCDR:                    .DEFINE         "H'ff6b"
PDDR:                    .DEFINE         "H'ff6c"
PEDR:                    .DEFINE         "H'ff6d"
PFDR:                    .DEFINE         "H'ff6e"
PGDR:                    .DEFINE         "H'ff6f"

P1DDR:                   .DEFINE         "H'feb0"
P2DDR:                   .DEFINE         "H'feb1"
P3DDR:                   .DEFINE         "H'feb2"
P4DDR:                   .DEFINE         "H'feb3"
P5DDR:                   .DEFINE         "H'feb4"
P6DDR:                   .DEFINE         "H'feb5"
P7DDR:                   .DEFINE         "H'feb6"
P8DDR:                   .DEFINE         "H'feb7"
P9DDR:                   .DEFINE         "H'feb8"
PADDR:                   .DEFINE         "H'feb9"
PBDDR:                   .DEFINE         "H'feba"
PCDDR:                   .DEFINE         "H'febb"
PDDDR:                   .DEFINE         "H'febc"
PEDDR:                   .DEFINE         "H'febd"
PFDDR:                   .DEFINE         "H'febe"
PGDDR:                   .DEFINE         "H'febf"

 .AENDI ; _H8S2339F_INC_
