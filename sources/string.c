/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 00:54:17 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 00:54:17 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_string_list(char *str, t_format *list, int len)
{
	int		i;

	i = 0;
	if (list->prec == 0)
	{
		ft_putnchar_list(' ', len, list);
		return ;
	}
	else if (list->prec > 0)
	{
		while (i < list->prec && str[i])
		{
			ft_putchar_list(str[i], list);
			i++;
		}
		return ;
	}
	while (str[i])
	{
		ft_putchar_list(str[i], list);
		i++;
	}
}

void	ft_print_string(t_format *list, va_list arg)
{
	char	*str;
	int		len;

	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (list->prec >= 0 && list->prec < len)
		len = list->prec;
	if (list->min)
	{
		ft_print_string_list(str, list, len);
		ft_putnchar_list(' ', list->width - len, list);
	}
	else
	{
		if (list->zero)
			ft_putnchar_list('0', list->width - len, list);
		else
			ft_putnchar_list(' ', list->width - len, list);
		ft_print_string_list(str, list, len);
	}
}
