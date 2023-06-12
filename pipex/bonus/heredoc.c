#include "pipex.h"


void check_here(int ac,char **av, t_base *base)
{
    
    int i =0;
    char *str;
    
    if (ft_strncmp("here_doc",av[1],9))
    {
        base->here_doc=open(av[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
        str =  get_next_line(STDIN_FILENO);
        while(str)
        {
            write(base->here_doc,str,ft_strlen(str));
            if(ft_strncmp(str ,av[2],ft_strlen(av[2]))==0)//strcmp;
                return ;
            str =  get_next_line(STDIN_FILENO);
        }  
    }  
}
//>> append 넣어주기 