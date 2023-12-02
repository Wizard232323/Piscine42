/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   an_firstline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:08:29 by gkubina           #+#    #+#             */
/*   Updated: 2023/07/26 10:53:12 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < size)
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	if (i != size)
	{
		return (0);
	}
	return (res);
}

t_map_def	analyse_firstline(char *str, int wide, int size)
{
	int			i;
	t_map_def	result;

	i = -1;
	result.empty = 'i';
	result.obs = '.';
	result.full = 'x';
	result.wide = wide;
	while (++i < size)
	{
		if (size < 4 || str[i] <= 31 || str[i] == 127)
		{
			result.height = -1;
			return (result);
		}
	}
	result.empty = str[size - 3];
	result.obs = str[size - 2];
	result.full = str[size - 1];
	result.height = ft_atoi(str, (size - 3));
	return (result);
}
