#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct node{
	char yemekAdi[255];
	int yemekGramaji;
	float yemekFiyati;
	node * next;

}node;

node * root = NULL;
node * ptr = NULL;





void Listele(){
printf("\n\t\t\tyemek adi: %s		yemek gramaji: %d	yemek fiyati:%.2f \n",root->yemekAdi, root -> yemekGramaji , root -> yemekFiyati);
node * temp = root -> next ;
	while (temp != root){
		printf("\n\t\t\t");
		printf("yemek adi: %s		yemek gramaji: %d	yemek fiyati:%.2f \n",temp->yemekAdi, temp -> yemekGramaji , temp -> yemekFiyati);
		temp = temp -> next;
		
	}
}




node * BilgiAl(){
	node * temp = (node *)malloc(1*sizeof(node));
	printf("\n\t\t\tyemegin ismini giriniz: ");
	scanf("%s",&temp -> yemekAdi);
	printf("\n\t\t\tyemegin gramajini giriniz: ");
	scanf("%d",&temp -> yemekGramaji);
	printf("\n\t\t\tyemegin fiyatini giriniz: ");
	scanf("%f", &temp -> yemekFiyati  );
	
	return temp;
}






void DosyayaEkle(node * temp){
	
	FILE *fp;
	fp=fopen("yemek_menusu.txt","a");	
	
	if(fp==NULL){
        fprintf(stderr,"dosya acilamadi");
    }
    fprintf(fp,"%s %d %.2f \n",temp ->yemekAdi,temp -> yemekGramaji,temp-> yemekFiyati );
    fclose(fp);
    
	}


	
	
	
	
		void EkleSirali(node * temp)
	{
		if(root == NULL)
		{
			root = temp;
			root -> next = root;
			ptr = root;	
				
		}		
	
		else if(root -> yemekFiyati >= temp -> yemekFiyati)
		{
			temp -> next = root;
			ptr -> next = temp;
			root = temp;
			
		}
		else
		{
			node * iter = root;
				while (iter -> next !=root && iter -> next -> yemekFiyati < temp -> yemekFiyati){
					iter = iter -> next;
				}
						
			temp -> next = iter -> next;
			iter -> next = temp;
						
		}
	
	}








void Sil(){
node * iter = root-> next;
node * temp =  NULL;
char yemek[255];
printf("\n\t\t\tSilinecek Yemegin ismini yaziniz: ");
scanf("%s",yemek);

	if(!strcmp( yemek , root -> yemekAdi)){
		temp = root;
		root = root -> next;
		free(temp);
		goto git;
	}
	
	while(iter-> next !=root && strcmp( yemek ,iter -> next -> yemekAdi))
	{
		iter = iter->next;
	}
	
	
	if(iter -> next == root){
			printf("sayi listede yok");
	return;
	}
temp = iter -> next;
	if(temp == ptr){
			ptr = iter; 
		}
	iter ->  next = iter -> next -> next;
	free(temp);	
	
	
	git:	
printf ("\n\t\t\tYemek Basariyla Silindi");
printf("\n\t\t\t___________________________________________\n\n");
FILE *fp;
fp = fopen("yemek_menusu.txt","w");

temp = root;
fprintf(fp,"%s %d %.2f \n",temp ->yemekAdi,temp -> yemekGramaji,temp-> yemekFiyati );
temp = temp -> next;
while(temp != root){
	 fprintf(fp,"%s %d %.2f \n",temp ->yemekAdi,temp -> yemekGramaji,temp-> yemekFiyati );
	 temp = temp -> next;
}
fclose(fp);
}











int main()
{
	int secim;
	FILE * fp;
	fp = fopen("yemek_menusu.txt","r");
	node * temp;
		while(!feof(fp)){
			temp = (node *)malloc(1*sizeof(node));
			fscanf(fp,"%s %d %f ",&temp ->yemekAdi,&temp -> yemekGramaji,&temp-> yemekFiyati );
			EkleSirali(temp);
		}
	
	

	while(1){
	printf("\t\t\t\t=======Islem Seciniz=======\n\n\n");
	printf("\n\t\t\t1-ekleme\n");
	printf("\n\t\t\t2-silme\n");
	printf("\n\t\t\t3-listeleme\n");
	printf("\n\t\t\t4-yemek secimi\n");
	printf("\n\t\t\t5-cikis\n");
	printf("\n\t\t\t___________________________________________\n\n");
	printf("\n\t\t\t :");
	scanf("%d",&secim);
	
		switch(secim){
			case 1:
				temp = (node *)malloc(1*sizeof(node));
				temp = BilgiAl();
				EkleSirali(temp);
				DosyayaEkle(temp);
				printf("\n\t\t\tYemek Basariyla Eklendi");
				printf("\n\n\t\t\t___________________________________________\n\n");
				break;
		
			case 2:
				Sil();
				break;
			
			case 3:
				
				Listele();
				printf("\n\t\t\t___________________________________________\n\n");
				break;
		
			case 4:
				
				
				node * iter = root;
				
				
				printf("\n\t\t\tYemek secimi icin 'e'\n \n\t\t\tbir sonraki yemek icin 'h'\n\n\t\t\tana menuye donmek icin 'a' degerinin girininiz\n");
				printf("\n\n\t\t\t%s  %d  %.2f tl(e/h/a): ",iter->yemekAdi,iter->yemekGramaji,iter->yemekFiyati);
				
				while (1)
				{
				
					char karakter = 'h';
					scanf("%c",&karakter);
					
					switch(karakter){
					
					
					case 'h':
						iter = iter -> next;
						printf("\n\t\t\t%s  %d  %.2f tl(e/h/a):",iter->yemekAdi,iter->yemekGramaji,iter->yemekFiyati);
						break;
					case 'e':
						printf("\n\t\t\t%s Siparisiniz en kisa zamanda teslim edilecektir.\n",iter->yemekAdi);
						printf("\n\t\t\t___________________________________________\n\n");
						goto git;
					break;
					
					
					
					
					}
					if(karakter =='a')break;
					
				}
			break;
		
		}
		git:
		if(secim==5)break;
	}
		
		
return 0;
}
