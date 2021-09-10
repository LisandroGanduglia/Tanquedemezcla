#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * getKey(char *key);



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

char * getKey(char *key){
char i =0;

nivel_tanque f_inicio(){  // lee el archivo de configuración y carga las variables.
    FILE *conf;
    char cadena[40], *key, *val;
    char variables[5][20]= {"NivelLeido","NivelA","NivelB","Tiempomotor","TiempoActivom"},i;
    if ((conf = fopen("confi.conf","rb")) == NULL){
        printf("No se encontro archivo de configuracion\n");
        return ;
    }

    fgets(cadena,40,conf);
    do {
        key = cadena;
        if((*key) != '#' && strlen(key) >= 0){
            val = getKey(key);
            for(i = 0; i<5; i++){
                if(!strcmp(key,variables[i])){
                    switch(i){
                    case 0: config.n = atoi(val);
                        break;
                    case 1: config.na_set = atoi(val);
                        break;
                    case 2: config.nb_set = atoi(val);
                        break;
                    case 3: config.t = atoi(val);
                        break;
                    case 4: config.tm_set = atoi(val);
                        break;
                        }
                }
            }
        }
        fgets(cadena,40,conf);
    }while (!feof(conf));
return config;
}
while(*(key+1) != ' '){
        i++;
    }
    *(key+i)=0;
    return key+i+1;
    }
#endif
