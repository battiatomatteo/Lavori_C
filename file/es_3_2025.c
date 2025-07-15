#include <stdio.h>
#include <stdlib.h>
typedef struct nodo{
	int num;
	struct nodo *next;
}node;


//prototipi, è possibile aggiungere funzioni
void visualizza(node *);
node* unione(node *, node*);
node* inserisciincoda(node*, int);

int main(){
	node *l1=NULL;
	node *l2=NULL;
	node *l;
	int val;
	
	scanf("%d",&val);
	while(val!=-99){
		l1=inserisciincoda(l1,val);
		scanf("%d",&val);
	}
	visualizza(l1);	
	scanf("%d",&val);
	while(val!=-99){
		l2=inserisciincoda(l2,val);
		scanf("%d",&val);
	}
	visualizza(l2);
	
	l=unione(l1,l2);
	visualizza(l);
	
	return 0;
}


void visualizza(node* lista){
  while(lista != NULL){
    if(lista->next!= NULL)
		printf("%d -> ", lista->num);
	else 
		printf("%d", lista->num);
    lista = lista->next;
  }
  printf("\n");  
}


node* inserisciincoda(node* lista, int num){
  node* copyOfList = lista;

  node* nuovoNodo = (node*) malloc(sizeof(node));
  
  if(nuovoNodo == NULL){
    printf("Errore allocazione memoria\n");
    return copyOfList;
  }

  nuovoNodo ->num = num;

  if(copyOfList == NULL){
    return nuovoNodo;
  }

  while(copyOfList->next != NULL){
    copyOfList = copyOfList->next;
  }

  copyOfList->next = nuovoNodo;
  return copyOfList;
}



node* unione(node *l1, node *l2){
	
    node* newList = l1;
    if(newList == NULL){ 
        printf("Errore allocazione memoria\n");
        return NULL;
    }

    for(int i = 0; i < strlen(l1); i++) {
        if(l1->num % 2 != 0) return l1;
    }
	
	return l1;
}


