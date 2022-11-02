<!--
  Copyright (c) 2022 Michael Federczuk
  SPDX-License-Identifier: CC-BY-SA-4.0
-->

# C & C++ Cross-Support Headers #

[version_shield]: https://img.shields.io/badge/version-1.0.0-informational.svg
[release_page]: https://github.com/mfederczuk/cross-support/releases/tag/v1.0.0 "Release v1.0.0"
[![version: 1.0.0][version_shield]][release_page]
[![Changelog](https://img.shields.io/badge/-Changelog-informational.svg)](CHANGELOG.md "Changelog")

## About ##

C & C++ header files for cross-everything support.

These headers define preprocessor macros to test support for different language standards, kernels, operating systems,
compilers, libraries, etc.

A lot of information was taken from the [Pre-defined Compiler Macros wiki] and these headers are basically a (partial)
implementation of that wiki.

[Pre-defined Compiler Macros wiki]: <https://github.com/cpredef/predef> "cpredef/predef: Pre-defined Compiler Macros wiki"

## Usage ##

Include the headers anywhere you need to use cross-anything support:

```c
#include "cross_support_core.h"
#include "cross_support_misc.h"
```

Make sure to always include `cross_support_core.h` *before* `cross_support_misc.h`.

The reason the headers are split into two is because `cross_support_core.h` does not contain any
`#include` directives.  
This is important for things like [feature test macros], which need to be defined before any `#include` directives.

For convenience, you can create a `cross_support.h` header in your project including both headers.

[feature test macros]: <https://linux.die.net/man/7/feature_test_macros> "feature_test_macros(7): feature test macros - Linux man page"

## Download ##

Simply download the header files from this repository and place them into your project.

## Contributing ##

Read through the [Contribution Guidelines](CONTRIBUTING.md) if you want to contribute to this project.

## License ##

**C & C++ Cross-Support Headers** are licensed under both the [**Mozilla Public License 2.0**](LICENSES/MPL-2.0.txt) AND
the [**Apache License 2.0**](LICENSES/Apache-2.0.txt).  
For more information about copying and licensing, see the [`COPYING.txt`](COPYING.txt) file.
