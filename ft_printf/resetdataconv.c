/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetdataconv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:56:25 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 17:59:16 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_data				*wipe_data(void)
{
	t_data		*ptr;

	if (!(ptr = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	ptr->cpy = NULL;
	ptr->o_minus = '\0';
	ptr->o_plus = '\0';
	ptr->o_diez = '\0';
	ptr->o_zero = '\0';
	ptr->o_space = '\0';
	ptr->width = 0;
	ptr->prec = 0;
	ptr->h = 0;
	ptr->hh = 0;
	ptr->l = 0;
	ptr->ll = 0;
	ptr->j = 0;
	ptr->z = 0;
	return (ptr);
}

t_conv				*wipe_conv(void)
{
	t_conv		*ptr;

	if (!(ptr = (t_conv *)malloc(sizeof(t_conv))))
		return (NULL);
	ptr->b_t_conv = NULL;
	ptr->s = '\0';
	ptr->sm = '\0';
	ptr->p = '\0';
	ptr->d = '\0';
	ptr->dm = '\0';
	ptr->i = '\0';
	ptr->o = '\0';
	ptr->om = '\0';
	ptr->u = '\0';
	ptr->um = '\0';
	ptr->x = '\0';
	ptr->xm = '\0';
	ptr->c = '\0';
	ptr->cm = '\0';
	return (ptr);
}

int					handle_glued(t_data *t)
{
	int			i;
	char		c;

	i = 0;
	c = ' ';
	if (t->o_zero)
		c = '0';
	if (t->width && !t->o_minus)
	{
		i = t->width - 1;
		while (i--)
			ft_putchar(c);
		ft_putchar('%');
		return (t->width);
	}
	ft_putchar('%');
	return (1);
}

int					null_case(void)
{
	ft_putstr("(null)");
	return (6);
}

char				*get(const char *fmt)
{
	char		*dup;

	dup = ft_strdup(fmt);
	dup[1] = '\0';
	return (dup);
}
