#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include <conio.h>

void statMas(void);
void dynMas(void);

int main()
{
	srand(time(0));
	statMas();
	printf("\n\n");
	dynMas();
	_getch();
	return 0;
}
void statMas(void)
{
	unsigned int startTime = clock();
	const short n = 10;

	const short myN = n + 1;
	float arr[myN] = {};
	int i = 0;
	short j = 0, first = 0, last = 0;
	short k = 0;	float sum = 0.0;
	printf("work with static array:\n");
	for (i = 1; i < n; i++)
		arr[i] = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 20)) - 10;		//create massive
	arr[n] = 0.16;
	printf("array:\n");
	for (i = 1; i < myN; i++)
		printf("%d\t%2.2f\n", i, arr[i]);	//out


	for (i = 1; i < myN; i += 2)
		sum += arr[i];
	printf("\nsumma of odd elements= %f\n", sum);		//nechetnoe

	sum = 0.0;
	for (i = 1; i < myN; i++)
		if (arr[i] < 0)
		{
			first = i;
			last = i + 1;
			while (j < myN)
			{
				if (arr[j] <= 0)
					last = j;
				j++;
			}
			break;
		}

	if ((first > 0) and (last > first))
		for (i = first; i <= last; i++)
			sum += arr[i];
	printf("summa between negatives= %f\n\n", sum);		//between negatives

	k = n;
	printf("changed array:\n");
	for (i = 1; i <= k; i++)
	{
		if ((arr[i] >= -1) and (arr[i] <= 1))
		{
			for (j = i; j < k; j++)
			{
				arr[j] = arr[j + 1];
			}
			arr[k] = 0;
			k--;
			i--;
		}
	}
	for (i = 1; i < myN; i++)
		printf("%d\t%2.2f\n", i, arr[i]);	//out
	printf("\n");


	const unsigned short size = 5;
	int mul = 1;
	int matr[size][size] = {};
	bool notcalc = false;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matr[i][j] = (rand() % 20) - 10;	//create
		}
	}
	printf("matrix:\n");
	for (i = 0; i < size; i++)
	{
		mul = 1;	notcalc = false;
		for (j = 0; j < size; j++)
		{
			printf("%-5d", matr[i][j]);
			if (matr[i][j] < 0)
				notcalc = true;

		}
		if (notcalc == false)
		{
			for (j = 0; j < size; j++)
				mul *= matr[i][j];
			printf("multiplication=%d", mul);
		}
		printf("\n");
	}

	int max = -20;
	for (j = 1; j < size; j++)
	{
		mul = 0;
		for (i = 0; i < size - j; i++)
		{
			mul += matr[i][i + j];
		}
		if (mul > max)
			max = mul;
	}
	for (j = 1; j < size; j++)
	{
		mul = 0;
		for (i = 0; i < size - j; i++)
		{
			mul += matr[i+j][i];
		}
		if (mul > max)
			max = mul;
	}
	printf("max=%d\n", max);
	printf("runtime=%d\n", clock() - startTime);
}

void dynMas(void)
{
	unsigned int startTime = clock();
	unsigned short n = 10;

	unsigned short myN = n + 1;
	printf("work with dynamic array:\n");
	float* arr = new float[myN]();
	for (unsigned short i = 1; i < myN; i++)
		arr[i] = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 20)) - 10;
	//arr[1] = 0.1; arr[2] =0.2; arr[3] = 0.3; arr[4] = 0.4; arr[5] = -1.0;
	for (unsigned short i = 1; i < myN; i++)
		printf("%d\t%4.5f\n", i, arr[i]);

	float sum = 0.0;
	for (int i = 1; i < myN; i += 2)
		sum += arr[i];
	printf("\nsumma of odd elements= %f\n", sum);		//nechetnoe

	sum = 0.0;	
	short j = 0, first = 0, last = 0;
	for (unsigned short i = 1; i < myN; i++)
		if (arr[i] < 0)
		{
			first = i;
			last = i + 1;
			while (j < myN)
			{
				if (arr[j] <= 0)
					last = j;
				j++;
			}
			break;
		}

	if ((first > 0) and (last > first))
		for (unsigned short i = first; i <= last; i++)
			sum += arr[i];
	printf("summa between negatives= %f\n\n", sum);		//between negatives

	short k = n;
	printf("changed array:\n");
	for (unsigned short i = 1; i <= k; i++)
	{
		if ((arr[i] >= -1) and (arr[i] <= 1))
		{
			for (j = i; j < k; j++)
			{
				arr[j] = arr[j + 1];
			}
			arr[k] = 0;
			k--;
			i--;
		}
	}
	for (unsigned short i = 1; i < myN; i++)
		printf("%d\t%2.2f\n", i, arr[i]);	//out
	printf("\n");
	delete[] arr;

	unsigned short size = 5;
	int mul = 1;	bool notcalc = false;
	int** matr = new int* [size];
	for (unsigned short i = 0; i < size; i++)
		matr[i] = new int[size]();
	printf("matrix:\n");
	for (unsigned short i=0; i<size; i++)
	{
		for (unsigned short j=0; j<size; j++)
		{
			matr[i][j] = (rand() % 20)-10;		//create			
		}
	}
	for (unsigned int i = 0; i < size; i++)
	{
		mul = 1;	notcalc = false;
		for (j = 0; j < size; j++)
		{
			printf("%-5d", matr[i][j]);
			if (matr[i][j] < 0)
				notcalc = true;

		}
		if (notcalc == false)
		{
			for (j = 0; j < size; j++)
				mul *= matr[i][j];
			printf("multiplication=%d", mul);
		}
		printf("\n");
	}
	int max = -20;
	for (j = 1; j < size; j++)
	{
		mul = 0;
		for (unsigned short i = 0; i < size - j; i++)
		{
			mul += matr[i][i + j];
		}
		if (mul > max)
			max = mul;
	}
	for (j = 1; j < size; j++)
	{
		mul = 0;
		for (unsigned short i = 0; i < size - j; i++)
		{
			mul += matr[i + j][i];
		}
		if (mul > max)
			max = mul;
	}
	printf("max=%d\n", max);
	for (unsigned short i = 0; i < size; i++)
		delete[] matr[i];
	delete[] matr;
	printf("runtime=%d\n", clock() - startTime);
}