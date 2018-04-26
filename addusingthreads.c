#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int finalResult = 0;
int numbers[1000];

void *addNumbers(void *arg)
{
	int *Index = (int*)arg;
	int sum = 0;
	int i = 0;
	
	for(i = (*Index)*100; i < (*Index)*100 + 100 ; i++)
		{
			sum = sum + numbers[i];	
		}

	finalResult = finalResult + sum;
}

int main()
{
	int Index[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	pthread_t threads[10];
	int i = 0;

	for(i; i<1000; i++)
	{
		numbers[i] = i+1; //from 1 to 1000
	}

	i = 0;
	
	for(i; i<10; i++)
	{
		pthread_create(&threads[i], NULL, addNumbers, (void*)&Index[i]);
	}

	i = 0;

	for(i; i<10; i++)
	{
	pthread_join(threads[i], NULL);
	}
	
	printf("%d\n", finalResult);

	return 0;
	
}



