
#include <stdio.h> 
#include <conio.h> 
#include <stdio.h>

int main()
{
int i[10], j;
int *iptr;

for (j=0; j<10; j++)
    i[j]=j;

iptr = i;
printf("\n (1) iptr'nin adresi.....:%p\n",iptr);
for (j=0; j<10; j++) 
{
   printf("%d ", *iptr);
   iptr++;
}

printf("\n (2) iptr'nin adresi.....:%p\n",iptr);

/* iptr artýk dizinin baþýný göstermez */

iptr = i; // iptr tekrar dizinin baþlangýç adresini gösterir.
printf("\n (3) iptr'nin adresi.....:%p\n",iptr);
for (j=0; j<10; j++)
    printf("%d ", *(iptr+j));

printf("\n (4) iptr'nin adresi.....:%p\n",iptr);;

/* iptr hala dizinin baþýný gösterir */

getch();
return 0;
}

