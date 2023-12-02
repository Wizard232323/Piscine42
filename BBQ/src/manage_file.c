/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:13:19 by gkubina           #+#    #+#             */
/*   Updated: 2023/07/26 15:10:06 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_fileinfo	init_fileinfo(t_fileinfo info)
{
	info.len = 0;
	info.line = 0;
	info.len_first = 0;
	info.len_sec = 0;
	return (info);
}

t_fileinfo	fileinfo(char *filename)
{
	t_fileinfo	info;
	char		c;
	int			file;
	int			i;

	info = init_fileinfo(info);
	i = 0;
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (info);
	while (read(file, &c, 1) > 0)
	{
		info.len++;
		i++;
		if (c == '\n')
			info.line++;
		if (c == '\n' && info.line == 1)
			info.len_first = i;
		if (c == '\n' && info.line == 2)
			info.len_sec = i - info.len_first;
	}
	close (file);
	return (info);
}

/* Readfile returns contents of the file in a previously allocated charchain*/
char	*readfile(char *filename, t_fileinfo info, char *str)
{
	int		i;
	char	c;
	int		file;

	i = 0;
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (NULL);
	while (i < info.len && read(file, &c, 1) > 0)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	close (file);
	return (str);
}

/* reads from stdin and writes in new created or overwr existing file tempfile*/
int	catch_stdin(void)
{
	int		file;
	char	c;

	file = open("tempfile", O_CREAT | O_RDWR | O_TRUNC, S_IWUSR | S_IRUSR);
	if (file == -1)
		return (-1);
	while (read(0, &c, 1) > 0)
	{
		write(file, &c, 1);
	}
	close(file);
	return (0);
}
