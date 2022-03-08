/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:09:58 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/08 04:45:05 by ejahan           ###   ########.fr       */
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
	int	error;
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	exist;
	int	number_of_times_each_philosopher_must_eat;
	
}	t_philo;

t_philo	*parsing(int ac, char **av, t_philo *philo);
long	ft_atoi(const char *str);
int		check_digit(char *str);
int		check_max(char *str);
int		check_int(char **av, int ac);
int		ft_isdigit(int c);

#endif