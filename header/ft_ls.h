/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:26:33 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 17:33:23 by bndao            ###   ########.fr       */
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

typedef struct				s_l
{
	char					*arg;
	struct stat				s;
	struct s_l				*next;
}							t_l;

typedef struct				s_opt
{
	char					**av;
	int						ac;
	int						one;
	int						l;
	int						rm;
	int						a;
	int						r;
	int						t;
}							t_opt;

typedef struct				s_pars
{
	t_l						*l;
	t_opt					*o;
}							t_pars;

void						display_error(char **av);
t_opt						*get_opt(int ac, char **av);
int							find_char(char **av, char c);

t_l							*l_new(char *arg, struct stat s);
void						push_back_list(t_l *b_list, t_l *list);
void						merge_sort(t_l **source);
t_l							*getdir_nodes(char *str, struct stat s);

t_l							*initav_list(t_l *start, char **av, struct stat s);
t_pars						*init_data(t_opt *o, t_l *l);

int							print_av(t_opt *o, struct stat s);
int							print(t_opt *o, struct stat s);

void						usage(char *str);
void						display_av(t_pars *p, t_l *lav, t_l *l);
void						title(t_l *lav, t_pars *p);
int							close_dir(DIR *dir);
int							is_dir(char *str);
int							is_opt(char *fmt);
int							no_option(t_opt *o);
int							thereisno_file(t_opt *o);

#endif
