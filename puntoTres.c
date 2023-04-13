#include <stdio.h>
#include <stdlib.h>

#define TAMA 5

void pedirNombres(char **nombres);
void mostrarNombres(char **nombres);

int main() {
    char *nombres[TAMA];
    // solicitar 5 nombres
    pedirNombres(nombres);
    // mostrar los nombres
    mostrarNombres(nombres);

    return 0;
}

void pedirNombres(char **nombres) {
    puts("__Ingresar 5 nombres__");
    for (int i = 0; i < 5; i++) {
        printf("%d: ", i + 1);
        nombres[i] = malloc(sizeof(char) * 11);
        fflush(stdin);
        scanf("%10s", nombres[i]);
    }
}

void mostrarNombres(char **nombres) {
    for (int i = 0; i < 5; i++) {
        printf("\nNombre %d: %s", i + 1, nombres[i]);
        free(nombres[i]);
    }
}