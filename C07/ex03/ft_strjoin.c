/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:42:36 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/07/27 14:29:29 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_ek(char *rep, char **strs, char *sep, int size);
int		ft_strlen(char *str);

char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[j + i] = s2[j];
		j++;
	}	
	s1[j + i] = 0;
	return (s2);
}

void	ft_ek2(int size, int *size2, char **strs, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		*size2 = *size2 + ft_strlen(strs[i]);
		if (i < size - 1)
			*size2 = *size2 + ft_strlen(sep);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		size2;
	char	*rep;

	size2 = 0;
	if (size == 0)
	{
		rep = malloc(1 * sizeof(char));
		if (rep == 0)
			return (0);
		*rep = '\0';
		return (rep);
	}
	ft_ek2(size, &size2, strs, sep);
	rep = (char *)malloc((size2 + 1) * sizeof(char));
	if (rep == 0)
		return (rep);
	ft_ek(rep, strs, sep, size);
	return (rep);
}

void	ft_ek(char *rep, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{	
		ft_strcat(rep, strs[i]);
		if (i < size - 1)
			ft_strcat(rep, sep);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	k;

	k = 0;
	while (str[k] != 0)
		k++;
	return (k);
}

int	main(int argc, char *argv[])
{
	char	*res;

	res = ft_strjoin(argc, argv, "_|_");
	printf("%s", res);
	return (0);
}

