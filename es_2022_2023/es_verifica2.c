#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void nuovo_vet(int vet[],int nvet[] int  nl, int num1, int num2 );

void nuovo_vet(int vet[],int nvet[] int  nl, int num1, int num2 ){
	int terzo_vet[nl];
	for(int c=0; c<num1; c++){
		terzo_vet[c]=vet[c];
	}
	for(int o=0; o<num1; o++){
		num1=num+1
		terzo_vet[num1]=vet[o];
	}
	stampa(terzo_vet, nl);
}
void stampa(int terzo_vet[], int nl){
	for(int x=0;x<nl; x++){
		printf("%d", terzo_vet[x]);
	}	
}

int main(void) {
  int  num1, num2, nnum=0, prec=0;
  printf("inserire grandezza vettore (deve essere massimo 20)");
  scanf("%d", &num1);
  printf("inserire grandezza vettore (deve essere massimo 20)");
  scanf("%d", &num2);
  int vet[num1], nvet[num2];
  
  srand ((unsigned) time (NULL));
  if(num1<=20 && num2<=20){
  	for(int i=0; i<num1; i++){
  		printf("inserire un numero mggiore del precedente");
  		scanf("%d", &nnum);
  		if(nnum>prec){
  			vet[i]= nnum;
  			prec=nnum;
		}
    	else{
    		printf("hai sbagliato");
    		i--;
		}
  	}
  	prec=0;
  	for(int x=0; x<num2; x++){
  		printf("inserire un numero mggiore del precedente");
  		scanf("%d", &nnum);
  		if(nnum>prec){
  			nvet[x]= nnum;
  			prec=nnum;
		}
    	else{
    		printf("hai sbagliato");
    		i--;
		}
  	}
  }
  else{
  	printf("Hai sbagliato ad inserire la grandezza dei vettori!!");
  	
  }
  int nl= num1+num2;
  nuovo_vet(vet, nl, num1, num2 );
  
  return 0;
}
