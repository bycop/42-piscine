/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bycop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:38:57 by bycop          #+#    #+#             */
/*   Updated: 2020/10/08 11:02:39 by bycop         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_pair(int size)
{
	int pair;

	if (size % 2 == 1)
		pair = (size - 1) / 2;
	else
		pair = size / 2;
	return (pair);
}

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int tmp;
	int pair;

	i = 0;
	pair = ft_pair(size);
	size--;
	while (i < pair)
	{
		tmp = tab[i];
		tab[i] = tab[size - i];
		tab[size - i] = tmp;
		i++;
	}
}
