/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:28:00 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/07/16 15:01:04 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_check_death(void *ph)
{
	int		i;
	t_philo	*philo;

	philo = (t_philo *)ph;
	i = philo->id;
	while (1)
	{
		if (ft_dying(philo->info, i))
		{
			sem_post(philo->info->stop);
			exit (0);
		}
	}
	return (NULL);
}

void	*check_stop(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	sem_wait(philo->info->stop);
	sem_post(philo->info->stop);
	exit(0);
}

void	ft_routine(t_philo *philo)
{
	int			i;
	pthread_t	th;

	i = philo->id;
	pthread_create(&philo->th, NULL, &ft_check_death, philo);
	pthread_create(&th, NULL, &check_stop, philo);
	if (i % 2)
		usleep(100);
	while (!philo->info->is_finished)
	{
		ft_grab_fork(philo->info);
		ft_eating(philo->info, i);
		ft_sleeping(philo->info, i);
		ft_thinking(philo->info, i);
	}
}
