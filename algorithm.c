/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlypai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:52:13 by mlypai            #+#    #+#             */
/*   Updated: 2017/12/25 14:52:15 by mlypai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		put_in(char **map, int i, int j, char **figure)
{
	int i2;
	int temp2;
	int j2;

	i2 = 0;
	j2 = 0;
	temp2 = j;
	while (figure[i2])
	{
		while (figure[i2][j2])
		{
			if (figure[i2][j2] != '.')
				map[i][j] = figure[i2][j2];
			j++;
			j2++;
		}
		i++;
		i2++;
		j = temp2;
		j2 = 0;
	}
}

int			is_fit(char **map, int i, int j, char **figure)
{
	int i2;
	int temp1;
	int temp2;
	int j2;

	i2 = -1;
	j2 = 0;
	temp1 = i;
	temp2 = j;
	while (figure[++i2])
	{
		while (figure[i2][j2])
		{
			if (map[i] && map[i][j] && (map[i][j++] == '.'
				|| figure[i2][j2] == '.'))
				j2++;
			else
				return (0);
		}
		i++;
		j = temp2;
		j2 = 0;
	}
	put_in(map, temp1, temp2, figure);
	return (1);
}

int			algorithm(char ***figure, int b, char **map)
{
	int i;
	int j;

	if (figure[b] && (i = -1))
	{
		while (map[++i] && (j = -1))
			while (map[i][++j])
				if (is_fit(map, i, j, figure[b]))
				{
					if (algorithm(figure, b + 1, map))
						return (1);
					map = ft_replacer(map, 'A' + b, '.');
				}
		return (0);
	}
	else
	{
		i = 0;
		while (map[i])
			ft_putendl(map[i++]);
		return (1);
	}
}
