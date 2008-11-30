/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
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
 *  @(#) $Id: mpc860_sil.h,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

#include <sil.h>

/*
 *  MPC860�����̐��䃌�W�X�^�ւ̃A�N�Z�X�E���[�e�B���e�B
 *  
 *  powerpc.h�ɋL�q����̂��G���K���g�����Asil.h�Ƃ̃C���N���[�h��
 *  ���Ԃ̊֌W�œƗ������t�@�C���Ƃ���B
 *  t_config.h�𒼐ڃC���N���[�h�����Ƃ���sil.h�����powerpc.h��
 *  �C���N���[�h�����\��������B
 *  
 *  �R���p�C���̌^�`�F�b�N�@�\��L���ɂ��邽�߁A�|�C���^�^��
 *  VB *�AVH *�AVW *��p���Ă���B
 *  
 */

#ifndef _MPC860_SIL_H_
#define _MPC860_SIL_H_

#ifndef _MACRO_ONLY

/*
 *  SIL�Ɠ����̃A�N�Z�X�֐��i�^�`�F�b�N�@�\�t���j
 */

#ifndef SIL_DEBUG

/*
 *  8�r�b�g�P�ʂ̓Ǐo���^������
 */
Inline VB
mpc860_reb_mem(VB *mem)
{
	VB reg = sil_reb_mem((VP)mem);
	return(reg);
}

Inline void
mpc860_wrb_mem(VB *mem, VB data)
{
	sil_wrb_mem((VP)mem, data);
}

/*
 *  16�r�b�g�P�ʂ̓Ǐo���^������
 */
Inline VH
mpc860_reh_mem(VH *mem)
{
	VH reg = sil_reh_mem((VP)mem);
	return(reg);
}

Inline void
mpc860_wrh_mem(VH *mem, VH data)
{
	sil_wrh_mem((VP)mem, data);
}

/*
 *  32�r�b�g�P�ʂ̓Ǐo���^������
 */
Inline VW
mpc860_rew_mem(VW *mem)
{
	VW reg = sil_rew_mem((VP)mem);
	return(reg);
}

Inline void
mpc860_wrw_mem(VW *mem, VW data)
{
	sil_wrw_mem((VP)mem, data);
}



/*
 *  �r�b�g���Z
 */

/*
 *  8�r�b�g���W�X�^��AND���Z
 */
Inline void
mpc860_andb_mem(VB *mem, VB data)
{
	VB reg = mpc860_reb_mem((VP)mem);
	reg &= data;
	mpc860_wrb_mem(mem, reg);
}

/*
 *  8�r�b�g���W�X�^��OR���Z
 */
Inline void
mpc860_orb_mem(VB *mem, VB data)
{
	VB reg = mpc860_reb_mem(mem);
	reg |= data;
	mpc860_wrb_mem(mem, reg);
}


/*
 *  16�r�b�g���W�X�^��AND���Z
 */
Inline void
mpc860_andh_mem(VH *mem, VH data)
{
	VH reg = mpc860_reh_mem(mem);
	reg &= data;
	mpc860_wrh_mem(mem, reg);
}

/*
 *  16�r�b�g���W�X�^��OR���Z
 */
Inline void
mpc860_orh_mem(VH *mem, VH data)
{
	VH reg = mpc860_reh_mem(mem);
	reg |= data;
	mpc860_wrh_mem(mem, reg);
}

/*
 *  32�r�b�g���W�X�^��AND���Z
 */
Inline void
mpc860_andw_mem(VW *mem, VW data)
{
	VW reg = mpc860_rew_mem(mem);
	reg &= data;
	mpc860_wrw_mem(mem, reg);
}

/*
 *  32�r�b�g���W�X�^��OR���Z
 */
Inline void
mpc860_orw_mem(VW *mem, VW data)
{
	VW reg = mpc860_rew_mem(mem);
	reg |= data;
	mpc860_wrw_mem(mem, reg);
}

#else	/*  SIL_DEBUG  */

extern UW sil_log_id;
extern BOOL sil_debug_on;

/*
 *  SIL�̃��O�o�͂����蓖�Ă郍�O�d�v�x�̒�`
 *�@�iuser.txt�́u4.4 ���O���̏d�v�x�v�Q�Ɓj
 */
#ifndef LOG_SIL
#define LOG_SIL	LOG_EMERG
#endif	/*  LOG_SIL  */


/*
 *  8�r�b�g�P�ʂ̓Ǐo��
 */
#define mpc860_reb_mem(mem)	mpc860_reb_mem_deb(#mem, mem)

Inline VB
mpc860_reb_mem_deb(char *str, VB *mem)
{
	BOOL sil_debug_tmp, is_end_of_line;
	SYSUTIM sysutim;
	VB reg;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	reg = sil_reb_mem((VP)mem);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		is_end_of_line = (reg == '\n') || (reg == '\r');
		if (!is_end_of_line) {
			syslog(LOG_SIL, 
			"%d time:%08d read VB %s(0x%08x) data=0x%02x(%c)",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UB)reg, (UW)(UB)reg);
		} else {
			syslog(LOG_SIL, 
			"%d time:%08d read VB %s(0x%08x) data=0x%02x(%s)",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UB)reg, 
			(reg == '\n') ? "\\n" : "\\r");
		}
	}
	
	return(reg);
}


