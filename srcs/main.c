/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:56:03 by dnaruto           #+#    #+#             */
/*   Updated: 2019/10/15 21:29:23 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** print sudoku square
*/

void	print_square(char **l)
{
	int i;

	i = 0;
	while (l[i] != 0)
	{
		ft_putstr(l[i]);
		ft_putchar('\n');
		i++;
	}
}
int		main(int argc, char **argv)
{
	t_list *out;
	t_square *k;

	out = 0;
	k = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [input_file]");
		return (0);
	}
	if (!(out = save_file(argv[1])))
	{
		ft_putendl("error");
		return (0);
	}
	k = (t_square *)ft_fill_square(&out);
	print_square(k->table);
}
