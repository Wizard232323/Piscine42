/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekoubbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:23:22 by ekoubbi           #+#    #+#             */
/*   Updated: 2023/07/18 16:25:30 by ekoubbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*z;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	z = malloc(((max - min)) * sizeof(int));
	if (z == NULL)
		return (-1);
	while (min < max)
	{
		z[i] = min;
		i++;
		min++;
	}
	*range = z;
	return (i);
}
/*
#include <stdio.h>

int    main(int argc, char *argv[])
{
    int    min;
    int    max;
    int    *tab;
    int    range;
    int    i;

    if (2 < argc)
    {
        min = atoi(argv[1]);
        max = atoi(argv[2]);
        range = ft_ultimate_range(&tab, min, max);
        printf("range = %d\n", range);
        if (tab && 0 < range)
        {
            i = 0;
            while (i < range)
            {
                printf("%d", tab[i++]);
                if (i < range)
                    printf(", ");
            }
            printf("\n");
        }
        else
            printf("NULL\n");
    }
    else
        printf("required 'min' 'max'\n");
    return (0);
}
*/
