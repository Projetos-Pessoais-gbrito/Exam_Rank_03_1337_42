/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 09:42:32 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/08/13 09:57:48 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strncmp(char *original, char *to_compare, int len)
{
	int i;

	i = 0;
	while (i < len && to_compare[i])
	{
		if (original[i] != to_compare[i])
			return 0;
		i++;
	}
	return 1;
}

int main(int argc, char **argv)
{
	char *buffer = malloc(100000000);
	char c;
	char *tmp = argv[1];
	int len = strlen(argv[1]);
	int i = 0;
	int r = read(0, &c, 1);
	(void) argc;

	i = -1;
	if (r < 0)
		write(2, "Error: invalid read", 19);
	if (!buffer)
		write(2, "Error: invalid malloc", 21);
	while (r > 0)
	{
		buffer[++i] = c;
		r = read(0, &c, 1);
		if (r < 0)
			write(2, "Error: invalid read", 19);
	}
	buffer[i] = '\0';
	i = 0;
	while (buffer[i])
	{
		if (ft_strncmp(&buffer[i], tmp, len))
		{
			for (int j = 0; j < len; j++)
				write(1, "*", 1);
			i += len;
		}
		else
		{
			write(1, &buffer[i], 1);
			i++;
		}
	}
	free(buffer);
}