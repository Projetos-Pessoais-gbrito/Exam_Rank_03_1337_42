/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_gs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 01:47:54 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/08/05 02:10:26 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int is_safe(int *positions, int current_col, int current_row)
{
	for (int prev_col = 0; prev_col < current_col; prev_col++)
	{
		int prev_row = positions[prev_col];
		if (prev_row == current_row ||
			prev_row - prev_col == current_row - current_col ||
			prev_row + prev_col == current_row + current_col)
			return 0;
	}
	return 1;
}

void solve(int *positions, int col, int n)
{
	if (n == col)
	{
		for(int i = 0; i < n; i++)
		{
			if (i > 0)
				printf(" ");
			printf("%d", positions[i]);
		}
		printf("\n");
		return ;
	}
	for(int row = 0; row < n; row++)
	{
		if (is_safe(positions, col, row))
		{
			positions[col] = row;
			solve(positions, col + 1, n);
		}
	}
}

int main(int argc, char **argv)
{
	int n;

	n = 0;
	if (argc == 2 && argv[1][0] != '-')
	{
		n = atoi(argv[1]);
		int *positions = malloc(sizeof(int) * n);
		if (!positions)
			return (0);
		solve(positions,0,n);
		free(positions);
	}
}