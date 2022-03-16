/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:10:37 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/16 07:01:46 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

int	get_forks(t_philo *philo, t_data *data, int nb)
{
	pthread_mutex_lock(&data->fork[philo->fork_right]);
	if (get_time(philo->time_last_meal) >= philo->data->time_to_die)
	{
		pthread_mutex_unlock(&data->fork[philo->fork_right]);
		return (-1);
	}
	printf("\033[1;35m%lld %d has taken a fork\033[0m\n", get_time(philo->time), nb);
	pthread_mutex_lock(&data->fork[philo->fork_left]);
	if (get_time(philo->time_last_meal) >= philo->data->time_to_die)
	{
		pthread_mutex_unlock(&data->fork[philo->fork_right]);
		pthread_mutex_unlock(&data->fork[philo->fork_left]);
		return (-1);
	}
	printf("\033[1;35m%lld %d has taken a fork\033[0m\n", get_time(philo->time), nb);
	if (philo_eat(philo, nb) == -1)
	{
		pthread_mutex_unlock(&data->fork[philo->fork_right]);
		pthread_mutex_unlock(&data->fork[philo->fork_left]);
		return (-1);
	}
	pthread_mutex_unlock(&data->fork[philo->fork_right]);
	pthread_mutex_unlock(&data->fork[philo->fork_left]);
	return (0);
}

void	*fonction(void *arg)
{
	t_philo			*philo;
	struct timeval	time;

	philo = (t_philo *)arg;
	gettimeofday(&time, NULL);
	philo->time = (time.tv_sec * 1000 + time.tv_usec / 1000);
	philo->time_last_meal = (time.tv_sec * 1000 + time.tv_usec / 1000);
	if (philo->nb %2 == 1)
		usleep(3000);
	while (1)
	{
		if (philo->data->exist == 1 && philo->nb_of_meal
			>= philo->data->number_of_times_each_philosopher_must_eat)
			return (NULL);
		philo->nb_of_meal++;
		if (get_forks(philo, philo->data, philo->nb) == -1)
		{
			printf("DEAD\n");
			return (NULL);
		}
		if (philo_sleep(philo, philo->nb) == -1)
		{
			printf("DEAD\n");
			return (NULL);
		}
		if (get_time(philo->time_last_meal) >= philo->data->time_to_die)
		{
			printf("DEAD\n");
			printf("last meal = %lld\n", philo->time_last_meal);
			return (NULL);
		}
		printf("\033[1;36m%lld %d is thinking\033[0m\n", get_time(philo->time), philo->nb);
	}
	return (philo);
}
