/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   untitled                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:53:14 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 00:53:14 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_print_char(t_format *list, va_list param)
{
	char c;

	c = (char)va_arg(param, int);
	if (list->min == 1)
	{
		ft_putchar_list(c, list);
		ft_putnchar_list(' ', list->width - 1, list);
	}
	else if (list->min == 0)
	{
		if (list->zero == 1)
			ft_putnchar_list('0', list->width - 1, list);
		else
			ft_putnchar_list(' ', list->width - 1, list);
		ft_putchar_list(c, list);
	}
}

void		ft_print_pourcent(t_format *list, va_list param)
{
	char c;

	c = '%';
	if (list->min == 1)
	{
		ft_putchar_list(c, list);
		ft_putnchar_list(' ', list->width - 1, list);
	}
	else if (list->min == 0)
	{
		if (list->zero == 1)
			ft_putnchar_list('0', list->width - 1, list);
		else
			ft_putnchar_list(' ', list->width - 1, list);
		ft_putchar_list(c, list);
	}
}
