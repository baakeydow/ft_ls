/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:31:15 by bndao             #+#    #+#             */
/*   Updated: 2016/01/01 17:31:19 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *nptr)
{
	size_t		i;
	int			neg;
	int			num;

	i = 0;
	neg = 0;
	num = 0;
	while ((nptr[i] == ' ') || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num *= 10;
		num += ((int)nptr[i] - 48);
		i++;
	}
	if (neg == 0 && num >= 2147483647)
		return (2147483647);
	else if (neg == 1 && num >= -2147483647)
		return (-num);
	else
		return (num);
}
