/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:44:13 by dgonor            #+#    #+#             */
/*   Updated: 2018/01/08 15:50:01 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		check_dot(char *str)
{
	int		i;
	int		dot;

	i = 0;
	dot = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	return (dot);
}

static	int		check_hesh(char *str)
{
	int		i;
	int		hesh;

	i = 0;
	hesh = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			hesh++;
		i++;
	}
	return (hesh);
}

int				check_bn(char *str)
{
	int		i;
	int		bn;

	i = 0;
	bn = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			bn++;
		i++;
	}
	return (bn);
}

int				check_n(char *str)
{
	int		i;
	int		tetr;

	i = 0;
	tetr = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			tetr++;
		i++;
	}
	return (tetr);
}

int				valid_content(char *str)
{
	int		n;

	n = check_n(str);
	if ((n * 4 == check_hesh(str)) && (n * 12 == check_dot(str))
		&& (n - 1 + (n * 4) == check_bn(str)))
		return (1);
	else
		return (0);
}
