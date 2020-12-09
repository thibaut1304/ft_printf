/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:39:43 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/09 15:39:43 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		len_nbr(int nb)
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

void	ft_print_nb(long nb, t_format *list)
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
