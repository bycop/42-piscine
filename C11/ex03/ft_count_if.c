/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 09:36:08 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/21 16:23:45 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int length, int (*f) (char*))
{
	int i;
	int count;

	count = 0;
	i = -1;
	while (++i < length)
	{
		if ((*f)(tab[i]) != 0)
			count++;
	}
	return (count);
}
