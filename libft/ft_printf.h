/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:40:10 by yharwyn-          #+#    #+#             */
/*   Updated: 2019/03/11 08:14:20 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

enum { FAIL = -1, SUCCESS = 0 };

# define ISFAILED(f) if ((f) == FAIL) return (FAIL);

/*
** MIN will give us min value of type (ex: MIN(char) = -256)
*/
# define MIN(x) (1LL << (sizeof(x) * 8 - 1))

typedef struct		s_type
{
	char			*type;
	char			*flags;
	int				width;
	int				precision;
	char			zero;
}					t_type;

int					ft_printf(const char *format, ...);
void				ft_freenode(t_type *node);

int					ft_isfl_in(t_type *node, char flag);
int					ft_flagssearcher(t_type *node, const char *format,
	size_t *i);
int					ft_widthsearcher(t_type *node, const char *format,
	size_t *i);
int					ft_precisionsearcher(t_type *node, const char *format,
	size_t *i);
int					ft_typesearcher(t_type *node, const char *format,
	size_t *i);

int					ft_typevalidator(t_type *node, int len, size_t *i);
int					ft_flagsvalidator(char flag);
int					ft_numvalidator(const char *format, size_t *i);

int					ft_print_dispatcher(t_type *node, va_list args);
int					cmp(char *type, char *c);

void				ft_flagminus(t_type *node, char *to, char *from, int *i);
void				ft_flagzero(t_type *node, char *str, int *i);

int					ft_print_string(t_type *node, char *str, int i);
int					print_color_string(t_type *node, char *str, int i, int mod);

int					ft_print_char(t_type *node, int c, int i);

void				turnoff_fl(char *flags, char c);

int					ft_print_int(t_type *node, char *str, int i);
void				ft_swap(char *a, char *b);
int					ft_isnegative(char *str);
void				ft_zerofiller(t_type *node, char *str, int len, int *i);
void				ft_fillin_num(t_type *node, char *to, char *from, int len);
void				ft_flagminus_num(t_type *node, char *str, int len);
void				ft_flagplus_num(t_type *node, char *str, int minus,
	int len);
void				ft_flagsp_num(char *str, int len);

int					ft_print_u(t_type *node, char *str, int i);

char				*ft_itoa_ui(unsigned int n);
char				*ft_itoa_ll(long n);
char				*ft_itoa_ull(unsigned long n);
char				*ft_itoa_uh(unsigned short n);
char				*ft_itoa_im(intmax_t n);
char				*ft_itoa_uim(uintmax_t n);
char				*ft_itoa_st(ssize_t n);
char				*ft_itoa_uhh(unsigned char n);
char				*ft_ftoa(double n, int afterpoint, t_type *node);
char				*ft_ntoa_base(uintmax_t n, int base);
char				*ft_ldtoa(long double n, int afterpoint, t_type *node);

int					ft_print_x(t_type *node, char *str);
int					ft_ntoa_dispatcher(t_type *node, char *n, int base);
unsigned long		ft_nlen(uintmax_t n, int base);
void				str2upcase(char *str);

intmax_t			ft_abs(intmax_t n);
void				str2upcase(char *str);

char				*shift_npos(char *str, int n);
char				*expand_str(char *str);

int					ft_print_float(t_type *node, double n, int i);
int					ft_print_ld(t_type *node, long double n, int i);
void				ft_addflag(t_type *node, char flag);
void				add_flag(t_type **node, char mod);
char				*zero_cases(t_type *node, char *str);
char				*ntoa_xflags(t_type *node, char *n, int base);
char				*ntoa_oflags(t_type *node, char *n, int base);
char				*hash(char *str, t_type *node, int i);
char				*octo_addzero(char *str);
int					printf_len_corrector(t_type *node, char *str, int len);

void				join_parts(char *floatrdy, char *intres, char *floatres);
void				ft_flagminus_float(char *str, int len);
void				sharpmod(char *floatrdy);
char				*afterminus(t_type *node, char *fres, char *intres);

char				*zeroprec(double floatpart, long res);
double				roundgenerator(int prec);
char				*zeroprec2(long double floatpart, long res);
long double			roundgenerator2(int prec);

void				ft_zerofiller2(t_type *node, char *str, int len, int *i);
void				ft_zerofiller3(t_type *node, char *str, int len, int i);
int					ft_isnegative2(char *str);
void				ft_flagminus_num2(char *str, int len);
int					is_const(char *str);

int					ft_print_fconst(t_type *node, char *str, int i);

int					ft_print_float2(t_type *node, char *str, int minus);
int					ifzero(t_type *node, int i);

#endif
