<!--
  Copyright (c) 2022 Michael Federczuk
  SPDX-License-Identifier: CC-BY-SA-4.0
-->

<!-- markdownlint-disable no-duplicate-heading -->

# Changelog #

All notable changes to this project will be documented in this file.
The format is based on [**Keep a Changelog v1.0.0**](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [**Semantic Versioning v2.0.0**](https://semver.org/spec/v2.0.0.html).

## Unreleased ##

### Added ###

* Macro `CROSS_SUPPORT_BSD` evaluates to a nonzero value if the target system is **BSD**-based
* Macro `CROSS_SUPPORT_MACOS` evaluates to a nonzero value if the target system is **Mac OS**
* Macro `CROSS_SUPPORT_UNIX_LIKE` evaluates to a nonzero value if the target system is Unix-like
* Macro `CROSS_SUPPORT_HAS_INCLUDE_AVAILABLE` evaluates to a nonzero value if the preprocessor operator `__has_include`
  is supported
* Macros `CROSS_SUPPORT_POSIX`, `CROSS_SUPPORT_POSIX_2001` and `CROSS_SUPPORT_POSIX_2008` evaluate to nonzero values if
  the target system is generally **POSIX**-, **POSIX.1-2001**- and **POSIX.1-2008/2017** compliant, respectively

### Fixed ####

* Fixed the `CROSS_SUPPORT_WINDOWS` macro
* The condition to redefine `cross_support_if_likely` and `cross_support_if_unlikely` in the `cross_support_core.h`
  header was fixed

## [v1.1.0] - 2022-11-05 ##

[v1.1.0]: https://github.com/mfederczuk/cross-support/releases/tag/v1.1.0

### Added ###

* Macro `CROSS_SUPPORT_CXX` evaluates to a nonzero value if the current language is C++
* Macro `cross_support_nullptr` will either expand to `nullptr` or `NULL` and may include `<cstddef>` or `<stddef.h>`
* The `cross_support_noreturn` macro now supports C11's `_Noreturn`/`noreturn` function specifier and
  C23's `[[noreturn]]` attribute
* Macro `cross_support_constexpr_func` is the same as `cross_support_constexpr` (now deprecated) — the only thing
  different is the name. The new name is more clear what it's used for
* `cross_support_if_likely` and `cross_support_if_unlikely` are now also available in the `cross_support_core.h` header

### Deprecated ###

* `cross_support_constexpr` is deprecated. As replacement use `cross_support_constexpr_func`

## [v1.0.0] - 2022-11-02 ##

[v1.0.0]: https://github.com/mfederczuk/cross-support/releases/tag/v1.0.0

Initial Release
