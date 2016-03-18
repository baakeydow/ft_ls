/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 14:52:05 by bndao             #+#    #+#             */
/*   Updated: 2016/01/27 00:53:58 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_splits(const char *str, char c)
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

static char		**ft_real_str(const char *s, int splits_nbr, char c)
{
	int		i[2];
	int		nb;
	char	**tab;

	i[0] = 0;
	i[1] = 0;
	nb = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (splits_nbr + 1))))
		return (NULL);
	tab[splits_nbr] = NULL;
	while (s[nb])
		while (i[0] < splits_nbr)
		{
			while (s[nb] && (s[nb] == c))
				nb++;
			if (s[nb])
				i[1] = nb;
			while (s[nb] && (s[nb] != c))
				nb++;
			tab[i[0]] = ft_strsub(s, i[1], nb - i[1]);
			if (!tab[i[0]])
				return (tab);
			i[0]++;
		}
	return (tab);
}

static char		**ft_return_exception(int sn, char **t, char *trimmed)
{
	if (sn == 0)
	{
		t[0] = NULL;
		t[1] = NULL;
	}
	else
	{
		t[0] = trimmed;
		t[1] = NULL;
	}
	return (t);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	char	*trimmed;
	int		splits_nbr;

	if (!s)
		return (NULL);
	trimmed = ft_strtrim_mod((char *)s, c);
	if (!trimmed)
		return (NULL);
	splits_nbr = ft_count_splits(trimmed, c);
	if (splits_nbr == 0 || splits_nbr == 1)
	{
		if (!(tab = (char **)malloc(sizeof(char *) * 2)))
			return (NULL);
		ft_return_exception(splits_nbr, tab, trimmed);
	}
	else
		tab = ft_real_str(trimmed, splits_nbr, c);
	return (tab);
}
