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
