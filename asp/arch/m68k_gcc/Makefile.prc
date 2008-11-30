#
#  @(#) $Id: Makefile.prc 304 2007-07-16 07:50:38Z hiro $
# 

#
#		Makefile のプロセッサ依存部（M68040用）
#

#
#  GNU開発環境のターゲットアーキテクチャの定義
#
GCC_TARGET = m68k-unknown-elf

#
#  コンパイルオプション
#
COPTS := $(COPTS) -m68020-40 -msoft-float
LDFLAGS := $(LDFLAGS) -msoft-float

#
#  カーネルに関する定義
#
KERNEL_DIR := $(KERNEL_DIR) $(SRCDIR)/arch/$(PRC)_$(TOOL)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o
