/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 01:35:39 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 17:24:32 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				part(t_l *head, t_l **front, t_l **back)
{
	t_l		*fast;
	t_l		*slow;

	if (!head || !head->next)
	{
		*front = head;
		*back = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = head;
		*back = slow->next;
		slow->next = NULL;
	}
}

static int datecmp (long long int a, long long int b)
{
	if (a <= b)
		return (1);
	else if (a > b)
		return (-1);
	return (0);
}

static int decide_sort(t_l *a, t_l *b, t_opt *o)
{
	if (o->t)
	{
		return (datecmp(a->s.st_mtime, b->s.st_mtime));
	}
	else
		return (ft_strcmp(a->arg, b->arg));
}

t_l				*merge_lists(t_l *a, t_l *b, t_opt *o)
{
	t_l *merge_it;

	merge_it = NULL;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (o->r ? decide_sort(a, b, o) > 0 : decide_sort(a, b, o) < 0)
	{
		merge_it = a;
		merge_it->next = merge_lists(a->next, b, o);
	}
	else
	{
		merge_it = b;
		merge_it->next = merge_lists(a, b->next, o);
	}
	return (merge_it);
}

void			merge_sort(t_l **source, t_opt *o)
{
	t_l		*head;
	t_l		*a;
	t_l		*b;

	head = *source;
	a = NULL;
	b = NULL;
	if (!head || !head->next)
		return ;
	part(head, &a, &b);
	merge_sort(&a, o);
	merge_sort(&b, o);
	*source = merge_lists(a, b, o);
}
