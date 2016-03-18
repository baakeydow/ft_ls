/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 21:24:17 by bndao             #+#    #+#             */
/*   Updated: 2016/03/09 13:36:29 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					find_h(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'h' && str[i + 1] != 'h' && str[i + 1] != '\0')
			return (1);
		else if (str[i] == 'h' && str[i + 1] == 'h')
			return (0);
		i++;
	}
	return (0);
}

int					find_hh(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'h' && str[i + 1] == 'h')
			return (1);
		else if (str[i] == 'h' && str[i + 1] != 'h')
			return (0);
		i++;
	}
	return (0);
}

int					find_l(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'l' && str[i + 1] != 'l' && str[i + 1] != '\0')
			return (1);
		else if (str[i] == 'l' && str[i + 1] == 'l')
			return (0);
		i++;
	}
	return (0);
}

int					find_ll(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'l' && str[i + 1] == 'l')
			return (1);
		else if (str[i] == 'l' && str[i + 1] != 'l')
			return (0);
		i++;
	}
	return (0);
}

int					find_j(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'j')
			return (1);
		i++;
	}
	return (0);
}
