#include<stdio.h>
#include<string.h>
#define FNAME "testo.txt"
#define MAXS 15
#define SOGLIA 3

int main(){
  int ok, i;
  FILE *fp;
  char p[MAXS+1];

  fp=fopen(FNAME,"r");
  
  if(fp == NULL){
    printf("errore apertura file.");
    return 1;
  }
  int indc_spazio = 0;
  while(fgets(p, MAXS+1, fp) != NULL){
    
    for(i = 0;  i < MAXS+1; i ++){
        if(p[i] == 'a' ||  p[i] <= 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u'){
            ok ++;
        }
        if(p[i] == ' ') {
            indc_spazio = i;
            i = MAXS+1; // esco dal ciclo for
        }
    }
    if(ok >= SOGLIA){
        // posso stampare la prima stringa 
        for(int y = indc_spazio -1 ; y >= 0; y--){
            if(p[y] != '\x00' ) printf("%c", p[y]);
        }
    }

    ok = 0; // resetto il contatore
    printf(" "); // spazio tra le due stringhe
    for(int u = indc_spazio +1 ; u < MAXS+1; u++){
         if(p[i] == 'a' ||  p[i] <= 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u'){
            ok ++;
        }
    }
    if(ok >= SOGLIA){
        // posso stampare la seconda stringa 
        for(int y = MAXS+1 ; y >= indc_spazio+1; y--){
            if(p[y] != '\x00' ) printf("%c", p[y]);
        }
    }
  }
  
}