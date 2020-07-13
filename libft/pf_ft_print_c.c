/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:14:31 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 10:53:20 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_ft_left_c(t_pf *pf, char c)
{
	pf_ft_write(pf, pf->fd, &c, 1);
	while (pf->width-- > 1)
		pf_ft_write(pf, pf->fd, " ", 1);
}

void	pf_ft_rigth_c(t_pf *pf, char c)
{
	while (pf->width-- > 1)
	{
		if (pf->is_zero)
			pf_ft_write(pf, pf->fd, "0", 1);
		else
			pf_ft_write(pf, pf->fd, " ", 1);
	}
	pf_ft_write(pf, 1, &c, 1);
}

void	pf_ft_print_c(va_list *list, t_pf *pf)
{
	char	c;

	c = (unsigned char)va_arg(*list, int);
	if (pf->left == 1)
		pf_ft_left_c(pf, c);
	else
		pf_ft_rigth_c(pf, c);
}
