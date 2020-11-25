/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:03:42 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/22 09:39:11 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char *charset, char c)
{
	int i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int		wordl(char *str, char *charset)
{
	int	count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && !is_charset(charset, str[i]))
		{
			count++;
			while (str[i] && !is_charset(charset, str[i]))
				i++;
		}
	}
	return (count);
}

char	*mallocw(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !is_charset(charset, str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !is_charset(charset, str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		j;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (wordl(str, charset) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_charset(charset, str[i]))
			i++;
		if (str[i] && !is_charset(charset, str[i]))
		{
			arr[j] = mallocw(&str[i], charset);
			j++;
		}
		while (str[i] && !is_charset(charset, str[i]))
			i++;
	}
	arr[j] = NULL;
	return (arr);
}
