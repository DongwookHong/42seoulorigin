#include <stdio.h>
char  *rew (int n)
{
    char rek[2] = "a";
    if(n ==1)
        return rek;
    else
        return 0;
}


int main(){

    char *pow;
    pow = rew(1);
    printf("%p\n",pow);
    printf("%p\n","abc");
}
