/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 23:35:59 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 18:33:40 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*ft_zero_or_min(int number)
{
	char	*str;

	if (number == 0)
		str = ft_strdup("0");
	else
		str = ft_strdup("-2147483648");
	return (str);
}

static char		*str_size(char **str, int *not_neg, size_t *i, int *rem)
{
	*i = 0;
	*not_neg = 1;
	*rem = 0;
	if (!((*str) = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	return (*str);
}

char			*ft_itoa_base(long long int nbr, int base, char c)
{
	int		d[2];
	size_t	i;
	char	*str_number;

	if (!(str_size(&str_number, &d[1], &i, &d[0])))
		return (NULL);
	if (nbr == 0 || nbr == LLONG_MIN)
		return (ft_zero_or_min(nbr));
	if (nbr < 0)
	{
		nbr = -nbr;
		d[1] = 0;
	}
	while (nbr)
	{
		d[0] = nbr % base;
		str_number[i++] = (d[0] > 9) ? (d[0] - 10) + c : d[0] + '0';
		nbr = nbr / base;
	}
	if (!d[1])
		str_number[i++] = '-';
	str_number[i] = '\0';
	return (ft_strrev(str_number));
}

void				ft_putnbr_u(uintmax_t n)
{
	if (n > ULONG_MAX)
		ft_putstr("18446744073709551615");
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
		ft_putchar(48 + n);
}

void				ft_putnbr_ll(intmax_t n)
{
	if (n > LLONG_MAX)
		ft_putstr("-1");
	if (n <= LLONG_MIN)
	{
		ft_putstr("-9");
		n = 223372036854775808;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
	else
		ft_putchar(48 + n);
}
