/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 00:41:52 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:49:25 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t		a;
	size_t		b;

	a = 0;
	b = 0;
	if (to_find[b] == '\0')
		return ((char *)str);
	while (str[a] && a < n)
	{
		b = 0;
		while (to_find[b] == str[a + b])
		{
			if (a + b < n && to_find[b + 1] == '\0')
				return ((char *)(str + a));
			b++;
		}
		a++;
	}
	return (0);
}
