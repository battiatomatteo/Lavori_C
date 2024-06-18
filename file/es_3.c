//la funzione stampa_lista per visualizzare una lista di interi (creata con inserimento in testa fino all'inserimento del valore -1 che non fa parte della lista).
//monotona che data la testa della lista restituisce -1 in caso di lista vuota, 1 se la lista è strettamente monotona crescente (cioè se ogni elemento è strettamente superiore al suo predecessore), 0 negli altri casi.

#include <stdio.h>
#include <stdlib.h>


struct node_t{
  int numero;
  struct node_t * next;
};

typedef struct node_t node;

node* inserisciInTesta(node*, int);
void stampa_lista(node *);
int monotona(node *);

int main()
{
   int v;
   node *lista = NULL;
   scanf("%d",&v);
   while(v!=-1){
          lista=inserisciInTesta(lista,v);
          scanf("%d",&v);
   }
   stampa_lista(lista);
   printf("\n");
   int r = monotona(lista);
   printf("%d",r); 
  return(0);
}

/*inserisce un nuovo numero in testa alla lista*/
node* inserisciInTesta(node* lista, int num){
  node *tmp;

  tmp = (node*) malloc(sizeof(node));
  if(tmp != NULL){
    tmp->numero = num;
    tmp->next = lista;
    lista = tmp;    
  } 
  return lista;
}