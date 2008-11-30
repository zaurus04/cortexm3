/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 Takagi Nobuhisa
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
 *  @(#) $Id: cxx_sample2.cpp,v 1.1 2008/06/17 00:04:35 suikan Exp $
 */

/*
 *  C++�T���v���v���O����(2)�̖{��
 *
 *  ���̃T���v���v���O�����́u�N�w�҂̐H���v���x�[�X�Ƃ��āAC++�̊e�@�\
 *  �̃f�����s���Ă���B
 *  5�l�̓N�w�҂����E�̃t�H�[�N�����ہA�̈ӂɃf�b�h���b�N�𔭐������A
 *  �^�C���A�E�g�����o�������_��C++�̗�O�𑗏o���Ă���B
 *
 *  ���쒆��'q'����͂���Ɠ�����~���邱�Ƃ��ł��Arestart? [y|n]�ɑ�
 *  ����'y'����͂���΍ċN���A'n'����͂���ΏI������B
 *  �܂��A���쒆��'a'����͂���΃A�{�[�g����B
 */

#include <t_services.h>
#include <cstdlib>
#include <new>
#include "kernel_id.h"
#include "cxx_sample2.h"

//	��}���`�^�X�N�e�X�g�N���X
//	�ÓI�I�u�W�F�N�g�̃R���X�g���N�^�ƃf�X�g���N�^�̓���T���v��
class non_multitask_test
{
	int* x_;
public:
	non_multitask_test()
		: x_(new int(12345))	// �J�[�l���񓮍��Ԃł�new���Z�q
	{
	}
	~non_multitask_test()
	{
		if (*x_== 12345)
			syslog(LOG_NOTICE,"non-multitask test succeeded");
		else
			syslog(LOG_NOTICE,"non-multitask test failed");
		delete x_;				// �J�[�l���񓮍��Ԃł�delete���Z�q
		x_ = 0;
	}
} test;

class timeout_error
{
};

// �[������
int rnd()
{
	static unsigned int seed = 1;
	loc_cpu();
	seed = seed * 1566083941UL + 1;
	unl_cpu();
	return (seed >> 16) % 0x7fff;
}

//	�t�H�[�N�N���X
class fork
{
	ID semid_;
	bool used_;
public:
	explicit fork(int semid)
		: semid_(semid), used_(false)
	{
	}
	~fork()
	{
		if (used_)
			give();
	}
	ID id() const { return semid_; }
	bool is_used() const { return used_; }
	void take()
	{
		if (twai_sem(semid_, 500*5) == E_TMOUT)
			throw timeout_error();
		used_ = true;
	}
	void give()
	{
		used_ = false;
		sig_sem(semid_);
	}
};

fork* p_fork[5];

//	�N�w�҃N���X
class philosopher
{
	ID		tskid_;
	fork* left_;
	fork* right_;
public:
	explicit philosopher(int tskid, fork* left, fork* right)
		: tskid_(tskid),
			left_(left), right_(right)
	{
		syslog(LOG_NOTICE,"philosofer #%d", tskid);
	}
	void think()
	{
		syslog(LOG_NOTICE, "#%d thinking...", tskid_);
		dly_tsk(100 * (rnd() % 5 + 1));
	}
	void eat()
	{
		syslog(LOG_NOTICE, "#%d eat up", tskid_);
		dly_tsk(100 * (rnd() % 5 + 1));
	}
	void run()
	{
		for (;;)
		{
			try
			{
				//	�Ӑ}�I�Ƀf�b�h���b�N�𔭐�������B
				left_->take();
				syslog(LOG_NOTICE, "#%d take left fork(%d)", tskid_, left_->id());

				dly_tsk(100 * (rnd() % 5 + 1));

				right_->take();
				syslog(LOG_NOTICE, "#%d take right fork(%d)", tskid_, right_->id());

				eat();

				left_->give();
				syslog(LOG_NOTICE, "#%d give left fork(%d)", tskid_, left_->id());
				right_->give();
				syslog(LOG_NOTICE, "#%d give right fork(%d)", tskid_, right_->id());
				think();
			}
			catch (timeout_error&)
			{
				//	�^�C���A�E�g�ɂ��f�b�h���b�N�����o����ƁA�t�H�[�N������B
				syslog(LOG_NOTICE, "#%d !!!! timeout error !!!!", tskid_);
				if (left_->is_used())
				{
					left_->give();
					syslog(LOG_NOTICE, "#%d give left fork(%d)", tskid_, left_->id());
				}
				if (right_->is_used())
				{
					right_->give();
					syslog(LOG_NOTICE, "#%d give right fork(%d)", tskid_, right_->id());
				}
				rot_rdq(TPRI_SELF);
			}
		}
	}
};

void task(VP_INT exinf)
{
	_toppers_cxxrt_reset_specific();	// �^�X�N�̍ċN�����\�ɂ��邽�߂̏���������
	ID		tskid = ID(exinf);
	fork* left	= p_fork[(tskid - 1) % 5];
	fork* right = p_fork[(tskid - 1 + 4) % 5];
	philosopher phil(tskid, left, right);
	phil.run();
}

//	std::atexit�œo�^����I�����֐�
void finish()
{
	syslog(LOG_NOTICE, "finish");
}


//	���C���^�X�N
void main_task(VP_INT exinf)
{
	serial_ctl_por(TASK_PORTID, (IOCTL_CRLF | IOCTL_FCSND | IOCTL_FCRCV));
	syslog(LOG_NOTICE,"Sample program starts (exinf = %d)", exinf);

	std::atexit(finish);

	try
	{
		for (;;)
		{
			for (ID semid = 1; semid <= 5; semid++)
				p_fork[semid - 1] = new fork(semid);

			for (ID tskid = 1; tskid <= 5; tskid++)
				act_tsk(tskid);

			char c;
			do
			{
				serial_rea_dat(TASK_PORTID, &c, 1);
				if (c == 'a')
					std::abort();
			} while (c != 'q' && c != 'Q');

			for (ID tskid = 1; tskid <= 5; tskid++)
			{
				ter_tsk(tskid);
			}

			for (ID semid = 1; semid <= 5; semid++)
			{
				delete p_fork[semid - 1];
				p_fork[semid - 1] = 0;
			}

			do
			{
				syslog(LOG_NOTICE, "restart? [y|n] ");
				serial_rea_dat(TASK_PORTID, &c, 1);
			} while (c != 'y' && c != 'n');

			if (c == 'n')
				break;
		}

		syslog(LOG_NOTICE, "multitask test succeeded");
	}
	catch (std::bad_alloc&)
	{
		syslog(LOG_NOTICE, "multitask test failed");
	}

	std::exit(0);
}

