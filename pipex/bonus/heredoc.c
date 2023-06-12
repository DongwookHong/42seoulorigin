#include "pipex.h"


void check_here(int ac,char **av, t_base *base)
{
    
    int i =0;
    char *str;
    
    if (ft_strncmp("here_doc",av[1],9))
    {
        base->heredoc_file=open(av[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
        // here_ doc 구분자 limiter 가 바로들어왔을때 종료 누수체크 
        str =  get_next_line(STDIN_FILENO);
        while(str) // 파일종료 
        {
            write(base->heredoc_file,str,ft_strlen(str));
            if(str == av[2])//strcmp;
                return ;
            str =  get_next_line(STDIN_FILENO);
        }  
    }  
}
//>> append 넣어주기 