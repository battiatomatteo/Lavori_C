#include <stdio.h>
#include <stdlib.h>

#define MAX_ESAMI 3
#define MAX_APPELLI 2
#define MAX_STUDENTI 50

struct Studente {
    char nome[31];
    int matricola;
    int voti[MAX_ESAMI][MAX_APPELLI];
};

// Calcolo media
float media_voti(int voti_appelli[], int n) {
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma += voti_appelli[i];
    }
    return (float)somma / n;
}

int main() {
    int num_studenti = 0;

    printf("Inserisci il numero di studenti (max %d): ", MAX_STUDENTI);
    do {
        scanf("%d", &num_studenti);
    } while (num_studenti < 1 || num_studenti > MAX_STUDENTI);

    struct Studente studenti[num_studenti];

    // Inserimento
    for (int i = 0; i < num_studenti; i++) {
        printf("\nStudente %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", studenti[i].nome);  // accetta spazi
        printf("Matricola: ");
        scanf("%d", &studenti[i].matricola);

        for (int esame = 0; esame < MAX_ESAMI; esame++) {
            for (int appello = 0; appello < MAX_APPELLI; appello++) {
                printf("Voto esame %d, appello %d: ", esame + 1, appello + 1);
                scanf("%d", &studenti[i].voti[esame][appello]);
            }
        }
    }

    // Salvataggio su file di testo
    FILE *file_scrittura = fopen("studenti.txt", "w");
    if (file_scrittura == NULL) {
        perror("Errore apertura file scrittura");
        return 1;
    }

    for (int i = 0; i < num_studenti; i++) {
        fprintf(file_scrittura, "%s\n%d\n", studenti[i].nome, studenti[i].matricola);
        for (int esame = 0; esame < MAX_ESAMI; esame++) {
            for (int appello = 0; appello < MAX_APPELLI; appello++) {
                fprintf(file_scrittura, "%d ", studenti[i].voti[esame][appello]);
            }
            fprintf(file_scrittura, "\n");
        }
    }
    fclose(file_scrittura);

    // Lettura da file
    FILE *file_lettura = fopen("studenti.txt", "r");
    if (file_lettura == NULL) {
        perror("Errore apertura file lettura");
        return 1;
    }

    struct Studente letti[MAX_STUDENTI];

    for (int i = 0; i < num_studenti; i++) {
        fscanf(file_lettura, " %[^\n]\n%d\n", letti[i].nome, &letti[i].matricola);
        for (int esame = 0; esame < MAX_ESAMI; esame++) {
            for (int appello = 0; appello < MAX_APPELLI; appello++) {
                fscanf(file_lettura, "%d", &letti[i].voti[esame][appello]);
            }
        }
    }

    fclose(file_lettura);

    // Stampa dei dati letti
    printf("\n=== STUDENTI ===\n");
    for (int i = 0; i < num_studenti; i++) {
        printf("Studente: %s\n", letti[i].nome);
        printf("Matricola: %d\n", letti[i].matricola);
        for (int esame = 0; esame < MAX_ESAMI; esame++) {
            float media = media_voti(letti[i].voti[esame], MAX_APPELLI);
            printf("  Media esame %d: %.2f\n", esame + 1, media);
        }
        printf("\n");
    }

    return 0;
}
