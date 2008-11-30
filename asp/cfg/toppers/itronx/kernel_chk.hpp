/*
 *  TOPPERS Software
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *
 *  Copyright (C) 2007 by TAKAGI Nobuhisa
 * 
 *  �嵭����Ԥϡ��ʲ���(1)��(4)�ξ������������˸¤ꡤ�ܥ��եȥ���
 *  �����ܥ��եȥ���������Ѥ�����Τ�ޤࡥ�ʲ�Ʊ���ˤ���ѡ�ʣ������
 *  �ѡ������ۡʰʲ������ѤȸƤ֡ˤ��뤳�Ȥ�̵���ǵ������롥
 *  (1) �ܥ��եȥ������򥽡��������ɤη������Ѥ�����ˤϡ��嵭������
 *      ��ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ��꤬�����Τޤޤη��ǥ���
 *      ����������˴ޤޤ�Ƥ��뤳�ȡ�
 *  (2) �ܥ��եȥ������򡤥饤�֥������ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ�����Ǻ����ۤ�����ˤϡ������ۤ�ȼ���ɥ�����ȡ�����
 *      �ԥޥ˥奢��ʤɡˤˡ��嵭�����ɽ�����������Ѿ�浪��Ӳ���
 *      ��̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *  (3) �ܥ��եȥ������򡤵�����Ȥ߹���ʤɡ�¾�Υ��եȥ�������ȯ�˻�
 *      �ѤǤ��ʤ����Ǻ����ۤ�����ˤϡ����Τ����줫�ξ�����������
 *      �ȡ�
 *    (a) �����ۤ�ȼ���ɥ�����ȡ����Ѽԥޥ˥奢��ʤɡˤˡ��嵭����
 *        �ɽ�����������Ѿ�浪��Ӳ�����̵�ݾڵ����Ǻܤ��뤳�ȡ�
 *    (b) �����ۤη��֤��̤�������ˡ�ˤ�äơ�TOPPERS�ץ������Ȥ�
 *        ��𤹤뤳�ȡ�
 *  (4) �ܥ��եȥ����������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������뤤���ʤ�»
 *      ������⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ����դ��뤳�ȡ�
 *      �ޤ����ܥ��եȥ������Υ桼���ޤ��ϥ���ɥ桼������Τ����ʤ���
 *      ͳ�˴�Ť����ᤫ��⡤�嵭����Ԥ����TOPPERS�ץ������Ȥ�
 *      ���դ��뤳�ȡ�
 * 
 *  �ܥ��եȥ������ϡ�̵�ݾڤ��󶡤���Ƥ����ΤǤ��롥�嵭����Ԥ�
 *  ���TOPPERS�ץ������Ȥϡ��ܥ��եȥ������˴ؤ��ơ�����λ�����Ū
 *  ���Ф���Ŭ������ޤ�ơ������ʤ��ݾڤ�Ԥ�ʤ����ޤ����ܥ��եȥ���
 *  �������Ѥˤ��ľ��Ū�ޤ��ϴ���Ū�������������ʤ�»���˴ؤ��Ƥ⡤��
 *  ����Ǥ�����ʤ���
 * 
 */
#undef  BEGIN_KERNEL_CHK
#undef  END_KERNEL_CHK
#undef  KERNEL_CHK_SIZEOF
#undef  KERNEL_CHK_OFFSETOF
#undef  KERNEL_CHK_VALUEOF

#ifdef IMPLEMENT_KERNEL_CHK

#define BEGIN_KERNEL_CHK            ofile_ << "\t0x12345678,\n\tTKERNEL_PRID,\n"  \
                                              "\tCHAR_BIT,\n" \
                                              "\tCHAR_MAX,\n" \
                                              "\tSCHAR_MAX,\n" \
                                              "\tSHRT_MAX,\n" \
                                              "\tINT_MAX,\n" \
                                              "\tLONG_MAX,\n"
#define END_KERNEL_CHK              ;
#define KERNEL_CHK_SIZEOF( sym )    KERNEL_CHK_SIZEOF_( sym )
#define KERNEL_CHK_SIZEOF_( sym )   "\tsizeof(" #sym "),\n"
#define KERNEL_CHK_OFFSETOF( type, member )  "\toffsetof(" #type ", " #member "),\n"
#define KERNEL_CHK_VALUEOF( expr )  "\t" #expr ",\n"

#else

#define BEGIN_KERNEL_CHK            enum { magic_number, TKERNEL_PRID, \
                                           valueof_CHAR_BIT, \
                                           valueof_CHAR_MAX, \
                                           valueof_SCHAR_MAX, \
                                           valueof_SHRT_MAX, \
                                           valueof_INT_MAX, \
                                           valueof_LONG_MAX,
#define END_KERNEL_CHK              kernel_chk_table_size };
#define KERNEL_CHK_SIZEOF( sym )    sizeof_##sym,
#define KERNEL_CHK_OFFSETOF( type, member )  offsetof_##type##_##member,
#define KERNEL_CHK_VALUEOF( expr )  valueof_##expr,

#endif
