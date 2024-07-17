#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int num;
	struct node* next_node;
} Node;

Node* end_insertion(Node* par_list, int par_num) {
	// Copy of par_list, used to reach end of list
	Node* final_node = par_list;
	// Creating new node to insert, with mem allocation
	Node* new_node = (Node*)calloc(1, sizeof(Node));  // no malloc , allocazione memoria
	// Checking if mem allocation failed
	if (new_node == NULL){
		printf("Memory allocation failed\n");   // errore di allocazione 
		return par_list;
	}

	new_node->num = par_num;
	// If par_list is a fresh list (empty)
	if (par_list == NULL){
		return new_node;
	}

	// Going at the end of the list
	while(final_node->next_node != NULL){
		final_node = final_node->next_node;
	}

	final_node->next_node = new_node;
	return par_list;
}

Node* front_insertion(Node* par_list, int par_num){    // inserisco un nodo prima del primo nodo già esistente 
	Node* new_node = (Node*)calloc(1, sizeof(Node));
	if (new_node == NULL){
		printf("Memory allocation failed\n");
		return par_list;
	}

	new_node->num = par_num;
	new_node->next_node = par_list;

	return new_node;
}

Node* ordered_insertion(Node* par_list, int par_num){
	// Copy of par_list, used to reach point of list
	// in which par_num is >= than par_list->num
	Node* final_node = par_list;
	Node* new_node = (Node*)calloc(1, sizeof(Node));
	if (new_node == NULL){
		printf("Memory allocation failed\n");
		return par_list;
	}

	new_node->num = par_num;   // gli do il nomero da inserire nel nodo

	if(par_list == NULL){
		return new_node;
	}

	while(final_node->num < par_num){  // fino a quando il numero che gli sto passando è maggiore del numero del nodo a cui sto puntando 
		final_node = final_node->next_node;
	}

	Node* rest_of_list = final_node->next_node;
	final_node->next_node = new_node;
	new_node->next_node = rest_of_list;

	return par_list;
}

Node* remove_node_first_occurrence(Node* par_list, int par_num){
	Node* cursor = par_list;
	Node* previous;   // dichiaro nodo precedente

	if(par_list == NULL){
		return par_list;
	}

	while(cursor->num != par_num){
		previous = cursor;
		if(cursor->next_node == NULL){ // il numero non è presente nella lista 
			return par_list;
		}
		cursor = cursor->next_node;   // scorro in avanti 
	}

	previous->next_node = cursor->next_node;    // salvo il nodo precedente e gli dico che punta al sucessivo di quello che viene tolto 
	free(cursor);  // tolgo il nodo col numero ( il contrario di alloc )
	return par_list;
}

void view_list(Node* par_list) {  // visualizza 
	if(par_list == NULL) {
		printf("List is null\n");
	} else {
		while(par_list->next_node != NULL) {
			printf("%d ", par_list->num);
			par_list = par_list->next_node;
		}
		printf("\n");
	}
}

void free_list(Node* par_list) {    // libero la lista
	Node* temp;     // creo un nodo temporaneo 
	if(par_list == NULL) {
		printf("The list is NULL\n");
		return;
	}
	while(par_list->next_node != NULL) {
		temp = par_list;                         // copio il puntatore principale che punta il primo nodo
		par_list = par_list->next_node;          // sposto in avanti di uno il puntatore principale
		free(temp);                              // cancello il nodo a cui punta il puntatore copia 
	}
}

int node_exists(Node* par_list, int par_num) {     // se esiste il nodo che sto cercando
	int flag = 0;
	if(par_list == NULL){
		return flag;
	}
	while(par_list->next_node != NULL){
		if(par_list->num == par_num){
			flag = 1;
			return flag;
		}
		par_list = par_list->next_node;
	}
}

int max_node_number(Node* par_list) {
	int max_number = 0;
	if(par_list == NULL){
		return 0;
	}
	while(par_list->next_node != NULL){
		if(par_list->num > max_number){
			max_number = par_list->num;
		}
		par_list = par_list->next_node;
	}
	return max_number;
}




int main() {
	int num = 0;
	Node* lista;
	lista = end_insertion(lista , num);

	return 0;
}