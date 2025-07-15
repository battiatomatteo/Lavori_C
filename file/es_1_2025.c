#include<stdio.h>

#define N 3
#define M 4
#define K 3

int main(){
  int sum; 
  int mat[N][M];
  int vec[K];
  int type;
  
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&mat[i][j]);
    }
  }

  for(int k=0;k<K;k++){
    scanf("%d",&vec[k]);
  }
  
  scanf("%d",&type);
  //completare
  int flag = 1;

  if(type == 1 ){
    for(int i = 0; i < K; i++) {
        if(vec[i] > 0 && vec[i] <= N*M){
            int riga = ( vec[i]- 1 ) / M ;
            int colonna  = (vec[i] - 1) % M;
            sum += mat[riga][colonna];
        }
        else flag = 0;
    }
    if(flag == 0){
      sum = -1 ;
    }
  }else {
    for(int i = 0; i < K; i++) {
        if(vec[i] > 0 && vec[i] <= N*M){
            int riga = ( vec[i]- 1 ) / M ;
            int colonna  = (vec[i] - 1) % M;
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int rr = riga + i;
                    int cc = colonna + j;

                    if(rr >= 0 && rr < N && cc >= 0 && cc < M){
                        sum += mat[rr][cc];
                    }
                }
            }
            
        }
        else flag = 0;
    }
    if(flag == 0){
      sum = -1 ;
    }
  }

  printf("%d\n",sum);
  return 0;
}