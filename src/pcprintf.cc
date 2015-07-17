#include <cstdio>
#include <iostream>
#include <pipecolors.h>
#include <climits>
#include <cstring>
#include <cstdarg>
#include <vector>
using namespace pipecolors;
using namespace std;


void usage() {
  pcprintf("|10|30  * |15|30pcprintf|39: |12|30usage|39: |15pcprintf |03\"|11|30string|03\"|39\n");
}

void bprintf(const char * format, ... ) {


  char * buf;

  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
  //pcprintf(buf);
  //delete[] buf;

}

int
ssvprintf(const char *fmt, ...)
{
 va_list args, rag;
 va_start(args,fmt);
 va_copy(rag, args);
 va_end(args);
 char * val = va_arg(rag, char*);
 printf(fmt, val );


 va_end(rag);

}
int
g (const char *a, ...)
{
  va_list ap;
  va_start (ap, a);
  va_arg (ap, char*);
  if (va_arg (ap, int) != 1234)
    std::cout << "Hello" << std::endl;

  va_end (ap);
}
int main( int argc, char * argv[] ) {


  if(argc <= 1 || argc > 2) {
    usage();
    return(1);
  }
  pcprintf(argv[1],argv[2]);

  return 0;
}
