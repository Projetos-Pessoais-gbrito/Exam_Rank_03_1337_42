#include <stdlib.h>
#include <stdio.h>

void print(int *subsize, int size)
{
	for(int i = 0; i < size; i++)
	{
		if (i > 0)
			printf(" ");
		printf("%d", subsize[i]);
	}
	printf("\n");
}

int calcul(int *subnet, int subsize)
{
	int n;

	n = 0;
	for(int i = 0; i < subsize; i++)
	{
		n += subnet[i];
	}
	return n;
}

void solve(int *nums, int *subset, int size, int n, int subsize, int level)
{
	if(level == size)
	{
		if(calcul(subset, subsize) == n)
			print(subset, subsize);
		return;
	}
	subset[subsize] = nums[level];
	solve(nums, subset, size, n, subsize + 1, level + 1);
	solve(nums, subset, size, n, subsize, level + 1);
}

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int size = argc - 2;
	int *subset = malloc(sizeof(int) * size);
	int *nums = malloc(sizeof(int) * size);
	for(int x = 0; x < size; x++)
		nums[x] = atoi(argv[x + 2]);
	solve(nums, subset, size, n, 0, 0);
	free(nums);
	free(subset);
	return 0;
}