#include <stdio.h>

int num, prec, succ;
int main(void)
{
    printf("Inserire un numero intero\n");
    scanf("%d", &num);
    prec=num-1;
    succ=num+1;
    printf("Il numero che precede %d è %d mentre il suo successivo è %d", num, prec, succ);
    return 0;
}
