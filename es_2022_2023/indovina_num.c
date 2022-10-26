#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool controllo(int num1, int num){
  if(num1==num){
    return true;
  }
  return false;
}
int indovina(bool con, int num1, int num2, int i){
  if(con==true){
    printf("hai indovinato\n");
    printf("Il numero era %d", num1);
  }
  else{
    if(num1>num2) printf("Hai inserito un numero più piccolo\n");
    else printf("Hai inserito un numero più grande\n");
  }
  printf("Hai ancora %d tenattivi\n", 5-i);
  printf("\nProva ad indovinare: ");
  scanf("%d", &num2);
  return num2;
}
int main(void) {
  int num1, num2;
  bool con=false;
  srand ((unsigned) time (NULL));
  num1= rand()%8999+1000;

  printf("Prova ad indovinare (hai 6 tentativi): ");
  scanf("%d", &num2);

  for(int i=0; i<5; i++){
    con=controllo(num1, num2);
    num2=indovina(con, num1, num2, i);
  }
  printf("Il numero era %d", num1);
  return 0;
}