#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void copia(const char*);

int main(){
    system("cls");
    
    copia("nombres.txt");
    return 0;
}


void copia(const char* nombre_archivo){
    FILE *arch1, *arch2;

    arch1=fopen(nombre_archivo,"r");
    if(arch1!=NULL){
        int aux=0;
        char nombre_copia[strlen(nombre_archivo)];


        strcpy(nombre_copia, nombre_archivo);

        for(int i=0; i<strlen(nombre_archivo); i++){
            if(nombre_copia[i+1]=='.'){
                if(nombre_copia[i]!='2'){
                    nombre_copia[i]='2';
                }
                else{
                    nombre_copia[i]='1';
                }
            }

        }


    
        arch2=fopen(nombre_copia,"w");

        if(arch1!=NULL && arch2!=NULL){
        
            while(!feof(arch1)){
                fread(&aux, sizeof(char), 1, arch1);
                if(!feof(arch1)){
                    fwrite(&aux, sizeof(char), 1, arch2);
                }
            

            }
            fclose(arch1);
            fclose(arch2);
        }

    }
    else{
        cout<<"\n\nNO SE HA ENCONTRADO ESE ARCHIVO\n\n";
    }
    

}
