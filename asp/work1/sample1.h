/*
 *  �^�[�Q�b�g�ˑ��̒�`
 */
#include "target_test.h" 

/*
 *  �e�^�X�N�̗D��x�̒�`
 */

#define MAIN_PRIORITY	5		/* ���C���^�X�N�̗D��x */
								/* HIGH_PRIORITY��荂�����邱�� */

#define HIGH_PRIORITY	9		/* ����Ɏ��s�����^�X�N�̗D��x */
#define MID_PRIORITY	10
#define LOW_PRIORITY	11 

/*
 *  �^�[�Q�b�g�Ɉˑ�����\���̂���萔�̒�`
 */

#ifndef TASK_PORTID
#define	TASK_PORTID		1			/* �������͂���V���A���|�[�gID */
#endif /* TASK_PORTID */

#ifndef STACK_SIZE
#define	STACK_SIZE		4096		/* �^�X�N�̃X�^�b�N�T�C�Y */
#endif /* STACK_SIZE */

#ifndef LOOP_REF
#define LOOP_REF		ULONG_C(1000000)	/* ���x�v���p�̃��[�v�� */
#endif /* LOOP_REF */

/*
 *  �֐��̃v���g�^�C�v�錾
 */
#ifndef TOPPERS_MACRO_ONLY

extern void	task1(intptr_t exinf);

#endif /* TOPPERS_MACRO_ONLY */

