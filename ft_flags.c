/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:18:07 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/28 03:56:37 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//Implementing without error treatment
//after this functions, you should expect to have all meaningful data stored in struct atributes

void	ft_read_flags(t_conv *conv, va_list args)
{
	int i;

	i = 0;
	while (conv->flags[i] != '\0')
	{
		if (conv->flags[i] == '-')				//position only will be used in validation data if necessary, maybe delete it later
		{
			conv->minus.state = 1;
			conv->minus.position = i;
		}
		else if (conv->flags[i] == '0')
		{											//will only read the flag without mixing with width 
			if (conv->precision.state == 0)			//before precision
				conv->zero.state = 1;
			conv->zero.position = i;
		}
		else if (conv->flags[i] == '.')
		{
			conv->precision.state = 1;
			conv->precision.position = i;
		}
		else if (conv->flags[i] == '*')				//need to paralell *, one to width and other to precision. do this function later
		{
			ft_flag_asterisk(conv, args);
		}
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
		conv->width.state = 1;											// if need to use width position, set here
		conv->width.content = ft_pf_atoi(conv,&(conv->flags[*ref]));
	}
	else
		conv->precision.content = ft_pf_atoi(conv,&(conv->flags[*ref]));
	*ref += conv->len_atoi;
	conv->len_atoi = 0;
}

void	ft_flag_asterisk(t_conv *conv, va_list args)
{
	if (conv->precision.state == 0)
	{
		conv->asterisk.state = 1;
		conv->asterisk.content = va_arg(args, int);
	}
	else
	{
		conv->asterisk.state_2 = 1;
		conv->asterisk.content_2 = va_arg(args, int);
	}
}

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
