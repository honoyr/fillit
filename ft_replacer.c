/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlypai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:38:19 by mlypai            #+#    #+#             */
/*   Updated: 2017/12/25 13:38:21 by mlypai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_replacer(char **string, char a, char b)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (string[i])
	{
		while (string[i][j])
		{
			if (string[i][j] == a)
				string[i][j] = b;
			j++;
		}
		i++;
		j = 0;
	}
	return (string);
}
