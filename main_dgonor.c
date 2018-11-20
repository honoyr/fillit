/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_dgonor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:33:53 by dgonor            #+#    #+#             */
/*   Updated: 2018/01/08 16:34:04 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		***ft_array(char **tetr)
{
	int		i;
	char	sym;
	char	***array;

	i = 0;
	sym = 'A';
	array = NULL;
	while (tetr[i] != NULL)
	{
		i++;
	}
	array = (char***)malloc(sizeof(char**) * (i + 1));
	i = 0;
	while (tetr[i] != NULL)
	{
		array[i] = ft_strsplit(tetr[i], '\n');
		array[i] = ft_replacer(array[i], '#', sym++);
		i++;
	}
	array[i] = NULL;
	return (array);
}

void		ft_validate(char *tetr)
{
	int		i;
	int		k;
	int		x;
	int		n;

	i = 0;
	k = 0;
	x = 4;
	n = 0;
	while (tetr[i] != '\0')
	{
		if (tetr[i] == '#')
		{
			k = ((i + 1) < 20 && tetr[i + 1] == '#') ? k + 1 : k;
			k = ((i + 5) < 20 && tetr[i + 5] == '#') ? k + 1 : k;
		}
		if (tetr[i] == '\n' && x == i)
		{
			x = x + 5;
			n++;
		}
		i++;
	}
	if ((k != 3 && k != 4) || n != 4)
		err();
}

char		**reading(char *file)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		ret;
	char	**ptr;
	int		i;

	i = 0;
	ptr = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		err();
	if ((ret = read(fd, buf, BUF_SIZE)) == -1)
		err();
	buf[ret] = '\0';
	if (ret > 545 || ret < 20)
		err();
	if (valid_content(buf) == 0)
		err();
	ptr = ft_vfigure(buf);
	while (ptr[i])
	{
		ft_validate(ptr[i]);
		i++;
	}
	return (ptr);
}

int			main(int argc, char **argv)
{
	char	***array;
	char	**tetr;
	int		i;

	i = 0;
	array = NULL;
	tetr = NULL;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(0);
	}
	tetr = reading(argv[1]);
	while (tetr[i] != NULL)
	{
		tetr[i] = ft_cut(tetr[i]);
		tetr[i] = ft_cutvert(tetr[i]);
		i++;
	}
	array = ft_array(tetr);
	while (!algorithm(array, 0, create_map(square(i * 4))))
		i++;
}
