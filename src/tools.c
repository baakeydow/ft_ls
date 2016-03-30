/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:53:38 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 17:27:00 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			**just_valid(t_opt *o)
{
	struct stat s;
	int			i;
	int			j;
	char		**tab;

	i = 1;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * o->ac)))
		return (NULL);
	while (o->av[i])
	{
		if (stat(o->av[i], &s) == 0)
			tab[j++] = ft_strdup(o->av[i]);
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

int				is_opt(char *fmt)
{
	int			i;
	struct stat s;

	i = 0;
	if (fmt[0] == '-' && !fmt[1] && stat(fmt, &s) != 0)
		return (0);
	if (fmt[0] != '-' || !fmt[1] || fmt[1] == '-')
		return (0);
	while (fmt[i])
	{
		if (fmt[i] != '-' && fmt[i] != '1' && fmt[i] != 'l' && fmt[i] != 'R' &&
				fmt[i] != 'a' && fmt[i] != 'r' && fmt[i] != 't' &&
				fmt[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int				close_dir(DIR *dir)
{
	if (dir && closedir(dir) == -1)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	return (1);
}

int				is_dir(char *str)
{
	struct stat s;

	if (!str)
		return (0);
	if (lstat(str, &s) == 0)
		if (s.st_mode & S_IFDIR)
			return (1);
	return (0);
}

int 			no_dir_in(char **av)
{
	int 	i;
	int 	cmp;

	i = 1;
	cmp = 0;
	while (av[i])
	{
		if (is_dir(av[i]))
			cmp++;
		i++;
	}
	if (cmp == 0)
		return (1);
	return (0);
}

int 			just_dir_in(char **av)
{
	int 	i;
	int 	cmp;

	i = 1;
	cmp = 0;
	while (av[i])
	{
		if (is_dir(av[i]))
			cmp++;
		i++;
	}
	if (cmp == i - 1)
		return (1);
	return (0);
}
