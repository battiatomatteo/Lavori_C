/*
Completare il programma che stampa a video coppie di lettere e un numero a partire da stringhe presenti in un file. In particolare, si definisca:

Il sottoprogramma estrai che prende in input una stringa e restituisce al chiamante la distanza, secondo l'ordine alfabetico, in valore assoluto tra
la prima lettera minuscola incontrata e l’ultima (non si verificherà MAI che la stringa in ingresso non consenta di trovare lettere minuscole). 

Alcuni esempi:
Input	Output
1Afc2     	3 (f e c distano 3)
PGRastueVWX   	4
41Bec3d4ezF      	21
123yUCHET	 0 (y e y distano 0)

il sottoprogramma ricorsivo conta che riceve come input un intero e restituisce quante cifre pari contiene il numero in input (es. 256 restituisce 2).
Per esempio, se in un file sono presenti le parole 1Afc2  PGRastueVWX 41Bec3d4ezF 123yUCHET a video dal main verrà stampato:

3      f    c   0
4      a    e    1 
22    d   z    2
0      y   y    1

3 (distanza tra f e c) f (primo carattere minuscolo della stringa) c (ultimo carattere minuscolo della stringa) 0 (numero di cifre pari in 3) etc.
*/


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
			printf("%d %c %c %d\n",num, p, u, conta(num));

			fscanf(fid,"%s",str2);
		}
		fclose(fid);
	}
	return 0;

}

//funzione che estrae un numero da una stringa, salva nel parametro prima la prima lettera minuscola trovata e in ultima l'ultima
int estrai(char *s1, char *prima, char *ultima){


}


// FUNZIONE RICORSIVA che conta le cifre pari
int conta(int n){
    if(n==0) return 1;
	
}
