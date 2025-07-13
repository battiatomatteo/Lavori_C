#include<stdio.h>
#define DIM 10

/* prototipi */
int crea(int *,int *);
int somma(int);

int crea(int *ar1, int *ar2){
    int som = 0, flag = 0, count =0 ;
    for(int i  = 0; i< DIM ; i++){
        som = somma(ar1[i]);
        for(int j = 0 ; j < DIM; j++){
            if(som == ar2[j]){
                flag =1;
            }
        }
        if(flag == 0){
            ar2[i] = som;
            count++;
        }else flag = 0;
    }
    return count;
}

int somma(int n) {
    if (n == 0) return 0;
    return (n % 10) + somma(n / 10);
}

int main() {
  int ar1[DIM], ar2[DIM], i,r;
	for(i=0; i<DIM; i++){
		scanf("%d",&ar1[i]);
	}
  r=crea(ar1,ar2);
  printf("%d",r);
  
  return (0);
}
