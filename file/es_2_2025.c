#include<stdio.h>
#include<string.h>
#define DIM 25

/* prototipi delle funzioni */
int estrai(char *, char *, char *);
int conta(int);

int main(){
	char nome[20];
	char p,u;
	int num;
	FILE *fid;
	char str2[DIM+1];


	scanf("%s",nome);
	fid=fopen(nome,"r");
	if(fid==NULL)
		printf("Errore apertura file");
	else{
		fscanf(fid,"%s",str2);
		while(!feof(fid)){
			num=estrai(str2,&p,&u);
			if (num > 0 ) printf("%d %c %c %d\n",num,p,u,conta(num));
            else printf("%d %c %c %d\n",num,p,u,1);
			fscanf(fid,"%s",str2);
		}
		fclose(fid);
	}
	return 0;

}

//funzione che estrae un numero da una stringa, salva nel parametro prima la prima lettera minuscola trovata e in ultima l'ultima
int estrai(char *s1, char *prima, char *ultima){

    int count = 0;
    for(int u = 0; u < strlen(s1); u ++){
        if(s1[u]>= 'a' && s1[u]<= 'z'){
            if( count == 0){
                *prima = s1[u];
                count++;
                *ultima = *prima;
            }else {
                *ultima = s1[u];
            }
        }
    }
    if( *ultima > *prima) return *ultima - *prima;
    if(*ultima < *prima ) return *prima - *ultima;
    if(*ultima == *prima && count > 0) return 0;
    else if((*ultima == *prima) && count == 0 ) return 0;
    else return 0;
}


// FUNZIONE RICORSIVA che conta le cifre pari
int conta(int n){
    if(n == 0) return 0;

    // estrai l'ultima cifra
    int cifra = n % 10;

    if(cifra % 2 == 0)
        return 1 + conta(n / 10);
    else
        return conta(n / 10);
}
