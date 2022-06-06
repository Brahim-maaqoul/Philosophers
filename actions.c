/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:40 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/06 15:18:27 by bmaaqoul         ###   ########.fr       */
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
		ft_grab_fork(inf, i + 1);
		mutex_print_str(inf, "has taken a fork", i);
		mutex_print_str(inf, "has taken a fork", i);
		inf->b = 0;
	}
	inf->ph[i].last_meal = ft_gettime();
	mutex_print_str(inf, "is eating", i);
		// pthread_mutex_unlock(&inf->forks[i]);
	pthread_mutex_unlock(&inf->forks[i]);
	pthread_mutex_unlock(&inf->forks[i + 1]);
	usleep(inf->time_eat);
}

void	ft_sleeping(t_infos *inf, int i)
{
	mutex_print_str(inf, "is sleeping", i);
	usleep(inf->time_sleep * 1000);
}

void	ft_dying(t_infos *inf, int i)
{
	if (ft_gettime() - inf->ph[i].last_meal > inf->time_die)
	{
		mutex_print_str(inf, "died", i);
		inf->is_finished = 1;
	}
}