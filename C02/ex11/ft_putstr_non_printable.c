/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 09:48:44 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/09 12:54:53 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;
	int		tmp;

	hex = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		tmp = str[i];
		if (str[i] < 0)
			tmp += 256;
		if (tmp < 32 || tmp > 126)
		{
			ft_putchar('\\');
			ft_putchar(hex[tmp / 16]);
			ft_putchar(hex[tmp % 16]);
		}
		else
			ft_putchar(tmp);
		i++;
	}
}
