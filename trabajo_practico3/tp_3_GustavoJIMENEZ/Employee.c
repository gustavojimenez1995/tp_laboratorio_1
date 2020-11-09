#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "-------");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado ;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* nuevoEmpleado = employee_new();
    if(nuevoEmpleado != NULL)
    {

        int id = atoi(idStr);
        int horas = atoi(horasTrabajadasStr);
        int sueldo = atoi(sueldoStr);
        if(employee_setId(nuevoEmpleado,id)
                ||employee_setNombre(nuevoEmpleado,nombreStr)
                ||employee_setHorasTrabajadas(nuevoEmpleado,horas)
                ||employee_setSueldo(nuevoEmpleado,sueldo))
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}


void employee_delete(Employee* this)
{
    return free(this);
}
int employee_setId(Employee* this,int id)
{
    int error = 1;
    if (this != NULL && id >= 0 && id<2000)
    {
        this->id = id;
        error = 0;
    }
    return error;
}


int employee_getId(Employee* this,int*id)
{
    int error = 1;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = 1;
    if (this != NULL && nombre!=NULL)
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }
    return error;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int error = 1;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre );
        error = 0;
    }
    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error = 1;
    if (this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 0;
    }
    return error;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error = 1;
    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 0;
    }
    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 1;
    if (this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        error = 0;
    }
    return error;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 1;
    if (this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }
    return error;
}

int employee_SortById(void* empleadoA, void*empleadoB)
{
    int retorno = 0;
    int idA;
    int idB;
    employee_getId((Employee*) empleadoA, &idA);
    employee_getId((Employee*) empleadoB, &idB);

     if( idA == idB)
    {
        retorno = 0;
    }
    else if(idA < idB)
    {
        retorno = -1;
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}
int employee_SortByHorasTrabajadas(void* empleadoA, void*empleadoB)
{
    int retorno;
    int idA;
    int idB;
    employee_getId((Employee*) empleadoA, &idA);
    employee_getId((Employee*) empleadoB, &idB);

     if( idA == idB)
    {
        retorno = 0;
    }
    else if(idA < idB)
    {
        retorno = -1;
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}
int employee_SortBySueldo(void* empleadoA, void*empleadoB)
{
    int retorno;
    int idA;
    int idB;
    employee_getId((Employee*) empleadoA, &idA);
    employee_getId((Employee*) empleadoB, &idB);

     if( idA == idB)
    {
        retorno = 0;
    }
    else if(idA < idB)
    {
        retorno = -1;
    }
    else
    {
        retorno = 1;
    }

    return retorno;
}

int employee_SortByName(void* empleadoA, void*empleadoB)
{
    int retorno;
    char primerEmpleado [128];
    char segundoEmpleado[128];
    employee_getNombre((Employee*)empleadoA,primerEmpleado);
    employee_getNombre((Employee*)empleadoA,segundoEmpleado);

    if( strcmp(primerEmpleado,segundoEmpleado)==0)
    {
        retorno = 0;
    }
    else if(strcmp(primerEmpleado,segundoEmpleado)<0)
    {
        retorno = -1;
    }
    else if (strcmp(primerEmpleado,segundoEmpleado)>0)
    {
        retorno = 1;
    }
    return retorno;
}
