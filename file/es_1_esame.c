#include<stdio.h>
#define N 3
#define M 4
#define K 3

int main(){
  int sum = 0;
  int mat[N][M];
  int vec[K];
  int type, i , j, k, sum2 = 0;
  
  for(i=0;i<N;i++){
  for(j=0;j<M;j++){
    scanf("%d",&mat[i][j]);
  }
  }
  for(k=0;k<K;k++){
    scanf("%d",&vec[k]);
  }
  
  scanf("%d",&type);
  //completare
  i = 0 ;
  
  if(k<=(N*M)){
    if(type == 1){
      //
      for(int y = 0 ; y<3; y++) {
        sum += vec[y];
        j =  vec[y];
        do{
          if(j<=4){
             sum2 += mat[i][j];
             k=1;
          }
          else{
            i++;
            j -= 4;
          }
        }
        while(k==1);
      }
      if(sum != sum2) sum = -1;
    }
    else{
      // da finire : somma e controllo sotto matrici fatta : manca controllo risultato 
      for(int y = 0 ; y<3; y++) {
        sum += vec[y];
        j =  vec[y];
        do{
          if(j<=4){
             sum2 += mat[i][j];
             //inizio il controllo 
             if( (i+1)>=0 ) for(int u=-1 ; u<2; u++) sum2 += mat[i+1][j+u]; // controllo sopra
             if( (i+1)<=3 ) for(int u=-1 ; u<2; u++) sum2 += mat[i+1][j+u]; // controllo sotto
             if( (j+1)<=4 ) sum2 += mat[i][j+1]; // controllo a destra
             if( (j-1)>=0 ) sum2 += mat[i][j-1]; // controllo a sinistra

             k = 0;
          }
          else{
            i++;
            j -= 4;
          }
        }
        while(k==1);
      }
    }
  }
  else sum = -1;
    
  printf("%d\n",sum);
  
  return 0;
}