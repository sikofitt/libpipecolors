#include <cstdio>
#include <iostream>
#include <pipecolors.h>

using namespace pipecolors;

int main(void) {
   
   char buffer[256];
   int num = 5;
   const char* str = "My number is";
   const char* str2 = "|10My number is|07";
   int len = pcprintf("|01%s |09%d|39\n", str, num);
   pcprintf("|10Length of Len is : |15|30%d\n|07", len);
   int len2 = pcsprintf(buffer, "%s %d\n", str2, num);
   printf("\n%s %d\n", buffer, len2);
   return 0;                  
}