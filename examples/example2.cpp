#include <cstdio>
#include <iostream>
#include <pipecolors.h>

using namespace pipecolors;

int main(void) {

   int num = 5;
   const char* str = "My number is";
   pcprintf("|40%s |05%d|39\n", str, num);
   
   return 0;                  
}