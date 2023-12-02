/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:12:53 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/07/20 23:26:04 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>	

int	*ft_range(int min, int max)
{
	int	*z;
	int	i;
	int	len;

	if (max <= min)
		return (0);
	len = min;
	i = 0;
	z = malloc(((max - min)) * sizeof(int));
	if (z == NULL)
		return (0);
	while (i < (max - min))
	{
		z[i] = len;
		i++;
		len++;
	}
	return (z);
}
/*
int	main(void)
{
	int	a;
	int	b;
	int 	*c;
	int	i;
	
	i = 0;
	a = 2;
	b = 23;
	c = ft_range(a, b);

	while (c[i] != '\0')
	{	printf("mon tableau ; %d\n", c[i]);
		i++;
	}
	return (0);
}*/
