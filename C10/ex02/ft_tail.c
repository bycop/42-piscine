/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 08:53:04 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/26 09:31:06 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		main(int ac, char **av)
{
	char c;
	int fd;
	int i;

	if (ac == 1)
	{
		while (read(0, &c, 1) > 0)
			;
	}
	if (ft_strcmp(av[1], "-c") == 0)
	{
		if (is_num(av[2]) == 0)
		{
			ft_putstr(basename(av[0]));
			ft_putstr(": illegal offset -- ");
			ft_putstr(av[2]);
			ft_putstr("\n");
			return (0);
		}
		i = 2;
		fd = 0;
		custom_while(av, ac, c, i, fd);
	}
	else
	{
		i = 0;
		fd = 0;
		default_while(av, ac, c, i, fd);
	}
	return (0);
}
