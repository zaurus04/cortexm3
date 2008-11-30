/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2007 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2001-2004 by Dep. of Computer Science and Engineering
 *                   Tomakomai National College of Technology, JAPAN
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
 *  @(#) $Id: hw_serial.h,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_

/*
 *  �^�[�Q�b�g�ˑ��V���A��I/O���W���[���iH8�p�j
 *    �E�|�[�g�� 1�{�̏ꍇ�� HWPORT1_ADDR�Ɏw�肳�ꂽ�|�[�g���g�p���A
 *      2�{�̏ꍇ�́AHWPORT1_ADDR�����[�U�p�AHWPORT2_ADDR���R���\�[��
 *      �o�͂Ƃ��Ďg�p����B
 *      HWPORTx_ADDR�� �^�[�Q�b�g�ˑ��� sys_config.h���Ŏw�肷��B
 *    �E���ʕ��̃��W���[���ɂ���āAXON/XOFF�t���[���䂪�s��
 *      ��Ă���̂ŁA�M������TxD��RxD��2�{�ł悢
 */

#include <s_services.h>
#include <h8_sil.h>

#ifndef _MACRO_ONLY

/*
 *  �V���A���|�[�g�̏������u���b�N
 */
typedef struct sio_port_initialization_block {
        UB      *base;          /* SCI �̃x�[�X�A�h���X */
        UW      baudrate;       /* �{�[���C�g           */
        IRC     irc;            /* �����݃��x���ݒ��� */
        UB      smr_init;       /* SMR �̐ݒ�l         */
} SIOPINIB;

/*
 *  �V���A���|�[�g�̐���u���b�N
 */

typedef struct sio_port_control_block {
        const SIOPINIB  *inib;          /* �������u���b�N       */
        VP_INT          exinf;          /* �g�����             */
        BOOL            openflag;       /* �I�[�v���ς݃t���O   */
} SIOPCB;

extern SIOPCB siopcb_table[TNUM_PORT];

/*
 *  SIO ID ����Ǘ��u���b�N�ւ̕ϊ�
 */
#define INDEX_SIO(sioid)        ((UINT)(sioid) - 1u)

Inline SIOPCB*
get_siopcb(ID sioid)
{
	UINT index = INDEX_SIO(sioid);
	
	assert(index < TNUM_PORT);
	
    return(&(siopcb_table[index]));
}

/*
 *  �R�[���o�b�N���[�`���̎��ʔԍ�
 */
#define SIO_ERDY_SND            1u              /* ���M�\�R�[���o�b�N                 */
#define SIO_ERDY_RCV            2u              /* ��M�ʒm�R�[���o�b�N                 */

/*
 *  SCI �֐��̎Q��
 */
extern void     SCI_initialize (ID sioid);      /* SCI �̏�����                         */
extern void     SCI_cls_por(UB *base);          /* SCI �̃N���[�Y                       */
extern void     SCI_in_handler(ID sioid);       /* SCI ���͊��荞�݃n���h��             */
extern void     SCI_out_handler(ID sioid);      /* SCI �o�͊��荞�݃n���h��             */
extern void     SCI_err_handler(ID sioid);      /* SCI ���̓G���[���荞�݃n���h��       */
extern void     SCI_ierdy_snd(VP_INT exinf);    /* �V���A�� I/O ����̑��M�\�R�[���o�b�N */
extern void     SCI_ierdy_rcv(VP_INT exinf);    /* �V���A�� I/O ����̎�M�ʒm�R�[���o�b�N */

/*
 *  SCI ���x���̊֐�
 */

/*
 *  SCI �̃I�[�v��
 */
Inline SIOPCB *
SCI_opn_por (ID sioid)
{
        SCI_initialize(sioid);
        return get_siopcb(sioid);
}

/*
 *  SCI_putchar -- ���M���镶���̏�������
 */
Inline void
SCI_putchar(const SIOPCB *p, UB c)
{
        UB *base_addr = p->inib->base;

        sil_wrb_mem((VP)(base_addr + H8TDR), (VB)c);
        bitclr(base_addr + H8SSR, (UB)H8SSR_TDRE_BIT);
}


/*
 *  �჌�x���o�͂ɗp����V���A���|�[�g��
 *  ���䂷�郌�W�X�^�Q�̐擪�A�h���X
 */
#if SCI_LOW_PORTID == SCI_PORTID1
#define SCI_LOW_BASE			SCI_PORT1_BASE
#else /* SCI_LOW_PORTID == SCI_PORTID1 */
#define SCI_LOW_BASE			SCI_PORT2_BASE
#endif

/*
 *  SCI_putchar_pol -- �|�[�����O�����ɂ��჌�x���o��
 */
Inline void
SCI_putchar_pol(UB c)
{
        UB *base = (UB*)SCI_LOW_BASE;
        UB *addr = base + H8SSR;
        UB tdre = 0;

        /* TDRE���Z�b�g�����܂ő҂� */
        while (tdre == 0) {
			/*  �R���p�C���̌x����}�����邽�߁A�L���X�g���Ă���  */
			tdre = (UB)((UB)sil_reb_mem((VP)addr) & H8SSR_TDRE);
		}
        sil_wrb_mem((VP)(base + H8TDR), (VB)c);
        bitclr(addr, (UB)H8SSR_TDRE_BIT);
}

/*
 *  SCI_getchar -- ��M���������̓ǂݏo��
 */
Inline INT
SCI_getchar(const SIOPCB *p)
{
        UB      *base_addr = p->inib->base;
        INT     ch = (UB)sil_reb_mem((VP)(base_addr + H8RDR));
                /* UB �̃L���X�g�́A�����g����h�~���邽�� */

        bitclr(base_addr + H8SSR, (UB)H8SSR_RDRF_BIT);
        return ch;
}

/*
 *  SCI_putready -- ���M�\��
 */
Inline BOOL
SCI_putready(const SIOPCB *pcb)
{
        BOOL ret = TRUE;
        UB ssr = sil_reb_mem((VP)(pcb->inib->base + H8SSR));
        
        ssr &= (UB)H8SSR_TDRE;
        if (ssr == 0) {
			ret = FALSE;
		}
        return(ret);
}

/*
 *  SCI_getready -- ��M�\��
 */
Inline BOOL
SCI_getready(const SIOPCB *pcb)
{
        BOOL ret = TRUE;
        UB ssr = sil_reb_mem((VP)(pcb->inib->base + H8SSR));

        ssr &= (UB)H8SSR_RDRF;
        if (ssr == 0) {
			ret = FALSE;
		}
        return(ret);
}

/*
 *  ���M���荞�ݐ���֐�
 */
Inline void
SCI_enable_send(const SIOPCB *p)
{
        UB *addr = p->inib->base + H8SCR;
        bitset(addr, (UB)H8SCR_TIE_BIT);
}

Inline void
SCI_disable_send(const SIOPCB *p)
{
        UB *addr = p->inib->base + H8SCR;
        bitclr(addr, (UB)H8SCR_TIE_BIT);
}

/*
 *  ��M���荞�ݐ���֐�
 */
Inline void
SCI_enable_recv(const SIOPCB *p)
{
        UB *addr = p->inib->base + H8SCR;
        bitset(addr, (UB)H8SCR_RIE_BIT);
}

Inline void
SCI_disable_recv(const SIOPCB *p)
{
        UB *addr = p->inib->base + H8SCR;
        bitclr(addr, (UB)H8SCR_RIE_BIT);
}

/*
 *  SIO �֐��̎Q��
 */
                                /* SCI �̏�����                         */
extern void     sio_initialize(void);
                                /* �V���A�� I/O ����̃R�[���o�b�N����  */
extern void     sio_ena_cbr(SIOPCB *pcb, UINT cbrtn);
                                /* �V���A�� I/O ����̃R�[���o�b�N�֎~  */
extern void     sio_dis_cbr(SIOPCB *pcb, UINT cbrtn);

/*
 *  �֐��V�~�����[�V�����}�N��
 */
                        /* �V���A�� I/O ����̑��M�\�R�[���o�b�N      */
#define sio_ierdy_snd(e)        SCI_ierdy_snd(e)
                        /* �V���A�� I/O ����̎�M�ʒm�R�[���o�b�N      */
#define sio_ierdy_rcv(e)        SCI_ierdy_rcv(e)

/*
 *  SIO ���x���̊֐�
 */

extern void sio_in_handler (void);
extern void sio_out_handler (void);

#ifdef H8_CFG_SCI_ERR_HANDLER
extern void sio_err_handler (void);
#endif  /* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#if TNUM_PORT >= 2u
extern void sio_in2_handler (void);
extern void sio_out2_handler (void);

#ifdef H8_CFG_SCI_ERR_HANDLER
extern void sio_err2_handler (void);
#endif  /* of #ifdef H8_CFG_SCI_ERR_HANDLER */

#endif  /* of #if TNUM_PORT >= 2u */

/*
 *  sio_opn_por -- �|�[�g�̃I�[�v��
 */
Inline SIOPCB *
sio_opn_por(ID sioid, VP_INT exinf)
{
        SIOPCB  *pcb = SCI_opn_por(sioid);

        pcb->exinf    = exinf;
        pcb->openflag = TRUE;
        return pcb;
}

/*
 *  sio_cls_por -- �|�[�g�̃N���[�Y
 */
Inline void
sio_cls_por(SIOPCB *pcb)
{
        SCI_cls_por(pcb->inib->base);
        pcb->openflag = FALSE;
}

/*
 *  sio_snd_chr -- �������M
 */
Inline BOOL
sio_snd_chr(const SIOPCB *pcb, char chr)
{
        BOOL ret = FALSE;
        if (SCI_putready(pcb) == TRUE) {
                SCI_putchar(pcb, (UB)chr);
                ret = TRUE;
        }
        return ret;
}

/*
 *  sio_rcv_chr -- ������M
 */
Inline INT
sio_rcv_chr(const SIOPCB *pcb)
{
        INT ret = 0;
        if (SCI_getready(pcb) == TRUE) {
                ret = SCI_getchar(pcb);
        } else {
                ret = -1;
        }
        return(ret);
}

#endif  /* of #ifndef _MACRO_ONLY */

#endif /* _HW_SERIAL_H_ */
