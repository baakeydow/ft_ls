/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 09:38:17 by bndao             #+#    #+#             */
/*   Updated: 2016/01/03 09:49:01 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*compt;
	t_list		*stock;

	new = NULL;
	if (lst != NULL && f != NULL)
	{
		new = f(lst);
		compt = new;
		while (lst->next)
		{
			lst = lst->next;
			stock = f(lst);
			if (stock == NULL)
				return (0);
			compt->next = stock;
			compt = compt->next;
		}
	}
	return (new);
}
