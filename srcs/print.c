#include "main.h"

void ft_printtetris(char **s)
{

	if (s)
	{
		while(s)
		{
			ft_putstr(*s);
			ft_putchar('\n');
			s++;
		}
	}
}