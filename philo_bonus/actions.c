/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:40 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/27 20:32:09 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_thinking(t_infos *inf, int i)
{
	print_str(inf, "is thinking", i);
}

void	ft_grab_fork(t_infos *inf)
{
	sem_wait(inf->forks);
}

void	ft_eating(t_infos *inf, int i)
{
	print_str(inf, "has taken a fork", i);
	if (i + 1 == inf->num_phil)
	{
		ft_grab_fork(inf);
		print_str(inf, "has taken a fork", i);
	}
	else
	{
		ft_grab_fork(inf);
		print_str(inf, "has taken a fork", i);
	}
	print_str(inf, "is eating", i);
	inf->ph[i].num++;
	inf->ph[i].last_meal = ft_gettime();
	usleep(1000 * inf->time_eat);
	sem_post(inf->forks);
	if (i + 1 == inf->num_phil)
		sem_post(inf->forks);
	else
		sem_post(inf->forks);
	if (inf->ph[i].num == inf->num_eat)
		exit(0);
}

void	ft_sleeping(t_infos *inf, int i)
{
	print_str(inf, "is sleeping", i);
	usleep(1000 * inf->time_sleep);
}

int	ft_dying(t_infos *inf, int i)
{
	if (ft_gettime() - inf->ph[i].last_meal > inf->time_die)
	{
		sem_wait(inf->output);
		print_str(inf, "died", i);
		inf->is_finished = 1;
		return (1);
	}
	return (0);
}
