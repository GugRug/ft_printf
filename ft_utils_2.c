/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:21:43 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 16:22:38 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_pf_atoi(t_conv *conv, char *str)
{
	int i;
	int soma;
	
	i = 0;
	soma = 0;
	while (str[i] && ft_isnum(str[i]))
	{
		soma = (soma * 10) + (str[i] - '0');
		i++;
	}
	conv->len_atoi = i;
	return (soma);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_isnum(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}
