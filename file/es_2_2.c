#include <stdio.h>
#include <string.h>

#define FNAME "testo.txt"
#define MAXS 15
#define SOGLIA 3

int main() {
    FILE *fp;
    char parola[MAXS + 1];
    int c;

    fp = fopen(FNAME, "r");
    if(fp == NULL) {
        printf("Errore apertura file\n");
        return 1;
    }

    while(1) {
        int i = 0;
        // Legge un carattere alla volta fino a uno spazio o EOF
        while((c = fgetc(fp)) != EOF && c != ' ' && c != '\n') {
            if(i < MAXS) {
                parola[i++] = c;
            }
        }
        parola[i] = '\0';

        if(i == 0 && c == EOF) break;

        // Conta le vocali
        int count_vocali = 0;
        for(int j = 0; j < i; j++) {
            if(parola[j] == 'a' || parola[j] == 'e' || parola[j] == 'i' ||
               parola[j] == 'o' || parola[j] == 'u') {
                count_vocali++;
            }
        }

        // Se ci sono almeno SOGLIA vocali, stampa la parola al contrario
        if(count_vocali >= SOGLIA) {
            for(int j = i - 1; j >= 0; j--) {
                printf("%c", parola[j]);
            }
            printf(" ");
        }

        if(c == EOF) break;
    }

    fclose(fp);
    return 0;
}
