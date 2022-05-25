/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:19:43 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/05/25 18:32:58 by bmaaqoul         ###   ########.fr       */
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
    int num_phil;
    int time_die;
    int time_eat;
    int time_sleep;
    int num_eat;
    int     id;
    pthread_t   *th;
    pthread_mutex_t *fork;
    long long     created_at;
}       t_philo;

typedef struct  s_infos
{
    t_philo *ph;
    int     b;
}       t_infos;

int		ft_atoi(const char	*str);
void    ft_parsing(t_philo *philo, int ac, char **av);
void	*ft_calloc(size_t num, size_t size);
long long	    ft_current_time(t_philo *ph);
long long ft_gettime(void);

#endif