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

int			len_nbr(int nb)
{
	int				i;

	i = 1;
	if (nb < 0)
		nb = -nb;
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void		ft_print_nb(long nb, t_format *list)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_print_nb(nb / 10, list);
		ft_print_nb(nb % 10, list);
	}
	else
		ft_putchar_list(nb + '0', list);
}

int			check_nb_prec(int nb, t_format *list)
{
	if (list->prec == 0 && nb == 0)
	{
		ft_putnchar_list(' ', list->width, list);
		return (1);
	}
	return (0);
}

void		ft_print_integer(t_format *list, va_list param)
{
	int	nb;
	int	len;
	int	lengh_official;

	nb = (int)va_arg(param, int);
	lengh_official = len_nbr(nb);
	if (nb < 0)
		list->width--;
	if (list->prec > lengh_official)
		len = list->prec;
	else
		len = lengh_official;
	if (check_nb_prec(nb, list))
		return ;
	if (list->min == 0 && (list->zero == 0 || list->prec != -1))
		ft_putnchar_list(' ', list->width - len, list);
	if (nb < 0)
		ft_putchar_list('-', list);
	if (list->zero == 1 && list->prec == -1)
		ft_putnchar_list('0', list->width - len, list);
	if (list->prec > lengh_official && list->prec != -1)
		ft_putnchar_list('0', list->prec - lengh_official, list);
	ft_print_nb(nb, list);
	if (list->min == 1)
		ft_putnchar_list(' ', list->width - len, list);
}
