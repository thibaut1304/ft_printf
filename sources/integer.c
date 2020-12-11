/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:56:00 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 00:56:00 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		check_nb_prec(int nb, t_format *list)
{
	if (list->prec == 0 && nb == 0)
	{
		if (list->space && !list->plus)
		{
			list->width--;
			ft_putchar_list(' ', list);
		}
		if (list->plus && list->min)
			ft_putchar_list('+', list);
		if (list->plus && list->width == 0)
			ft_putchar_list('+', list);
		if (list->width != 0)
			ft_putnchar_list(' ', list->width, list);
		if (list->plus && list->width != 0)
			ft_putchar_list('+', list);
		return (1);
	}
	return (0);
}

void	ft_print_integer_last(t_format *list, int len,
		int lengh_official, int nb)
{
	if (list->min == 0 && (list->zero == 0 || list->prec != -1))
	{
		ft_putnchar_list(' ', list->width - len, list);
		if (list->plus && nb >= 0)
			ft_putchar_list('+', list);
	}
	if (nb < 0)
		ft_putchar_list('-', list);
	if (list->zero == 1 && list->prec == -1)
	{
		if (list->plus && nb >= 0)
			ft_putchar_list('+', list);
		ft_putnchar_list('0', list->width - len, list);
	}
	if (list->prec > lengh_official && list->prec != -1)
	{
		if (list->plus && nb >= 0)
			ft_putchar_list('+', list);
		ft_putnchar_list('0', list->prec - lengh_official, list);
	}
	if (list->min && list->plus && nb >= 0)
		ft_putchar_list('+', list);
	ft_print_nb(nb, list);
	if (list->min == 1)
		ft_putnchar_list(' ', list->width - len, list);
}

void	ft_space_plus(t_format *list)
{
	list->width--;
	ft_putchar_list(' ', list);
}

void	ft_print_integer(t_format *list, va_list param)
{
	int	nb;
	int	len;
	int	lengh_official;

	nb = va_arg(param, int);
	lengh_official = len_nbr(nb);
	if (nb < 0)
		list->width--;
	if (list->prec > lengh_official)
		len = list->prec;
	else
		len = lengh_official;
	if (list->plus && nb >= 0)
		list->width--;
	if (check_nb_prec(nb, list))
		return ;
	if (list->space && !list->plus && nb >= 0)
		ft_space_plus(list);
	ft_print_integer_last(list, len, lengh_official, nb);
}
