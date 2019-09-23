
#include "get_next_line.h"
#include "main.h"

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
	if (cnt == 6)
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
	while((r = read(fd, buff, 21)) >= 19)
	{
		if(!check_tetrims(buff) || !check_connections(buff))
			return(0);
		temp = ft_lstnew(buff, 21);
		//printf("%s ", temp->content);
		ft_lstadd(&new, temp);
	}
	close(fd);
	return(new);
}



int main(void)
{
	//printf("adsasd\n");
	t_list *out = save_file("input");
	//char *ll = ft_strdup(out->next->content);
	int a = check_tetrims(out->content);
	int b = check_tetrims(out->next->content);
	int c = check_connections(out->content);
	printf("%d  %d  %d  %lu %lu\n", a, b, c, ft_strlen(out->content), ft_strlen(out->next->content));
}