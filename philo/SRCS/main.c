/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:31:06 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/17 16:06:32 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

void	init_mutex(t_struct *all)
{
	int	i;

	i = 0;
	while (i < all->data.number_of_philosophers)
	{
		pthread_mutex_init(&all->data.fork[i], NULL);
		pthread_mutex_init(&all->philo[i].mutex_time, NULL);
		pthread_mutex_init(&all->philo[i].mutex_last_meal, NULL);
		pthread_mutex_init(&all->philo[i].mutex_nb_of_meal, NULL);
		i++;
	}
	pthread_mutex_init(&all->data.mutex_death, NULL);
	pthread_mutex_init(&all->data.mutex_enough, NULL);
}

void	destroy_mutex(t_struct *all)
{
	int	i;

	i = 0;
	while (i < all->data.number_of_philosophers)
	{
		pthread_mutex_destroy(&all->data.fork[i]);
		pthread_mutex_destroy(&all->philo[i].mutex_time);
		pthread_mutex_destroy(&all->philo[i].mutex_last_meal);
		pthread_mutex_destroy(&all->philo[i].mutex_nb_of_meal);
		i++;
	}
	pthread_mutex_destroy(&all->data.mutex_death);
	pthread_mutex_destroy(&all->data.mutex_enough);
}

int	philosophers(int ac, char **av, t_struct *all)
{
	int	i;

	i = 0;
	parsing(ac, av, &all->data);
	if (all->data.error == 1)
		return (-1);
	if (all->data.number_of_times_each_philosopher_must_eat == 0
		&& all->data.exist == 1)
		return (0);
	all->philo = init_philo(all);
	if (all->philo == NULL)
		return (-1);
	all->data.fork
		= malloc(sizeof(pthread_mutex_t) * all->data.number_of_philosophers);
	if (all->data.fork == NULL)
		return (-1);
	init_mutex(all);
	start_philo(all->data.number_of_philosophers, all);
	destroy_mutex(all);
	free(all->philo);
	free(all->data.fork);
	return (0);
}

int	main(int ac, char **av)
{
	t_struct	all;

	(void)av;
	if (ac != 5 && ac != 6)
	{
		printf("wrong number of arguments\n");
		return (1);
	}
	if (philosophers(ac, av, &all) == -1)
		return (1);
	return (0);
}
