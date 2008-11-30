#! /usr/bin/perl
#
#  TOPPERS/JSP Kernel
#      Toyohashi Open Platform for Embedded Real-Time Systems/
#      Just Standard Profile Kernel
# 
#  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
#                              Toyohashi Univ. of Technology, JAPAN
#  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
#              Graduate School of Information Science, Nagoya Univ., JAPAN
#  Copyright (C) 2005-2007 by Industrial Technology Institute,
#                              Miyagi Prefectural Government, JAPAN
# 
#  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
#  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
#  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
#  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
#  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
#  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
#      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
#      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
#  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
#      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
#      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
#      �̖��ۏ؋K����f�ڂ��邱�ƁD
#  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
#      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
#      �ƁD
#    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
#        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
#    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
#        �񍐂��邱�ƁD
#  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
#      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
# 
#  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
#  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
#  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
#  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
# 
#  @(#) $Id: gen_intentry.pl,v 1.1 2008/06/17 00:04:58 suikan Exp $
# 


#
#  �����݂̓������������X�N���v�g
#  �@���O�ɐ��������tmp_script.pl��ǂݍ��ނ��Ƃɂ���Ď��s�ł���悤�ɂȂ�B
#
#�@�@��������H8S�łƏ������قȂ邽�߁A�������Ă���B
#


#
#  tmp_script.pl������Ă΂��֐��̒�`
#�@�@ �����݂̓����������o�͂���B
#
sub define_inh {
	my($inhno, $handler) = @_;
	
	printf " INTHDR_ENTRY %s, %s_intmask\n", $handler , $handler;
}	

#
# �����݂̓��������̏o��
#
print <<INTENTRY

;
;  �����݂̓��������̒�`
;    ���̃t�@�C���ɂ̓��[�U�[��`�̊����݃n���h���iC���ꃋ�[�`���j����
;    �L�q����
;
        .SECTION P, CODE, ALIGN=2

;
;    �����݂̓��������𐶐�����}�N���̎g����
;      �i�����ݗv�����ɈقȂ镔���j
;
;    �}�N��INTHDR_ENTRY C_ROUTINE, INTMASK
;      �p�����[�^
;          C_ROUTINE�FC���ꃋ�[�`���̊֐����i�擪��'_'�͕t���Ȃ��j
;          INTMASK�F  �����݋����Ɋ����݃}�X�N�ɐݒ肷��l
;                      IPM_LEVEL1�AIPM_LEVEL2�̂����ꂩ�ɂ��邱��
;                      �����Ɠ������x���̊����݂��}�X�N���邽�߁A
;                      IPM�ɂ͂P��̃��x����ݒ肷��B
;

INTENTRY
;

# �����������ꂽ�X�N���v�g�̓ǂݍ��݂Ǝ��s
require "./tmp_script.pl";

print "\n .END\n";

