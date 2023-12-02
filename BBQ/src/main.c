/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:13:19 by gkubina           #+#    #+#             */
/*   Updated: 2023/07/26 15:08:12 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	start(char *cont, t_map_def mapdef, t_fileinfo info)
{
	char		**map;
	t_max_point	maxpoint;

	map = alloc_map(mapdef);
	if (map == NULL)
	{	
		free_map(map, mapdef);
		return (-1);
	}
	setup_map(cont, map, mapdef, info);
	maxpoint = analyze(map, mapdef);
	if (maxpoint.max > -1)
		print_solution(map, maxpoint, mapdef);
	free_map(map, mapdef);
	return (0);
}

/* Acquire Information about file and the mapdefinition, and check coherence*/
int	bsq(char *filename)
{
	t_fileinfo	info;
	int			file;

	file = open(filename, O_RDONLY);
	if (file == -1)
		return (-1);
	info = fileinfo(filename);
	close (file);
	if (info.len_first < 4 || checkfile_and_go(filename, info) == -1)
	{
		return (-1);
	}
	return (0);
}

/* main checks the number of args and decides if stdin or files are treated. */
int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		if (catch_stdin() == -1)
		{
			ft_putstr("map error\n");
			return (0);
		}
		argv[0] = "tempfile";
		if (bsq(argv[0]) == -1)
			ft_putstr("map error\n");
	}
	while (i < argc)
	{
		if (i > 1)
			ft_putchar('\n');
		if (bsq(argv[i]) == -1)
			ft_putstr("map error\n");
		i++;
	}
	return (0);
}
