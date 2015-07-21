#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pipecolors.h>

using namespace pipecolors;
using namespace std;

int main(void) {

  char buffer[100];
  int num = 5;
  const char* str = "My number is";
  const char* str2 = "|03My number is";

  pcprintf("\n\n\t|01P|02i|03p|04e|05c|06ol|07o|08r|09s |10l|11i|12b|13r|14a|15r|14y |131|12.|112|10.|090|07 |15* |0101|0202|0303|0404|0505|0606|0707|0808|0909|1010|1111|1212|1313|1414|1515\n\n");

  int len = pcprintf("\t|01%s |41|09|30%d|39 (pcprintf)\n", str, num);
  pcprintf("\t|02Length of |15pcprintf |02is  : |10|30%d|39 : We count escape characters just like printf\n", len);

  int len2 = pcsprintf(buffer, "\t%s |11|30%d|39 (pcsprintf)\n", str2, num);
  printf("%s", buffer);

  pcprintf("\t|02Length of |15pcsprintf |02is : |10|30%d|39 : We count escape characters just like sprintf\n\n", len2);

  return 0;
  
}