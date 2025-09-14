#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Errore nell'apertura del file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0'; // Rimuove newline

        int len = strlen(line);
        int i = len - 1;

        // Trova l'inizio del numero alla fine
        while (i >= 0 && isdigit(line[i])) {  // verificare se il carattere line[i] è una cifra numerica, cioè uno dei caratteri da '0' a '9'
            i--;
        }

        // Se c'è un numero alla fine
        if (i < len - 1) {
            int num = atoi(&line[i + 1]); // Converte il numero
            int start = num; // Numero di lettere da togliere

            if (start < i + 1) {
                printf("%s\n", &line[start]);
            } else {
                printf("(Parola troppo corta per rimuovere %d lettere)\n", num);
            }
        } else {
            printf("(Nessun numero trovato in: %s)\n", line);
        }
    }

    fclose(file);
}
