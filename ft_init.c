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

#include "philosophers.h"

void	*ft_init_philos(t_infos *info)
{
	int	i;

	info->ph = ft_calloc(info->num_phil, sizeof(t_philo));
	if (!info->ph)
		return (NULL);
	i = 0;
	// pthread_detach(info->ph[i].th);
	info->is_finished = 0;
	info->ate_cp = 0;
	info->created_at = ft_gettime();
	while (i < info->num_phil)
	{
		info->ph[i].id = i;
		info->ph[i].num = 0;
		info->ph[i].info = info;
		info->ph[i].last_meal = ft_gettime();
		if (pthread_create(&info->ph[i].th, NULL, &ft_routine, &info->ph[i]) != 0)
			return NULL;
		i++;
	}
	// usleep(500);
	return (NULL);
}

void	ft_check_death(t_infos *inf)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < inf->num_phil)
		{
			if (inf->ate_cp == inf->num_phil)
			{
				inf->is_finished = 1;
				return ;
			}
			if (ft_dying(inf, i))
				return ;
			i++;
		}
		// usleep(500);
	}
}

int	ft_init(t_infos *info)
{
	int	i;

	info->forks = ft_calloc(info->num_phil, sizeof(pthread_mutex_t));
	if (!info->forks)
		return (0);
	i = 0;
	while (i < info->num_phil)
	{
		if (pthread_mutex_init(&info->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&info->output, NULL) != 0)
		return (0);
	// i = 0;
	ft_init_philos(info);
	ft_check_death(info);
	// while (i < info->num_phil)
	// {
	// 	if (pthread_join(info->ph[i].th, NULL) != 0)
	// 		break;
	// 	i++;
	// }
	return (1);
}

// int main(int ac, char **av)
// {
// 	t_infos	*info;

// 	// info = ft_calloc(5, sizeof(t_infos*));
// 	// ft_parsing(info, ac, av);
// 	info->num_phil = ft_atoi(av[1]);
//     info->time_die = ft_atoi(av[2]);
//     info->time_eat = ft_atoi(av[3]);
//     info->time_sleep = ft_atoi(av[4]);
// 	// info->num_eat = ft_atoi(av[5]);
// 	// ft_init(info);
// 	// i = 0;
// 	// pthread_mutex_destroy(info->forks);
// 	// while (i < info->num_phil)
// 	// 	pthread_mutex_init(&info->forks[i++], NULL);
// 	// pthread_mutex_destroy(&info->output);
// }