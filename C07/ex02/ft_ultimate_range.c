/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 09:50:15 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/15 16:09:26 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	else
	{
		if (!(*range = malloc(sizeof(int) * (max - min))))
			return (-1);
		i = -1;
		while (min + (++i) < max)
			(*range)[i] = min + i;
		return (i);
	}
}
