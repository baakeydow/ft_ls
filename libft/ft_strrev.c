/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 08:38:41 by bndao             #+#    #+#             */
/*   Updated: 2016/01/04 08:47:02 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrev(const char *s)
{
	int		len;
	int		i;
	char	*result;

	len = ft_strlen(s);
	i = 0;
	if (!(result = (char *)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (len--)
		result[i++] = s[len];
	result[i] = '\0';
	return (result);
}
