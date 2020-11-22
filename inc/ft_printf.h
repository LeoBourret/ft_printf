#ifndef __FT_PRINTF_H__
# define __FT_PRINTF_H__

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef	struct		s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

t_flags		ft_init_flags(void);

int			ft_putchar_ret(char);
int			ft_putstr_ret(char*);
int			ft_putstr_prec(char*, int);

int			ft_parser(const char*, int, t_flags*, va_list);
int			ft_manage_type(int, va_list, t_flags);
int			ft_print_width(int, int, int);
int			ft_print_int(char*, t_flags, long, int);
int			ft_manage_hex(unsigned int, t_flags, int);
int			ft_manage_char(char, t_flags);
int			ft_manage_str(char*, t_flags);
int			ft_manage_int(int, t_flags);
int			ft_manage_uint(unsigned int, t_flags);
int			ft_manage_percent(t_flags flags);
int			ft_manage_addr(unsigned long long, t_flags);
int			ft_parser(const char*, int, t_flags*, va_list);

long		ft_abs(long);
int			ft_nblen(long);
int			ft_strlen(char*);
int			ft_isdigit(int);
int			ft_istype(int);
int			ft_isflag(int);
int			ft_flag_dot(const char*, int, t_flags*, va_list);
void		ft_flag_digit(char, t_flags*);
void		ft_flag_minus(t_flags*);
void		ft_flag_width(t_flags*, va_list);


char		*ft_strdup(char*);
char		*ft_strcat(char*, char*);
char		*ft_realloc(char*, int);
char		*ft_itoa(long);
char		*ft_itoa_hex(long);
char		*ft_set_strlower(char*);
char		*ft_addr_to_char(char*);
char		*ft_tolower(char*);

#endif
