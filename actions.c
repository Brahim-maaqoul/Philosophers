/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:40 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/05 12:03:03 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_thinking(t_infos *inf, int i)
{
	mutex_print_str(inf, "is thinking", i);
}

void	ft_grab_fork(t_infos *inf, int i)
{
	pthread_mutex_lock(&inf->forks[i]);
	mutex_print_str(inf, "has taken a fork", i);
	inf->b = 1;
}

void	ft_eating(t_infos *inf, int i)
{
	long	t;

	t = ft_gettime();
	if (inf->b != 0)
	{
		if (i == inf->num_phil)
			i = 0;
		// ft_grab_fork(inf, i);
		mutex_print_str(inf, "has taken a fork", i);
		inf->b = 0;
	}
	inf->ph[i].last_meal = ft_current_time(inf, t);
	mutex_print_str(inf, "is eating", i);
		// pthread_mutex_unlock(&inf->forks[i]);
	pthread_mutex_unlock(&inf->forks[i]);
	usleep(inf->time_eat * 1000);
}

void	ft_sleeping(t_infos *inf, int i)
{
	mutex_print_str(inf, "is sleeping", i);
	usleep(inf->time_sleep * 1000);
}

void	ft_dying(t_infos *inf, int i)
{
	if (inf->ph[i].last_meal > inf->time_die)
	{
		mutex_print_str(inf, "died", i);
		inf->ph[i].is_finished = 1;
	}
}