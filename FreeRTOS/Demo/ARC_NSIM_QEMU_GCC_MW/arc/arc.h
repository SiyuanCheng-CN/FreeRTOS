/*
 * Copyright (c) 2022 Synopsys
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * \file
 * \ingroup ARC_HAL_CORE_COMM
 * \brief  header file including common core definitions
 */

/**
 * \addtogroup ARC_HAL_CORE_COMM
 * @{
 */

#ifndef _ARC_HAL_CORE_H_
#define _ARC_HAL_CORE_H_

#include "arc_feature_config.h"
#define AUX_BCR_TIMERS                  (0x75)  /*!< build configuration for processor timers */
#define AUX_STATUS32                    (0xa)
#define AUX_STATUS_BIT_AE       (5)             /*!< processor is in an exception */
#define AUX_STATUS_BIT_IE       (31)            /*!< interrupt enable */
#define AUX_STATUS_BIT_HALT     (0)             /*!< halt bit */
#define AUX_STATUS_BIT_SC       (14)            /*!< stack check bit */
#define AUX_STATUS_BIT_US       (20)            /*!< user sleep mode enable bit */
#define AUX_STATUS_MASK_IE      (1 << AUX_STATUS_BIT_IE)        /*!< mask of AUX_STATUS_BIT_IE */
#define AUX_STATUS_MASK_HALT    (1 << AUX_STATUS_BIT_HALT)      /*!< mask of AUX_STATUS_BIT_HALT */
#define AUX_STATUS_MASK_US      (1 << AUX_STATUS_BIT_US)        /*!< mask of AUX_STATUS_BIT_US */
#define STATUS32_RESET_VALUE    (AUX_STATUS_MASK_US)
#define AUX_LP_START                    (0x2)   /*!< loop start address (32-bit) */
#define AUX_LP_END                      (0x3)   /*!< loop end address (32-bit) */
#define AUX_KSTACK_TOP                  (0x264)
#define AUX_KSTACK_BASE                 (0x265)
#define AUX_TIMER0_LIMIT                (0x23)  /*!< timer 0 limit value */
#define AUX_TIMER0_CTRL                 (0x22)  /*!< timer 0 control value */
#define AUX_TIMER0_CNT                  (0x21)  /*!< timer 0 count value */
#define AUX_ERRET                       (0x400) /*!< exception return address */
#define AUX_ERBTA                       (0x401) /*!< BTA saved on exception entry */
#define AUX_ERSTATUS                    (0x402) /*!< STATUS32 saved on exception */
#define AUX_ECR                         (0x403) /*!< exception cause register */
#define AUX_IRQ_CTRL                    (0xe)   /*!< interrupt context saving control register */
#define AUX_INT_VECT_BASE               (0x25)  /*!< interrupt vector base register */
#define AUX_IRQ_ACT                     (0x43)  /*!< active interrupts register */
#define AUX_IRQ_CAUSE                   (0x40a) /*!< interrupt cause register */
#define AUX_IRQ_SELECT                  (0x40b) /*!< interrupt select register */
#define AUX_IRQ_PRIORITY                (0x206) /*!< interrupt priority register */
#define AUX_IRQ_ENABLE                  (0x40c) /*!< interrupt enable register */
#define AUX_IRQ_TRIGGER                 (0x40d) /*!< interrupt trigger: level or pulse */
#define AUX_IRQ_HINT                    (0x201) /*!< software interrupt trigger */

#ifndef __ASSEMBLY__

#include <stdint.h>     /* C99 standard lib */
#include <limits.h>     /* C99 standard lib */
#include <stddef.h>     /* C99 standard lib */
#include <stdbool.h>    /* C99 standard lib */

#define Inline  static __inline__               /* inline function */

#define Asm     __asm__ volatile                /* inline asm (no optimization) */

#endif  /* __ASSEMBLY__ */

#endif  /* _ARC_HAL_CORE_H_ */

// /**  @} */
