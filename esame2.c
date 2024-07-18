/*

Completare il programma che stampa a video coppie di lettere e un numero a partire da stringhe presenti in un file. In particolare, si definisca:

- Il sottoprogramma estrai che prende in input una stringa e restituisce al chiamante la distanza, secondo l'ordine alfabetico, in valore 
  assoluto tra la prima lettera minuscola incontrata e l'ultima (non si verifichera' MAI che la stringa in ingresso non consenta di trovare 
  lettere minuscole). Alcuni esempi:

Input
1Afc2
PGRastueVWX
41Bec3d4ezF
123yUCHET

Output
3 (f e c distano 3)
4
21
0 (y e y distano 0)

- Il sottoprogramma ricorsivo conta che riceve come input un intero e restituisce quante cifre pari contiene il numero in input (es. 256 restituisce 2)

Per esempio, se in un file sono presenti le parole 1Afc2 PGRastueVWX 41Bec3d4ezF 123yUCHET a video del main verra' stampato:

3   f c 0
4   a e 1
22  d z 2
0   y y 1

3 (distanza tra f e c) f (primo carattere minuscolo della stringa) c (ultimo carattere minuscolo della stringa) 0 (numero di cifre pari in 3) etc.

 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_BURGER 1024

//TODO: estrai
int estrai(char* par_stringa){
	int i = 0;
	char first_letter;
	char last_letter;
	int count = 0;
	while(par_stringa[i] != '\0'){
		if(par_stringa[i] == '\n'){
			i++;
			continue;
		}
		if(par_stringa[i] >= 'a' && par_stringa[i] <= 'z'){
			if(count == 0){
				first_letter = par_stringa[i];
			}
			last_letter = par_stringa[i];
			count++;
		}
		i++;
	}

	if(first_letter == last_letter){
			return 0;
	}

	if(first_letter > last_letter){
		return first_letter - last_letter;
	} else if (first_letter < last_letter){
		return last_letter - first_letter;
	}


	return 0;
}

//TODO: conta
int conta(int par_input){
	if(par_input > 0){
		if(par_input % 2 == 0){
			return 1 + conta(par_input/10);
		}
	} else {
		return 0;
	}
}

int main(int argc, char** argv){

	FILE* file_pointer = fopen("testo_esame.txt", "r");
	char myString[MAX_BURGER];


	while(fgets(myString, MAX_BURGER, file_pointer)){
		printf("%d\n", estrai(myString));
	}
	printf("\n");

	printf("=======================\n");
	printf("%d\n", conta(2468));
	printf("=======================\n");
	

	fclose(file_pointer);

	return 0;
}