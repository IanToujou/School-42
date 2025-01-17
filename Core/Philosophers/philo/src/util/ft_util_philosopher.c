#include "../../include/philosophers.h"

int ft_util_philosopher_is_dead(t_philosopher *philosopher)
{
    pthread_mutex_lock(&philosopher->general->mutex);
    if (philosopher->general->philosopher_dead == 1)
    {
        pthread_mutex_unlock(&philosopher->general->mutex);
        return (1);
    }
    pthread_mutex_unlock(&philosopher->general->mutex);
    return (0);
}

int     ft_util_philosopher_take_forks(t_philosopher* philosopher)
{
    if (philosopher->id % 2 == 0)
        pthread_mutex_lock(philosopher->general->right_fork);
    else
        pthread_mutex_lock(philosopher->general->left_fork);
    // todo grab forks
    return (0);
}

void    ft_util_philosopher_eat(t_philosopher *philosopher)
{
    // todo eat
}

void    ft_util_philosopher_sleep(t_philosopher *philosopher)
{
    ft_util_print("is sleeping", philosopher);
    ft_util_sleep(philosopher->general->time_to_sleep, philosopher);
}

void    ft_util_philosopher_think(t_philosopher *philosopher)
{
    ft_util_print("is thinking", philosopher);
}
