/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 22:36:01 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/23 01:17:53 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	inic(t_spec *spec)
{
	int i;

	i = 0;
	spec->specifier = 0;
	while (i <= MAX_FLAGS)
	{
		spec->flags[i] = 0;
		i++;
	}
	spec->content = 0;
	spec->size = 0;
	spec->counter = 0;
	spec->print = 0;
}

int	main(void)
{
	t_spec spec;
	init(&spec);
	ft_putnbr(5, &(spec));
	return (0);
}