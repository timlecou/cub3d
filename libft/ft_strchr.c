/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:21:29 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/07 17:45:44 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char*)s;
	if (!s)
		return (NULL);
	while (*ptr != c)
	{
		if (!*ptr)
			return (NULL);
		ptr++;
	}
	return (ptr);
}
