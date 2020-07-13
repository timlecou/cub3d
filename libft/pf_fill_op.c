/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 15:30:10 by timlecou          #+#    #+#             */
/*   Updated: 2020/05/08 10:51:24 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pf_ft_t(char *str, int i)
{
	while (ft_isdigit(str[i]) && str[i] != '\0')
		i++;
	return (i);
}

int		pf_ft_get_flags(t_pf *pf, char *format, int index)
{
	while (pf_ft_is_flag(format[index]) && format[index] != '\0')
	{
		if (format[index] == '-')
			pf->left = 1;
		else if (format[index] == '0' && pf->left != 1)
			pf->is_zero = 1;
		index++;
	}
	return (index);
}

int		pf_ft_get_prec(t_pf *pf, char *format, int index, va_list *list)
{
	char	*ptr;
	int		i;

	i = 0;
	if (format[index] == '.')
	{
		index++;
		pf->is_prec = 1;
		if (format[index] == '*')
		{
			pf->prec = va_arg(*list, int);
			index++;
		}
		else if (ft_isdigit(format[index]))
		{
			if (!(ptr = malloc(sizeof(char) * pf_ft_t(format, index) + 1)))
				return (0);
			while (ft_isdigit(format[index]) && format[index] != '\0')
				ptr[i++] = format[index++];
			ptr[i] = '\0';
			pf->prec = ft_atoi(ptr);
			free(ptr);
		}
	}
	return (index);
}

int		pf_ft_get_width(t_pf *pf, char *format, int index, va_list *list)
{
	char	*ptr;
	int		i;

	ptr = NULL;
	i = 0;
	if (format[index] == '*')
	{
		pf->width = va_arg(*list, int);
		index++;
	}
	else if (ft_isdigit(format[index]))
	{
		if (!(ptr = (char*)malloc(sizeof(char) * pf_ft_t(format, index) + 1)))
			return (-1);
		while (ft_isdigit(format[index]) && format[index] != '\0')
		{
			ptr[i] = format[index];
			index++;
			i++;
		}
		ptr[i] = '\0';
		pf->width = ft_atoi(ptr);
		free(ptr);
	}
	return (index);
}

t_pf	pf_ft_fill_pf(char *format, va_list *list, int fd)
{
	int		i;
	t_pf	pf;

	i = 0;
	pf = pf_ft_init_pf(fd);
	i = pf_ft_get_flags(&pf, format, i);
	i = pf_ft_get_width(&pf, format, i, list);
	i = pf_ft_get_prec(&pf, format, i, list);
	pf.conv = format[i];
	pf_ft_last_change(&pf);
	return (pf);
}
