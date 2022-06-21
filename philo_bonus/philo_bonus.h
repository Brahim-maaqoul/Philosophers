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

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_philo
{
	int				id;
	int				num;
	long long		last_meal;
	pthread_t		th;
	struct s_infos	*info;
}		t_philo;

typedef struct s_infos
{
	t_philo			*ph;
	int				num_phil;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				is_finished;
	int				*pid;
	sem_t			*forks;
	sem_t			*output;
	long long		created_at;
	int				ate_cp;
	int				b;
}		t_infos;

int			ft_atoi(const char	*str);
int			ft_isdigit(char n);
int			ft_parsing(char **av);
int			check_args(t_infos *info, int ac);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t num, size_t size);
long long	ft_current_time(t_infos *inf, long i);
long long	ft_gettime(void);
void		print_str(t_infos *inf, char *str, int i);
void		ft_routine(t_philo *philo);
int			ft_init(t_infos *info);
void		*ft_init_philos(t_infos *info);
void		ft_thinking(t_infos *inf, int i);
void		ft_eating(t_infos *inf, int i);
void		ft_sleeping(t_infos *inf, int i);
void		ft_grab_fork(t_infos *inf, int i);
int			ft_dying(t_infos *inf, int i);
void		ft_check_death(t_infos *inf);
void		ft_destroyer(t_infos *inf);
void		delay(int t);

#endif
