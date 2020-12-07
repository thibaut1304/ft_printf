/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:47:43 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 00:47:43 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	list_reset(t_format *list)
{
	list->zero = 0;
	list->min = 0;
	list->prec = -1;
	list->width = 0;
	list->count = 0;
	list->type = '0';
}

void	ft_print(t_format *list, va_list param)
{
	if (list->type == '%')
		ft_print_pourcent(list, param);
	else if (list->type == 'c')
		ft_print_char(list, param);
	else if (list->type == 's')
		ft_print_string(list, param);
	else if (list->type == 'd' || list->type == 'i')
		ft_print_integer(list, param);
	else if (list->type == 'u')
		ft_print_unsigned(list, param);
	else if (list->type == 'x')
		ft_print_hex_up_low(list, param, "0123456789abcdef");
	else if (list->type == 'X')
		ft_print_hex_up_low(list, param, "0123456789ABCDEF");
	else if (list->type == 'p')
		ft_print_pointer(list, param, "0123456789abcdef");
}

int		ft_printf(const char *src, ...)
{
	va_list		arg;
	int			i;
	int			nb;
	t_format	*list;

	va_start(arg, src);
	list = malloc(sizeof(t_format));
	i = -1;
	nb = 0;
	while (src[++i])
	{
		if (src[i] != '%' && (nb += 1))
			ft_putchar(src[i]);
		else
		{
			i += ft_pasrse_flag(list, &(src[i + 1]), arg) + 1;
			ft_print(list, arg);
			nb += list->count;
		}
	}
	free(list);
	va_end(arg);
	return (nb);
}
