/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:40 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/05/26 22:52:57 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thinking(t_infos *inf, int i)
{
	printf("%lld  %d is thinking\n", inf->created_at, i);
}

void	ft_grab_fork(t_infos *inf, int i)
{
	pthread_mutex_lock(&inf->forks[i]);
	printf("%lld  %d has taken a fork\n", inf->created_at, i);
	inf->b = 1;
}

void	ft_eating(t_infos *inf, int i)
{
	t_philo	*th;
	if (inf->b != 0)
	{
		if (i == inf->num_phil)
			i = 0;
		ft_grab_fork(inf, i + 1);
		inf->b = 0;
	}
	else
	{
		printf("%lld  %d is eating\n", inf->created_at, i);
		pthread_mutex_unlock(&inf->forks[i]);
		pthread_mutex_unlock(&inf->forks[i]);
	}
}

void	ft_sleeping(t_infos *inf, int i)
{
	printf("%lld  %d is sleeping\n", inf->created_at, i);
	usleep(inf->time_sleep * 1000);
}

void	ft_dying(t_infos *inf, int i)
{
	printf("%lld  %d died\n", inf->created_at, i);
}