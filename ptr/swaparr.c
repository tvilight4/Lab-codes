#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print(int *p, int n) {
for (int i=0; i<n; i++) {
printf("%d\t", *(p+i));
}
printf("\n");
}

void swap(int *a, int *b) {
int temp;
temp = *a; // temp holds deferenced value
*a = *b;
*b = temp;
}
int main() {
int arr[] = {3, 4, 7, 11};
int n = sizeof(arr)/sizeof(arr[0]);
int *ptr = arr;
print(arr, n);
int smallest = 0;
int largest = 0;
for (int i=0; i<n; i++) {
if (*(ptr + i) < ptr[smallest]) {
smallest = i;
}if (*(ptr + i) > ptr[largest]) {
largest = i;
}
}
swap(ptr+smallest, ptr+largest);
print(arr, n);
return 0;
}