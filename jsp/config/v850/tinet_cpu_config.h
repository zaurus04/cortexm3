/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2004 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
 *  @(#) $Id: tinet_cpu_config.h,v 1.1 2008/06/17 00:04:50 suikan Exp $
 */

#ifndef _TINET_CPU_CONFIG_H_
#define _TINET_CPU_CONFIG_H_

/*
 *  TCP/IP �Ɋւ����`
 */

/* TCP �Ɋւ����` */

/*
 *  MAX_TCP_RCV_SEG: ��M�Z�O�����g�T�C�Y�̍ő�l
 *
 *    ����: �ύX���ׂ��ł͂Ȃ��B
 */

#define MAX_TCP_RCV_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))

/*
 *  MAX_TCP_SND_SEG: ���M�Z�O�����g�T�C�Y�̍ő�l
 *
 *    ���肩�� MSS �I�v�V�����ŃZ�O�����g�T�C�Y���w�肳��Ă��A
 *    ���̒l�ŁA�Z�O�����g�T�C�Y�𐧌��ł���B
 */

#ifdef SUPPORT_PPP

#define MAX_TCP_SND_SEG		(256 - ((IF_IP_TCP_HDR_SIZE + 3) >> 2 << 2))
/*#define MAX_TCP_SND_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))*/
/*#define MAX_TCP_SND_SEG		TCP_MSS*/

#endif	/* of #ifdef SUPPORT_PPP */

#ifdef SUPPORT_ETHER

/*#define MAX_TCP_SND_SEG		(1024 - ((IF_IP_TCP_HDR_SIZE + 3) >> 2 << 2))*/
#define MAX_TCP_SND_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
/*#define MAX_TCP_SND_SEG		TCP_MSS*/

#endif	/* of #ifdef SUPPORT_ETHER */

#ifdef SUPPORT_LOOP

#define MAX_TCP_SND_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))

#endif	/* of #ifdef SUPPORT_LOOP */

/*
 *  DEF_TCP_SND_SEG: ���M�Z�O�����g�T�C�Y�̋K��l
 *  DEF_TCP_RCV_SEG: ��M�Z�O�����g�T�C�Y�̋K��l
 */

#ifdef SUPPORT_PPP

#define DEF_TCP_SND_SEG		MAX_TCP_SND_SEG

#define DEF_TCP_RCV_SEG		(256 - ((IF_IP_TCP_HDR_SIZE + 3) >> 2 << 2))
/*#define DEF_TCP_RCV_SEG		MAX_TCP_RCV_SEG*/

#endif	/* of #ifdef SUPPORT_PPP */

#ifdef SUPPORT_ETHER

#define DEF_TCP_SND_SEG		MAX_TCP_SND_SEG

/*#define DEF_TCP_RCV_SEG		(1024 - ((IF_IP_TCP_HDR_SIZE + 3) >> 2 << 2))*/
#define DEF_TCP_RCV_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))
/*#define DEF_TCP_RCV_SEG		TCP_MSS*/

#endif	/* of #ifdef SUPPORT_ETHER */

#ifdef SUPPORT_LOOP

#define DEF_TCP_SND_SEG		MAX_TCP_SND_SEG
#define DEF_TCP_RCV_SEG		(IF_MTU - (IP_HDR_SIZE + TCP_HDR_SIZE))

#endif	/* of #ifdef SUPPORT_LOOP */

/* 
 *  �Z�O�����g�̏��Ԃ����ւ���Ƃ��ɐV���Ƀl�b�g���[�N�o�b�t�@�������ĂāA
 *  �f�[�^���R�s�[����T�C�Y�̂������l
 */
#define MAX_TCP_REALLOC_SIZE	1024	

#define TMO_TCP_GET_NET_BUF	1000	/* [ms]�Anet_buf �l���^�C���A�E�g		*/
#define TMO_TCP_OUTPUT		1000	/* [ms]�ATCP �o�̓^�C���A�E�g			*/

#define TCP_CFG_OPT_MSS		/* �R�l�N�V�����J�ݎ��ɁA�Z�O�����g�T�C�Y�I�v�V���������đ��M����B*/
#define TCP_CFG_DELAY_ACK	/* ACK ��x�点��Ƃ��̓R�����g���O���B			*/
#define TCP_CFG_ALWAYS_KEEP	/* ��ɃL�[�v�A���C�u���鎞�̓R�����g���O���B		*/

/*
 *  �o�̓^�X�N
 */

#define	TCP_OUT_TASK_STACK_SIZE	1024	/* TCP �o�̓^�X�N�̃X�^�b�N�T�C�Y		*/
#define TCP_OUT_TASK_PRIORITY	5	/* TCP �o�̓^�X�N�̗D��x			*/

/* UDP �Ɋւ����` */

					/* UDP ��M�L���[�T�C�Y				*/
#define NUM_DTQ_UDP_RCVQ	(NUM_MPF_NET_BUF_IF_PDU-1)	/* ��R�[���o�b�N�p	*/
#define NUM_DTQ_UDP_CB_RCVQ	(NUM_DTQ_UDP_RCVQ+1)		/* �R�[���o�b�N�p	*/

#define TMO_UDP_OUTPUT	10000		/* [ms]�AUDP �o�̓^�C���A�E�g			*/

#define UDP_CFG_IN_CHECKSUM	/* UDP �̓��̓`�F�b�N�T�����s���ꍇ�̓R�����g���O���B	*/
#define UDP_CFG_OUT_CHECKSUM	/* UDP �̏o�̓`�F�b�N�T�����s���ꍇ�̓R�����g���O���B	*/

/*
 *  �m���u���b�L���O�R�[�����s���ꍇ�ɑg�ݍ��ރ^�X�N�ƃf�[�^�L���[
 */

#define NUM_DTQ_UDP_OUTPUT	1	/* UDP �o�̓f�[�^�L���[�T�C�Y			*/
#define	UDP_OUT_TASK_STACK_SIZE	1024	/* UDP �o�̓^�X�N�̃X�^�b�N�T�C�Y			*/
#define UDP_OUT_TASK_PRIORITY	5	/* UDP �o�̓^�X�N�̗D��x				*/

/* ICMPv4/v6 �Ɋւ����` */

#define ICMP_REPLY_ERROR		/* ICMP �G���[���b�Z�[�W�𑗐M����ꍇ�̓R�����g���O���B*/

#define TMO_ICMP_OUTPUT		1000	/* [ms]�AICMP �o�̓o�b�t�@�l���^�C���A�E�g	*/

/* IPv4/IPv6 ���ʒ�` */

#define TMO_IN_REDIRECT	(10*60*1000)	/* [ms]�A�����������[�e�B���O�G���g���^�C���A�E�g	*/

/* IPv4 �Ɋւ����` */

/*#define IP4_CFG_FRAGMENT		 �f�[�^�O�����̕����E�č\���s���ꍇ�̓R�����g���O���B*/
#define NUM_IP4_FRAG_QUEUE	2	/* �f�[�^�O�����č\���L���[�T�C�Y			*/
#define TMO_IP4_FRAG_GET_NET_BUF	1000	/* [ms]�Anet_buf �l���^�C���A�E�g		*/

/* IPv6 �Ɋւ����` */

#ifdef SUPPORT_ETHER

#define IP6_CFG_AUTO_LINKLOCAL		/* �����N���[�J���A�h���X�̎����ݒ���s���ꍇ�̓R�����g���O���B*/

#endif	/* of #ifdef SUPPORT_ETHER */

#define NUM_IP6_DAD_COUNT	1	/* �d���A�h���X���o�ő��M����ߗחv���̉񐔁A		*/
					/*  0 ���w�肷��ƁA�d���A�h���X���o���s��Ȃ��B	*/
#define NUM_ND6_CACHE_ENTRY	10	/* �ߗ׃L���b�V���̃G���g����			*/

#ifdef SUPPORT_ETHER

/*
 *  �f�B�t�H���g���[�^���X�g�̃G���g�����B
 *  0 ���w�肷��ƃ��[�^�ʒm����M���Ȃ��B
 */
#define NUM_ND6_DEF_RTR_ENTRY	2

/*
 *  �N�����̃��[�^�v���o�͉񐔁B
 *  0 ���w�肷��ƃ��[�^�v�����o�͂��Ȃ��B
 */
#define NUM_ND6_RTR_SOL_RETRY	3	

#endif	/* of #ifdef SUPPORT_ETHER */

#define TMO_ND6_NS_OUTPUT	1000	/* [ms]�A�ߗחv���o�̓^�C���A�E�g		*/
#define TMO_ND6_NA_OUTPUT	1000	/* [ms]�A�ߗגʒm�o�̓^�C���A�E�g		*/
#define TMO_ND6_RS_OUTPUT	1000	/* [ms]�A���[�^�v���o�̓^�C���A�E�g		*/
#define TMO_ND6_RTR_SOL_DELAY	1000	/* [ms]�A���[�^�v���o�͒x��			*/
#define TMO_ND6_RTR_SOL_INTERVAL	\
				3000	/* [ms]�A���[�^�v���o�͊Ԋu			*/

/*
 *  �f�[�^�����N�w (�l�b�g���[�N�C���^�t�F�[�X) �Ɋւ����`
 */

/*
 *  PPP �Ɋւ����`
 */

#define NUM_DTQ_PPP_OUTPUT	2	/* PPP �o�̓f�[�^�L���[�T�C�Y�A2 �ȏ�	*/

#define	PPP_INPUT_STACK_SIZE	1024	/* PPP �^�X�N�̃X�^�b�N�T�C�Y		*/
#define	PPP_OUTPUT_STACK_SIZE	1024	/* PPP �o�̓^�X�N�̃X�^�b�N�T�C�Y		*/

#define PPP_INPUT_PRIORITY	5	/* PPP �^�X�N�̗D��x			*/
#define PPP_OUTPUT_PRIORITY	5	/* PPP �^�X�N�̗D��x			*/

#define TMO_PPP_GET_NET_BUF	1000	/* [ms]�A��M�p net_buf �l���^�C���A�E�g	*/

/*
 *  PPP�A���f���Ɋւ����`
 */

#define MODEM_CFG_DIAL		"ATD"	/* �_�C�A���R�}���h������			*/
#define MODEM_CFG_RETRY_CNT	3	/* �_�C�A�����g���C��			*/
#define MODEM_CFG_RETRY_WAIT	10000	/* �_�C�A�����g���C�܂ł̑҂����� [ms]	*/

/*
 *  PPP�AHDLC �Ɋւ����`
 */

#define DEF_LOCAL_ACCM		0x000a0000	/* ������ ACCM�AXON �� XOFF �̂ݕϊ�	*/
#define DEF_REMOTE_ACCM		0xffffffff	/* ����� ACCM�A�����l�͑S�ĕϊ�		*/

/*
 *  PPP�ALCP �Ɋւ����`
 */

#define LCP_CFG_MRU		0x0001	/* MRU					*/
#define LCP_CFG_ACCM		0x0002	/* ACCM					*/
#define LCP_CFG_MAGIC		0x0004	/* �}�W�b�N�ԍ�				*/
#define LCP_CFG_PCOMP		0x0008	/* �v���g�R�������k�@�\			*/
#define LCP_CFG_ACCOMP		0x0010	/* �A�h���X�E���䕔���k			*/
#define LCP_CFG_PAP		0x0020	/* PAP					*/
/*#define LCP_CFG_CHAP		0x0040	   CHAP �͎����\��			*/

#ifdef LCP_CFG_MAGIC

#define LCP_ECHO_INTERVAL	(20*NET_TIMER_HZ)	/* �C���^�[�o������		*/
#define LCP_ECHO_FAILS		9			/* ���s臒l			*/

#endif	/* of #ifdef LCP_CFG_MAGIC */

/*
 *  PPP�APAP �Ɋւ����`
 */

#define DEF_PAP_TIMEOUT		(3*NET_TIMER_HZ)
#define DEF_PAP_REQTIME		(30*NET_TIMER_HZ)	/* �^�C���A�E�g�������s���Ƃ��̓R�����g���O���B*/
#define MAX_PAP_REXMT		10			/* �F�ؗv���̍ő�đ���	*/

/*
 *  ARP �Ɋւ����`
 */

#define NUM_ARP_ENTRY		10			/* ARP �L���b�V���G���g����	*/
#define ARP_CACHE_KEEP		(20*60*NET_TIMER_HZ)	/* ARP �L���b�V���̃^�C���A�E�g	*/
#define TMO_ARP_GET_NET_BUF	1000	/* [ms]�A�A�h���X�����v���p net_buf �l���^�C���A�E�g*/
#define TMO_ARP_OUTPUT		1000	/* [ms]�A�A�h���X�����v���o�̓^�C���A�E�g	*/

/*
 *  DHCP �Ɋւ����`
 *
 *    �E����: TINET �́ADHCP ���������Ă��Ȃ��B���p�v���O�����ŁA
 *            DHCP ���b�Z�[�W����M���邽�߂̒�`�ł���B
 *            �܂��A���݂� IPv4 �̂ݗL���ł���B
 */

/*#define DHCP_CFG					 DHCP ����������ꍇ�̓R�����g���O���B*/

/*
 *  Ethernet �Ɋւ����`
 */

#define NUM_DTQ_ETHER_OUTPUT	2	/* Ethernet �o�̓f�[�^�L���[�T�C�Y	*/

#define	ETHER_INPUT_STACK_SIZE	1024	/* Ethernet ���̓^�X�N�̃X�^�b�N�T�C�Y	*/
#define	ETHER_OUTPUT_STACK_SIZE	1024	/* Ethernet �o�̓^�X�N�̃X�^�b�N�T�C�Y	*/

#define ETHER_INPUT_PRIORITY	5	/* Ethernet ���̓^�X�N�̗D��x		*/
#define ETHER_OUTPUT_PRIORITY	5	/* Ethernet �o�̓^�X�N�̗D��x		*/

/*#define ETHER_CFG_ACCEPT_ALL		 �}���`�L���X�g�A�G���[�t���[������M����Ƃ��̓R�����g���O���B	*/
/*#define ETHER_CFG_UNEXP_WARNING	 ��T�|�[�g�t���[���̌x����\������Ƃ��̓R�����g���O���B		*/
/*#define ETHER_CFG_802_WARNING		 IEEE 802.3 �t���[���̌x����\������Ƃ��̓R�����g���O���B		*/
/*#define ETHER_CFG_MCAST_WARNING	 �}���`�L���X�g�̌x����\������Ƃ��̓R�����g���O���B		*/

/*
 *  ���[�v�o�b�N�C���^�t�F�[�X�Ɋւ����`
 */

#define LOMTU			1500	/* ���[�v�o�b�N�� MTU			*/

#define NUM_DTQ_LOOP_INPUT	0	/* ���[�v�o�b�N���̓f�[�^�L���[�T�C�Y	*/
#define NUM_DTQ_LOOP_OUTPUT	0	/* ���[�v�o�b�N�o�̓f�[�^�L���[�T�C�Y	*/

#define	LOOP_INPUT_STACK_SIZE	1024	/* ���[�v�o�b�N���̓^�X�N�̃X�^�b�N�T�C�Y	*/
#define	LOOP_OUTPUT_STACK_SIZE	1024	/* ���[�v�o�b�N�o�̓^�X�N�̃X�^�b�N�T�C�Y	*/

#define LOOP_INPUT_PRIORITY	5	/* ���[�v�o�b�N���̓^�X�N�̗D��x		*/
#define LOOP_OUTPUT_PRIORITY	5	/* ���[�v�o�b�N�o�̓^�X�N�̗D��x		*/

/*
 *  �l�b�g���[�N�Ɋւ����`
 */

/* �l�b�g���[�N�^�C�}�^�X�N */

#define	NET_TIMER_STACK_SIZE	1024	/* �l�b�g���[�N�^�C�}�^�X�N�̃X�^�b�N�T�C�Y */
#define NET_TIMER_PRIORITY	5	/* �l�b�g���[�N�^�C�}�^�X�N�̗D��x */

#define NUM_NET_CALLOUT		10	/* �^�C���A�E�g�ďo�����A10 �ȏ�	*/

/* net_buf �� */

#ifdef SUPPORT_PPP

/*
 *  PPP �ł́A��M�p�� net_buf �� PDU (1502) �T�C�Y�����
 *  ���蓖�ĂȂ���΂Ȃ�Ȃ��̂� PDU �T�C�Y�𑽂߂Ɋm�ۂ���B
 *  128 �T�C�Y�� net_buf �́ATCP �Z�O�����g�p�ɑ��߂Ɋm�ۂ���B
 */

#define NUM_MPF_NET_BUF_128	2	/* net_buf ���A128�A2 �ȏ�	*/
#define NUM_MPF_NET_BUF_256	4	/* net_buf ���A256		*/
#define NUM_MPF_NET_BUF_512	1	/* net_buf ���A512		*/
#define NUM_MPF_NET_BUF_1024	1	/* net_buf ���A1024		*/
#define NUM_MPF_NET_BUF_IF_PDU	1	/* net_buf ���APDU		*/

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)

