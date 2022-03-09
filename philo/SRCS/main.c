/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:31:06 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/10 00:45:29 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

int	philosophers(int ac, char **av, t_philo *philo)
{
	parsing(ac, av, philo);
	if (philo->error == 1)
		return (-1);
	if (philo->number_of_times_each_philosopher_must_eat == 0
		&& philo->exist == 1)
		return (0);
	printf("num of philo = %d\n", philo->number_of_philosophers);
	printf("die = %d\n", philo->time_to_die);
	printf("eat = %d\n", philo->time_to_eat);
	printf("sleep = %d\n", philo->time_to_sleep);
	if (philo->exist == 1)
		printf("num of time = %d\n", philo->number_of_times_each_philosopher_must_eat);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	philo;

	(void)av;
	if (ac != 5 && ac != 6)
	{
		printf("wrong number of arguments\n");
		return (1);
	}
	if (philosophers(ac, av, &philo) == -1)
		return (1);
	return (0);
}

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]

	// printf("num of philo = %d\n", philo.number_of_philosophers);
	// printf("die = %d\n", philo.time_to_die);
	// printf("eat = %d\n", philo.time_to_eat);
	// printf("sleep = %d\n", philo.time_to_sleep);
	// if (philo.exist == 1)
	// 	printf("num of time = %d\n", philo.number_of_times_each_philosopher_must_eat);
