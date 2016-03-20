/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:42:34 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:42:35 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!(dest > src && src + n > dest))
		ft_memcpy(dest, src, n);
	else
		while (n--)
			*((char *)dest + n) = *((char *)src + n);
	return (dest);
}
