/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_hex_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:51:36 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 00:51:36 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			ft_len_nbr_base(long long unsigned nbr, char *base)
{
	int		i;
	int		len_base;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr = -nbr;
	len_base = ft_strlen(base);
	if (len_base == 0)
		return (0);
	while (nbr > 0)
	{
		i++;
		nbr /= len_base;
	}
	return (i);
}

void		ft_print_nbr_base(long long unsigned nbr, char *base,
t_format *list)
{
	int		len_base;

	len_base = ft_strlen(base);
	if (nbr >= len_base)
	{
		ft_print_nbr_base(nbr / len_base, base, list);
		ft_print_nbr_base(nbr % len_base, base, list);
	}
	else
		ft_putchar_list(base[nbr % len_base], list);
}
