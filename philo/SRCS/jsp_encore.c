/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsp_encore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 06:10:37 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/10 10:45:30 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

void	*fonction(void *data)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	// printf("je sais pas si ca veut dire que ca marche bien mais cest cool\n");
	printf("time = %ld\n", time.tv_sec);
	return (data);
}
