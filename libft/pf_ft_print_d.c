/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 17:31:22 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 10:55:43 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_ft_left_neg_d(t_pf *pf, int nb)
{
	char	*ptr;
	int		len;

	ptr = pf_ft_itoa_d(nb);
	len = (int)ft_strlen(ptr);
	pf_ft_write(pf, pf->fd, "-", 1);
	if (pf->is_prec)
	{
		while (pf->prec > len)
		{
			pf_ft_write(pf, pf->fd, "0", 1);
			len++;
		}
	}
	pf_ft_write(pf, pf->fd, ptr, (int)ft_strlen(ptr));
	while (pf->width-- > len + 1)
		pf_ft_write(pf, pf->fd, " ", 1);
	free(ptr);
}

void	pf_ft_left_pos_d(t_pf *pf, int nb)
{
	char	*ptr;
	int		len;

	ptr = ft_itoa(nb);
	len = (int)ft_strlen(ptr);
	while (pf->prec > len)
	{
		pf_ft_write(pf, pf->fd, "0", 1);
		len++;
	}
	pf_ft_write(pf, pf->fd, ptr, (int)ft_strlen(ptr));
	while (pf->width-- > len)
		pf_ft_write(pf, pf->fd, " ", 1);
	free(ptr);
}

void	pf_ft_rigth_neg_d(t_pf *pf, int nb)
{
	char	*ptr;
	int		len;

	ptr = pf_ft_itoa_d(nb);
	len = (pf->prec < (int)ft_strlen(ptr)) ? (int)ft_strlen(ptr) : pf->prec;
	if (pf->is_zero == 1 && !pf->is_prec)
	{
		pf_ft_write(pf, pf->fd, "-", 1);
		while (pf->width-- > len + 1)
			pf_ft_write(pf, pf->fd, "0", 1);
	}
	else
	{
		while (pf->width-- > len + 1)
			pf_ft_write(pf, pf->fd, " ", 1);
		pf_ft_write(pf, pf->fd, "-", 1);
		while (pf->prec-- > (int)ft_strlen(ptr))
			pf_ft_write(pf, pf->fd, "0", 1);
	}
	pf_ft_write(pf, pf->fd, ptr, (int)ft_strlen(ptr));
	free(ptr);
}

void	pf_ft_rigth_pos_d(t_pf *pf, int nb)
{
	char	*ptr;
	int		len;

	ptr = ft_itoa(nb);
	len = (pf->prec < (int)ft_strlen(ptr)) ? (int)ft_strlen(ptr) : pf->prec;
	if (!pf->is_prec && pf->is_zero)
	{
		while (pf->width-- > len)
			pf_ft_write(pf, pf->fd, "0", 1);
	}
	else
	{
		while (pf->width-- > len)
			pf_ft_write(pf, pf->fd, " ", 1);
		while (pf->prec-- > (int)ft_strlen(ptr))
			pf_ft_write(pf, pf->fd, "0", 1);
	}
	pf_ft_write(pf, pf->fd, ptr, (int)ft_strlen(ptr));
	free(ptr);
}

void	pf_ft_print_d(va_list *list, t_pf *pf)
{
	int	nb;

	nb = va_arg(*list, int);
	if (nb == 0 && pf->is_prec && !pf->prec)
	{
		while (pf->width--)
			pf_ft_write(pf, pf->fd, " ", 1);
	}
	else if (pf->left == 1)
	{
		if (nb < 0)
			pf_ft_left_neg_d(pf, nb);
		else
			pf_ft_left_pos_d(pf, nb);
	}
	else
	{
		if (nb < 0)
			pf_ft_rigth_neg_d(pf, nb);
		else
			pf_ft_rigth_pos_d(pf, nb);
	}
}
