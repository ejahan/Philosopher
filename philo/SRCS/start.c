/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 03:14:55 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/16 10:15:38 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

void	start_philo(int nb, t_struct *all)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (pthread_create(&all->philo[i].thread, NULL,
				&fonction, &all->philo[i]) != 0)
			return ;
		i++;
	}
	i = 0;
	while (i < nb)
	{
		if (pthread_join(all->philo[i].thread, NULL) != 0)
			return ;
		i++;
	}
}
