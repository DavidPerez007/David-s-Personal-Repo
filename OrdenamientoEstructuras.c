// Nombre: David Leobardo Pérez Cruz
// Fecha: 28/03/2022
// Descripción: Algoritmo que realiza el ordenamiento por nombre, apellido paterno y apellido materno
// de todos los alumnos de programación estructurada por medio del uso de estructuras
// en el lenguaje c

#include<stdio.h>
#include<string.h>

#define CARACTERES 50
#define CANTIDAD_ALUMNOS 25

struct Alumnos{

    char nombre[CARACTERES];
    char apellido_paterno[CARACTERES];
    char apellido_materno[CARACTERES];
    
}
typedef Alumnos;

int Comparar(Alumnos Estudiantes[], int j, int ordenamiento);
int Verificar_Swap(int resultado);
void Swap(Alumnos *nombre1, Alumnos *nombre2);
void Printar_Lista(Alumnos Students[], int ordenamiento);     


int main(){
    
    struct Alumnos Alumn[CANTIDAD_ALUMNOS];

    strcpy(Alumn[0].nombre, "David Leobardo"); strcpy(Alumn[0].apellido_paterno, "Perez"); strcpy(Alumn[0].apellido_materno, "Cruz");      
    strcpy(Alumn[1].nombre, "Reyna Valentina"); strcpy(Alumn[1].apellido_paterno, "Ortíz"); strcpy(Alumn[1].apellido_materno, "Porras");  
    strcpy(Alumn[2].nombre, "Fernando"); strcpy(Alumn[2].apellido_paterno, "Villajuana"); strcpy(Alumn[2].apellido_materno, "Saavedra");  
    strcpy(Alumn[3].nombre, "Carlos Augusto"); strcpy(Alumn[3].apellido_paterno, "May"); strcpy(Alumn[3].apellido_materno, "Vivas");  
    strcpy(Alumn[4].nombre, "Daniel Eduardo"); strcpy(Alumn[4].apellido_paterno, "Vallado"); strcpy(Alumn[4].apellido_materno, "Orozco");
    strcpy(Alumn[5].nombre, "Alvaro de Jesus"); strcpy(Alumn[5].apellido_paterno, "Xool"); strcpy(Alumn[5].apellido_materno, "Canul");  
    strcpy(Alumn[6].nombre, "Carlos Javier"); strcpy(Alumn[6].apellido_paterno, "Calderón"); strcpy(Alumn[6].apellido_materno, "Delgado");  
    strcpy(Alumn[7].nombre, "Adjany"); strcpy(Alumn[7].apellido_paterno, "Armenta"); strcpy(Alumn[7].apellido_materno, "Aguilar");  
    strcpy(Alumn[8].nombre, "Jose Carlos"); strcpy(Alumn[8].apellido_paterno, "Leo"); strcpy(Alumn[8].apellido_materno, "Fernandez");  
    strcpy(Alumn[9].nombre, "Luis Miguel"); strcpy(Alumn[9].apellido_paterno, "Medina"); strcpy(Alumn[9].apellido_materno, "Avila");  
    strcpy(Alumn[10].nombre, "Juan Omar"); strcpy(Alumn[10].apellido_paterno, "Trivellari"); strcpy(Alumn[10].apellido_materno, "Ramirez");  
    strcpy(Alumn[11].nombre, "Mariam Guadalupe"); strcpy(Alumn[11].apellido_paterno, "Moreno"); strcpy(Alumn[11].apellido_materno, "Farah");  
    strcpy(Alumn[12].nombre, "Adrian"); strcpy(Alumn[12].apellido_paterno, "Fonseca"); strcpy(Alumn[12].apellido_materno, "Loria");      
    strcpy(Alumn[13].nombre, "Gilmer Esau"); strcpy(Alumn[13].apellido_paterno, "Poot"); strcpy(Alumn[13].apellido_materno, "Piste");  
    strcpy(Alumn[14].nombre, "Jose Angel"); strcpy(Alumn[14].apellido_paterno, "Magaña"); strcpy(Alumn[14].apellido_materno, "Garcia");  
    strcpy(Alumn[15].nombre, "Kevin Alejandro"); strcpy(Alumn[15].apellido_paterno, "Medina"); strcpy(Alumn[15].apellido_materno, "Padilla");  
    strcpy(Alumn[16].nombre, "Fernando"); strcpy(Alumn[16].apellido_paterno, "Joachin"); strcpy(Alumn[16].apellido_materno, "Prieto");  
    strcpy(Alumn[17].nombre, "Cristian David"); strcpy(Alumn[17].apellido_paterno, "Pan"); strcpy(Alumn[17].apellido_materno, "Zaldivar");  
    strcpy(Alumn[18].nombre, "Abraham"); strcpy(Alumn[18].apellido_paterno, "Espinoza"); strcpy(Alumn[18].apellido_materno, "Mendoza");  
    strcpy(Alumn[19].nombre, "Rossana Guadalupe"); strcpy(Alumn[19].apellido_paterno, "González"); strcpy(Alumn[19].apellido_materno, "Uc");  
    strcpy(Alumn[20].nombre, "Juan Carlos"); strcpy(Alumn[20].apellido_paterno, "Ceballos"); strcpy(Alumn[20].apellido_materno, "Medina");    
    strcpy(Alumn[21].nombre, "Luis Alejandro"); strcpy(Alumn[21].apellido_paterno, "Cruz"); strcpy(Alumn[21].apellido_materno, "Inzunza");
    strcpy(Alumn[22].nombre, "Elias"); strcpy(Alumn[22].apellido_paterno, "Madera"); strcpy(Alumn[22].apellido_materno, "De Regil");
    strcpy(Alumn[23].nombre, "Andrea Isabel"); strcpy(Alumn[23].apellido_paterno, "Torres"); strcpy(Alumn[23].apellido_materno, "Pérez");
    strcpy(Alumn[24].nombre, "Alan Alfonso"); strcpy(Alumn[24].apellido_paterno, "Pérez"); strcpy(Alumn[24].apellido_materno, "Romero");
    

    int i, j, tipo_ordenamiento;
    for(tipo_ordenamiento=1; tipo_ordenamiento<=3; tipo_ordenamiento++){
        for (i=0; i<CANTIDAD_ALUMNOS; i++){
            for(j=0; j<CANTIDAD_ALUMNOS-1; j++){
                Comparar(Alumn, j, tipo_ordenamiento);
                if(Verificar_Swap(Comparar(Alumn, j, tipo_ordenamiento))> 0){
                    
                    Alumnos *p_alumno1, *p_alumno2;
                    p_alumno1 = &Alumn[j];
                    p_alumno2 = &Alumn[j+1];
                    Swap(p_alumno1, p_alumno2);
                    
                }
            }
        }
        printf("\n\n--------------------------------------\n");
        if(tipo_ordenamiento == 1){
            printf("\nEl ordenamiento por nombres es: \n");
        }
        else if(tipo_ordenamiento == 2){
            printf("\nEl ordenamiento por apellido paterno es: \n");
        }
        
        else if(tipo_ordenamiento == 3){
            printf("\nEl ordenamiento por apellido materno es: \n");
        }

        Printar_Lista(Alumn, tipo_ordenamiento);   
    }
     
}

