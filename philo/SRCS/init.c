/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:07:07 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/10 07:00:25 by ejahan           ###   ########.fr       */
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
