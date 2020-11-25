/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                              :+:      :+:    :+:*/
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 08:37:04 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/21 14:54:10 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>

void	ft_putchar(char c)
{ 
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

int		main(int ac, char **av)
{
	char c;
	int fd;
	int i;

	i = 0;
	if (ac == 1)
	{
		while (read(0, &c, 1) > 0)
			ft_putchar(c);
	}
	while (++i < ac)
	{
		fd = open(av[i], O_RDWR);
		if (fd < 0)
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
			while (read(fd, &c, 1) > 0)
				ft_putchar(c);
		close(fd);
	}
	return 0;
}
