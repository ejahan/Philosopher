/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:07:07 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/15 06:20:27 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

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
		philo[i].nb = i + 1;
		if (philo[i].nb == 1)
			philo[i].fork_right = data->number_of_philosophers;
		else
			philo[i].fork_right = philo[i].nb - 1;
		philo[i].fork_left = philo[i].nb;
		i++;
	}
	philo->data = data;
	return (philo);
}
