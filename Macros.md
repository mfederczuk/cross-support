<!--
  Copyright (c) 2022 Michael Federczuk
  SPDX-License-Identifier: CC-BY-SA-4.0
-->

<!-- markdownlint-disable no-duplicate-heading -->

# Defined Macros #

This document lists all macros defined in the headers [`cross_support_core.h`](headers/cross_support_core.h) and
[`cross_support_misc.h`](headers/cross_support_misc.h).

Generally, macros which names are written in UPPER\_SNAKE\_CASE (a.k.a.: _"screaming snake case"_ or _"const case"_) are
only supposed to be used in preprocessor directives. (the only exceptions are the `CROSS_SUPPORT_EXTERN_C_BEGIN` and
`CROSS_SUPPORT_EXTERN_C_END` macros)  
Any other macros (with names written in lower\_snake\_case) are supposed to be used in regular C or C++ code.

If a macro is said to be "truthy", it means that this macro will expand to an expression that evaluates to a nonzero
integer value.

If a macro is said that it may include a header, it doesn't mean that using this macro will include a header, instead it
means that the implementation of this macro may have required a header to be included before it was defined.

## `cross_support_core.h` ##

### Language Standards ###

* `CROSS_SUPPORT_C99` — truthy if the language standard is **C99** or later

* `CROSS_SUPPORT_C11` — truthy if the language standard is **C11** or later

* `CROSS_SUPPORT_C18` — truthy if the language standard is **C18** or later

* `CROSS_SUPPORT_C23` — truthy if the language standard is **C23** or later

* `CROSS_SUPPORT_CXX` — truthy if the language is **C++**

* `CROSS_SUPPORT_CXX98` — truthy if the language standard is **C++98** or later

* `CROSS_SUPPORT_CXX11` — truthy if the language standard is **C++11** or later

* `CROSS_SUPPORT_CXX17` — truthy if the language standard is **C++17** or later

* `CROSS_SUPPORT_CXX14` — truthy if the language standard is **C++14** or later

* `CROSS_SUPPORT_CXX20` — truthy if the language standard is **C++20** or later

* `CROSS_SUPPORT_CXX23` — truthy if the language standard is **C++23** or later

### Kernels & Operating Systems ###

* `CROSS_SUPPORT_LINUX` — truthy if the target system is **Linux**-based

* `CROSS_SUPPORT_BSD` — truthy if the target system is **BSD**-based

* `CROSS_SUPPORT_WINDOWS` — truthy if the target system is **Windows**

### Compilers ###

* `CROSS_SUPPORT_GCC_LEAST(major, minor)` — truthy if the current compiler used is compatible with **GCC** version
  `major.minor` or greater

* `CROSS_SUPPORT_CLANG` — truthy if the current compiler is **Clang**

* `CROSS_SUPPORT_MSVC` — truthy if the current compiler is **MSVC**

### C/C++ compatibility ###

* `CROSS_SUPPORT_EXTERN_C_BEGIN` — expands to `extern "C" {` if the language standard is **C++98** or later and
  to nothing otherwise

  **Example:**

  ```c
  CROSS_SUPPORT_EXTERN_C_BEGIN

  void func();

  CROSS_SUPPORT_EXTERN_C_END
  ```

* `CROSS_SUPPORT_EXTERN_C_END` — expands to `}` if the language standard is **C++98** or later and to nothing otherwise

* `cross_support_constexpr_func` — expands to `constexpr` if the language standard is **C++17** or later,
  to `static inline` if the language standard is **C99** or later and to `static` otherwise

  **Example:**

  ```c
  cross_support_constexpr_func int times2(int n) {
  	return n * 2;
  }
  ```

* `cross_support_constexpr` — **Deprecated.** Use `cross_support_constexpr_func` instead

### Attributes ###

* `cross_support_attr_const` — expands to `__attribute__((__const__))` if the current compiler supports it

* `cross_support_attr_pure` — expands to `__attribute__((__pure__))` if the current compiler supports it

