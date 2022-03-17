/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 10:23:44 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/17 14:43:33 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

int	check_all_philo_meal(t_struct *all)
{
	int	i;

	i = 0;
	if (all->data.exist == 0)
		return (0);
	while (i < all->data.number_of_philosophers)
	{
		pthread_mutex_lock(&all->philo[i].mutex_nb_of_meal);
		if (all->philo[i].nb_of_meal
			< all->data.number_of_times_each_philosopher_must_eat)
		{
			pthread_mutex_unlock(&all->philo[i].mutex_nb_of_meal);
			return (0);
		}
		pthread_mutex_unlock(&all->philo[i].mutex_nb_of_meal);
		i++;
	}
	pthread_mutex_lock(&all->data.mutex_enough);
	all->data.enough = 1;
	pthread_mutex_unlock(&all->data.mutex_enough);
	return (1);
}

int	check_philo_dead(t_struct *all, int i)
{
	pthread_mutex_lock(&all->philo[i].mutex_last_meal);
	pthread_mutex_lock(&all->philo[i].mutex_time);
	if (get_time(all->philo[i].time_last_meal)
		> all->data.time_to_die)
	{
		pthread_mutex_lock(&all->data.mutex_death);
		all->data.death = 1;
		pthread_mutex_unlock(&all->data.mutex_death);
		printf("\033[1;31m%lld %d died\033[0m\n",
			get_time(all->philo[i].time), i + 1);
		pthread_mutex_unlock(&all->philo[i].mutex_last_meal);
		pthread_mutex_unlock(&all->philo[i].mutex_time);
		return (1);
	}
	pthread_mutex_unlock(&all->philo[i].mutex_last_meal);
	pthread_mutex_unlock(&all->philo[i].mutex_time);
	return (0);
}
