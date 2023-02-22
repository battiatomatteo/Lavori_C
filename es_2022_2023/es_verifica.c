#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampa(int vet[], int num);
void crescente(int vet[],int nvet[], int num);
void sposta(int vet[], int num);

void stampa(int vet[], int num){
	for(int x=0;x<num; x++){
		printf("%d", vet[x]);
	}
	
}

void crescente(int vet[], int nvet[], int num){
	int prec=0, w=0;
	for(int x=0;x<num; x++){
		if(prec<vet[x]){
			nvet[w]=vet[x];
			prec=vet[x];
			w+=1;
		}
	}
}

void sposta(int vet[], int num){
	int appog=0;
	for(int i = 0; i<num; i++){
		appog= vet[i];
		vet[i]=vet[i+1];
		vet[i+1]= appog;
	}
	stampa(vet, num);
}


int main(void) {
  int  num=0, nums=0;
  srand ((unsigned) time (NULL));
  prinf("inserire grandezza vettore (deve essere massimo 30)");
  scanf("%d", &num);
  int vet[num], nvet[num];
  
  if(num<=30){
  	for(int i=0; i<num; i++){
    	vet[i]= rand()%25+1;
  	}
  }
  else{
  	printf("Hai sbagliato ad inserire la grandezza del vettore!!");
  	
  }
  stampa(vet, num);
  
  crescente(vet, nvet, num);
  sposta(vet, num);
  return 0;
}
