/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 02:42:52 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/05 21:39:16 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_infos	info;

	if (ac == 5 || ac == 6)
	{
		if (!ft_parsing(av))
			return (0);
		info.num_phil = ft_atoi(av[1]);
		info.time_die = ft_atoi(av[2]);
		info.time_eat = ft_atoi(av[3]);
		info.time_sleep = ft_atoi(av[4]);
		if (ac == 6)
			info.num_eat = ft_atoi(av[5]);
		if (!check_args(&info, ac))
			return (0);
		if (!ft_init(&info))
			return (0);
	}
	else
	{
		printf("you need to enter valid arguments!\n");
		return (0);
	}
}
