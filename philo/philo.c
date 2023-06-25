#include "philo.h"

int main(int ac, char** av) {
    t_info info;
    t_data  data;
    t_philo * philo;

    init_info(&info, ac, av);
    init_philo(&info,&philo, data);
    


    return 0;
}
