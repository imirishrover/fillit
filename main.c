
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
	return (point);
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
** Эта функция проверяет может ли наш тетрим поместиться в сетку с текущим размером
** До конца еще не работает ДОДЕЛАТЬ
*/
int ft_solve_sq(t_square *square, t_point *start_point, t_list *lst)
{
	t_point *s = start_point;
	s = 0;
	char *l = lst->content;
	size_t i = 0;
	char **tbl = square->table;
	while(*l != '\0')
	{
		if(i >= (square->size * square->size) || !l[i] || !l[i + 1] || !tbl[l[i] - '0'][l[i+1] - '0'])
			break ;
		tbl[l[i] - '0'][l[i+1] - '0'] = '#';
		i+=2;
		l++;
	}
	if(i == 7)
		return (1);
	else
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
	ft_printtetris(square->table);
	free(square); //make a special function to free it right
	return (1);
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
			printf("%c lol\n", lol[i]);
		i++;
	}
}


int main(void)
{
	t_list *out = save_file("input");
	mm(out->content);
	ft_fill_square(&out);
}