#include <stdio.h>
#include <stdlib.h>
#include "countsort.h"

/* ������� ���������� ��������� */
void count_sort(int* a, int n) {
	// ����� ����������� ������� �����
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	int* count = (int*)calloc(max + 1, sizeof(int));	// �������� ������ ��� ����� ������
	// ������� ���� ����� ����� 0
	for (int i = 0; i < max + 1; i++)
		count[i] = 0;

	// ������������ ���������� ������� ����� � �������� �������
	for (int i = 0; i < n; i++) {
		count[a[i]] = count[a[i]] + 1;
	}

	// ���������� ����������
	int index = 0;
	for (int i = 0; i < max + 1; i++) {
		for (int j = 0; j < count[i]; j++) {
			a[index++] = i;
		}
	}

	//free(*count);		�������???
}