/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 09:03:06 by bycop          #+#    #+#             */
/*   Updated: 2020/10/21 16:22:38 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f) (int))
{
	int i;
	int	*tabres;

	if (length < 1 || (!(tabres = malloc(sizeof(int) * length))))
		return (NULL);
	i = -1;
	while (++i < length)
		tabres[i] = (*f)(tab[i]);
	return (tabres);
}
