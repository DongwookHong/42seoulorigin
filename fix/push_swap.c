#include "push_swap.h"


void abc()
{
     system("leaks push_swap");
}

int main(int ac, char *av[])
{
    char **sp;
    t_info info;
    t_list *a;
    // t_list *b;

    // b= NULL;
    a= NULL;
    sp =NULL;
    ft_memset(&info, 0, sizeof(t_info));
    atexit(abc);
    sp = fix(ac, av);
    printf("%s",sp[0]);
    info.size =0;
    info.chunk=0;
    // changesp(&a, &b,info, sp);
    ft_lstclear(&a);
}

