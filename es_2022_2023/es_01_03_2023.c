#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

//[(15/5) * (4-1)] + [(49+51) - (30 * 3)]
//    1       2           3         4
int main(void) {
  int stato;
  pid_t pid1, pid2, pid3, pid4;
  clock_t inizio , fine;
  inizio= clock();
  pid1= fork();
  if(pid1>0){
    //padre
    pid2= fork();
    if(pid2>0){
      //padre
      pid2= waitpid(pid2, &stato, 0);
      int r = WEXITSTATUS(stato);
      int l= 30*3;
      int f= r-l;
      pid1= waitpid(pid1, &stato, 0);
      int t = WEXITSTATUS(stato);
      int ris= t+f;
      printf("risultato : %d", ris);
    }
    else{
      //figlio 2
      int d = 49+51;
      exit(d);
    }
  }
  else{
    //figlio 1
    pid3= fork();
    if(pid3>0){
      //figlio 1
      pid3= waitpid(pid3, &stato, 0);
      int q = WEXITSTATUS(stato);
      int b=4-1;
      int c = b*q;
      exit(c);
    }
    else{
      //nipote 1
      int a = 15/5;
      exit(a);
    }
  }
  fine = clock();
  double total = ((double)(fine-inizio))/60 ;
  printf("\ntempo esecuzione : %.2f", total);
  return 0;
}
