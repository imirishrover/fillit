
#include "main.h"
#include "read.h"
void		ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *alst;
	while (cur != NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*alst = prev;
}

void del(void *c, size_t s)
{
	if (!c)
		return ;
	free(c);
	s = 0;
	c = NULL;
}
t_get_arr *set_get_arr(void)
{
	t_get_arr *out = (t_get_arr *)ft_memalloc(sizeof(out));
	out->col_cnt = 0;
	out->row_cnt = 0;
	out->hor_shift = 0;
	out->ver_shift = 0;
	out->fl = 0;
	out->i = 0;
	return(out);
}
void set_sharp(t_get_arr *get, char *out)
{
	if(!get->fl)
				{
					get->fl = 1;
					get->hor_shift = get->col_cnt;
					get->ver_shift = get->row_cnt;
				}
	out[get->i++] = get->col_cnt - get->hor_shift + '0';
	out[get->i++] = get->row_cnt - get->ver_shift + '0';
}
/*
** создает строку(с интами не получается) в которой последовательно хранятся координаты всех решеток тетрима
** Причем все эти решетки смещены к левому верхнему углу, чтобы удалить лишние пустые ячейки
** Функцию ОПТИМИЗИРОВАТЬ
*/
char *get_array(char *buff)
{
	char *out;

	out = (char *)ft_memalloc(sizeof(char) * (8 + 1));
	t_get_arr *get = set_get_arr(); //freeeeeeeee
		while((*buff) != '\0')
		{
			get->col_cnt++;
			if (*buff == '\n')
				{
					get->row_cnt++;
					get->col_cnt = 0;
				}
			if (*buff == '#')
			{
				set_sharp(get, out);
			}
			buff++;
		}
		out[get->i] = '\0';
	return(out);
}


/*
** Читает из файла поток тетримов, если они валидны, то создает эл-ты списка, в которые пишет эти фигуры
** 100 процентов есть утечки. Функцию ОПТИМИЗИРОВАТЬ
*/
t_list *save_file(char *filename)
{
	char *buff = ft_strnew(21);
	t_list *new = 0;
	t_tet *tetris = 0;

	int r = 0;
	
	ft_bzero(buff, strlen(buff));
	int fd = 0;
	char letter = 'A';
	fd = open(filename, O_RDONLY);
	while((r = read(fd, buff, 21)) >= 19)
	{
		if(!check_tetrims(buff) || !check_connections(buff) || !(tetris = tetris_new(get_array(buff), letter++)))
		{	
			ft_memdel((void **)&buff);
			//return (free_list(list));    реализовать функцию и заменить!
			return(0);
		}
		buff[20] = '\0';
		ft_lstadd(&new, ft_lstnew(tetris, sizeof(t_tet)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&tetris);
	close(fd);
	ft_lstrev(&new);
	return(new);
}