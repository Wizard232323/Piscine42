/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:23:53 by event             #+#    #+#             */
/*   Updated: 2023/07/16 01:09:33 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	k;

	k = 1;
	if (nb > 2147395600)
		return (0);
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	while ((k * k) <= nb)
	{
		if ((k * k) == nb)
			return (k);
		k++;
	}
	return (0);
}
/*

int	main(void)
{
	int	nb;

	nb = 1764;
	printf("%d\n", ft_sqrt(nb));
	return (0);
}*/
