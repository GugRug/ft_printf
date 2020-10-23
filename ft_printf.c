/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:39:47 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 01:03:08 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	t_spec	teste;
	clean_test(&teste);
	printf("Int teste: %%batata");
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	t_spec spec;
	va_list args;
	
	va_start(args, fmt);
	init(spec);
	while (fmt)
	{
		if ()
		{
			
		}
		
	}
}

void	inic(t_spec *spec)
{
	int i;

	i = 0;
	spec->specifier = 0;
	while (i < MAX_FLAGS)
	{
		spec->flags[i];
		i++;
	}
	spec->content = 0;
	spec->size = 0;
	spec->counter = 0;
	spec->print = '/0';
}