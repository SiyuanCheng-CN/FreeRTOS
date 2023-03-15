/*
 * Copyright (c) 2022 Synopsys
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @ingroup ARC_HAL_BUILTIN
 * @brief Header file of builtin and helper functions
 *
 * The Metaware toolchain and the GNU toolchain are supported. The details please go to see the file.
 */

/**
 * @addtogroup	ARC_HAL_BUILTIN
 * @{
 */

#ifndef _ARC_HAL_BUILTIN_H_
#define _ARC_HAL_BUILTIN_H_

#include "arc.h"

#ifndef __ASSEMBLY__

#if defined(__CCAC__)

#define arc_aux_read(reg) _lr((volatile uint32_t)reg)
#define arc_aux_write(reg, val) _sr((unsigned int)val, (volatile uint32_t)reg)

#else /* ! __CCAC__ */

#define arc_aux_read(reg) __builtin_arc_lr((volatile uint32_t)reg)
#define arc_aux_write(reg, val) __builtin_arc_sr((unsigned int)val, (volatile uint32_t)reg)

#endif /* __CCAC__ */

/**
 * @fn void arc_halt(void)
 * @brief Call kflag instruction to change status32
 *
 * @param flag Flag to set in status32
 */
Inline void arc_halt(void)
{
	/*sr cannot write AUX_STATUS32 */
	Asm("kflag %0" ::"ir" (1));
}

/**
 * @fn uint32_t arc_clri(void)
 * @brief Call clri instruction
 * call a clri instruction to disable interrupt
 * @return interrupt related bits in status32
 */
Inline uint32_t arc_clri(void)
{
	uint32_t v;

	Asm("clri %0" : "=r" (v):: "memory");
	return v;
}

/**
 * @fn void arc_seti(uint32_t key)
 * @brief Call seti instruction
 * call a set instruction to change interrupt status
 * @param key  interrupt status
 */
Inline void arc_seti(uint32_t key)
{
	Asm("seti %0" : : "ir" (key) : "memory");
}

#endif  /* __ASSEMBLY__ */

/** @} */
#endif /* _ARC_HAL_BUILTIN_H_ */
/** @} */
