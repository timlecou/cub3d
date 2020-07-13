/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:23:01 by timlecou          #+#    #+#             */
/*   Updated: 2020/04/15 16:08:39 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	while (is_charset(s1[i], set))
		i++;
	j = ft_strlen(s1);
	j--;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	while (is_charset(s1[j], set))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
