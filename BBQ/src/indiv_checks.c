/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indiv_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:13:19 by gkubina           #+#    #+#             */
/*   Updated: 2023/07/25 18:59:59 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ch_mapsize(t_map_def mapdef)
{
	if (mapdef.wide >= 1 && mapdef.height >= 1)
	{
		return (0);
	}
	return (-1);
}

int	ch_mapdef(t_map_def mapdef, t_fileinfo info)
{
	if (info.line - 1 == mapdef.height
		&& info.len_sec - 1 == mapdef.wide
		&& !(mapdef.empty == mapdef.full)
		&& !(mapdef.obs == mapdef.full)
		&& !(mapdef.empty == mapdef.obs))
	{
		return (0);
	}
	return (-1);
}

int	ch_linelength(char *cont, t_fileinfo info)
{
	int	i;

	i = info.len_first;
	while (i < info.len)
	{
		if (cont[i] == '\n' && (i - info.len_first + 1) % (info.len_sec) != 0)
		{
			return (-1);
		}
		i = i + 1;
	}
	return (0);
}

int	ch_linecount(char *cont, t_map_def mapdef, t_fileinfo info)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < info.len)
	{
		if (cont[i] == '\n')
			n = n + 1;
		i++;
	}
	if (n != mapdef.height + 1)
	{
		return (-1);
	}
	return (0);
}

int	ch_char_check(char *cont, t_map_def mapdef, t_fileinfo info)
{
	int	i;

	i = info.len_first ;
	while (i < info.len)
	{
		if (!(cont[i] == '\n'
				|| cont[i] == mapdef.empty
				|| cont[i] == mapdef.obs))
		{
			return (-1);
		}
		i = i + 1;
	}
	return (0);
}
