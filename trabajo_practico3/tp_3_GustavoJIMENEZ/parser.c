#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error = 0;
    char buffer[3][100];
    int cantCargada;
    Employee* auxiliar;
    if(pArrayListEmployee != NULL)
    {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]);
        do
        {
            cantCargada=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cantCargada==4)
            {

                auxiliar = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                ll_add(pArrayListEmployee,auxiliar);
            }
            else
            {
                break;
            }
            free(pFile);
            error = 1;
        }
        while(!feof(pFile));

    }
    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int error = 0;
    char titulo[]= {" ID   nombre  horas trabajadas  sueldo  \n"};
    int tamString = strlen(titulo)+1;
    Employee* auxEmpleado = employee_new();
    int fin;
    if(pArrayListEmployee != NULL)
    {
            fread(&titulo,sizeof(char),tamString,pFile);
        do{
            fin = fread(auxEmpleado,sizeof(Employee),1,pFile);
            if( fin == 1)
            {
            ll_add(pArrayListEmployee,auxEmpleado);
            }
       }while(fin!=0);
    }
    return error;
}
