#include<stdio.h>
#include<string.h>

int main(){

    FILE file_pointer;
    //file_pointer = fopen("fileprova.txt", "w");
    char var[100];

    /printf("Inserire quello che vuoi scrivere al file: ");
    scanf("%s", var);
    fprintf(file_pointer, "%s", var);

    fclose(file_pointer);/

    file_pointer = fopen("fileprova.txt", "a");

    printf("Inserire quello che vuoi appendere al file: ");
    scanf("%s", var);
    fprintf(file_pointer, "\n%s", var);

    /fgets(var, 100, file_pointer);
    printf("%s", var);*/

    fclose(file_pointer);

    return 0;
}