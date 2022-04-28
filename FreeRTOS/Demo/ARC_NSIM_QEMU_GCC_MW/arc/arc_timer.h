/*
 * Copyright (c) 2022 Synopsys
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * \file
 * \ingroup ARC_HAL_MISC_TIMER
 * \brief header file of ARC internal timer
 */

/**
 * \addtogroup ARC_HAL_MISC_TIMER
 * @{
 */

#ifndef _ARC_HAL_TIMER_H_
#define _ARC_HAL_TIMER_H_
#include "arc.h"
#include "arc_builtin.h"

/**
 * \name arc internal timers names
 * @{
 */
#define TIMER_0         0               /*!< macro name for arc internal timer 0 */

#define INTNO_TIMER0 ARC_FEATURE_TIMER0_VECTOR

/** @} */

/**
 * \name bit definition of timer CTRL reg
 * @{
 */
#define TIMER_CTRL_IE           (1 << 0)        /*!< Interrupt when count reaches limit */
#define TIMER_CTRL_NH           (1 << 1)        /*!< Count only when CPU NOT halted */
#define TIMER_CTRL_W            (1 << 2)        /*!< watchdog enable */
#define TIMER_CTRL_IP           (1 << 3)        /*!< interrupt pending */

/** @} */
extern int32_t arc_timer_present(const uint32_t no);
extern int32_t arc_timer_start(const uint32_t no, const uint32_t mode, const uint32_t val);
extern int32_t arc_timer_stop(const uint32_t no);
extern int32_t arc_timer_int_clear(const uint32_t no);
extern void arc_timer_init(void);

#endif  /* _ARC_HAL_TIMER_H_ */
/** @} */
