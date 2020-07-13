/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utilities_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 10:58:05 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 10:51:53 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_ft_is_flag(char c)
{
	return (c == '0' || c == '-');
}

int		pf_ft_skip_nb(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]) && str[i] != '\0')
		i++;
	return (i);
}

int		pf_ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	pf_ft_last_change(t_pf *pf)
{
	if (pf->prec < 0)
	{
		pf->prec = 0;
		pf->is_prec = 0;
	}
	if (pf->width < 0)
	{
		pf->width *= -1;
		pf->left = 1;
	}
	if (pf->is_zero == 1 && pf->left == 1)
		pf->is_zero = 0;
}

t_pf	pf_ft_init_pf(int fd)
{
	t_pf	pf;

	pf.conv = ' ';
	pf.width = 0;
	pf.prec = 0;
	pf.left = 0;
	pf.char_nb = 0;
	pf.is_prec = 0;
	pf.is_zero = 0;
	pf.fd = fd;
	return (pf);
}
