#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef enum {
  cargar = 0,
  mezclar = 1,
  descargar = 2
}estado_tanque;


typedef struct{
    char n; //nivel leido
    char na_set; //nivel liquido A
    char nb_set; //nivel liquido B
    char t; //Tiempo del motor activo leído
    char tm_set; //Tiempo configurado para el motor activo
}nivel_tanque;

nivel_tanque config;


estado_tanque f_cargar(nivel_tanque);
estado_tanque f_mezclar(nivel_tanque);
estado_tanque f_descargar(nivel_tanque);


#endif
