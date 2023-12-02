/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:40:10 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/07/27 14:53:27 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

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

char	*ft_strdup(char *str)
{
	char	*str2;
	int		i;

	i = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str2 == NULL)
		return (0);
	while (str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*sxr;
	int			i;

	i = 0;
	sxr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (sxr == NULL)
		return (NULL);
	while (i < ac)
	{
		sxr[i].size = ft_strlen(av[i]);
		sxr[i].str = av[i];
		sxr[i].copy = ft_strdup(av[i]);
		i++;
	}
	sxr[i].str = 0;
	return (sxr);
}
