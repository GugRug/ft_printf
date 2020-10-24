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
	int a = 5; unsigned int un = 5; char c = 'W'; int he = 17080; 
	char *str = "test71";
	// printf("Isso e o pf %.5- real \n%d, %i, %u, %c, %s, %x, %X, %p\n", -234, 3834567899, 3834567899,'h', "abacate", 163, 32456, &a);
	// ft_printf("Isso e um %.5- basico \n%d, %i, %u, %c, %s, %x, %X, %p\n", -234, 3834567899, 3834567899,'h', "abacate", 163, 32456, &a);
	ft_printf("INTEGERS\n");
	ft_printf("ft_printf |%-*d|	-	", 3, a);printf("|%-*d| Correto\n", 3, a);
	ft_printf("ft_printf |%05d|	-	", a);printf("|%05d| Correto\n", a);
	ft_printf("ft_printf |%-05d|	-	", a);printf("|%-05d| Correto\n", a);
	ft_printf("ft_printf |%.9d|	-	", a);printf("|%-.9d| Correto\n", a);
	ft_printf("ft_printf |%-.9d|	-	", a);printf("|%-.9d| Correto\n", a);
	ft_printf("ft_printf |%5.2d|	-	", a);printf("|%5.2d| Correto\n", a);
	ft_printf("ft_printf |%010.2d|	-	", a);printf("|%010.2d| Correto\n", a);


	ft_printf("UNSIGNED INT\n");
	ft_printf("ft_printf |%-*u|	-	", 3, un);printf("|%-*u| Correto\n", 3, un);
	ft_printf("ft_printf |%05u|	-	", un);printf("|%05u| Correto\n", un);
	ft_printf("ft_printf |%-05u|	-	", un);printf("|%-05u| Correto\n", un);
	ft_printf("ft_printf |%.9u|	-	", un);printf("|%-.9u| Correto\n", un);
	ft_printf("ft_printf |%-.9u|	-	", un);printf("|%-.9u| Correto\n", un);
	ft_printf("ft_printf |%5.2u|	-	", un);printf("|%5.2u| Correto\n", un);
	ft_printf("ft_printf |%010.2u|	-	", un);printf("|%010.2u| Correto\n", un);

	ft_printf("HEXDx -> %x\n", he);
	ft_printf("ft_printf |%-*x|	-	", 8, he);printf("|%-*x| Correto\n", 8, he);
	ft_printf("ft_printf |%05x|	-	", he);printf("|%05x| Correto\n", he);
	ft_printf("ft_printf |%-05x|	-	", he);printf("|%-05x| Correto\n", he);
	ft_printf("ft_printf |%.9x|	-	", he);printf("|%-.9x| Correto\n", he);
	ft_printf("ft_printf |%-.9x|	-	", he);printf("|%-.9x| Correto\n", he);
	ft_printf("ft_printf |%5.2x|	-	", he);printf("|%5.2x| Correto\n", he);
	ft_printf("ft_printf |%010.8x|	-	", he);printf("|%010.8x| Correto\n", he);

	ft_printf("CHARS\n");
	ft_printf("ft_printf |%-*c|	-	", 3, c);printf("|%-*c| Correto\n", 3, c);
	ft_printf("ft_printf |%05c|	-	", c);printf("|%05c| Correto\n", c);
	ft_printf("ft_printf |%-05c|	-	", c);printf("|%-05c| Correto\n", c);
	ft_printf("ft_printf |%.9c|	-	", c);printf("|%-.9c| Correto\n", c);
	ft_printf("ft_printf |%-.9c|	-	", c);printf("|%-.9c| Correto\n", c);
	ft_printf("ft_printf |%5.2c|	-	", c);printf("|%5.2c| Correto\n", c);
	ft_printf("ft_printf |%010.2c|	-	", c);printf("|%010.2c| Correto\n", c);

	ft_printf("String -> %s\n", str);
	ft_printf("ft_printf |%-*s|	-	", 8, str);printf("|%-*s| Correto\n", 8, str);
	ft_printf("ft_printf |%05s|	-	", str);printf("|%05s| Correto\n", str);
	ft_printf("ft_printf |%-05s|	-	", str);printf("|%-05s| Correto\n", str);
	ft_printf("ft_printf |%.9s|	-	", str);printf("|%-.9s| Correto\n", str);
	ft_printf("ft_printf |%-.9s|	-	", str);printf("|%-.9s| Correto\n", str);
	ft_printf("ft_printf |%5.2s|	-	", str);printf("|%5.2s| Correto\n", str);
	ft_printf("ft_printf |%010.8s|	-	", str);printf("|%010.8s| Correto\n", str);

	return (0);
}