/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 22:36:01 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/24 13:10:17 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main(void)
{
	int a = 5552; int hex = 161680; char c = 'W';

	
	//ft_printf("Isso e um teste basico \n%d, %i, %u, %c, %s, %x, %X, %p\n", -546, 3834567899, 3834567899,'h', "abacate", 163, 32456, &a);
	ft_printf("\nft_printf |%d|    -    ", a);printf("|%d| Correto\n", a);
	return (0);
}