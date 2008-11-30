/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2005 by Embedded and Real-Time Systems Laboratory
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
 */

/*
 *  �V���A��I/O�f�o�C�X�iSIO�j�h���C�o�iXstormy16�p�j
 */

#include <kernel.h>
#include <s_services.h>
#include <hw_serial.h>
#include <cpu_sfrs.h>

/*
 *  �񓯊����M�ł�TxReady�̃^�C���A�E�g
 */
#define TXREADY_TIMEOUT 400

/*
 *  SIOPCB*�`�F�b�N�̂��߂̃}�W�b�N�l
 */
#define MAGIC_SIOPCB 0xabcd

/*
 *  �V���A��I/O�|�[�g�Ǘ��u���b�N�̃G���A
 */
static SIOPCB siopcb_table[TNUM_PORT] = {
    { MAGIC_SIOPCB, __U0CR, 0x1400 },
    { MAGIC_SIOPCB, __U1CR, 0x4800 },
} ;

/*
 *  SIO�h���C�o�̏��������[�`��
 */
void sio_initialize(void)
{
    /* nothing to do here */
}

/*
 *  �V���A��I/O�|�[�g�̃I�[�v��
 */
SIOPCB *sio_opn_por(ID siopid, VP_INT exinf)
{
    SIOPCB* siopcb ;
    UH uhBase ;
                                /*
                                 *  �I�[�v���o����|�[�g���̃`�F�b�N
                                 */
    if ( siopid < 1 || siopid > TNUM_PORT ) return NULL ;
    siopcb = &siopcb_table[siopid-1] ;
    if ( siopcb->bNotExist ) return NULL ;
                                /*
                                 *  ���ɃI�[�v���ς݂̏ꍇ
                                 */
    if ( siopcb->bOpened ) {
        siopcb->vpiExinf = exinf ;
        return siopcb ;
    }
                                /*
                                 *  SIO�̏������Ƒ��݂̃`�F�b�N
                                 */
    uhBase = siopcb->uhBase ;
    __SFR(uhBase) = __UxCR_RUN|__UxCR_TXEMPTY ;
    if ( ( __SFR(uhBase) &
        ( __UxCR_RUN|__UxCR_BAUDRATE|__UxCR_PARITY|__UxCR_TXIE|
        __UxCR_RXIE) ) != __UxCR_RUN ) {
        siopcb->bNotExist = TRUE ;
        return NULL ;
    }
                                /*
                                 *  �Ǘ��e�[�u���̏�����
                                 */
    siopcb->vpiExinf = exinf ;
    siopcb->bOpened = TRUE ;
    siopcb->bTxIe = FALSE ;
    siopcb->bRxIe = FALSE ;
    siopcb->bLastIsCr = FALSE ;
                                /*
                                 *  ���荞�݃n���h���̓o�^�Ƌ���
                                 */
    define_inh( INHNO_SIO, sio_handler ) ;
    __UNLOCK_EXCP() ;
    __SFRW(__EXCPL) |= siopcb->uhExcpMask ;
    __LOCK_EXCP() ;
    return siopcb ;
}

/*
 *  �V���A��I/O�|�[�g�̃N���[�Y
 */
void sio_cls_por(SIOPCB *siopcb)
{
                                /*
                                 *  �N���[�Y�o����|�[�g���̃`�F�b�N
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return ;
                                /*
                                 *  �Ǘ��e�[�u���̕ύX
                                 */
    siopcb->bOpened = FALSE ;
                                /*
                                 *  ���荞�݂̋֎~
                                 */
    __UNLOCK_EXCP() ;
    __SFRW(__EXCPL) &= ~siopcb->uhExcpMask ;
    __LOCK_EXCP() ;
                                /*
                                 *  SIO�̒�~
                                 */
    __SFR(siopcb->uhBase) = 0 ;
}

/*
 *  SIO�̊����݃n���h��
 */
