#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
# define BOYUT 100
 
  typedef struct Node{
 	int indis;
 	int eleman[BOYUT];
 }Stack;
 
 Stack Yeni_stack;
 Yeni_stack.indis=-1;
 
 int dolu_mu(){
 	if(Yeni_stack.indis>=BOYUT-1)return -1;
 	else return 1;
 	
 }
 int bos_mu(){
 	if(Yeni_stack.indis==-1) return -1;
 	else return 1;
 }
 void ekleme(int veri){
 	if(dolu_mu(Yeni_stack)==-1){
 		printf("Yigin doludur ekleme yapilamaz");
	 }
	else{
		Yeni_stack.indis++;
		Yeni_stack.eleman[Yeni_stack->indis]=veri;
	}
 }

  void cikarma{
  	int cikan;
  	if(bos_mu(Yeni_stack)==-1){
  		printf("Stack bostur cikarma yapilamaz");
  		return -1;
	  }
	else{
		cikan=Yeni_stack->eleman[Yeni_stack.indis];
		Yeni_stack.indis--;
		return cikan;
	}
  }
  
  void yazdir(){
  nt i;
	for (i=Yeni_stack.indis;i>=0;i--)
printf("\n %d",Yeni_stack->eleman);
}

 
 
 int main(){
 	return 0;
 }
