/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utilities_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 12:50:06 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/07 18:22:32 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_ft_left_d2(t_pf *pf, intmax_t nb)
{
	if (nb == 0 && pf->is_prec && !pf->prec)
	{
		while (pf->width)
		{
			pf_ft_write(pf, 1, " ", 1);
			pf->width--;
		}
		return (1);
	}
	return (0);
}

int		pf_ft_rigth_d2(t_pf *pf, intmax_t nb)
{
	if (nb == 0 && pf->is_prec && !pf->prec)
	{
		while (pf->width)
		{
			pf_ft_write(pf, 1, " ", 1);
			pf->width--;
		}
		return (1);
	}
	return (0);
}

int		pf_get_nb_size_d(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb *= -1;
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

char	*pf_ft_itoa_d(int nb)
{
	int		i;
	char	*res;

	if (nb == -2147483648)
		return (ft_strdup("2147483648"));
	i = pf_get_nb_size_d(nb);
	if (nb == 0)
		return (ft_strdup("0"));
	if (!(res = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (nb < 0)
		nb *= -1;
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
