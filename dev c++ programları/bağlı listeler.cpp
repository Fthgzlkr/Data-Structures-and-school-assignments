#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *root=NULL;
struct node *ptr=NULL;
struct node *gecici=NULL;

void insert(int sayi){
	
if(root==NULL){
  root=(node*)malloc(sizeof(node));
  root->data=sayi;
  root->next=NULL;
  root->prev=NULL;
  ptr=root;	
	}
	
	else{
		ptr->next=(node*)malloc(sizeof(node));
		ptr->next->prev=ptr;
		ptr=ptr->next;
		ptr->data=sayi;
		ptr->next=NULL;
	}
}

void printer(node *r){
	while(r!=NULL){
		printf("%d ->",r->data);
		r=r->next;
	}
}

void deletion(int sayi){
node *iter=root;
node *temp;
	
if(root->data==sayi){
   root=root->next;   	
   free(root->prev);
   root->prev=NULL;	
}

else{
	while(iter-> next !=NULL && iter -> next -> data != sayi )
	iter = iter -> next;
	
		if(iter -> next == NULL){
			printf("sayi listede yok");
		}
		else{
			
		temp = iter -> next;
		if(temp ==ptr){
			ptr = ptr -> prev; 
		}
		
		iter -> next = iter -> next -> next;
		free(temp);
		if(iter -> next != NULL)
		iter -> next -> prev = iter;
		
		}
	}
}
int main(){
	int sayi;
	srand(time(NULL));
for(int i=0;i<10;i++){
	insert(rand()%100);
}	
printer(root);
printf("\n silinecek deðer giriniz;"); scanf("%d",&sayi);
deletion(sayi);
printf("\n");
printer(root);
	
	return 0;
}
	







