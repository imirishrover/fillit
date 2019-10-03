
#include "get_next_line.h"
#include "main.h"
/*
**Создает указатель на точку с которой мы должны работать. Используется как курсор в основном алгоритме. Идея честно скопипизжена из примера =)
*/
t_point		*ft_create_p(int len)
{
	t_point *point;

	if ((point = (t_point *)ft_memalloc(sizeof(*point))))
	{
		point->x = len % 5;
		point->y = ((len + 5) / 5);
		if (point->y > 0)
			point->y -= 1;
	}
	printf("start point created with parameters: x = %zu, y = %zu", point->x, point->y);
	return (point);
}

/*
**Просто печатает текущий квадрат на экран
*/
void draw_sq(char **sq)
{
	int i = 0;
	while (sq[i] != '\0')
		{
			ft_putstr(sq[i]);
			ft_putchar('\n');
			i++;
		}
	ft_putstr("End of the block\n");
}
/*
int		tetr_xshift(char **tetri)
{
	int shift;

	shift = 0;
	while (tetri[0][shift] == '.')
		shift++;
	return (shift);
}
*/

/*
** Функция которая смещает курсор на один символ
*/
int	get_next_point(t_point **point, char **square)
{
	if (!square)
		return (0);
	(*point)->x = (*point)->x + 1;
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

/*
** Эта функция проверяет может ли наш тетрим поместиться в сетку с текущим размером
** До конца еще не работает ДОДЕЛАТЬ
*/
int ft_solve_sq(t_square *square, t_point *start_point, t_list *lst)
{
	char *l = lst->content;
	size_t i = 0;
	char **tbl = square->table;
	draw_sq(square->table);
 	while(l[i] != '\0')
	{
		if(!l[i] || !l[i + 1] || (l[i] - '0') >= (int)square->size || (l[i + 1] - '0') >= (int)square->size)
			break ;
		tbl[l[i + 1] - '0' + start_point->y][l[i] - '0' + start_point->x] = '#';
		draw_sq(square->table);
		i+=2;
	}
	if(i < 8)
		return (0);
	if (!get_next_point(&start_point, tbl))
		return (1);
	if(i == 8)
	{
		lst = lst->next;
		ft_solve_sq(square, start_point, lst);
	}
	return(0);
}


/* 
t_tet *ft_create_tetrimo_struct(t_list *list)
{
	t_tet *out;
	out = 0;
	int i = 0;
	int j = 0;
	int flag = 0;
	//char **temp_arr = 0;

	out = (t_tet *)ft_memalloc(sizeof(out));
	out->table = list->content;
	printf("%s ", out->table);
	while((out->table)[i] != 0)
	{
		j= 0;
		while((out->table)[i][j] != '\0')
		{
			if (((out->table)[i][j] == '#') && (flag == 0))
			{
				out->start->y = i;
				out->start->x = j;
			}
			j++;
		}
		i++;
	}
	return(out);
}
*/

/*
** Создает "таблицу" в которую пытается вместить тетрим, 
**если он не помещается, то все стирает, увеличивает размерность сетки на 1 и повторяет процедуру"
*/

int ft_fill_square(t_list **lst)
{
	size_t size = 2;
	t_square *square;
	t_point *start_p;
	square = ft_create_sq(size);
	start_p = ft_create_p(0);
	//char *l = ft_strdup((*lst)->content);

	while(*lst && !ft_solve_sq(square, start_p, *lst))
	{
		size++;
		free(square); //make a special foo
		square = ft_create_sq(size);
		start_p->x = 0;
		start_p->y = 0;
	}
	printf("kkkkkkkkk");
	return(1);
}
/*
** Говнофункция для теста. Выводит значения координат с решеточками для тетрима
*/
void mm(char *lol)
{
	int i = 0;

	while (i < 8 && lol != '\0')
	{
		if (lol[i])
			printf("%c ", lol[i]);
		i++;
	}
}


int main(void)
{
	t_list *out = save_file("input");
	//mm(out->content);
	//printf("next");
	//mm(out->next->content);
	ft_fill_square(&out);
}