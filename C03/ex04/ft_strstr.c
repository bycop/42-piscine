/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfournio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:26:32 by sfournio          #+#    #+#             */
/*   Updated: 2020/10/11 09:52:57 by sfournio         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
		j = 0;
	}
	return (0);
}
#include <stdio.h>
#include <string.h>

int main() {

    char login[40] = "set";
    char password[40] = "les chaussetes del archiduchesse dont elels sechent acrchisseenth";

    printf("%s\n", strstr(password, login));
	printf("%s\n", ft_strstr(password, login));

    return 0;
}

