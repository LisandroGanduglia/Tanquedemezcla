#include "funciones.c"

int main(int argc, char const *argv[]) {
    estado_tanque estado = cargar; // primer estado
    estado_tanque (*p[])(nivel_tanque) = {f_cargar, f_mezclar, f_descargar}
    config = f_inicio();
    while(1) estado = (*p[estado])(config);

  return 0;
}