void sio_handler(void)
{
                                /*
                                 *  �S�Ẵ|�[�g�ɂ��ă`�F�b�N
                                 */
    ID portid ;
    for ( portid = 0 ; portid < TNUM_PORT ; portid++ ) {
        SIOPCB *siopcb = &siopcb_table[portid] ;
        UH uhBase = siopcb->uhBase ;
                                /*
                                 *  ���M�������荞�݂�
                                 */
        if ( ( __SFR(uhBase) & ( __UxCR_TXIE | __UxCR_TXEMPTY ) ) ==
            ( __UxCR_TXIE | __UxCR_TXEMPTY ) ) {
            sio_ierdy_snd( siopcb->vpiExinf ) ;
        }
                                /*
                                 *  ��M���荞�݂�
                                 */
        if ( ( __SFR(uhBase) & ( __UxCR_RXIE | __UxCR_RXREADY ) ) ==
            ( __UxCR_RXIE | __UxCR_RXREADY ) ) {
            sio_ierdy_rcv( siopcb->vpiExinf ) ;
        }
    }
}

/*
 *  �V���A��I/O�|�[�g�ւ̕������M
 */
BOOL sio_snd_chr(SIOPCB *siopcb, char c)
{
    UH uhBase ;
                                /*
                                 *  �L���ȃ|�[�g���ǂ����̃`�F�b�N
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return FALSE ;
    uhBase = siopcb->uhBase ;
                                /*
                                 *  ���M�\���ǂ����̃`�F�b�N
                                 */
    if ( ! ( __SFR(uhBase) & __UxCR_TXEMPTY ) ) return FALSE ;
                                /*
                                 *  ���M�f�[�^�̏�������
                                 */
    __SFRW(uhBase+4) = __UxTX_STOPBIT | c ;
    return TRUE ;
}

/*
 *  �V���A��I/O�|�[�g����̕�����M
 */
INT sio_rcv_chr(SIOPCB *siopcb)
{
    UH uhBase ;
                                /*
                                 *  �L���ȃ|�[�g���ǂ����̃`�F�b�N
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return -1 ;
    uhBase = siopcb->uhBase ;
                                /*
                                 *  ��M�f�[�^�L���̃`�F�b�N
                                 */
    if ( ! ( __SFR(uhBase) & __UxCR_RXREADY ) ) return -1 ;
                                /*
                                 *  ��M�f�[�^�̎��o��
                                 */
    return __SFRW(uhBase+2) & 0xff ;
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋���
 */
void sio_ena_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    UH uhBase ;
                                /*
                                 *  �L���ȃ|�[�g���ǂ����̃`�F�b�N
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return ;
    uhBase = siopcb->uhBase ;
                                /*
                                 *  ���M���荞�݂̋���
                                 */
    if ( cbrtn == SIO_ERDY_SND ) {
        __SFR(uhBase) |= __UxCR_TXIE ;
        siopcb->bTxIe = TRUE ;
    }
                                /*
                                 *  ��M���荞�݂̋���
                                 */
    if ( cbrtn == SIO_ERDY_RCV ) {
        __SFR(uhBase) |= __UxCR_RXIE ;
        siopcb->bRxIe = TRUE ;
    }
}

/*
 *  �V���A��I/O�|�[�g����̃R�[���o�b�N�̋֎~
 */
void sio_dis_cbr(SIOPCB *siopcb, UINT cbrtn)
{
    UH uhBase ;
                                /*
                                 *  �L���ȃ|�[�g���ǂ����̃`�F�b�N
                                 */
    if ( !siopcb || siopcb->uhMagic != MAGIC_SIOPCB ||
        siopcb->bNotExist || !siopcb->bOpened ) return ;
    uhBase = siopcb->uhBase ;
                                /*
                                 *  ���M���荞�݂̋֎~
                                 */
    if ( cbrtn == SIO_ERDY_SND ) {
        __SFR(uhBase) &= ~__UxCR_TXIE ;
        siopcb->bTxIe = FALSE ;
    }
                                /*
                                 *  ��M���荞�݂̋֎~
                                 */
    if ( cbrtn == SIO_ERDY_RCV ) {
        __SFR(uhBase) &= ~__UxCR_RXIE ;
        siopcb->bRxIe = FALSE ;
    }
}

