/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
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
 */

#ifndef _CPU_DEFS_H_
#define _CPU_DEFS_H_

/*
 *  �v���Z�b�T�Ɉˑ������`�iH8S�p�j
 *
 *  ���̃C���N���[�h�t�@�C���́Ckernel.h �� sil.h �ŃC���N���[�h�����D
 *  ���̃t�@�C�����璼�ڃC���N���[�h���邱�Ƃ͂Ȃ��D���̃t�@�C�����C��
 *  �N���[�h����O�ɁCt_stddef.h �� itron.h ���C���N���[�h�����̂ŁC
 *  �����Ɉˑ����Ă��悢�D
 */

#define H8S

/* �J�[�l���N�����̃��b�Z�[�W */
#define COPYRIGHT_CPU \
"Copyright (C) 2001-2007 by Industrial Technology Institute,\n" \
"                            Miyagi Prefectural Government, JAPAN\n" \
"Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering,\n" \
"                 Tomakomai National College of Technology, JAPAN\n"

#ifndef _MACRO_ONLY

/*
 *  �����݁^CPU��O�n���h���ԍ��̌^
 */
typedef	UINT	INHNO;			/* �����݃n���h���ԍ� */
typedef	UINT	EXCNO;			/* CPU��O�n���h���ԍ� */

/*
 *  �����݃}�X�N�̌^�Ɗ����݃}�X�N�̕ύX�^�Q��
 */

/* �����݃}�X�N�̌^ */
typedef	UB	IPM;			/* �����݃}�X�N */

/* �����݃}�X�N����p�̊֐� */
extern ER	chg_ipm(IPM ipm) throw();	/* �����݃}�X�N�̕ύX */
extern ER	get_ipm(IPM *p_ipm) throw();	/* �����݃}�X�N�̎擾 */

#if 0		/*  �����_�ł̓T�|�[�g���Ă��Ȃ�  */
/*
 *  INTNO�^�Ɗ����݂̋֎~/����
 */
typedef	UINT	INTNO;			/* �����ݔԍ� */

extern ER	dis_int(INTNO intno) throw();
extern ER	ena_int(INTNO intno) throw();
#endif


/*
 *�@�V�X�e���C���^�t�F�[�X���C��
 */

/*
 *  �����݃��b�N��Ԃ̐���
 */
#define	SIL_PRE_LOC	IPM _intmask_ = current_intmask()
#define	SIL_LOC_INT()	_disint_()
#define	SIL_UNL_INT()	set_intmask(_intmask_)

/*
 * �������ԑ҂�
 * �@�@���ӎ����F
 * �@�@�@�W���ł�dlytim��UINT�^����16�r�b�g�����Ȃ��̂ŁA
 * �@�@�@sil_dly_nse_long()�ł͈�����UW�^�ɕύX���Ă���B
 * �@�@�@sil_dly_nse()�͓�����sil_dly_nse_long()���Ăяo���B
 * �@�@�@
 * �@�@�@sil_dly_nse()�̃v���g�^�C�v�錾��jsp/include/sil.h�ɂ���B
 */
extern void sil_dly_nse_long(UW dlytim) throw();

/*
 *  �v���Z�b�T�̃G���f�B�A��
 */
#define	SIL_ENDIAN	SIL_ENDIAN_BIG		/* �r�b�O�G���f�B�A�� */


/*
 *  �G���f�B�A���̔��]
 */
#define	SIL_REV_ENDIAN_H(data) \
	((VH)((((UH)(data) & 0xff) << 8) | (((UH)(data) >> 8) & 0xff)))

#define	SIL_REV_ENDIAN_W(data) \
	((VW)((((UW)(data) & 0xff) << 24) | (((UW)(data) & 0xff00) << 8) \
		| (((UW)(data)>> 8) & 0xff00) | (((UW)(data) >> 24) & 0xff)))

