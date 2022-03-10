/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 00:38:45 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/10 01:33:20 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/philosophers.h"

static int	check_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		while (ft_isdigit(str[i]) == 1)
			i++;
		while (str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] != '-' && ft_isdigit(str[i]) != 1)
			return (-1);
		if (str[i] == '-' && i >= 1 && str[i - 1] != ' ')
			return (-1);
	}
	if (str[i] != '\0')
		return (-1);
	return (1);
}

static int	check_max(char *str)
{
	int		i;
	long	check;

	i = 0;
	while (str[i])
	{
		check = ft_atoi(&str[i]);
		if (check > 2147483647 || check < 0)
		{
			printf("not a valid argument\n");
			return (-1);
		}
		while (str[i] == ' ')
			i++;
		if (str[i] == '-')
			i++;
		while (ft_isdigit(str[i]) == 1)
			i++;
	}
	return (1);
}

static int	check_int(char **av, int ac)
{
	int	i;
	int	j;

	j = ac - 1;
	while (j > 0)
	{
		i = 0;
		if (check_digit(av[j]) == -1)
		{
			printf("not a number\n");
			return (-1);
		}
		if (check_max(av[j]) == -1)
			return (-1);
		j--;
	}
	return (0);
}

void	parsing(int ac, char **av, t_data *data)
{
	data->error = 0;
	if (check_int(av, ac) == -1)
	{
		data->error = 1;
		return ;
	}
	data->number_of_philosophers = (int)ft_atoi(av[1]);
	if (data->number_of_philosophers < 1)
	{
		printf("to few philosophers :(\n");
		data->error = 1;
		return ;
	}
	data->time_to_die = (int)ft_atoi(av[2]);
	data->time_to_eat = (int)ft_atoi(av[3]);
	data->time_to_sleep = (int)ft_atoi(av[4]);
	data->exist = 0;
	if (ac == 6)
	{
		data->number_of_times_each_philosopher_must_eat = (int)ft_atoi(av[5]);
		data->exist = 1;
	}
}