int Comparar(Alumnos Estudiantes[], int j, int ordenamiento){
    
    int comparacion;
    if(ordenamiento==1){
        comparacion = strcmp(Estudiantes[j].nombre, Estudiantes[j+1].nombre);
        if(comparacion == 0){
            comparacion = strcmp(Estudiantes[j].apellido_paterno, Estudiantes[j+1].apellido_paterno);

            if(comparacion == 0){
                comparacion = strcmp(Estudiantes[j].apellido_materno, Estudiantes[j+1].apellido_materno);
            }
        } 
    }

    else if(ordenamiento == 2){
        comparacion = strcmp(Estudiantes[j].apellido_paterno, Estudiantes[j+1].apellido_paterno);
        if(comparacion == 0){
            comparacion = strcmp(Estudiantes[j].apellido_materno, Estudiantes[j+1].apellido_materno);

            if(comparacion == 0){
                comparacion = strcmp(Estudiantes[j].nombre, Estudiantes[j+1].nombre);
            }
        } 
    }

    else if(ordenamiento == 3){
        comparacion = strcmp(Estudiantes[j].apellido_materno, Estudiantes[j+1].apellido_materno);
        if(comparacion == 0){
            comparacion = strcmp(Estudiantes[j].apellido_paterno, Estudiantes[j+1].apellido_paterno);

            if(comparacion == 0){
                comparacion = strcmp(Estudiantes[j].nombre, Estudiantes[j+1].nombre);
            }
        } 
    }
     
    return comparacion;
}

int Verificar_Swap(int resultado){
    int hara_swap=0;
    if(resultado>0){
        hara_swap = 1;
    }
    else{
        hara_swap = 0;
    }

return hara_swap;
}

void Swap(Alumnos *nombre1, Alumnos *nombre2){
    Alumnos auxiliar;

    auxiliar = *nombre1;
    *nombre1 = *nombre2;
    *nombre2 = auxiliar;
    
}

void Printar_Lista(Alumnos Students[], int ordenamiento){
    int i;
    if(ordenamiento == 1){
        for(i=0; i<CANTIDAD_ALUMNOS; i++){
            printf("%s %s %s\n " ,  Students[i].nombre, Students[i].apellido_paterno, Students[i].apellido_materno);
        }
    }
    
    if(ordenamiento == 2){
        for(i=0; i<CANTIDAD_ALUMNOS; i++){
            printf("%s %s %s\n " ,  Students[i].apellido_paterno, Students[i].apellido_materno, Students[i].nombre);
        }
    }

    if(ordenamiento == 3){
        for(i=0; i<CANTIDAD_ALUMNOS; i++){
            printf("%s %s %s\n " ,  Students[i].apellido_materno, Students[i].apellido_paterno, Students[i].nombre);
        }
    }
}