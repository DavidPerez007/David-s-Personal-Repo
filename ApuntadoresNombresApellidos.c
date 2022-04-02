/*
Nombre: Pérez Cruz David Leobardo
Fecha: 11/03/2022
Descripción: Algoritmo que ordena la lista de estudiantes de programación estructurada por nombres y apellidos
considerando aquellos casos donde los nombres y/o apellidos sean iguales.
*/
#include <stdio.h>
int Comparar_Lista(char *Vector1, char *Vector2);
void Ordenar(char Nombres[28][50] , char Apellidos[28][50]);
void Printar_Lista(char Lista_Arreglada_Apellidos[28][50] , char Lista_Arreglada_Nombres[28][50]);
void Swap_Vectores(char *Vector1 , char *Vector2);
void Testing(char (*Arreglo_Nombres[50]), char (*Arreglo_Apellidos)[50]);

int main(){
 
    char Array_Nombres_Alumnos[28][50] = {
                                {"Alvaro"},    {"Andrea"} ,    {"Carlos"} ,   {"Carlos"} , 
                                {"Fernando"} , {"Fernando"} ,  {"Gilmer"} ,    {"Jose"} ,
                                {"Luis"} ,      {"Luis"},       {"Mariam"} ,  {"Rossana"} ,
                                {"Abraham"},   {"Adjany"},    {"Adrian"},   {"Alan"},
                                {"Cristian"} ,  {"Daniel"},     {"David"} ,   {"Elias"},
                                {"Jose"},        {"Juan"} ,      {"Juan"} ,  {"Kevin"} ,
                                {"Reyna"} ,    {"Rosa"}};

    char Array_Apellidos_Alumnos[28][50] = {
                                {"Xool"},        {"Torres"} ,       {"May"} ,       {"Calderon"} , 
                                 {"Joachin"} ,  {"Villajuana"} , {"Poot"} ,      {"Magaña"} ,
                                {"Cruz"} ,       {"Medina"},     {"Moreno"} ,    {"Gonzalez"} ,
                                {"Espinoza"}, {"Armenta"},       {"Fonseca"},    {"Perez"},
                                {"Pan"} ,      {"Vallado"},       {"Perez"} ,      {"Madera"},
                                {"Leo"},           {"Ceballos"} ,       {"Trivellari"} ,  {"Medina"} ,
                                {"Ortiz"} ,       {"Arzabala"}};
    
   printf("La lista ordenada por apellidos es:  \n");
    Ordenar(Array_Apellidos_Alumnos , Array_Nombres_Alumnos);
    Printar_Lista(Array_Apellidos_Alumnos, Array_Nombres_Alumnos ); 
    printf("\nLa lista ordenada por nombres es: \n");
    Ordenar(Array_Nombres_Alumnos, Array_Apellidos_Alumnos);
    Printar_Lista(Array_Nombres_Alumnos, Array_Apellidos_Alumnos);
}



void Ordenar(char (*Apellidos)[50] , char (*Nombres)[50] ){

    int i, j, Resta_Caracteres=0;

    for( i=0;i<28;i++){ 
        for(j=0;j<27;j++){ 
            if(Comparar_Lista(*(Apellidos + j) , *(Apellidos + j+1))>0){ 
                Swap_Vectores(*(Apellidos + j) , *(Apellidos + j+1));
                Swap_Vectores(*(Nombres + j) , *(Nombres + j+1));
            } 
             if(Resta_Caracteres==0){
                 Resta_Caracteres= Comparar_Lista(*(Nombres + j) , *(Nombres + j+1));
             }   
            
        }
    }
}

void Swap_Vectores(char *Vector1 , char *Vector2){
    char Vector_Auxiliar[100];
    int iterador=0;
    for(iterador=0; iterador<50; iterador++){
        Vector_Auxiliar[iterador] =  Vector1[iterador];
        *(Vector1 + iterador) = *(Vector2 + iterador);
        *(Vector2 + iterador) = Vector_Auxiliar[iterador];
        
         

    }
}


int Comparar_Lista(char *Vector1, char *Vector2){
    int iterador, Resta=0;
    
    for(iterador=0;iterador<50;iterador++){
        if(*(Vector1 + iterador) != *(Vector2 + iterador)){
            Resta = *(Vector1 + iterador) - *(Vector2 + iterador);
            break;
        }
    } 
    return Resta;
}


void Printar_Lista(char (*Lista_Arreglada_Apellidos)[50] , char (*Lista_Arreglada_Nombres)[50]){
    int iterador;
    for(iterador=0;iterador<28;iterador++){
            printf("%s_%s", *(Lista_Arreglada_Apellidos + iterador) , *(Lista_Arreglada_Nombres + iterador));
    printf("\n");
    }
}


