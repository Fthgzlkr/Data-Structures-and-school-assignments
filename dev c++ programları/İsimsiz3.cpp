#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char mapping[10][5] = {"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

char *temp =(char*)malloc(sizeof(char)*10);


void telefon_animsaticilari(char* numara, int sayac){
	
	
	if (strlen(numara) == 0) { 	
    printf("%s ", temp);
    return;
  }
  
  
   int indis = numara[0] - '0';
   
   
   
   for (int i=0 ; i<strlen(mapping[indis]) ; i++){
   	 *(temp+sayac) = mapping[indis][i];
   	 telefon_animsaticilari(numara + 1, sayac+1);
   }
}

int main() {
  char numara[] = "623";
  telefon_animsaticilari(numara, 0);
  
  return 0;
}
