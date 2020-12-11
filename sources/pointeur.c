/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointeur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:59:05 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 00:59:05 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_zero(int min, int width, t_format *list)
{
	if (min)
	{
		ft_putstr_list("0x", list);
		ft_putnchar_list(' ', width, list);
	}
	else
	{
		ft_putnchar_list(' ', width, list);
		ft_putstr_list("0x", list);
	}
}

void	ft_print_pointer(t_format *list, va_list param, char *base)
{
	long long unsigned	nbr;
	long long			len;

	nbr = va_arg(param, long long);
	list->width -= 2;
	if (list->prec > ft_len_nbr_base(nbr, base))
		len = list->prec;
	else
		len = ft_len_nbr_base(nbr, base);
	if (nbr == 0 && list->prec == 0)
	{
		ft_zero(list->min, list->width, list);
		return ;
	}
	if (list->min == 0)
		ft_putnchar_list(' ', list->width - len, list);
	ft_putstr_list("0x", list);
	if (list->zero && list->prec == -1)
		ft_putnchar_list('0', list->width - len, list);
	if (list->prec > ft_len_nbr_base(nbr, base))
		ft_putnchar_list('0', list->prec - ft_len_nbr_base(nbr, base), list);
	ft_print_nbr_base(nbr, base, list);
	if (list->min)
		ft_putnchar_list(' ', list->width - len, list);
}
