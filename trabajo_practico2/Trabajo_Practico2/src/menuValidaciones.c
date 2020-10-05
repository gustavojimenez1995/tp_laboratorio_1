/*
 * menuValidaciones.c
 *
 *  Created on: 5 oct. 2020
 *      Author: A.G.J.C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"



int menu ()
{
    int comando;
    printf("****Menu****\n");
    printf("1. ALTAS : \n");
    printf("2. MODIFICAR : \n");
    printf("3. BAJA : \n");
    printf("4. INFORMAR : \n");
    printf("5. SALIR : \n");
    scanf("%d",&comando);

  return comando;
}
void validacionCadenaCaracteres(char cadena[])
{
     int flag=0;

    for(int i = 0 ; i <strlen(cadena); i++)
    {
        while(!isalpha(cadena[i]) || isdigit(cadena[i]))
        {

            printf("Error caracteres incorrectos, ingrese: ");
            fflush(stdin);
            scanf("%s",cadena);

        }

        if(flag == 0)
        {
            cadena[i]=toupper(cadena[i]);
            flag=1;
        }
        else if(flag == 1)
        {
            cadena[i]=tolower(cadena[i]);

        }

    }
    flag=0;
}
void validacionCadenaLongitud(char cadena[])
{

     while(strlen(cadena)>30)
    {
        printf("Error nombre excedido\n");
        printf("Ingrese : ");
        fflush(stdin);
        scanf("%s",cadena);

    }


}
char validacionSalir()
{
    char confirmacion;
    printf(" Confirmar salir s/n : ");

    fflush(stdin);
    confirmacion = tolower(getchar());

    while(confirmacion!='s' && confirmacion!='n')
    {
        printf("Error: Confirmar salir s/n : ");

        fflush(stdin);
        confirmacion = tolower(getchar());

    }
    return confirmacion;

}

