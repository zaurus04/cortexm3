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
 *  Xstormy16����SFR�̒�`
 */
#ifndef _CPU_SFRS_H_
#define _CPU_SFRS_H_
                                /*
                                 *  ���荞�݂Ɨ�O�̐���
                                 */
#define __IL1L 0x7F02
#define __IL1H 0x7F03
#define __IL2L 0x7F04
#define __IL2H 0x7F05
#define __EXCPL 0x7f08
#define __EXCPH 0x7f09
                                /*
                                 *  �V�X�e���N���b�N�̐���
                                 */
#define __OCR0 0x7F0A
#define __OCR1 0x7F0B
                                /*
                                 *  ���b�`�h�b�O�^�C�}�[
                                 */
#define __WDTCR 0x7F0C
                                /*
                                 *  �x�[�X�^�C�}�[
                                 */
#define __BTCR 0x7F0E
                                /*
                                 *  �^�C�}�[0/1
                                 */
#define __T0LR 0x7F10
#define __T0HR 0x7F11
#define __T0CNT 0x7F12
#define __T0PR 0x7F13
#define __T1LR 0x7F14
#define __T1HR 0x7F15
#define __T1CNT 0x7F16
#define __T1PR 0x7F17
                                /*
                                 *  UART
                                 */
#define __U0CR 0x7f38
#define __U1CR 0x7f78
#define __UxCR_RUN 0x80
#define __UxCR_ORERR 0x40
#define __UxCR_BAUDRATE 0x20
#define __UxCR_PARITY 0x10
#define __UxCR_TXEMPTY 0x08
#define __UxCR_TXIE 0x04
#define __UxCR_RXREADY 0x02
#define __UxCR_RXIE 0x01
#define __UxTX_STOPBIT 0x0000

#endif /* _CPU_SFRS_H_ */
