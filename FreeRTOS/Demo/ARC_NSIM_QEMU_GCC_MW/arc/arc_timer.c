/*
 * Copyright (c) 2022 Synopsys
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @ingroup	ARC_HAL_MISC_TIMER
 * @brief  implementation of internal timer related functions
 * @todo RTC support should be improved if RTC is enabled
 */
#include "arc_timer.h"
#include "arc_exception.h"

/**
 * @brief  check whether the specific timer present
 * @param[in] no timer number
 * @return 1 present, 0 not present
 */
int32_t arc_timer_present(const uint32_t no)
{
	uint32_t bcr = arc_aux_read(AUX_BCR_TIMERS);

	bcr = (bcr >> 8) & 1;

	return (int)bcr;
}

/**
 * @brief  start the specific timer
 * @param[in] no	timer number
 * @param[in] mode	timer mode
 * @param[in] val	timer limit value (not for RTC)
 * @return 0 success, -1 failure
 */
int32_t arc_timer_start(const uint32_t no, const uint32_t mode, const uint32_t val)
{
	arc_aux_write(AUX_TIMER0_CTRL, 0);
	arc_aux_write(AUX_TIMER0_LIMIT, val);
	arc_aux_write(AUX_TIMER0_CTRL, mode);
	arc_aux_write(AUX_TIMER0_CNT, 0);

	return 0;
}

/**
 * @brief  stop and clear the specific timer
 *
 * @param[in] no timer number
 * @return 0 success, -1 failure
 */
int32_t arc_timer_stop(const uint32_t no)
{
	arc_aux_write(AUX_TIMER0_CTRL, 0);
	arc_aux_write(AUX_TIMER0_LIMIT, 0);
	arc_aux_write(AUX_TIMER0_CNT, 0);

	return 0;
}

/**
 * @brief  clear the interrupt pending bit of timer
 *
 * @param[in] no timer number
 * @return 0 success, -1 failure
 */
int32_t arc_timer_int_clear(const uint32_t no)
{
	uint32_t val;

	val = arc_aux_read(AUX_TIMER0_CTRL);
	val &= ~TIMER_CTRL_IP;
	arc_aux_write(AUX_TIMER0_CTRL, val);

	return 0;
}

/**
 * @brief  init internal timer
 */
void arc_timer_init(void)
{
	if (arc_timer_present(TIMER_0)) {
		arc_timer_stop(TIMER_0);
	}
}
