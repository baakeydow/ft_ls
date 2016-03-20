/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 06:12:18 by bndao             #+#    #+#             */
/*   Updated: 2016/01/03 08:38:59 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		(*node).content = NULL;
		(*node).content_size = 0;
	}
	else
	{
		(*node).content = malloc(sizeof(char) * content_size);
		if ((*node).content)
		{
			ft_memcpy((*node).content, content, content_size);
			(*node).content_size = content_size;
		}
		else
			(*node).content_size = 0;
	}
	(*node).next = NULL;
	return (node);
}
