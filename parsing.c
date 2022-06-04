/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:02:57 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/02 17:42:31 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int    ft_parsing(t_infos *info, int ac, char **av)
{
    if (ac == 5 || ac == 6)
    {
        info->num_phil = ft_atoi(av[1]);
        info->time_die = ft_atoi(av[2]);
        info->time_eat = ft_atoi(av[3]);
        info->time_sleep = ft_atoi(av[4]);
        if (info->num_phil <= 0 || info->time_die <= 60 || info->time_eat <= 60
            || info->time_sleep <= 60)
            return (printf("you need to enter valid number!\n"));
        if (ac == 6)
        {
            info->num_eat = ft_atoi(av[5]);
            if (info->num_eat <= 0)
                return (printf("you need to enter valid number!\n"));
        }
    }
    else
    {
        printf("you need to enter valid arguments!\n");
        return (0);
    }
    return (0);
}
