
// #include "../../incs/minishell.h"

// void	new_prompt_handler(int signo)
// {
// 	if (signo == SIGINT)
// 	{
// 		rl_replace_line("", 0);
// 		write (1, "\n", 1);
// 		rl_on_new_line();
// 		rl_redisplay();
// 		g_exit_status = 1;
// 	}
// }

// void	child_handler(int signo)
// {
// 	(void) signo;
//     write(STDERR_FILENO, "", ft_strlen(""));
// 	write(STDERR_FILENO, "\n", 1);
// 	exit(1);
// }

// void	default_signal(void)
// {
// 	signal(SIGINT, new_prompt_handler);
// 	signal(SIGQUIT, SIG_IGN);
// }

// void	herdoc_signal(void)
// {
// 	signal(SIGINT, child_handler); //  자식 프로세스는 부모랑 다르게 ctrl+c 를 누를경우 종료가됨 
// }

