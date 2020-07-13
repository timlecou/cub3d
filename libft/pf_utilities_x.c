/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utilities_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:00:05 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/07 18:18:37 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_ft_get_size_x(unsigned long long value)
{
	int		i;

	i = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= 16;
		i++;
	}
	return (i);
}

char	*pf_ft_itoa_base_x(unsigned int nb, int num)
{
	char	*res;
	int		i;

	i = pf_ft_get_size_x(nb);
	if (nb == 0)
		return (ft_strdup("0\0"));
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	i--;
	while (nb)
	{
		res[i] = pf_ft_get_char(nb % 16, num);
		i--;
		nb /= 16;
	}
	return (res);
}
