/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:13:16 by event             #+#    #+#             */
/*   Updated: 2023/07/15 23:38:29 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	return (nb = nb * ft_recursive_power(nb, power - 1));
}
/*
int	main(void)
{
	int     nb;
	int     power;

	nb = 12;
	power = 3;
	printf("%d\n", ft_recursive_power(nb, power));
	return (0);
}*/
