#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindroma(char *string_parole, int sx, int dx){
    
    //x = strlen(string_parole);
    
    if(sx == dx) return 1;
    else if(string_parole[sx] == string_parole[dx]) return palindroma(string_parole, sx+1, dx-1);
}

int main(int argc, char const *argv[])
{
    int ris;
    char *string_parola;
    scanf("%c", &string_parola);

    ris = palindroma(string_parola, 0, strlen(string_parola)-1);
    
    if(ris==1) {
        printf("La parola è palindroma");
    }
    else 
    {
         printf("La parola non è palindroma");
    }
    
    return 0;
}
