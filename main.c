#include "main.h"

/*
**Shifts the start pointer on the 1 pos
*/
/*
void shifted(t_point **point)
{
	(*point)->x = (*point)->x + 1;
}
*/


/*
** Функция которая смещает курсор на один символ
*/
/*
int	get_next_point(t_point **point, char **square)
{
	if (!square)
		return (0);
	//(*point)->x = (*point)->x + 1;
	while (square[(*point)->y] != NULL)
	{
		while (square[(*point)->y][(*point)->x] != '\0')
		{
			if (square[(*point)->y][(*point)->x] == '.')
				return (1);
			(*point)->x = (*point)->x + 1;
		}
		(*point)->y = (*point)->y + 1;
		(*point)->x = 0;
	}
	return (0);
}
*/
/*
** Fit sudoku figure to the square
*/

void print_square(char **l)
{
	int i = 0;

	while (l[i] != 0)
	{
		ft_putstr(l[i]);
		ft_putchar('\n');
		i++;
	}
}
int main(int argc, char **argv)
{
	if (argc != 2)
		return(0);
	t_list *out = save_file(argv[1]);
	t_square *k = (t_square *)ft_fill_square(&out);
	print_square(k->table);
}