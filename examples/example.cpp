#include <cstdio>
#include <iostream>
#include <pipecolors.h>

using namespace pipecolors;

int main(void) {

   int num = 5;
   const char* str = "My number is";
   pcprintf("|01%s |09%d\n", str, num);
   
   return 0;                  
}