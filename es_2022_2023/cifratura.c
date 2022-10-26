// cifratura a chiave sistematica
#include <stdio.h>
#define k 3

void codifica(char val[]);
void decodifica(char val[]);
int lunghezza(char vet[]);

int lunghezza(char vet[]) { return strlen(vet); }


void codifica(char val[]) {
  for (int x = 0; x < lunghezza(val); x++) {
    if (val[x] == 'Z') {
      printf("C");
    } else if (val[x] == 'Y') {printf("B");
      } else if (val[x] == 'X'){ printf("A");
        } else {
            char val_nuovo = val[x] + k;
            printf("%c", val_nuovo);
          }  
  }
}

void decodifica(char val[]) {
  for (int x = 0; x < lunghezza(val); x++) {
    if (val[x] == 'C') {
      printf("Z");
    } else if (val[x] == 'B'){ printf("Y");
      } else if (val[x] == 'A'){ printf("X");
        } else {
            char val_nuovo = val[x] + k;
            printf("%c", val_nuovo);
          }  
  }
}

int main(void) {
  char val[50];
  printf("Inserire la stringa : ");
  scanf("%s", &val);
  printf("Codifica: ");
  codifica(val);
  printf("\nDecodifica: ");
  decodifica(val);
  return 0;
}