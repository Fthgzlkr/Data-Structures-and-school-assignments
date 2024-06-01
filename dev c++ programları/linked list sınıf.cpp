#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Class{
	int number;
	char name[100];
	int vize;
	int final;
	float ortalama;
	struct Class * next;	
	
}Class;


void print_list(Class * root){

	Class * temp= root;
	
while(temp){
  printf("\nno: %d\n",temp->number);
  printf("name: %s\n",temp->name);
  printf("vize: %d   final: %d\n",temp->vize,temp->final);
  printf("ortalama: %0.4f \n \n",temp->ortalama);
  temp=temp->next; //Tempin nexti null olana kadar temp i temp next e atama.
  }
	return;
}


Class * Create_node(int x,char* name,int vize,int final){
	
   Class * node=(Class *)malloc(sizeof(Class)); // Ýlk düðümü oluþturma.
if(node){
	node->number = x;
	strcpy(node->name,name);
	node->vize = vize;
	node->final = final;
	node->ortalama =(node->vize+node->final)/2;
	node->next = NULL;  
}	
	return node;
}


 int main(){
 	Class * tmp=NULL;
	Class * node=NULL;
	Class * root=NULL;
	int numara=0;
	char name[100];
	int vize=0,final=0,i=0;
	float ortalama=0,ort_top=0;
	int choice=0;

	root=Create_node(100,"Fatih",100,0);
	node=root; 
	
  printf("for exit enter 0 to exit variable,\n 1 for append student,\n2 for print student names");
  
	do{
		printf("\n choice:");
		scanf("%d",&choice);
		
switch(choice)
{
	case 1:
		printf("Numara gir :");
		scanf("%d",&numara);
	    printf("Vize notu gir:\n");
	    scanf("%d",&vize);
	    printf("Final notu gir:\n");
	    scanf("%d",&final);
	    printf("isim giris:");
		scanf("%s ",&name);
		tmp=Create_node(numara,name,vize,final);
		if(tmp){
			node->next=tmp;
			node=node->next;
		}
		
break; 

	case 2:	
		print_list(root);	
break;	

     }
}while(choice!=0);



	return 0;
 }
