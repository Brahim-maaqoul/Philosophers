/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:22:19 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/06 15:18:10 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_init_philos(t_infos *info)
{
	int	i;

	info->ph = ft_calloc(info->num_phil, sizeof(t_philo*));
	if (!info->ph)
		return (NULL);
	i = 0;
	// pthread_detach(info->ph[i].th);
	info->is_finished = 0;
	while (i < info->num_phil)
	{
		info->ph[i].last_meal = 0;
		info->ph[i].id = i + 1;
		if (pthread_create(&info->ph[i].th, NULL, &ft_routine, info) != 0)
			return NULL;
		usleep(100);
		i++;
	}
	return (NULL);
}

void	ft_init(t_infos *info)
{
	info->forks = ft_calloc(info->num_phil, sizeof(pthread_mutex_t*));
	if (!info->forks)
		return ;
	int	i;

	i = 0;
	while (i < info->num_phil)
	{
		if (pthread_mutex_init(&info->forks[i++], NULL) != 0)
			return ;
	}
	if (pthread_mutex_init(&info->output, NULL) != 0)
		return ;
	i = 0;
	ft_init_philos(info);
	while (i < info->num_phil)
	{
		if (pthread_join(info->ph[i].th, NULL) != 0)
			break;
		i++;
	}
	// return (NULL);
}

// int main(int ac, char **av)
// {
// 	t_infos	*info;

// 	// info = ft_calloc(5, sizeof(t_infos*));
// 	// ft_parsing(info, ac, av);
// 	info->num_phil = ft_atoi(av[1]);
//     info->time_die = ft_atoi(av[2]);
//     info->time_eat = ft_atoi(av[3]);
//     info->time_sleep = ft_atoi(av[4]);
// 	// info->num_eat = ft_atoi(av[5]);
// 	// ft_init(info);
// 	// i = 0;
// 	// pthread_mutex_destroy(info->forks);
// 	// while (i < info->num_phil)
// 	// 	pthread_mutex_init(&info->forks[i++], NULL);
// 	// pthread_mutex_destroy(&info->output);
// }