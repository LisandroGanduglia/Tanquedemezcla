#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#include <stdio.h>


typedef enum {
  cargar = 0,
  mezclar = 1,
  descargar = 2
}estado_tanque;


typedef struct{
    int n; //nivel leido
    int na_set; //nivel liquido A
    int nb_set; //nivel liquido B
    int t; //Tiempo del motor activo leído
    int tm_set; //Tiempo configurado para el motor activo
}nivel_tanque;


nivel_tanque f_inicio(void); // lee el archivo de configuración y carga las variables.
estado_tanque f_cargar(nivel_tanque);
estado_tanque f_mezclar(nivel_tanque);
estado_tanque f_descargar(nivel_tanque);

#endif
