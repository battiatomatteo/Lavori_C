#include <stdio.h>

int base, altezza, resto;
float area;

int main(void)
{
    printf("Inserire i valori di base e altezza del tringolo\n");
    scanf("%d %d", &base, &altezza);
    area=(float)base*altezza/2;
    resto=base*altezza%2;
    printf("L'area del triangolo con base %d e altezza %d è %f \n", base, altezza, area);
    printf("Il resto è %d\n", resto);
    return 0;
}