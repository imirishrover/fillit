/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:36:49 by admin             #+#    #+#             */
/*   Updated: 2019/10/18 20:59:17 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Clear table replacing all "c" symbols by "."
*/

void			free_table(char **t, char c)
{
	int i;
	int k;

	i = 0;
	while (t[i] != 0)
	{
		k = 0;
		while (t[i][k] != 0)
		{
			if (t[i][k] == c)
				t[i][k] = '.';
			k++;
		}
		i++;
	}
}

/*
**Free list
*/

t_list			*free_list_and_string(t_list *list, char **string, t_read *r)
{
	t_tet	*tetris;
	t_list	*next;

	while (list)
	{
		tetris = (t_tet *)list->content;
		next = list->next;
		free_tetris(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	if (string && r)
	{
		ft_strdel(string);
		free(r);
	}
	return (NULL);
}

/*
** Frees a tetrimino structure.
*/

void			free_tetris(t_tet *tetri)
{
	free(tetri->table);
	free(tetri);
}

t_square		*free_square(t_square *sq)
{
	int		i;
	char	**s;

	s = (char **)sq->table;
	i = 0;
	while (s[i] != '\0')
		free(s[i++]);
	free(s);
	free(sq);
	return (0);
}

int				ft_memdel_c(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
	return (1);
}
