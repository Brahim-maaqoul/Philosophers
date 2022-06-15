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

#include "philosophers.h"

void	*ft_routine(void *philo)
{
	int	i;
	long	t;
	t_philo *philos;
	
	philos = (t_philo *) philo;
	i = philos->id;
	if (i % 2 == 0)
		usleep(100);
	while (!philos->info->is_finished || philos->info->ate_cp != philos->info->num_eat)
	{
		// if (philos->info->ate_cp == philos->info->num_eat)
			// return (NULL);
		ft_grab_fork(philos->info, i);
		ft_eating(philos->info, i);
		ft_sleeping(philos->info, i);
		ft_thinking(philos->info, i);
	}
	return (NULL);
}