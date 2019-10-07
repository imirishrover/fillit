#include "main.h"

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