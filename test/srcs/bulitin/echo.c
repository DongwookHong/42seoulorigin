#include "../../incs/minishell.h"


static int check_n(char *str)
{
    int i=0;
    int flag =0;
    int len = ft_strlen(str);
    int cnt=0;
    while(str[i])
    {
        if(str[i] == '-')
        {
            ++i; 
            while(str[i] == 'n')
                cnt++;
        }
        ++i;
    }
    if (cnt == len -1)
        return 1;
    return 0; 
}
     
static int echo_link(char *str)
{
    int i =-1;
    int a;
    if(str[0]== '-')
        if (a= check_n(str))
            return  1;
    else 
        파이프가 있고 없고 의 경우를 따져봐야함 ! 
}