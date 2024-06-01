#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct Yigin
{ int indis;
 char eleman[YBoyut];
}Yiginlar;
void Yigina_Ekle(char ekle)
char Yigindan_Cikar();
int Parantez_Kotrol(char *islem)
{ int i;
for (i=0;i<strlen(islem);i++)
{
if (islem[i]=='(')
Yigina_Ekle(islem[i]);
else
{
if (islem[i]==')')
{if(Yigin_Bosmu()==-1)
return -1;
else
Yigindan_Cikar();
}
}
}
if (Yigin_Bosmu(Yeni_Yigin)==-1) return 0;
else
return 1;
}
void main()
{
Yiginlar *Yeni_Yigin=Yigin_Olustur();
int i;
char secim;
char *islem;//="(3+4)/5)";
clrscr();
printf("Kontrol stringi=>");
scanf("%s",islem);
i=Parantez_Kotrol(islem);
switch(i)
{
case -1:printf("Hata:Acma Parantezi Eksik");
break;
case 0:printf("Parantez Hatasi Yok");break;
case 1:printf("Hata:Kapama parantezi Eksik");

}
}

