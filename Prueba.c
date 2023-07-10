// determinar las librerias
#include <stdio.h>
#include <stdlib.h>

// Define estructura del estudiante
typedef struct {
    int codigo;
    double nota;
} Estudiante;

// Función para la comparación de estructuras de estudiantes
int comparar(const void* a, const void* b) {
    Estudiante* estudianteA = (Estudiante*)a;
    Estudiante* estudianteB = (Estudiante*)b;
    return estudianteB->codigo - estudianteA->codigo;
}

// Leer y escribir archivos
void procesarArchivos(char* archivoEntrada, char* archivoSalida) {
    FILE* inputFile = fopen(archivoEntrada, "r");
    FILE* outputFile = fopen(archivoSalida, "w");

    Estudiante estudiantes[1000]; // Ajustar según necesidades
    int i = 0;
    double sumaNotas = 0;

    // Leer archivo de entrada y almacenar en la estructura
    while (fscanf(inputFile, "%d,%lf", &estudiantes[i].codigo, &estudiantes[i].nota) != EOF) {
        sumaNotas += estudiantes[i].nota;
        i++;
    }

    // Ordenar estudiantes
    qsort(estudiantes, i, sizeof(Estudiante), comparar);

    // Calcular la nota promedio
    double promedio = sumaNotas / i;

    // Escribir estudiantes ordenados en archivo de salida 
    for (int j = 0; j < i; j++) {
        fprintf(outputFile, "%d,%lf\n", estudiantes[j].codigo, estudiantes[j].nota);
    }

    // Escribir la nota promedio
    fprintf(outputFile, "Promedio,%lf\n", promedio);

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    procesarArchivos("input.csv", "output.csv");
    return 0;
}
//Culminado
