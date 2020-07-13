/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ft_print_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 19:30:03 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 10:56:59 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_ft_lepf_ft_s(t_pf *pf, char *str)
{
	int	j;
	int	len;

	j = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		j = 1;
	}
	len = (int)ft_strlen(str);
	if (pf->is_prec && len > 0 && len > pf->prec)
		len = pf->prec;
	pf_ft_write(pf, pf->fd, str, len);
	while (pf->width-- > len)
		pf_ft_write(pf, pf->fd, " ", 1);
	if (j == 1)
		free(str);
}

void	pf_ft_rigth_s(t_pf *pf, char *str)
{
	int	j;
	int	len;

	j = 0;
	if (!str)
	{
		str = ft_strdup("(null)");
		j = 1;
	}
	len = (int)ft_strlen(str);
	if (pf->is_prec && len > 0 && len > pf->prec)
		len = pf->prec;
	while (pf->width-- > len)
	{
		if (pf->is_zero)
			pf_ft_write(pf, pf->fd, "0", 1);
		else
			pf_ft_write(pf, pf->fd, " ", 1);
	}
	pf_ft_write(pf, pf->fd, str, len);
	if (j == 1)
		free(str);
}

void	pf_ft_print_s(va_list *list, t_pf *pf)
{
	char	*str;

	str = va_arg(*list, char*);
	if (pf->left == 1)
		pf_ft_lepf_ft_s(pf, str);
	else
		pf_ft_rigth_s(pf, str);
}
