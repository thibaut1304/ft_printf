/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_function_print.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:39:41 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 15:39:41 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putchar_list(char c, t_format *list)
{
	if (c == '+')
		list->plus = 0;
	write(1, &c, 1);
	list->count += 1;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_list(char *str, t_format *list)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar_list(str[i++], list);
}

void	ft_putnchar_list(const char c, const int n, t_format *list)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
	list->count += i;
}
