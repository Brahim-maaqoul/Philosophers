/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:23:35 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/05/28 01:35:18 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long ft_gettime(void)
{
	long long milliseconds;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	milliseconds =  tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

long long	ft_current_time(t_infos *inf)
{
	return (ft_gettime() - inf->created_at);
}

// int main(void)
// {
// 	t_philo *ph;
// 	struct timeval tv;
// 	ph = malloc(sizeof(pthread_t));
// 	ph->created_at = ft_gettime();
// 	int l = 0;
// 	while (l < 5)
// 	{
// 		long long i = ft_current_time(ph);
// 		printf("%lld\n", i);
// 		usleep(200 * 1000);
// 		l++;
// 	}
// }