/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 * 
 *  Copyright (C) 2005-2007 by Y.D.K.Co.,LTD Technologies company
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
 *  @(#) $Id: sys_config.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *    �^�[�Q�b�g�V�X�e���ˑ����W���[��
 */

#include "jsp_kernel.h"
#include <ns9360.h>


/*
 * GPIO Setup 
 */
static void	cpuSetupGPIO(void);
/*
 * CS0 Setup
 */
static void	cpuSetupCS0(void);
/*
 * CS2 Setup
 */
static void	cpuSetupCS2(void);
/*
 * CS3 Setup
 */
static void	cpuSetupCS3(void);
/*
 * CS5 Setup
 */
static void	cpuSetupCS5(void);
/*
 * CS6 Setup
 */
static void	cpuSetupCS6(void);
/*
 * CS7 Setup
 */
static void	cpuSetupCS7(void);


/*
 * �����݃n���h���o�^�p�e�[�u��
 */
FP   int_table[MAX_INT_NUM];
UW   int_mask_table[MAX_INT_NUM];

/*
 * IRQ��INT ID�̑Ή��e�[�u���AIRQ�ɑΉ�����INT ID��ݒ肷��B
 * ���̃e�[�u���̃f�[�^����AIntConfigRegistar��ݒ肷��B
 * ���g�p��IRQ�ɂ�INT_ID_NONE���Z�b�g����
 */
const	UW	int_id_table[] = {
	INT_ID_NONE,			/* IRQ0 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ1 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ2 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ3 INT ID  : unuse							*/
	INT_ID_TIMER0,			/* IRQ4 INT ID  : TIMER 0 Interrupt				*/
	INT_ID_NONE,			/* IRQ5 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ6 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ7 INT ID  : unuse							*/
	INT_ID_BBUS_INT,		/* IRQ8 INT ID  : BBus Aggregate Interrupt		*/
	INT_ID_NONE,			/* IRQ9 INT ID  : unuse							*/
	INT_ID_NONE,			/* IRQ10 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ11 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ12 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ13 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ14 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ15 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ16 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ17 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ18 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ19 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ20 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ21 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ22 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ23 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ24 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ25 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ26 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ27 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ28 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ29 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ30 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ31 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ32 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ33 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ34 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ35 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ36 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ37 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ38 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ39 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ40 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ41 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ42 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ43 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ44 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ45 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ46 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ47 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ48 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ49 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ50 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ51 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ52 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ53 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ54 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ55 INT ID : unuse							*/
	INT_ID_SERC_TX,			/* IRQ56 INT ID : SER C Tx Interrupt			*/
	INT_ID_SERC_RX,			/* IRQ57 INT ID : SER C Rx Interrupt			*/
	INT_ID_SERA_TX,			/* IRQ58 INT ID : SER A Tx Interrupt			*/
	INT_ID_SERA_RX,			/* IRQ59 INT ID : SER A Rx Interrupt			*/
	INT_ID_NONE,			/* IRQ60 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ61 INT ID : unuse							*/
	INT_ID_NONE,			/* IRQ62 INT ID : unuse							*/
	INT_ID_NONE				/* IRQ63 INT ID : unuse							*/
};


/*--- GPIO �ݒ��� ---*/
/*
 **** Control Registers ****
 */
/* Control Registers #1 (GPIO[0]�`[31]) */
const	UW	BbusGpio_ContSts1 = (BBUS_GPIO_CONT_STS1_GPIO2 | BBUS_GPIO_CONT_STS1_GPIO16);

/* Control Registers #2 (GPIO[32]�`[63]) */
const	UW	BbusGpio_ContSts2 = (BBUS_GPIO_CONT_STS2_GPIO36 | BBUS_GPIO_CONT_STS2_GPIO37 
                                            | BBUS_GPIO_CONT_STS2_GPIO38 | BBUS_GPIO_CONT_STS2_GPIO39);
	
/* Control Registers #3 (GPIO[64]�`[72]) */
const	UW	BbusGpio_ContSts3 = 0;

/*
 **** Configration Registers ****
 */

/* Configration Registers #1 (GPIO[0]�`[7]) */
const	UW	BbusGpio_Config1 = (BBUS_GPIO_CONFIG1_GPIO0 | BBUS_GPIO_CONFIG1_GPIO1
                              | BBUS_GPIO_CONFIG1_GPIO2 | BBUS_GPIO_CONFIG1_GPIO3
                              | BBUS_GPIO_CONFIG1_GPIO4 | BBUS_GPIO_CONFIG1_GPIO5
                              | BBUS_GPIO_CONFIG1_GPIO6 | BBUS_GPIO_CONFIG1_GPIO7);

/* Configration Registers #2 (GPIO[8]�`[15]) */
const	UW	BbusGpio_Config2 = (BBUS_GPIO_CONFIG2_GPIO8 | BBUS_GPIO_CONFIG2_GPIO9
                              | BBUS_GPIO_CONFIG2_GPIO10 | BBUS_GPIO_CONFIG2_GPIO11
                              | BBUS_GPIO_CONFIG2_GPIO12 | BBUS_GPIO_CONFIG2_GPIO13
                              | BBUS_GPIO_CONFIG2_GPIO14 | BBUS_GPIO_CONFIG2_GPIO15);

/* Configration Registers #3 (GPIO[16]�`[23]) */
const	UW	BbusGpio_Config3 = (BBUS_GPIO_CONFIG3_GPIO16 | BBUS_GPIO_CONFIG3_GPIO17
                              | BBUS_GPIO_CONFIG3_GPIO18 | BBUS_GPIO_CONFIG3_GPIO19
                              | BBUS_GPIO_CONFIG3_GPIO20 | BBUS_GPIO_CONFIG3_GPIO21
                              | BBUS_GPIO_CONFIG3_GPIO22 | BBUS_GPIO_CONFIG3_GPIO23);

/* Configration Registers #4 (GPIO[24]�`[31]) */
const	UW	BbusGpio_Config4 = (BBUS_GPIO_CONFIG4_GPIO24 | BBUS_GPIO_CONFIG4_GPIO25
                              | BBUS_GPIO_CONFIG4_GPIO26 | BBUS_GPIO_CONFIG4_GPIO27
                              | BBUS_GPIO_CONFIG4_GPIO28 | BBUS_GPIO_CONFIG4_GPIO29
                              | BBUS_GPIO_CONFIG4_GPIO30 | BBUS_GPIO_CONFIG4_GPIO31);

/* Configration Registers #5 (GPIO[32]�`[39]) */
const	UW	BbusGpio_Config5 = (BBUS_GPIO_CONFIG5_GPIO32 | BBUS_GPIO_CONFIG5_GPIO33
                              | BBUS_GPIO_CONFIG5_GPIO34 | BBUS_GPIO_CONFIG5_GPIO35
                              | BBUS_GPIO_CONFIG5_GPIO36 | BBUS_GPIO_CONFIG5_GPIO37
                              | BBUS_GPIO_CONFIG5_GPIO38 | BBUS_GPIO_CONFIG5_GPIO39);

/* Configration Registers #6 (GPIO[40]�`[47]) */
const	UW	BbusGpio_Config6 = (BBUS_GPIO_CONFIG6_GPIO40 | BBUS_GPIO_CONFIG6_GPIO41
                              | BBUS_GPIO_CONFIG6_GPIO42 | BBUS_GPIO_CONFIG6_GPIO43
                              | BBUS_GPIO_CONFIG6_GPIO44 | BBUS_GPIO_CONFIG6_GPIO45
                              | BBUS_GPIO_CONFIG6_GPIO46 | BBUS_GPIO_CONFIG6_GPIO47);

/* Configration Registers #7 (GPIO[48]�`[55]) */
const	UW	BbusGpio_Config7 = (BBUS_GPIO_CONFIG7_GPIO48 | BBUS_GPIO_CONFIG7_GPIO49
                              | BBUS_GPIO_CONFIG7_GPIO50 | BBUS_GPIO_CONFIG7_GPIO51
                              | BBUS_GPIO_CONFIG7_GPIO52 | BBUS_GPIO_CONFIG7_GPIO53
                              | BBUS_GPIO_CONFIG7_GPIO54 | BBUS_GPIO_CONFIG7_GPIO55);

/* Configration Registers #8 (GPIO[56]�`[63]) */
const	UW	BbusGpio_Config8 = (BBUS_GPIO_CONFIG8_GPIO56 | BBUS_GPIO_CONFIG8_GPIO57
                              | BBUS_GPIO_CONFIG8_GPIO58 | BBUS_GPIO_CONFIG8_GPIO59
                              | BBUS_GPIO_CONFIG8_GPIO60 | BBUS_GPIO_CONFIG8_GPIO61
                              | BBUS_GPIO_CONFIG8_GPIO62 | BBUS_GPIO_CONFIG8_GPIO63);

/* Configration Registers #9 (GPIO[64]�`[71]) */
const	UW	BbusGpio_Config9 = (BBUS_GPIO_CONFIG9_GPIO64 | BBUS_GPIO_CONFIG9_GPIO65
                              | BBUS_GPIO_CONFIG9_GPIO66 | BBUS_GPIO_CONFIG9_GPIO67
                              | BBUS_GPIO_CONFIG9_GPIO68 | BBUS_GPIO_CONFIG9_GPIO69
                              | BBUS_GPIO_CONFIG9_GPIO70 | BBUS_GPIO_CONFIG9_GPIO71);

/* Configration Registers #10 (GPIO[72]) */
const	UW	BbusGpio_Config10 = (BBUS_GPIO_CONFIG10_GPIO72);


/*
 *  �^�[�Q�b�g�V�X�e���ˑ��̏�����
 */
void
sys_initialize()
{
    /*
     *  ARM�̃x�N�^�e�[�u���֊����݃n���h����o�^
     */
    arm_install_handler(IRQ_Number,IRQ_Handler);
  
    /*
     *  sys_putc ���\�ɂȂ�悤��UART��������
     */
    uart_init(LOGTASK_PORTID);
    /*
     * BBus�̊����݋���
     */
     sil_wrw_mem((VP)BBBIE_REG, sil_rew_mem((VP)BBBIE_REG) | BBBI_GLBL);
}


/*
 *  �^�[�Q�b�g�V�X�e���̏I��
 */
void
sys_exit(void)
{
    syslog(LOG_EMERG, "End Kernel.....!");
    while(1);
}


/*
 *  �^�[�Q�b�g�V�X�e���̕����o��
 */
void
sys_putc(char c)
{
    if (c == '\n') {
        uart_putc('\r');
    }
  uart_putc(c);  
}


/*
 *  �����݃n���h���̐ݒ�
 *
 *  �����ݔԍ� inhno �̊����݃n���h���̋N���Ԓn�� inthdr �ɐݒ肷��D
 */
void
define_inh(INHNO inhno, FP inthdr)
{
	VW	reg;
	
    assert(inhno < MAX_INT_NUM);
    int_table[inhno] = inthdr;
    
    if(INT_ID_BBUS_F > inhno)
    {
		/*
		 * BBusBridge�o�R�ł͂Ȃ������݂̓o�^
		 */
	    sil_wrw_mem((VP)(IVARV_REG+inhno*4),(VW)inthdr);     /* Interruput Vector Reg �̐ݒ� */
	    
	    /* IntConfigReg�̐ݒ� */
	    reg = sil_rew_mem((VP)((INT_CONFIG_REG+inhno)&0xfffffffc));
	    reg &= ~(0xff000000 >> (inhno%4)*8);
	    reg |= ((int_id_table[inhno] | INT_CFG_BIT_IT)<<24) >> ((inhno%4)*8);
	    sil_wrw_mem((VP)((INT_CONFIG_REG+inhno)&0xfffffffc), reg);
	}
}


/*
 * �����݃n���h���N�����Ɋ����݃R���g���[���[�ɃZ�b�g����}�X�N�l��ݒ�D
 */
void
define_inh_mask(INHNO inhno, UW mask)
{
    assert(inhno < MAX_INT_NUM);
    int_mask_table[inhno] = mask;
}


/*
 *  ����`�̊����݂��������ꍇ�̏���
 */
void
undef_interrupt(){
    syslog(LOG_EMERG, "Unregistered Interrupt occurs.");
    while(1);
}

/*
 *  BBus�����݃T�[�r�X���[�`��
 */
void
BBus_isr()
{
	UW	i;
	UW	int_sts;
	
	int_sts = sil_rew_mem((VP)(BBBIS_REG)) & BBBIS_MASK;
	for( i = INT_ID_BBUS_F ; i < MAX_INT_NUM ; ++i )
	{
		if(int_sts & 0x80000000)
		{
			if(0 == int_table[i])
			{
				 undef_interrupt();
			}
			else
			{
				int_table[i]();
			}
		}
		int_sts <<= 1;
	}
}

/*
 *  CS�AGPIO�ݒ�
 */
void cpu_CsGpioInit(void)
{
    BOOL    debugger, software_restart;
	software_restart = 0;
        cpuSetupGPIO();
		*(UW*)(BBUS_GPIO_CONT1_REG) |= 0x10;

	
    /* ���X�^�[�g�t���O�̎擾���Z�b�g */
    software_restart = ((~AHB_ABT_CFG_REG_restart) & sil_rew_mem((VP)AHB_ABT_CFG_REG));
    														/* Restart Flag get		*/
	
	sil_wrw_mem((VP)AHB_ABT_CFG_REG , (AHB_ABT_CFG_REG_restart | sil_rew_mem((VP)AHB_ABT_CFG_REG)));
															/* Restart Flag set	*/

	
    /* �f�o�b�O�t���O�̎擾 */
    debugger = ((~AHB_ABT_CFG_REG_debug) & sil_rew_mem((VP)AHB_ABT_CFG_REG));	/* Debug Flag get */
 
    if (!software_restart)
    {
        /* Setup the GPIO ports. */
        cpuSetupGPIO();

		*(UW*)(BBUS_GPIO_CONT1_REG) |= 0x10;

		/* Enable Instruction Cache */
		cpuEnableICache();

        /* Setup the Static chip selects */
        cpuSetupCS0();							/* CS0 setup 			*/
        cpuSetupCS2();							/* CS2 setup 			*/
        cpuSetupCS3();							/* CS3 setup 			*/

        /* Setup the Dynamic chip selects */
        cpuSetupCS5();							/* CS5 setup 			*/
        cpuSetupCS6();							/* CS6 setup 			*/
        cpuSetupCS7();							/* CS7 setup 			*/

    }
    else
    {
        /* Setup the GPIO ports. */
        cpuSetupGPIO();
        ;
        cpuEnableICache();
    }
    return;
}


/*
 * CS0 Setup
 */
static void	cpuSetupCS0(void)
{
	/*
	 * �^�[�Q�b�g�ɍ��킹�ď������������L�q����
	 * Boot���[�_�[�ɂĐݒ�ς݂̏ꍇ�A�����ł̐ݒ�͕s�v
	 */
}
/*
 * CS2 Setup
 */
static void	cpuSetupCS2(void)
{
	/*
	 * �^�[�Q�b�g�ɍ��킹�ď������������L�q����
	 * Boot���[�_�[�ɂĐݒ�ς݂̏ꍇ�A�����ł̐ݒ�͕s�v
	 */
}
/*
 * CS3 Setup
 */
static void	cpuSetupCS3(void)
{
	/*
	 * �^�[�Q�b�g�ɍ��킹�ď������������L�q����
	 * Boot���[�_�[�ɂĐݒ�ς݂̏ꍇ�A�����ł̐ݒ�͕s�v
	 */
}
/*
 * CS5 Setup
 */
static void	cpuSetupCS5(void)
{
	/*
	 * �^�[�Q�b�g�ɍ��킹�ď������������L�q����
	 * Boot���[�_�[�ɂĐݒ�ς݂̏ꍇ�A�����ł̐ݒ�͕s�v
	 */
}
/*
 * CS6 Setup
 */
static void	cpuSetupCS6(void)
{
	/*
	 * �^�[�Q�b�g�ɍ��킹�ď������������L�q����
	 * Boot���[�_�[�ɂĐݒ�ς݂̏ꍇ�A�����ł̐ݒ�͕s�v
	 */
}
/*
 * CS7 Setup
 */
static void	cpuSetupCS7(void)
{
	/*
	 * �^�[�Q�b�g�ɍ��킹�ď������������L�q����
	 * Boot���[�_�[�ɂĐݒ�ς݂̏ꍇ�A�����ł̐ݒ�͕s�v
	 */
}

/*
 * GPIO Setup 
 */
static void	cpuSetupGPIO(void)
{
	UW config;

	/*
	 **** Control Registers ****
	 */
	/* �Y��pin��GPIO�o�͂ɐݒ肵���ꍇ�Ƀf�t�H���g�o�͂��w�肵�����ꍇ�Ɉȉ����L�q���� */
	
	/* Control Registers #1 (GPIO[0]�`[31]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONT1_REG , BbusGpio_ContSts1);

	/* Control Registers #2 (GPIO[32]�`[63]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONT2_REG , BbusGpio_ContSts2);
	
	/* Control Registers #3 (GPIO[64]�`[72]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONT3_REG , BbusGpio_ContSts3);

	/*
	 **** Configration Registers ****
	 */
	/* Configration Registers #1 (GPIO[0]�`[7]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG1_REG , BbusGpio_Config1);

	/* Configration Registers #2 (GPIO[8]�`[15]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG2_REG , BbusGpio_Config2);

	/* Configration Registers #3 (GPIO[16]�`[23]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG3_REG , BbusGpio_Config3);

	/* Configration Registers #4 (GPIO[24]�`[31]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG4_REG , BbusGpio_Config4);

	/* Configration Registers #5 (GPIO[32]�`[39]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG5_REG , BbusGpio_Config5);

	/* Configration Registers #6 (GPIO[40]�`[47]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG6_REG , BbusGpio_Config6);

	/* Configration Registers #7 (GPIO[48]�`[55]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG7_REG , BbusGpio_Config7);

	/* Configration Registers #8 (GPIO[56]�`[63]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG8_REG , BbusGpio_Config8);

	/* Configration Registers #9 (GPIO[64]�`[71]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG9_REG , BbusGpio_Config9);

	/* Configration Registers #10 (GPIO[72]) */
	sil_wrw_mem((VP) BBUS_GPIO_CONFIG10_REG , BbusGpio_Config10);
}


