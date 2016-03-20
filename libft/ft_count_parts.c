/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 08:33:26 by bndao             #+#    #+#             */
/*   Updated: 2016/01/04 08:37:20 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_parts(const char *str, char c)
{
	int		nb;
	int		cmp;

	nb = 0;
	cmp = 0;
	while (str[nb])
	{
		while (str[nb] && (str[nb] == c))
			nb++;
		if (str[nb])
			cmp++;
		while (str[nb] && (str[nb] != c))
			nb++;
	}
	return (cmp);
}
