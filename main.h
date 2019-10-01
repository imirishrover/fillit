#ifndef MAIN_C
# define MAIN_C
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_point
{
    size_t x;
    size_t y;
}              t_point;

typedef struct s_tet
{
    char **table;
    size_t h;
    size_t w;
    char symbol;
}              t_tet;

typedef struct s_square
{
    char **table;
    size_t size;
}               t_square;


int check_connections(char *s);
int check_tetrims(char *s);
void		ft_lstrev(t_list **alst);
t_list *save_file(char *filename);
void del(void *c, size_t s);
void ft_printtetris(char **tet);
t_square	*ft_create_sq(size_t size);
# endif