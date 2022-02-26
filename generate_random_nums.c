#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SIZE 100

int find(int *nums, int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		if (nums[i] == num)
			return 1;
	}
	return (0);
}

int main(int ac, char **av)
{
	int size;
	int step;
	if (ac == 1)
		size = SIZE;
	else
		size = atoi(av[1]);

	int *nums = malloc(sizeof(int) * size);
	memset(nums, 0, (size * sizeof(int)));
	step = size * 2;
	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		int num = rand() % step;
		if (!find(nums, size, num))
		{
			nums[i] = num;
			printf("%d ", num);
		}
		else
			i--;
	}
	printf("\n");
}
