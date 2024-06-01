#include <stdio.h>

#define SIZE 10

int binarySearch(int array[], int size, int element) {
  int low = 0;
  int high = size - 1;

  while (low <= high) {
    int middle = (low + high) / 2;
    int guess = array[middle];

    if (guess == element) {
      return middle;
    }

    if (guess > element) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }

  return -1;
}

int main() {
  int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int element;

  printf("Enter the element to search for: ");
  scanf("%d", &element);

  int index = binarySearch(array, SIZE, element);
  if (index >= 0) {
    printf("Element %d found at index %d\n", element, index);
  } else {
    printf("Element %d not found in the array\n", element);
  }

  return 0;
}

