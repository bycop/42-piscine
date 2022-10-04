/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:34:08 by bycop          #+#    #+#             */
/*   Updated: 2020/10/22 14:19:56 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		exceptions(char *base);
int		check(char *base, char c);
char	*ft_rev_int_tab(char *tab, int size);
int		tailleint(int nbr, int baselen);

int		ft_atoi_base(char *str, char *base)
{
	int		i;
	int		neg;
	int		res;
	int		j;

	i = 0;
	neg = 1;
	res = 0;
	j = ft_strlen(base);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && check(base, str[i]) != -1)
	{
		res = res * j + check(base, str[i]);
		i++;
	}
	return (res * neg);
}

char	*ft_putnbr_base(int nbr, char *base, char *res)
{
	int			j;
	int			i;
	int			neg;

	neg = nbr;
	i = 0;
	i = 0;
	j = ft_strlen(base);
	if (nbr == 0)
	{
		res[0] = base[0];
		return (res);
	}
	if (nbr < 0)
		nbr = nbr * -1;
	while (nbr)
	{
		res[i] = base[nbr % j];
		nbr = nbr / j;
		i++;
	}
	if (neg < 0)
		res[i++] = '-';
	res[i] = '\0';
	return (res);
}

int		check_test(char *str, char *base_from)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '-' || str[i] == '+' ||
			(str[i] >= 9 && str[i] <= 13))
		i++;
	if (check(base_from, str[i]) == -1)
		return (0);
	return (1);
}

char	*malloc_s(int nb, char *base)
{
	int		baselen;
	long	nbr;
	int		count;
	char	*res;

	count = 0;
	baselen = ft_strlen(base);
	nbr = nb;
	if (nbr < 0)
	{
		nbr = -nbr;
		count++;
	}
	while (nbr >= baselen)
	{
		count++;
		nbr = nbr / baselen;
	}
	count++;
	if (!(res = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		j;
	char	*i;

	if (exceptions(base_from) == 1 && exceptions(base_to) == 1)
	{
		j = ft_atoi_base(nbr, base_from);
		i = malloc_s(j, base_to);
		i = ft_putnbr_base(j, base_to, i);
		i = ft_rev_int_tab(i, ft_strlen(i));
		return (i);
	}
	return (NULL);
}
