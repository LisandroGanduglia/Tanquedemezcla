#include <stdlib.h>
#include <string.h>
#include "mylib.h"

char * getKey(char *key);

int main(int argc, char const *argv[]) {
    nivel_tanque config;
    FILE *conf;
    char cadena[40], *key, *val;
    char variables[5][20]= {"NivelLeido","NivelA","NivelB","Tiempomotor","TiempoActivom"},i;
    if ((conf = fopen("confing.conf","rb")) == NULL){
        printf("No se encontro archivo de configuracion\n");
        return 1;
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
char * getKey(char *key){
char i =0;

    while(*(key+1) != ' '){
        i++;
    }
    *(key+i)=0;
    return key+i+1;
}
