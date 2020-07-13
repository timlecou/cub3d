/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utilities_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:51:54 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/07 18:22:18 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_ft_set(t_pf *pf, int n, char c)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pf_ft_write(pf, 1, &c, 1);
		i++;
	}
	return (n);
}

int		pf_ft_is_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		pf_ft_pf_size(char *str, t_pf *pf)
{
	int	i;

	i = 0;
	(void)pf;
	if (pf_ft_is_in_str(str[i], "scdiuxXp%"))
		return (1);
	while (pf_ft_is_in_str(str[i], "scdiuxXp%-0.*123456789")
	&& str[i] != '\0'
	&& !pf_ft_is_in_str(str[i - 1], "scdiuxXp%"))
		i++;
	return (i);
}

int		pf_ft_s_int(int nb, t_pf *pf)
{
	int	i;

	i = 0;
	(void)pf;
	if (nb == 0)
		return (1);
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

void	pf_ft_write(t_pf *pf, int fd, char *str, int len)
{
	write(fd, str, len);
	pf->char_nb += len;
}
