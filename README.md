# LoremIpsumGenerator

LoremIpsumGenerator is a simple header-only library for the simplest task of generating lorem ipsum text.


## Usage

Usage can be done in two forms (compile time form and runtime form).

### Runtime version

Runtime version can generate lorem ipsum text with runtime argument. If argument is too long it can throw exception.
```c
	auto lorem_ipsum = lorem_ipsum::generate_lorem_ipsum_lines(3);

```

### Compile time version
Compile time version can generate lorem ipsum with validations done in compile time. It do not throw. This is prefered way for generating lorem ipsum.

```c
	auto lorem_ipsum = lorem_ipsum::generate_lorem_ipsum_lines<3>();

```

## Installation

For installation you only need to use header only.
```c
	#include <include/LoremIpsumGenerator.hpp>

```

## Licencing

MIT License

Copyright (c) 2023 Rami Mtier

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.