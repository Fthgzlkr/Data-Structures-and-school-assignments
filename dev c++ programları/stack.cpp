#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define Boyut 100
  
 struct Stack
 {
	int indis;
	int veri[Boyut];
};
 struct Stack yeni_y;

	yeni_y.indis=-1;

int Yigina_ekle(int veri){
	if(yeni_y->indis>=Boyut-1){
		printf("Yigin doludur ekleme yapilamaz \n");
	}
	else{
		yeni_y->indis++;
		yeni_y->veri[yeni_y->indis]=veri;
	}
}

int Yigindan_cikar(){
	int cikan;
	if(yeni_y->indis==-1){
		printf("Yigin bostur yigindan cikarma yapilamaz \n");
	}
	else {
		cikan= yeni_y->veri[yeni_y->indis];
		yeni_y->indis--;
		return cikan;
	}
}


