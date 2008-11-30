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
 *  @(#) $Id: mpc860_smc.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *   MPC860�����V���A���E�}�l�[�W�����g�R���g���[��SMC1�p �ȈՃh���C�o
 *�@�@�@�@
 *�@�@�@�@SMC1�݂̂��T�|�[�g���Ă���
 *
 *�@�@�@�@smc.{c,h}��hw_serial.h�̕����̊
 *�@�@�@�@�@�@�Esmc.{c,h}�F�V���A���f�o�C�X�Ɉˑ����镔���̂݋L�q
 *�@�@�@�@�@�@�Ehw_serial.h�F�����݃R���g���[���ˑ�
 *�@�@�@�@�@�@
 *�@�@�@�@�@�@�E�N���b�N���g���ˑ��ɂ���
 *�@�@�@�@�@�@�@�@�E�f�o�C�X�ˑ��̃p�����[�^��mpc860_smc.c���ŗp�ӂ���B
 *�@�@�@�@�@�@�@�@�E�匳�̃N���b�N���g���̓R���p�C���I�v�V�����Ƃ��ė^����
 */

#include <s_services.h>
#include <mpc860_smc.h>

/*
 *  �R���g���[�����W�X�^�̒�`
 */

/*  SMC���[�h���W�X�^  */
#define SMCMR1          (VH *)(IMMR_BASE + 0xa82)
#define SMCMR_SM_UART   BIT10_16    /*  SMC���[�h�FUART  */
#define SMCMR_TEN       BIT14_16    /*  SMC���M�C�l�[�u��  */
#define SMCMR_REN       BIT15_16    /*  SMC��M�C�l�[�u��  */


/*
 *  30.2.3 �p�����[�^RAM
 */
/*  �o�b�t�@�E�f�B�X�N���v�^BD�̐擪�A�h���X  */
#define BD1_BASE    (IMMR_BASE + 0x3e80)
#define RBASE1      (VH *)BD1_BASE          /*  RxBD�x�[�X�A�h���X  */
#define TBASE1      (VH *)(BD1_BASE+2)      /*  TxBD�x�[�X�A�h���X  */
#define RFCR1       (VB *)(BD1_BASE+4)      /*  ��M�t�@���N�V�����R�[�h  */
					    /*  �o�C�g���i��M�j  */
#if SIL_ENDIAN == SIL_ENDIAN_BIG	    /* �r�b�O�G���f�B�A�� */
#define RFCR_BO     0x10
#else /* SIL_ENDIAN == SIL_ENDIAN_BIG */    /* ���g���G���f�B�A�� */
#define RFCR_BO	    0x08
#endif /* SIL_ENDIAN == SIL_ENDIAN_BIG */

#define TFCR1       (VB *)(BD1_BASE+5)      /*  ���M�t�@���N�V�����R�[�h  */
					    /*  �o�C�g���i���M�j  */
#if SIL_ENDIAN == SIL_ENDIAN_BIG	    /* �r�b�O�G���f�B�A�� */
#define TFCR_BO     0x10
#else /* SIL_ENDIAN == SIL_ENDIAN_BIG */    /* ���g���G���f�B�A�� */
#define TFCR_BO	    0x08
#endif /* SIL_ENDIAN == SIL_ENDIAN_BIG */

/*
 *  30.3.2 UART�̏ꍇ�̃p�����[�^RAM
 */
#define MRBLR1      (VH *)(BD1_BASE+6)      /*  �ő��M�o�b�t�@��  */
#define RBPTR1      (VH *)(BD1_BASE+0x10)   /*  RxBD�|�C���^  */
#define TBPTR1      (VH *)(BD1_BASE+0x20)   /*  TxBD�|�C���^  */
                                            /*  �ő�A�C�h���L�����N�^��  */
#define MAX_IDL1    (VH *)(BD1_BASE+0x28)
#define IDLC1       (VH *)(BD1_BASE+0x2a)   /*  �ꎞ�A�C�h���E�J�E���^  */
#define BRKLN1      (VH *)(BD1_BASE+0x2c)   /*  �ŏI��M�u���[�N��  */
                                            /*  ��M�u���[�N�����J�E���^  */
#define BRKEC1      (VH *)(BD1_BASE+0x2e)
                                    /*  �u���[�N�J�E���g���W�X�^�i���M�j  */
#define BRKCR1      (VH *)(BD1_BASE+0x30)
#define R_MASK1     (VH *)(BD1_BASE+0x32)   /*  �ꎞ�r�b�g�E�}�X�N  */


/*
 *  �f���A���|�[�g�E��������Ɋm�ۂ���̈�
 */

/*
 *  �o�b�t�@�E�f�B�X�N���v�^BD�̃x�[�X�A�h���X
 */
#define RxBD_BASE_ADDRESS   0x0     /*  RxBD�x�[�X�A�h���X  */
#define TxBD_BASE_ADDRESS   0x8     /*  TxBD�x�[�X�A�h���X  */

/*  30.3.10 ��M�p�o�b�t�@�f�B�X�N���v�^RxBD  */
#define RxBD        (DUAL_PORT_RAM + RxBD_BASE_ADDRESS)
#define RxBD_STATUS (VH *)RxBD     	/*  �X�e�[�^�X�Ɛ���  */
#define RxBD_LENGTH (VH *)(RxBD+2) 	/*  �f�[�^��  */
#define RxBD_BUFFP  (VW *)(RxBD+4) 	/*  ��M�o�b�t�@�|�C���^  */

/*  30.3.11 ���M�p�o�b�t�@�f�B�X�N���v�^TxBD  */
#define TxBD        (DUAL_PORT_RAM + TxBD_BASE_ADDRESS)
#define TxBD_STATUS (VH *)TxBD     	/*  �X�e�[�^�X�Ɛ���  */
#define TxBD_LENGTH (VH *)(TxBD+2) 	/*  �f�[�^��  */
#define TxBD_BUFFP  (VW *)(TxBD+4) 	/*  ���M�o�b�t�@�|�C���^  */

/*  ��M�p�o�b�t�@�f�B�X�N���v�^RxBD  */
/*  �@�u�X�e�[�^�X�Ɛ���v�t�B�[���h�̒萔  */
#define RxBD_STATUS_E       BIT0_16     /*  ��  */
#define RxBD_STATUS_W       BIT2_16     /*  ���b�v  */
#define RxBD_STATUS_I       BIT3_16     /*  ������  */
#define RxBD_STATUS_CM      BIT6_16     /*  �p�����[�h  */
#define RxBD_STATUS_ID      BIT7_16     /*  �A�C�h����M  */
#define RxBD_STATUS_BR      BIT10_16    /*  �u���[�N��M  */
#define RxBD_STATUS_FR      BIT11_16    /*  �t���[�~���O�E�G���[  */
#define RxBD_STATUS_PR      BIT12_16    /*  �p���e�B�E�G���[  */
#define RxBD_STATUS_OV      BIT14_16    /*  �I�[�o�[����  */

/* ���M�p�o�b�t�@�f�B�X�N���v�^TxBD  */
/*  �@�u�X�e�[�^�X�Ɛ���v�t�B�[���h�̒萔  */
#define TxBD_STATUS_R       BIT0_16     /*  ���f�B  */
#define TxBD_STATUS_W       BIT2_16     /*  ���b�v  */
#define TxBD_STATUS_I       BIT3_16     /*  ������  */
#define TxBD_STATUS_CM      BIT6_16     /*  �p�����[�h  */
#define TxBD_STATUS_P       BIT7_16     /*  �v���A���u��  */

/*  30.3.12 SMC UART�C�x���g���W�X�^  */
#define SMCE1           (VB *)(IMMR_BASE + 0xa86)
#define SMCE_BRKE       BIT1_8      /*  �u���[�N�ŏI  */
#define SMCE_BRK        BIT3_8      /*  �u���[�N�L�����N�^��M  */
#define SMCE_BSY        BIT5_8      /*  �r�W�[����  */
#define SMCE_TX         BIT6_8      /*  ���M�o�b�t�@  */
#define SMCE_RX         BIT7_8      /*  ��M�o�b�t�@  */

/*  SMC UART�}�X�N���W�X�^  */
#define SMCM1           (VB *)(IMMR_BASE + 0xa8a)
#define SMCM_BRKE       BIT1_8      /*  �u���[�N�ŏI  */
#define SMCM_BRK        BIT3_8      /*  �u���[�N�L�����N�^��M  */
#define SMCM_BSY        BIT5_8      /*  �r�W�[����  */
#define SMCM_TX         BIT6_8      /*  ���M�o�b�t�@  */
#define SMCM_RX         BIT7_8      /*  ��M�o�b�t�@  */

#define PIC_BUFFER_SIZE     1      		/*  �o�b�t�@�T�C�Y  */

volatile static UB Rx_buffer[PIC_BUFFER_SIZE];	/*  ��M�o�b�t�@  */
volatile static UB Tx_buffer[PIC_BUFFER_SIZE];	/*  ���M�o�b�t�@  */


/*
 *  �{�[���[�g�ݒ�p�萔
 *  
 *  �@�񓯊��̏ꍇ�́~16�N���b�N��p����̂�16�Ŋ����Ă���
 *  �i���[�U�[�̐ݒ��16�������Ă���킯�ł͂Ȃ��j
 *  
 */
#define MHZ		1000000

#define BRGC1_CD_VAL		\
	(((SYSTEM_CLOCK * MHZ * 10 + 10) / (16 * BAUD_RATE * 10)) - 1) 

/*  BRGC1���W�X�^��CD�t�B�[���h��20�r�b�g�ɐ�������Ă���  */
#if (BRGC1_CD_VAL & ~0xfffff) != 0
�@�����ŃR���p�C���G���[
#endif


/*
 *  ������ƃr�b�g���[�g�̐ݒ�
 *
 */


/*
 *  �{�[���[�g�ݒ��A�N���b�N�����肷��܂ł̑҂�����
 *  �@�i�ŏ���1�r�b�g���j�@
 *  BPS=9600bps�̏ꍇ
 *  �@t = 1 / BPS = 104,167 = 105,000[nsec]
 */
#define SMC_1BIT_TIME 	105000


/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̒�`
 *  �@2ch�T�|�[�g�Ɋg������ꍇ�͏����l�p�̃f�[�^���܂߂�
 */
struct sio_port_control_block {
	VP_INT		exinf;		/* �g����� */
	BOOL		openflag;	/* �I�[�v���ς݃t���O */
};

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 *  �@�@ID = 1 ��SMC1�ɑΉ������Ă���D
 */
static SIOPCB	siopcb_table[TNUM_SIOP];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)	((UINT)((siopid) - 1))
#define get_siopcb(siopid)	(&(siopcb_table[INDEX_SIOP(siopid)]))


#define	CODE_LF		0x0a		/*  ���s�R�[�h  */

/*  �L�����N�^���M��̑҂�����  */
#ifdef DOWNLOAD_TO_RAM      /*  �f�o�b�O�p  */

#define	DELAY_CH	      0		/*  �ʏ�̃L�����N�^  */
#define	DELAY_LF	5000000		/*  ���s�R�[�h  */

#else /* DOWNLOAD_TO_RAM */ /*  ROM��  */

#define	DELAY_CH	4000000		/*  �ʏ�̃L�����N�^  */
#define	DELAY_LF	1000000		/*  ���s�R�[�h  */

#endif /* DOWNLOAD_TO_RAM */



/*
 *  ��������M�ł��邩�H
 */
Inline BOOL
smc_getready(SIOPCB *siopcb)
{
	VH status;
	
	status = mpc860_reh_mem(RxBD_STATUS);
	return(!(status & RxBD_STATUS_E));
}

/*
 *  �����𑗐M�ł��邩�H
 */
Inline BOOL
smc_putready(SIOPCB *siopcb)
{
	VH status;

	status = mpc860_reh_mem(TxBD_STATUS);
	return(!(status & TxBD_STATUS_R));
}

/*
 *  ��M���������̎�o��
 */
Inline char
smc_getchar(SIOPCB *siopcb)
{
	char c;
	SIL_PRE_LOC;
	
	SIL_LOC_INT();		/*  �����݋֎~  */
    	c = Rx_buffer[0];
    	
    	/*  ���ӁF��M�o�b�t�@�T�C�Y���P�̏ꍇ�̂ݗL��  */
    	mpc860_orh_mem(RxBD_STATUS, RxBD_STATUS_E);
    	SIL_UNL_INT();		/*  �����݋���  */
    	return(c);
}

/*
 *  ���M���镶���̏�����
 */
Inline void
smc_putchar(SIOPCB *siopcb, char c)
{
	SIL_PRE_LOC;

	SIL_LOC_INT();		/*  �����݋֎~  */
    	Tx_buffer[0] = c;
    	
    	/*  ���ӁF���M�o�b�t�@�T�C�Y���P�̏ꍇ�̂ݗL��  */
    	mpc860_orh_mem(TxBD_STATUS, TxBD_STATUS_R);
    	
    	SIL_UNL_INT();		/*  �����݋���  */

	/*
	 *  ����������h�����߁A�҂����Ԃ�����
	 */
	sil_dly_nse(DELAY_CH);

    	/*  ���s�R�[�h�̏ꍇ  */
    	if (c == CODE_LF) {
		sil_dly_nse(DELAY_LF);
	}
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
smc_initialize()
{
	SIOPCB	*siopcb;
	UINT	i;

	/*
	 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
	 */
	for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
		siopcb->openflag = FALSE;
	}
}


/*
 *  �I�[�v�����Ă���|�[�g�����邩�H
 */
BOOL
smc_openflag(void)
{
	return(siopcb_table[0].openflag);
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
smc_opn_por(ID siopid, VP_INT exinf)
{
	SIOPCB *siopcb;

	siopcb = get_siopcb(siopid);
	     					/*  ����M��~  */
	mpc860_andh_mem(SMCMR1, ~(SMCMR_TEN | SMCMR_REN));

	/*
	 *  �s���E�A�T�C��
	 *  �@�@�|�[�gB�̐ݒ�
	 *�@�@�@�@�@BP25�s���FSMTXD1
	 *�@�@�@�@�@BP24�s���FSMRXD1
	 */
         				/*  ��p�y���t�F�����@�\�I��  */
     	mpc860_orw_mem(PBPAR, (PBPAR_DD24 | PBPAR_DD25));
        				/*  �y���t�F�����@�\0�I��  */
     	mpc860_andw_mem(PBDIR, ~(PBDIR_DR24 | PBDIR_DR25));
        				/*  �A�N�e�B�u�Ƀh���C�u  */
     	mpc860_andw_mem(PBODR, ~(PBODR_OD24 | PBODR_OD25));

    	/*
    	 *  VCOUT����BRGCLK�ւ̕����W���ݒ�
    	 *      SCCR.DFBRG=00�F������P
    	 */
    	unlock_sccr();          		/*  SCCR�A�����b�N  */
    	mpc860_andw_mem(SCCR, ~SCCR_DFBRG);    	/*  ������ݒ�  */
    	lock_sccr();            		/*  SCCR���b�N  */

    	/*
    	 *  �{�[���[�g�ݒ�iBRG1�j
    	 *  �@�@EN=1�FBRG�J�E���g�C�l�[�u��
    	 *  �@�@EXTC=00�F�N���b�N�\�[�X��BRGCLK��I��
    	 *  �@�@ATB=0�F�I�[�g�{�[�@�\�f�B�Z�[�u��
    	 *  �@�@CD�F������
    	 *  �@�@DIV16�F16�������邩�ۂ�
    	 */
    	mpc860_wrw_mem(BRGC1, BRGC1_EN | (BRGC1_CD_VAL<<1));
    
    	/*
    	 *  BRG1��SMC1�̐ڑ�
    	 *  �@�@SMC1=0�FNMSI���[�h�i���d�����Ȃ��j
    	 *  �@�@SMC1CS=000�F�N���b�N�\�[�XBRG1
    	 */
    	mpc860_andw_mem(SIMODE, ~(SIMODE_SMC1 | SIMODE_SMC1CS));
    
    	/*�@�N���b�N�����肷��܂ő҂� */
    	sil_dly_nse(SMC_1BIT_TIME);

    	/*
    	 *  �o�b�t�@�E�f�B�X�N���v�^BD�̐ݒ�
    	 */
    					/*  RxBD�x�[�X�A�h���X  */
    	mpc860_wrh_mem(RBASE1, RxBD_BASE_ADDRESS);
         				/*  TxBD�x�[�X�A�h���X  */
    	mpc860_wrh_mem(TBASE1, TxBD_BASE_ADDRESS);

    	/*
    	 *  �ʐM�v���Z�b�TCP��INIT RX AND TX PARAMETERS�R�}���h�𔭍s
    	 */
    	mpc860_CP_command(CPCR_INIT_RX_TX_PARAMETERS, CPCR_CH_NUM_SMC1);
    
    	/*  SDMA��U�o�X����D��x��ݒ�  */
    	mpc860_wrw_mem(SDCR, SDCR_RAID_RB5);   /*  �D��x5�F�ʏ폈��  */

    	/*  �o�b�t�@�E�f�B�X�N���v�^BD�̃G���f�B�A���ݒ�  */
    	mpc860_wrb_mem(RFCR1, RFCR_BO);		/*  ��M  */
    	mpc860_wrb_mem(TFCR1, TFCR_BO);		/*  ���M  */
    	    			/*  �ő��M�o�b�t�@��  */
    	mpc860_wrh_mem(MRBLR1, PIC_BUFFER_SIZE);
       		/*  �A�C�h���L�����N�^�����o�@�\�f�B�Z�[�u��  */
    	mpc860_wrh_mem(MAX_IDL1, 0);
    
    	/*  ��M�u���[�N�Ɋւ���ݒ�͕K�v�Ȃ��̂ŃN���A  */
    	mpc860_wrh_mem(BRKLN1, 0);
    	mpc860_wrh_mem(BRKEC1, 0);
    
    	/*  STOP TRANSMIT�R�}���h�ő��M�����u���[�N�L�����N�^�̐���ݒ�  */
    	mpc860_wrh_mem(BRKCR1, 1);

    	/*  ��M�o�b�t�@�E�f�B�X�N���v�^RxBD�̏�����  */
    	mpc860_wrh_mem(RxBD_STATUS,
                 RxBD_STATUS_E | RxBD_STATUS_W | RxBD_STATUS_I);
                /*  E�t���O�Z�b�g  */
                /*  W=1�F�e�[�u�����̍ŏIBD  */
                /*  I=1�F��M�����ݔ���  */

    	mpc860_wrh_mem(RxBD_LENGTH, PIC_BUFFER_SIZE);  /*  �f�[�^��  */
       					/*  ��M�o�b�t�@�|�C���^  */
    	mpc860_wrw_mem(RxBD_BUFFP, (VW)Rx_buffer);

    	/*  ���M�o�b�t�@�E�f�B�X�N���v�^TxBD�̏�����  */
    	mpc860_wrh_mem(TxBD_STATUS,
    		TxBD_STATUS_R | TxBD_STATUS_W | TxBD_STATUS_I);
                /*  R�t���O�Z�b�g  */
                /*  W=1�F�e�[�u�����̍ŏIBD  */
                /*  I=1�F���M�����ݔ���  */

    	mpc860_wrh_mem(TxBD_LENGTH, PIC_BUFFER_SIZE);  /*  �f�[�^��  */
    					/*  ���M�o�b�t�@�|�C���^  */
    	mpc860_wrw_mem(TxBD_BUFFP, (VW)Tx_buffer);
    
    	/*  �ȑO�̃C�x���g���N���A  */
    	mpc860_wrb_mem(SMCE1,
    		SMCE_BRKE | SMCE_BRK | SMCE_BSY | SMCE_TX | SMCE_RX);

    	/*  ���ׂĂ�UART�����݂�����  */
    	mpc860_wrb_mem(SMCM1,
     		SMCM_BRKE | SMCM_BRK | SMCM_BSY | SMCM_TX | SMCM_RX);
    
    	/*  SMC���[�h�ݒ�  */
    	mpc860_wrh_mem(SMCMR1, (VH)((0x9<<11) | SMCMR_SM_UART));
        	/*  
        	 *  CLEN=9�F�L�����N�^��
        	 *  SL=0�F1�X�g�b�v�r�b�g
        	 *  PEN=0�F�p���e�B�Ȃ�
        	 *  SM=10�FSMC���[�h UART
        	 *  DM=00�F�f�f���[�h �ʏ퓮��
        	 *  TEN=0�FSMC���M�f�B�Z�[�u��
        	 *  REN=0�FSMC��M�f�B�Z�[�u��
        	 *   ���̎��_�ł͂܂��A���M����M���C�l�[�u���ł͂Ȃ�
        	 */
    
    	mpc860_orh_mem(SMCMR1, (SMCMR_TEN | SMCMR_REN));
        	/*  
        	 *  ��L�ɉ�����
        	 *  �@TEN=1�FSMC���M�C�l�[�u��
        	 *  �@REN=1�FSMC��M�C�l�[�u��
        	 */

	siopcb->exinf = exinf;
	siopcb->openflag = TRUE;
	return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
smc_cls_por(SIOPCB *siopcb)
{
         					/*  ����M��~  */
	mpc860_andh_mem(SMCMR1, ~(SMCMR_TEN | SMCMR_REN));
	siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
smc_snd_chr(SIOPCB *siopcb, char c)
{
	if (smc_putready(siopcb)) {
		smc_putchar(siopcb, c);
		return(TRUE);
	}
	return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
smc_rcv_chr(SIOPCB *siopcb)
{
	if (smc_getready(siopcb)) {
		return((INT)(UB) smc_getchar(siopcb));
	}
	return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
smc_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	SIL_PRE_LOC;
	
	switch (cbrtn) {
	case SIO_ERDY_SND:	/* ���M���荞�ݗv�������� */
		SIL_LOC_INT();
		mpc860_orh_mem(SMCMR1, SMCMR_TEN);
		SIL_UNL_INT();
		break;
	case SIO_ERDY_RCV:	/* ��M���荞�ݗv�������� */
		SIL_LOC_INT();
		mpc860_orh_mem(SMCMR1, SMCMR_REN);
		SIL_UNL_INT();
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
smc_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
	SIL_PRE_LOC;

	switch (cbrtn) {
	case SIO_ERDY_SND:	/* ���M���荞�ݗv�����֎~ */
		SIL_LOC_INT();
		mpc860_andh_mem(SMCMR1, ~SMCMR_TEN);
		SIL_UNL_INT();
		break;
	case SIO_ERDY_RCV:	/* ��M���荞�ݗv�����֎~ */
		SIL_LOC_INT();
		mpc860_andh_mem(SMCMR1, ~SMCMR_REN);
		SIL_UNL_INT();
		break;
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�����ݏ���
 */
Inline void
smc_isr_siop_out(SIOPCB *siopcb)
{
	/*  SMCE1�ł̊����ݗv���̃`�F�b�N�͍ς�ł���  */
	
	if (smc_putready(siopcb)) {
		/*
		 *  ���M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		smc_ierdy_snd(siopcb->exinf);
	}
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�����ݏ���
 */
Inline void
smc_isr_siop_in(SIOPCB *siopcb)
{
	/*  SMCE1�ł̊����ݗv���̃`�F�b�N�͍ς�ł���  */

	if (smc_getready(siopcb)) {
		/*
		 *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
		 */
		smc_ierdy_rcv(siopcb->exinf);
	}
}

/*
 *  SIL���g�p�����Ƃ��̃��O�@�\
 */
#ifdef SIL_DEBUG
#define ENTER_SMC_ISR						\
	if (sil_debug_on) {					\
		syslog(LOG_EMERG, "Enter selial interrupt.");	\
	}

#else /* SIL_DEBUG */

#define ENTER_SMC_ISR

#endif /* SIL_DEBUG */


/*
 *  SIO���M�����݃T�[�r�X���[�`��
 *  
 *  �@����M����
 *  
 */
void
smc_isr()
{
    	UB smce1, smcm1, event;
    	SIL_PRE_LOC;

	ENTER_SMC_ISR
	
    	if (!siopcb_table[0].openflag) goto exit_label;
    
    	smce1 = mpc860_reb_mem(SMCE1);
    	smcm1 = mpc860_reb_mem(SMCM1);
    	event = smce1 & smcm1;
    	
    	if (event & (SMCE_BRKE | SMCE_BRK | SMCE_BSY)) {
    		/*  �G���[�����F������  */
    		goto exit_label;
    	}
    	
    	if (event & SMCE_RX) {         /*  ��M������  */
	        	/*  1���Z�b�g���邱�Ƃɂ��A�C�x���g���N���A  */
        	mpc860_wrb_mem(SMCE1, SMCE_RX);
        	smc_isr_siop_in(&siopcb_table[0]);
    	}
    	if (event & SMCE_TX) {         /*  ���M������  */
	        	/*  1���Z�b�g���邱�Ƃɂ��A�C�x���g���N���A  */
        	mpc860_wrb_mem(SMCE1, SMCE_TX);
        	smc_isr_siop_out(&siopcb_table[0]);
    	}

exit_label:
    	/*
    	 * �@�����ݗv���̃N���A
    	 *  �@�@�����݃R���g���[���ˑ�
    	 *  �@�@�isys_config.h�Œ�`�j
    	 */
    	SIL_LOC_INT();
	CLEAR_IRQ_TO_ICU(SMC1);	
    	SIL_UNL_INT();
}

/*
 * �|�[�����O�ɂ�镶���̑��M
 */
void
smc_putc_pol(char c)
{
	BOOL is_ten_ok;
	VH smcmr;
	if (smc_openflag()) {	/*  ����������Ă��邩�`�F�b�N  */
		smcmr = mpc860_reh_mem(SMCMR1);
		is_ten_ok = smcmr & SMCMR_TEN;
		if (!is_ten_ok) {
						/*  ���M����  */
			mpc860_orh_mem(SMCMR1, SMCMR_TEN);
		}
				/*  �o�b�t�@����ɂȂ�̂�҂�  */
		while(!smc_putready(&siopcb_table[0]));	
		smc_putchar(&siopcb_table[0], c);	/*  1�������M  */

		if (!is_ten_ok) {
				/*  �o�b�t�@����ɂȂ�̂�҂�  */
			while(!smc_putready(&siopcb_table[0]));
				/*  2�L�����N�^���҂�  */
			sil_dly_nse(SMC_1BIT_TIME*18*10);	
						/*  ���M�֎~  */
			mpc860_andh_mem(SMCMR1, ~SMCMR_TEN);
		}
	}
}

/*  end of file  */
