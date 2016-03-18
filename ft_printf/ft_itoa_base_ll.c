/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 02:10:18 by bndao             #+#    #+#             */
/*   Updated: 2016/03/16 02:10:36 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_z_or_m(intmax_t number)
{
	char	*str;

	if (number == 0)
		str = ft_strdup("0");
	else
		str = ft_strdup("-9223372036854775808");
	return (str);
}

static char		*s_size(char **str, int *not_neg, size_t *i)
{
	*i = 0;
	*not_neg = 1;
	if (!((*str) = (char *)malloc(sizeof(char) * 19)))
		return (NULL);
	return (*str);
}

char			*ft_itoa_ll(intmax_t nbr)
{
	int		pos;
	size_t	i;
	char	*str_number;

	if (!(s_size(&str_number, &pos, &i)))
		return (NULL);
	if (nbr == 0 || nbr <= LLONG_MIN)
		return (ft_z_or_m(nbr));
	if (nbr < 0)
	{
		nbr = -nbr;
		pos = 0;
	}
	while (nbr)
	{
		str_number[i] = (nbr) % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	if (!pos)
		str_number[i++] = '-';
	str_number[i] = '\0';
	return (ft_strrev(str_number));
}

static char		*s_s(char **str, size_t *i)
{
	*i = 0;
	if (!((*str) = (char *)malloc(sizeof(char) * 19)))
		return (NULL);
	return (*str);
}

char			*ft_itoa_ull(uintmax_t nbr)
{
	size_t	i;
	char	*str_number;

	if (!(s_s(&str_number, &i)))
		return (NULL);
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		str_number[i] = (nbr) % 10 + '0';
		nbr = nbr / 10;
		i++;
	}
	str_number[i] = '\0';
	return (ft_strrev(str_number));
}
