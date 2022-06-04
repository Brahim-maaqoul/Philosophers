/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:28:00 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/04 23:28:01 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *philo)
{
	int	i;
	long	t;
	t_infos *inf;
	
	i = 0;
	inf = (t_infos *) philo;
	// inf->ph = ft_calloc(inf->num_phil, sizeof(t_infos*));
	t = ft_gettime();
	// usleep (200 * 1000);
	inf->created_at = ft_current_time(inf, t);
	while (i < inf->num_phil)
	{
		ft_grab_fork(inf, i);
		ft_eating(inf, i);
		ft_sleeping(inf, i);
		ft_thinking(inf, i);
		// printf("NYO-HO\n");
		i++;
		if (i == inf->num_phil)
			i = 0;
	}
	return (NULL);
}