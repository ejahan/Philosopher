/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:10:37 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/15 10:04:47 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

void	get_fork_right(int nb, t_data *data)
{
	pthread_mutex_lock(data->fork[nb]);
	printf("%ld %d has taken a fork", get_time(data->start_time), nb);
}

void	get_fork_left(int nb, t_data *data)
{
	pthread_mutex_lock(data->fork[nb]);
	printf("%ld %d has taken a fork", get_time(data->start_time), nb);
}

void	get_forks(int i, int j, t_data *data)
{
	get_fork_right(philo->fork_right, philo->data);
	get_fork_left(philo->fork_left, philo->data);
}

void	*fonction(void *arg)
{
	t_philo		*philo;
	int			i;

	i = 0;
	philo = (t_philo *)arg;
	if (philo->nb %2 == 1)
		usleep(3000);
	while (i < 5)
	{
		get_forks(philo->fork_right, philo->fork_left, philo->data);
		philo_eat(time, philo->data->time_to_eat, philo->nb);
		// si mort -> return (NULL);
		
		i++;
	}
	return (philo);
}
