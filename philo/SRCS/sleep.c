/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 03:33:35 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/15 03:56:14 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

void	philo_sleep(long time, long time_to_sleep, int nb)
{
	printf("%ld %d is sleeping\n", time, nb);
	usleep(time_to_sleep * 1000);
}

void	philo_eat(long time, long time_to_eat, t_philo *philo)
{
	printf("%ld %d is eating\n", time, philo->nb);
	usleep(time_to_eat * 1000);
	philo->time_last_meal = get_time(philo->time);
}
