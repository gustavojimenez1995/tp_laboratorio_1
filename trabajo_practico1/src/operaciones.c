/*
 * operaciones.c
 *
 *  Created on: 11 sep. 2020
 *      Author: A.G.J.C
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "operaciones.h"
#include "validacionesMenu.h"


int suma (int num1,int num2)
{
    int total;
    total= num1 + num2; ;
    return  total;
}

int resta (int num1, int num2)
{
    int total;
    total = num1-num2;
    return total;
}

float division ( int num1, int num2)
{
    int total;
    total = (float)num1/num2;
    return total;
}

int multiplicacion (int num1, int num2)
{
    int total;
    total = (float)num1*num2;
    return total;
}


long long int factorial(int num)
{
    long long int fact;
    long long int numF = num;
    if(numF==0)
    {
        fact=0;
    }
    else if(numF==1)
    {
        fact=1;
    }
    else
    {
        fact= numF*factorial(num-1);

    }
    return fact;


}
