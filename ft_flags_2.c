/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:26:06 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 21:24:10 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_precision(t_conv *conv)
{
	char	*temp;
	int		size;

	if (conv->precision.content > 0)
	{
		size = conv->precision.content - ft_strlen(conv->sp_print);
		if (size > 0)
		{
			temp = strbuild('0', size);
			conv->sp_print = ft_strjoin(conv, temp, conv->sp_print);
			free(temp);
			temp = NULL;
		}
	}
}

void	put_width(t_conv *conv)
{
	char	*temp;
	char	c;
	int		size;
	int		len;

	len = 0;
	if (conv->zero.state == 1)
		len = ft_strlen(conv->part_chr);
	size = conv->width.content - (ft_strlen(conv->sp_print) + len);
	c = ' ';
	if (conv->zero.state == 1 && conv->minus.state == 0)
		c = '0';
	if (size > 0)
	{
		temp = strbuild(c, size);
		if (conv->minus.state == 0)
			conv->sp_print = ft_strjoin(conv, temp, conv->sp_print);
		else
			conv->sp_print = ft_strjoin(conv, conv->sp_print, temp);
		free(temp);
		temp = NULL;
	}
}

char	*strbuild(char c, int n)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char*)malloc(sizeof(char*) * (n + 1));
	while (i < n)
	{
		temp[i] = c;
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

void	special_cases(t_conv *conv)
{
	if (conv->specifier == 'd' || conv->specifier == 'i' ||
		conv->specifier == 'u' || conv->specifier == 'x' ||
		conv->specifier == 'X')
	{
		if (conv->precision.state == 1 && conv->precision.content == 0 &&
			conv->sp_print[0] == '0' && conv->sp_print[1] == '\0')
			conv->sp_print[0] = '\0';
	}
}

void	ft_correct_flags(t_conv *conv)
{
	if (conv->precision.state == 1 && conv->precision.content >= 0)
		conv->zero.state = 0;
}
