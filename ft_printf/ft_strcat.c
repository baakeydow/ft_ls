/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:44:26 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:44:28 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strcat(char *dest, const char *src)
{
	size_t	a;
	size_t	b;
	char	*srcpy;

	srcpy = (char *)src;
	a = 0;
	b = 0;
	while (dest[a])
		a++;
	while (srcpy[b])
	{
		dest[a] = srcpy[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}
