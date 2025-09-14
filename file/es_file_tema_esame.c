#include <stdio.h>
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

/** 
 * input stringa s1, int n, int k 
 * output 1 if s1 --> s1.strlen() >= n && k >= num caratteri numerici in s1
 * output 0 altrimenti
 */
int parola_valida(char *s1, int n, int k){
    int countk = 0;
    int l = strlen(s1) - 1;
    //printf("lunghezza %d\n", l);
    if(l < n){
        return 0;
    }

    for(int i = 0; i<l; i++){
        if(s1[1] >= '0' && s1[i] <= '9'){
            countk ++;
        }
    }
    //printf("numero cifre %d\n", countk);
    if(countk >= k){
        return 1;
    }else{
        return 0;
    }
}

/** 
 * Apre il file che contiene un inseme di parole 
 * input int n, int k 
 * output num parole valide 
 */
int conta_valide(int n, int k){
    int count = 0;
	FILE *fp = fopen("origine.txt","r");

    if(fp == NULL){
        printf("Errore nell'apertura del file\n");
        return -1;
    }

    char s1[DIM];

    while(fgets(s1, 25, fp)){
        //printf("parola: %s\n", s1);
        if(parola_valida(s1, n, k)){
            count++;
        }
    }
	
    fclose(fp);
    return count;
}
