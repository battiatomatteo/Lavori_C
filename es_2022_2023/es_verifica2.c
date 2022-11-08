#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void nuovo_vet(int vet[],int nvet[], int  nl, int num1, int num2 );
void sposta(int terzo_vet[], int nl);

void stampa(int terzo_vet[], int nl){
    printf("terzo vettore:\n");
	for(int x=0;x<nl; x++){
		printf("%d ", terzo_vet[x]);
	}	
}

void nuovo_vet(int vet[],int nvet[], int  nl, int num1, int num2 ){
	int terzo_vet[nl];
	for(int c=0; c<num1; c++){
		terzo_vet[c]=vet[c];
	}
	for(int o=0; o<num2; o++){
		num1=num1+1;
		terzo_vet[num1]=nvet[o];
	}
	stampa(terzo_vet, nl);
}

int main(void) {
  int  num1, num2, nnum=0, prec=0, nl=0;
  printf("inserire grandezza vettore (deve essere massimo 20): ");
  scanf("%d", &num1);
  printf("inserire grandezza vettore (deve essere massimo 20): ");
  scanf("%d", &num2);
  int vet[num1], nvet[num2];
  
  srand ((unsigned) time (NULL));
  
  if(num1<=20 && num2<=20){
    printf("primo vettore:\n");
  	for(int i=0; i<num1; i++){
  		printf("inserire un numero mggiore del precedente: ");
  		scanf("%d", &nnum);
  		if(nnum>prec){
  			vet[i]= nnum;
  			prec=nnum;
		}
    	else{
    		printf("hai sbagliato\n");
    		i--;
		}
  	}
  	prec=0;
    printf("secondo vettore:\n");
  	for(int x=0; x<num2; x++){
  		printf("inserire un numero mggiore del precedente: ");
  		scanf("%d", &nnum);
  		if(nnum>prec){
  			nvet[x]= nnum;
  			prec=nnum;
		}
    	else{
    		printf("hai sbagliato!\n");
    		x--;
		}
  	}
  }
  else{
  	printf("Hai sbagliato ad inserire la grandezza dei vettori!!");
  }
  
  nl= num1+num2;
  nuovo_vet(vet, nvet, nl, num1, num2 );
  
  return 0;
}