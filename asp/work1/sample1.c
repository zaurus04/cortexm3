#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include <string.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "sample1.h"

void task1(intptr_t exinf)
{


    syslog( LOG_NOTICE, "test = %x", 0x444 );



}

