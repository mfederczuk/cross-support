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

* Macro `CROSS_SUPPORT_CXX` evaluates to a nonzero value if the current language is C++
* The `cross_support_noreturn` macro now supports C11's `_Noreturn`/`noreturn` function specifier and
  C23's `[[noreturn]]` attribute

## [v1.0.0] - 2022-11-02 ##

[v1.0.0]: https://github.com/mfederczuk/cross-support/releases/tag/v1.0.0

Initial Release
