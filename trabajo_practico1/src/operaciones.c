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


int factorial(int num)
{
    int fact;
    if(num==0)
    {
        fact=0;
    }
    else if(num==1)
    {
        fact=1;
    }
    else
    {
        fact= num *factorial(num-1);

    }
    return fact;


}
