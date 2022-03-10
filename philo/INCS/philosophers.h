/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:09:58 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/10 05:13:01 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_philo
{
	pthread_mutex_t	fork;
	pthread_t		thread;
	int				time;
}	t_philo;

typedef struct s_data
{
	int		error;
	int		number_of_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		exist;
	int		number_of_times_each_philosopher_must_eat;
	t_philo	*philo;
	
}	t_data;

void	parsing(int ac, char **av, t_data *data);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
