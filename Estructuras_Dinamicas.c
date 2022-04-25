/*
Nombre: Pérez Cruz David Leobardo
Fecha: 05/04/2022
Descripción: Algoritmo que ordena la lista de estudiantes de programación estructurada por apellido paterno mediante
el uso de estructuras y la reserva de memoria dinámica.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NO_ALUMNOS 21
 
struct Alumno {
    char* nombre;
    char* apellidoPaterno;
    char* apellidoMaterno;
};

typedef struct Alumno Alumno;


void insertarAlumno(Alumno *lista[], char *nombre, char *apellidoPaterno, char *apellidoMaterno, int i);
void llenadoLista(Alumno *lista[]);
void imprimirLista(Alumno *lista[]);
void ordenacionBurbuja(Alumno *lista[]);
void intercambiarAlumnos(Alumno *lista[], int j);


int main(){
    int i;
    Alumno *lista[NO_ALUMNOS];

    llenadoLista(lista);    
    ordenacionBurbuja(lista);
    imprimirLista(lista);
    
    return 0;
}

void insertarAlumno(Alumno *lista[], char *nombre, char *apellidoPaterno, char *apellidoMaterno, int i){
    Alumno *puntero;
    puntero = lista[i];
    puntero = (Alumno*) malloc(sizeof(Alumno));
    
    
    puntero->nombre = (char*) malloc((strlen(nombre)+1) * sizeof(char)); 
    
    strcpy(puntero->nombre, nombre); 
    puntero-> apellidoPaterno = (char*) malloc((strlen(apellidoPaterno)+1) * sizeof(char));
    strcpy(puntero->apellidoPaterno, apellidoPaterno); 
    puntero->apellidoMaterno = (char*) malloc((strlen(apellidoMaterno)+1) * sizeof(char));
    strcpy(puntero->apellidoMaterno, apellidoMaterno);
    lista[i] = puntero;
    
}

void llenadoLista(Alumno *lista[]){
        
    insertarAlumno(lista,"Fernando","Villajuana","Saavedra", 0);
    insertarAlumno(lista,"Luis","Cruz","Inzunza", 1);
    insertarAlumno(lista,"Jose Carlos","Leo","Fernandez", 2);
    insertarAlumno(lista,"Jose Angel","Magana","Garcia", 3);
    insertarAlumno(lista,"Carlos","May","Vivas", 4);
    insertarAlumno(lista,"Fernando","Joachin","Prieto", 5);
    insertarAlumno(lista,"Carlos","Calderon","Delgado", 6);
    insertarAlumno(lista,"Mariam Guadalupe","Moreno","Farah", 7);
    insertarAlumno(lista,"Adjany","Armenta","Aguilar", 8);
    insertarAlumno(lista,"Andrea","Torres","Perez", 9);
    insertarAlumno(lista,"Kevin Alejandro","Medina","Padilla", 10);
    insertarAlumno(lista,"Luismi","Medina","Avila", 11);
    insertarAlumno(lista,"Reyna Valeria","Ortiz","Porres", 12);
    insertarAlumno(lista,"David","Perez","Cruz", 13);
    insertarAlumno(lista,"Juan","Ceballos","Medina", 14);
    insertarAlumno(lista,"Daniel","Vallado","Orozco", 15);
    insertarAlumno(lista,"Alvaro","Xool","Canul", 16);
    insertarAlumno(lista,"Cristian","Pan","Zaldivar", 17);
    insertarAlumno(lista,"Abraham","Espinosa","Mendoza", 18);
    insertarAlumno(lista,"Alan","Perez","Romero", 19);
    insertarAlumno(lista,"Elias","Madera","De Regil", 20);
    
}

void imprimirLista(Alumno *lista[]) {
    for (int i = 0; i < NO_ALUMNOS; i++) {
        printf("%s %s %s\n", lista[i]->nombre, lista[i]->apellidoPaterno, lista[i]->apellidoMaterno);
    }
}

int compararAlumnos(Alumno *alumno1, Alumno *alumno2){
    int comparacion;

    comparacion = strcmp(alumno1->apellidoPaterno, alumno2->apellidoPaterno);

    if(comparacion == 0){
        comparacion = strcmp(alumno1->apellidoMaterno, alumno2->apellidoMaterno);
        if(comparacion == 0){
            comparacion = strcmp(alumno1->nombre, alumno2->nombre);
        }
        
    }    
    return comparacion;
}

void intercambiarAlumnos(Alumno *lista[], int j){
    Alumno *aux;

    aux = lista[j];
    lista[j] = lista[j+1];
    lista[j+1] = aux;


}

void ordenacionBurbuja(Alumno *lista[]){
  
    int i, j;

    for(i = 0; i < NO_ALUMNOS;i++){
        for(j = 0; j < NO_ALUMNOS-1;j++){
            if(compararAlumnos(lista[j], lista[j+1]) > 0){
                
                intercambiarAlumnos(lista, j);

            }
        }
    }
    
}

