/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:59:44 by event             #+#    #+#             */
/*   Updated: 2023/07/17 13:45:17 by ekoubbi          ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	while (ft_is_prime(nb) != 1)
	{
		nb = nb + 2;
	}	
	return (nb);
}
/*
int	main(void)
{
	int	nb;

	nb = 168;
	printf("%d\n", ft_find_next_prime(nb));
	return (0);
}*/
