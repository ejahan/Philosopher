/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 03:33:35 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/16 10:25:04 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

int	philo_sleep(t_philo *philo, int nb)
{
	long long int	i;

	if (check_death_or_time(philo) == -1)
		return (-1);
	i = get_time(philo->time);
	printf("\033[1;34m%lld %d is sleeping\033[0m\n", i, nb);
	usleep(philo->data->time_to_sleep * 1000);
	return (0);
}

int	philo_eat(t_philo *philo, int nb)
{
	struct timeval	time;

	if (check_death_or_time(philo) == -1)
		return (-1);
	printf("\033[1;32m%lld %d is eating\033[0m\n", get_time(philo->time), nb);
	usleep(philo->data->time_to_eat * 1000);
	gettimeofday(&time, NULL);
	philo->time_last_meal = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (0);
}
