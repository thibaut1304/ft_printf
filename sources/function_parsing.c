/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thhusser <thhusser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 01:00:04 by thhusser          #+#    #+#             */
/*   Updated: 2020/12/05 01:00:04 by thhusser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void		ft_recup_nb_width(const char *src, t_format *list)
{
	int j;

	j = 0;
	while (ft_isdigit(src[j]))
	{
		list->width = (src[j] - 48) + list->width * 10;
		j++;
	}
}

void	ft_recup_nb_prec(const char *src, t_format *list)
{
	int i;
	int nb_next;
	int sign;

	i = 1;
	sign = 0;
	nb_next = 0;
	if (src[i] == '-')
	{
		sign = 1;
		i++;
	}
	while (ft_isdigit(src[i]))
	{
		nb_next = (src[i] - 48) + nb_next * 10;
		i++;
	}
	list->prec = nb_next;
	if (sign == 1)
		list->prec = -1;
}
