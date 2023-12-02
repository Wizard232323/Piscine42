/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:13:19 by gkubina           #+#    #+#             */
/*   Updated: 2023/07/25 18:53:08 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

/* all necessary tests on the string containing the file to see if it is valid*/
int	check_conditions(char *cont, t_map_def mapdef, t_fileinfo info)
{
	if (ch_mapsize(mapdef) == 0
		&& ch_mapdef(mapdef, info) == 0
		&& ch_linelength(cont, info) == 0
		&& ch_linecount(cont, mapdef, info) == 0
		&& ch_char_check(cont, mapdef, info) == 0)
		return (0);
	else
		return (-1);
}

/* Allocate memory for cont put file inside, check it and start solution */
int	checkfile_and_go(char *filename, t_fileinfo info)
{
	char		*cont;
	t_map_def	mapdef;

	cont = (char *) malloc ((info.len + 1) * sizeof (char));
	if (!(cont == NULL))
	{
		cont = readfile(filename, info, cont);
		if (!(cont == NULL))
		{
			mapdef = analyse_firstline(cont,
					info.len_sec - 1, info.len_first - 1);
			if (check_conditions(cont, mapdef, info) == 0
				&& mapdef.height != -1 && start(cont, mapdef, info) == 0)
			{
				free (cont);
				return (0);
			}
		}
	}
	free(cont);
	return (-1);
}

/* write the file from line 2 onwards in the 2d array 'map' provided*/
void	setup_map(char *cont, char **map, t_map_def mapdef, t_fileinfo info)
{
	int	x;
	int	y;
	int	i;

	i = info.len_first;
	y = -1;
	while (++y < mapdef.height)
	{
		x = -1;
		while (++x < mapdef.wide)
		{
			if (cont[i] != '\n')
				map[x][y] = cont[i];
			else
				x--;
			i++;
		}
	}
}
