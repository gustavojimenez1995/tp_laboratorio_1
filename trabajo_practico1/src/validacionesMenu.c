/*
 * validacionesMenu.c
 *
 *  Created on: 11 sep. 2020
 *      Author: A.G.J.C
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operaciones.h"
#include "validacionesMenu.h"


int menu (int trigger1, int trigger2,int trigger3,int operando1, int operando2)
{
    int comando;
    printf("***Calculadora***\n\n");

    cambioXy("1. Ingresar 1er operando (A=x)","1. Ingresar 1er operando (A=",operando1,trigger1);
    cambioXy("2. Ingresar 2do operando (B=y)","2. Ingresar 2do operando (B=",operando2,trigger2);

    printf("3. Calcular todas las operaciones \n");
    menuOpc3(trigger3,operando1,operando2);

    printf("4. Informar resultados\n");

    printf("5.Salir\n\n");
    printf("6.Reiniciar \n\n: ");
    scanf("%d",&comando);
    return comando;
}

void cambioXy ( char texto1[],char texto2[], int valorxy, int trigger)
{
    if (trigger)
    {
        printf("%s%d)\n",texto2,valorxy);

    }
    else
    {
        printf("%s\n",texto1);
    }
}


void menuOpc3 (int trigger, int operandoA, int operandoB)
{
    if (!trigger)
    {
        printf(" a) Calcular la suma (A+B)\n");
        printf(" b) Calcular la resta (A-B)\n");
        printf(" c) Calcular la division (A/B)\n");
        printf(" d) Calcular la multiplicacion (A*B)\n");
        printf(" e) Calcular el factorial (A!) y (B!)\n");

    }
    else if(  trigger==1)
    {
        printf(" a) Calcular la suma (%d+%d)\n",operandoA, operandoB);
        printf(" b) Calcular la resta (%d+%d)\n",operandoA, operandoB);
        printf(" c) Calcular la division (%d+%d)\n",operandoA, operandoB);
        printf(" d) Calcular la multiplicacion (%d+%d)\n",operandoA, operandoB);
        printf(" e) Calcular el factorial (%d!) y (%d!)\n",operandoA,operandoB);
    }

}

int validacionPositivos(char texto[],int operando)
{
    int numero;
    printf("%s",texto);
    scanf("%d",&numero);


    while(operando<0)
    {
        printf("Ingrese numeros positivos\n");
        printf("%s",texto);
        scanf("%d",&numero);

    }

    return numero;
}
void validacionDivision(int dividendo, int divisor)
{
    if(divisor==0)
    {
        printf("No es posible dividir por cero \n");
    }
    else if(dividendo%divisor==0)
    {
        printf("b) El resultado de %d/%d es: %.0f\n",dividendo,divisor,division(dividendo,divisor));
    }
    else
    {
        printf("b) El resultado de %d/%d es: %.2f\n",dividendo,divisor,division(dividendo,divisor));
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
int activador(char textoError[],int trigger)
{
    int valor;

    if(!trigger)
    {
        printf("%s",textoError);
        valor=0;
    }
    else
    {
        valor=1;
    }
    return valor ;
}



