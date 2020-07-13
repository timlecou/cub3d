/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:09:50 by timlecou          #+#    #+#             */
/*   Updated: 2020/04/18 14:13:21 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*begin;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	if (alst && *alst && new)
	{
		begin = *alst;
		while (begin->next)
			begin = begin->next;
		begin->next = new;
	}
}
