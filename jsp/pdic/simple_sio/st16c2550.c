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
 *  @(#) $Id: st16c2550.c,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

/*
 *     ST16C2550 �p �Ȉ�SIO�h���C�o
 */
#include <s_services.h>
#include <st16c2550.h>
 
/*
 * �e���W�X�^�̃I�t�Z�b�g
 */
#define ST16C_RHR   0x00   /* H  LCR bit7=0 Read  */
#define ST16C_THR   0x00   /* H  LCR bit7=0 Write */
#define ST16C_DLL   0x00   /* H  LCR bit7=1       */
#define ST16C_IER   0x02   /* H  LCR bit7=0       */
#define ST16C_DLM   0x02   /* H  LCR bit7=1       */
#define ST16C_ISR   0x04   /* H  Read  */
#define ST16C_FCR   0x04   /* H  Write */
#define ST16C_LCR   0x06   /* H  */
#define ST16C_MCR   0x08   /* H  */
#define ST16C_LSR   0x0a   /* H  Read */
#define ST16C_MSR   0x0c   /* H  Read */
#define ST16C_SPR   0x0e   /* H  */

#define ISR_TX            0x02       /* ���M���荞�ݔ��� */
#define IER_TX            0x02       /* ���M���荞�݋��� */
#define ISR_RX            0x01       /* ��M���荞�ݔ��� */
#define IER_RX            0x01       /* ��M���荞�݋��� */

#define LCR_DL_MODE       0x80       /* Divisor Enable */
#define LCR_VAL           0x03       /* 8bit,1stop,Noparity,No break */
#define FCR_FIFO_DISABLE  0x00

#define LSR_RX_DATA_READY 0x01
#define LSR_TX_EMPTY      0x20

#define MCR_INT_ENABLE    0x08

/*
 *  115200bps�ɐݒ�
 *  4 = (7372800Hz)/(115200*16)
 */
#define DLM_VAL  0x00
#define DLL_VAL  0x04




/*
 * �V���A��I/O�|�[�g�������u���b�N
 */
const SIOPINIB siopinib_table[TNUM_SIOP] = {
    {ST16C_CHB, LCR_VAL, DLM_VAL, DLL_VAL, PINTER_PINT7E},
#if TNUM_SIOP > 2
    {ST16C_CHA, LCR_VAL, DLM_VAL, DLL_VAL, PINTER_PINT6E},
#endif /* TNUM_SIOP > 2 */    
};

/*
 *  �V���A��I/O�|�[�g�������u���b�N�̎�o��
 */
#define INDEX_SIOPINIB(siopid)  ((UINT)((siopid) - 1))
#define get_siopinib(siopid)  (&(siopinib_table[INDEX_SIOPINIB(siopid)]))


/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
SIOPCB  siopcb_table[TNUM_SIOP];

/*
 *  �V���A��I/O�|�[�gID����Ǘ��u���b�N�����o�����߂̃}�N��
 */
#define INDEX_SIOP(siopid)  ((UINT)((siopid) - 1))
#define get_siopcb(siopid)  (&(siopcb_table[INDEX_SIOP(siopid)]))

Inline void
st16c_write(UW addr, UW offset, UB val)
{
    sil_wrh_mem((VP)(addr + offset),val);
}

Inline UB
st16c_read(UW addr, UW offset)
{
    return(sil_reh_mem((VP)(addr + offset)));
}


/*
 * ��������M������?
 */ 
Inline BOOL
st16c_getready(SIOPCB *siopcb)
{
    UH status;

    status = st16c_read(siopcb->siopinib->reg_base, ST16C_LSR);
    
    return((status & LSR_RX_DATA_READY));
}

/*
 * �����𑗐M�ł��邩?
 */
Inline BOOL
st16c_putready(SIOPCB *siopcb)
{
    UH status;

    status = st16c_read(siopcb->siopinib->reg_base, ST16C_LSR);
    
    return (status & LSR_TX_EMPTY);
}

/*
 *  ��M���������̎��o��
 */
Inline UB
st16c_getchar(SIOPCB *siopcb)
{
    return(st16c_read(siopcb->siopinib->reg_base,ST16C_RHR));
}

/*
 *  ���M���镶���̏�������
 */
Inline void
st16c_putchar(SIOPCB *siopcb, UB c)
{
    st16c_write(siopcb->siopinib->reg_base, ST16C_THR, c);
}

/*
 *  ���M�����݋���
 */
Inline void
st16c_enable_send(SIOPCB *siopcb)
{
    st16c_write(siopcb->siopinib->reg_base, ST16C_IER,
                (st16c_read(siopcb->siopinib->reg_base,ST16C_IER) | IER_TX));
}

/*
 *  ���M�����݋֎~
 */
Inline void
st16c_disable_send(SIOPCB *siopcb)
{
    st16c_write(siopcb->siopinib->reg_base, ST16C_IER,
                (st16c_read(siopcb->siopinib->reg_base, ST16C_IER) & ~IER_TX));
                
}

/*
 *  ��M�����݋���
 */
Inline void
st16c_enable_rcv(SIOPCB *siopcb)
{
    st16c_write(siopcb->siopinib->reg_base, ST16C_IER,
                (st16c_read(siopcb->siopinib->reg_base,ST16C_IER) | IER_RX));
}

/*
 *  ��M�����݋֎~
 */
Inline void
st16c_disable_rcv(SIOPCB *siopcb)
{
    st16c_write(siopcb->siopinib->reg_base, ST16C_IER,
                (st16c_read(siopcb->siopinib->reg_base, ST16C_IER) & ~IER_RX));
                
}


/*
 *  SIO�h���C�o�̏��������[�`��
 */
void
st16c2550_initialize()
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
    }
}

    
/*
 *
 */
