#
#  @(#) $Id: Makefile.prc 304 2007-07-16 07:50:38Z hiro $
# 

#
#		Makefile �Υץ��å���¸����M68040�ѡ�
#

#
#  GNU��ȯ�Ķ��Υ������åȥ������ƥ���������
#
GCC_TARGET = m68k-unknown-elf

#
#  ����ѥ��륪�ץ����
#
COPTS := $(COPTS) -m68020-40 -msoft-float
LDFLAGS := $(LDFLAGS) -msoft-float

#
#  �����ͥ�˴ؤ������
#
KERNEL_DIR := $(KERNEL_DIR) $(SRCDIR)/arch/$(PRC)_$(TOOL)
KERNEL_ASMOBJS := $(KERNEL_ASMOBJS) prc_support.o
KERNEL_COBJS := $(KERNEL_COBJS) prc_config.o
