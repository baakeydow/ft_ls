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

typedef struct      s_l
{
  char              *arg;
  struct stat       s;
  struct s_l        *next;
}                   t_l;

typedef struct      s_pars
{
  t_l               *l;
  t_l               *sub;
  int               ac;
}                   t_pars;

t_l   				      *l_new(char *arg, struct stat s);
void				        push_back_list(t_l *b_list, t_l *list);
void                merge_sort(t_l **source);
t_l                 *getdir_nodes(char *str, struct stat s);

t_l                 *initav_list(t_l *start, char **av, struct stat s);
t_pars              *init_data(int ac, t_l *l);

int                 print_av(int ac, char **av, struct stat s);
int                 print(int ac, struct stat s);

void                display_av(t_pars *p, t_l *lav, t_l *l);
void                title(t_l *lav);
int                 close_dir(DIR *dir);
int                 is_dir(char *str);

#endif
