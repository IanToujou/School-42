#include "../../include/philosophers.h"

void    ft_init_thread_main(t_data *data)
{
    int i;

    i = 0;
    data->starting_time = ft_util_time();
    while (i < data->number_of_philosophers)
    {
        pthread_create(&data->philosophers[i].thread_id, NULL, &ft_thread_philosopher, (void *) &data->philosophers[i]);
    }
}
