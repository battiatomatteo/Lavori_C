#include <stdio.h>
#include <string.h>
#define DIM 25

/*prototipi delle funzioni*/
int parola_valida(char*,int,int);
int conta_valide(int,int);


// restituisce 1 se la stringa ricevuta in ingresso è lunga almeno n caratteri e contiene almeno k cifre (caratteri numerici), 0 altrimenti.
int parola_valida(char *s1, int n, int k){ 
  char anum[] = {'1', '2','3','4','5','6','7','8','9','0'};
  int nump = 0, numc = 0;
  int l = strlen(s1) ;
  while( nump != l ){//conto per vedere se la parola è lunga almeno n caratteri
    //aumento i contatori
    nump ++;
    for(int i=0; i <10; i++) if ( s1[nump] == anum[i] ) numc ++;
  }
  if ((nump>= n) && (numc >= k)) return 1;
  else return 0;
}


//apre il file "origine.txt" che contiene un insieme di parole, e restituisce il numero delle parole valide (ovvero che contengono almeno n caratteri e almeno k cifre)
int conta_valide(int n, int k){
  FILE *f;
  
  f = fopen("origine.txt", "r");  //apro il file in lettura
  
  char s1[DIM];
  int count = 0 ;

  if(f == NULL) {
    printf("\nNot able to open the file.\n");
  }
  else{
    while(fgets(s1, DIM, f)){ 
      count += parola_valida(s1, n, k);
    }
  }


  fclose(f);  //chiudo il file

  return count;
}


int main(){
  int num = 0;
  int ncar, ncifre;
  //printf("ciao\n");
  scanf("%d", &ncar);
  scanf("%d", &ncifre);
  //printf("%d \n%d \n", ncar, ncifre);
  num=conta_valide(ncar,ncifre);
  
  printf("%d\n",num);
  
  return 0;
}
