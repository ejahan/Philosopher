/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 01:05:22 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/08 03:50:28 by ejahan           ###   ########.fr       */
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

int	check_digit(char *str)
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

int	check_max(char *str)
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

int	check_int(char **av, int ac)
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
