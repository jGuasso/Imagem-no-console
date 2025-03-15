#ifndef PPM_CONSOLE_PRINTER_H
#define PPM_CONSOLE_PRINTER_H

#include <stdio.h>
#include <stdlib.h>

//biblioteca criada para PRINTAR arquivos .ppm tipo P6 no terminal
//João Antônio Guerim Guasso

typedef struct
{
    char format[3];
    int width;
    int height;
    int maxval;
}ppm_info;

ppm_info print_ppm_file(FILE*file);

#endif //PPM_CONSOLE_PRINTER_H