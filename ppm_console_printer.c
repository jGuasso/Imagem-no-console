#include "ansi_colors.h"
#include "ppm_console_printer.h"

ppm_info print_ppm_file(FILE*file){
    ppm_info f_info;
    fscanf(file, "%s", f_info.format);//O aceito pelo programa é somente o P6
    fscanf(file, "%d %d", &f_info.width, &f_info.height);
    fscanf(file, "%d", &f_info.maxval);
    fgetc(file);
    if (f_info.format[1]=='3')
    {
        printf("Formato de arquivo errado! a bibllioteca só aceita formato P6!!\n");
        return f_info;
    }
    unsigned char *pixels = (unsigned char *)malloc(3 * f_info.width * f_info.height);
    if (pixels == NULL) {
        printf("Erro ao alocar memória.\n");
        return f_info;
    }
    fread(pixels, 3, f_info.width * f_info.height, file);

    for (int y = 0; y < f_info.height; y++) {
        for (int x = 0; x < f_info.width; x++) {
            int index = (y * f_info.height + x) * 3;
            printf("%s  ",bg_color(pixels[index], pixels[index + 1], pixels[index + 2]));
        }
        printf("\n");
    }

    free(pixels);
    
}