#include<stdio.h>

int main(){
	int arr[1000];
	int sum,i,n;
scanf("%d",&n);	
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		
	}
	for(i=0;i<n;i++){
		sum=sum+arr[i];
	}
	printf("%d",&sum);
	
	
return 0;	
}
