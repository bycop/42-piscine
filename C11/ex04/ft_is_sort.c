/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:41:53 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/21 16:41:38 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort_cross(int *tab, int length, int (*f) (int, int))
{
	int i;

	i = -1;
	while (++i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
	}
	return (1);
}

int		ft_is_sort_desc(int *tab, int length, int (*f) (int, int))
{
	int i;

	i = -1;
	while (++i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			return (0);
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	if (((ft_is_sort_cross(tab, length, (*f)) == 1)
		|| (ft_is_sort_desc(tab, length, (*f)) == 1)))
		return (1);
	else
		return (0);
}
