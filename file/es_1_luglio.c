#include<stdio.h>
#define N 3
#define M 4
#define K 3

int main(){
  int sum = 0, k, i, j, ap = 0, l = 0, c = 0; 
  int mat[N][M];
  int vec[K];
  int type;
  
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      scanf("%d",&mat[i][j]);
    }
  }

  for(k=0;k<K;k++){
    scanf("%d",&vec[k]);
    if( vec[k] > 12) c = 1;
  }
  
  scanf("%d",&type);
  //completare
  
  if(c == 1){
    sum = -1;
  }
  else{
    if(type == 1){
      for(int p = 0; p<K ; p++){
        if(vec[p]<= M) sum = sum + mat[0][vec[p]-1]; // caso in cui ci si trova nella prima riga 
        else {
          ap = vec[p];
          while(ap >= 4) {   // fino a quando il numero non è minore o uguale a 4
              if (ap-1 > 3 ) l++ ;
              ap = ap - 4;  // si sottraggono 4
                  
          }
          sum = sum + mat[l][ap-1]; // si somma il numero
        }
      }
    }
    else {
      for(int p = 0; p<K ; p++){
        if(vec[p]<= M) {  // caso in cui ci si trova nella prima riga 
          sum = sum + mat[0][vec[p]-1] + mat[0][vec[p]-1]; // centro matrrice + quello sotto
          if( mat[0][vec[p]-1] < 3 ) sum = sum + mat[0][vec[p]] + mat[1][vec[p]];      // valore a destra + quello sotto
          if( mat[0][vec[p]-1] > 0) sum = sum + mat[0][vec[p]-2] + mat[1][vec[p]-2];       // valore a sinistra + quello sotto  
          /*for(int u = 0 ; u< 3; u++){   // li scorro da destra a sinistra 
            sum = sum + mat[1][vec[p]-u];
          }*/
        }
        else {
          ap = vec[p];
          while(ap >= 4) {   // fino a quando il numero non è minore o uguale a 4
              if (ap-1 > 3 ) l++ ;
              ap = ap - 4;  // si sottraggono 4
                  
          }
          sum = sum + mat[l][ap-1]; // si somma il numero che sta al centro della sottomatrice 
          printf("%d\n",sum);
          if( l <= 3 ){  // esiste una riga sotto 
             sum = sum + mat[l+1][ap-1];   // elemento sotto al centro 
             printf("%d\n",sum);
             sum = sum + mat[l-1][ap-1];   // elemento sopra al centro 
             printf("%d\n",sum);
             if( mat[l][vec[ap]-1] < 3 ) sum = sum + mat[l][vec[ap]] + mat[l+1][vec[ap]] + mat[l-1][vec[ap]];      // valore a destra + quello sotto + quello sopra
             if( mat[l][vec[ap]-1] > 0) sum = sum + mat[l][vec[ap]-2] + mat[l+1][vec[ap]-2] + mat[l+1][vec[ap]-2];       // valore a sinistra + quello sotto + quello sopra 
             printf("%d\n",sum);
          }
          else{  // non esiste una riga sotto
             sum = sum + mat[l-1][ap-1];   // elemento sopra al centro 
             printf("%d\n",sum);
             if( mat[l][vec[ap]-1] < 3 ) sum = sum + mat[l][vec[ap]] + mat[l-1][vec[ap]];      // valore a destra + quello sopra
             printf("%d\n",sum);
             if( mat[l][vec[ap]-1] > 0) sum = sum + mat[l][vec[ap]-2]+ mat[l+1][vec[ap]-2];       // valore a sinistra + quello sopra 
             printf("%d\n",sum);
          }
        }
      }
    }
  }

  printf("%d\n",sum);
  return 0;
}