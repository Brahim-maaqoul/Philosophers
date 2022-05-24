/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmaaqoul <bmaaqoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:19:27 by bmaaqoul          #+#    #+#             */
/*   Updated: 2022/05/24 18:20:21 by bmaaqoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_bzero(void *s, size_t n)
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