#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#define arraySize 40

typedef struct Stack{
	int index;
	int array[arraySize];
}Stack;


int isFull(Stack temp){
	return temp.index == arraySize-1;
}

int isEmpty(Stack temp){
	return temp.index == -1;
}


Stack add(Stack temp,int number){
	if(isFull(temp)){
		return temp;
	}

	temp.index ++;
	temp.array[temp.index] = number;
	return temp;
}

Stack remove(Stack temp){
	if(isEmpty(temp)){
		return temp;
	}
	temp.index--;
	return temp;
}


void printStack(Stack temp){
	int i = temp.index;
	while(i >= 0){
		printf("%d ",temp.array[i]);
		i--;
	}
}

int main(){
	
	Stack yigin;
	yigin.index = -1;
	
	yigin = add(yigin,5);
	yigin = add(yigin,4);
	yigin = add(yigin,3);
	yigin = add(yigin,2);
	
	printStack(yigin);
	
	yigin = remove(yigin);
	yigin = remove(yigin);
	
	printf("\n");
	
	printStack(yigin);
	return 0;
}
