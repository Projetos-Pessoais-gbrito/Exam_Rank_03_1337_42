/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_gs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gustavo-linux <gustavo-linux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:27:05 by gustavo-lin       #+#    #+#             */
/*   Updated: 2025/08/10 16:48:05 by gustavo-lin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int is_safe(int *positions, int current_col, int current_row)
{
	for(int previous_col = 0; previous_col < current_col; previous_col++)
	{
		int previous_row = positions[previous_col];
		if(current_row == previous_row || previous_col - previous_row == current_col - current_row || previous_col + previous_row == current_col + current_row)
			return 0;
	}
	return 1;
}

void solve(int *positions, int col, int n)
{
	if(col == n)
	{
		for(int i = 0; i < n; i++)
		{
			if(i > 0)
				printf(" ");
			printf("%d", positions[i]);
		}
		printf("\n");
		return;
	}
	for(int row = 0; row < n; row++)
	{
		if(is_safe(positions, col, row))
		{
			positions[col] = row;
			solve(positions, col + 1, n);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] != '-')
	{
		int n = atoi(argv[1]);
		int *positions = malloc(sizeof(int) * n);
		solve(positions, 0, n);
	}
	return 0;
}