void
st16c2550_init_siopinib(const SIOPINIB *siopinib)
{
    /*
     *  ������̐ݒ�
     */
    /* Divisor Enable */
    st16c_write(siopinib->reg_base, ST16C_LCR,
                (st16c_read(siopinib->reg_base, ST16C_LCR) | LCR_DL_MODE));
    st16c_write(siopinib->reg_base, ST16C_DLL, siopinib->dll_val);
    st16c_write(siopinib->reg_base, ST16C_DLM, siopinib->dlm_val);
    /* Divisor Disable */
    st16c_write(siopinib->reg_base, ST16C_LCR,
                (st16c_read(siopinib->reg_base, ST16C_LCR) & ~LCR_DL_MODE));

    /* ���[�h�ݒ� */
    st16c_write(siopinib->reg_base, ST16C_LCR, siopinib->lcr_val);

    /* FIFO Disable */
    st16c_write(siopinib->reg_base, ST16C_FCR, FCR_FIFO_DISABLE);

    /* �����݋֎~ */
    st16c_write(siopinib->reg_base, ST16C_IER, 0x00);
}


/*
 *  �J�[�l���N�����̃o�[�i�[�o�͗p�̏�����
 */
void
st16c2550_init(void)
{
    
    st16c2550_init_siopinib(get_siopinib(1));
#if TNUM_SIOP > 2
    st16c2550_init_siopinib(get_siopinib(2));    
#endif /* TNUM_SIOP > 2 */        
    
}

/*
 * �I�[�v�����Ă���|�[�g�����邩
 */
BOOL
st16c2550_openflag(void)
{
#if TNUM_SIOP < 2
    return(siopcb_table[0].openflag);
#else /* TNUM_SIOP < 2 */
    return(siopcb_table[0].openflag || siopcb_table[1].openflag);
#endif /* TNUM_SIOP < 2 */
}


/*
 * �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *
st16c2550_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB      *siopcb;
    const SIOPINIB  *siopinib;

    siopcb = get_siopcb(siopid);
    siopinib = siopcb->siopinib;
    
    /*
     * ������
     */
    st16c2550_init_siopinib(siopcb->siopinib);
    
    /* ��M�����݋��� */
    st16c_write(siopcb->siopinib->reg_base, ST16C_IER, IER_RX);
    
    /* �����ݐ����C�l�[�u�� */
    st16c_write(siopcb->siopinib->reg_base, ST16C_MCR, MCR_INT_ENABLE);

    siopcb->exinf = exinf;
    siopcb->getready = siopcb->putready = FALSE;
    siopcb->openflag = TRUE;

    return(siopcb);
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void
st16c2550_cls_por(SIOPCB *siopcb)
{
    /* �����݋֎~ */
    st16c_write(siopcb->siopinib->reg_base, ST16C_IER, 0x00);   
    siopcb->openflag = FALSE;
}


/*
 *  �V���A��I/O�|�[�g�ւ̃|�[�����O�ł̏o��
 */
void
st16c2550_pol_putc(char c, ID siopid)
{
    const SIOPINIB *siopinib;
    
    siopinib = get_siopinib(siopid);
    
    while((st16c_read(siopinib->reg_base, ST16C_LSR) & LSR_TX_EMPTY)
          != LSR_TX_EMPTY)
        ;
    st16c_write(siopinib->reg_base, ST16C_THR, c);
}


/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL
st16c2550_snd_chr(SIOPCB *siopcb, char c)
{
    if (st16c_putready(siopcb)){
        st16c_putchar(siopcb, c);
        return(TRUE);
    }
    return(FALSE);
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT
st16c2550_rcv_chr(SIOPCB *siopcb)
{
    if (st16c_getready(siopcb)) {
        return((INT)(UB) st16c_getchar(siopcb));
    }
    return(-1);
}





/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void
st16c2550_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{

    switch (cbrtn) {
        case SIO_ERDY_SND:
            st16c_enable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            st16c_enable_rcv(siopcb);
            break;
    }
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void
st16c2550_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    switch (cbrtn) {
        case SIO_ERDY_SND:
            st16c_disable_send(siopcb);
            break;
        case SIO_ERDY_RCV:
            st16c_disable_rcv(siopcb);
            break;
    }
}

/*
 *  �V���A��I/O�|�[�g�ɑ΂��銄���ݏ���
 */
static void
st16c2550_isr_siop(SIOPCB *siopcb)
{
    if (st16c_getready(siopcb)) {
        /*
         *  ��M�ʒm�R�[���o�b�N���[�`�����Ăяo���D
         */
        st16c2550_ierdy_rcv(siopcb->exinf);
    }
    if (st16c_putready(siopcb)) {
        /*
         *  ���M�\�R�[���o�b�N���[�`�����Ăяo���D
         */
        st16c2550_ierdy_snd(siopcb->exinf);
    }
}

/*
 *  SIO�̊����݃T�[�r�X���[�`��
 */
void
st16c2550_isr()
{
    st16c2550_isr_siop(&(siopcb_table[0]));
}
