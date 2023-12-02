/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:27:15 by event             #+#    #+#             */
/*   Updated: 2023/07/13 18:33:56 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int	main(int argc, char *argv[])
{
	int i;

	i =0;
	(void) argc;
	
	while (argv[0][i] != '\0')
	{
		write(1, &argv[0][i], 1);
		i++;	
	}	

//  printf("Le nom du programme est : %s\n", argv[0]);
    return 0;
}
