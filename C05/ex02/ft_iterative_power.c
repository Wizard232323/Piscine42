/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:47:34 by event             #+#    #+#             */
/*   Updated: 2023/07/16 17:05:09 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	a;

	a = nb;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (nb == 0)
		return (1);
	power = power - 1;
	while (power != 0)
	{
		nb = nb * a;
		--power;
	}
	return (nb);
}
/*
int	main(void)
{
	int	nb;
	int	power;

	nb = 12;
	power = 3;
	printf("%d\n", ft_iterative_power(nb, power));
	return (0);
}*/
