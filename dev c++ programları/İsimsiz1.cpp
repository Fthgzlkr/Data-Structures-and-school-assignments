#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};



void ekleme(int x){
	node *root;
	node *iter;
if(root==NULL){
	root=(struct node*)malloc(sizeof(struct node));
	root->data=x;
	root->next=NULL;
	iter=root;			
}
else{
	iter->next=(struct node*)malloc(sizeof(struct node));
	iter->data=x;
	iter=iter->next;
	iter->next=NULL;
}		
}
void print(node *root){
 node *	temp=root;
	while(temp!=NULL){
		printf("\n %d",&temp->data);
		temp=temp->next;
	}
}
void sort(node *root,int x){
	node *ptr=root;
	while(ptr->next==NULL) ptr=ptr->next;
	
	if(x>ptr->data){
		ptr->next=ekleme(x);
		return root;
	}
	else return ekleme(x);
	
}

int main(){
	node *root = NULL;
	int x;
	printf("cikmak icin -1\n");
	while (1==1){
		printf("data: ");
		scanf("%d", &x);
		if (data == -1) break;
		
		root = sort(root, x);
	}	
	
	print(root);
}

