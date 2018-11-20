/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlypai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:10:26 by mlypai            #+#    #+#             */
/*   Updated: 2017/12/25 16:10:27 by mlypai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

char	**create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	if (size <= 1)
		err();
	map = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		map[i] = (char*)malloc(sizeof(char) * (size + 1));
		while (j < size)
			map[i][j++] = '.';
		map[i][j] = '\0';
		j = 0;
		i++;
	}
	map[i] = 0;
	return (map);
}
