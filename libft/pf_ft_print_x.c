/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 14:49:56 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 10:57:24 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_ft_lepf_ft_x(t_pf *pf, uintmax_t nb, int n)
{
	int		nb_len;
	char	*ptr;

	nb_len = pf_ft_get_size_x(nb);
	if (nb == 0 && pf->is_prec && !pf->prec)
	{
		while (pf->width--)
			pf_ft_write(pf, pf->fd, " ", 1);
		return ;
	}
	while (nb_len++ < pf->prec)
		pf_ft_write(pf, pf->fd, "0", 1);
	ptr = pf_ft_itoa_base_x(nb, n);
	pf_ft_write(pf, pf->fd, ptr, pf_ft_get_size_x(nb));
	free(ptr);
	while (pf->width-- >= nb_len)
		pf_ft_write(pf, pf->fd, " ", 1);
}

void	pf_ft_x(t_pf *pf, int nb)
{
	int	n;

	n = (nb < pf->prec) ? pf->prec : nb;
	if (!pf->is_prec)
	{
		while (pf->width-- > nb)
		{
			if (pf->is_zero)
				pf_ft_write(pf, pf->fd, "0", 1);
			else
				pf_ft_write(pf, pf->fd, " ", 1);
		}
	}
	else
	{
		while (pf->width-- > n)
			pf_ft_write(pf, pf->fd, " ", 1);
	}
}

void	pf_ft_rigth_x(t_pf *pf, uintmax_t nb, int n)
{
	int		nb_len;
	char	*ptr;

	(void)n;
	nb_len = pf_ft_get_size_x(nb);
	if (nb == 0 && pf->is_prec && !pf->prec)
	{
		while (pf->width--)
			pf_ft_write(pf, pf->fd, " ", 1);
		return ;
	}
	pf_ft_x(pf, nb_len);
	while (nb_len++ < pf->prec)
		pf_ft_write(pf, pf->fd, "0", 1);
	ptr = pf_ft_itoa_base_x(nb, n);
	pf_ft_write(pf, pf->fd, ptr, pf_ft_get_size_x(nb));
	free(ptr);
}

void	pf_ft_print_x(va_list *list, t_pf *pf, int n)
{
	unsigned int	nb;

	nb = va_arg(*list, unsigned int);
	if (pf->left == 1)
		pf_ft_lepf_ft_x(pf, nb, n);
	else
		pf_ft_rigth_x(pf, nb, n);
}
