/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:56:59 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 00:56:59 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			len_nbr_unsigned(unsigned int nbr)
{
	int				i;

	i = 1;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void		ft_print_u_list(unsigned int nbr, t_format *list)
{
	if (nbr >= 10)
	{
		ft_print_u_list(nbr / 10, list);
		ft_print_u_list(nbr % 10, list);
	}
	else
		ft_putchar_list(nbr + '0', list);
}

void		ft_print_unsigned(t_format *list, va_list arg)
{
	unsigned int	nbr;
	int				len;
	int				len_u;

	len = 0;
	nbr = va_arg(arg, unsigned int);
	len_u = len_nbr_unsigned(nbr);
	if (list->prec > len_u)
		len = list->prec;
	else
		len = len_u;
	if (list->prec == 0 && nbr == 0)
	{
		ft_putnchar_list(' ', list->width, list);
		return ;
	}
	if (list->min == 0 && (list->zero == 0 || list->prec != -1))
		ft_putnchar_list(' ', list->width - len, list);
	if (list->zero == 1 && list->prec == -1)
		ft_putnchar_list('0', list->width - len, list);
	if (list->prec > len_u && list->prec != -1)
		ft_putnchar_list('0', list->prec - len_u, list);
	ft_print_u_list(nbr, list);
	if (list->min == 1)
		ft_putnchar_list(' ', list->width - len, list);
}
