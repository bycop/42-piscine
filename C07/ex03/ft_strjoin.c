/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 22:29:07 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/19 14:15:07 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		countw(char **strs, int size, int sepl)
{
	int count;

	count = 0;
	while (size--)
		count += ft_strlen(strs[size]) + sepl;
	return (count);
}

char	*check(int size, char *str, int j)
{
	if (size != 0)
		str[j] = '\0';
	if (size == 0)
		if (!(str = malloc(sizeof(str) * 1)))
			return (NULL);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	char	*str;

	j = (size == 0) ? 1 : countw(strs, size, ft_strlen(sep)) - ft_strlen(sep);
	if (!(str = malloc(sizeof(*str) * j)))
		return (NULL);
	i = -1;
	k = -1;
	while (++i < size)
	{
		tmp = strs[i];
		while (tmp++[0])
			str[++k] = tmp[-1];
		if (i != size - 1)
		{
			tmp = &sep[0];
			while (tmp++[0])
				str[++k] = tmp[-1];
		}
	}
	return (check(size, str, j));
}
