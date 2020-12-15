#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

//Fonte
#include "dogica.h"
// #include "pixeled.h"

int main(){
    char frase[512];
    int carac, tipo;

    printf("Informe a frase: ");
    fgets(frase, 512, stdin);

    FILE * f_Arq = fopen("texto", "w");
    fprintf(f_Arq, "v2.0 raw\n");

    for(int i=0; frase[i]!='\0';i++){
        if(frase[i] == ' ' || frase[i]=='\n'){
            fprintf(f_Arq, "\n0 0 0 0\n");
            continue;
        }

        if(isalpha(frase[i])){
            carac = isupper(frase[i]) ? frase[i] - 65 : frase[i] - 97;
            tipo  = isupper(frase[i]) ? 0 : 1;
        }
        else if(isdigit(frase[i])){
            carac = frase[i] - 48;
            tipo  = 2;
        }
        else{
            continue;
        }

        fprintf(f_Arq, "\n0 ");
        for(int hex=0; hex<QUANT_COD; hex++){
            if(strcmp(caracteres[tipo][carac][hex], "--")){
                fprintf(f_Arq, " %s ", caracteres[tipo][carac][hex]);
            }
        }
    }

    fclose(f_Arq);

    printf("\nSalvo!\nFonte: %s\nArquivo: 'texto'\n", fonte);
    getchar();

    return 0;
}