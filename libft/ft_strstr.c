/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:49:59 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:50:03 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strstr(const char *str, const char *to_find)
{
	size_t		a;
	size_t		b;

	a = 0;
	b = 0;
	if (str[a] == '\0' && to_find[b] == '\0')
		return ((char *)str);
	while (str[a])
	{
		while (to_find[b] && (to_find[b] == str[a + b]))
			b++;
		if (to_find[b] == '\0')
			return ((char *)str + a);
		else
		{
			a++;
			b = 0;
		}
	}
	return (0);
}
