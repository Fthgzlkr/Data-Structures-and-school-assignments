#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
struct Node *next;
struct Node *prev;	
};

struct Node *root=NULL;
struct Node *iter=NULL;
struct Node *temp=NULL;
void insert(int x){
	
 if(root==NULL)    //Düðüm daha oluþturulmamýþsa
	{
		root=(struct Node*) malloc(sizeof(struct Node)),
		root->data=x;
		root->prev=NULL;
		root->next=NULL;
		iter=root;
	}
 else
		{
		iter->prev=(struct Node*) malloc(sizeof(struct Node));
		iter->prev->next=iter;
		iter=iter->prev;
		iter->data=x;	
		iter->prev=NULL;
			}	
	
	
}
void print_list(Node *prn){
temp=prn;
	while(temp!=NULL){
printf("\n %d",temp->data);		
	temp=temp->prev;	
	}
}

int main(){
	
int x,choice=0;
	
	
printf(" dugum ekleme 1 yazdirip cikma 2  \n");	
	
 	do{
		printf("\n choice:");
		scanf("%d",&choice);
		
switch(choice)
{
	case 1:
		printf("data gir :");
		scanf("%d",&x);
		insert(x);
		
break; 

	case 2:	
		print_list(root);	
		
break;	

     }
}while(choice!=0);

	
return 0;	
}
