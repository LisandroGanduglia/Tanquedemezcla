# Memoria descriptiva

Mi sistema representa un tanque con un motor donde se realiza una mezcla de dos componentes para obtener un nuevo compuesto.  Los niveles serán medidos por un único sensor ultrasonico, tanto el tiempo de trabajo del motor como los niveles de cada liquido pueden configurarse según los requerimiento del usuario.

Al encenderse el sistema se abre la válvula A donde ingresa el primer componente, cuando llega al nivel deseado, se cierra la válvula A y se abre la válvula B hasta que el segundo componete llegue al nivel deseado, una vez finalizada la carga se cierra la válvula B y se acciona el motor que facilitara la mezcla, luego de cierto tiempo se detiene el motor y se abre la válvula C por donde saldrá el nuevo compuesto.
<p align="center">
  <img width="500" height="500" src="https://github.com/LisandroGanduglia/Tanquedemezcla/blob/main/Recursos/esquematanque.png">
</p>

## Maquina de estado
<p align="center">
  <img width="500" height="500" src="https://github.com/LisandroGanduglia/Tanquedemezcla/blob/main/Recursos/maquinadeestado.png">
</p>

- __SET__: Bandera de fin de inicialización

- __n__: Nivel leído

- __na_set__: Nivel configurado del liquido A

- __nb_set__: Nivel configurado del liquido b

- __t__: Tiempo del motor activo leído

- __tm_set__: Tiempo configurado para el motor activo

### Código

- Archivo de cabecera __mylib.h__
```c
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
```
- Archivo __main.c__
> con Switch Case
```c
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

```
- Archivo __mainpunteros.c__
> con Punteros
```c
#include "funciones.c"

int main(int argc, char const *argv[]) {
    estado_tanque estado = cargar; // primer estado
    estado_tanque (*p[])(nivel_tanque) = {f_cargar, f_mezclar, f_descargar}
    config = f_inicio();
    while(1) estado = (*p[estado])(config);

  return 0;
}

```
- Archivo __funciones.c__
```c
#include "mylib.h"

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
```
- Archivo __config.conf__
```bash
# n Nivel leído
n 0
# nA Nivel configurado del liquido A
na_set 3
# nB Nivel configurado del liquido b
nb_set 5
# Tiempo del motor activo
t 0
# Tiempo configurado para el motor activo
tm_set 2

```
