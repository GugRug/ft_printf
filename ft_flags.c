/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:07 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/30 21:24:10 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_read_flags(t_conv *conv, va_list args)
{
	int i;

	i = 0;
	while (conv->flags[i] != '\0')
	{
		if (conv->flags[i] == '-')
			conv->minus.state = 1;
		else if (conv->flags[i] == '0')
		{
			if (conv->precision.state == 0)
				conv->zero.state = 1;
			else if (conv->zero.state == 1)
				conv->zero.state = 0;
		}
		else if (conv->flags[i] == '.')
			conv->precision.state = 1;
		else if (conv->flags[i] == '*')
			ft_flag_asterisk(conv, args);
		else if (ft_isnum(conv->flags[i]))
			ft_flag_num(conv, &i);
		i++;
	}
	ft_correct_flags(conv);
}

void	ft_exec_flags(t_conv *conv)
{
	special_cases(conv);
	if (conv->minus.state == 1)
		conv->zero.state = 0;
	if (conv->precision.state == 1 && conv->precision.content != 0)
		put_precision(conv);
	if (conv->part_chr[0] != '\0' && conv->zero.state == 0)
		conv->sp_print = ft_strjoin(conv, conv->part_chr, conv->sp_print);
	if (conv->width.state == 1 && conv->width.content != 0)
		put_width(conv);
	if (conv->part_chr[0] != '\0' && conv->zero.state == 1)
		conv->sp_print = ft_strjoin(conv, conv->part_chr, conv->sp_print);
	ft_putstr(conv, conv->sp_print);
	free(conv->sp_print);
	conv->sp_print = NULL;
	conv->counter += conv->len;
}

void	ft_flag_num(t_conv *conv, int *ref)
{
	if (conv->precision.state == 0)
	{
		conv->width.state = 1;
		conv->width.content = ft_pf_atoi(conv, &(conv->flags[*ref]));
	}
	else
		conv->precision.content = ft_pf_atoi(conv, &(conv->flags[*ref]));
	*ref += (conv->len_atoi - 1);
	conv->len_atoi = 0;
}

void	ft_flag_asterisk(t_conv *conv, va_list args)
{
	int	i;

	i = va_arg(args, int);
	if (i < 0)
	{
		if (conv->precision.state == 0)
		{
			i *= -1;
			conv->minus.state = 1;
		}
	}
	if (conv->precision.state == 0)
	{
		conv->width.state = 1;
		conv->width.content = i;
	}
	if (i < 0 && conv->precision.state == 1)
		conv->precision.state = 0;
	if (conv->precision.state == 1)
	{
		conv->precision.content = i;
	}
}
