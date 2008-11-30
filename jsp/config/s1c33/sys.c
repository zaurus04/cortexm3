/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 *
 *  Additional routine
 *
 *  Copyright (C) 2003 by SEIKO EPSON Corp, JAPAN
 *
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă���
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
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
 */

#include "cpu_rename.h"

unsigned char WRITE_BUF[65];

/* buffer for simulated stdin, WRITE_BUF[0] is size (1-0x40, 0 means no data)
   WRITE_BUF[1-64] is buffer area for data, max 64 bytes
   used in write () */

unsigned char READ_BUF[65];

/* buffer for simulated stdin, READ_BUF[0] is size (1-0x40, 0 means EOF)
   READ_BUF[1-64] is buffer area for data, max 64 bytes
   used in read() */

static unsigned char READ_EOF; /* if 1: READ_BUFFER become EOF, 0: not EOF */

/*
 *  void _exit
 *	_exit execute inifinity loop.
 */

void _exit()
{
LOOP:
	goto LOOP;
}

/*
 *  void _init_sys
 *	_init_sys initialize read() and write() bffer area
 */

void init_sys()
{
	READ_EOF = 0;		/* not EOF */
	READ_BUF[0] = 0;	/* BUFFER is empty */
}

/*
 *  read
 *	Read() get and return required bytes with using simulated input.
 *	If EOF return 0.
 *	READ_FLASH: is break point label for stdin
 *	READ_BUF is buffer area for stdin
 */

int read (int fhDummy, char *psReadBuf, int iReadBytes)
{
	int iBytes;		/* data size written to psReadBuf */
	int iSize;		/* data size in READ_BUF */
	char *psBuf;		/* top of read buffer */
	static int iNdxPos;	/* current positon in READ_BUF*/

/* start */

	iBytes = 0;		/* no read now */
	psBuf = psReadBuf;

/* This loop repeat for each byte to copy READ_BUF to psReadBuf */

	for (;;)
	    {

/* if iReadByte become 0, return */

		if (iReadBytes == 0)	/* if required size become 0, return */
			return(iBytes);

/* if EOF, return 0 */

		if (READ_EOF == 1)
			return(iBytes);

/* if there is data, copy 1 byte */

		iSize = READ_BUF[0];
		if (iSize > 0 )
		    {
		    	*psBuf = READ_BUF[iNdxPos];
		    	psBuf++;
		    	iReadBytes--;
		    	iNdxPos++;
		    	iSize--;
			iBytes++;
		    	READ_BUF[0] = (unsigned char)(iSize & 0xff);
		    }

/* if no data, read 0-64 bytes from simulated input */

		else
		    {
			asm(".global READ_FLASH");
			asm("READ_FLASH:");	/* label for simulated stdin */
			if (READ_BUF[0] == 0)
				READ_EOF = 1;	/* if size is 0, EOF */
		    	iNdxPos = 1;	/* reset index position */
		    }
	    } /* back to for (;;) */
}

/*
 *  write
 *	write datas with using simulated stdout
 *	WRITE_FLASH: is break point label for stdout
 *      WRITE_BUF is buffer area for stdout
 */

int write (int fhDummy, char *psWriBuf, int iWriBytes)
{
	int iBytes;	/* remain data bytes waiting WRITE_BUF */
	int iSize;	/* data size to write to WRITE_BUF */
	int iCount;	/* counter to copy data to WRITE_BUF */

	iBytes = iWriBytes;

	for (;;){				/* repeat each 255 bytes */

/* if remain 0, return original size */

	if (iBytes == 0)		/* remain size become 0, so return */
		return(iWriBytes);

/* if remain > 64, write size is 64 */

	if (iBytes > 64)
	{				/* over 64 */
		iSize = 64;				/* 64 bytes to WRITE_BUF */
		iBytes = iBytes - 64;	/* remain data */
	}
	else
	{						/* not over 64 */
		iSize = iBytes;		/* under 64 bytes to WRITE_BUF */
		iBytes = 0;			/* no remain data */
	}

/* copy psWriBuf to WRITE_BUF */

	WRITE_BUF[0] = (unsigned char)(iSize & 0xff);	/* set size */
	for (iCount = 1 ; iCount <= iSize ; iCount++)
	{
		WRITE_BUF[iCount] = *psWriBuf;		/* copy data */
		psWriBuf++;
	}
	asm(".global WRITE_FLASH");
	asm("WRITE_FLASH:");		/* label for simulated stdout */

    }	/* back to for (;;) */

	return(iSize);
}

