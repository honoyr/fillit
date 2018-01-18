/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:37:34 by dgonor            #+#    #+#             */
/*   Updated: 2017/11/09 17:37:37 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int		max;
	unsigned int		i;
	unsigned int		size_dst;
	unsigned int		size_both;

	i = 0;
	size_dst = ft_strlen(dst);
	size_both = ft_strlen(src) + ft_strlen(dst);
	if (size < size_dst)
		return (size + ft_strlen(src));
	else
	{
		max = size - size_dst - 1;
		while (dst[size_dst] != '\0')
			size_dst++;
		while (i < max && src[i] != '\0')
		{
			dst[size_dst] = src[i];
			i++;
			size_dst++;
		}
		dst[size_dst] = '\0';
		return (size_both);
	}
}
/*
**The strlcpy() and strlcat() functions copy and concatenate strings
**with the same input parameters and output result as snprintf(3).
**They are designed to be safer,
**more consistent, and less error prone replacements for
**the easily misused functions strncpy(3) and strncat(3).
**strlcpy() and strlcat() take the full size
**of the destination buffer and guarantee
**NUL-termination if there is room.
**Note that room for the NUL should be included in dstsize.
**
**strlcpy() copies up to dstsize - 1 characters from the string src to dst,
**NUL-terminating the result if dstsize is not 0.
**
**strlcat() appends string src to the end of dst.
**It will append at most dstsize - strlen(dst) - 1 characters.
**It will then NUL-terminate,
**unless dstsize is 0 or the original dst string was longer than dstsize
**(in practice this should not happen as it
**means that either dstsize is incorrect or that dst is not a proper string).
**
**If the src and dst strings overlap, the behavior is undefined.
*/
