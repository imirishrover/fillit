
#include "get_next_line.h"

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

int check_tetrims(char *s)
{
	int cnt;


	cnt = 0;
	while(s)
	{
		if (*s == '.' || *s == '#')
		{
			cnt++;
		}
		s++;
	}
	return(cnt);
}

void del(void *c, size_t s)
{
	if (!c)
		return ;
	free(c);
	s = 0;
	c = NULL;
}

t_list *save_file(char *filename)
{

	t_list *new = 0;
	t_list *temp = 0;
	int r = 0;
	char *buff = ft_strnew(21);
	ft_bzero(buff, strlen(buff));
	//char *line = 0;
	int fd = 0;
	fd = open(filename, O_RDONLY);
	while((r = read(fd, buff, 21)) >= 20)
	{

		temp = ft_lstnew(buff, 21);
		//printf("%s ", temp->content);
		ft_lstadd(&new, temp);
	}
	close(fd);
	return(new);
}



int main(void)
{
	printf("adsasd\n");
	//t_list *out = save_file("input");
	//int a = check_tetrims(out->content);
	//printf("%s %s", out->content, out->next->content);
	//printf("k");

}