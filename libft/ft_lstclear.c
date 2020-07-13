/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:10:42 by timlecou          #+#    #+#             */
/*   Updated: 2020/04/18 14:14:03 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && *lst && del)
	{
		tmp = (*lst);
		while (tmp)
		{
			(*lst) = (*lst)->next;
			del(tmp);
			tmp = (*lst);
		}
	}
	*lst = NULL;
}
