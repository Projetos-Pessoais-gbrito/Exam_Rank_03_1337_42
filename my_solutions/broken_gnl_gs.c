/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broken_gnl_gs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 00:54:29 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/08/05 01:18:12 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *ft_strdup(char *cpy)
{
	char *destiny;
	int i;

	destiny = (char *)malloc(sizeof(char) * strlen(cpy));
	if(!destiny)
		return NULL;
	i = 0;
	while(cpy[i])
	{
		destiny[i] = cpy[i];
		i++;
	}
	destiny[i] = '\0';
	return (destiny);
}

char	*brk_gnl(int fd)
{
	static char buffer[BUFFER_SIZE];
	char		line[70000];
	static int	read_pos;
	static int	read_b;
	int 		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0)
		return NULL;
	while(1)
	{
		if (read_b <= read_pos)
		{
			read_b = read(fd, buffer, BUFFER_SIZE);
			read_pos = 0;
			if (read_b <= 0)
				break;
		}
		line[i++] = buffer[read_pos++];
		if (buffer[read_pos - 1] == '\n')
			break;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int main(void)
{
	int fd;

	fd = 0;
	fd = open("file.txt", O_RDONLY);
	printf("%s" ,brk_gnl(fd));
	return 0;
}