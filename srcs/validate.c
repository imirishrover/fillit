/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsance <nsance@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 19:45:24 by dnaruto           #+#    #+#             */
/*   Updated: 2019/10/18 21:28:15 by nsance           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*
** Checks whether it is valid tetrim size and form
*/

int			check_tetrims(const char *str, int size)
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

int			check_connections(const char *s)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (s[i])
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
		return (1);
	return (0);
}

/*
** Read file and check are there any wrong tetrims inside.
** Returns tetrims amount
*/

int			input_checker(char *filename)
{
	int		temp;
	int		i;
	int		r;
	int		fd;
	char	*buff;

	i = 0;
	buff = ft_strnew(21);
	ft_bzero(buff, ft_strlen(buff));
	fd = open(filename, O_RDONLY);
	ft_putendl("inputchecker");
	while ((r = read(fd, buff, 21)))
	{
		temp = r;
		if (r < 19 || !check_tetrims(buff, ft_strlen(buff)))
		{
			ft_strdel(&buff);
			return (0);
		}
		i++;
	}
	if (temp == 21)
		return (0);
	close(fd);
	ft_strdel(&buff);
	return (i);
}
