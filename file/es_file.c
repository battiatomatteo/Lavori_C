#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 25

/*prototipi delle funzioni*/
int parola_valida(char*,int,int);
int conta_valide(int,int);

int main(){
	int num;
	int ncar, ncifre;
	scanf("%d",&ncar);
	scanf("%d",&ncifre);
	num=conta_valide(ncar,ncifre);
	printf("%d\n",num);

}


int parola_valida(char *s1, int n, int k){
    int l = strlen(s1), count = 0 ;
    if( l < n ) return 0;
    for(int i = 0; i < l ; i++){
        if(s1[i] >= '0' && s1[i] <= '9'){
            count ++;
        }
    }
    if(count >= k ) return 1;
    return 0;
 
}

int conta_valide(int n, int k){
	FILE *fp = fopen("origine.txt", "r");
    if(fp == NULL){
        printf("Errore apertura file\n");
        return -1;
    }

    char str[DIM+1];
    int count = 0;
    while(fgets(str, DIM+1, fp) != NULL){
        count += parola_valida(str, n, k);
    }
	return count ;
}
