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

t_l					*initav_list(char **av, t_opt *o)
{
	int		i;
	t_l 	*start;

	if (no_dir_in(av) || just_dir_in(av))
	{
		i = 2;
		start = l_new(NULL, av[1]);
		while (av[i])
			push_back_list(start, l_new(NULL, av[i++]));
		merge_sort(&start, o);
		return (start);
	}
	else if (!is_dir(av[1]))
		return (not_by_dir(av, o));
	return (by_dir(av, o));
}

t_l					*all_ex_dir(int i, char **av, t_l *start)
{
	struct stat s;

	while (av[i])
	{
		if (!is_dir(av[i]) && stat(av[i], &s) == 0)
			push_back_list(start, l_new(NULL, av[i]));
		i++;
	}
	return (start);
}

t_l					*get_all_d(int i, char **av, t_l *start)
{
	while (av[i])
	{
		if (is_dir(av[i]))
			push_back_list(start, l_new(NULL, av[i]));
		i++;
	}
	return (start);
}

t_l					*not_by_dir(char **av, t_opt *o)
{
	int		i;
	struct stat s;
	t_l 	*start;
	t_l		*tmp;

	i = 1;
	while (av[i])
	{
		if (!is_dir(av[i]) && stat(av[i], &s) == 0)
			break ;
		i++;
	}
	start = l_new(NULL, av[i]);
	start = all_ex_dir(++i, av, start);
	i = 2;
	while (av[i])
	{
		if (is_dir(av[i]))
			break ;
		i++;
	}
	tmp = l_new(NULL, av[i]);
	i++;
	tmp = get_all_d(i, av, tmp);
	merge_sort(&start, o);
	merge_sort(&tmp, o);
	push_back_list(start, tmp);
	return (start);
}

t_l					*by_dir(char **av, t_opt *o)
{
	int			i;
	t_l			*start;
	t_l			*tmp;

	i = 1;
	while (is_dir(av[i]))
		i++;
	start = l_new(NULL, av[i]);
	i++;
	start = all_ex_dir(i, av, start);
	i = 1;
	while (av[i])
	{
		if (is_dir(av[i]))
			break ;
		i++;
	}
	tmp = l_new(NULL, av[i]);
	i++;
	tmp = get_all_d(i, av, tmp);
	merge_sort(&start, o);
	merge_sort(&tmp, o);
	push_back_list(start, tmp);
	return (start);
}
