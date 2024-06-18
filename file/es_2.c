//Scrivere un programma C che apre un file di testo “testo.txt” contenente parole ciascuna di al massimo 15 caratteri (si considerino soltanto i caratteri minuscoli). Il programma trova tutte le parole con almeno tre vocali e le stampa al rovescio. Ad esempio, se il file “testo.txt” contiene il testo:

//bisogna studiare 

//Il programma visualizzerà il testo:

//angosib eraiduts 

#include<stdio.h>
#include<string.h>
#define FNAME "testo.txt"
#define MAXS 15
#define SOGLIA 3

int main(){
  int ok = 0, i, l = 0, voc = 0;
  FILE *fp;
  char p[MAXS+1];

  fp=fopen(FNAME,"r");

  if(fp == NULL) {
    printf("\nNot able to open the file.\n");
  }
  else{
    while(fgets(p, MAXS, fp)){ //salva la parola in p 
       l = strlen(p); //lunghezza della parola
       if( l<=MAXS ){
         for(i=0 ; i<l ; i++){
            if(p[i] >= 'A' && p[i] <= 'Z' ){ //CONTROLLO SE LA PAROLA E' MAIUSCOLA
               printf("\nsono presenti dei caratteri maiuscoli");
               ok = 1;
            }
           if(p[i] == 'a' || p[i] <= 'i' || p[i] == 'e' || p[i] == 'o' || p[i] == 'u'){
              voc += 1;
           }
          }
         if (ok == 0 && voc >= 3){
           for(i=l; i>=0; i--) printf("%c", p[i]); //stampa la parola al rovescio
         }
         printf("\n");
       }
      else {
        printf("\nla parola è troppo lunga");
      }
    }
  }


  fclose(fp);


}