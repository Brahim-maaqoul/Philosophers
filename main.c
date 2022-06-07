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

#include "philosophers.h"

int main(int ac, char **av)
{
	t_infos	info;

	// info = ft_calloc(5, sizeof(t_infos*));
	// ft_parsing(&info, ac, av);
	info.num_phil = ft_atoi(av[1]);
    info.time_die = ft_atoi(av[2]);
    info.time_eat = ft_atoi(av[3]);
    info.time_sleep = ft_atoi(av[4]);
	// info.num_eat = ft_atoi(av[5]);
	if (!ft_init(&info))
		return (0);
	// int i = 0;
	// while (i < info->num_phil)
	// {
	// 	pthread_join(info->ph[i].th, NULL);
	// 	i++;
	// }
	// i = 0;
	// pthread_mutex_destroy(info->forks);
	// while (i < info->num_phil)
	// 	pthread_mutex_init(&info->forks[i++], NULL);
	// pthread_mutex_destroy(&info->output);
}