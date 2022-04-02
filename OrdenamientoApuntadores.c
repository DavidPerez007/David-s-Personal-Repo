/*
Nombre: Pérez Cruz David Leobardo
Fecha: 11/03/2022
Descripción: Algoritmo que ordena la lista de estudiantes de programación estructurada por nombres y apellidos
considerando aquellos casos donde los nombres y/o apellidos sean iguales.
*/
#include <stdio.h>
int Comparar_Lista(char *Vector1, char *Vector2);
void Ordenar(char (*Apellidos)[50]);
void Printar_Lista(char (*Lista_Arreglada_Apellidos)[50]);
void Swap_Vectores(char *Vector1, char *Vector2 );
void Testing(char *Arreglo_Apellidos);

int main(){
 
    char Array_Apellidos_Alumnos[26][50] = {
                                {"Xool"},        {"Torres"} ,      {"May"} ,         {"Calderon"} , 
                                 {"Joachin"} ,   {"Villajuana"} ,  {"Poot"} ,        {"Magaña"} ,
                                {"Cruz"} ,       {"Medina"},       {"Moreno"} ,      {"Gonzalez"} ,
                                {"Espinoza"},    {"Armenta"},      {"Fonseca"},      {"Perez"},
                                {"Pan"} ,        {"Vallado"},      {"Perez"} ,       {"Madera"},
                                {"Leo"},         {"Ceballos"} ,    {"Trivellari"} ,  {"Medina"} ,
                                {"Ortiz"} ,      {"Arzabala"}};
// char (*pArray)[50] = Array_Apellidos_Alumnos;
                          
Ordenar(Array_Apellidos_Alumnos);
Printar_Lista(Array_Apellidos_Alumnos);
    
}


void Ordenar(char (*Apellidos)[50]){

    int i, j, Resta_Caracteres=0;

    for( i=0;i<28;i++){ 
        for(j=0;j<27;j++){ 
            if(Comparar_Lista(*(Apellidos + j) , *(Apellidos + j+1))>0){
                char *Pointer1;
                char *Pointer2; 

                Pointer1 = Apellidos[j];
                Pointer2 = Apellidos[j+1];
                Swap_Vectores(Pointer1, Pointer2);
            } 
            
        }
    }
}

void Swap_Vectores(char *Vector1, char *Vector2 ){
    char Vector_Auxiliar[100];
    int iterador=0;
    for(iterador=0; iterador<50; iterador++){
        Vector_Auxiliar[iterador] =  Vector1[iterador];
        *(Vector1+iterador) = *(Vector2+iterador);
        *(Vector2+iterador) = Vector_Auxiliar[iterador];
        
         

    }
}


int Comparar_Lista(char *Vector1, char *Vector2){
    int iterador, Resta=0;
    
    for(iterador=0;iterador<50;iterador++){
        if(*(Vector1+iterador) != *(Vector2+iterador)){
            Resta = *(Vector1+iterador) - *(Vector2+iterador);
            break;
        }
    } 
    return Resta;
}


void Printar_Lista(char (*Lista_Arreglada_Apellidos)[50]){
    int iterador;
    for(iterador=0;iterador<28;iterador++){
            printf("%s", *(Lista_Arreglada_Apellidos+iterador));
    printf("\n");
    }
}


