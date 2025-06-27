#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


void	print(int *board, int n)
{
	for(int x = 0; x < n; x++)
	{
		fprintf(stdout, "%d", board[x]);
		if(x < n - 1)
			fprintf(stdout, " ");
		else
			fprintf(stdout, "\n");
	}
}

int	check(int *board, int col, int row)
{
	for(int x = 0; x < col; x++)
	{
		if(board[x] == row || board[x] - row == col - x || row - board[x] == col - x)
			return 1;

	}
	return 0;
}

void	solve(int *board, int col, int n)
{
	if(col == n)
	{
		print(board, n);
		return ;
	}
	for(int row = 0; row < n; row++)
	{
		if(check(board, col, row) == 0)
		{
			board[col] = row;
			solve(board, col + 1, n);
		}

	}

}



int main(int ac, char **av)
{
	(void)ac;//needs to be changed according to the subject requi.
	int n = atoi(av[1]);
	int *board = malloc(sizeof(int) * n);

	solve(board, 0, n);
	free(board);


}
