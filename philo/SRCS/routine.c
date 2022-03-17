/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:10:37 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/17 11:43:52 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

int	get_forks(t_philo *philo, t_data *data, int nb)
{
	if (check_death_or_time(philo) == -1)
	{
		pthread_mutex_unlock(&data->fork[philo->fork_right]);
		return (-1);
	}
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
	printf("\033[1;35m%lld %d has taken a fork\033[0m\n",
		get_time(philo->time), nb);
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
	pthread_mutex_lock(&philo->mutex_last_meal);
	philo->time_last_meal = (time.tv_sec * 1000 + time.tv_usec / 1000);
	pthread_mutex_unlock(&philo->mutex_last_meal);
	if (philo->nb % 2 == 1)
		usleep(3000);
	while (1)
	{
		if (check_death_or_time(philo) == -1)
			return (NULL);
		pthread_mutex_lock(&philo->mutex_nb_of_meal);
		if (philo->data->exist == 1 && philo->nb_of_meal
			>= philo->data->number_of_times_each_philosopher_must_eat)
			return (NULL);
		philo->nb_of_meal++;
		pthread_mutex_unlock(&philo->mutex_nb_of_meal);
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

// void	*check_death(void *arg)
// {
// 	t_struct	*all;
// 	int			i;

// 	i = 0;
// 	all = (t_struct *)arg;
// 	usleep(3000);
// 	while (1)
// 	{
// 		pthread_mutex_lock(&all->philo[i].mutex_last_meal);
// 		pthread_mutex_lock(&all->philo[i].mutex_time);
// 		if (get_time(all->philo[i].time_last_meal)
// 			> all->data.time_to_die)
// 		{
// 			pthread_mutex_lock(&all->data.mutex_death);
// 			all->data.death = 1;
// 			pthread_mutex_unlock(&all->data.mutex_death);
// 			printf("\033[1;31m%lld %d died\033[0m\n",
// 				get_time(all->philo[i].time), i + 1);
// 			pthread_mutex_unlock(&all->philo[i].mutex_last_meal);
// 			pthread_mutex_unlock(&all->philo[i].mutex_time);
// 			return (NULL);
// 		}
// 		pthread_mutex_unlock(&all->philo[i].mutex_last_meal);
// 		pthread_mutex_unlock(&all->philo[i].mutex_time);
// 		i++;
// 		if (i == all->data.number_of_philosophers)
// 			i = 0;
// 	}
// 	return (NULL);
// }

void	*check_death(void *arg)
{
	t_struct	*all;
	int			i;

	all = (t_struct *)arg;
	usleep(3000);
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
