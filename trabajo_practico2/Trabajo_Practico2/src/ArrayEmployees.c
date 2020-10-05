/*
 * ArrayEmployees.c
 *
 *  Created on: 5 oct. 2020
 *      Author: A.G.J.C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"





int addEmployees(empleados persona[], int tam, int *idAutomatico)
{
    int error=1 ;
    int indice ;
    *idAutomatico=*idAutomatico+1;
    int ide = *idAutomatico;
    empleados nuevaPersona;


    if ( persona != NULL && tam>0)
    {
        indice = buscarLibre(persona,tam);
        if(indice == -1)
        {
            printf("El sistema esta lleno\n");
        }
        else
        {
            nuevaPersona.id = ide;
            nuevaPersona.isEmpty = 0;

            printf("ID : %d\n",ide);

            printf("Ingrese nombre:\n");
            fflush(stdin);
            scanf("%s",nuevaPersona.nombre);
            validacionCadenaCaracteres(nuevaPersona.nombre);
            validacionCadenaLongitud(nuevaPersona.nombre);

            printf("Ingrese apellido:\n");
            fflush(stdin);
            scanf("%s",nuevaPersona.apellido);
            validacionCadenaCaracteres(nuevaPersona.apellido);
            validacionCadenaLongitud(nuevaPersona.apellido);

            printf("Ingrese salario:\n");
            scanf("%f",&nuevaPersona.salario);

            printf("Ingrese sector:\n");
            scanf("%d", &nuevaPersona.sector);

            persona[indice] = nuevaPersona;
            error= 0;

        }
    }
    return error;
}


//FUNCIONES INFORMAR
int printEmployees(empleados persona[], int tam)
{
    system("cls");
    int error = 1;
    int flag = 0;
    if(persona != NULL && tam >0)
    {
        system("cls"),
        printf("  ID Nombre  Apellido Sector \n");
        printf("-----------------------------------\n");


        for(int i = 0 ; i<tam; i++)
        {
            if(persona[i].isEmpty == 0)
            {
                printf("%d %10s  %10s  %3.2f %3d \n",persona[i].id,persona[i].nombre,persona[i].apellido,persona[i].salario,persona[i].sector);
                flag= 1;
            }
        }

        if(flag==0)
        {
            printf(" No Hay empleados que mostrar ");
        }
        printf("\n\n");
        error= 0;
    }
    return error;
}
//ordena por sector y apellido
int sortEmployees(empleados persona[], int tam,int ascDesc)
{
    int error = 1;
    empleados auxEmpleado;
    if(persona != NULL && tam>0)
    {
    for( int i = 0; i < tam-1; i++)
    {
        for( int j= i+1; j< tam ; j++)
        {
            if((persona[i].sector > persona[j].sector && ascDesc)
                ||(persona[i].sector< persona[j].sector && !ascDesc))
            {
                auxEmpleado = persona[i];
                persona[i]= persona[j];
                persona[j]= auxEmpleado;

            }
            if(persona[i].sector == persona[j].sector )
            {
                if(strcmp(persona[i].apellido,persona[j].apellido)> 0 )
                {
                    auxEmpleado = persona[i];
                    persona[i]= persona[j];
                    persona[j]= auxEmpleado;
                }
            }
            error= 0;
        }
    }
    }
    return error;
}




// FUNCIONES ALTA
int initEmployees(empleados gente[], int tam)
{
    int error=1;
    if(gente != NULL && tam >0)
    {
        for(int i= 0; i < tam ; i++)
        {
            gente[i].isEmpty=1;
        }
        error= 0;
    }
    return error;
}

int buscarLibre(empleados persona[], int tam)
{
    int indice= -1;
    for(int i = 0; i < tam; i++)
    {
        if(persona[i].isEmpty == 1)
        {
            indice = i ;
            break;
        }
    }
    return indice;
}
int removeEmployee(empleados persona[], int tam)
{
    int error = 1;
    int id;
    int indice;
    char confirma;

    if(persona != NULL && tam>0)
    {
        system("cls");
        printf("  *** baja de personal *** \n\n");
        printEmployees(persona,tam);
        printf("ingrese ID:");
        scanf("%d", &id);

        indice = findEmployeeById(persona,tam,id);
        if(indice == -1)
        {
            printf("No existe ID \n");
        }
        else
        {
            mostrarpersona(persona[indice]);
            printf("confirma borrado : ");
            fflush(stdin);
            scanf("%c", &confirma);
            do{
            printf("confirmar cambios? s/n ");
            scanf("%c",&confirma);
            }while(confirma!='s' && confirma!='n');
            if(confirma== 's')
            {
                persona[indice].isEmpty =1;
                error= 0;
                printEmployees(persona,tam);
            }
            else
            {
                error= 2;
            }
        }
    }
    return error;
}
void mostrarpersona(empleados persona)
{
    printf("%3d %10s  %10s  %3.2f %3d \n",persona.id,persona.nombre,persona.apellido,persona.salario,persona.sector);
}

int findEmployeeById(empleados persona[], int tam, int id)
{
    int indice= -1;
    for(int i = 0; i < tam; i++)
    {
        if(persona[i].id == id && persona[i].isEmpty == 0)
        {
            indice = i ;
            break;
        }
    }
    return indice;
}

//modificar
int modificarEmpleado(empleados persona[], int tam)
{
    int error = 1;
    int id;
    int indice;
    char confirma;
    int opcion;
    char nombreSustituto[30];
    char apellidoSustito[30];
    int sectorsustituto;
    float salariosustituto;
    empleados datosSustitutos;


    if(persona != NULL && tam>0)
    {

        printEmployees(persona,tam);
         printf("\n***Modificar datos ***\n");
        printf("ingrese ID:");
        scanf("%d", &id);

        indice = findEmployeeById(persona,tam,id);
        datosSustitutos = persona[indice];
        if(indice == -1)
        {
            printf("No existe ID \n");
        }else{
        do{
            printf(" 1.Nombre :\n");
            printf(" 2.Apellido :\n");
            printf(" 3.sector :\n");
            printf(" 4.salario :\n");
            printf(" 5.Cancelar :\n");
            printf("Ingrese opcion :");
            scanf("%d",&opcion);
        }while(opcion<0 && opcion>5);



            switch(opcion)
            {
            case 1:
                printf("ingrese nombre nuevo:");
                fflush(stdin);
                scanf("%s",nombreSustituto);
                validacionCadenaLongitud(nombreSustituto);
                validacionCadenaCaracteres(nombreSustituto);
                strcpy(datosSustitutos.nombre,nombreSustituto);
                break;
            case 2:
                printf("ingrese apellido nuevo:");
                fflush(stdin);
                scanf("%s",apellidoSustito);
                validacionCadenaLongitud(apellidoSustito);
                validacionCadenaCaracteres(nombreSustituto);
                strcpy(datosSustitutos.apellido,apellidoSustito);
                break;
            case 3:
                printf("ingrese sector nuevo:");
                scanf("%d",&sectorsustituto);
                datosSustitutos.sector=sectorsustituto;
                break;
            case 4:
                printf("ingrese salario nuevo:");
                scanf("%f",&salariosustituto);
                datosSustitutos.salario=salariosustituto;
                break;
            case 5: error=0;
                break;}
        }
        }
    	if(error!=0){

            printf("confirmar cambios? s/n ");
            fflush(stdin);
            scanf("%c",&confirma);
            while(confirma!='s' && confirma!='n')
            {
             printf("Error: confirmar cambios? s/n ");
                scanf("%c",&confirma);
            }
            if(confirma=='s')
            {
                persona[indice]=datosSustitutos;
                mostrarpersona(persona[indice]);
                 printf("\n"); }
            {
                error=1;
            }
            }


return error;
}
