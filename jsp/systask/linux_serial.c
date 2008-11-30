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
 *  @(#) $Id: linux_serial.c,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */

#define _LINX_SERIAL_

#include <t_services.h>
#include <s_services.h>
#include <signal.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#undef __USE_MISC 
#include <unistd.h>
#include <linux_sigio.h>
#include "kernel_id.h"


/*
 *  �V���A���|�[�g�̒჌�x����`
 */

typedef struct hardware_serial_port_descripter {
	char   *path;		            /* UNIX ��ł̃t�@�C���� */
	int	   fd;		                /* �t�@�C���f�B�X�N���v�^ */
	struct termios	current_term;	/* �[�������� */
	struct termios	saved_term;    
} HWPORT;

#define NUM_PORT	1

#define RAWPORT1	{ 0 }

/*
 *  UNIX ���x���̃|�[�g������/�V���b�g�_�E������
 *
 *  ���݂̎����ł́C�[�����g���P�[�X�����l���Ă��Ȃ��D�{���́Copen ��
 *  ���̂��[�����ǂ����ŏ�����ς���ׂ��D
 */

Inline void
hw_port_initialize(HWPORT *p)
{
	if (p->path) {
		p->fd = open(p->path, O_RDWR|O_NDELAY);
	}
	else {
		p->fd = 0;			/* �W�����o�͂��g�� */
	}
	fcntl(p->fd, F_SETOWN, getpid());
	fcntl(p->fd, F_SETFL, FASYNC|FNDELAY);
    
    
    tcgetattr(p->fd, &(p->saved_term));
    
	p->current_term = p->saved_term;
    p->current_term.c_lflag &= ~(ECHO);
    p->current_term.c_lflag &= ~(ICANON);
    p->current_term.c_cc[VMIN] = 1;
    p->current_term.c_cc[VTIME] = 0;
    
    tcsetattr(p->fd, TCSAFLUSH, &(p->current_term));
}

Inline void
hw_port_terminate(HWPORT *p)
{
    tcsetattr(p->fd, TCSAFLUSH, &(p->saved_term));
	fcntl(p->fd, F_SETFL, 0);
	if (p->path) {
		close(p->fd);
	}
}


/*
 *  �V���A���C���^�t�F�[�X�h���C�o�p�� SIGIO �ʒm�C�x���g�u���b�N
 */

static SIGIOEB	serial_sigioeb;


/*
 *  �V���A���|�[�g�Ǘ��u���b�N�̒�`
 */

typedef struct ioctl_descripter {
	int	echo;
	int	input;
	int	newline;
	int	flowc;
} IOCTL;

#define	SERIAL_BUFSZ	256	/* �V���A���C���^�t�F�[�X�p�o�b�t�@�̃T�C�Y */

#define	inc(x)		(((x)+1 < SERIAL_BUFSZ) ? (x)+1 : 0)
#define	INC(x)		((x) = inc(x))


typedef struct serial_port_control_block {
	BOOL	init_flag;	/* �������ς��H */
	HWPORT	hwport;		/* �n�[�h�E�F�A�ˑ���� */
	ID	in_semid;	/* ��M�o�b�t�@�Ǘ��p�Z�}�t�H�� ID */
	ID	out_semid;	/* ���M�o�b�t�@�Ǘ��p�Z�}�t�H�� ID */

	int	in_read_ptr;	/* ��M�o�b�t�@�ǂݏo���|�C���^ */
	int	in_write_ptr;	/* ��M�o�b�t�@�������݃|�C���^ */
	int	out_read_ptr;	/* ���M�o�b�t�@�ǂݏo���|�C���^ */
	int	out_write_ptr;	/* ���M�o�b�t�@�������݃|�C���^ */
	UINT	ioctl;		/* ioctl �ɂ��ݒ���e */
	BOOL	send_enabled;	/* ���M���C�l�[�u�����Ă��邩�H */
	BOOL	ixon_stopped;	/* STOP ���󂯎������Ԃ��H */
	BOOL	ixoff_stopped;	/* ����� STOP �𑗂�����Ԃ��H */
	char	ixoff_send;	/* ����� START/STOP �𑗂邩�H */

	char	in_buffer[SERIAL_BUFSZ];	/* ��M�o�b�t�@�G���A */
	char	out_buffer[SERIAL_BUFSZ];	/* ��M�o�b�t�@�G���A */
} SPCB;


#define	IN_BUFFER_EMPTY(spcb) \
		((spcb)->in_read_ptr == (spcb)->in_write_ptr)
#define	IN_BUFFER_FULL(spcb) \
		((spcb)->in_read_ptr == inc((spcb)->in_write_ptr))
#define	OUT_BUFFER_FULL(spcb) \
		((spcb)->out_read_ptr == inc((spcb)->out_write_ptr))

/*
 *  ���W���[�����Ŏg���֐�
 */
static void	sigint_handler();
static BOOL	serial_getc(SPCB *spcb, char *c);
static BOOL	serial_putc(SPCB *spcb, char c);


/*
 *  �V���A���|�[�g�Ǘ��u���b�N�̒�`�Ə�����
 */

static SPCB spcb_table[NUM_PORT] = {
    {0, RAWPORT1, SEM_SERIAL1_IN, SEM_SERIAL1_OUT }
};

#define get_spcb(portid)	(&(spcb_table[(portid)-1]))
#define get_spcb_def(portid)	get_spcb((portid) ? (portid) : CONSOLE_PORTID)


/*
 *  �|�[�g�̏�����
 */
int
serial_opn_por(ID portid)
{

    SPCB	*spcb;
	ER	ercd = E_OK;;

	if (!(1 <= portid && portid <= NUM_PORT)) {
		return(E_PAR);
	}
	spcb = get_spcb(portid);

	/*
	 *  �����̃^�X�N�������� serial_open ���Ăԏ󋵂ɂ͑Ή����Ă�
	 *  �Ȃ��D
	 */
	if (spcb->init_flag) {		/* �������ς��̃`�F�b�N */
		return(E_OK);
	}

	/*
	 *  �ϐ��̏�����
	 */
	spcb->in_read_ptr = spcb->in_write_ptr = 0;
	spcb->out_read_ptr = spcb->out_write_ptr = 0;
	spcb->ixon_stopped = spcb->ixoff_stopped = FALSE;
	spcb->ixoff_send = 0;

	/*
	 *  �n�[�h�E�F�A�ˑ��̏�����
	 */
	hw_port_initialize(&(spcb->hwport));
        
	/*
 	 *  �v���Z�X���I��������V�O�i����߂܂���
         *  sigaction()�ŏ������������������̂�?
	 */
	signal(SIGHUP, sigint_handler);
	signal(SIGINT, sigint_handler);
	signal(SIGTERM, sigint_handler);
        
    spcb->init_flag = TRUE;
	spcb->send_enabled = FALSE;
	return(ercd);
}

/*
 *  �|�[�g�̃V���b�g�_�E��
 */

ER
serial_cls_por(ID portid)
{
	SPCB	*spcb;

	if (!(1 <= portid && portid <= NUM_PORT)) {
		return(E_PAR);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	spcb = get_spcb(portid);
	if (!(spcb->init_flag)) {	/* �������ς��̃`�F�b�N */
		return(E_OBJ);
	}

	/*
	 *  �n�[�h�E�F�A�ˑ��̃V���b�g�_�E������
	 */
	syscall(loc_cpu());
	hw_port_terminate(&(spcb->hwport));
	syscall(unl_cpu());

	spcb->init_flag = FALSE;
	return(E_OK);
}

/*
 *  �v���Z�X���I��������V�O�i���ɑ΂���n���h��
 */
void
sigint_handler()
{
	SPCB	*spcb;
	int	i;

	for (i = 1; i <= NUM_PORT; i++) {
		spcb = get_spcb(i);
		if (spcb->init_flag) {
			hw_port_terminate(&(spcb->hwport));
		}
	}
	exit(0);
}

/*
 *  �t���[�R���g���[���֌W�̒�`
 */
#define	STOP	'\023'		/* Control-S */
#define	START	'\021'		/* Control-Q */

#define	IXOFF_STOP	64	/* buffer area size to send STOP */
#define	IXOFF_START	128	/* buffer area size to send START */

#define	in_buf_area(p)							\
		((spcb->in_read_ptr >= spcb->in_write_ptr) ?		\
		 (spcb->in_read_ptr - spcb->in_write_ptr) :		\
		 (spcb->in_read_ptr + SERIAL_BUFSZ - spcb->in_write_ptr))
/*
 *  ���[�e�B���e�B���[�`��
 */

Inline BOOL
read_char(SPCB *spcb, char *c)
{
	int	n;

	if ((n = read(spcb->hwport.fd, c, 1)) == 1) {
		return(1);
	}
	assert(n < 0 && errno == EWOULDBLOCK);
	return(0);
}

Inline BOOL
write_char(SPCB *spcb, char c)
{
	int	n;

	if ((n = write(spcb->hwport.fd, &c, 1)) == 1) {
		return(1);
	}
	assert(n < 0 && errno == EWOULDBLOCK);
	return(0);
}

/*
 *  �V���A���|�[�g����̎�M
 */

static BOOL
serial_getc(SPCB *spcb, char *c)
{
	BOOL	buffer_empty;

	syscall(loc_cpu());
	*c = spcb->in_buffer[spcb->in_read_ptr];
        if (inc(spcb->in_write_ptr) == spcb->in_read_ptr) {
            /*
             *  �o�b�t�@�t����Ԃ��������ꂽ��A���荞�݂��������̂�
             *  �����U�镑����������B
             */
            kill(getpid(), SIGIO);
        }
        
	INC(spcb->in_read_ptr);

	if (spcb->ixoff_stopped && (in_buf_area(spcb) > IXOFF_START)) {
		if (!write_char(spcb, START)) {
			spcb->ixoff_send = START;
		}
		spcb->ixoff_stopped = FALSE;
	}
	buffer_empty = IN_BUFFER_EMPTY(spcb);
	syscall(unl_cpu());
	return(buffer_empty);
}

ER_UINT
serial_rea_dat(ID portid, char *buf, UINT len)
{
    	SPCB	*spcb;
	BOOL	buffer_empty;
	char	c;
	int	i;


	if (sns_dpn()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(0 <= portid && portid <= NUM_PORT)) {
		return(E_PAR);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	spcb = get_spcb_def(portid);
	if (!(spcb->init_flag)) {	/* �������ς��̃`�F�b�N */
		return(E_OBJ);
	}
	if (len == 0) {
		return(len);
	}


	syscall(wai_sem(spcb->in_semid));
	buffer_empty = FALSE;
	for (i = 0; i < len; i++) {
		buffer_empty = serial_getc(spcb, &c);
        if ((spcb->ioctl & IOCTL_ECHO) != 0) {
			syscall(wai_sem(spcb->out_semid));
			if (!serial_putc(spcb, c)) {
				syscall(sig_sem(spcb->out_semid));
			}
		}
		*buf++ = c;
		if (buffer_empty && i < len - 1) {
			syscall(wai_sem(spcb->in_semid));
		}
	}
	if (!buffer_empty) {
		syscall(sig_sem(spcb->in_semid));
	}
	return(len);
}


/*
 * �V���A���|�[�g�ւ̑��M
 */

static BOOL
serial_putc(SPCB *spcb, char c)
{
	BOOL	buffer_full;

    if (c == '\n' && (spcb->ioctl & IOCTL_CRLF) != 0) {
		if (serial_putc(spcb, '\r')) {
			syscall(wai_sem(spcb->out_semid));
		}
	}

	syscall(loc_cpu());
	if (!(spcb->ixon_stopped) && write_char(spcb, c)) {
		buffer_full = FALSE;
	}
	else {
		spcb->out_buffer[spcb->out_write_ptr] = c;
		INC(spcb->out_write_ptr);
		buffer_full = OUT_BUFFER_FULL(spcb);
	}
	syscall(unl_cpu());
	return(buffer_full);
}

ER_UINT
serial_wri_dat(ID portid, char *buf, UINT len)
{
	SPCB	*spcb;
	BOOL	buffer_full;
	int	i;

	if (sns_dpn()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(0 <= portid && portid <= NUM_PORT)) {
		return(E_PAR);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	spcb = get_spcb_def(portid);
	if (!(spcb->init_flag)) {	/* �������ς��̃`�F�b�N */
		return(E_OBJ);
	}

	syscall(wai_sem(spcb->out_semid));
	buffer_full = FALSE;
	for (i = 0; i < len; i++) {
		buffer_full = serial_putc(spcb, *buf++);
		if (buffer_full && i < len - 1) {
			syscall(wai_sem(spcb->out_semid));
		}
	}
	if (!buffer_full) {
		syscall(sig_sem(spcb->out_semid));
	}
	return(len);
}

/*
 *  �V���A���|�[�g�̐���
 */

int
serial_ctl_por(ID portid, UINT ioctl)
{
	SPCB	*spcb;

	if (sns_ctx()) {		/* �R���e�L�X�g�̃`�F�b�N */
		return(E_CTX);
	}
	if (!(0 <= portid && portid <= NUM_PORT)) {
		return(E_PAR);		/* �|�[�g�ԍ��̃`�F�b�N */
	}

	spcb = get_spcb_def(portid);
	if (!(spcb->init_flag)) {	/* �������ς��̃`�F�b�N */
		return(E_OBJ);
	}

    spcb->ioctl = ioctl;
    return(E_OK);
}


/*
 *  �V���A���|�[�g�����݃n���h��
 */

static BOOL
serial_int_handler(ID portid)
{
	SPCB	*spcb;
	BOOL	flag;
	char	c;

	spcb = get_spcb(portid);
	flag = 0;

	/*
	 *  1������M����
	 *
	 *  �܂��C�o�b�t�@�t���łȂ��ꍇ�ɁC1�����ǂ�ł݂�D�ǂ߂�΁C
	 *  ����ɉ������������s���D
	 */
	if (inc(spcb->in_write_ptr) != spcb->in_read_ptr
            && read_char(spcb, &c)) {
		if ((spcb->ioctl & IOCTL_FCSND) != 0 && c == STOP) {
			spcb->ixon_stopped = TRUE;
		}
        else if (((spcb->ioctl & IOCTL_FCSND) != 0 || spcb->ixon_stopped)
                                 && (c == START || (spcb->ioctl & IOCTL_FCANY) != 0)) {
			spcb->ixon_stopped = FALSE;
		}
		else {
			spcb->in_buffer[spcb->in_write_ptr] = c;
                        if(spcb->in_read_ptr == spcb->in_write_ptr){
                            syscall(sig_sem(spcb->in_semid));
                        }
                        
			INC(spcb->in_write_ptr);
                        
			if ((spcb->ioctl & IOCTL_FCRCV) != 0 && !(spcb->ixoff_stopped)
					&& (in_buf_area(p) < IXOFF_STOP)) {
				spcb->ixoff_stopped = TRUE;
				spcb->ixoff_send = STOP;
			}
		}
		flag = 1;
	}

	/*
	 *  1�������M����
	 */
	if (spcb->ixoff_send) {
		if (write_char(spcb, spcb->ixoff_send)) {
			spcb->ixoff_send = 0;
			flag = 1;
		}
	}
	else if (!(spcb->ixon_stopped)
                      && spcb->out_read_ptr != spcb->out_write_ptr) {
		if (write_char(spcb, spcb->out_buffer[spcb->out_read_ptr])) {
                    if(OUT_BUFFER_FULL(spcb)){
			syscall(sig_sem(spcb->out_semid));
                    }
                    INC(spcb->out_read_ptr);                        
                    flag = 1;
		}
	}
	return(flag);
}



/*
 *  SIGIO �R�[���o�b�N���[�`��
 */

static BOOL
serial_sigio_callback(VP arg)
{
	BOOL	flag;

	do {
//		syscall(loc_cpu());
		flag = serial_int_handler(1);
//		syscall(unl_cpu());
	} while (flag);
	return(0);
}



/*
 *  �V���A���C���^�t�F�[�X�h���C�o�̋N��
 */

void
serial_initialize(VP_INT exinf)
{
	serial_sigioeb.callback = serial_sigio_callback;
	serial_sigioeb.arg = (VP) 0;
	syscall(enqueue_sigioeb_initialize(&serial_sigioeb));
}
