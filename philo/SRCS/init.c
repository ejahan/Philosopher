/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:07:07 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/17 11:43:08 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

t_philo	*init_philo(t_struct *all)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * (all->data.number_of_philosophers));
	if (philo == NULL)
		return (NULL);
	while (i < all->data.number_of_philosophers)
	{
		philo[i].nb = i + 1;
		if (philo[i].nb == 1)
			philo[i].fork_right = all->data.number_of_philosophers - 1;
		else
			philo[i].fork_right = i - 1;
		philo[i].fork_left = i;
		philo[i].nb_of_meal = 0;
		philo[i].data = &all->data;
		// pthread_mutex_init(&philo[i].mutex_time, NULL);
		// pthread_mutex_init(&philo[i].mutex_last_meal, NULL);
		// pthread_mutex_init(&philo[i].mutex_nb_of_meal, NULL);
		i++;
	}
	philo->data->death = 0;
	return (philo);
}
