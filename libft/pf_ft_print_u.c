/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 20:21:51 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 10:57:07 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_ft_left_u(t_pf *pf, unsigned int nb)
{
	int		len;
	char	*ptr;

	ptr = pf_ft_itoa_u(nb, pf);
	len = (int)ft_strlen(ptr);
	if (pf->is_prec)
	{
		while (len < pf->prec)
		{
			pf_ft_write(pf, pf->fd, "0", 1);
			len++;
		}
	}
	pf_ft_write(pf, pf->fd, ptr, (int)ft_strlen(ptr));
	while (pf->width-- > len)
		pf_ft_write(pf, pf->fd, " ", 1);
	free(ptr);
}

void	pf_ft_rigth_u(t_pf *pf, unsigned int nb)
{
	int		len;
	char	*ptr;

	ptr = pf_ft_itoa_u(nb, pf);
	len = (pf->prec < (int)ft_strlen(ptr)) ? (int)ft_strlen(ptr) : pf->prec;
	if (!pf->is_prec && pf->is_zero)
	{
		while (pf->width > len)
		{
			pf_ft_write(pf, pf->fd, "0", 1);
			pf->width--;
		}
	}
	else
	{
		while (pf->width-- > len)
			pf_ft_write(pf, pf->fd, " ", 1);
	}
	while (pf->prec-- > (int)ft_strlen(ptr))
		pf_ft_write(pf, pf->fd, "0", 1);
	pf_ft_write(pf, pf->fd, ptr, (int)ft_strlen(ptr));
	free(ptr);
}

void	pf_ft_print_u(va_list *list, t_pf *pf)
{
	unsigned int	nb;

	nb = va_arg(*list, unsigned int);
	if (nb == 0 && pf->is_prec && !pf->prec)
	{
		while (pf->width--)
			pf_ft_write(pf, pf->fd, " ", 1);
	}
	else if (pf->left == 1)
		pf_ft_left_u(pf, nb);
	else
		pf_ft_rigth_u(pf, nb);
}
