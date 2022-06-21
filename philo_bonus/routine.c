/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:28:00 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/06 15:06:02 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	delay(int t)
{
	long long	start;

	start = ft_gettime();
	while (ft_gettime() - start < t)
		;
}

void	ft_routine(t_philo *philo)
{
	int		i;

	i = philo->id;
	if (i % 2 == 0)
		usleep(100);
	while (!philo->info->is_finished)
	{
		ft_grab_fork(philo->info, i);
		ft_eating(philo->info, i);
		ft_sleeping(philo->info, i);
		ft_thinking(philo->info, i);
	}
}
