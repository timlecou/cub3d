/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:13:14 by timlecou          #+#    #+#             */
/*   Updated: 2020/04/15 16:12:35 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char *t;
	unsigned const char *d;
	size_t				i;

	t = s1;
	d = s2;
	i = 0;
	while (i < n)
	{
		if (t[i] != d[i])
			return (t[i] - d[i]);
		i++;
	}
	return (0);
}
