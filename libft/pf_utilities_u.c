/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utilities_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:51:54 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/07 18:22:52 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_ft_s_u(unsigned int nb, t_pf *pf)
{
	int	i;

	i = 0;
	if (nb == 0 && pf->is_prec == 1 && pf->prec == 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*pf_ft_itoa_u(unsigned int nb, t_pf *pf)
{
	int		i;
	char	*res;

	i = pf_ft_s_u(nb, pf);
	if (nb == 0)
		return (ft_strdup("0\0"));
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i--;
	res[i + 1] = '\0';
	while (nb)
	{
		res[i] = ((nb % 10) + '0');
		i--;
		nb /= 10;
	}
	return (res);
}
