/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:57:53 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 00:57:53 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_print_hex_up_low(t_format *list, va_list param, char *base)
{
	long long unsigned	nbr;
	long long			len;
	long long			len_hexa;

	len = 0;
	nbr = va_arg(param, unsigned int);
	len_hexa = ft_len_nbr_base(nbr, base);
	if (list->prec > len_hexa)
		len = list->prec;
	else
		len = len_hexa;
	if (list->prec == 0 && nbr == 0)
	{
		ft_putnchar_list(' ', list->width, list);
		return ;
	}
	if (list->min == 0 && (list->zero == 0 || list->prec != -1))
		ft_putnchar_list(' ', list->width - len, list);
	if (list->zero == 1 && list->prec == -1)
		ft_putnchar_list('0', list->width - len, list);
	if (list->prec > len_hexa)
		ft_putnchar_list('0', list->prec - len_hexa, list);
	ft_print_nbr_base(nbr, base, list);
	if (list->min == 1)
		ft_putnchar_list(' ', list->width - len, list);
}
