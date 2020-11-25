/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 09:49:18 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/11 18:04:08 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		exceptions(char *base, int nb)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] < 32 || base[i] > 126)
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (nb == 0)
		ft_putchar(base[0]);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;
	int			j;
	int			res[100];
	int			i;

	i = 0;
	j = ft_strlen(base);
	nb = nbr;
	if (exceptions(base, nb) == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		while (nb)
		{
			res[i] = nb % j;
			nb = nb / j;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[res[i]]);
	}
}
