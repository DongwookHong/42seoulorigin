#include "minishell.h"

void get_pwd()
{
    char *pwd = getcwd(NULL,0);
    printf("pwd:%s\n", pwd);
}

// void get_cd(t_list **list )
// {
//     // list -> 를 받기 
//     if (ft_lstsize(*list) == 1)
//         chdir()
//     access()   
// }

void get_export()
{
    
}