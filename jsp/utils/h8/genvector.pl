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
#  @(#) $Id: genvector.pl,v 1.1 2008/06/17 00:04:45 suikan Exp $
# 


#
#  �x�N�^�e�[�u�������X�N���v�g
#  �@make depend���ɐ��������tmp_script.pl��ǂݍ��ނ��Ƃɂ����
#  �@���s�ł���悤�ɂȂ�

#  �I�v�V�����̒�`
#
#  -s <vector size>	�x�N�^�[�e�[�u���̃T�C�Y
#  -z 		�o�^����Ă��Ȃ������݃x�N�^�ɂ�0����������
#		-z�I�v�V�������w�肵�Ȃ��ꍇ�́A_no_reg_expretion��
#		��������
#		���s���iMakefile�Œ�`���Ă���DBGENV�}�N���̒l�j��
#		���j�^�̎d�l�ɂ��A�K�v�ɉ����ėp����


require "getopt.pl";


#
#  �����݃n���h�����x�N�^�e�[�u���ɓo�^
#�@�@ tmp_script.pl������Ă΂��B

sub define_inh {
	my($inhno, $inthdr) = @_;
	
	if ($inhno == 0) {
		print STDERR <<ERRMESSAGE
In generating vector.S
Error in DEF_INH($inhno, {TA_HLNG, $inthdr});
\t Macro of interrupt handler number $inhno isn't defined.
\t If you define macro $inhno in header files,
\t it's necessary to use "#include" directive in configuration files
\t to genarate vector.S. 
\t (And it's also necessary to use static API "INCLUDE()" 
\t in configuration files to genarate kernel_cfg.c. )
\t Check configuration files and header files.

ERRMESSAGE
		;
		exit(1);
	}
	else {
		# �x�N�^�e�[�u���Ɋ����݃n���h����o�^
		#�@�@ �����݃n���h�����̑O���"__kernel_"��"_entry"��t��
		$vector_table[$inhno] = "__kernel_" . $inthdr . "_entry";
	}
}	


#
#  �I�v�V�����̏���
#
do Getopt("s");

if ($opt_s == 0) {
	print STDERR "genvector.pl:\n";
	print STDERR "\t -s option(vector size) is necessary.\n";
	print STDERR "\t check jsp/config/h8/\$(SYS)/Makefile.config\n";
	exit(1);
}
	
$vector_size = $opt_s;

# ���s���ɂ���āA���o�^�̊����ݏ����̋L�q��؂蕪����
if ($opt_z) {
	$no_reg_exception = "0";
}
else {
	$no_reg_exception = "_no_reg_exception";
}

for ($i=0; $i<$vector_size; $i++) {
	$vector_table[$i]=$no_reg_exception;
}

# ���Z�b�g�x�N�^�̒�`
$vector_table[0] = "_start";

# �����������ꂽ�X�N���v�g�̓ǂݍ���
require "./tmp_script.pl";

# �x�N�^�e�[�u���̏o��
for ($i=0; $i<$vector_size; $i++) {
	printf "\t.long %s\t\t/* %d(0x%02x) */\n", $vector_table[$i], $i, $i;
}

