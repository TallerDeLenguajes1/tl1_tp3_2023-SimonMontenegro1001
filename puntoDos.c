#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANIOS 5
#define MESES 12

void cargar(int produccion[][MESES]);
void mostar(int produccion[][MESES]);
void mostrarPromedio(int produccion[][MESES]);
void mostrarmMinMax(int produccion[][MESES]);

int main() {
    int produccion[ANIOS][MESES];

    // setear la semilla
    srand(time(NULL));

    // cargar la matriz
    cargar(produccion);

    // mostar matriz
    mostar(produccion);
    // mostrarPromedio de ganancia por año
    mostrarPromedio(produccion);
    // valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
    mostrarmMinMax(produccion);
    return 0;
}

void cargar(int produccion[][MESES]) {
    for (int i = 0; i < ANIOS; i++) {
        for (int j = 0; j < MESES; j++) {
            produccion[i][j] = 10000 + rand() % 40001;
        }
    }
}

void mostar(int produccion[][MESES]) {
    for (int i = 0; i < ANIOS; i++) {
        printf("------ anio %d ------\n", i + 1);
        for (int j = 0; j < MESES; j++) {
            printf("- mes %d: $%d \n", j + 1, produccion[i][j]);
        }
    }
}

void mostrarPromedio(int produccion[][MESES]) {
    float prom = 0;
    for (int i = 0; i < ANIOS; i++) {
        prom = 0;
        for (int j = 0; j < MESES; j++) {
            prom += produccion[i][j];
        }
        printf("\n\npromedio del anio %d = $%.2f\n\n", i + 1, prom / MESES);
    }
}

void mostrarmMinMax(int produccion[][MESES]) {
    int max[3] = {0, 0, 0};
    int min[3] = {50000, 0, 0};

    for (int i = 0; i < ANIOS; i++) {
        for (int j = 0; j < MESES; j++) {
            if (produccion[i][j] >= max[0]) {
                max[0] = produccion[i][j];
                max[1] = i;
                max[2] = j;
            } else if (produccion[i][j] <= min[0]) {
                min[0] = produccion[i][j];
                min[1] = i;
                min[2] = j;
            }
        }
    }
    puts("----- Ganancia maxima -----");
    printf("\nAnio: %d\nMes: %d\nMonto: $%d\n\n", max[1] + 1, max[2] + 1, max[0]);
    puts("----- Ganancia minima -----");
    printf("\nAnio: %d\nMes: %d\nMonto: $%d\n\n", min[1] + 1, min[2] + 1, min[0]);
}
