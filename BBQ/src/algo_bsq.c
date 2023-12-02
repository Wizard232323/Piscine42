/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:22:08 by gkubina           #+#    #+#             */
/*   Updated: 2023/07/26 14:39:58 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h" 

/*Helperfunction small compares 3 int values and returns the smalles*/
int	small(int a, int b, int c)
{
	if (a <= b && b <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	if (c <= a && c <= b)
		return (c);
	return (a);
}

/*Recovers the information to write in struct maxpoint*/
t_max_point	set_max_point(int size_x, int size_y, int max)
{
	t_max_point	maxpoint;

	maxpoint.max = max;
	maxpoint.x = size_x;
	maxpoint.y = size_y;
	return (maxpoint);
}

/*Returns the leftes and highest coordinates for the biggest square*/
t_max_point	analyze(char **map, t_map_def mapinfo)
{
	t_max_point	max;
	int			y;
	int			x;
	int			**a;

	y = mapinfo.height;
	a = alloc_a_table(mapinfo);
	max.max = -1;
	while (a != NULL && --y > -1)
	{
		x = mapinfo.wide;
		while (--x > -1)
		{
			if (map[x][y] == mapinfo.obs)
				a[x][y] = 0;
			else if (x == mapinfo.wide - 1 || y == mapinfo.height - 1)
				a[x][y] = 1;
			else
				a[x][y] = 1 + small(a[x + 1][y], a[x][y + 1], a[x + 1][y + 1]);
			if (max.max <= a[x][y])
				max = set_max_point(x, y, a[x][y]);
		}
	}
	free_analyse(a, mapinfo);
	return (max);
}

/*Prints the map to the screen integrating the biggest square */
void	print_solution(char **map, t_max_point max, t_map_def mapinfo)
{
	int	x;
	int	y;
	int	en_x;
	int	en_y;
	int	stop;

	stop = max.max * max.max;
	y = -1;
	en_x = max.x + max.max - 1;
	en_y = max.y + max.max - 1;
	while (++y < mapinfo.height)
	{
		x = -1;
		while (++x < mapinfo.wide)
		{
			if (x <= en_x && x >= max.x && y <= en_y && y >= max.y && stop > 0)
			{
				ft_putchar(mapinfo.full);
				stop--;
			}
			else
				ft_putchar(map[x][y]);
		}
		ft_putchar('\n');
	}
}
