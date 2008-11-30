/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Advanced Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2005-2007 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ���(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F
 *  �A�i�{�\�t�g�E�F�A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E��
 *  �ρE�Ĕz�z�i�ȉ��C���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
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
 *      �܂��C�{�\�t�g�E�F�A�̃��[�U�܂��̓G���h���[�U����̂����Ȃ闝
 *      �R�Ɋ�Â�����������C��L���쌠�҂����TOPPERS�v���W�F�N�g��
 *      �Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC����̎g�p�ړI
 *  �ɑ΂���K�������܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F
 *  �A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C��
 *  �̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 * �^�[�Q�b�g�ˑ����W���[���iCQ-STARM�p�j
 */
#include "kernel_impl.h"
#include <sil.h>
#include "cq_starm.h"
#include "target_serial.h"
#include "target_syssvc.h"


/*
 * GPIO���W�X�^����֐�
 */
Inline void set_cr_mode(uint32_t reg, uint_t p, int_t v)
{
	if (p < 8) {
		sil_andw((void*)GPIO_CRL(reg), ~CR_MODE_MASK(p));
		sil_orw((void*)GPIO_CRL(reg), CR_MODE(p, v));
	} else if (8 <= p && p < 16) {
		sil_andw((void*)GPIO_CRH(reg), ~CR_MODE_MASK(p - 8));
		sil_orw((void*)GPIO_CRH(reg), CR_MODE(p - 8, v));
	}
}

Inline void set_cr_cnf(uint32_t reg, uint_t p, int_t v)
{
	if (p < 8) {
		sil_andw((void*)GPIO_CRL(reg), ~CR_CNF_MASK(p));
		sil_orw((void*)GPIO_CRL(reg), CR_CNF(p, v));
	} else if (8 <= p && p < 16) {
		sil_andw((void*)GPIO_CRH(reg), ~CR_CNF_MASK(p - 8));
		sil_orw((void*)GPIO_CRH(reg), CR_CNF(p - 8, v));
	}
}

Inline void set_port_pull(uint32_t reg, uint_t p, bool_t up)
{
	if (up) {
		sil_wrw_mem((void*)GPIO_BSRR(reg), 0x01 << p);
	} else {
		sil_wrw_mem((void*)GPIO_BRR(reg), 0x01 << p);
	}
}

/*
 * �^�[�Q�b�g�ˑ����@����������
 */
void target_initialize(void)
{
	/*
	 *  �v���Z�b�T�N���b�N(RCC)�̏�����
	 */
	/* HSE�̗L���� */
	sil_orw((void*)RCC_CR, CR_HSE_ON);

	/* HSE�L���҂� */
	while ((sil_rew_mem((void*)RCC_CR) & CR_HSE_RDY) == 0) ;

	/* FLASH ROM��2wait�҂� */
	sil_andw((void*)FLASH_ACR, ~ACR_LATENCY_MASK);
	sil_orw((void*)FLASH_ACR, ACR_LATENCY_TWO);

	/* HCLK = SYSCLK, PCLK2 = HCLK, PCLK1 = HCLK/2  */
	sil_orw((void*)RCC_CFGR, 0x00 | (0x00 << 11) | (0x04 << 8));

	/* PLLCLK = 8MHz x 9 = 72MHz, HSE as PLL clock */
	sil_orw((void*)RCC_CFGR, 0x07 << 18);
	sil_orw((void*)RCC_CFGR, CFGR_PLL_SRC);

	/* PLL�̗L���� */
	sil_orw((void*)RCC_CR, CR_PLL_ON);

	/* PLL�L���҂� */
	while ((sil_rew_mem((void*)RCC_CR) & CR_PLL_RDY) == 0) ;

	/* PLL���V�X�e���N���b�N�ɑI�� */
	sil_orw((void*)RCC_CFGR, CFGR_SW_PLL);

	/* PLL�̃V�X�e���N���b�N�I��҂� */
	while ((sil_rew_mem((void*)RCC_CFGR) & CFGR_SWS_MASK) != (CFGR_SW_PLL << 2)) ;


	/*
	 *  �v���Z�b�T�ˑ����̏�����
	 */
	prc_initialize();

	/*
	 *  �y���t�F�����̗L����
	 */
	sil_orw((void*)RCC_APB2ENR, APB2ENR_USART1_EN | APB2ENR_IOPA_EN |
			APB2ENR_IOPC_EN | APB2ENR_AFIO_EN);
#if (TNUM_PORT >= 2)
	sil_orw((void*)RCC_APB2ENR, APB2ENR_IOPD_EN);
	sil_orw((void*)RCC_APB1ENR, APB1ENR_USART2_EN);
#endif
	/*
	 *  I/O�|�[�g�̏�����
	 */
	/* USART1(RX)  �v���A�b�v */
	set_cr_mode(GPIOA_BASE, 10, MODE_INPUT);
	set_cr_cnf(GPIOA_BASE, 10, CNF_IN_FLOATING);

	/* USART1(TX) */
	set_cr_mode(GPIOA_BASE, 9, MODE_OUTPUT_50MHZ);
	set_cr_cnf(GPIOA_BASE, 9, CNF_OUT_AF_PP);

#if (TNUM_PORT >= 2)
	/* USART2(RX)  �v���A�b�v */
	set_cr_mode(GPIOD_BASE, 6, MODE_INPUT);
	set_cr_cnf(GPIOD_BASE, 6, CNF_IN_FLOATING);

	/* USART2(TX) */
	set_cr_mode(GPIOD_BASE, 5, MODE_OUTPUT_50MHZ);
	set_cr_cnf(GPIOD_BASE, 5, CNF_OUT_AF_PP);

	/* USART2�|�[�g�̃��}�b�v�iPD5,6�j */
	sil_orw((void*)AFIO_MAPR, MAPR_USART2_REMAP);
#endif
	/* LED�|�[�g */
	set_cr_mode(GPIOC_BASE, 6, MODE_OUTPUT_50MHZ);
	set_cr_cnf(GPIOC_BASE, 6, CNF_OUT_GP_PP);

	/*
	 *  �o�[�i�[�o�͗p�̃V���A��������
	 */
	target_usart_init(SIO_PORTID);
}

/*
 * �^�[�Q�b�g�ˑ����@�I������
 */
void target_exit(void)
{
	/* �v���Z�b�T�ˑ����̏I������ */
	prc_terminate();
}

/*
 * �V�X�e�����O�̒჌�x���o�͂̂��߂̕����o��
 */
void target_fput_log(char_t c)
{
	if (c == '\n') {
		sio_pol_snd_chr('\r', SIO_PORTID);
	}
	sio_pol_snd_chr(c, SIO_PORTID);
}
