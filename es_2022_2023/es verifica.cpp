#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampa(int matrice [7] [7]);
void simmetrica(int matrice [7] [7]);

void stampa(int matrice [7] [7]){
  int somma=0, prec=0, riga=0, colonna=0;
  printf("Matrice:\n");
  printf("\n");
  for(int y=0; y<7; y++){
    for (int x=0; x<7; x++){
      printf("%d " ,  matrice[y] [x] );
      if(y==x){
        somma+=matrice[y][x];
      }
      if(matrice[y][x]>prec){
        prec=matrice[y][x];
        riga=y;
        colonna=x;
      }
    }
    printf("\n");
  }
  printf("\n");
  printf("La somma dei numeri nella diagonale principale è: %d .\n", somma);
  printf("Il numero massima è: %d in riga %d nella colonna %d .", prec, riga, colonna);
}

void simmetrica(int matrice [7] [7]){
  for(int y=0; y<7; y++){
    for (int x=0; x<7; x++){
      if((matrice[y] [x]==matrice[x] [y]) && (x!=y)){
        printf("\nIl numero in posizione (%d;%d) è uguale al numero in posizione (%d;%d) .", y, x, x, y);
      }
    }
  }
}

int main(void) {
  int matrice[7] [7], num;
  srand ((unsigned) time (NULL));
  for(int y=0; y<7; y++){
    for (int x=0; x<7; x++){
      //printf("Inserire numero: ");
      //scanf("%d", &num);
      //matrice[y] [x] = num;
      matrice[y] [x] =rand()%30+1;
    }
  }
  stampa(matrice);
  simmetrica(matrice);
  return 0;
}
