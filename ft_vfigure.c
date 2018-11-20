/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfigure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:12:02 by dgonor            #+#    #+#             */
/*   Updated: 2018/01/04 19:12:06 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_vfigure(char *str)
{
	char	**ptr;
	int		i;
	int		x;
	int		j;
	int		n;

	i = 0;
	x = 0;
	j = 0;
	n = check_n(str);
	if (!(ptr = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	ptr[n] = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			if (i != j + 19)
				err();
			*(ptr + x++) = ft_strsub(str, j, 20);
			j = j + 21;
		}
		i++;
	}
	return (ptr);
}
