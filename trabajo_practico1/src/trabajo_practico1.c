/*
 ============================================================================
 Name        : trabajo_practico1.c
 Author      : G.jimenez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operaciones.h"
#include "validacionesMenu.h"

int main(void) {

    setbuf(stdout,NULL);

    int operando1=0;
    int operando2=0;

    int triggerA=0;
    int triggerB=0;
    int triggerC=0;

    char seguir = 'n';



    do
    {
        system("cls");

        switch(menu(triggerA,triggerB,triggerC,operando1,operando2))
        {
        case 1 :
            operando1=validacionPositivos("Ingrese A : ",operando1);
            triggerA=1;
            break;
        case 2 :
            if(activador("ERROR primero ingrese numero A \n", triggerA))
            {
                operando2=validacionPositivos("Ingrese B : ",operando2);
                triggerB=1;
            }
            break;
        case 3:
            if (activador("ERROR primero ingrese numeros A ,B \n", triggerB))
            {
                triggerC=1;
            }
            break;
        case 4:
            if (activador("ERROR para mostrar resultado, primero calcule (opc3)\n",triggerC))
            {
                printf("\nb) El resultado de %d+%d es: %d\n",operando1,operando2,suma(operando1,operando2));
                printf("b) El resultado de %d-%d es: %d\n",operando1,operando2,resta(operando1,operando2));
                validacionDivision(operando1,operando2);
                printf("b) El resultado de %d*%d es: %d\n",operando1,operando2,multiplicacion(operando1,operando2));
                printf("e) El factorial de %d es: %I64d  y  El factorial de %d es: %I64d\n\n",operando1,factorial(operando1),operando2,factorial(operando2));
            }
            break;
        case 5:
            seguir=validacionSalir();
            break;
        case 6:
            operando1=0;
            operando2=0;
            triggerA=0;
            triggerB=0;
            triggerC=0;
            break;
        default:
            printf("Opcion invalida!!\n");
            break;
        }
        system("pause");
    }
    while(seguir=='n');

	return EXIT_SUCCESS;
}
