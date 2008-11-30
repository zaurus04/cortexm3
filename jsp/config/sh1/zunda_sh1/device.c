/*
 *  TOPPERS/JSP Rose-RT Link Programs
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
/*
 *  (��)�������쏊����ITRON����SH1CPU�{�[�h�p
 *  LED,SW ����֐�
 */
#include <s_services.h>
#include <sh1_sil.h>
#include "zunda_sh1.h"
#include "device.h"

/*
 *  LED�̏�����
 */
void
initial_led(void)
{
	set_led( LED1, OFF );
	set_led( LED2, OFF );
	set_led( LED3, OFF );
}

/*
 *  LED�̐ݒ���s��
 *  arg1: LED1 - 3
 *  arg2: ON|OFF
 */
void
set_led( int led, int req )
{
	if ( req != ON && req != OFF ) {
		return;
	}
	
	switch ( led ) {
	case LED1:
		if( req == OFF ) {
			sh1_orh_reg( PA_DR, LED_CTL1 );
		} else {
			sh1_anh_reg( PA_DR, ~LED_CTL1 );
		}
		break;
	case LED2:
		if( req == OFF ) {
			sh1_orh_reg( PB_DR, LED_CTL2 );
		} else {
			sh1_anh_reg( PB_DR, ~LED_CTL2 );
		}
		break;
	case LED3:
		if( req == OFF ) {
			sh1_orh_reg( PB_DR, LED_CTL3 );
		} else {
			sh1_anh_reg( PB_DR, ~LED_CTL3 );
		}
		break;
	default:
		break;
	}
}

/*
 *  LED�̏�Ԏ擾
 *  arg1: LED1 - 3
 */
int
get_led( int led )
{
	switch ( led ) {
	case LED1:
		if ( (sil_reh_mem( PA_DR ) & LED_CTL1) == 0 ) {
			return ON;
		}
		break;
	case LED2:
		if ( (sil_reh_mem( PB_DR ) & LED_CTL2) == 0 ) {
			return ON;
		}
		break;
	case LED3:
		if ( (sil_reh_mem( PB_DR ) & LED_CTL3) == 0 ) {
			return ON;
		}
		break;
	default:
		break;
	}
	return OFF;
}

/*
 *  �f�B�b�v�X�C�b�`�̏�Ԏ擾
 *  return:ON OFF
 *  arg1:DSW11 �` DSW14
 */
int
get_dsw( int sw )
{
	UH	key = 0;
	int	result = OFF;

	key = sil_reh_mem( SW_DR );
	switch ( sw ) {
	case DSW11:
		if ((key & DSW11) == 0 ) {
			result = ON;
		}
		break;
	case DSW12:
		if ((key & DSW12) == 0 ) {
			result = ON;
		}
		break;
	case DSW13:
		if ((key & DSW13) == 0 ) {
			result = ON;
		}
		break;
	case DSW14:
		if ((key & DSW14) == 0 ) {
			result = ON;
		}
		break;
	default:
		break;
	}
	return result;
}

/*
 *  ���[�^���[�X�C�b�`�̒l�擾
 *  return:�X�C�b�`�̒l
 */
int
get_rsw(void)
{
	return (sil_reh_mem( SW_DR ) & RSW_CTL);
}

