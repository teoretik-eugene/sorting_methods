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

	count_sort(arr, n);

	return 0;
}

/* Функция сортировки подсчетом */
void count_sort(int *a, int n) {
	int* count = (int*)calloc(n, sizeof(int));
	// Счетчик всех чисел обнуляем
	for (int i = 0; i < n; i++)
		count[i] = 0;

	// Подсчитываем количество чисел исходного массива
	for (int i = 0; i < n; i++) {
		count[a[i]]++;
	}

	// Производим сортировку
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < count[i]; j++) {
			a[index++] = i;
		}
	}

	// Вывод массива на экран
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		printf(" ");
	}
}