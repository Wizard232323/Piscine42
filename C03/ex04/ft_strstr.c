/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:41:51 by event             #+#    #+#             */
/*   Updated: 2023/07/12 23:53:54 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*to_find == 0)
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && to_find[j] != '\0'
			&& str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		j = 0;
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char s1[] = "vive l ecole 42";
	char s2[] = "";

	printf("%s\n", strstr(s1, s2));
	printf("%s\n", ft_strstr(s1, s2));
	return (0);
}*/
