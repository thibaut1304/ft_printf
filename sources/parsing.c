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

int		ft_parse_width(t_format *list, const char *src, va_list arg)
{
	int	i;
	int nb_next;

	i = 0;
	nb_next = 0;
	if (ft_isdigit(src[i]))
		ft_recup_nb_width(src, list);
	else
	{
		nb_next = va_arg(arg, int);
		if (nb_next < 0)
		{
			list->width = -nb_next;
			list->min = 1;
			list->zero = 0;
		}
		else
			list->width = nb_next;
		return (1);
	}
	while (ft_isdigit(src[i]))
		i++;
	return (i);
}

int		ft_parse_prec(t_format *list, const char *src, va_list arg)
{
	int	i;
	int	nb_next;

	i = 1;
	nb_next = 0;
	if (ft_isdigit(src[i]) || src[i] == '-')
		ft_recup_nb_prec(src, list);
	else if (src[i] == '*')
	{
		nb_next = (int)va_arg(arg, int);
		if (nb_next < 0)
			list->prec = -1;
		else
			list->prec = nb_next;
		return (2);
	}
	else
		list->prec = 0;
	while (ft_isdigit(src[i]))
		i++;
	return (i);
}

int		ft_first_pars(const char *src, t_format *list)
{
	int i;

	i = 0;
	if (src[i] == '0' && !list->min)
		list->zero = 1;
	else if (src[i] == '-')
	{
		list->zero = 0;
		list->min = 1;
	}
	if (src[i] == '0' || src[i] == '-')
		i++;
	return (i);
}

int		ft_pasrse_flag(t_format *list, const char *src, va_list arg)
{
	int	i;

	i = 0;
	list_reset(list);
	while ((ft_isdigit(src[i]) || src[i] == '-' || src[i] == '*'
		|| src[i] == '.') && src[i])
	{
		i += ft_first_pars(&(src[i]), list);
		if (ft_isdigit(src[i]) || src[i] == '*')
			i += ft_parse_width(list, &(src[i]), arg);
		else if (src[i] == '.')
			i += ft_parse_prec(list, &(src[i]), arg);
	}
	list->type = src[i];
	return (i);
}
