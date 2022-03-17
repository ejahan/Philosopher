/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 03:33:35 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/17 09:56:24 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

int	philo_sleep(t_philo *philo, int nb)
{
	long long int	i;

	if (check_death_or_time(philo) == -1)
		return (-1);
	pthread_mutex_lock(&philo->mutex_time);
	i = get_time(philo->time);
	pthread_mutex_unlock(&philo->mutex_time);
	printf("\033[1;34m%lld %d is sleeping\033[0m\n", i, nb);
	usleep(philo->data->time_to_sleep * 1000);
	if (check_death_or_time(philo) == -1)
		return (-1);
	return (0);
}

int	philo_eat(t_philo *philo, int nb)
{
	struct timeval	time;

	if (check_death_or_time(philo) == -1)
		return (-1);
	pthread_mutex_lock(&philo->mutex_time);
	printf("\033[1;32m%lld %d is eating\033[0m\n", get_time(philo->time), nb);
	pthread_mutex_unlock(&philo->mutex_time);
	usleep(philo->data->time_to_eat * 1000);
	gettimeofday(&time, NULL);
	pthread_mutex_lock(&philo->mutex_last_meal);
	philo->time_last_meal = (time.tv_sec * 1000 + time.tv_usec / 1000);
	pthread_mutex_unlock(&philo->mutex_last_meal);
	return (0);
}
