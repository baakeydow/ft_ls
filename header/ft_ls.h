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
# include <pwd.h>
# include <sys/dir.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/stat.h>
# include <time.h>

typedef struct				s_l
{
	char					*arg;
	char					*path;
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


char						*get_path(char *dir, char *file);
char						get_type(t_l *l);
int							get_total(t_l *l, t_opt *o);
void						print_rights(t_l *l);
void						time_it(t_l *l);
void						l_option(t_l *l, t_opt *o);

void						display_error(char **av, t_opt *o);
t_opt						*get_opt(int ac, char **av);
int							find_char(char **av, char c);

t_l							*l_new(char *arg, char *path, struct stat s);
void						push_back_list(t_l *b_list, t_l *list);
void						push_back_list_mod(t_l *b_list, t_l *list);
void						merge_sort(t_l **source, t_opt *o);
t_l							*getdir_nodes(char *str, struct stat s, t_opt *o);

int							no_dir_in(char **av);
int							just_dir_in(char **av);
t_l							*get_all_d(int i, char **a, struct stat l, t_l *s);
t_l							*all_ex_dir(int i, char **v, struct stat l, t_l *s);
t_l							*not_by_dir(struct stat s, char **av, t_opt *o);
t_l							*by_dir(struct stat s, char **av, t_opt *o);
t_l							*initav_list(char **av, struct stat s, t_opt *o);

int							direcursive(t_l *l, t_opt *o);
int							print_av(t_opt *o, struct stat s);
int							print(t_opt *o, char *str);
void						just_print(t_l *l, t_opt *o);

void						print_in(t_opt *o, t_l *l);
void						codekeepin(t_opt *o, t_l *lav);
void						display_av(t_opt *o, t_l *lav, t_l *l);
void						usage(char *str);
void						title(t_l *lav, t_opt *o);
int							close_dir(DIR *dir);
int							is_dir(char *str);
int							is_link(char *str);
int							is_opt(char *fmt);
int							no_option(t_opt *o);
int							thereis_files(t_opt *o);

#endif
