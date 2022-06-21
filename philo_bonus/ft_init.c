/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:22:19 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/06 15:18:10 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_init_philos(t_infos *info)
{
	int	i;

	info->ph = ft_calloc(info->num_phil, sizeof(t_philo));
	info->pid = ft_calloc(info->num_phil, sizeof(pid_t));
	if (!info->ph || !info->pid)
		return (NULL);
	i = 0;
	info->is_finished = 0;
	info->ate_cp = 0;
	info->created_at = ft_gettime();
	while (i < info->num_phil)
	{
		info->ph[i].id = i;
		info->ph[i].num = 0;
		info->ph[i].info = info;
		info->ph[i].last_meal = ft_gettime();
		pthread_create(&info->ph[i].th, NULL,&ft_check_death, info);
		i++;
	}
	return (NULL);
}

void	*ft_check_death(void *info)
{
	int		i;
	t_infos	*inf;

	inf = (t_infos *)info;
	while (1)
	{
		i = 0;
		while (i < inf->num_phil)
		{
			if (inf->ate_cp == inf->num_phil)
			{
				inf->is_finished = 1;
				exit (0);
			}
			if (ft_dying(inf, i))
				exit (0);
			i++;
		}
	}
	return (NULL);
}

int	ft_init(t_infos *info)
{
	int	i;

	info->forks = ft_calloc(info->num_phil, sizeof(sem_t));
	if (!info->forks)
		return (0);
	i = 0;
	sem_unlink("forks");
	sem_unlink("output");
	info->forks = sem_open("forks", O_CREAT, 0, info->num_phil);
	info->output = sem_open("output", O_CREAT, 0, 1);
	while (i < info->num_phil)
	{
		info->pid[i] = fork();
		if (info->pid[i] < 0)
			exit (1);
		else if (info->pid[i] == 0)
			ft_routine(&info->ph[i]);
		// waitpid(0, &info->pid[i], 0);
		i++;
	}
	ft_init_philos(info);
	// ft_check_death(info);
	ft_destroyer(info);
	return (1);
}
