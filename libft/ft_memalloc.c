/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:41:33 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:41:37 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memalloc(size_t size)
{
	unsigned char *mem;

	if (size == 0)
		return (0);
	if (!(mem = (unsigned char *)malloc(sizeof(*mem) * size)))
		return (NULL);
	ft_bzero((void *)mem, size);
	return ((void *)mem);
}
