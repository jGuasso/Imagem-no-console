#include <stdio.h>
#include <stdlib.h>
#include "ansi_colors.h"

int main(){
    printf("Escreva o nome do arquivo:");
    char filename[100];
    scanf("%s",filename);
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char format[3];
    int width, height, maxval;

    fscanf(file, "%s", format);//O aceito pelo programa é somente o P6
    fscanf(file, "%d %d", &width, &height);
    fscanf(file, "%d", &maxval);
    fgetc(file);

    printf("Formato: %s\n", format);
    printf("Dimensoes: %dx%d\n", width, height);
    printf("Valor maximo: %d\n", maxval);
    unsigned char *pixels = (unsigned char *)malloc(3 * width * height);
    if (pixels == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(file);
        return 1;
    }
    fread(pixels, 3, width * height, file);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            printf("%s  ",bg_color(pixels[index], pixels[index + 1], pixels[index + 2]));
        }
        printf("\n");
    }

    free(pixels);
    fclose(file);
    return 0;
}