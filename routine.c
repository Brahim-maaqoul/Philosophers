/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:28:00 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/05/28 02:44:52 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *philo)
{
	int	i;
	t_infos *inf;
	
	i = 0;
	inf = (t_infos *) philo;
	inf->created_at = ft_current_time(inf);
	while (i < inf->num_phil)
	{
		ft_grab_fork(inf, i);
		ft_eating(inf, i);
		ft_sleeping(inf, i);
		ft_thinking(inf, i);
		i++;
	}
	return (NULL);
}