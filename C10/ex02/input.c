/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:01:55 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/26 09:38:31 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	custom_while(char **av, int ac, char c, int i, int fd)
{
	while (++i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd < 0 && errno != 21)
		{
			ft_putstr(basename(av[0]));
			ft_putstr(": ");
			ft_putstr(av[i]);
			if (errno == 21)
				ft_putstr(": Is a directory\n");
			else
				ft_putstr(": No such file or directory\n");
		}
		else
		{
			if (ac > 4)
			{
				ft_putstr("==> ");
				ft_putstr(av[i]);
				ft_putstr(" <==\n");
			}
			custom_op(fd, i, av, c, ft_atoi(av[2]));
			if (av[i + 1])
				ft_putchar('\n');
		}
	}
}

void	default_while(char **av, int ac, char c, int i, int fd)
{
	while (++i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd < 0 && errno != 21)
		{
			ft_putstr(basename(av[0]));
			ft_putstr(": ");
			ft_putstr(av[i]);
			if (errno == 21)
				ft_putstr(": Is a directory\n");
			else
				ft_putstr(": No such file or directory\n");
		}
		else
		{
			if (ac > 2)
			{
				ft_putstr("==> ");
				ft_putstr(av[i]);
				ft_putstr(" <==\n");
			}
			default_op(fd, i, av, c);
			close(fd);
			if (av[i + 1])
				ft_putchar('\n');
		}
	}
}
