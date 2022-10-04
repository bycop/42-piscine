/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 09:04:09 by bycop          #+#    #+#             */
/*   Updated: 2020/10/15 16:07:56 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *tab;

	if (min >= max)
		return (NULL);
	else
	{
		tab = malloc(sizeof(int) * (max - min));
		i = -1;
		while (min + (++i) < max)
			tab[i] = min + i;
		return (tab);
	}
}
