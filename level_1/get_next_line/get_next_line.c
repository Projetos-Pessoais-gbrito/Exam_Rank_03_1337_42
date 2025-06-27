#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

char	*ft_strdup(char *s)
{
	char *tmp = malloc(sizeof(char) * (strlen(s) + 1));
	if (!tmp)
		return (NULL);
	int x = 0;
	while (s[x])
	{
		tmp[x] = s[x];
		x++;
	}
	tmp[x] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char buff[SIZE];
	char line[70000];
	static int r = 0;
	static int x = 0;
	int y = 0;

	while (1)
	{
		if (x >= r)
		{
			r = read(fd, buff, SIZE);
			x = 0;
			if (r <= 0)
				break ;
		}
		line[y++] = buff[x++];
		if (buff[x - 1] == '\n')
			break ;
	}
	line[y] = '\0';
	if (y == 0)
		return (NULL);
	return (ft_strdup(line));
}

//int main(){
//	int fd = open("in", O_RDONLY);
//	char *line;
///	while ((line = get_next_line(fd)) != NULL)
//	{
//		printf("%s", line);
//		free(line);
//	}
//
//
//}

