
#include "main.h"


/*
** Создает новую структуру которая хранит в себе элемент тетриса. На данный момент используется частично. Возможны изменения
*/
t_tet		*tetris_new(char **pos, int width, int height, char value)
{
	t_tet	*tetris;

	tetris = ft_memalloc(sizeof(t_tet));
	tetris->table = pos;
	tetris->w = width;
	tetris->h = height;
	tetris->symbol = value;
	return (tetris);
}
/*
**Проверяет что перед нами табличка валидной формы с валидными симвоалми внутри. Требуется для проверки тетрима
*/
int check_tetrims(char *s)
{
	int cnt_hashtag;
	int cnt_void;
	int i;


	cnt_hashtag = 0;
	cnt_void = 0;
	i = 0;
	while(s[i])
	{
		if (s[i] == '#')
			cnt_hashtag++;
		else if (s[i] == '.')
			cnt_void++;
		i++;
	}
	if ((cnt_void + cnt_hashtag == 16) && (cnt_hashtag == 4))
		return(1);
	return(0);
}
/*
** Проверяет правильность поступившего на вход тетрима
*/
int check_connections(char *s)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while(s[i])
	{
		if (s[i] == '#')
		{
				if (s[i + 1] && s[i + 1] == '#')
					cnt++;
				if (s[i - 1] && s[i - 1] == '#')
					cnt++;
				if (s[i + 5] && s[i + 5] == '#')
					cnt++;
				if (s[i - 5] && s[i - 5] == '#')
					cnt++;
		}
		i++;
	}
	if (cnt >= 6)
		return(1);
	return(0);
}

void del(void *c, size_t s)
{
	if (!c)
		return ;
	free(c);
	s = 0;
	c = NULL;
}
/*
** Ищет начало и конец фигуры. Сейчас не используется. Возможно удалю
*/
void	min_max(char *str, t_point *min, t_point *max)
{
	size_t i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}
/*
** Инициализирует новый указатель
*/
t_point		*point_new(int x, int y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}
/*
** создает строку(с интами не получается) в которой последовательно хранятся координаты всех решеток тетрима
** Причем все эти решетки смещены к левому верхнему углу, чтобы удалить лишние пустые ячейки
** Функцию ОПТИМИЗИРОВАТЬ
*/
char *get_array(char *buff)
{
	int row_cnt;
	int col_cnt;
	int hor_shift;
	int ver_shift;
	int fl;
	char *out;
	int i;

	out = (char *)ft_memalloc(sizeof(char) * (8 + 1));
	row_cnt = 0;
	col_cnt = 0;
	hor_shift = 0;
	ver_shift = 0;
	fl = 0;
	i = 0;
	if (!buff)
		return(0);
	else
	{
		while((*buff) != '\0')
		{
			col_cnt++;
			if (*buff == '\n')
				{
					row_cnt++;
					col_cnt = 0;
				}
			if (*buff == '#')
			{
				if(!fl)
				{
					fl = 1;
					hor_shift = col_cnt;
					ver_shift = row_cnt;
				}
				out[i] = col_cnt - hor_shift + '0';
				i++;
				printf("out val(x) %d is %d\n", i - 1, out[i - 1]);
				out[i] = row_cnt - ver_shift + '0';
				i++;
				printf("out val(y) %d is %d\n", i - 1, out[i - 1]);
			}
			buff++;
		}
		out[i] = '\0';
	}
	return(out);
}


/*
** Читает из файла поток тетримов, если они валидны, то создает эл-ты списка, в которые пишет эти фигуры
** 100 процентов есть утечки. Функцию ОПТИМИЗИРОВАТЬ
*/
t_list *save_file(char *filename)
{

	t_list *new = 0;
	t_list *temp = 0;
	t_tet *tetris = 0;
	int r = 0;
	char *buff = ft_strnew(21);
	ft_bzero(buff, strlen(buff));
	//int *buff_data = 0;
	int fd = 0;
	//int *lol = (int *)ft_memalloc(sizeof(int) * 8);
	//char letter = 'A';
	fd = open(filename, O_RDONLY);
	while((r = read(fd, buff, 21)) >= 19)
	{
		if(!check_tetrims(buff) || !check_connections(buff))
		{	
			printf("non valid tetris\n");
			return(0);
		}
		buff[20] = '\0';
		temp = ft_lstnew(tetris, sizeof(tetris));
		//ft_memcpy(buff_data, get_array(buff), 8);
		temp->content = ft_strdup(get_array(buff));
		temp->content_size = ft_strlen(temp->content);
		ft_lstadd(&new, temp);
	}
	ft_memdel((void **)&tetris);
	close(fd);
	printf("Tetris block succefully added to list\n");
	return(new);
}