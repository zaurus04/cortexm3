
        �� TOPPERS/JSP�J�[�l�� ���[�U�Y�}�j���A�� ��
                    �iGHS�f�o�b�O���j

        �iRelease 1.4 �Ή��C�ŏI�X�V: 24-Dec-2003�j

------------------------------------------------------------------------
 TOPPERS/JSP Kernel
     Toyohashi Open Platform for Embedded Real-Time Systems/
     Just Standard Profile Kernel

 Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
                             Toyohashi Univ. of Technology, JAPAN
 Copyright (C) 2003 by Advanced Data Controls, Corp

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

���̃h�L�������g�ł́ATOPPERS/JSP��Green Hills Software(GHS)�Ђ��J�����������J����MULTI�ł̍\�z�ɕK�v�ȃt�@�C���ɂ��ĉ������B

1. �f�B���N�g���̍\��

jsp
  +--config
  |     +---armv4-ghs
  |     |      +---integrator
  |     +---sh3-ghs
  |            +---ms7727cp01
  |            +---solution_engine
  +--tools
        +-----GHS
               +---ghs_hook_bld
               +---kernel_bld
               +---sample


2.�Ή��v���Z�b�T

�ESH3(solution engine��ms7727)
�Earmv4(Integrator/AP�A�R�AARM966ES��ARM920T)


3.�@�f�B���N�g���ƃt�@�C���̐���

GNU���ł̎����ƈقȂ�t�@�C����config/armv4-ghs�܂���config/sh3-ghs�f�B���N�g���ɒu����Ă���B
�܂��Atools/GHS�f�B���N�g���ɂ̓J�[�l���Ȃǂ��r���h���邽�߂̃t�@�C����GHS�J�����Ɉˑ�����t�@�C�����u����Ă���B

3.1 config/armv4-ghs

a. armv4t-ghs.bld ---- armv4�ˑ�����integrator�̃r���h�t�@�C��
b. integrator/integrator.bld ---- integrator�ˑ����̃r���h�t�@�C��
c. ���̑� ---- armv4�ˑ����̃R�[�h
armv4t-ghs.bld����integrator.bld���C���N���[�h����Ă���Aarmv4t-ghs.bld���v���W�F�N�g�ɃC���N���[�h����΁A�����I��integrator.bld���C���N���[�h�����B

3.2 config/sh3-ghs

a. sh3_ms7727-ghs.bld ---- sh3��ms7727�ˑ����̃r���h�t�@�C��
b. sh3_solution-ghs.bld ---- sh3��solution_engine�ˑ����̃r���h�t�@�C��
c. ms7727cp01/ms7727cp01.bld ---- ms7727�ˑ����̃r���h�t�@�C��
d. solution_engine/solution.bld ---- solution_engine�ˑ����̃r���h�t�@�C��

sh3_ms7727-ghs.bld����ms7727cp01.bld���C���N���[�h����Ă���Ash3_ms7727-ghs.bld���v���W�F�N�g�ɃC���N���[�h����΁A�����I��ms7727cp01.bld���C���N���[�h�����Bsh3_solution.bld�����l�ł���B

3.3 tools/GHS/kernel_bld

���̃f�B���N�g���̓J�[�l����V�X�^�X�N�Ȃǂ��r���h���邽�߂̃t�@�C�����u����Ă���B

a. kernel.bld ---- �J�[�l�������C�u�����Ƀr���h���邽�߂̃t�@�C���B���̃r���h�t�@�C���ɂ͈ȉ��̃r���h�t�@�C�����܂܂�Ă���B
 �E cyclic.bld 
 �E dataqueue.bld 
 �E eventflag.bld
 �E exception.bld
 �E interrupt.bld
 �E mailbox.bld
 �E mempfix.bld
 �E semaphore.bld
 �E sys_manage.bld
 �E syslog.bld
 �E task.bld
 �E task_except.bld
 �E task_manage.bld
 �E task_sync.bld
 �E time_event.bld
 �E time_manage.bld
 �E wait.bld

kernel.bld���v���W�F�N�g�ɃC���N���[�h����΁A�����I�ɃJ�[�l���̃��C�u�������v���W�F�N�g�ɃC���N���[�h����A�v���W�F�N�g���r���h����ƃJ�[�l�����r���h�����Bkernel.bld�͔ėp���̂��߁ACPU�I�v�V������C���N���[�h�t�@�C���̃T�[�`�p�[�X�Ȃǂ��ݒ肳��Ă��炸�A�P�Ƃł̓r���h�ł��Ȃ��B�J�[�l���������r���h����ꍇ�Akernel.bld�������C���N���[�h���Ă���ʂ̃r���h�t�@�C�����쐬���A���̃r���h�t�@�C����CPU�I�v�V������T�[�`�p�[�X�̐ݒ������Ηǂ��B

b. library.bld ---- log_output.c, strerror.c, t_perror.c, vasyslog.c���I�u�W�F�N�g�Ƀr���h���邽�߂̃t�@�C���ł���B

c. systask.bld ---- serial.c, timer.c, logtask.c ���I�u�W�F�N�g�t�@�C���Ƀr���h���邽�߂̃t�@�C���ł���B



3.4  tools/GHS/ghs_hook_bld

���̃f�B���N�g���̓g���[�X���O�}�N���Ȃǂ̃J�[�l���̃f�o�b�O����MULTI�f�o�b�K�ŕ\�������邽�߂̃R�[�h���u����Ă���B

a. ghs_hook.bld ---- �f�o�b�O����\������邽�߂̃R�[�h�̃r���h�t�@�C��
b. ���̑� ---- �f�o�b�O����\������邽�߂̃R�[�h

�g���[�X���O�}�N���@�\���g�p����Ȃ�v���W�F�N�g�̃r���h�t�@�C���̃t�@�C���I�v�V������GHS_HOOK���`���Ȃ���΂Ȃ�Ȃ��B����ɁAGHS_HOOK=2���w�肷��ƃg���[�X�f�[�^�́A�K�v�Ȃ��̂�����I�����Ď擾���邱�Ƃ��ł��܂��BGHS_HOOK=1���f�t�H���g�ŁA�S�Ẵg���[�X�f�[�^���擾�����B

BUFF_SIZE=xxx���`����΁A�g���[�X���O�}�N���p�̃o�b�t�@�T�C�Y���w��ł���B�������ABUFF_SIZE �͕K���A1024(1kbyte) , 2048(2kbyte) , 4096(4kbyte) , 8192(8kbyte) , 16384(16kbyte) �̒�����w�肵�Ă��������BBUFF_SIZE�̃f�t�H���g�l��16kbyte�ł���B


3.5 tools/GHS/sample

���̃f�B���N�g���̓T���v���v���O�����̃R�[�h�̃r���h�t�@�C�����u����Ă���B

a. arm920t.bld ---- Integrator/ARM920T�p�̃T���v���v���O�����̃r���h�t�@�C��
b. solution_engine.bld ---- SH3/Solution Engine�p�̃T���v���v���O�����̃r���h�t�@�C��
c. linker_arm.lnk ---- ARMV4�̃����J�[�t�@�C��
d. linker_sh3.lnk ---- SH3�̃����J�[�t�@�C��
e. kernel.bld ---- 3.3�߂��Q��
f. systask.bld ---- 3.3�߂��Q��
g. library.bld ---- 3.3�߂��Q��
h. armv4t-ghs.bld�܂���sh3_solution-ghs.bld ---- 3.1�߂܂���3.2�߂��Q��
i. user_program.bld --- �T���v���v���O�����̃R�[�h�̃r���h�t�@�C���B
j. configuration.bld --- �R���t�B�M�����[�V�����t�@�C�����������邽�߂̃r���h�t�@�C��
k. ���̑� --- �T���v���v���O�����̃R�[�h

arm920t.bld�܂���solution_engine.bld�̍\���͈ȉ��Ɏ����B

arm920t.bld/solution_engine.bld
    |-------kernel.bld
    |-------systask.bld
    |-------library.bld
    |-------armv4t-ghs.bld/sh3_solution-ghs.bld
    |-------ghs_hook.bld
    |-------user_program.bld
    |------------|---configuration.bld
    |------------|---------|----sample1.cfg
    |------------|----sample1.c
    |------------|----sample1.h
    |-------linker_arm.lnk/linker_sh3.lnk


��1�߂Ɏ������f�B���N�g���\���ł́Aarm920t.bld�܂���solution_engine.bld�������ύX���Ȃ��Ńr���h�ł��邪�A�f�B���N�g���̍\�����قȂ�ꍇ�A�T�[�`�p�[�X��ς���K�v������B

