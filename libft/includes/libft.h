/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguyet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:36:11 by jguyet            #+#    #+#             */
/*   Updated: 2016/05/27 21:39:55 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define BOOLEAN int

typedef enum		e_boolean
{
	true = 1,
	false = 0
}					t_boolean;

/*
** PART1
*/

size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(long int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(long int n, int fd);
char				*ft_strdup(char const *s1);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_atoi(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** PART2
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);

/*
** BONUS
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** STRING
*/

char				*ft_dstrjoin(char *s1, char *s2, short flag);
char				*ft_dstrjoin_char(char *s1, char c, short flag);
char				*ft_strndup(const char *src, size_t n);
int					ft_strnchr(char const *s, int c, int nbr);
int					ft_count_char(char *txt, char c);
char				*ft_strtrim_n(char const *s);
void				ft_outstring(char **ptr, int len);
char				*ft_strtrim_string(char const *s, char const *c);
char				**ft_split_string(char const *s, char *c);
unsigned int		ft_lenbychar(char *s, char c);
char				*ft_replace(char *str, char *old, char *new);
char				*ft_strdelandnew(char **del, int size);
BOOLEAN				ft_is_string_printable(char *str);
BOOLEAN				ft_is_string_numeric(char *str);
BOOLEAN				ft_strcontains(char const *src, char const *srh);

/*
** LST
*/

t_list				*ft_lstsplit(char const *src, char c);
void				ft_putlst(t_list *lst);
void				ft_lstaddend(t_list **alst, t_list *new);

/*
** INTEGER
*/

char				*ft_litoa(long long int c);
char				*ft_itoabase(long long int nbr, char *base);
int					*ft_add_end_int(int *tab, int val, int size);
int					ft_nbrlen(long long int nbr);
int					ft_max(int min, int nbr);
char				*ft_convert_double_to_string(double nbr, \
					unsigned int precision);
int					ft_atoi_base(const char *str, int str_base);

/*
** UINT
*/

char				*ft_uitoabase(unsigned long long int nbr, char *base);
char				*ft_uitoa(unsigned long long int c);

/*
** SORTING
*/

void				ft_qsort(void *base, size_t mmemb, char *type,\
					int(*compar)(const void *, const void *));
size_t				array_length(char **array);
void				free_array(char **array);

/*
** Utils
*/
# define TIME_SEC 500000000
# define TIME_MILLIS (TIME_SEC / 1000)

void				ft_sleep(int millis);

# define ___N0		STDERR_FILENO, "{bold}{red}ERROR{white} %s:%i:{reset}\t"
# define ___N1		__FILE__, __LINE__
# define ERROR(format, ...)	ft_dprintf(___N0 format "\n", ___N1, ##__VA_ARGS__)

# define ___N2		"{bold}{yellow}DEBUG {white}%s:%i:{reset}\t"
# define ___N3		__FILE__, __LINE__
# define DEBUG(format, ...)	ft_printf(___N2 format "\n", ___N3, ##__VA_ARGS__)

# define ___N4		"{bold}{yellow}DEBUG {cyan}\'%s\' {white}%s:%i{reset}"
# define ___N5		__func__, __FILE__, __LINE__
# define DEBUGLINE	ft_printf(___N4 "\n", ___N5)

#endif
