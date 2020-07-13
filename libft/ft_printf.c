/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 14:47:01 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 11:02:27 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_ft_do_printf(const char *str, va_list *list, int i, int fd)
{
	t_pf	pf;
	int		ret;
	char	*ptr;

	ret = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ptr = ft_strdup(&str[i]);
			pf = pf_ft_fill_pf(ptr, list, fd);
			print_conversion(list, &pf);
			i += pf_ft_pf_size(ptr, &pf) - 1;
			ret += pf.char_nb;
			free(ptr);
		}
		else if (str[i] != '%' && str[i] != '\0')
		{
			write(fd, &str[i], 1);
			ret++;
		}
	}
	return (ret);
}

int		ft_printf_fd(int fd, const char *str, ...)
{
	va_list	list;
	int		ret;

	ret = 0;
	va_start(list, str);
	ret = pf_ft_do_printf(str, &list, -1, fd);
	va_end(list);
	return (ret);
}
