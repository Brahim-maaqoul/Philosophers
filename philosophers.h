/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:19:43 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/06 15:39:35 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int     id;
	long     last_meal;
	pthread_t   th;
}       t_philo;

typedef struct  s_infos
{
	t_philo *ph;
	int 		num_phil;
	int			time_die;
	int 		time_eat;
	int 		time_sleep;
	int 		num_eat;
	int     is_finished;
	pthread_mutex_t *forks;
	pthread_mutex_t	output;
	long long	created_at;
	int	ate;
	int     b;
}       t_infos;

int		ft_atoi(const char	*str);
int    ft_parsing(t_infos *info, int ac, char **av);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
long long	ft_current_time(t_infos *inf, long i);
long long ft_gettime(void);
void	mutex_print_str(t_infos *inf, char *str, int i);
void	*ft_routine(void *philo);
int		ft_init(t_infos *info);
void	*ft_init_philos(t_infos *info);
void	ft_thinking(t_infos *inf, int i);
void	ft_eating(t_infos *inf, int i);
void	ft_sleeping(t_infos *inf, int i);
void	ft_grab_fork(t_infos *inf, int i);
int	ft_dying(t_infos *inf, int i);

#endif