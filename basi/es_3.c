#include <stdio.h>
int num1, num2;
float media;
int main(void)
{
    printf("Inserire due valori\n");
    scanf("%d %d", &num1, &num2);
    media=(float)(num1+num2)/2;
    printf("La media di %d e %d è %f.", num1, num2, media);
    return 0;
}
