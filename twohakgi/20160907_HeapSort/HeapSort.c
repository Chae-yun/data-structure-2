#include <stdio.h>

void HeapSort(int a[], int n){
	int i, parent, child, value, m = n;
	//�ִ� �� ����
	for (i = n / 2; i >= 1; i--){
		value = a[i];
		parent = i;
		while ((child = parent * 2) <= n){
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
	}

	//�� ����
	while (n > 1){
		value = a[n];
		a[n--] = a[1];
		parent = 1;
		while ((child = parent * 2) <= n){
			if (child + 1 <= n && a[child] < a[child + 1]) child++;
			if (value >= a[child]) break;
			a[parent] = a[child];
			parent = child;
		}
		a[parent] = value;
		for (i = 1; i <= m; i++)
			printf("%4d", a[i]);
		printf("\n");
	}
}

int main(){
	int a[] = { NULL, 10, 7, 1, 18, 6, 3, 15, 11, 12, 25 }; //a[0]�� ������� ����
	int n = sizeof(a) / sizeof(int);
	int i;
	printf("���� �� : ");
	for (i = 1; i < n; i++) printf("%4d", a[i]);
	printf("\n\n");
	HeapSort(a, n - 1);
	printf("\n�� ���� �� : ");
	for (i = 1; i < n; i++) printf("%4d", a[i]);
	printf("\n");

	return 0;
}