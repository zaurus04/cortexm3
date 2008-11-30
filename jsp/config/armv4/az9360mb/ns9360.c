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
 *  @(#) $Id: ns9360.c,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */

/*
 *    �����@�\�p�h���C�o
 */
#include <s_services.h>
#include <ns9360.h>

/*
 * ����UART�p �Ȉ�SIO�h���C�o
 */

/*
 * �V���A��I/O�|�[�g�������u���b�N
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
	{
		/* UART Channel A */
		 (VP)SC1SRA_REG , (VP)SC1FIFO_REG , (VP)SC1CRA_REG , (VP)SC1CRB_REG
		,(VP)SC1RCT_REG , (VP)SC1RBT_REG , (VP)SC1BRG_REG
		,(SCCRA_CE | SCCRA_WLS | SCCRA_DTR | SCCRA_RTS)
		,0x08000000
		,0x80000008
		,0x80000008
		,(0xC0140000 | 7)			/* 29.4912MHz /2/8 = 115200*16 */
		,BBBI_S1TX , BBBI_S1RX
	 }
#if TNUM_SIOP >= 2
    ,
    {
		/* UART Channel C */
		 (VP)SC3SRA_REG , (VP)SC3FIFO_REG , (VP)SC3CRA_REG , (VP)SC3CRB_REG
		,(VP)SC3RCT_REG ,(VP)SC3RBT_REG ,  (VP)SC3BRG_REG
		,(SCCRA_CE | SCCRA_WLS | SCCRA_DTR | SCCRA_RTS)
		,0x08000000
		,0x80000008
		,0x80000008
		,(0xC0140000 | 7)			/* 29.4912MHz /2/8 = 115200*16 */
		,BBBI_S3TX , BBBI_S3RX
	}
#endif
 };

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
SIOPCB  siopcb_table[TNUM_SIOP];

/*
 * �V�X�e���o�͗p�V���A���|�[�g���
 */
SIOPCB      *sys_siopcb;


/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))


/*
 * ��������M������?
 */ 
Inline BOOL
uart_getready(SIOPCB *siopcb)
{
	VW	dt;
	
	if(0 != siopcb->rxfdb)
		return TRUE;
	
	dt = sil_rew_mem((VP)siopcb->siopinib->pSraReg);
	return(dt &(SCSRA_RFS | SCSRA_RRDY));
}

/*
 * �����𑗐M�ł��邩?
 */
Inline BOOL
uart_putready(SIOPCB *siopcb)
{
	return(sil_rew_mem((VP)siopcb->siopinib->pSraReg)&(SCSRA_TRDY | SCSRA_THALF | SCSRA_TEMPTY));
}

/*
 *  ��M���������̎��o��
 */
Inline UB
uart_getchar(SIOPCB *siopcb)
{
	UW	dt;
	
	if(0 == siopcb->rxfdb)
	{
		siopcb->rxfdb = (sil_rew_mem((VP)siopcb->siopinib->pSraReg) >> 20) & 0x03;
		if(0 == siopcb->rxfdb)
			siopcb->rxfdb = 4;
		
		siopcb->rxbuf = sil_rew_mem((VP)siopcb->siopinib->pFifoReg);
	}
	--(siopcb->rxfdb);
	dt = (siopcb->rxbuf >> 24) & 0xff;
	siopcb->rxbuf <<= 8;
	
	return (UB)dt;

}

/*
 *  ���M���镶���̏�������
 */
Inline void
uart_putchar(SIOPCB *siopcb, UB c)
{
    sil_wrb_mem((VP)siopcb->siopinib->pFifoReg, (VB)c);
}

/*
 *  ���M�����݋���
 */
Inline void
uart_enable_send(SIOPCB *siopcb)
{
		sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) | siopcb->siopinib->BbbiTx);
}

/*
 *  ���M�����݋֎~
 */
Inline void
uart_disable_send(SIOPCB *siopcb)
{
	sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) & ~siopcb->siopinib->BbbiTx);
}

/*
 *  ��M�����݋���
 */
Inline void
uart_enable_rcv(SIOPCB *siopcb)
{
	sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) | siopcb->siopinib->BbbiRx);
}

/*
 *  ��M�����݋֎~
 */
Inline void
uart_disable_rcv(SIOPCB *siopcb)
{
	sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) & ~siopcb->siopinib->BbbiRx);
}



/*
 * �J�[�l���N�����̃��O�o�͗p�̏�����
 */
void
uart_init(ID siopid){
    SIOPCB      *siopcb;

	uart_initialize();

    siopcb = get_siopcb(siopid);

	sys_siopcb = siopcb;

    /* UART Initialize */
    sil_wrw_mem((VP)siopcb->siopinib->pCraReg,(VW)siopcb->siopinib->CraData);
	sil_wrw_mem((VP)siopcb->siopinib->pCrbReg,(VW)siopcb->siopinib->CrbData);
	sil_wrw_mem((VP)siopcb->siopinib->pRctReg,(VW)0);
	
    /* Set bound rate */
	sil_wrw_mem((VP)siopcb->siopinib->pBrgReg,siopcb->siopinib->BrgData);
}


/*
 *  �I���`�b�v��UART����̃|�[�����O�o��
 */
