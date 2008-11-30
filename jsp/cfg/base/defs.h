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
 *  @(#) $Id: defs.h,v 1.1 2008/06/17 00:04:36 suikan Exp $
 */


// $Header: /cvsroot/jsp4cm3/jsp/cfg/base/defs.h,v 1.1 2008/06/17 00:04:36 suikan Exp $

#ifndef DEFS_H
#define DEFS_H

    /*
     *  �����n�Ɉˑ����镔��
     *      �֐����� : mktemp, popen, pclose
     */

#ifdef CALL_EXTERNAL_PROGRAM

    /* Microsoft Visual C++ */
#if defined(_MSC_VER) || defined(__MINGW__)
#  include <io.h>
#  define   popen _popen
#  define   pclose _pclose
#  define   mktemp _mktemp

    /* GNU Compiler Collection on Linux environment*/
#elif defined(__GNUC__)
#  include  <stdlib.h>
#  define   mktemp mkstemp

    /* GNU Compiler Collection on Cygwin */
#elif defined(__CYGWIN__)
#  include  <stdlib.h>
#  define   mktemp mkstemp

    /* Borland C++ Compiler */
#elif defined(__BORLANDC__)
#  include <io.h>
#  include <stdio.h>
#  define   popen  ::std::_popen
#  define   pclose ::std::_pclose
#  define   mktemp ::std::_mktemp

#endif


    /*
     *  fc_binutils.cpp���g�p����v���O�����̒�`
     */

#ifdef _MSC_VER
#  define   CMD_PREPROCESSOR "\"C:\\Program Files\\Microsoft Visual Studio\\VC98\\Bin\\cl.exe\" /E /nologo"
#  define   CMD_SYMBOLLISTER "nm.exe"
#  define   CMD_OBJDUMP      "objdump.exe"
#  define   CMD_OBJCOPY      "objcopy.exe"
#  define   CMD_GREP         "grep.exe"
#else
#  define   CMD_PREPROCESSOR "cpp -ansi"
#  define   CMD_SYMBOLLISTER "nm"
#  define   CMD_OBJDUMP      "objdump"
#  define   CMD_OBJCOPY      "objcopy"
#  define   CMD_GREP         "grep"
#endif

#endif /* CALL_EXTERNAL_PROGRAM */

#endif /* DEFS_H */

