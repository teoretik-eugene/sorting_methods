#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void quick_sort(int* arr, int low, int high);
int partition(int* arr, int low, int high);
void swap(int *a, int *b);
void ShowArr(int* arr, int len);

int main() {
	int length;
	scanf("%d", &length);
	int* array = (int*)calloc(length, sizeof(int));
	for (int i = 0; i < length; i++) {
		scanf("%d", &array[i]);
	}
	quick_sort(array, 0, length - 1);
	printf("\n");
	ShowArr(array, length);

	return 0;
}

int partition(int* arr, int low, int high) {
	int pivot = arr[high];		// пивот или же разрешающий элемент

	int i = low - 1;
	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i+1);
}

void quick_sort(int *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);

		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}

}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void ShowArr(int *arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d%s", arr[i], " ");
	}
}
