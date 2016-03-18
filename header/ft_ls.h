/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:26:33 by bndao             #+#    #+#             */
/*   Updated: 2016/03/18 04:08:09 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include "printf.h"
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <uuid/uuid.h>
# include <sys/stat.h>

typedef struct      s_pars
{
  char              **av;
  int               ac;
}                   t_pars;

int   close_dir(DIR *dir);
int   is_dir(char *str);

#endif
