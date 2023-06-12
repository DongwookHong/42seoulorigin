#include "pipex.h"

int main(int ac, char ** av, char **envp)
{
    t_base base;
    if (ac != 5 )
        error("Check arguments");
    init_pipex(ac,av,&base);
    ft_path(envp,&base);
    execute(&base,av,envp);
    return (0);
}
