/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:07 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/28 02:33:19 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//Implementing without error treatment


void	ft_read_flags(t_conv *conv, va_list args)
{
	int i;

	i = 0;
	while (conv->flags[i] != '\0')
	{
		if (conv->flags[i] == '-')
			conv->minus.state = 1;
		else if (conv->flags[i] == '0')				//will only read the flag without mixing with width 
			if (conv->precision.state == 0)			//before precision
				conv->zero.state = 1;
		else if (conv->flags[i] == '.')
			conv->precision.state = 1;
		else if (ft_isnum(conv->flags[i]))
			ft_flag_num(conv, args, &i);			//deal with all sequencial numbers from here, after it, 
  													//need only i++ one time to skip number
		i++;
	}
}


void	ft_flag_num(t_conv *conv, va_list args, int *ref)
{
	if (conv->precision.state == 0)
	{
		conv->width.state = 1;
		conv->width.content = 0;			//to change
	}
	else
	{
		conv->precision.content = 0;       //to change
	}
	
	
}

// void	setflag(t_conv *conv, const char *fmt)
// {
// 	return;
// }



// void	ft_exec_flags(t_conv *conv, size_t nb)
// {
// 	ft_cut_flags(conv, nb);
// }

// void	ft_cut_flags(t_conv *conv, size_t nb)
// {
// 	int i;
// 	int size;

// 	i = 0;
// 	size = conv->len;
	
// }

// void	ft_flags_side_check()
