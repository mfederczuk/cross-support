/*
 * Copyright (c) 2022 Michael Federczuk
 *
 *
 *  This Source Code Form is subject to the terms of the Mozilla Public
 *  License, v. 2.0. If a copy of the MPL was not distributed with this
 *  file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * AND
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

// Version 1.0.0 (https://github.com/mfederczuk/cross-support)

#ifndef CROSS_SUPPORT_MISC_H
#define CROSS_SUPPORT_MISC_H 1

#if (!(defined(CROSS_SUPPORT_CORE_H)) && !(CROSS_SUPPORT_CORE_H + 0))
	#error Include 'cross_support_core.h' before 'cross_support_misc.h'
#endif

// === kernels / operating systems ================================================================================== //

#if CROSS_SUPPORT_LINUX
	#include <linux/version.h>

	#define CROSS_SUPPORT_LINUX_LEAST(major, patchlevel, sublevel) \
		(LINUX_VERSION_CODE >= KERNEL_VERSION(major, patchlevel, sublevel))
#else
	#define CROSS_SUPPORT_LINUX_LEAST(major, patchlevel, sublevel)  0
#endif

// === libraries ==================================================================================================== //

#if defined(__has_include)
	#if __has_include(<features.h>)
		#include <features.h>
	#endif
#endif

#if (!(defined(__GLIBC__))       && !(defined(__GLIBC_MINOR__)) && \
     !(defined(__GNU_LIBRARY__)) && !(defined(__GNU_LIBRARY_MINOR__)))

	#if __cplusplus
		#include <climits>
	#else
		#include <limits.h>
	#endif
#endif

#define CROSS_SUPPORT_GLIBC_LEAST(major, minor) \
	(                                                           \
		(                                                       \
			((major) >= 6)                                      \
			&&                                                  \
			(                                                   \
				((__GLIBC__ + 0) > (major))                     \
				||                                              \
				(                                               \
					((__GLIBC__       + 0) == (major))          \
					&&                                          \
					((__GLIBC_MINOR__ + 0) >= (minor))          \
				)                                               \
			)                                                   \
		)                                                       \
		||                                                      \
		(                                                       \
			(((major) < 6))                                     \
			&&                                                  \
			(                                                   \
				((__GNU_LIBRARY__ + 0) > (major))               \
				||                                              \
				(                                               \
					((__GNU_LIBRARY__       + 0) == (major))    \
					&&                                          \
					((__GNU_LIBRARY_MINOR__ + 0) >= (minor))    \
				)                                               \
			)                                                   \
		)                                                       \
	)

// === attributes =================================================================================================== //

#if (defined(cross_support_noreturn) && !CROSS_SUPPORT_CXX11 && CROSS_SUPPORT_C11)
	#include <stdnoreturn.h>
	#undef  cross_support_noreturn
	#define cross_support_noreturn  noreturn
#endif

// === UB optimization ============================================================================================== //

#if CROSS_SUPPORT_C23
	#include <stddef.h>
	#define cross_support_unreachable()  unreachable()
#elif CROSS_SUPPORT_CXX23
	#include <utility>
	#define cross_support_unreachable()  ::std::unreachable()
#elif (CROSS_SUPPORT_GCC_LEAST(4,5) || CROSS_SUPPORT_CLANG)
	#define cross_support_unreachable()  __builtin_unreachable()
#elif CROSS_SUPPORT_MSVC
	#define cross_support_unreachable()  __assume(0)
#else
	#if (__cplusplus + 0)
		#include <cassert>
	#else
		#include <assert.h>
	#endif

	// using `assert` because some implementations have noreturn optimizations
	#define cross_support_unreachable()  assert(0)
#endif

// === branch optimization ========================================================================================== //

#if CROSS_SUPPORT_CXX20
	#define cross_support_if_likely(condition)    if(condition) [[likely]]
	#define cross_support_if_unlikely(condition)  if(condition) [[unlikely]]
#elif (CROSS_SUPPORT_GCC_LEAST(3,0) || CROSS_SUPPORT_CLANG)
	#if (__cplusplus + 0)
		#define cross_support_if_likely(condition)    if(__builtin_expect(static_cast<long>(static_cast<bool>(condition)), static_cast<long>(true)))
		#define cross_support_if_unlikely(condition)  if(__builtin_expect(static_cast<long>(static_cast<bool>(condition)), static_cast<long>(false)))
	#elif CROSS_SUPPORT_C99
		#include <stdbool.h>

		#define cross_support_if_likely(condition)    if(__builtin_expect((long)(bool)(condition), (long)(true)))
		#define cross_support_if_unlikely(condition)  if(__builtin_expect((long)(bool)(condition), (long)(false)))
	#else
		#define cross_support_if_likely(condition)    if(__builtin_expect((long)!!(condition), 1L))
		#define cross_support_if_unlikely(condition)  if(__builtin_expect((long)!!(condition), 0L))
	#endif
#else
	#define cross_support_if_likely(condition)    if(condition)
	#define cross_support_if_unlikely(condition)  if(condition)
#endif

#endif /* CROSS_SUPPORT_MISC_H */
