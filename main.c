#include "header.h"

int main(){
    library *lib[2000];
    for(int i = 0; i<2000; i++){
        lib[i] = (library*)malloc(sizeof(library));
    }
    int count = LoadData(lib);
    Print(lib,count);
}
