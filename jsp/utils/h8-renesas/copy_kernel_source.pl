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

#�@�������e
#  �@�Ejsp/kernel�ɂ���\�[�X�R�[�h��API���ɃR�s�[����B
#  �@�@�i�֐��P�ʂŃ����N�ł���悤�ɂ���j
#  �@�E�R�s�[����ۂɁA�t�@�C���擪��#define __tskini�Ȃǂ̃}�N����`��ǉ�����B
#  �@
#  �g����
#  �@�@perl copy_kernel_source.pl src_path dst_path
#  �@�@�@����
#  �@�@�@�@src_path�Fjsp/kernel�ւ̑��΃p�X
#  �@�@�@�@dst_path�F�t�@�C���̃R�s�[��ւ̑��΃p�X


$src_path = $ARGV[0];
$dst_path = $ARGV[1];

# ���ɂȂ�\�[�X�t�@�C�����ƒǉ�����}�N�����̒�`
%hash_array = (
 "task.c"
	=> [qw(tskini tsksched tskrun tsknrun tskdmt tskact tskext tskpri tskrot tsktex)],
 "wait.c"
	=> [qw(waimake waicmp waitmo waitmook waican wairel wobjwai wobjwaitmo wobjpri)],
 "time_event.c"
	=> [qw(tmeini tmeup tmedown tmeins tmedel isig_tim)],
 "syslog.c"
	=> [qw(logini vwri_log vrea_log vmsk_log logter)],
 "task_manage.c"
	=> [qw(act_tsk iact_tsk can_act ext_tsk ter_tsk chg_pri get_pri)],
 "task_sync.c"
	=> [qw(slp_tsk tslp_tsk wup_tsk iwup_tsk can_wup rel_wai irel_wai sus_tsk rsm_tsk frsm_tsk dly_tsk)],
 "task_except.c"
	=> [qw(ras_tex iras_tex dis_tex ena_tex sns_tex)],
 "semaphore.c"
	=> [qw(semini sig_sem isig_sem wai_sem pol_sem twai_sem)],
 "eventflag.c"
	=> [qw(flgini flgcnd set_flg iset_flg clr_flg wai_flg pol_flg twai_flg)],
 "dataqueue.c"
	=> [qw(dtqini dtqenq dtqfenq dtqdeq dtqsnd dtqrcv snd_dtq psnd_dtq ipsnd_dtq tsnd_dtq fsnd_dtq ifsnd_dtq rcv_dtq prcv_dtq trcv_dtq)],
 "mailbox.c"
	=> [qw(mbxini snd_mbx rcv_mbx prcv_mbx trcv_mbx)],
 "mempfix.c"
	=> [qw(mpfini mpfget get_mpf pget_mpf tget_mpf rel_mpf)],
 "time_manage.c"
	=> [qw(set_tim get_tim vxget_tim)],
 "cyclic.c"
	=> [qw(cycini cycenq sta_cyc stp_cyc cyccal)],
 "sys_manage.c"
	=> [qw(rot_rdq irot_rdq get_tid iget_tid loc_cpu iloc_cpu unl_cpu iunl_cpu dis_dsp ena_dsp sns_ctx sns_loc sns_dsp sns_dpn vsns_ini)],
 "interrupt.c"
	=> [qw(inhini)],
 "exception.c"
	=> [qw(excini vxsns_ctx vxsns_loc vxsns_dsp vxsns_dpn vxsns_tex)]
);

#
#�@���C���̏���
#
foreach $file (keys(%hash_array)) {
	@array = @{$hash_array{$file}};
	foreach $api (@array) {
		&copy_file($file, $api);
	}
}


#
#�@��1�����F���ɂȂ�\�[�X�R�[�h�̃t�@�C�����i�p�X���܂܂��j
#�@��2�����F�����R���p�C���p�̃}�N����`��ǉ�����API�A�֐���
#�@�@�@�@�@�@���o�͂���t�@�C���������˂Ă���B
#
sub copy_file {
	my($filename, $api) = @_;
	open(OUTFILE, ">$dst_path/$api.c") || die "Cannot open $dst_path/$api.c";
	
	# API���̃}�N����`��ǉ�
	print OUTFILE "#define __$api\n";
	
	# jsp/kernel����t�@�C�����R�s�[
	open(INFILE, "$src_path/$filename") || die "Cannot open $src_path/$filename";
	while ($line = <INFILE>) {
		print OUTFILE $line;
	}
	
	close(INFILE);
	close(OUTFILE);
}
