/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RIOCH COMPANY,LTD. JAPAN
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
 *  @(#) $Id: tlcs900offset.cpp,v 1.1 2008/06/17 00:04:55 suikan Exp $
 */
// tlcs900offset.cpp : �R���\�[�� �A�v���P�[�V�����p�̃G���g�� �|�C���g�̒�`
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BUF_SIZE		512
#define	STR_SIZE		128
#define BIT_SIZE		6

#define	NORMAL_STATE	0
#define	TEXPTN_STATE	1
#define	SP_STATE		2
#define	PC_STATE		3
#define	ENATEX_STATE	4


static char const default_input_file[] = "makeoffset.asm";
static char const default_output_file[] = "offset.inc";
static char const lf[] = "\n";

static char input_file[STR_SIZE];
static char output_file[STR_SIZE];

/*
���̓t�@�C����BEGIN, END�̋�Ԃł���ꍇ��
offset_state = NORMAL_STATE;
*/
static int  offset_state = NORMAL_STATE;

static bool test_string(char** s, char const * t);
static bool skip_space(char** s);
static bool skip_char(char** s, char const c);

unsigned int atoh(char* s);
void get_num(char* s);
void get_num_undo(char* s);

int main(int argc, char* argv[]){
	FILE* pfo;
	FILE* pfi;
	int nCnt, address;
	int shift_bit = 1;
	int shift_cnt = 0;

	char* s;
	char  str[100];

	char  buf[BUF_SIZE];
	char  c;

	strcpy(input_file, default_input_file);
	strcpy(output_file, default_output_file);

	//�R�}���h���C�����͂����
	for(nCnt = 1 ; nCnt < argc ; nCnt++){
		s = argv[nCnt];
		if(*s++ == '-'){
			c = *s;
			while(*s != 0){
				if(*s == ':')
					break;
				s++;
			}
			if(*s++ == ':'){
				switch(c){
				//output file name
				case 'O':		
				case 'o':
					strcpy(output_file, s);
					break;
				//input file name
				case 'R':
				case 'r':
					strcpy(input_file, s);
					break;
				default:
					printf("tlcs900offset -R:input_file -O:output_file\n");
					break;
				}
			}
		}
	}
	//input, output�t�@�C�����̕W���o��
	printf("input file   = %s\n", input_file);
	printf("output file  = %s\n", output_file);

	if((pfi = fopen(input_file, "r")) == NULL){
		fprintf(stderr, "can't open input file!");
		exit(1);
	}
	if((pfo = fopen(output_file, "w")) == NULL){
		fclose(pfi);
		fprintf(stderr, "can't open output file!");
		exit(1);
	}

	//input�t�@�C���̎�荞��
	for(;;){
		if((fgets(buf, BUF_SIZE, pfi)) == NULL)
			break;
		s = buf;
		switch(offset_state){
		//; BEGIN TCB_texptn�͈̔͂̉��
		case TEXPTN_STATE:
			if(test_string(&s, "; END")){
				offset_state = NORMAL_STATE;
				continue;
			}

			if(test_string(&s, "line") || test_string(&s, "call"))
				continue;

			if(skip_char(&s, 'x')){
				continue;
			}

			get_num(s);
			address = atoh(s);
			printf("TCB_texptn\tequ\t%d\n",address);
			fputs("TCB_texptn\t\tequ\t", pfo);
			sprintf(str,"%d",address);
			fputs(str, pfo);
			fputs(lf, pfo);
			break;

		case SP_STATE:
		//; BEGIN TCB_sp�͈̔͂̉��
			if(test_string(&s, "; END")){
				offset_state = NORMAL_STATE;
				continue;
			}

			if(test_string(&s, "line") || test_string(&s, "call") )
				continue;

			if(skip_space(&s))
				continue;

			if(skip_char(&s, '(')){
				continue;
			}

			if(skip_char(&s, 'x')){
				continue;
			}

			get_num(s);
			address = atoh(s);
			printf("TCB_sp\t\tequ\t%d\n",address);
			fputs("TCB_sp\t\t\tequ\t", pfo);
			sprintf(str,"%d",address);
			fputs(str, pfo);
			fputs(lf, pfo);

			break;

		case PC_STATE:
		//; BEGIN TCB_pc�͈̔͂̉��
			if(test_string(&s, "; END")){
				offset_state = NORMAL_STATE;
				continue;
			}

			if(test_string(&s, "line") || test_string(&s, "call"))
				continue;

			if(skip_char(&s, 'x')){
				continue;
			}
			get_num(s);
			address = atoh(s);
			printf("TCB_pc\tequ\t%d\n",address);
			fputs("TCB_pc\t\t\tequ\t", pfo);
			sprintf(str,"%d",address);
			fputs(str, pfo);
			fputs(lf, pfo);
			break;

		case ENATEX_STATE:
		//; BEGIN TCB_pc�͈̔͂̉��
			if(test_string(&s, "; END")){
				offset_state = NORMAL_STATE;
				continue;
			}

			if(test_string(&s, "line") || test_string(&s, "call"))
				continue;

			if(skip_char(&s, 'x')){
				continue;
			}
			get_num(s);
			address = atoh(s);
			printf("TCB_enatex\tequ\t%d\n",address);
			fputs("TCB_enatex\t\tequ\t", pfo);
			sprintf(str,"%d",address);
			fputs(str, pfo);
			fputs(lf, pfo);
			get_num_undo(s);
			if(skip_char(&s, ',')){
				continue;
			}

			*(s + BIT_SIZE) = '\0';
			printf("TCB_enatex_mask\tequ\t%s\n",s);
			fputs("TCB_enatex_mask\tequ\t", pfo);
			fputs(s, pfo);
			fputs(lf, pfo);

			if(skip_char(&s, 'x')){
				continue;
			}

			address = atoh(s);

			for(shift_cnt=0;shift_cnt<=16;shift_cnt++){
				if(address == shift_bit){
					printf("TCB_enatex_bit\tequ\t%d\n",shift_cnt);
					fputs("TCB_enatex_bit\tequ\t", pfo);
					sprintf(str,"%d",shift_cnt);
					fputs(str, pfo);
					fputs(lf, pfo);
				}
				shift_bit<<=1;
			}

			break;

		default:
			if(test_string(&s, "; BEGIN TCB_texptn")){
				offset_state = TEXPTN_STATE;
				continue;
			}else if(test_string(&s, "; BEGIN TCB_sp")){
				offset_state = SP_STATE;
				continue;
			}else if(test_string(&s, "; BEGIN TCB_pc")){
				offset_state = PC_STATE;
				continue;
			}else if(test_string(&s, "; BEGIN TCB_enatex")){
				offset_state = ENATEX_STATE;
				continue;
			}

			break;
		}
	}
	return 0;
}

/*
 * 16�i�������int�^�ɕϊ�
 */
unsigned int atoh(char* s)
{
	int nCnt = 0;
	for(;;){
		if(*s >= '0' && *s <= '9')
			nCnt = (nCnt * 16) + (*s - '0');
		else if(*s >= 'A' && *s <= 'F')
			nCnt = (nCnt * 16) + (*s - 'A' + 10);
		else if(*s >= 'a' && *s <= 'f')
			nCnt = (nCnt * 16) + (*s - 'a' + 10);
		else
			break;
		s++;
	}
	return nCnt;
}
/*
 * �A�h���X�����𒊏o
 */
void get_num(char* s)
{
	int nCnt;

	for(nCnt = 0 ; nCnt < 4 ; nCnt++){
		if(*(s+nCnt) == ')'){
			*(s+nCnt) = '\0';
		}
	}
}

/*
 * get_num�ŏ������������������ɖ߂�
 */
void get_num_undo(char* s)
{
	int nCnt;

	for(nCnt = 0 ; nCnt < 4 ; nCnt++){
		if(*(s+nCnt) == '\0'){
			*(s+nCnt) = ')';
		}
	}
}


/*
 * ��������r���ē���Ȃ��TURE
 */
static bool test_string(char** s, char const *t)
{
	char*  p;
	char   c;

	p = *s;
	while(*p <= ' '){
		if(*p == 0)
			return false;
		p++;
	}
	while((c = *p++) != 0){
		if(c != *t++)
			break;
		if(*t == 0){
			*s = p;
			return true;
		}
	}
	return false;
}

/*
 * �w��̃L�����N�^�܂ŃX�L�b�v
 */
static bool skip_char(char** s, char const c)
{
	char* p;

	p = *s;
	while(*p != c){
		if(*p == 0)
			break;
		p++;
	}
	if(*p){
		p++;
		*s = p;
		return false;
	}
	else{
		*s = p;
		return true;
	}
}

/*
 * �X�y�[�X�܂��̓^�u���X�L�b�v����
 */
static bool skip_space(char** s)
{
	char* p;

	p = *s;
	while(*p <= ' '){
		if(*p == 0)
			break;
		p++;
	}
	*s = p;
	if(*p)
		return false;
	else
		return true;
}
