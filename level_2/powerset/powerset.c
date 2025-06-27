#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



int	calcul(int *nums, int n)
{
	int sum = 0;
	for(int x = 0; x < n; x++)
	{
		sum += nums[x];

	}
	return sum;
}

void	print(int *nums, int n)
{
	for(int x = 0; x < n; x++)
	{
		printf("%d", nums[x]);
		if(x < n -1 )
			printf(" ");

	}
	printf("\n");
}

void	solve(int *nums, int *subset, int size, int n, int subsize, int level)
{
	if(level == size)
	{
		if(calcul(subset, subsize) == n)
			print(subset, subsize);
		return ;
	}
	subset[subsize] = nums[level];
	solve(nums, subset, size, n, subsize + 1, level + 1);
	solve(nums, subset, size, n, subsize, level + 1);


}

int main(int ac, char **av)
{
	int n = atoi(av[1]);
	int size = ac - 2;
	int *nums  = malloc(sizeof(int) * size);
	int *subset  = malloc(sizeof(int) * size);
	for(int x = 0; x < size; x++)
		nums[x] = atoi(av[x + 2]);
	solve(nums, subset, size, n, 0, 0);
	free(nums);
	free(subset);
}
