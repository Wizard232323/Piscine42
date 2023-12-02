/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:22:08 by gkubina           #+#    #+#             */
/*   Updated: 2023/07/26 14:34:01 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_max_point
{
	int	x;
	int	y;
	int	max;
}	t_max_point;

typedef struct s_map_def
{
	char	empty;
	char	obs;
	char	full;
	int		wide;
	int		height;
}	t_map_def;

typedef struct s_fileinfo
{
	int	len;
	int	line;
	int	len_first;
	int	len_sec;
}	t_fileinfo;

/* algo.bsq.c */
int			small(int a, int b, int c);
t_max_point	set_max_point(int size_x, int size_y, int max);
t_max_point	analyze(char **map, t_map_def mapinfo);
void		print_solution(char **map, t_max_point max, t_map_def info);

/* alloc_free.c */
int			**alloc_a_table(t_map_def info);
void		free_analyse(int **analyse, t_map_def info);
char		**alloc_map(t_map_def info);
void		free_map(char **map, t_map_def info);

/* filecheck.c */
int			check_conditions(char *cont, t_map_def mapdef, t_fileinfo info);
int			checkfile_and_go(char *filename, t_fileinfo info);
void		setup_map(char *cont, char **map, t_map_def mapdef,
				t_fileinfo info);

/* indiv_checks.c */
int			ch_mapsize(t_map_def mapdef);
int			ch_mapdef(t_map_def mapdef, t_fileinfo info);
int			ch_linelength(char *cont, t_fileinfo info);
int			ch_linecount(char *cont, t_map_def mapdef, t_fileinfo info);
int			ch_char_check(char *cont, t_map_def mapdef, t_fileinfo info);

/* main .c*/
int			start(char *cont, t_map_def mapdef, t_fileinfo info);
int			bsq(char *filename);

/* manage_file.c*/
t_fileinfo	fileinfo(char *filename);
char		*readfile(char *filename, t_fileinfo info, char *str);
int			catch_stdin(void);
t_fileinfo	init_fileinfo(t_fileinfo info);

/* helpers.c */
void		ft_putchar(char c);
void		ft_putstr(char *str);

/* an_firstline.c */
int			ft_strlen(char *str);
int			ft_atoi(char *str, int size);
t_map_def	analyse_firstline(char *str, int wide, int size);

#endif