/*
 *  �f�t�H���g�̑��M�\�R�[���o�b�N
 */
void sio_ierdy_snd(VP_INT exinf) __attribute__((__weak__)) ;
void sio_ierdy_snd(VP_INT exinf)
{
}

/*
 *  �f�t�H���g�̎�M�ʒm�R�[���o�b�N
 */
void sio_ierdy_rcv(VP_INT exinf) __attribute__((__weak__)) ;
void sio_ierdy_rcv(VP_INT exinf)
{
}

/*
 *  �V���A��I/O�|�[�g�ւ̔񓯊������o��
 */
void sio_asnd_chr( INT c )
{
    SIOPCB* siopcb ;
    UH uhBase ;
    int i ;
                                /*
                                 *  CPU���b�N��Ԃɂ���
                                 */
    BOOL bLocked ;
    if ( sns_loc() ) bLocked = TRUE ;
    else {
        bLocked = FALSE ;
        if ( sns_ctx() ) iloc_cpu() ;
        else loc_cpu() ;
    }
                                /*
                                 *  �񓯊��p�|�[�g���J��
                                 */
    if ( ( siopcb = sio_opn_por( LOGTASK_PORTID,
        siopcb_table[LOGTASK_PORTID-1].vpiExinf ) ) != NULL ) {
        uhBase = siopcb->uhBase ;
                                /*
                                 *  LF�Ȃ�܂�CR�𑗏o
                                 */
        if ( c == '\n' ) {
            for ( i = 0 ; i < TXREADY_TIMEOUT ; i++ ) {
                if ( __SFR(uhBase) & __UxCR_TXEMPTY ) break ;
            }
            if ( i < TXREADY_TIMEOUT ) {
                __SFRW(uhBase+4) = __UxTX_STOPBIT | '\r' ;
            }
        }
                                /*
                                 *  �f�[�^���o
                                 */
        for ( i = 0 ; i < TXREADY_TIMEOUT ; i++ ) {
            if ( __SFR(uhBase) & __UxCR_TXEMPTY ) break ;
        }
        if ( i < TXREADY_TIMEOUT ) {
            __SFRW(uhBase+4) = __UxTX_STOPBIT | c ;
        }
    }
                                /*
                                 *  CPU���b�N�����ɖ߂�
                                 */
    if ( !bLocked ) {
        if ( sns_ctx() ) iunl_cpu() ;
        else unl_cpu() ;
    }
}

/*
 *  �V���A��I/O�|�[�g����̔񓯊���������
 */
INT sio_arcv_chr( void )
{
    SIOPCB* siopcb ;
    UH uhBase ;
    INT c = -1 ;
                                /*
                                 *  �^�X�N�R���e�L�X�g����̂ݎg�p��
                                 */
    if ( sns_ctx() || sns_loc() || sns_dsp() ) return -1 ;
                                /*
                                 *  CPU���b�N��Ԃɂ���
                                 */
    loc_cpu() ;
                                /*
                                 *  �񓯊��p�|�[�g���J��
                                 */
    if ( ( siopcb = sio_opn_por( LOGTASK_PORTID,
        siopcb_table[LOGTASK_PORTID-1].vpiExinf ) ) != NULL ) {
        uhBase = siopcb->uhBase ;
                                /*
                                 *  ��M�҂�
                                 */
        while(1) {
            if ( __SFR(uhBase) & __UxCR_RXREADY ) {
                c = __SFRW(uhBase+2) & 0xff ;
                if ( c == '\r' ) {
                    c = '\n' ;
                    siopcb->bLastIsCr = TRUE ;
                }
                else {
                    if ( c == '\n' && siopcb->bLastIsCr ) c = -1 ;
                    siopcb->bLastIsCr = FALSE ;
                }
            }
            if ( c != -1 ) break ;
            unl_cpu() ;
            dly_tsk( 50 ) ;
            loc_cpu() ;
        }
    }
                                /*
                                 *  CPU���b�N������
                                 */
    unl_cpu() ;
    return c ;
}

