# libpipecolors
[![Build Status](https://travis-ci.org/sk-5/libpipecolors.svg?branch=master)](https://travis-ci.org/sk-5/libpipecolors)

This library parses input like **_printf_** and **_sprintf_** but instead of returning a boring string it will replace renegade bbs style    pipecodes (|09) with their ansi equivelent.
 
## It has two functions -
```c++
int pcprintf(const char * format, ...);
int pcsprintf(char * str, const char * format, ...);
```
### To Do
- [x] Remove std::map requirement
- [x] Remove boost requirement without forcing `-std=c++11` (Reduced size from 1.2M to 87K)

## Example use

```c++
#include <cstdio>
#include <iostream>
#include <pipecolors.h>

using namespace pipecolors;

int main(void) {

  int num = 5;
  const char* str = "My number is";
  pcprintf("|02%s |10%d|39\n", str, num);

  return 0;
}
```
This would return `\x1b[0;32mMy number is \x1b[0;92m5\x1b[0;39m\n`,
Printing str in <span style="color:#009900;">*dark green*</span> and num in <span style="color:#00FF00;">*light green*</span>
