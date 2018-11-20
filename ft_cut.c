/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 16:27:10 by dgonor            #+#    #+#             */
/*   Updated: 2018/01/04 14:39:17 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_cutvert_new(char *tetr, int i, int dist)
{
	int		j;
	int		k;
	char	*new;

	j = 0;
	k = 0;
	new = ft_strnew(ft_strlen(tetr) - check_bn(tetr));
	while (tetr[k] != '\0')
	{
		if (k == i)
		{
			k++;
			i = i + dist;
		}
		new[j] = tetr[k];
		k++;
		j++;
	}
	return (new);
}

int		ft_check_dot(char *tetr, int dist)
{
	int		j;
	int		dot;
	int		len;

	dot = 0;
	j = 0;
	len = ft_strlen(tetr);
	while (j < len)
	{
		if (tetr[j] == '.')
			dot++;
		j = j + dist;
	}
	return (dot);
}

char	*ft_cutvert(char *tetr)
{
	int		i;
	int		dot;
	char	*tmp;
	int		dist;

	i = 0;
	dot = 0;
	tmp = NULL;
	dist = 5;
	while (tetr[i] != '\0')
	{
		dot = ft_check_dot(&tetr[i], dist);
		if (dot == check_bn(tetr))
		{
			tmp = ft_cutvert_new(tetr, i, dist);
			ft_strdel(&tetr);
			tetr = tmp;
			i = -1;
			dist--;
		}
		i++;
	}
	return (tetr);
}

char	*ft_cut(char *tetr)
{
	int		i;
	int		dot;
	int		hesh;

	i = 0;
	dot = 0;
	hesh = 0;
	while (tetr[i] != '\0')
	{
		hesh = (tetr[i] == '#') ? hesh + 1 : hesh;
		dot = (tetr[i] == '.' && (tetr[i + 1] == '.'
			|| tetr[i + 1] == '\n')) ? dot + 1 : dot;
		if (dot == 4 && tetr[i + 1] == '\n')
		{
			tetr = hesh == 0 ? ft_strsub(tetr,
				i + 2, ft_strlen(tetr) - 5) : tetr;
			i = hesh == 0 ? -1 : i;
			dot = hesh == 0 ? 0 : dot;
			if (hesh == 4)
				return (ft_strsub(tetr, 0, i - 3));
		}
		dot = (tetr[i + 1] == '\n') ? 0 : dot;
		i++;
	}
	return (tetr);
}
