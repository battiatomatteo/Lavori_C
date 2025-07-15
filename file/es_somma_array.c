#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define DIM 10

/* prototipi */
int crea(int *,int *);
int somma(int);

int main() {
  int ar1[DIM], ar2[DIM], i,r;
	for(i=0; i<DIM; i++){
		scanf("%d",&ar1[i]);
	}
  r=crea(ar1,ar2);
  printf("%d",r);
  
  return (0);
}


int crea(int *a1, int *a2){
    int num = 0, flag = 0 , count_insert = 0, a2_ind = 0;
    for(int i =0 ; i< DIM ; i++){
        num = somma(a1[i]);
        // printf("somma: %d ", num);
        for(int y = 0; y < a2_ind + 1 ; y ++){
            if(a2[y] == num) flag = 1;
        }
        if( flag == 0){
            // printf("a2[a2_ind+1]: %d ", num);
            a2[a2_ind+1] = num;
            count_insert++;
            a2_ind++;
        }else flag = 0 ;
    }

     return count_insert;
}


int somma(int n){
    if(n == 0) return 0;
    else {
        return n % 10 + somma(n/10);
    }
}