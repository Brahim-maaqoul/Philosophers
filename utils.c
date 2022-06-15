/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:57:34 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/06/06 15:39:30 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char	*str)
{
	int	i;
	int	n;
	int	rst;

	i = 0;
	rst = 0;
	n = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		rst = rst * 10 + (str[i] - 48);
		i++;
	}
	return (rst * n);
}

void	ft_bzero(void *s, size_t n)
{
	char	*pt;
	size_t	i;

	i = 0;
	pt = (char *) s;
	while (i < n)
	{
		pt[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*pt;

	pt = (void *) malloc(num * size);
	if (!pt)
		return (NULL);
	ft_bzero(pt, num * size);
	return (pt);
}

void	mutex_print_str(t_infos *inf, char *str, int i)
{
	pthread_mutex_lock(&inf->output);
	if (inf->is_finished)
		return;
	printf("%lld\t%d %s\n", ft_gettime() - inf->created_at, i + 1, str);
	pthread_mutex_unlock(&inf->output);

}
