/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:02:57 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/02 17:42:31 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char n)
{
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}

int	ft_parsing(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
			{
				printf("you need to enter a number !");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(t_infos *info, int ac)
{
	if (info->num_phil <= 0 || info->time_die <= 0 || info->time_eat <= 0
		|| info->time_sleep <= 0)
	{
		printf("you need to enter valid number!\n");
		return (0);
	}
	if (ac == 6)
	{
		if (info->num_eat <= 0)
		{
			printf("you need to enter valid number!\n");
			return (0);
		}
	}
	return (1);
}