void
uart_putc(char c)
{
    UW buf_level;
    
    do{
        buf_level = sil_rew_mem((VP)sys_siopcb->siopinib->pSraReg) & SCSRA_TRDY;
    }while(buf_level == 0);
    
    sil_wrb_mem((VP)sys_siopcb->siopinib->pFifoReg,(VW)c);
}

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
uart_initialize()
{
    SIOPCB  *siopcb;
    UINT    i;

    /*
     *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̏�����
     */
    for (siopcb = siopcb_table, i = 0; i < TNUM_SIOP; siopcb++, i++) {
        siopcb->siopinib = &(siopinib_table[i]);
        siopcb->openflag = FALSE;
        siopcb->sendflag = FALSE;
        siopcb->rxfdb = 0;
        siopcb->rxbuf = 0;
        siopcb->siopid = i;
    }
}

/*
 * �I�[�v�����Ă���|�[�g�����邩
 */
BOOL
uart_openflag(ID siopid)
{
    return(siopcb_table[siopid].openflag);
}


/*
 * �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
uart_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;
	UW		n;
	
    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;

    /* UART Initialize */
    sil_wrw_mem((VP)siopinib->pCraReg,(VW)siopinib->CraData);
	sil_wrw_mem((VP)siopinib->pCrbReg,(VW)siopinib->CrbData);
	sil_wrw_mem((VP)siopinib->pRctReg,(VW)siopinib->RctData);
	sil_wrw_mem((VP)siopinib->pRbtReg,(VW)siopinib->RbtData);
	
    /* Set bound rate */
	sil_wrw_mem((VP)siopinib->pBrgReg,siopinib->BrgData);

    /* ��MRcvRdy,FIFO=Half�A���MTxEmpty,FIFO-Half�����݋��� */
	n = sil_rew_mem((VP)siopinib->pCraReg);
	n &=  (~(SCCRA_RIE | SCCRA_TIC));
	n |= (0xe00 | 0x0c);
    sil_wrw_mem((VP)siopinib->pCraReg,(VW)n);
	
    /* BBUS�����݋��� */
	sil_wrw_mem((VP)BBBIE_REG,sil_rew_mem((VP)BBBIE_REG) | siopinib->BbbiRx);
	sil_wrw_mem((VP)INT_CFG8_11_REG,sil_rew_mem((VP)INT_CFG8_11_REG)|0x80000000);
	
    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;
    siopcb->rxfdb = 0;
    siopcb->rxbuf = 0;

    return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
uart_cls_por(SIOPCB *siopcb)
{
    siopcb->openflag = FALSE;
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
uart_snd_chr(SIOPCB *siopcb, char c)
{
    if (uart_putready(siopcb)){
        uart_putchar(siopcb, c);
        return(TRUE);
    }
    return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
uart_rcv_chr(SIOPCB *siopcb)
{
    if (uart_getready(siopcb)) {
        return((INT)(UB) uart_getchar(siopcb));
    }
    return(-1);
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
uart_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_enable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_enable_rcv(siopcb);
            break;
    }
}


/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
uart_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            uart_disable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            uart_disable_rcv(siopcb);
            break;
    }
}


/*
 *  �V���A��I/O�|�[�g�ɑ΂��鑗�M�����ݏ���
 */
static void
uart_Txisr_siop(SIOPCB *siopcb)
{
    /*
     *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
     */
    uart_ierdy_snd(siopcb->exinf);
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂����M�����ݏ���
 */
static void
uart_Rxisr_siop(SIOPCB *siopcb)
{
    /*
     *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
     *  �ő�4����(32bit)��M���Ă���̂ł����őS��M��������������
     */
    while(1)
    {
        uart_ierdy_rcv(siopcb->exinf);
        if(0 == siopcb->rxfdb)
            break;                           /* ��M�ς݃L�����N�^�Ȃ� */
	}
}


/*
 *  SIO��Tx�����݃T�[�r�X���[�`��
 */
void
uart_Tx_isr()
{
	uart_Txisr_siop(&(siopcb_table[0]));
}

/*
 *  SIO��Rx�����݃T�[�r�X���[�`��
 */
void
uart_Rx_isr()
{
	uart_Rxisr_siop(&(siopcb_table[0]));
	sil_wrw_mem((VP)siopcb_table[0].siopinib->pSraReg , 
					sil_rew_mem((VP)siopcb_table[0].siopinib->pSraReg) );
}

/*
 *  SIO2��Tx�����݃T�[�r�X���[�`��
 */
void
uart2_Tx_isr()
{
	uart_Txisr_siop(&(siopcb_table[1]));
}

/*
 *  SIO2��Rx�����݃T�[�r�X���[�`��
 */
void
uart2_Rx_isr()
{
	uart_Rxisr_siop(&(siopcb_table[1]));
	sil_wrw_mem((VP)siopcb_table[1].siopinib->pSraReg , 
					sil_rew_mem((VP)siopcb_table[1].siopinib->pSraReg) );
}


/*
 *  SIO�̊����݋����[�`��
 */
void
uart_TxRx_Enable(ID siopid)
{
	sil_wrw_mem((VP)BBBIE_REG,
				sil_rew_mem((VP)BBBIE_REG) | siopcb_table[siopid].siopinib->BbbiTx 
		                                   | siopcb_table[siopid].siopinib->BbbiRx);
}

/*
 *  SIO�̊����݋֎~���[�`��
 */
void
uart_TxRx_Disable(ID siopid)
{
		sil_wrw_mem((VP)BBBIE_REG,
				sil_rew_mem((VP)BBBIE_REG) & ~(siopcb_table[siopid].siopinib->BbbiTx
												 | siopcb_table[siopid].siopinib->BbbiRx) );
}

/*
 * ���݂̃V���A���|�[�g�̎擾
 */
ID
uart_get_id(SIOPCB *siopcb)
{
	return(siopcb->siopid);
}

