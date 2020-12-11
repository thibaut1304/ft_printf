/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:46:11 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 00:46:11 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_format
{
	int		zero;
	int		min;
	int		width;
	int		prec;
	int		count;
	int		space;
	int		plus;
	char	type;
}				t_format;

void			list_reset(t_format *list);
int				ft_isdigit(int c);
int				ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putchar_list(char c, t_format *list);
void			ft_putstr_list(char *str, t_format *list);
void			ft_putnchar_list(const char c, const int n, t_format *list);
int				ft_len_nbr_base(long long unsigned nbr, char *base);
void			ft_print_nbr_base(long long unsigned nbr, char *base,
			t_format *list);
void			ft_print_pourcent(t_format *list, va_list param);
void			ft_print_char(t_format *list, va_list param);
void			ft_print_string_list(char *str, t_format *list, int len);
void			ft_print_string(t_format *list, va_list param);
int				len_nbr(long nbr);
void			ft_print_nb(long nb, t_format *list);
int				check_nb_prec(int nb, t_format *list);
void			ft_print_integer_last(t_format *list, int len,
				int lengh_official, int nb);
void			ft_space_plus(t_format *list);
void			ft_print_integer(t_format *list, va_list param);
int				len_nbr_unsigned(unsigned int nbr);
void			ft_print_u_list(unsigned int nbr, t_format *list);
void			ft_print_unsigned(t_format *list, va_list param);
void			ft_print_hex_up_low(t_format *list, va_list param, char *base);
void			ft_zero(int min, int width, t_format *list);
void			ft_print_pointer(t_format *list, va_list param, char *base);
void			ft_print(t_format *list, va_list param);
int				ft_flag(const char *src, va_list arg, t_format *list);
int				ft_parse_precision(const char *src, va_list arg,
				t_format *list);
int				ft_parse_width(const char *src, va_list arg, t_format *list);
int				ft_parse_flag(const char *src, t_format *list);
int				ft_printf(const char *src, ...);
#endif
