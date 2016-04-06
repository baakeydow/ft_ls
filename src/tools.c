/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:53:38 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 03:11:48 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	if (stat(str, &s) == 0)
		if (s.st_mode & S_IFDIR)
			return (1);
	return (0);
}

int				is_link(char *str)
{
	struct stat s;

	if (!str)
		return (0);
	if (lstat(str, &s) == 0)
		if (s.st_mode & S_IFLNK)
			return (1);
	return (0);
}

int				no_dir_in(char **av)
{
	int		i;
	int		cmp;

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

int				just_dir_in(char **av)
{
	int		i;
	int		cmp;

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
