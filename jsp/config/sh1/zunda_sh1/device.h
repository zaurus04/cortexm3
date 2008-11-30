/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by CHUO ELECTRIC WORKS Co.,LTD. JAPAN
 *
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 */
 
#ifndef _DEVICE_H_
#define _DEVICE_H_

/*
 *  LED ID��`
 */
#define LED1		1		/* LED1��ID��` */
#define LED2		2		/* LED2��ID��` */
#define LED3		3		/* LED3��ID��` */

/*
 *  LED����r�b�g
 */
#define LED_CTL1	0x0100		/* LED1 ���� */
#define LED_CTL2	0x0040		/* LED2 ���� */
#define LED_CTL3	0x1000		/* LED3 ���� */

/*
 *  �X�C�b�`���[�h�A�h���X
 */
#define SW_DR		((VB *)0x6000200)

/*
 *  �f�B�b�v�X�C�b�`�擾�p�̃}�X�N�r�b�g
 */
#define DSW11		0x10
#define DSW12		0x20
#define DSW13		0x40
#define DSW14		0x80

/*
 *  ���[�^���[�X�C�b�`�擾�p�̃}�X�N�r�b�g
 */
#define RSW_CTL		0x0F

/*
 *  ON OFF ��`
 */
#define ON		1
#define OFF		0

/*
 *  �E�I�b�`�h�b�O�^�C�}�N���A
 */
Inline void
wdt_clear(void)
{
	sil_wrh_mem(PA_DR, (sil_reh_mem(PA_DR) ^ (1<<5)));
}

/*
 *  �f�o�C�X�̃v���g�^�C�v�錾
 */
void	initial_led(void );
void	set_led( int led, int req );
int	get_led( int led );
int	get_dsw( int sw );
int	get_rsw( void );

#endif /* _DEVICE_H_ */
