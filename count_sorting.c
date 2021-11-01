#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void count_sort(int* a, int n);

int main() {
	// ������ ������ �����
	printf("Enter size of array\n");
	int n;		// ������ �������
	scanf("%d", &n);
	int* arr = (int*)calloc(n, sizeof(int));
	printf("Enter numbers\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	count_sort(arr, n);

	return 0;
}

/* ������� ���������� ��������� */
void count_sort(int *a, int n) {
	int* count = (int*)calloc(n, sizeof(int));
	// ������� ���� ����� ��������
	for (int i = 0; i < n; i++)
		count[i] = 0;

	// ������������ ���������� ����� ��������� �������
	for (int i = 0; i < n; i++) {
		count[a[i]]++;
	}

	// ���������� ����������
	int index = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < count[i]; j++) {
			a[index++] = i;
		}
	}

	// ����� ������� �� �����
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		printf(" ");
	}
}