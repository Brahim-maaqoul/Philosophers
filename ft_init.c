/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:22:19 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/05/27 00:14:57 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_init_philos(t_infos *info)
{
	int	i;

	i = 0;
	while (i < info->num_phil)
	{
		info->ph[i].id = 0;
		info->ph[i].is_finished = 0;
		info->ph[i].last_meal = 0;
		pthread_create(&info->ph[i].th, NULL, &ft_routine, NULL);
		usleep(100);
		i++;
	}
	return (NULL);
}

void	*ft_init(t_infos *info)
{
	info->ph = ft_calloc(info->num_phil, sizeof(t_philo*));
	info->forks = ft_calloc(info->num_phil, sizeof(pthread_mutex_t*));
	if (!info->ph || !info->forks)
		return (NULL);
	int	i;

	i = 0;
	pthread_mutex_init(&info->output, NULL);
	while (i < info->num_phil)
		pthread_mutex_init(&info->forks[i++], NULL);
	ft_init_philos(info);
	return (NULL);
}