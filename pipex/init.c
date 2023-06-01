#include "pipex.h"


void init_pipex(int ac,t_base *base)
{
    base->infile =0;
    base->outfile =0;
    base->file_num = ac-3;
    base->com = (t_pid *)malloc(base->file_num * sizeof(t_pid));
    if (base->com == NULL) {
        return;
    }
    char **path = NULL;
}