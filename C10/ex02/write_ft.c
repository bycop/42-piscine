/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 08:52:36 by bycop          #+#    #+#             */
/*   Updated: 2020/10/26 09:31:59 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int     is_num(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	i -= 1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

void	default_op(int fd, int i, char **av, char c)
{
	int j;
	int count;

	j = 0;
	count = 0;
	fd = open(av[i], O_RDWR);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			j++;
	close(fd);
	fd = open(av[i], O_RDWR);
	while (read(fd, &c, 1) > 0)
	{
		if (count > j - 11)
			ft_putchar(c);
		if (c == '\n')
			count++;
	}
}

void	custom_op(int fd, int i, char **av, char c, int index)
{
	int j;
	int count;

	j = 0;
	count = 0;
	fd = open(av[i], O_RDWR);
	while (read(fd, &c, 1) > 0)
		j++;
	close(fd);
	fd = open(av[i], O_RDWR);
	while (read(fd, &c, 1) > 0)
	{
		if (count >= j - index)
			ft_putchar(c);
		count++;
	}
}
