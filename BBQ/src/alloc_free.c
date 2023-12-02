/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:22:08 by gkubina           #+#    #+#             */
/*   Updated: 2023/07/24 14:21:15 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h" 

int	**alloc_a_table(t_map_def info)
{
	int	i;
	int	**analyse;

	i = -1;
	analyse = malloc (info.wide * sizeof (int *));
	if (analyse == NULL)
		return (NULL);
	while (++i < info.wide)
	{
		analyse[i] = malloc(info.height * sizeof (int));
		if (analyse[i] == NULL)
		{
			while (--i > -1)
				free(analyse[i]);
			return (NULL);
		}
	}
	return (analyse);
}

void	free_analyse(int **analyse, t_map_def info)
{
	int	i;

	i = -1;
	while (++i < info.wide)
		free (analyse[i]);
	free(analyse);
}

char	**alloc_map(t_map_def info)
{
	char	**map;
	int		i;

	i = -1;
	map = malloc (info.wide * sizeof (char *));
	if (map == NULL)
		return (NULL);
	while (++i < info.wide)
	{
		map[i] = malloc(info.height * sizeof (char));
		if (map[i] == NULL)
		{
			while (--i > -1)
				free(map[i]);
			return (NULL);
		}
	}
	return (map);
}

void	free_map(char **map, t_map_def info)
{
	int	i;

	i = -1;
	while (++i < info.wide)
		free (map[i]);
	free(map);
}
