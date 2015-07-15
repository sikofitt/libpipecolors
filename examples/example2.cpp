#include <cstdio>
#include <iostream>
#include <pipecolors.h>
#include <climits>
using namespace pipecolors;

int main(void) {
   
   char buffer[UCHAR_MAX];
   int num = 5;
   const char* str = "My number is";
   const char* str2 = "|03My number is|11|30";
   int len = pcprintf("|01%s |41|09|30%d|39\n", str, num);
   pcprintf("|10Length of Len is : |15|30%d\n|07", len);
   int len2 = pcsprintf(buffer, "%s %d|39\n", str2, num);
   printf("%s", buffer);
   pcprintf("|10Length of Len2 is : |15|30%d\n|07", len2);
   return 0;                  
}