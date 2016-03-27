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

t_l				*merge_lists(t_l *a, t_l *b)
{
	t_l *merge_it;

	merge_it = NULL;
	if (!a)
		return (b);
	else if (!b)
		return (a);
	if (ft_strcmp(a->arg, b->arg) < 0)
	{
		merge_it = a;
		merge_it->next = merge_lists(a->next, b);
	}
	else
	{
		merge_it = b;
		merge_it->next = merge_lists(a, b->next);
	}
	return (merge_it);
}

void			merge_sort(t_l **source)
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
	merge_sort(&a);
	merge_sort(&b);
	*source = merge_lists(a, b);
}
