/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:10:37 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/17 16:04:35 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

int	eat_unlock(t_philo *philo, t_data *data, int nb)
{
	if (philo_eat(philo, nb) == -1)
	{
		pthread_mutex_unlock(&data->fork[philo->fork_right]);
		pthread_mutex_unlock(&data->fork[philo->fork_left]);
		return (-1);
	}
	pthread_mutex_unlock(&data->fork[philo->fork_right]);
	pthread_mutex_unlock(&data->fork[philo->fork_left]);
	if (check_death_or_time(philo) == -1)
		return (-1);
	return (0);
}

int	get_forks(t_philo *philo, t_data *data, int nb)
{
	pthread_mutex_lock(&data->fork[philo->fork_right]);
	if (check_death_or_time(philo) == -1)
	{
		pthread_mutex_unlock(&data->fork[philo->fork_right]);
		return (-1);
	}
	printf("\033[1;35m%lld %d has taken a fork\033[0m\n",
		get_time(philo->time), nb);
	if (check_death_or_time(philo) == -1 || data->number_of_philosophers == 1)
	{
		pthread_mutex_unlock(&data->fork[philo->fork_right]);
		return (-1);
	}
	pthread_mutex_lock(&data->fork[philo->fork_left]);
	if (check_death_or_time(philo) == -1 || data->number_of_philosophers == 1)
	{
		pthread_mutex_unlock(&data->fork[philo->fork_right]);
		pthread_mutex_unlock(&data->fork[philo->fork_left]);
		return (-1);
	}
	printf("\033[1;35m%lld %d has taken a fork\033[0m\n",
		get_time(philo->time), nb);
	return (eat_unlock(philo, data, nb));
}

void	*fonction(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	init_time(philo);
	if (philo->nb % 2 == 1)
		usleep(3000);
	while (1)
	{
		if (check_death_or_time(philo) == -1)
			return (NULL);
		if (get_forks(philo, philo->data, philo->nb) == -1)
			return (NULL);
		if (check_death_or_time(philo) == -1)
			return (NULL);
		if (philo_sleep(philo, philo->nb) == -1)
			return (NULL);
		if (check_death_or_time(philo) == -1)
			return (NULL);
		printf("\033[1;36m%lld %d is thinking\033[0m\n",
			get_time(philo->time), philo->nb);
	}
	return (philo);
}

void	*check_death(void *arg)
{
	t_struct	*all;
	int			i;

	all = (t_struct *)arg;
	usleep(3050);
	while (1)
	{
		i = 0;
		if (check_all_philo_meal(all) == 1)
			return (NULL);
		while (i < all->data.number_of_philosophers)
		{
			if (check_philo_dead(all, i) == 1)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
