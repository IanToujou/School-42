/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 19:03:12 by ibour             #+#    #+#             */
/*   Updated: 2025/02/10 10:05:01 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# define TRUE 		1
# define FALSE		0

# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# include "errortype.h"

typedef struct s_philosopher
{
	int					id;
	int					last_meal;
	int					is_eating;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_meals;
	pthread_t			thread_id;
	struct s_data		*general;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}	t_philosopher;

typedef struct s_data
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_sleep;
	int					time_to_eat;
	int					number_of_meals;
	int					start;
	int					philosopher_dead;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		mutex;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_philosopher		*philosophers;
}	t_data;

void	ft_throw_error(int error);

int		ft_init_data(t_data *data, char **argv);
void	ft_init_thread_main(t_data *data);
void	ft_init_join(const t_data *data);
void	*ft_init_monitoring(void *arg);

void	*ft_thread_philosopher(void *args);

int		ft_util_atoi(const char *str);
long	ft_util_atol(const char *str);
void	ft_util_msg(char *msg, const t_philosopher *philosopher);
int		ft_util_str_is_num(const char *str);
char	*ft_util_str_get_name(int num);
int		ft_util_validate_args(int argc);
int		ft_util_validate_num(char **argv);
int		ft_util_validate_limits(char **argv);
void	ft_util_sleep(int time, const t_philosopher *philosopher);
int		ft_util_time(void);
void	ft_util_free(const t_data *data);

int		ft_util_philosopher_is_dead(const t_philosopher *philosopher);
int		ft_util_philosopher_take_forks(const t_philosopher *philosopher);
void	ft_util_philosopher_eat(t_philosopher *philosopher);
void	ft_util_philosopher_sleep(t_philosopher *philosopher);
void	ft_util_philosopher_think(const t_philosopher *philosopher);

#endif
