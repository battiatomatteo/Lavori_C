#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void riempi(int vettore[], int num){
    //funzione che riempie i vettori
    for(int i=0; i<num; i++){
        vettore[i]= rand()%5+1;
    }
}

void mostra(int vettore[], int num){
    //funzione che stampa a video il contenuto dei vettori
    for(int i=0; i<num; i++){
        printf("%d ", vettore[i]);
    }
    printf("\n");
}

bool duplicati(int vettore[], int num, int l){
    /*funzione che mi ritorna un valore booleano: - false se il numero non è già presente nel vettore dei duplicati
                                                  - true se è già presente nel vettore dei duplicati*/
    for(int o=0; o<l; o++){
        if (vettore[o]==num){
            return true;
        }
    }
    return false;
}

void controllo(int vettore1[], int vettore2[], int num1, int num2){
    //funzione che controlla se il numero è presente in entrambi i vettori
    int p=0, vettore3[p], num_max, num_min, num, lv=0;
    bool ris = false;
    if (num1>num2){
        num_max=num1;
        num_min=num2;
    }
    else{
        num_max=num2;
        num_min=num1;
    }
    for (int y=0; y< num_max; y++){
        for(int w=0; w< num_min; w++){
            if(vettore1[w] == vettore2[y]){
                //printf("il numero : %d  è presente in entrambi i vettori.\n", vettore1[w]);
                num = vettore1[w];
                vettore3[p]= vettore1[w];
                ris= duplicati(vettore3, num, lv);
                if(ris == false){
                    vettore3[p]= vettore1[w];
                    printf("%d ", vettore3[p]);
                    p+=1;
                    lv+=1;
                    //lv= sizeof(vettore[p])/sizeof(vettore[0]);
                }
            }
        }
    }
}

int main(void) {
    int num1, num2;
    srand ((unsigned) time (NULL));
    printf("inserire grandezza vettore 1: ");
    scanf("%d", &num1);
    printf("inserire grandezza vettore 2: ");
    scanf("%d", &num2);

    int vettore1[num1], vettore2[num2];
    //chiamata funzioni
    riempi(vettore1, num1);
    riempi(vettore2, num2);
    mostra(vettore1, num1);
    mostra(vettore2, num2);
    controllo(vettore1, vettore2, num1, num2);
    return 0;
}