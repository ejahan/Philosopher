/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:09:58 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/15 05:38:50 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_data
{
	int				error;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				exist;
	int				number_of_times_each_philosopher_must_eat;
	pthread_t		death;
	pthread_mutex_t	*fork;
}	t_data;

typedef struct s_philo
{
	pthread_t	thread;
	int			nb;
	int			fork_right;
	int			fork_left;
	long		time;
	long		time_last_meal;
	t_data		*data;
}	t_philo;

typedef struct s_struct
{
	t_data	data;
	t_philo	*philo;
}	t_struct;

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
void	*fonction(void *data);
t_philo	*init_philo(t_data *data);
void	parsing(int ac, char **av, t_data *data);
void	start_philo(int nb, t_struct *all);

#endif
