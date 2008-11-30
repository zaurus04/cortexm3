/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Copyright (C) 2000,2001 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2002 by Hokkaido Industrial Research Institute, JAPAN
 *
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă���
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ���̏����̂����ꂩ�𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
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
 *  @(#) $Id: sh7145.h,v 1.1 2008/06/17 00:04:40 suikan Exp $
 */

#ifndef _SH7145_H_
#define _SH7145_H_

#include <sil.h>

/*
 *  �����݂̃x�N�^�ԍ���`
 */

#define ERI0	128				/*  SCI0    */
#define RXI0	129				/*  SCI0    */
#define TXI0	130				/*  SCI0    */
#define ERI1	132				/*  SCI1    */
#define RXI1	133				/*  SCI1    */
#define TXI1	134				/*  SCI1    */
#define CMI0	144				/*  CMT    */
#define ERI2	168				/*  SCI2    */
#define RXI2	169				/*  SCI2    */
#define TXI2	170				/*  SCI2    */

#ifndef _MACRO_ONLY

/*
 *  SH2�̓������W�X�^��`
 */
/* ���W���[���X�^���o�C���W�X�^ */
#define MSTCR1	((VH *)0xffff861c)
#define MSTCR2	((VH *)0xffff861e)

#define BCR1	((VH *)0xffff8620)
#define BCR2	((VH *)0xffff8622)
#define WCR1	((VH *)0xffff8624)
#define PACRH	((VH *)0xffff8388)
#define PACRL1	((VH *)0xffff838c)
#define PACRL2	((VH *)0xffff838e)
#define PBCR1	((VH *)0xffff8398)
#define PBCR2	((VH *)0xffff839a)
#define PCCR	((VH *)0xffff839c)
#define PDCRH1	((VH *)0xffff83a8)
#define PDCRH2	((VH *)0xffff83aa)
#define PDCRL1	((VH *)0xffff83ac)
#define PDCRL2	((VH *)0xffff83ae)
#define PECRL1	((VH *)0xffff83b8)
#define PECRL2	((VH *)0xffff83ba)
#define PAIORL	((VH *)0xffff8386)
#define PBIOR	((VH *)0xffff8394)
#define PEIORL	((VH *)0xffff83b4)
#define PEDRL	((VH *)0xffff83b0)

/* ���荞�ݗD��x���x���ݒ背�W�X�^ */
#define IPRA    ((VH *)0xffff8348)
#define IPRB    ((VH *)0xffff834a)
#define IPRC    ((VH *)0xffff834c)
#define IPRD    ((VH *)0xffff834e)
#define IPRE    ((VH *)0xffff8350)
#define IPRF    ((VH *)0xffff8352)
#define IPRG    ((VH *)0xffff8354)
#define IPRH    ((VH *)0xffff8356)
#define IPRI    ((VH *)0xffff835c)
#define IPRJ    ((VH *)0xffff835e)

/*
 * ���荞�݃R���g���[���̏�����
 */
Inline void sh2_init_intcontorller(void)
{
	sil_wrh_mem (IPRA, 0x0000);
	sil_wrh_mem (IPRB, 0x0000);
	sil_wrh_mem (IPRC, 0x0000);
	sil_wrh_mem (IPRD, 0x0000);
	sil_wrh_mem (IPRE, 0x0000);
	sil_wrh_mem (IPRF, 0x0000);
	sil_wrh_mem (IPRG, 0x0000);
	sil_wrh_mem (IPRH, 0x0000);
	sil_wrh_mem (IPRI, 0x0000);
	sil_wrh_mem (IPRJ, 0x0000);
}
#endif /* _MACRO_ONLY */

#endif /* _SH7145_H_ */