#ifndef NUM_MPF_NET_BUF_4096
#define NUM_MPF_NET_BUF_4096	2	/* net_buf ���A4096		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_4096 */

#endif	/* of #if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT) */

#endif	/* of #ifdef SUPPORT_PPP */

#ifdef SUPPORT_ETHER

/*
 *  �C�[�T�l�b�g�ł́A��M�p�� net_buf �́ANIC �̃o�b�t�@�ɂ���
 *  �t���[���������Ċ��蓖�Ă�΂悢�B
 *  TCP �̍ő�Z�O�����g�T�C�Y�� 1024 �I�N�e�b�g�� net_buf �ɒ�������ꍇ�́A
 *  ���̃T�C�Y�� net_buf �͑��߂Ɋm�ۂ���B
 *  128 �T�C�Y�� net_buf ���ATCP �̐���Z�O�����g�p�ɑ��߂Ɋm�ۂ���B
 */

#ifndef NUM_MPF_NET_BUF_128
#define NUM_MPF_NET_BUF_128	4	/* net_buf ���A128�A2 �ȏ�	*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_128 */

#ifndef NUM_MPF_NET_BUF_256
#define NUM_MPF_NET_BUF_256	2	/* net_buf ���A256		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_256 */

#ifndef NUM_MPF_NET_BUF_512
#define NUM_MPF_NET_BUF_512	2	/* net_buf ���A512		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_512 */

