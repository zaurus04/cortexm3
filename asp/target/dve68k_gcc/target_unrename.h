/* This file is generated from target_rename.def by genrename. */

/* This file is included only when target_rename.h has been included. */
#ifdef TOPPERS_TARGET_RENAME_H
#undef TOPPERS_TARGET_RENAME_H

/*
 *  target_config.c
 */
#undef board_id
#undef board_addr
#undef bitpat_cfgint
#undef x_config_int

/*
 *  prc_config.c, prc_support.S
 */
#undef prc_initialize
#undef prc_terminate


#ifdef TOPPERS_LABEL_ASM

/*
 *  target_config.c
 */
#undef _board_id
#undef _board_addr
#undef _bitpat_cfgint
#undef _x_config_int

/*
 *  prc_config.c, prc_support.S
 */
#undef _prc_initialize
#undef _prc_terminate


#endif /* TOPPERS_LABEL_ASM */

#include "m68k_gcc/prc_unrename.h"

#endif /* TOPPERS_TARGET_RENAME_H */
