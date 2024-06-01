#include<stdio.h>

struct ders{
	
int ders_kodu;	
int vize;
int final;
double gecme_notu;	
};

struct ogrenci{
char ad[20];char soyad[20];	
int no;	
struct ders dersler[2];	
}students[3];

int main(){
for(int i=0;i<3;i++){
	printf("%d. Ogrencinin ad soyad ve nosunu giriniz: \n",i+1);
	scanf("%s %s %d",students[i].ad,students[i].soyad,&students[i].no);
	for(int j=0;j<2;j++){
	printf("Ders kodu vizesi ve finalini giriniz:");	
	scanf("%d%d%d",&students[i].dersler[j].ders_kodu,&students[i].dersler[j].vize,&students[i].dersler[j].final);	
	students[i].dersler[j].gecme_notu=students[i].dersler[j].vize*(0.4)+students[i].dersler[j].final*(0.6);
}
	}
for	(int k=0;k<3;k++)
{
printf("%d. ogrencinin bilgileri sunlardir:%s %s %d",students[k].ad,students[k].soyad,students[k].no);	
	for(int m=0;m<2;m++)
	{
		printf("Ders kodu:%d \n Gecme Notu: %f\n vize:%d \n final:%d",students[k].dersler[m].ders_kodu,students[k].dersler[m].gecme_notu,students[k].dersler[m].vize,students[k].dersler[m].final);	
	}
	
}	
	
	
	return 0;
}
