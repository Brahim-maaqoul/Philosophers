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

// void	*ft_routine(void *philo)
// {
// 	int	i;
// 	long	t;
// 	t_infos *inf;
	
// 	i = 0;
// 	inf = (t_infos *) philo;
// 	// inf->ph = ft_calloc(inf->num_phil, sizeof(t_infos*));
// 	// usleep (200 * 1000);
// 	inf->created_at = ft_gettime();
// 	while (1)
// 	{
// 		i = 0;
// 		while (i < inf->num_phil)
// 		{
// 			ft_grab_fork(inf, i);
// 			ft_eating(inf, i);
// 			ft_sleeping(inf, i);
// 			ft_thinking(inf, i);
// 			// if (ft_dying(inf, i))
// 			// 	return (NULL);
// 			// printf("NYO-HO\n");
// 			i++;
// 			// if (i == inf->num_phil)
// 			// 	i = 0;
// 			// usleep (200);
// 		}
// 	}
// 	return (NULL);
// }

void	*ft_routine(void *philo)
{
	int	i;
	long	t;
	t_philo *philos;
	
	philos = (t_philo *) philo;
	i = philos->id;
	if (i % 2 == 0)
		usleep(200);
	while (!philos->info->is_finished)
	{
		ft_grab_fork(philos->info, i);
		ft_eating(philos->info, i);
		ft_sleeping(philos->info, i);
		ft_thinking(philos->info, i);
	}
	return (NULL);
}