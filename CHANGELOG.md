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

* Macro `CROSS_SUPPORT_BSD` evaluates to a nonzero value if the target system is **BSD**-based ([`d26cb79`])
* Macro `CROSS_SUPPORT_MACOS` evaluates to a nonzero value if the target system is **Mac OS** ([`0db93aa`])
* Macro `CROSS_SUPPORT_UNIX_LIKE` evaluates to a nonzero value if the target system is Unix-like ([`e2d5926`])
* Macro `CROSS_SUPPORT_HAS_INCLUDE_AVAILABLE` evaluates to a nonzero value if the preprocessor operator `__has_include`
  is supported ([`f606027`])
* Macros `CROSS_SUPPORT_POSIX`, `CROSS_SUPPORT_POSIX_2001` and `CROSS_SUPPORT_POSIX_2008` evaluate to nonzero values if
  the target system is generally **POSIX**-, **POSIX.1-2001**- and **POSIX.1-2008/2017** compliant, respectively
  ([`4c30d20`])
* Macro `cross_support_static_assert(expr, msg)` and `cross_support_static_assert_nomsg(expr)` which expand to
  static assertions ([`c59100a`])

[`d26cb79`]: <https://github.com/mfederczuk/cross-support/commit/d26cb79807f3c8aba5ce19eea96db19e7a0a030b> "Commit d26cb79"
[`0db93aa`]: <https://github.com/mfederczuk/cross-support/commit/0db93aa33c7ac746514653a58971d386cc67db67> "Commit 0db93aa"
[`e2d5926`]: <https://github.com/mfederczuk/cross-support/commit/e2d5926aa3df323c17d1077d885bb41a16b6ba92> "Commit e2d5926"
[`f606027`]: <https://github.com/mfederczuk/cross-support/commit/f6060279f1560208e2ce78c3e32464b0fcff8af6> "Commit f606027"
[`4c30d20`]: <https://github.com/mfederczuk/cross-support/commit/4c30d20253fabbbc19c70c7be58e9eccc8f6949c> "Commit 4c30d20"
[`c59100a`]: <https://github.com/mfederczuk/cross-support/commit/c59100abc085d8fe9b53c86f270b64762a399df6> "Commit c59100a"

### Fixed ####

* Fixed the `CROSS_SUPPORT_WINDOWS` macro ([`5e2abd5`])
* The condition to redefine `cross_support_if_likely` and `cross_support_if_unlikely` in the `cross_support_core.h`
  header was fixed ([`45dbbbd`])

[`5e2abd5`]: <https://github.com/mfederczuk/cross-support/commit/5e2abd5510218ba23fe1a92d26a63db73312c63e> "Commit 5e2abd5"
[`45dbbbd`]: <https://github.com/mfederczuk/cross-support/commit/45dbbbdbfe0431b6a0beece331d68cd556ffcdaa> "Commit 45dbbbd"

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
