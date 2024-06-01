#include <stdio.h>
#include <string.h>

char phone_num[10]; 
//Her rakama karsilik gelen harfi veren map
char mapping[8][4] = {
  {'A', 'B', 'C'},//2 
  {'D', 'E', 'F'},//3
  {'G', 'H', '�'},//4 
  {'J', 'K', 'L'},//5 
  {'M', 'N', 'O'}, //6
  {'P', 'Q', 'R', 'S'},//7 
  {'T', 'U', 'V'},//8 
  {'W', 'X', 'Y', 'Z'}//9 
};

void print_combinations(char *combination, int index) {
  // Girilen numaradaki rakamlar�n sonuna ula��lm��sa kombinasyonu bast�r
  if (index == strlen(phone_num)) {
    printf("%s\n", combination);
    return;
  }

  // Mevcut basamak i�in b�t�n olas� harfleri dene
  //2 ��kar�lma sebebi harf kar��l��� olan rakamlar�n ilk iki rakamda bulunmamas�
  if (phone_num[index] >= '2' && phone_num[index] <= '9') {
    for (int i = 0; i < strlen(mapping[phone_num[index] - '2']); i++) {
      combination[index] = mapping[phone_num[index] - '2'][i];
      //rek�sif ile ibr sonraki index e ge�
      print_combinations(combination, index + 1);
    }
  }
}

int main() {
  printf("0-1 Kullanmadan bir numara giriniz : ");
  scanf("%s", phone_num);

  char combination[strlen(phone_num) ];
  print_combinations(combination, 0);

  return 0;
}


