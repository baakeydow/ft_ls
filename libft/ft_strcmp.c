/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:45:06 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:57:38 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	int				cptr;
	unsigned char	*u_str1;
	unsigned char	*u_str2;

	u_str1 = (unsigned char *)s1;
	u_str2 = (unsigned char *)s2;
	cptr = 0;
	while (u_str1[cptr] && u_str1[cptr] == u_str2[cptr])
		cptr++;
	return (u_str1[cptr] - u_str2[cptr]);
}
