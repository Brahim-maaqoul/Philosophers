/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:19:43 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/05/21 20:34:34 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <time.h>

typedef struct s_philo
{
    int num_phil;
    int time_die;
    int time_eat;
    int time_sleep;
    int num_eat;
}       t_philo;

int		ft_atoi(const char	*str);
void    ft_parsing(t_philo *philo, int ac, char **av);

#endif