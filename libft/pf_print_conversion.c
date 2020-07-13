/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:54:45 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/07 18:22:11 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_conversion(va_list *list, t_pf *pf)
{
	if (pf->conv == 'd' || pf->conv == 'i')
		pf_ft_print_d(list, pf);
	else if (pf->conv == 'c')
		pf_ft_print_c(list, pf);
	else if (pf->conv == 's')
		pf_ft_print_s(list, pf);
	else if (pf->conv == 'u')
		pf_ft_print_u(list, pf);
	else if (pf->conv == 'p')
		pf_ft_print_p(list, pf);
	else if (pf->conv == '%')
		pf_ft_print_per(pf);
	else if (pf->conv == 'x')
		pf_ft_print_x(list, pf, 1);
	else if (pf->conv == 'X')
		pf_ft_print_x(list, pf, 2);
}
