/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:26:33 by bndao             #+#    #+#             */
/*   Updated: 2016/03/17 07:53:03 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/libft.h"
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <uuid/uuid.h>
# include <sys/stat.h>

int   close_dir(DIR *dir);
int   is_dir(char *str);

#endif
