/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 19:15:29 by nsance            #+#    #+#             */
/*   Updated: 2019/10/18 21:20:29 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_point
{
	size_t x;
	size_t y;
}				t_point;

typedef struct	s_tet
{
	char *table;
	char symbol;
}				t_tet;

typedef struct	s_square
{
	char	**table;
	size_t	size;
}				t_square;

typedef struct	s_read
{
	int		fd;
	int		r;
	char	l;
}				t_read;

typedef struct	s_get_arr
{
	int		row_cnt;
	int		col_cnt;
	int		hor_shift;
	int		ver_shift;
	int		fl;
	int		i;
}				t_get_arr;

int				put_figure(t_list *ls, t_square *sq, t_point *st);
int				ft_lstcnt(t_list *lst);
t_square		*ft_fill_square(t_list **lst);
char			*get_array(char *buff);
t_list			*save_file(char *filename);
void			print_square(char **l);
int				ft_solve_sq(t_square *square, t_list *lst);
t_square		*ft_create_sq(size_t size);
t_point			*ft_create_p(int x, int y);
t_tet			*tetris_new(char *pos, char value);
int				check_tetrims(const char *s, int size);
int				check_connections(const char *s);
void			free_tetris(t_tet *tetri);
t_list			*free_list_and_string(t_list *list, char **string, t_read *r);
void			free_table(char **t, char c);
t_square		*free_square(t_square *sq);
int				input_checker(char *filename);
int				ft_memdel_c(void **ap);
t_read			*new_read(void);
#endif
