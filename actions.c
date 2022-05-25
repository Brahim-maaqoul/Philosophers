/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:40 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/05/25 20:28:47 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thinking(t_infos *inf, int i)
{
	printf("%lld  %d is thinking\n", inf->ph[i].created_at, i);
}

void	ft_grab_fork(t_infos *inf, int i)
{
	pthread_mutex_lock(inf->ph[i].fork);
	printf("%lld  %d has taken a fork\n", inf->ph[i].created_at, i);
	pthread_mutex_unlock(inf->ph[i].fork);
	inf->b = 1;
}

void	ft_eating(t_infos *inf, int i)
{
	printf("%lld  %d is eating\n", inf->ph[i].created_at, i);
}

void	ft_sleeping(t_infos *inf, int i)
{
	printf("%lld  %d is sleeping\n", inf->ph[i].created_at, i);
	usleep(200 * 1000);
}

void	ft_dying(t_infos *inf, int i)
{
	printf("%lld  %d died\n", inf->ph[i].created_at, i);
}