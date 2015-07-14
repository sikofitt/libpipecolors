#include <cstdio>
#include <iostream>
#include <pipecolors.h>

using namespace pipecolors;

int main(void) {
   char * buffer;
   int num = 5;
   const char* str = "My number is";
   int len = pcprintf("|01%s |41|09%d|39\n", str, num);
   pcprintf("|10Length of Len is : |15|30%d\n|07", len);
   int len2 = pcsprintf(buffer, "%s %d\n", str, num);
   printf("%s\n", buffer);
   return 0;                  
}