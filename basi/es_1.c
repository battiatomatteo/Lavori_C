#include <stdio.h>

int num1, num2;
float somma;

int main(void)
{
    printf("Inserire i valori di num1 e num2\n");
    scanf("%d %d", &num1, &num2);
    somma=(float)num1+num2;
    printf("La somma di num1 %d e num2 %d è %f \n", num1, num2, somma);
    return 0;
}
