/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 18:49:17 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 10:55:55 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_ft_left_p(t_pf *pf, uintptr_t nb)
{
	int		len;
	char	*ptr;

	len = pf_ft_size_uintptr_t(nb) + 2;
	pf_ft_write(pf, pf->fd, "0x", 2);
	if (nb == 0 && pf->is_prec && !pf->prec)
		return ;
	while (pf->prec > (len - 2))
	{
		pf_ft_write(pf, pf->fd, "0", 1);
		pf->prec--;
	}
	ptr = pf_ft_itoa_base_p(nb, 1);
	pf_ft_write(pf, pf->fd, ptr, (int)ft_strlen(ptr));
	free(ptr);
	while (pf->width > len)
	{
		pf_ft_write(pf, pf->fd, " ", 1);
		pf->width--;
	}
}

void	pf_ft_rigth_p(t_pf *pf, uintptr_t nb)
{
	int		len;
	char	*ptr;

	len = pf_ft_size_uintptr_t(nb) + 2;
	while (pf->width > len)
	{
		pf_ft_write(pf, pf->fd, " ", 1);
		pf->width--;
	}
	pf_ft_write(pf, pf->fd, "0x", 2);
	if (nb == 0 && pf->is_prec && !pf->prec)
		return ;
	while ((len - 2) < pf->prec)
	{
		pf_ft_write(pf, pf->fd, "0", 1);
		len++;
	}
	ptr = pf_ft_itoa_base_p(nb, 1);
	pf_ft_write(pf, pf->fd, ptr, (int)ft_strlen(ptr));
	free(ptr);
}

void	pf_ft_print_p(va_list *list, t_pf *pf)
{
	uintptr_t	ptr;

	ptr = va_arg(*list, uintptr_t);
	if (ptr == 0 && pf->is_prec && !pf->prec)
	{
		if (pf->left == 1)
		{
			pf_ft_write(pf, pf->fd, "0x", 2);
			while (pf->width-- > 2)
				pf_ft_write(pf, pf->fd, " ", 1);
		}
		else
		{
			while (pf->width-- > 2)
				pf_ft_write(pf, pf->fd, " ", 1);
			pf_ft_write(pf, pf->fd, "0x", 2);
		}
	}
	else if (pf->left == 1)
		pf_ft_left_p(pf, ptr);
	else
		pf_ft_rigth_p(pf, ptr);
}
