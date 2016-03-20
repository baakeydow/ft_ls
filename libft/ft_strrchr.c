/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:49:32 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 18:04:01 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = 0;
	if (c == 0)
		return ((char *)s + ft_strlen((char *)s));
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = ((char *)s + i);
		i++;
	}
	return (ptr);
}
