#include <stdio.h>
int A, B;
float somma, sottrazione, divisione, moltiplicazione;
int main(void)
{
    printf("Inserire due numeri:\n");
    scanf("%d %d", &A, &B);    
    somma=(float)A+B;
    sottrazione=(float)A-B;
    divisione=(float)A/B;
    moltiplicazione=(float)A*B;
    printf("La somma di %d e %d è %f", A, B, somma);
    printf("\nLa differenza tra %d e %d è %f", A, B, sottrazione);
    printf("\nLa divisione tra %d e %d è %f", A, B, divisione);
    printf("\nLa moltiplicazione tra %d e %d è %f", A, B, moltiplicazione);
    return 0;
}
