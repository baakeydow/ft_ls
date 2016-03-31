/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initav_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 05:18:45 by bndao             #+#    #+#             */
/*   Updated: 2016/03/28 05:18:55 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_l					*initav_list(char **av, struct stat s)
{
	int		i;
	t_l 	*start;

	if (no_dir_in(av) || just_dir_in(av))
	{
		i = 2;
		start = l_new(av[1], NULL, s);
		while (av[i])
			push_back_list(start, l_new(av[i++], NULL, s));
		merge_sort(&start);
		return (start);
	}
	else if (!is_dir(av[1]))
		return (not_by_dir(s, av));
	return (by_dir(s, av));
}

t_l					*all_ex_dir(int i, char **av, struct stat s, t_l *start)
{
	while (av[i])
	{
		if (!is_dir(av[i]) && stat(av[i], &s) == 0)
			push_back_list(start, l_new(av[i], NULL, s));
		i++;
	}
	return (start);
}

t_l					*get_all_d(int i, char **av, struct stat s, t_l *start)
{
	while (av[i])
	{
		if (is_dir(av[i]))
			push_back_list(start, l_new(av[i], NULL, s));
		i++;
	}
	return (start);
}

t_l					*not_by_dir(struct stat s, char **av)
{
	int		i;
	t_l 	*start;
	t_l		*tmp;

	i = 1;
	while (av[i])
	{
		if (!is_dir(av[i]) && stat(av[i], &s) == 0)
			break ;
		i++;
	}
	start = l_new(av[i], NULL, s);
	start = all_ex_dir(++i, av, s, start);
	i = 2;
	while (av[i])
	{
		if (is_dir(av[i]))
			break ;
		i++;
	}
	tmp = l_new(av[i], NULL, s);
	i++;
	tmp = get_all_d(i, av, s, tmp);
	merge_sort(&start);
	merge_sort(&tmp);
	push_back_list_mod(start, tmp);
	return (start);
}

t_l					*by_dir(struct stat s, char **av)
{
	int			i;
	t_l			*start;
	t_l			*tmp;

	i = 1;
	while (is_dir(av[i]))
		i++;
	start = l_new(av[i], NULL, s);
	i++;
	start = all_ex_dir(i, av, s, start);
	i = 1;
	while (av[i])
	{
		if (is_dir(av[i]))
			break ;
		i++;
	}
	tmp = l_new(av[i], NULL, s);
	i++;
	tmp = get_all_d(i, av, s, tmp);
	merge_sort(&start);
	merge_sort(&tmp);
	push_back_list_mod(start, tmp);
	return (start);
}
