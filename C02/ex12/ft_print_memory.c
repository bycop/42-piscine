/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 01:47:35 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/22 13:35:14 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);

}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < 32 || str[i] > 126)
			ft_putchar('.');
		else
			ft_putchar(str[i]);
	}
}

void	ft_put_hex(char c)
{
	char *base;

	base = "0123456789abcdef";
	if (c < 32 || c > 126)
		ft_putchar('.');
	else
	{
		ft_putchar(base[c / 16]);
		ft_putchar(base[c % 16]);	
	}
}

void	ft_put_adress(unsigned long nbr, int i)
{
	char *base;

	base = "0123456789abcdef";
	if (nbr >= 16 || i < 16)
		ft_put_adress((nbr / 16), i + 1);
	ft_putchar(base[nbr % 16]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;
	unsigned long adress;

	i = -1;
	adress = (unsigned long)addr;
	ft_put_adress(adress, 0);
	ft_putchar(':');
	ft_putchar(' ');
	while ((char *)addr[++i])
		ft_put_hex((char *)addr[i]);

	return (0);
}

int		main(int ac, char **av)
{
	ft_print_memory(av[1], 16);
}
