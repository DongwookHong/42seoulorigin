#include "pipex.h"

int main(int ac, char ** av, char **envp)
{
    t_base base;
  
    if (ac !=5 )
        return (0);
    init_pipex(ac,av,&base);
    ft_path(envp,&base);
    execute(&base,av,envp);
}
