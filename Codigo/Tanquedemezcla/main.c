#include "mylib.h"
#include "funciones.c"

int main(int argc, char const *argv[]) {

estado_tanque estado = cargar; // primer estado
config = f_inicio();
while (1){
    switch (estado){
    case cargar:estado = f_cargar(config);
         break;
    case mezclar:estado = f_mezclar(config);
         break;
    case descargar:estado = f_descargar(config);
         break;
    }
}
    return 0;
}

