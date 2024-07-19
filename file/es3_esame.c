#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int num;
    struct nodo *next;
}node;

// * prototipi, è possibile aggiungere funzioni
void visualizza(node *);
node* unione(node *, node*);
node* inserisciincoda(node*, int);

int main(){
    node *l1 = NULL;
    node *l2 = NULL;
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

        if(lista->next!= NULL) printf("%d -> ", lista->num);
        else printf("%d", lista->num);

        lista = lista->next;
    }

    printf("\n");
}

node* inserisciincoda(node* lista, int num){   // ! inserisco in coda alla lista 
    node* ultimo_nodo = lista;
    node* nuovo_nodo  = (node*)calloc(1,sizeof(node));    // ! alloco memoria 

    if(nuovo_nodo == NULL){
        printf("errore allocazione memoria.");
        return lista;
    }

    nuovo_nodo->num = num;      // * inserisco il numero nel nuovo nodo 

    if(lista == NULL) return nuovo_nodo;    // * se la lista è piena ritorno il nuovo nodo

    while(ultimo_nodo->next != NULL){   // * mi sposto fino alla fine della lista
        ultimo_nodo = ultimo_nodo->next;     // * passo al nodo sucessivo 
    }

    ultimo_nodo->next = nuovo_nodo;   // * il nuovo nodo appena creato è l'ultimo 
    return lista;   // * ritorno la lista 

}

node* unione(node *l1, node *l2){   //! unione delle due liste 
    int n1 = 0, v =100, flag = 0;
    int lista_dispari [v] ;
    node* l_n = NULL;   
    node* ultimo_nodo_l1 = l1;
    node* ultimo_nodo_l2 = l2;
    // ? node* nuovo_nodo  = (node*)calloc(1,sizeof(node));    // * alloco memoria per la nuova lista 


    while(ultimo_nodo_l1 != NULL || ultimo_nodo_l2 != NULL){   // ! fino a quando non ho finito entrambe le liste 
        if(ultimo_nodo_l1->num > ultimo_nodo_l2->num){   
            if( ultimo_nodo_l2->num %2 == 0){  // ! se il numero è pari nessun problema 
                l_n = inserisciincoda(l_n, ultimo_nodo_l2->num);   // * inseriesco in coda 
            }
            else{ // ! controllo se il numero dipari è gia presente nella lista 
                for(int o = 0; (o < v ) && (flag == 0) ; o++) {
                    if( ultimo_nodo_l2->num == lista_dispari[o]) flag = 1;   // * scorro la lista lista_dispari , se lo trovo allora alzo il flag 
                    n1 = o;      // * esco dal ciclo 
                }
                if(flag == 0){   // * nel caso in cui il numero da inserire non è presente nella lista_dispari proseguo con l'inserimento in coda 
                    lista_dispari[n1] = ultimo_nodo_l2->num;   // * inser
                    l_n = inserisciincoda(l_n, ultimo_nodo_l2->num);
                    ultimo_nodo_l2 = ultimo_nodo_l2->next;   // * passo al nodo sucessivo
                }
                flag = 0;
                n1 = 0; 
            }
        }
        else{
            if( ultimo_nodo_l1->num %2 == 0){  // ! se il numero è pari nessun problema 
                l_n = inserisciincoda(l_n, ultimo_nodo_l1->num);   // * inseriesco in coda 
            }
            else{ // ! controllo se il numero dipari è gia presente nella lista 
                for(int o = 0; (o < v ) && (flag == 0); o++) {
                    if( ultimo_nodo_l1->num == lista_dispari[o]) flag = 1;   // * scorro la lista lista_dispari , se lo trovo allora alzo il flag 
                    n1 = o;
                }
                if(flag == 0){   // * nel caso in cui il numero da inserire non è presente nella lista_dispari proseguo con l'inserimento in coda 
                    lista_dispari[n1] = ultimo_nodo_l2->num;   // * inser
                    l_n = inserisciincoda(l_n, ultimo_nodo_l1->num);
                    ultimo_nodo_l1 = ultimo_nodo_l1->next;   // * passo al nodo sucessivo
                }
                flag = 0;
                n1 = 0; 
            }
        }
        // ? nuovo_nodo = nuovo_nodo->next;               // * passo al nodo sucessivo della nuova lista
    }

    return l_n;
}