* `cross_support_noreturn` — expands to `[[noreturn]]` if the language standard is **C++11** or later or
  **C23** or later, to `_Noreturn` if the language standard is **C11** or later and to nothing otherwise

* `cross_support_attr_noreturn` — expands to `__attribute__((__noreturn__))` if the current compiler supports it

  **Example:**

  ```c
  cross_support_noreturn
  void bye() cross_support_attr_noreturn;
  void bye() {
  	puts("Bye.");
  	exit(0);
  }
  ```

* `cross_support_attr_always_inline` — expands to `__attribute__((__always_inline__))` if the current compiler supports
  it

* `cross_support_attr_unused` — expands to `__attribute__((__unused__))` if the current compiler supports it

* `cross_support_nodiscard` — expands to `[[nodiscard]]` if the language standard is **C++17** or later or
  **C23** or later and to nothing otherwise

* `cross_support_attr_warn_unused_result` — expands to `__attribute__((__warn_unused_result__))` if the current compiler
  supports it

  **Example:**

  ```c
  cross_support_nodiscard
  int times(int n) cross_support_attr_warn_unused_result;
  int times(int n) {
  	return n * 2;
  }
  ```

* `cross_support_attr_nonnull(...)` — expands to `__attribute__((__nonnull__(__VA_ARGS__)))` if the current compiler
  supports it

* `cross_support_attr_nonnull_all` — expands to `__attribute__((__nonnull__))` if the current compiler supports it

* `cross_support_attr_hot` — expands to `__attribute__((__hot__))` if the current compiler supports it

* `cross_support_attr_cold` — expands to `__attribute__((__cold__))` if the current compiler supports it

### Branch Optimization ###

* `cross_support_if_likely(condition)` — expands to an compiler-optimized `if` head where the condition is expected to
  be more likely to be `true`. (see [cppreference.com: likely, unlikely])

* `cross_support_if_unlikely(condition)` — expands to an compiler-optimized `if` head where the condition is expected to
  be more likely to be `false`. (see [cppreference.com: likely, unlikely])

  **Example:**

  ```c
  void* p = malloc(64);
  cross_support_if_unlikely(p == cross_support_nullptr) {
  	exit(EXIT_FAILURE);
  }
  ```

[cppreference.com: likely, unlikely]: <https://en.cppreference.com/w/cpp/language/attributes/likely> "C++ attribute: likely, unlikely (since C++20) - cppreference.com"

## `cross_support_misc.h` ##

### Kernels & Operating Systems ###

* `CROSS_SUPPORT_LINUX_LEAST(major, patchlevel, sublevel)` — Truthy if the target system is **Linux**-based,
  version `major.patchlevel.sublevel` or greater.  
  This macro may include the header `<linux/version.h>`

### Libraries ###

* `CROSS_SUPPORT_GLIBC_LEAST(major, minor)` — Truthy if the **glibc** library is used, version `major.minor` or
  greater.  
  This macro may include the headers `<features.h>`, `<climits>` or `<limits.h>`

### C/C++ Compatibility ###

* `cross_support_nullptr` — Expands to `nullptr` if the language standard is **C++11** or later,
  to `NULL` if the language is **C++**,
  to `nullptr` if the language standard **C23** or later and to `NULL` otherwise.  
  This macro may include the headers `<cstddef>` or `<stddef.h>`

### Attributes ###

* `cross_support_noreturn` — This macro is changed to expand to `noreturn` instead of `_Noreturn`.  
  This macro may include the header `<stdnoreturn.h>`

### UB Optimization ###

* `cross_support_unreachable()` — Expands Attempts to invoke undefined behavior.  
  This macro may include the headers `<utility>`, `<stddef.h>`, `<cassert>` or `<assert.h>`

### Branch Optimization ###

* `cross_support_if_likely(condition)` — This macro is changed to use `bool` instead of `_Bool`.  
  This macro may include the header `<stdbool.h>`

* `cross_support_if_unlikely(condition)` — This macro is changed to use `bool` instead of `_Bool`.  
  This macro may include the header `<stdbool.h>`
