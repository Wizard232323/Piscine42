/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:04:27 by event             #+#    #+#             */
/*   Updated: 2023/07/09 23:09:38 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	alpha;
	int	i;

	alpha = 1;
	i = 0;
	if (str != 0)
	{
		while (str[i] != '\0')
		{
			if (str[i] < 'A' || str[i] > 'Z')
				alpha = 0;
			i++;
		}
	}		
	return (alpha);
}
