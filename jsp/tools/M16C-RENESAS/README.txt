
        �� TOPPERS/JSP�J�[�l�� ���[�U�Y�}�j���A�� ��
                    �im16c:TM�J�����j

        �iRelease 1.4 �Ή��C�ŏI�X�V: 15-May-2006�j

------------------------------------------------------------------------
 TOPPERS/JSP Kernel
     Toyohashi Open Platform for Embedded Real-Time Systems/
     Just Standard Profile Kernel

 Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
                             Toyohashi Univ. of Technology, JAPAN
 Copyright (C) 2003-2004 by Platform Development Center
                                         RIOCH COMPANY,LTD. JAPAN
 Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
               Graduate School of Information Science, Nagoya Univ., JAPAN

 ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
     ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
     �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
     �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
     �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
     �̖��ۏ؋K����f�ڂ��邱�ƁD
 (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
     �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
     �ƁD
   (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
       �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
   (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
       �񍐂��邱�ƁD
 (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
     �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD

 �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
------------------------------------------------------------------------

���̃h�L�������g�ł́AM16C�p�̃��l�T�X�e�N�m���W�Ђ̊J���c�[�����g�p��
�āCTOPPERS/JSP�J�[�l�����\�z���邽�߂ɕK�v�ȃt�@�C���ɂ��ĉ������D

1. �f�B���N�g���̍\��

jsp
  +--config
  |     +---m16c-renesas
  |            +---oaks16
  |            +---oaks16_mini
  |            +---m3029
  +--tools
  |     +-----M16C-RENESAS
  +--utils
        +-----m16c-renesas


2.�f�B���N�g���ƃt�@�C���̐���

M16C�ˑ����̃t�@�C���́Cconfig/m16c-renesas�f�B���N�g���ɒu���D�\�z��
�ۂ��āC�����݂�G�N�Z�v�V�����̃x�N�g����������������c�[��(m16cvec. 
exe)�ƁCTCB�̃I�t�Z�b�g�l���A�Z���u���ŏ����ꂽ�\�[�X�ɐݒ肷��c�[��
(m16co ffset.exe)�̍\�z���ƁCmake��p�����J���t���[�̏ꍇ�ɕK�v�Ƃ�
��C�\�[�X�̈ˑ��֌W�𐶐�����perl�X�N���v�g��tools/m16c-renesas�f���N
�g���B�ɒu���D�����J����TM��p����TOPPERS/JSP���\�z���邽�߂̃t�@�C
����tools/M16C-RENESAS�f���N�g���B�ɒu���D


2.1 config/m16c-renesas

a. Makefile.config
    make�R�}���h��p����m16c�pTOPPERS/JSP���\�z����ꍇ��make�t�@�C��
b. oaks16/Makefile.config 
    make�R�}���h��p����m16c-OAKS16�pTOPPERS/JSP���\�z����ꍇ��make�t�@�C��
c. oaks16_mini/Makefile.config 
    make�R�}���h��p����m16c-OAKS16 MINI�pTOPPERS/JSP���\�z����ꍇ��make�t�@�C��
d. ���̑� ---- M16C�ˑ����̃R�[�h


2.2 utils/m16c-renesas

a. makedep.m16c
    make��p���ĊJ�����ꍇ�A�\�[�X�̈ˑ��֌W�𐶐�����PERL�X�N���v�g
b. m16cutils.dsw 
    m16cvec.exe��m16coffset.exe�R�}���hVC++��p���č\�z���邽�߂̃��[�N�X�y�[�X�t�@�C��
c. m16cutils.opt 
    VC++�p��OPT�t�@�C��
d: m16cutils/m16coffset/m16coffset.dsp
    m16coffset�쐬�̃v���W�F�N�g�t�@�C��
e: m16cutils/m16coffset/m16coffset.cpp
    m16coffset�R�}���hC++����L�q
f: m16cutils/m16coffset/StdAfx.h
    �W���V�X�e���C���N���[�h�t�@�C��
g: m16cutils/m16coffset/StdAfx.cpp
    �W���V�X�e���C���N���[�h�t�@�C�����܂ރ\�[�X�t�@�C��
h: m16cutils/m16coffset/m16cvec.dsp
    m16cvec�쐬�̃v���W�F�N�g�t�@�C��
i: m16cutils/m16coffset/m16cvec.cpp
    m16cvec�R�}���hC++����L�q
j: m16cutils/m16coffset/StdAfx.h
    �W���V�X�e���C���N���[�h�t�@�C��
k: m16cutils/m16coffset/StdAfx.cpp
    �W���V�X�e���C���N���[�h�t�@�C�����܂ރ\�[�X�t�@�C��


2.3 utils/M16C-RENESAS

a.Jsp14sample1.tmi,Jsp14sample1.tmk 
   TM��p����OAKS16�p��TOPPERS/JSP���\�z���邽�߂̃v���W�F�N�g�t�@�C��
b.Jsp14sample1m.tmi,Jsp14samplem1.tmk
   TM��p����OAKS16 MINI�p��TOPPERS/JSP���\�z���邽�߂̃v���W�F�N�g�t�@�C��
c.Jsp14sample1_m3029.tmi,Jsp14samplem1_m3029.tmk 
   TM��p����M3029�p��TOPPERS/JSP���\�z���邽�߂̃v���W�F�N�g�t�@�C��
d.Jsp14sample1.id 
   ��������MOT�t�@�C����OAKS16�{�[�h�̃t���b�V��ROM�̏������ގ��Ɏg�p����ID�t�@�C��
e.Jsp14sample1m.id 
   ��������MOT�t�@�C����OAKS16 MINI�{�[�h�̃t���b�V��ROM�̏������ގ��Ɏg�p����ID�t�@�C��
f.Jsp14sample1_m3029.id 
   ��������MOT�t�@�C���� M3029�̃t���b�V��ROM�̏������ގ��Ɏg�p����ID�t�@�C��
g.sample1.cfg 
   OAKS16, M3029�p��TOPPERS/JSP���\�z���邽�߂̃R���t�B�M���t�@�C��
h.sample1m.cfg 
   OAKS16 MINI�p��TOPPERS/JSP���\�z���邽�߂̃R���t�B�M���t�@�C��


2.4  sample

a.Makefile.m16c-oaks16 
   make�R�}���h��p����OAKS16�p��TOPPERS/JSP���\�z���邽�߂�make�t�@�C��


