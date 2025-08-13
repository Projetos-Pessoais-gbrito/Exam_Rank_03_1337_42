#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	calcul(int *subset, int subsize)
{
	int sum = 0;
	for(int x = 0; x < subsize; x++)
	{
		sum += subset[x];
	}
	return sum;
}

void	print(int *subset, int subsize)
{
	for(int x = 0; x < subsize; x++)
	{
		printf("%d", subset[x]);
		if(x < subsize - 1 )
			printf(" ");
	}
	printf("\n");
}

void solve(int *nums, int *subset, int size, int n, int subsize, int level)
{
	if (level == size)
	{
		if (calcul(subset, subsize) == n)
			print(subset, subsize);
		return;
	}
	subset[subsize] = nums[level];
	solve(nums, subset, size, n, subsize + 1, level + 1);
	solve(nums, subset, size, n, subsize, level + 1);
}

int main(int argc, char **argv)
{
	int size = argc - 2;
	int *subset = malloc(sizeof(int) * size);
	int *nums = malloc(sizeof(int) * size);
	int n = atoi(argv[1]);
	for (int i = 0; i < size; i++)
		nums[i] = atoi(argv[i + 2]);
	solve(nums, subset, size, n, 0, 0);
	free(subset);
	free(nums);
}