/*
 *  8�r�b�g�P�ʂ̏�������
 */
#define mpc860_wrb_mem(mem, data)	mpc860_wrb_mem_deb(#mem, mem, data)

Inline void
mpc860_wrb_mem_deb(char *str, VB *mem, VB data)
{
	BOOL sil_debug_tmp, is_end_of_line;
	SYSUTIM sysutim;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	sil_wrb_mem((VP)mem, data);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		is_end_of_line = (data == '\n') || (data == '\r');
		if (!is_end_of_line) {
			syslog(LOG_SIL, 
			"%d time:%08d write VB %s(0x%08x) data=0x%02x(%c)",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UB)data, (UW)(UB)data);
		} else {
			syslog(LOG_SIL, 
			"%d time:%08d write VB %s(0x%08x) data=0x%02x(%s)",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UB)data, 
			(data == '\n') ? "\\n" : "\\r");
		}
	}
}

/*
 *  16�r�b�g�P�ʂ̓Ǐo��
 */
#define mpc860_reh_mem(mem)	mpc860_reh_mem_deb(#mem, mem)

Inline VH
mpc860_reh_mem_deb(char *str, VH *mem)
{
	BOOL sil_debug_tmp;
	SYSUTIM sysutim;
	VH reg;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	reg = sil_reh_mem((VP)mem);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		syslog(LOG_SIL, 
			"%d time:%08d read VH %s(0x%08x) data=0x%04x",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UH)reg);
	}
	
	return(reg);
}

/*
 *  16�r�b�g�P�ʂ̏�������
 */
#define mpc860_wrh_mem(mem, data)	mpc860_wrh_mem_deb(#mem, mem, data)

Inline void
mpc860_wrh_mem_deb(char *str, VH *mem, VH data)
{
	BOOL sil_debug_tmp;
	SYSUTIM sysutim;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	sil_wrh_mem((VP)mem, data);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		syslog(LOG_SIL, 
			"%d time:%08d write VH %s(0x%08x) data=0x%04x",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)(UH)data);
	}
}


/*
 *  32�r�b�g�P�ʂ̓Ǐo��
 */
#define mpc860_rew_mem(mem)	mpc860_rew_mem_deb(#mem, mem)

Inline VW
mpc860_rew_mem_deb(char *str, VW *mem)
{
	BOOL sil_debug_tmp;
	SYSUTIM sysutim;
	VW reg;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	reg = sil_rew_mem((VP)mem);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		syslog(LOG_SIL, 
			"%d time:%08d read VW %s(0x%08x) data=0x%08x",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)reg);
	}
	
	return(reg);
}


/*
 *  32�r�b�g�P�ʂ̏�������
 */
#define mpc860_wrw_mem(mem, data)	mpc860_wrw_mem_deb(#mem, mem, data)

Inline void
mpc860_wrw_mem_deb(char *str, VW *mem, VW data)
{
	BOOL sil_debug_tmp;
	SYSUTIM sysutim;
	ER err;
	SIL_PRE_LOC;
	
	sil_debug_tmp = sil_debug_on;
	if (sil_debug_on) {
		SIL_LOC_INT();
		sil_debug_on = FALSE;
		++sil_log_id;
		SIL_UNL_INT();
		err = vxget_tim(&sysutim);
		if (err != E_OK) {
			sysutim = 0;
		}
		SIL_LOC_INT();
	}
	
	sil_wrw_mem((VP)mem, data);

	if (sil_debug_tmp) {
		sil_debug_on = TRUE;
		SIL_UNL_INT();
		syslog(LOG_SIL, 
			"%d time:%08d write VW %s(0x%08x) data=0x%08x",
			sil_log_id, (UW)sysutim, str, 
			(UW)mem, (UW)data);
	}
}


