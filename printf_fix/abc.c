#include <string.h>
#include <stdio.h>
int main()
{
    char *abc = "%";
    
    
    if(strchr(abc, 37))
        printf("1");
    else
         printf("00000\n");
}