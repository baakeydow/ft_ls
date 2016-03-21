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
  struct s_l        *prev;
}                   t_l;

typedef struct			s_mylist
{
	t_l    			     	*begin;
}						        t_mylist;

typedef struct      s_pars
{
  t_l               *l;
  t_mylist          *b;
  int               st_mode;
  int               ac;
}                   t_pars;

t_l   				      *l_new(char *arg, struct stat s);
t_l                 *init_list(t_l *start, char **av, struct stat s);
t_pars              *init_data(t_l *l, t_mylist *b);
t_pars              *init_all(char **av, struct stat s);
void				      	swap_elem_data(t_l *elem1, t_l *elem2);
void				        push_back_list(t_l *b_list, t_l *list);
int                 print_no_av(int ac, struct stat s);
int                 print_dir(int ac, DIR *dir, struct dirent *file, t_pars *p);
void                dir_regfilenames(struct dirent *file, DIR *dir);
void                title(int ac, t_pars *p);
int                 close_dir(DIR *dir);
int                 is_dir(char *str);

#endif