#ifndef NUM_MPF_NET_BUF_1024
#define NUM_MPF_NET_BUF_1024	2	/* net_buf ���A1024		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_1024 */

#ifndef NUM_MPF_NET_BUF_IF_PDU
#define NUM_MPF_NET_BUF_IF_PDU	4	/* net_buf ���APDU		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_IF_PDU */

#if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT)

#ifndef NUM_MPF_NET_BUF_4096
#define NUM_MPF_NET_BUF_4096	2	/* net_buf ���A4096		*/
#endif	/* of #ifndef NUM_MPF_NET_BUF_4096 */

#endif	/* of #if defined(SUPPORT_INET4) && defined(IP4_CFG_FRAGMENT) */

#endif	/* of #ifdef SUPPORT_ETHER */

#ifdef SUPPORT_LOOP

#define NUM_MPF_NET_BUF_128	2	/* net_buf ���A128�A2 �ȏ�	*/
#define NUM_MPF_NET_BUF_256	2	/* net_buf ���A256		*/
#define NUM_MPF_NET_BUF_512	2	/* net_buf ���A512		*/
#define NUM_MPF_NET_BUF_1024	2	/* net_buf ���A1024		*/
#define NUM_MPF_NET_BUF_IF_PDU	2	/* net_buf ���APDU		*/

