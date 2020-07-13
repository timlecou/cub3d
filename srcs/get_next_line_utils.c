/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:24:25 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:51:56 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_cut_begin(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	if (!str)
		return (NULL);
	if (!(tmp = malloc(sizeof(char) * j + 1)))
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_cut(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i++;
	if (!(res = (char*)malloc(sizeof(char) * ((int)ft_strlen(&str[i]) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		res[j] = str[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

int		ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (!(s3 = (char *)malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1))))
		return (NULL);
	while (s1 != NULL && s1[++j] != '\0')
		s3[++i] = s1[j];
	j = -1;
	while (s2 != NULL && s2[++j] != '\0')
		s3[++i] = s2[j];
	s3[++i] = '\0';
	return (s3);
}
