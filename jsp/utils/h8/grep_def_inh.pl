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
#  @(#) $Id: grep_def_inh.pl,v 1.1 2008/06/17 00:04:45 suikan Exp $
# 


#
#  �x�N�^�e�[�u�������p�t�B���^
#  �@�R���t�B�M�����[�V�����E�t�@�C���̃v���v���Z�X���ʂ�
#�@�@�x�N�^�e�[�u�������X�N���v�g(perl)�ɕϊ�����B
#�@�@�������ꂽ�X�N���v�g��genvector.pl����Ăяo�����B
#
#
#�@�g����
#�@�@grep_def_inh.pl file_name
#�@�@�@����file_name�F���̓f�[�^�t�@�C��
#�@�@�@�@�@�@�@�@�@�@�@�R���t�B�M�����[�V�����E�t�@�C���̃v���v���Z�X
#�@�@�@�@�@�@�@�@�@�@�@���ʂ��n����邱�Ƃ�z�肵�Ă���B

#�@�������e
#  �@�EDEF_INH����&define_inh(xx, "*******");�̌`�ɕϊ����ďo�͂���B
#  �@
#  �@���l
#  �@�E��2�����i�����݃n���h�������j��TA_HLNG���w�肳��Ă���Ɖ��肵�Ă���
#  �@�@�@�E��2�����̓`�F�b�N���s���Ă��Ȃ�
#  �@�@�@�ETA_HLNG�̒l�i0x00u�j�𕶎���u���̐��K�\���ɗp���Ă���

#
#�@DEF_INH���̓r���ŉ��s����Ă��������������邽�߁A
#�@��x�A���ׂĂ̍s��A�����Ă���A;�ŋ�؂蒼���B
#
#�@��{�I�ɕʂ̊��ō�������̓f�[�^��ǂݍ��ނ��Ƃ͍l�����Ă��Ȃ��B
#�@�܂�A���s�R�[�h�̈Ⴂ�ŁA��L��while���ň�s���ǂݍ��ނ����
#�@���ׂĂ̍s��1�x�ɓǂݍ��܂�Ă��܂��\���͖������Ă���B
#
$text = "";
while($line = <>) {
	#�@#�Ŏn�܂�s�̓v���v���Z�b�T�ɂ��R�����g�Ȃ̂ŁA�X�L�b�v����
	if ($line !~ /^#/) {
		$text .= $line;
	}
}

#�@���Ɉˑ����Ȃ����s�R�[�h�̒u��
#�@�@�E���K�\����(\x0D?\x0A?)�Ƃ��Ȃ��̂́A�󕶎��Ƀq�b�g�����Ȃ�����
$text =~ s/(\x0D\x0A)|\x0D|\x0A//g;

$text =~ s/(\s)+//g;		#�@�󔒕������폜
@list = split(/;/, $text);	#�@;���ɋ�؂�

#
#  &define_inh(xx, "*******");�̌`�ŏo�͂���B
#
#�@�����ŁA���x�����̑O���__kernel_��_entry��t�����Ȃ��̂�
#�@gcc�ł�HEW�łŋ��ʂɎg����悤�ɂ��邽�߁B
#�@HEW�łł́Atmp_script.pl���ȉ��̂Q�̖ړI�Ŏg�p�����B
#�@�@�E�x�N�^�e�[�u���̐���
#�@�@�E�����݂̏o���������̐���
#
foreach $line (@list) {
	if ($line =~ s/^DEF_INH\(/\&define_inh\(/) {
		
		# TA_HLNG�̒l��0x00u�ł��邱�Ƃ����肵�Ă���
		$line =~ s/,{0x00u,/\,"/;
		$line =~ s/}\)/"\)/g;
		
		#  �����ݔԍ��̖�����u,ul���t���Ă���ꍇ�͍폜����
		$line =~ s/((ul)|(lu)|(u)|(l))\,/\,/i;
		printf "\t%s;\n", $line;
	}
}

# ���C�u�����Ƃ��ČĂяo����悤�ɖ߂�l���P�ɂ���B
print "1;\n";

