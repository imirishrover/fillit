#ifndef MAIN_C
# define MAIN_C
# include "../libft/libft.h"
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
    char *table;
    char symbol;
}              t_tet;

typedef struct s_square
{
    char **table;
    size_t size;
}               t_square;

void del(void *c, size_t s);
char *get_array(char *buff);
t_list *save_file(char *filename);

void print_square(char **l);
t_square *ft_fill_square(t_list **lst);
int ft_solve_sq(t_square *square, t_list *lst);
void set_block(char **t, t_point *p, int i, char *tet, char s);
int put_figure(t_list *lst, t_square *square, t_point *start_point);
int	get_next_point(t_point **point, char **square);

t_square	*ft_create_sq(size_t size);
//static char	**make_square_str(size_t size);
t_point		*point_new(int x, int y);
t_point		*ft_create_p(int x, int y);
t_tet		*tetris_new(char *pos, char value);

int check_tetrims(const char *s, int size);
int check_connections(const char *s);
void	min_max(char *str, t_point *min, t_point *max);

void		free_tetris(t_tet *tetri);
t_list		*free_list_and_string(t_list *list, char **string);
void free_table(char **t, char c);
int input_checker(char *filename);
t_square *free_square(t_square *sq);
int	ft_memdel_c(void **ap);
# endif