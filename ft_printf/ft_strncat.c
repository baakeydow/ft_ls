/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:47:48 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:48:00 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	a;
	size_t	b;
	char	*srcpy;

	srcpy = (char *)src;
	a = 0;
	b = 0;
	while (dest[a])
		a++;
	while (srcpy[b] && b < n)
	{
		dest[a] = srcpy[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}
