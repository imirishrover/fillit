#include "main.h"

int put_figure(t_list *lst, t_square *square, t_point *start_point)
{
	size_t i = 0;
	char **tbl = square->table;
	t_tet *content = (t_tet*)lst->content;
	char *l = content->table;
	while(l[i] != '\0')
	{
		if(!l[i] || !l[i + 1] || (int)(l[i] - '0' + start_point->x) >= (int)square->size ||
		(int)(l[i + 1] - '0' + start_point->y) >= (int)square->size
		|| tbl[l[i + 1] - '0' + start_point->y][l[i] - '0' + start_point->x] != '.')
					return(0);
		i+=2;
	}
	i = 0;
	while(l[i] != '\0')
	{
		set_block(tbl, start_point, i, l, content->symbol);
		i+=2;
	}
	if(i < 8)
		return (0);
	if(i == 8)
		return(1);
return(-1);
}

void set_block(char **t, t_point *p, int i, char *tet, char s)
{
	t[tet[i + 1] - '0' + p->y][tet[i] - '0' + p->x] = s;
}

int ft_solve_sq(t_square *square, t_list *lst)
{
	t_point *s_p;
	t_tet *piece;

	if(lst == NULL)
		return(1);
	piece = (t_tet *)lst->content;
	s_p = ft_create_p(0, 0);
 	while (s_p->y < square->size) 
	 {
		 s_p->x = 0;
		 while(s_p->x < square->size)
		 {
			 if (put_figure(lst, square, s_p))
			 {
				 if (ft_solve_sq(square, lst->next))
				 	return (1);
				else
					set_block(square->table, ft_create_p(s_p->x, s_p->y), 0, piece->table, '.');
			 }
			 s_p->x++;
		 }
		s_p->y++;
	 }
	return(0);
}

t_square *ft_fill_square(t_list **lst)
{
	size_t size = 2;
	t_square *square;
	square = ft_create_sq(size);
	while(!ft_solve_sq(square, *lst))
	{
		size++;
		free(square); //make a special foo
		square = ft_create_sq(size);
	}
	return(square);
}