/*
 *  ��������ԃA�N�Z�X�֐�
 *  
 *  �R���p�C���̌x����������邽�߁A�@��ˑ����ŃA�N�Z�X�֐���p�ӂ���B
 *  �������e��jsp/include/sil.h�Ƃ܂����������B
 *  ��`���鏇�Ԃ̓s����A��L�́u�G���f�B�A���̔��]�v���_�u���Ē�`���Ă���B
 */
#define OMIT_SIL_ACCESS

/*
 *  8�r�b�g�P�ʂ̓Ǐo���^������
 */
Inline VB
sil_reb_mem(VP mem)
{
	VB data = *((volatile VB *) mem);
	return(data);
}

Inline void
sil_wrb_mem(VP mem, VB data)
{
	*((volatile VB *) mem) = data;
}

/*
 *  16�r�b�g�P�ʂ̓Ǐo���^������
 */
Inline VH
sil_reh_mem(VP mem)
{
	VH data = *((volatile VH *) mem);
	return(data);
}

Inline void
sil_wrh_mem(VP mem, VH data)
{
	*((volatile VH *) mem) = data;
}

#define	sil_reh_bem(mem)	sil_reh_mem(mem)
#define	sil_wrh_bem(mem, data)	sil_wrh_mem(mem, data)

Inline VH
sil_reh_lem(VP mem)
{
	VH data = *((volatile VH *) mem);
	return(SIL_REV_ENDIAN_H(data));
}

Inline void
sil_wrh_lem(VP mem, VH data)
{
	*((volatile VH *) mem) = SIL_REV_ENDIAN_H(data);
}

/*
 *  32�r�b�g�P�ʂ̓Ǐo���^������
 */
Inline VW
sil_rew_mem(VP mem)
{
	VW data = *((volatile VW *) mem);
	return(data);
}

Inline void
sil_wrw_mem(VP mem, VW data)
{
	*((volatile VW *) mem) = data;
}

#define	sil_rew_bem(mem)	sil_rew_mem(mem)
#define	sil_wrw_bem(mem, data)	sil_wrw_mem(mem, data)

Inline VW
sil_rew_lem(VP mem)
{
	VW data= *((volatile VW *) mem);
	return(SIL_REV_ENDIAN_W(data));
}

Inline void
sil_wrw_lem(VP mem, VW data)
{
	*((volatile VW *) mem) = SIL_REV_ENDIAN_W(data);
}

/*
 *�@I/O�|�[�g�̃f�[�^�E�f�B���N�V�����E���W�X�^DDR�ւ̃A�N�Z�X
 */

/*  �|�[�g�ԍ��̒�`  */
typedef enum  {
	IO_PORT1,
	IO_PORT2,
	IO_PORT3,
	IO_PORT5,	/*  �|�[�g�S��DDR�͂Ȃ�  */
	IO_PORT6,
	IO_PORT7,
	IO_PORT8,
	IO_PORT9,
	IO_PORTA,
	IO_PORTB,
	IO_PORTC,
	IO_PORTD,
	IO_PORTE,
	IO_PORTF,
	IO_PORTG
} IO_PORT_ID;

extern UB sil_reb_ddr(IO_PORT_ID port) throw();
extern void sil_wrb_ddr(IO_PORT_ID port, UB data) throw();
extern void sil_anb_ddr(IO_PORT_ID port, UB data) throw();
extern void sil_orb_ddr(IO_PORT_ID port, UB data) throw();


/*============================================================================*/
/*  �f�o�b�O�p�R�[�h  */

#ifdef TEST_CPU_INSN
extern void test_cpu_insn(void);
#endif /* TEST_CPU_INSN */

#ifdef TEST_CPU_CONFIG
extern void test_cpu_config(void);
#endif /* TEST_CPU_CONFIG */

#ifdef TEST_H8S_SIL
extern void test_h8s_sil(void);
#endif /* TEST_H8S_SIL */

/*============================================================================*/



#endif /* _MACRO_ONLY */

#endif /* _CPU_DEFS_H_ */
