/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utilities_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:53:36 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/07 18:22:42 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_ft_size_uintptr_t(uintptr_t nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

char	pf_ft_get_char(int nb, int j)
{
	char	*str1;
	char	*str2;
	char	c;

	str1 = ft_strdup("0123456789abcdef");
	str2 = ft_strdup("0123456789ABCDEF");
	if (j == 1)
		c = str1[nb];
	else
		c = str2[nb];
	free(str1);
	free(str2);
	return (c);
}

int		pf_ft_get_size_p(uintptr_t nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (3);
	while (nb)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

char	*pf_ft_itoa_base_p(uintptr_t nb, int num)
{
	char	*res;
	int		i;

	i = pf_ft_get_size_p(nb);
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
