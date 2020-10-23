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

void	init(t_conv *conv)
{

}

int	main(void)
{
	t_spec *spec;
//	printf("Endereço t:%p\n", &tst);
	spec = (t_spec*)malloc(sizeof(t_spec*) + 17);
	init(spec);
	ft_putnbr(5, spec);
	printf("Teste %c", spec->print[0]);
	//printf("Teste x: %d, y: %d\n", tst->x, tst->y);
	return (0);
}