#include<stdio.h>
#include<stdlib.h>

struct List{
	int data;
struct List *next;
};
typedef List node;



void push(int x){
	node *root;
	node *iter;
if(root==NULL){
	root=(node*)malloc(sizeof(node));
	root->data=x;
	root->next=NULL;
	iter=root;
}	
else{
	iter=(node*)malloc(sizeof(node));
	iter->data=x;		
	iter->next=root;
	root=iter;	
  }	
}



void print(node *root){
	node *iter;
	iter=root;
	
while(iter!=NULL){
	printf("%d\n",iter->data);
	iter=iter->next;
}	
}
