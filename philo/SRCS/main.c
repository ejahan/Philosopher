/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:31:06 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/16 10:17:52 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

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
	while (i < all->data.number_of_philosophers)
	{
		pthread_mutex_init(&all->data.fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&all->data.mutex_death, NULL);
	start_philo(all->data.number_of_philosophers, all);
	i = 0;
	while (i < all->data.number_of_philosophers)
	{
		pthread_mutex_destroy(&all->data.fork[i]);
		i++;
	}
	pthread_mutex_destroy(&all->data.mutex_death);
	free(all->philo);
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

	// printf("num of philo = %d\n", data->number_of_philosophers);
	// printf("die = %d\n", data->time_to_die);
	// printf("eat = %d\n", data->time_to_eat);
	// printf("sleep = %d\n", data->time_to_sleep);
	// if (data->exist == 1)
	// 	printf("num of time = %d\n",
			// data->number_of_times_each_philosopher_must_eat);
