#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void count_sort(int* a, int n);

int main() {
	// Введем массив чисел
	printf("Enter size of array\n");
	int n;		// Размер массива
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	printf("Enter numbers\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	count_sort(arr, n);		// сортируем
	free(*arr);

	return 0;
}

/* Функция сортировки подсчетом */
void count_sort(int *a, int n) {
	// Найти максимально большое число
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	int* count = (int*)calloc(max + 1, sizeof(int));	// Выделяем память под новый массив
	// Счетчик всех чисел равен 0
	for (int i = 0; i < max + 1; i++)
		count[i] = 0;

	// Подсчитываем количество каждого числа в исходном массиве
	for (int i = 0; i < n; i++) {
		count[a[i]] = count[a[i]] + 1;
	}

	// Производим сортировку
	int index = 0;
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < count[i]; j++) {
			a[index++] = i;
		}
	}

	// Вывод массива на экран
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		printf(" ");
	}

	//free(*count);		ошиббка???
}
