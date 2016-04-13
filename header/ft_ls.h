/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:26:33 by bndao             #+#    #+#             */
/*   Updated: 2016/04/05 20:04:41 by bndao            ###   ########.fr       */
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
	time_t					time_c;
	int						one;
	int						l;
	int						rm;
	int						a;
	int						r;
	int						t;
}							t_opt;

t_opt						*get_opt(int ac, char **av);
int							display_error(char **av, t_opt *o);
int							print_all_right(t_opt *o);

t_l							*l_new(char *arg, char *path);
t_l							*getdir_nodes(char *str, t_opt *o);
void						push_back_list(t_l *b_list, t_l *list);

void						merge_sort(t_l **source, t_opt *o);
void						part(t_l *head, t_l **front, t_l **back);
t_l							*merge_lists(t_l *a, t_l *b, t_opt *o);

int							get_padding_size(t_l *l);
int							get_padding_links(t_l *l);
int							get_padding_name(t_l *l);
int							get_padding_grp(t_l *l);
int							*get_tab_spaces(t_l *l);
char						get_type(t_l *l);
void						print_rights(t_l *l);
void						print_size(int len, t_l *l);
void						print_links(int len, t_l *l);
void						print_name(int len, t_l *l);
void						print_grpname(int len, t_l *l);
void						time_it(t_l *l, t_opt *o);

void						get_link(t_l *l);
int							get_total(t_l *l, t_opt *o);
void						l_option(t_l *l, t_opt *o, int *tab);

t_l							*initav_list(char **av, t_opt *o);
t_l							*get_all_d(int i, char **a, t_l *s);
t_l							*all_ex_dir(int i, char **v, t_l *s);
t_l							*not_by_dir(char **av, t_opt *o);
t_l							*by_dir(char **av, t_opt *o);
int							no_dir_in(char **av);
int							just_dir_in(char **av);

int							direcursive(t_l *l, t_opt *o);
void						print_in(t_l *l, t_opt *o, int *tab);

void						just_print(t_l *l, t_opt *o);
int							print_av(t_l *l, t_opt *o);
void						print_file(t_l *lav, t_opt *o, int *tab);
void						print_space(t_l *l, t_opt *o);

int							go_in(char *str, t_opt *o);
void						usage(char *str);
void						title(t_l *lav, t_opt *o);
char						*chams(char *dir, char *file);
int							find_char(char **av, char c);
int							close_dir(DIR *dir);
int							no_option(t_opt *o);
int							thereis_files(t_opt *o);
int							isnot_points(char *str);
int							is_dir(char *str);
int							is_link(char *str);
int							is_opt(char *fmt);

#endif
