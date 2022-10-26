#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char vet[], int i, char val, int p);
int pop(char array[]);
int lunghezza(char vet[]);
void carica(char* elemento, char* pila);


void push(char vet[], int i, char val, int p){
  vet[i-p] = val;
  
}

int pop(char vet[]){
  int ris = 0, o=0;
  char val2;
  
  for(int y=0; y< lunghezza(vet); y++)
    if((vet[y]=='+') || (vet[y]=='-') || (vet[y]=='*') || (vet[y]=='/')){
      o=y;
      val2 = vet[o+1];
      vet[o+1] = vet[o];
      vet[o]= val2;
      if(vet[o]=='+') ris = vet[o-1] + vet[o];
      else if(vet[o]=='-') ris = vet[o-1] - vet[o];
      else if(vet[o]=='*') ris = vet[o-1] * vet[o];
      else if(vet[o]=='/') ris = vet[o-1] / vet[o];
    }
  return ris;
}

int lunghezza(char vet[]){
  return strlen(vet);
}

void carica(char* elemento, char* pila){
  int p=0;
  for(int i = 0; i < lunghezza(elemento); i++){
      char car = elemento[i];
      if((car != '(') && (car != ')')){
          push(pila, i, car, p);
      }
      else{
        p++;
      }
  }
  
  //stampo tutto senza le parentesi
  for (int x=0; x<lunghezza(pila); x++){
    printf("%c ", pila[x]);
  }

  int ris = pop(pila);
  printf("\n");

  //stampo tutto senza operandi
  for (int x=0; x<lunghezza(pila); x++){
    printf("%c, ", pila[x]);
  }

  printf("\n %d", ris);
  
} 

int main(void)
{
  char elemento[100], pila;

  printf("Inserisci la prima esperessione: ");
  scanf("%s", &elemento);

  char pila1[lunghezza(elemento)];
  carica(elemento, pila1);

  return 0;
}