#include<stdio.h>
	
void selection(int arr[],int n);
void buble_s(int arr[],int n);
void insertion(int arr[],int n);	
void print_ar(int arr[],int n);
void swap(int *x,int *y);

int main(){
	
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
     print_ar(arr,n);
     selection(arr,n);
     print_ar(arr,n);
	return 0;
}	

void print_ar(int arr[],int n){
	int i=0;
for(i=0;i<n;i++){
	printf("%d ",arr[i]);
}	
printf("\n");	
}

void swap(int *x,int *y){
	int temp= *x;
	*x=*y;
	*y=temp;
}

void buble_s(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void insertion(int arr[],int n){
	int i,j,key;
	
  for(i=1;i<n;i++){
key=arr[i];
j=i-1;

	while(j>=0&&arr[j]>key){
	arr[j+1]=arr[j];
	j--;
}
	arr[j+1]=key;
}		
}

void selection(int arr[],int n){
	
		int i, j, min_idx;


	for (i = 0; i < n-1; i++)
	{
		
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		
		swap(&arr[min_idx], &arr[i]);
	}
}


