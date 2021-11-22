#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "countsort.h"
#include "qsort.h"
#include <time.h>


int main() {
	FILE* fp;
	if ((fp = fopen("output.txt", "w+")) == NULL) {
		printf("ERROR with opening");
		return 1;
	}
	printf("Enter size of array: ");
	int n;
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));

	fprintf(fp, "%d", n);
	fprintf(fp, "%s", " Numbers: \t");

	/* Генерация случайных чисел от 0 до 100 */
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 101;
		//fprintf(fp, "%d%s", arr[i], " ");
	}

	
	int choose;
	printf("Choose the sort:\n1 - Count Sort\n2 - Quick Sort\n");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1: {
		FILE* count_file;
		count_file = fopen("count time.txt", "w+");
		clock_t begin = clock();		// Начало отсчета
		count_sort(arr, n);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		fprintf(count_file, "%d%s%lf", n," Numbers / Count sort Spent Time: ", time_spent);
	}
	case 2: {
		FILE* quick_file;
		quick_file = fopen("quick time.txt", "w+");
		clock_t begin = clock();		// Начало отсчета
		quick_sort(arr, 0, n - 1);
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		fprintf(quick_file, "%d%s%lf", n," Numbers / Quick sort Spent Time: ", time_spent);
	}
	}

	for (int i = 0; i < n; i++) {
		fprintf(fp, "%d%s", arr[i], " ");
	}
	

	free(arr);
	fclose(fp);

	return 0;
}
