#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
	int temp= *a;
	*a=*b;
	*b=temp;
}
void insertion(int arr[],int size){
	int i,j;
for(i=0;i<size;i++){
	for(j=i;j>=0;j--){
		if(arr[j]>arr[j+1]) swap(&arr[j+1],&arr[j]);
		else break;
	}
  }		
}

int main(){
	int i,arr[100];
	srand(time(NULL));
FILE *f=fopen("ilk.txt","w");
for(i=0;i<100;i++)fprintf(f,"%d\n",rand()%100);
	fclose(f);
	
f=fopen("ilk.txt","r");
for(i=0;i<100;i++)fscanf(f,"%d",&arr[i]);
fclose(f);
insertion(arr,100);
f=fopen("son.txt","w");
for(i=0;i<100;i++) fprintf(f, "%d\n", arr[i]);
fclose(f);	
	
	return 0;
}
