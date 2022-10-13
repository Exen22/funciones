#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void copia(const char*,const char*);

int main(){
    system("cls");
    
    copia("nombre.txt", "nombrecopia.txt");
    
    return 0;
}


void copia(const char* nombre_archivo,const char* nombre_copia){
    FILE *arch1, *arch2;

    arch1=fopen(nombre_archivo,"rb");
    if(arch1!=NULL){
        int aux=0;
    
        arch2=fopen(nombre_copia,"wb");

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
