/*
 *  TOPPERS/JSP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003-2004 by Ryosuke Takeuchi
 *              Platform Development Center RIOCH COMPANY,LTD. JAPAN
 *  Copyright (C) 2007 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
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
 *  @(#) $Id: m16coffset.cpp,v 1.1 2008/06/17 00:04:45 suikan Exp $
 */
// m16coffset.cpp : �R���\�[�� �A�v���P�[�V�����p�̃G���g�� �|�C���g�̒�`
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define	BUF_SIZE		512
#define	STR_SIZE		128

#define	NORMAL_STATE	0
#define	CHECK_STATE		1

struct OFF {
	int		bit;
	int		offset;
	int 	check_type; /* OFF=0 or BIT=1 */
	char	label[STR_SIZE];
	char	mask[STR_SIZE];
};

static char const version[] = "02.00";
static char const default_input_file[] = "makeoffset.a30";
static char const default_output_file[] = "offset.inc";

static char input_file[STR_SIZE];
static char output_file[STR_SIZE];
static int  num_offset = 0;
static int  offset_state = NORMAL_STATE;
static struct OFF off_table[20];

static bool test_string(char** s, char const * t);
static bool skip_space(char** s);

int main(int argc, char* argv[])
{
	FILE* pfo;
	FILE* pfi;
	struct OFF *v = NULL;
	char* s;
	char* p;
	char  buf[BUF_SIZE];
	char  c;
	int i;
	int val;
	int ofs = 0;
	char ct[4]; /* "BIT" or "OFF" */

	strcpy(input_file, default_input_file);
	strcpy(output_file, default_output_file);

	for(i = 1 ; i < argc ; i++){
		s = argv[i];
		if(*s++ == '-'){
			c = *s;
			while(*s != 0){
				if(*s == ':')
					break;
				s++;
			}
			if(*s++ == ':'){
				switch(c){
				case 'O':		// �A�E�g�v�b�g�t�@�C���̐ݒ�
				case 'o':
					strcpy(output_file, s);
					break;
				case 'R':		// �C���v�b�g�t�@�C���̐ݒ�
				case 'r':
					strcpy(input_file, s);
					break;
				default:
					printf("m16coffset -R:input_file -O:output_file\n");
					break;
				}
			}
		}
	}
	printf("version      = %s\n", version);
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

	/* ��s���� �� ��� */
	for(;;){
		if((fgets(buf, BUF_SIZE, pfi)) == NULL)	break;
		s = buf;

		switch(offset_state){
		  case CHECK_STATE:
			if(skip_space(&s)) /* �s���̋󔒂����� */
				continue;

			/* �I�t�Z�b�g */
			if(test_string(&s, ".word")){
				ofs = 2;
			}
			else if(test_string(&s, ".lword")){
				ofs = 4;
			}
			else if(test_string(&s, ".byte")){
				ofs = 1;
			}
			else if(test_string(&s, ".addr")){
				ofs = 3;
			}
			else {
				continue;
			}

			if(skip_space(&s))
				continue;

			sscanf(s, "%x", &val);
			if(val){
				offset_state = NORMAL_STATE;
				if(v->check_type) {
					sprintf(v->mask, "%xH", val);
					for(v->bit=0; val>1; v->bit++) {
						val /= 2;
					}
				}
				continue;
			}
			v->offset += ofs;
			break;
		  default:
			if(!test_string(&s, "_____BEGIN_")) {
				continue;
			}
			v = &off_table[num_offset++];

			for(i = 0, p = ct; i < 4 && isalpha(*s) && *s != '_'; i++){
				*p++ = *s++;
			}
			*p++ = 0, *s++;
			if(strncmp(ct, "BIT", sizeof("BIT")) == 0) {
				v->check_type = 1;
			}

			p = v->label;
			while(*s > ':')
				*p++ = *s++;
			*p++ = 0;
			offset_state = CHECK_STATE;
			break;
		}
	}

	/* �o�� */
	for(i = 0 ; i < num_offset ; i++){
		v = &off_table[i];
		fprintf(pfo, "%s\t.equ\t%d\n", v->label, v->offset);
		printf("%s\t.equ\t%d\n", v->label, v->offset);
		if(v->check_type) {
			fprintf(pfo, "%s_bit\t.equ\t%d\n", v->label, v->bit);
			fprintf(pfo, "%s_mask\t.equ\t%s\n", v->label, v->mask);
			printf("%s_bit\t.equ\t%d\n", v->label, v->bit);
			printf("%s_mask\t.equ\t%s\n", v->label, v->mask);
		}
	}
	fclose(pfi);
	fclose(pfo);

	return 0;
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
