/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:41:48 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:41:51 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char *)src;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
		{
			*(unsigned char *)dest++ = *ptr++;
			return (dest);
		}
		*(unsigned char *)dest++ = *ptr++;
	}
	return (NULL);
}
