#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "hash.h"
#include "bulit.h"
#include "../libft/libft.h"


typedef struct termios term;
typedef struct sigaction sig;

/*signal*/
void main_signal();

#endif
