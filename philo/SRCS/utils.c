/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:05:22 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/17 14:16:33 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

long	ft_atoi(const char *str)
{
	int		i;
	int		n;
	long	nb;

	i = 0;
	n = 0;
	nb = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		n = 1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (n == 1)
		nb = -nb;
	return (nb);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long long int	get_time(long long int start_time)
{
	long long int	time;
	struct timeval	t;

	gettimeofday(&t, NULL);
	time = t.tv_sec * 1000 + t.tv_usec / 1000;
	time -= start_time;
	return (time);
}

int	check_death_or_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mutex_enough);
	if (philo->data->enough == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex_enough);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->mutex_enough);
	pthread_mutex_lock(&philo->data->mutex_death);
	if (philo->data->death == 1)
	{
		pthread_mutex_unlock(&philo->data->mutex_death);
		return (-1);
	}
	pthread_mutex_unlock(&philo->data->mutex_death);
	return (0);
}
