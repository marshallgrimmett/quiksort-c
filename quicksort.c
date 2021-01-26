#include <stdio.h>

int partition(int *a, int p, int r);
void quicksort(int *a, int i, int j);

int main(int argc, char *argv[]) {
	int a[] = {4, 8, 3, 9, 3, 7, 7, 2, 1, 2};	
	
	// sort array
	quicksort(a, 0, 9);
	//quicksort(argv, 0, argc);
	
	// print array
	for (int i = 0; i < 9; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

void quicksort(int *a, int i, int j) {
	if (i < j) {
		int p = partition(a, i, j);
		quicksort(a, i, p);
		quicksort(a, (p+1), j);	
	}
	return;
}

// could maybe optimize the while loops to stop when they pass each other.
// could maybe remove some redundancy.
int partition(int *a, int s, int t) {
	int p = a[s];
	int i = s;
	int j = t;
	int temp;

	while (1) {
		while (i < t && a[i] < p)
			i++;
		while (j > s && a[j] >= p)
			j--;
		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else {
			return j;
		}
	}
}

