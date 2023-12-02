/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:10:42 by event             #+#    #+#             */
/*   Updated: 2023/07/16 17:07:24 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	k;

	k = nb - 2;
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	while (k != 2)
	{
		if (k == 1)
			return (1);
		if (nb % k == 0)
			return (0);
		k = k - 2;
	}
	return (0);
}
/*
int	main(void)
{
	int	nb;

	nb = 22090;
	printf("%d\n", ft_is_prime(nb));
	return (0);
}*/
