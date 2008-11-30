/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 *  @(#) $Id: check.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *	�G���[�`�F�b�N�p�}�N��
 */

#ifndef _CHECK_H_
#define _CHECK_H_

/*
 *  �D��x�͈̔͂̔���
 */
#define VALID_TPRI(tpri) \
	(TMIN_TPRI <= (tpri) && (tpri) <= TMAX_TPRI)

/*
 *  �^�X�N�D��x�̃`�F�b�N�iE_PAR�j
 */
#define CHECK_TPRI(tpri) {					\
	if (!VALID_TPRI(tpri)) {				\
		ercd = E_PAR;					\
		goto exit;					\
	}							\
}

#define CHECK_TPRI_INI(tpri) {					\
	if (!(VALID_TPRI(tpri) || (tpri) == TPRI_INI)) {	\
		ercd = E_PAR;					\
		goto exit;					\
	}							\
}

#define CHECK_TPRI_SELF(tpri) {					\
	if (!(VALID_TPRI(tpri) || (tpri) == TPRI_SELF)) {	\
		ercd = E_PAR;					\
		goto exit;					\
	}							\
}

/*
 *  �^�C���A�E�g�w��l�̃`�F�b�N�iE_PAR�j
 */
#define CHECK_TMOUT(tmout) {					\
	if (!(TMO_FEVR <= (tmout))) {				\
		ercd = E_PAR;					\
		goto exit;					\
	}							\
}

/*
 *  ���̑��̃p�����[�^�G���[�̃`�F�b�N�iE_PAR�j
 */
#define CHECK_PAR(exp) {					\
	if (!(exp)) {						\
		ercd = E_PAR;					\
		goto exit;					\
	}							\
}

/*
 *  �I�u�W�F�N�gID�͈̔͂̔���
 */
#define VALID_TSKID(tskid) \
	(TMIN_TSKID <= (tskid) && (tskid) <= tmax_tskid)

#define VALID_SEMID(semid) \
	(TMIN_SEMID <= (semid) && (semid) <= tmax_semid)

#define VALID_FLGID(flgid) \
	(TMIN_FLGID <= (flgid) && (flgid) <= tmax_flgid)

#define VALID_DTQID(dtqid) \
	(TMIN_DTQID <= (dtqid) && (dtqid) <= tmax_dtqid)

#define VALID_MBXID(mbxid) \
	(TMIN_MBXID <= (mbxid) && (mbxid) <= tmax_mbxid)

#define VALID_MPFID(mpfid) \
	(TMIN_MPFID <= (mpfid) && (mpfid) <= tmax_mpfid)

#define VALID_CYCID(cycid) \
	(TMIN_CYCID <= (cycid) && (cycid) <= tmax_cycid)

/*
 *  �I�u�W�F�N�gID�̃`�F�b�N�iE_ID�j
 */
#define CHECK_TSKID(tskid) {					\
	if (!VALID_TSKID(tskid)) {				\
		ercd = E_ID;					\
		goto exit;					\
	}							\
}

#define CHECK_TSKID_SELF(tskid) {				\
	if (!(VALID_TSKID(tskid) || (tskid) == TSK_SELF)) {	\
		ercd = E_ID;					\
		goto exit;					\
	}							\
}

#define CHECK_SEMID(semid) {					\
	if (!VALID_SEMID(semid)) {				\
		ercd = E_ID;					\
		goto exit;					\
	}							\
}

#define CHECK_FLGID(flgid) {					\
	if (!VALID_FLGID(flgid)) {				\
		ercd = E_ID;					\
		goto exit;					\
	}							\
}

#define CHECK_DTQID(dtqid) {					\
	if (!VALID_DTQID(dtqid)) {				\
		ercd = E_ID;					\
		goto exit;					\
	}							\
}

#define CHECK_MBXID(mbxid) {					\
	if (!VALID_MBXID(mbxid)) {				\
		ercd = E_ID;					\
		goto exit;					\
	}							\
}

#define CHECK_MPFID(mpfid) {					\
	if (!VALID_MPFID(mpfid)) {				\
		ercd = E_ID;					\
		goto exit;					\
	}							\
}

#define CHECK_CYCID(cycid) {					\
	if (!VALID_CYCID(cycid)) {				\
		ercd = E_ID;					\
		goto exit;					\
	}							\
}

/*
 *  �ďo���R���e�L�X�g�̃`�F�b�N�iE_CTX�j
 */
#define CHECK_TSKCTX() {					\
	if (sense_context()) {					\
		ercd = E_CTX;					\
		goto exit;					\
	}							\
}

#define CHECK_INTCTX() {					\
	if (!sense_context()) {					\
		ercd = E_CTX;					\
		goto exit;					\
	}							\
}

/*
 *  �ďo���R���e�L�X�g��CPU���b�N��Ԃ̃`�F�b�N�iE_CTX�j
 */
#define CHECK_TSKCTX_UNL() {					\
	if (sense_context() || t_sense_lock()) {		\
		ercd = E_CTX;					\
		goto exit;					\
	}							\
}

#define CHECK_INTCTX_UNL() {					\
	if (!sense_context() || i_sense_lock()) {		\
		ercd = E_CTX;					\
		goto exit;					\
	}							\
}

/*
 *  �f�B�X�p�b�`�ۗ���ԂłȂ����̃`�F�b�N�iE_CTX�j
 */
#define CHECK_DISPATCH() {					\
	if (sense_context() || t_sense_lock() || !(enadsp)) {	\
		ercd = E_CTX;					\
		goto exit;					\
	}							\
}

/*
 *  ���̑��̃R���e�L�X�g�G���[�̃`�F�b�N�iE_CTX�j
 */
#define CHECK_CTX(exp) {					\
	if (!(exp)) {						\
		ercd = E_CTX;					\
		goto exit;					\
	}							\
}

/*
 *  ���^�X�N���w�肵�Ă��Ȃ����̃`�F�b�N�iE_ILUSE�j
 */
#define CHECK_NONSELF(tcb) {					\
	if ((tcb) == runtsk) {					\
		ercd = E_ILUSE;					\
		goto exit;					\
	}							\
}

/*
 *  ���̑��̕s���g�p�G���[�̃`�F�b�N�iE_ILUSE�j
 */
#define CHECK_ILUSE(exp) {					\
	if (!(exp)) {						\
		ercd = E_ILUSE;					\
		goto exit;					\
	}							\
}

#endif /* _CHECK_H_ */
