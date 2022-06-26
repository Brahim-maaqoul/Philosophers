/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:22:19 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/26 21:54:26 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_init_philos(t_infos *info)
{
	int	i;

	info->ph = ft_calloc(info->num_phil, sizeof(t_philo));
	if (!info->ph)
		return (NULL);
	i = 0;
	info->is_finished = 0;
	info->created_at = ft_gettime();
	while (i < info->num_phil)
	{
		info->ph[i].id = i;
		info->ph[i].num = 0;
		info->ph[i].info = info;
		info->ph[i].last_meal = ft_gettime();
		i++;
	}
	return (NULL);
}

void	ft_init_sem(t_infos *info)
{
	sem_unlink("forks");
	sem_unlink("output");
	sem_unlink("stop");
	info->forks = sem_open("forks", O_CREAT, 0, info->num_phil);
	info->output = sem_open("output", O_CREAT, 0, 1);
	info->stop = sem_open("stop", O_CREAT, 0, 0);
}

void	ft_waitpids(t_infos *info)
{
	int	i;

	i = 0;
	while (i < info->num_phil)
	{
		waitpid(info->pid[i], NULL, 0);
		i++;
	}
}

int	ft_init(t_infos *info)
{
	int	i;

	i = 0;
	ft_init_sem(info);
	ft_init_philos(info);
	info->pid = ft_calloc(info->num_phil, sizeof(pid_t));
	if (!info->pid)
		return (0);
	while (i < info->num_phil)
	{
		info->pid[i] = fork();
		if (info->pid[i] < 0)
			exit (1);
		else if (info->pid[i] == 0)
		{
			ft_routine(&info->ph[i]);
			exit(0);
		}
		i++;
	}
	ft_waitpids(info);
	ft_destroyer(info);
	return (1);
}
