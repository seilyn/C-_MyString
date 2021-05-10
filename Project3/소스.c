#include <stdio.h>
#define MAX_SIZE 10

void Swap(int arr[], int i, int j);
void Print(int arr[]);

void QuickSort(int arr[], int left, int right) {
	if (left < right) {
		int q = Partition(arr, left, right);

		Print(arr);
		QuickSort(arr, left, q - 1);;
		QuickSort(arr, q + 1, right);
	}
}

int Partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot >= arr[low] && low <= right) {
			low++;
		}
		while (pivot <= arr[high] && high >= (left + 1)) {
			high--;
		}
		if (low <= high) {
			Swap(arr, left, high);
		}
	}
	Swap(arr, left, high);
	return high;
}

void Swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void Print(int arr[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%2d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int b_ar[MAX_SIZE], i_ar[MAX_SIZE], q_ar[MAX_SIZE];

	srand((unsigned)time(NULL));

	for (int i = 0; i < MAX_SIZE; i++) {
		b_ar[i] = rand() % 10 + 1;
		i_ar[i] = b_ar[i];
		q_ar[i] = b_ar[i];
		for (int j = 0; j < i; j++) {
			if (b_ar[j] == b_ar[i]) {
				i--;
				break;
			}
		}
	}
	QuickSort(q_ar, 0, MAX_SIZE - 1);
	Print(q_ar);

	return 0;
}