#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
bool cambio_segno = false; //se è stato cambiato di segno 


//{[(a-b) * (c+d)] + [(d-b) - (c / a)]}*(d+a)^2
/*    a       b          c        d        e
          f                  g          e
                      padre
*/

//se la variabile è negativa viene cambiata di segno(vero = cambiato, falso = non cambiato)
int cambioSegno(int r){
  if(cambio_segno==true) {
        r=r*(-1);
        cambio_segno = false;
      }
  return r;
}

int main(void) {
  pid_t pid1, pid2, pid3, pid4, pid5;
  int a, b, c, d;
  int stato;
  printf("Inserire a = ");
  scanf("%d", &a);
  printf("\n");
  printf("Inserire b = ");
  scanf("%d", &b);
  printf("\n");
  printf("Inserire c = ");
  scanf("%d", &c);
  printf("\n");
  printf("Inserire d = ");
  scanf("%d", &d);

  pid1 = fork();
  if(pid1>0){
    //padre
    pid3=fork();
    if(pid3>0){
      //padre
      pid4=fork();
      if(pid4>0){
        //padre
        waitpid(pid1, &stato, 0);
        int risf1 = WEXITSTATUS(stato);
        waitpid(pid4, &stato, 0);
        risf1= cambioSegno(risf1);
        int risf3 = WEXITSTATUS(stato);
        waitpid(pid3, &stato, 0);
        risf3= cambioSegno(risf3);
        int risf2 = WEXITSTATUS(stato);
        risf2= cambioSegno(risf2);
        int ristot= (risf1+risf2)*risf3;
        printf("\nIl risultato dell'espressione è : %d", ristot);
      }
      else{
        //figlio 3
        int r5 = (d+a)*(d+a);
        printf("\nr5 = %d", r5);
        if(r5>250) r5=250;
        exit(r5);
      }
    }
    else{
      //figlio 2
      pid5=fork();
      if(pid5>0){
        //figlio2
        waitpid(pid5, &stato, 0);
        int r3 = WEXITSTATUS(stato);
        r3 = cambioSegno(r3);
        int r4 = c/a;
        int r34= r3-r4;
        printf("\nris34 = %d", r34);
        if(r34>250) r34=250;
        if(r34<0) cambio_segno= true;
        exit(r34);
      }
      else{
        //nipote2
        int r3 = d-b;
        //r3 = r3*(-1);
        if(r3>250) r3=250;
        if(r3<0) cambio_segno= true;
        exit(r3);
      }
    }
  }
  else{
    //figlio1
    pid2=fork();
    if(pid2>0){
      //figlio1
      waitpid(pid2, &stato, 0);
      int r1 = WEXITSTATUS(stato);
      r1= cambioSegno(r1);
      int r2 = c+d;
      int r12= r1*r2;
      if(r12>250) r12=250;
      if(r12<0) cambio_segno= true;
      printf("\nris1 = %d", r12);
      exit(r12);
    }
    else{
      //nipote1
      int r1= a-b;
      if(r1>250) r1=250;
      if(r1<0) cambio_segno= true;
      exit(r1);
    }
  }
  return 0;
}