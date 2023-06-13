#include "pipex.h"

int main(int ac, char ** av, char **envp)
{
    t_base base;
    t_here here;
    if (ac < 5)
        file_error("Check arguments");
    here.check_here = check_exist(ac,av);
	if (here.check_here)
	{
		if (ac < 6)
			file_error("Check arguments");
		here.file_num = ac-4;
        init_here(ac,av,&here);
        combine(ac, av, &here);
        ft_bonus_path(envp,&here);
        bonus_execute(&here,av,envp);
	}
	else
    {
		base.file_num = ac - 3;
        init_pipex(ac,av,&base);
        ft_path(envp,&base);
        execute(&base,av,envp);
    }
    return (0);
}
