/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <jguyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:11:36 by jguyet            #+#    #+#             */
/*   Updated: 2016/07/12 19:16:09 by jguyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <libft.h>
# include <stdarg.h>
# include <stdlib.h>

int						ft_printf(const char *s, ...);
int						ft_fprintf(int fd, const char *s, ...);
int						ft_asprintf(char **ptr, const char *s, ...);
char					*ft_sprintf(const char *s, ...);

# ifdef PRINTF_PROG

typedef struct			s_convert
{
	char				type[2];
}						t_convert;

typedef enum			e_ptr_conv
{
	s = 0,
	d,
	c,
	i,
	x,
	big_x,
	big_c,
	big_s,
	p,
	big_d,
	o,
	big_o,
	u,
	big_u,
	f,
	big_f,
	conv_len
}						t_ptr_conv;

#  define BUFFER_SUBNUM 100

typedef struct			s_string
{
	char				*s;
	va_list				list;
	unsigned int		res;
	unsigned int		size;
	t_convert			converter;
	unsigned short		sub_flags;
	char				sub_num[BUFFER_SUBNUM];
	char				*new;
	int					space;
	int					zero;
	short				is_negative;
	short				left;
	short				pad;
	short				base;
	short				end;
	char				*tmp;
	int					tmp_alloc;
	void				*ptrs[conv_len];
	char				is_big;
	wchar_t				*wtmp;
}						t_string;

#  define BUFFER 1024
#  define FLAG string->s + (i + 1)
#  define SECURE string->s[i + 1] != '\0'
#  define AI (i = i + 1)
#  define SUB_SHARP 1024
#  define SUB_ZERO 2048
#  define SUB_INF 4096
#  define SUB_SUP 8192
#  define SUB_SPACE 16384
#  define DELIMITER '%'
#  define MAX_UINT 4294967295
#  define NRM  "\x1B[0m"
#  define RED  "\x1B[31m"
#  define GRN  "\x1B[32m"
#  define YEL  "\x1B[33m"
#  define BLU  "\x1B[34m"
#  define MAG  "\x1B[35m"
#  define CYN  "\x1B[36m"
#  define WHT  "\x1B[37m"
#  define BOL  "\e[1m"
#  define BONUS 1

void					load_ptr_function(t_string *string);
/*
**	HANDLER
*/

int						parse_flags(t_string *string, int i);
void					load(t_string *t);
void					modif_colors(t_string *string);
void					precision(t_string *t);
void					fill_character(t_string *t, char c);
void					process_left(t_string *t);
void					process_right(t_string *t);
/*
** FUNCTION
*/

void					add_string(t_string *string, char *s, int del);
void					add_char(t_string *string, char c);
void					add_zero(t_string *string, int zero);
void					add_space(t_string *string, int space);
void					add_int(t_string *string, int s);
void					add_uint(t_string *string, unsigned int s);
void					add_uint_long(t_string *string, unsigned long int s);
void					add_long_int(t_string *string, long int s);
void					add_uint_long_long(t_string *string, \
						unsigned long long int s);
/*
**	SUBFLAGS
*/

int						sub_flags(t_string *string, int i);

/*
**	GET
*/

# ifdef __linux__

typedef long long int intmax_t;

# endif

char					get_char(t_string *t);
unsigned char			get_uchar(t_string *t);
wchar_t					get_wchar(t_string *t);
int						get_int(t_string *t);
unsigned int			get_uint(t_string *t);
unsigned long			get_ulong(t_string *t);
long int				get_long_int(t_string *t);
unsigned long int		get_ulong_int(t_string *t);
long long int			get_long_long_int(t_string *t);
unsigned long long int	get_ulong_long_int(t_string *t);
char					*get_string(t_string *t);
wchar_t					*get_wstring(t_string *t);
double					get_double(t_string *t);
short					get_short(t_string *t);
unsigned short			get_ushort(t_string *t);
intmax_t				get_intmax_t(t_string *t);
size_t					get_size_t(t_string *t);
int						get_ptr_function(t_string *string, \
						int i, int f(t_string*, int));
double					get_float(t_string *t);

/*
**	ADD
*/

void					add_wchar(t_string *t, wchar_t c);
char					*wschar_to_string(wchar_t *s);
char					*wchar_to_string(wchar_t c);
int						ft_wslen(wchar_t *c);
int						ft_wlen(wchar_t c);
int						add_wildcard(int i, t_string *t, short point);
int						sub(t_string *string, int i, char *s, int zero);

/*
** CONVERSION
*/

int						conv_big_s(t_string *string, int i);
int						conv_big_c(t_string *string, int i);
int						conv_big_d(t_string *string, int i);
int						conv_big_o(t_string *string, int i);
int						conv_big_u(t_string *string, int i);
int						conv_big_x(t_string *string, int i);
int						conv_s(t_string *string, int i);
int						conv_c(t_string *string, int i);
int						conv_d(t_string *string, int i);
int						conv_i(t_string *string, int i);
int						conv_o(t_string *string, int i);
int						conv_p(t_string *string, int i);
int						conv_purcent(t_string *string, int i);
int						conv_u(t_string *string, int i);
int						conv_x(t_string *string, int i);
int						conv_f(t_string *string, int i);

/*
** FLAGS
*/

void					flag_default_char(t_string *string, char tmp);
void					flag_default_string(t_string *string, \
						char *tmp, short del);
void					add_conv_string(t_string *t, char *s);
void					add_conv_char(t_string *t, char c);
void					add_conv_wchar(t_string *t, wchar_t c);
char					*flag_ll(t_string *string, short base);
char					*flag_ull(t_string *string, short base);
char					*flag_z(t_string *string, short base);
char					*flag_l(t_string *string, short base);
char					*flag_ul(t_string *string, short base);
char					*flag_hh(t_string *string, short base);
char					*flag_uhh(t_string *string, short base);
char					*flag_h(t_string *string, short base);
char					*flag_uh(t_string *string, short base);
char					*flag_j(t_string *string, short base);
char					*flag_int(t_string *string, short base);
char					*flag_uint(t_string *string, short base);

/*
** BASES
*/

char					alt_eight(t_string *t);
char					if_flag_sixteen(t_string *t);
char					if_flag_ten(t_string *t);
char					is_flag_eight(t_string *t);

# endif
#endif
