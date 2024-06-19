#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *next;
}  //element;

elem* inserisci_in_testa(elem* , int);
elem* distruggi(elem*);
void visualizza(elem*);

int main(int argc, char const *argv[])
{
  int num;
  elem* lista = NULL; //lista vuota 
  scanf("%d", &num);
  while(num > 0){
    while(num > 0){
      lista = inserisci_in_testa(lista, num%10);
      num = num/10;
    }
    visualizza(lista);
    lista= distruggi(lista); // LISTA SOLE CIFRE ULTIMO NUMERO LETTO
    scanf("%d", &num);
  }
  return 0;
}

elem* inserisci_in_testa(elem* lista, int n){
  elem* tmp;
  tmp = (elem*)malloc(sizeof(elem));
  if(tmp != NULL){
    tmp->num = n;
    tmp->next = lista;
    lista=tmp
  }
  return lista;
}

void visualizza(elem* l){
  while(l != NULL){
    printf("%3d", l->num);
    l = l->next;
  }
}

elem* distruggi(elem* l){
  elem* tmp;
  while(l != NULL){
    tmp = l;
    l = l->next;
    free(tmp);
  }
  return l;
}