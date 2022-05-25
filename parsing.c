/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:02:57 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/05/25 18:14:22 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int ft_error(void)
{
    printf("Enter a number!\n");
    return (0);
}

void    ft_parsing(t_philo *philo, int ac, char **av)
{
    if (ac == 5 || ac == 6)
    {
        philo->num_phil = ft_atoi(av[1]);
        philo->time_die = ft_atoi(av[2]);
        philo->time_eat = ft_atoi(av[3]);
        philo->time_sleep = ft_atoi(av[4]);
        if (philo->num_phil <= 0 || philo->time_die <= 60 || philo->time_eat <= 60
            || philo->time_sleep <= 60)
            return (ft_error());
        if (ac == 6)
        {
            philo->num_eat = ft_atoi(av[5]);
            if (philo->num_eat <= 0)
                return (ft_error());
        }
    }
    else
    {
        printf("you need to enter valid arguments!\n");
        return (0);
    }
}