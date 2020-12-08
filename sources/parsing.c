/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 01:01:20 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 01:01:20 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int 	ft_parse_flag(const char *src, t_format *list)
{
	int i;

	i = 0;
	while (src[i] == '0' || src[i] == '-'
	|| src[i] == '+' || src[i] == ' ' || src[i] == '#')
	{
		if (src[i] == '0')
			list->zero = 1;
		else if (src[i] == '-')
			list->min = 1;
		else if (src[i] == '+')
			list->plus = 1;
		else if (src[i] == ' ')
			list->space = 1;
		else if (src[i] == '#')
			list->hashtag = 2;
		i++;
	}
	return (i);
}

int		ft_parse_width(const char *src, va_list arg, t_format *list)
{
	int		i;
	int 	nb;

	i = 0;
	nb = 0;
	if (src[i] == '*')
	{
		list->width = va_arg(arg, int);
		i++;
	}
	else if (ft_isdigit(src[i]))
	{
		while (ft_isdigit(src[i]))
			nb = (src[i++] - 48) + nb * 10;
		list->width = nb;
	}
	if (list->width < 0)
	{
		list->width *= -1;
		list->min = 1;
		list->zero = 0;		
	}
	return (i);
}

int		ft_parse_precision(const char *src, va_list arg, t_format *list)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (src[i] == '.')
	{
		i++;
		if (src[i] == '*')
		{
			list->prec = va_arg(arg, int);
			i++;
		}
		else
		{
			while (ft_isdigit(src[i]))
				nb = (src[i++] - 48) + nb * 10;
			list->prec = nb;
		}
		if (list->prec < 0)
			list->prec = -1;
	}
	return (i);
}

int 	ft_flag(const char *src, va_list arg, t_format *list)
{
	int 	i;
	int 	nb;

	nb = 0;
	i = 0;
	list_reset(list);
	i = ft_parse_flag(src, list);
	i += ft_parse_width(&src[i], arg, list);
	i += ft_parse_precision(&src[i], arg, list);
	list->type = src[i];
	return (i);
}
