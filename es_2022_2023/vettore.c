#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int sostituzione(int vettore[], int pot, int ris, int ind){
    for(int x=0; x<10; x++){
        if(vettore[x] % 2 == 0){
            vettore[x]= 0;
        }
        else{
            vettore[x]= 1;
            ind = (9-x);
            pot = (int) pow(2, ind);
            printf("indice %d \n", ind);  
        }
        ris += pot;
        pot=0;
    }
    for(int w=0; w<10; w++){
        printf("%d ", vettore[w]);
    }
    return ris;
}

int main(void) {
    int vettore[10];
    int pot=0, ris=0, ind=0;
    srand ((unsigned) time (NULL));
    for(int j=0; j<10; j++){
        vettore[j]= rand()%10;
    }
    ris = sostituzione(vettore, pot, ris, ind);
    printf("\n%d", ris);
    return 0;
}