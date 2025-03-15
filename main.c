#include "ppm_console_printer.h"

int main(){
    printf("Escreva o nome do arquivo:");
    char filename[100];
    scanf("%s",filename);
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    ppm_info f_info = print_ppm_file(file);
    
    printf("\nFormato:%s, Tamanho:%dx%d, Valor máximo:%d",f_info.format,f_info.width,f_info.height,f_info.maxval);

    fclose(file);
    return 0;
}