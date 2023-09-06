
#include "../includes/bonus.h"

int main(int ac, char **av)
{
    t_info info;
    init_info(&info, ac, av);
    init_sem(&info);

    philo_act(info);
}