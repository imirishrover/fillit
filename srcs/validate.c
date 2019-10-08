#include "main.h"

/*
**Проверяет что перед нами табличка валидной формы с валидными симвоалми внутри. Требуется для проверки тетрима
*/
/*int check_tetrims(char *s)
{
	int cnt_hashtag;
	int cnt_void;
	int cnt_n;
	int i;


	cnt_hashtag = 0;
	cnt_void = 0;
	cnt_n = 0;
	i = 0;
	while(s[i])
	{
		if (s[i] == '#')
			cnt_hashtag++;
		if (s[i] == '.')
			cnt_void++;
		i++;
	}
	printf("hashtagd: %d, dots: %d, ns: %d\n", cnt_hashtag, cnt_void, cnt_n);
	if ((cnt_void + cnt_hashtag == 16) && (cnt_hashtag == 4) && (s[19] == '\n'))
		return(1);
	
	return(0);
}*/
int		check_tetrims(const char *str, int size)
{
	int		i;
	int		hex;

	i = -1;
	hex = 0;
	while (++i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] == '#')
				hex++;
			else if (str[i] != '.')
				return (0);
		}
		else if (str[i] != '\n')
			return (0);
	}
	if (size == 21 && str[20] != '\n')
		return (0);
	if (hex != 4 || !check_connections(str))
		return (0);
	return (1);
}


/*
** Проверяет правильность поступившего на вход тетрима
*/
int check_connections(const char *s)
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