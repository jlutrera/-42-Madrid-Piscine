#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_map(int lines, char empty, char obstacle, char fill, int width, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    // Escribir la primera línea con el formato requerido
    fprintf(file, "%d%c%c%c\n", lines, empty, obstacle, fill);

    // Generar el mapa aleatorio
    srand(time(NULL)); // Inicializar la semilla para números aleatorios
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < width; j++) {
            // Elegir aleatoriamente entre vacío y obstáculo
            if (rand() % 4 == 0) { // Aproximadamente 25% de obstáculos
                fputc(obstacle, file);
            } else {
                fputc(empty, file);
            }
        }
        fputc('\n', file); // Nueva línea al final de cada fila
    }

    fclose(file);
    printf("Mapa generado correctamente en el archivo: %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Uso: %s <número de líneas> <carácter de vacío> <carácter de obstáculo> <carácter de lleno> <ancho>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int lines = atoi(argv[1]);
    char empty = argv[2][0];
    char obstacle = argv[3][0];
    char fill = argv[4][0];
    int width = atoi(argv[5]);

    if (lines <= 0 || width <= 0) {
        fprintf(stderr, "Error: El número de líneas y el ancho deben ser mayores a 0.\n");
        exit(EXIT_FAILURE);
    }

    const char *filename = "test"; // Nombre del archivo de salida
    generate_map(lines, empty, obstacle, fill, width, filename);

    return 0;
}
