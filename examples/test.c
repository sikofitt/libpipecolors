#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pipecolors.h>

main() {
    int a,b;
    const char* str = "|0101|0202|0303|0404|0505|0606|0707|0808|0909|1010|1111|1212|1313|1414|1515|07";
    const char* name = "|01P|02i|03p|04e|05c|06ol|07o|08r|09s |10l|11i|12b|13r|14a|15r|14y |130|12.|111|07";

    a = pcprintf("\n%s\n\n", name);
    b = pcprintf("%s\n", str);


}
