/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:46:30 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 18:02:38 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dstcpy;
	const char	*srcpy;
	size_t		len;
	size_t		n;

	dstcpy = dst;
	srcpy = src;
	n = size;
	while (*dstcpy && n-- != 0)
		dstcpy++;
	len = dstcpy - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(srcpy));
	while (*srcpy)
	{
		if (n != 1)
		{
			*dstcpy++ = *srcpy;
			n--;
		}
		srcpy++;
	}
	*dstcpy = '\0';
	return (len + (srcpy - src));
}