#endif	/* of #ifdef SUPPORT_PPP */

/*
 *  �l�b�g���[�N���v���̌v��
 *
 *  �l�b�g���[�N���v���̌v�����s���ꍇ�́Atinet/include/net/net.h
 *  �Œ�`����Ă���v���g�R�����ʃt���O���w�肷��B
 */

#if 1

#ifdef SUPPORT_INET4

#define NET_COUNT_ENABLE	(0			\
				| PROTO_FLG_PPP_HDLC	\
				| PROTO_FLG_PPP_PAP	\
				| PROTO_FLG_PPP_LCP	\
				| PROTO_FLG_PPP_IPCP	\
				| PROTO_FLG_PPP		\
				| PROTO_FLG_LOOP	\
				| PROTO_FLG_ETHER_NIC	\
				| PROTO_FLG_ETHER	\
				| PROTO_FLG_ARP		\
				| PROTO_FLG_IP4		\
				| PROTO_FLG_ICMP4	\
				| PROTO_FLG_UDP		\
				| PROTO_FLG_TCP		\
				| PROTO_FLG_NET_BUF	\
				)

#endif	/* of #ifdef SUPPORT_INET4 */

#ifdef SUPPORT_INET6

#define NET_COUNT_ENABLE	(0			\
				| PROTO_FLG_PPP_HDLC	\
				| PROTO_FLG_PPP_PAP	\
				| PROTO_FLG_PPP_LCP	\
				| PROTO_FLG_PPP_IPCP	\
				| PROTO_FLG_PPP		\
				| PROTO_FLG_LOOP	\
				| PROTO_FLG_ETHER_NIC	\
				| PROTO_FLG_ETHER	\
				| PROTO_FLG_IP6		\
				| PROTO_FLG_ICMP6	\
				| PROTO_FLG_ND6		\
				| PROTO_FLG_UDP		\
				| PROTO_FLG_TCP		\
				| PROTO_FLG_NET_BUF	\
				)

#endif	/* of #ifdef SUPPORT_INET6 */

#else	/* of #if 0 */

#define NET_COUNT_ENABLE	(0			\
				)

#endif	/* of #if 0 */

#endif /* _TINET_CPU_CONFIG_H_ */
