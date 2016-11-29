#include <stdio.h>
#define R 3

int b[R] = { 0, };
int cnt = 0;

void PrintRePer(){
	int i;
	
	cnt++;
	for (i = 0; i < R; i++)
		printf("%d  ", b[i]);
	printf("\n");
}

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void RePermutation(int a[], int n, int r){
	int i;
	if (r >= R)PrintRePer();
	else for (i = 0; i < n; i++){
		Swap(a + 0, a + i);
		b[r] = a[0];
		RePermutation(a, n, r + 1);
		Swap(a + 0, a + i);
	}
}

int main(){
	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);

	RePermutation(a, n, 0);
	printf("중복 순열 개수 : %d\n", cnt); //5*5*5

	return 0;
}