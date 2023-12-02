/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 00:07:37 by event             #+#    #+#             */
/*   Updated: 2023/07/12 16:02:50 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = 0;
	while (dest[destlen] != '\0')
		destlen++;
	while (src[i] != '\0')
	{	
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = 0;
	return (dest);
}
/*int main(void)
 {
         char s1[] = "abcdefgh";
         char s2[] = "zzzzzzzz";
 
         printf("%s\n", ft_strcat(s1, s2));
         return (0);
 }
*/
