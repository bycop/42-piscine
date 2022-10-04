/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:23:19 by bycop          #+#    #+#             */
/*   Updated: 2020/10/21 16:31:11 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "put.h"

int		ft_atoi(char *str)
{
	int i;
	int neg;
	int res;

	res = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * neg);
}

int		calc(int nb1, int nb2, char op)
{
	if (op == '+')
		ft_put(nb1 + nb2, 2);
	else if (op == '-')
		ft_put(nb1 - nb2, 2);
	else if (op == '/')
	{
		if (nb2 == 0)
			return (-1);
		ft_put(nb1 / nb2, 2);
	}
	else if (op == '%')
	{
		if (nb2 == 0)
			return (-2);
		ft_put(nb1 % nb2, 2);
	}
	else if (op == '*')
	{
		ft_put(nb1 * nb2, 2);
	}
	else
		return (0);
	return (1);
}

int		check_err(int ac, char **av)
{
	if (ac != 4)
		return (0);
	if (av[2][1])
		return (2);
	return (1);
}

int		main(int ac, char **av)
{
	int		nb1;
	int		nb2;
	char	op;
	int		res;

	if (check_err(ac, av) == 2)
	{
		ft_put(0, 0);
		return (0);
	}
	else if (check_err(ac, av) == 0)
		return (0);
	nb1 = ft_atoi(av[1]);
	nb2 = ft_atoi(av[3]);
	op = av[2][0];
	res = calc(nb1, nb2, op);
	if (res == -1)
		write(1, "Stop : division by zero\n", 24);
	if (res == -2)
		write(1, "Stop : modulo by zero\n", 22);
	if (res == 0)
		ft_put(0, 0);
	return (0);
}