/*
 *  �r�b�g���Z
 */

/*
 *  8�r�b�g���W�X�^��AND���Z
 */
#define mpc860_andb_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s & 0x%02x",	 		\
			#mem, (UW)(UB)data);			\
	}							\
	mpc860_andb_mem_deb(mem, data)

Inline void
mpc860_andb_mem_deb(VB *mem, VB data)
{
	VB reg = mpc860_reb_mem((VP)mem);
	reg &= data;
	mpc860_wrb_mem(mem, reg);
}

/*
 *  8�r�b�g���W�X�^��OR���Z
 */
#define mpc860_orb_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s | 0x%02x",	 		\
			#mem, (UW)(UB)data);			\
	}							\
	mpc860_orb_mem_deb(mem, data)

Inline void
mpc860_orb_mem_deb(VB *mem, VB data)
{
	VB reg = mpc860_reb_mem(mem);
	reg |= data;
	mpc860_wrb_mem(mem, reg);
}


/*
 *  16�r�b�g���W�X�^��AND���Z
 */
#define mpc860_andh_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s & 0x%04x",	 		\
			#mem, (UW)(UH)data);			\
	}							\
	mpc860_andh_mem_deb(mem, data)

Inline void
mpc860_andh_mem_deb(VH *mem, VH data)
{
	VH reg = mpc860_reh_mem(mem);
	reg &= data;
	mpc860_wrh_mem(mem, reg);
}

/*
 *  16�r�b�g���W�X�^��OR���Z
 */
#define mpc860_orh_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s | 0x%04x",	 		\
			#mem, (UW)(UH)data);			\
	}							\
	mpc860_orh_mem_deb(mem, data)

Inline void
mpc860_orh_mem_deb(VH *mem, VH data)
{
	VH reg = mpc860_reh_mem(mem);
	reg |= data;
	mpc860_wrh_mem(mem, reg);
}

/*
 *  32�r�b�g���W�X�^��AND���Z
 */
#define mpc860_andw_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s & 0x%08x",	 		\
			#mem, (UW)data);			\
	}							\
	mpc860_andw_mem_deb(mem, data)

Inline void
mpc860_andw_mem_deb(VW *mem, VW data)
{
	VW reg = mpc860_rew_mem(mem);
	reg &= data;
	mpc860_wrw_mem(mem, reg);
}

/*
 *  32�r�b�g���W�X�^��OR���Z
 */
#define mpc860_orw_mem(mem, data)				\
	if (sil_debug_on) {					\
		syslog(LOG_SIL, "%s | 0x%08x",	 		\
			#mem, (UW)data);			\
	}							\
	mpc860_orw_mem_deb(mem, data)

Inline void
mpc860_orw_mem_deb(VW *mem, VW data)
{
	VW reg = mpc860_rew_mem(mem);
	reg |= data;
	mpc860_wrw_mem(mem, reg);
}


#endif	/*  SIL_DEBUG  */

/*
 *  CP�R�}���h�����s�\�ɂȂ�܂ő҂�
 */
Inline void
mpc860_wait_ready_CP_command(void)
{
	UH cpcr;
    	do {
		cpcr = mpc860_reh_mem(CPCR);
    	} while(cpcr & CPCR_FLG); 
}	


/*
 *  CP�R�}���h�𔭍s����
 *	����
 *	�@UW opcode�F�R�}���h���
 *	�@UW ch_num�F�`���l���ԍ��i�f�o�C�X�ԍ��j
 */
Inline void
mpc860_CP_command(UW opcode, UW ch_num)
{
	UH cpcr;
	
	/*  ����CP�R�}���h�I���҂�  */
	mpc860_wait_ready_CP_command();
	
	/*  CP�R�}���h���s  */
	cpcr = (UH)((opcode << 8) | (ch_num << 4) | CPCR_FLG);
    	mpc860_wrh_mem(CPCR, cpcr);

	/*  CP�R�}���h�I���҂�  */
	mpc860_wait_ready_CP_command();
    	
}



#endif /* _MACRO_ONLY */
#endif	/*  _MPC860_SIL_H_  */
/*  end of file  */
