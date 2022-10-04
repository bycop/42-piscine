/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 13:54:04 by bycop          #+#    #+#             */
/*   Updated: 2020/10/06 19:57:37 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_to_put(char *i, char *j, char *k)
{
	if (*i == '7' && *j == '8' && *k == '9')
	{
		ft_putchar(*i);
		ft_putchar(*j);
		ft_putchar(*k);
	}
	else
	{
		ft_putchar(*i);
		ft_putchar(*j);
		ft_putchar(*k);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char i;
	char j;
	char k;

	i = '0' - 1;
	while (++i <= '7')
	{
		j = i;
		while (++j <= '8')
		{
			k = j;
			while (++k <= '9')
				ft_print_to_put(&i, &j, &k);
		}
	}
}
