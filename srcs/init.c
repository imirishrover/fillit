/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:23:36 by admin             #+#    #+#             */
/*   Updated: 2019/10/18 21:30:03 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Создает новую структуру которая хранит в себе элемент тетриса.
*/

t_tet			*tetris_new(char *pos, char value)
{
	t_tet	*tetris;

	tetris = ft_memalloc(sizeof(t_tet));
	tetris->table = pos;
	tetris->symbol = value;
	if(tetris)
		ft_putendl("tetrisnew");
	return (tetris);
}

/*
**Создает указатель на точку с которой мы должны работать.
**Используется как курсор в основном алгоритме.
*/

t_point			*ft_create_p(int x, int y)
{
	t_point	*point;

	if ((point = (t_point *)ft_memalloc(sizeof(*point))))
	{
		point->x = x;
		point->y = y;
	}
	return (point);
}

/*
** Создает табличку заполненную точками
*/

static char		**make_square_str(size_t size)
{
	char	**square;
	size_t	i;

	if ((square = (char **)ft_memalloc((sizeof(*square) * (size + 1)))))
	{
		i = 0;
		while (i < size)
		{
			if (!(square[i] = ft_strnew(size)))
			{
				while (--i)
					ft_strdel(&square[i]);
				free(square);
				return (NULL);
			}
			ft_memset(square[i++], '.', size);
		}
	}
	return (square);
}

/*
** Инициализирует нашу главную табличку, куда все и вмещается
*/

t_square		*ft_create_sq(size_t size)
{
	t_square *square;

	if ((square = (t_square *)ft_memalloc(sizeof(*square))))
	{
		if (!(square->table = make_square_str(size)))
		{
			free(square);
			return (NULL);
		}
		square->size = size;
	}
	return (square);
}

t_read			*new_read(void)
{
	t_read	*re;

	re = 0;
	if ((re = (t_read *)ft_memalloc(sizeof(*re))))
	{
		re->r = 0;
		re->l = 'A';
		re->fd = 0;
		return (re);
	}
	else
		return (0);
}
