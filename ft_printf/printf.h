/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:55:16 by bndao             #+#    #+#             */
/*   Updated: 2016/03/18 03:57:33 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>
# define TAB_SIZE 14

typedef struct	s_data
{
	char		*cpy;
	char		o_minus;
	char		o_plus;
	char		o_diez;
	char		o_zero;
	char		o_space;
	int			width;
	int			prec;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_data;

typedef struct	s_conv
{
	char		*b_t_conv;
	char		s;
	char		sm;
	char		p;
	char		d;
	char		dm;
	char		i;
	char		o;
	char		om;
	char		u;
	char		um;
	char		x;
	char		xm;
	char		c;
	char		cm;
}				t_conv;

typedef struct	s_va_arg
{
	int			(*f)(va_list conv, struct s_data *t, struct s_conv *c);
	char		c;
}				t_va_arg;

struct s_va_arg	tab[TAB_SIZE];
intmax_t		size_d(va_list conv, t_data *t, t_conv *c);
uintmax_t		size_uox(va_list conv, t_data *t, t_conv *c);
int				ft_printf(const char *format, ...);
char			*ft_widechar_2_reg(wchar_t wide);
char			*ft_widestr_2_reg(wchar_t *src);
char			*ft_itoa_base(long long int nbr, int base, char c);
char			*ft_uitoa_base(uintmax_t nbr, int base, char c);
char			*ft_itoa_ll(intmax_t nbr);
char			*ft_itoa_ull(uintmax_t nbr);
void			ft_putnbr_u(uintmax_t n);
void			ft_putnbr_ll(intmax_t n);
int				find_h(char *str);
int				find_hh(char *str);
int				find_l(char *str);
int				find_ll(char *str);
int				find_j(char *str);
int				find_z(char *str);
int				false_type(t_conv *c);
int				printchar(const char **cpy);
int				handle_no_p_cent(const char *cpy);
int				is_not_data(const char *fmt, int *i);
int				handle_glued(t_data *t);
int				percent_nbr(const char *fmt);
t_data			*init(const char *cpy);
t_data			*wipe_data(void);
t_conv			*init_conv(const char *cpy);
t_conv			*wipe_conv(void);
char			*before_t_conv(const char *fmt);
char			*after_t_conv(const char *fmt, t_conv *c, t_data *t);
int				is_b_t_conv(const char *fmt, int *i);
char			*get(const char *fmt);
char			return_char(char *fmt, char c);
int				null_case(void);
char			find_o_zero(char *fmt);
int				find_width(char *str);
int				find_prec(char *str);
int				prec_str(t_data *t, char *str, t_conv *c);
int				prec_str_wide(t_data *t, int len, char *str, t_conv *c);
int				get_wide_prec(int prec, wchar_t wide);
int				len_str(t_data *t, char *str, t_conv *c);
int				handle_false_type(t_conv *c, t_data *t);
int				handle_width_d(int len, t_data *t, intmax_t d, t_conv *c);
int				handle_width_u(int len, t_data *t, uintmax_t d, t_conv *c);
int				handle_width(int len_conv, t_data *t, t_conv *c);
int				handle_o_point(int len_conv, t_data *t, intmax_t d);
int				handle_o_point_u(int len_conv, t_data *t);
int				handle_o_zero_d(intmax_t d, t_data *t, t_conv *c);
int				handle_o_space(intmax_t d, t_data *t, t_conv *c);
int				handle_s(va_list conv, t_data *t, t_conv *c);
int				handle_s_maj(va_list conv, t_data *t, t_conv *c);
int				handle_d(va_list conv, t_data *t, t_conv *c);
int				handle_d_maj(va_list conv, t_data *t, t_conv *c);
int				handle_i(va_list conv, t_data *t, t_conv *c);
int				handle_u(va_list conv, t_data *t, t_conv *c);
int				handle_u_maj(va_list conv, t_data *t, t_conv *c);
int				handle_c(va_list conv, t_data *t, t_conv *c);
int				handle_c_maj(va_list conv, t_data *t, t_conv *c);
int				handle_x(va_list conv, t_data *t, t_conv *c);
int				handle_x_maj(va_list conv, t_data *t, t_conv *c);
int				handle_o(va_list conv, t_data *t, t_conv *c);
int				handle_o_maj(va_list conv, t_data *t, t_conv *c);
int				handle_p(va_list conv, t_data *t, t_conv *c);

#endif
