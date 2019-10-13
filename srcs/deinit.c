/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deinit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:36:49 by admin             #+#    #+#             */
/*   Updated: 2019/10/13 19:01:31 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Clear table replacing all "c" symbols by "."
*/
void free_table(char **t, char c)
{
	int i;
	int k;

	i = 0;
	while(t[i] != 0)
	{
		k = 0;
		while(t[i][k] != 0)
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
t_list		*free_list_and_string(t_list *list, char **string)
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
	ft_strdel(string);
	return (NULL);
}

/*
** Frees a tetrimino structure.
*/
void		free_tetris(t_tet *tetri)
{
	free(tetri->table);
	free(tetri);
}

t_square *free_square(t_square *sq)
{
	int i;

	i = 0;
	char **s = (char **)sq->table;
	while(s[i] != '\0')
		free(s[i++]);
	free(s);
	free(sq);
	return(0);
}