#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void	swap(char *s, char *ss)
{
	char tmp = *s;
	*s = *ss;
	*ss = tmp;
}

void	sort(char *s)
{
	for(int x = 0; s[x]; x++)
	{
		for(int y = x + 1; s[y]; y++)
		{
			if(s[x] > s[y])
				swap(&s[x], &s[y]);
		}
	}
}

void	print(char *s, int n)
{
	write(1, s, n);
	write(1, "\n", 1);
}

void	solve(char *s, int start, int n)
{
	if(start == n)
	{
		print(s, n);
		return ;
	}
	for(int x = start; x < n; x++)
	{
		swap(&s[start], &s[x]);
		solve(s, start + 1, n);
		swap(&s[start], &s[x]);
	}
}


int main(int ac, char **av)
{
	(void)ac;//needs to be changed
	char *s = strdup(av[1]);
	int n = strlen(av[1]);
	sort(s);
	solve(s, 0, n);
	free(s);

}
