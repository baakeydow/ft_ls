/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:46:22 by bndao             #+#    #+#             */
/*   Updated: 2016/01/04 17:24:03 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_splits(char *s)
{
	int		nb;
	int		cmp;

	nb = 0;
	cmp = 0;
	while (s[nb])
	{
		while (s[nb] && (s[nb] == ' ' || s[nb] == '\n' || s[nb] == '\t'))
			nb++;
		if (s[nb])
			cmp++;
		while (s[nb] && (s[nb] != ' ' && s[nb] != '\n' && s[nb] != '\t'))
			nb++;
	}
	return (cmp);
}

static char			**ft_real_str(const char *s, int splits_nbr)
{
	int		i[2];
	int		nb;
	char	**tab;

	i[0] = 0;
	i[1] = 0;
	nb = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * splits_nbr + 1)))
		return (NULL);
	tab[splits_nbr] = NULL;
	while (s[nb])
		while (i[0] < splits_nbr)
		{
			while (s[nb] && (s[nb] == ' ' || s[nb] == '\n' || s[nb] == '\t'))
				nb++;
			if (s[nb])
				i[1] = nb;
			while (s[nb] && (s[nb] != ' ' && s[nb] != '\n' && s[nb] != '\t'))
				nb++;
			tab[i[0]] = ft_strsub(s, i[1], nb - i[1]);
			if (!tab[i[0]])
				return (tab);
			i[0]++;
		}
	return (tab);
}

static char			**ft_return_exception(int sn, char **t, char *trimmed)
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

char				**ft_split_whitespaces(const char *s)
{
	char	**tab;
	char	*trimmed;
	int		splits_nbr;

	if (!s)
		return (NULL);
	trimmed = ft_strtrim(s);
	if (!trimmed)
		return (NULL);
	splits_nbr = ft_count_splits(trimmed);
	if (splits_nbr == 0 || splits_nbr == 1)
	{
		if (!(tab = (char **)malloc(sizeof(char *) * 2)))
			return (NULL);
		ft_return_exception(splits_nbr, tab, trimmed);
	}
	else
		tab = ft_real_str(trimmed, splits_nbr);
	return (tab);
}
