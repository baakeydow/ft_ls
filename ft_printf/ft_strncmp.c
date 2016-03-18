/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:48:05 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:48:12 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			cptr;
	unsigned char	*u_str1;
	unsigned char	*u_str2;

	u_str1 = (unsigned char *)s1;
	u_str2 = (unsigned char *)s2;
	cptr = 0;
	while (u_str1[cptr] && u_str1[cptr] == u_str2[cptr] && cptr < n)
		cptr++;
	if (cptr == n)
		return (u_str1[cptr - 1] - u_str2[cptr - 1]);
	return (u_str1[cptr] - u_str2[cptr]);
}
