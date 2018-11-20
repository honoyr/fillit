/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlypai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:47:24 by mlypai            #+#    #+#             */
/*   Updated: 2017/12/10 14:47:27 by mlypai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# define BUF_SIZE 546

void				err(void);
char				**reading(char *file);
int					valid_content(char *str);
int					check_n(char *str);
int					check_bn(char *str);
char				**ft_vfigure(char *str);
void				ft_validate(char *tetr);
char				*ft_cut(char *tetr);
char				*ft_cutvert(char *tetr);
int					ft_check_dot(char *tetr, int dist);
char				*ft_cutvert_new(char *tetr, int	i, int dist);
char				**ft_replacer(char **string, char a, char b);
char				**create_map(int size);
int					square(int i);
int					algorithm(char ***figure, int b, char **map);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
size_t				ft_strlen(const char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_putendl(char const *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

#endif
