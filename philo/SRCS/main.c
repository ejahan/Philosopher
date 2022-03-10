/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:31:06 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/10 05:27:00 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

void	*fonction(void *data)
{
	printf("je sais pas si ca veut dire que ca marche bien mais cest cool\n");
	return (data);
}

t_philo	*init_philo(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * (data->number_of_philosophers));
	if (philo == NULL)
		return (NULL);
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&philo[i].thread, NULL, &fonction, data) != 0)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (NULL);
		i++;
	}
	return (philo);
}

int	philosophers(int ac, char **av, t_data *data)
{
	parsing(ac, av, data);
	if (data->error == 1)
		return (-1);
	if (data->number_of_times_each_philosopher_must_eat == 0
		&& data->exist == 1)
		return (0);
	data->philo = init_philo(data);
	if (data->philo == NULL)
		return (-1);
	free(data->philo);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac != 5 && ac != 6)
	{
		printf("wrong number of arguments\n");
		return (1);
	}
	if (philosophers(ac, av, &data) == -1)
		return (1);
	return (0);
}

// number_of_philosophers
// time_to_die
// time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]

	// printf("num of philo = %d\n", data->number_of_philosophers);
	// printf("die = %d\n", data->time_to_die);
	// printf("eat = %d\n", data->time_to_eat);
	// printf("sleep = %d\n", data->time_to_sleep);
	// if (data->exist == 1)
	// 	printf("num of time = %d\n",
			// data->number_of_times_each_philosopher_must_eat);
