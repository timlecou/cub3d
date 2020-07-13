/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_per.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:14:31 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 10:56:51 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_ft_left_per(t_pf *pf)
{
	pf_ft_write(pf, pf->fd, "%", 1);
	while (pf->width > 1)
	{
		pf_ft_write(pf, pf->fd, " ", 1);
		pf->width--;
	}
}

void	pf_ft_rigth_per(t_pf *pf)
{
	while (pf->width > 1)
	{
		if (pf->is_zero)
			pf_ft_write(pf, pf->fd, "0", 1);
		else
			pf_ft_write(pf, pf->fd, " ", 1);
		pf->width--;
	}
	pf_ft_write(pf, pf->fd, "%", 1);
}

void	pf_ft_print_per(t_pf *pf)
{
	if (pf->left == 1)
		pf_ft_left_per(pf);
	else
		pf_ft_rigth_per(pf);
}
