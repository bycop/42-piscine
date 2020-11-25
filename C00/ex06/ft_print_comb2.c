/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 14:57:01 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/06 21:42:54 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0 - 1;
	while (++i <= 98)
	{
		j = 0;
		while (++j <= 99)
		{
			if (i < j)
			{
				ft_putchar(i / 10 + '0');
				ft_putchar(i % 10 + '0');
				ft_putchar(' ');
				ft_putchar(j / 10 + '0');
				ft_putchar(j % 10 + '0');
				if (i != 98 || j != 99)
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
