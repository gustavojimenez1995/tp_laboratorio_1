#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "validacionesHerramientas.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(pArrayListEmployee != NULL)
    {
        FILE* archivo;
        archivo = fopen(path,"r");
        if (archivo != NULL)
        {
            parser_EmployeeFromText(archivo,pArrayListEmployee);
            error=0;
        }
        else
        {
            printf("no se puede abrir el arhivo");
            exit(EXIT_FAILURE);
        }
    }
    return error;
}


/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    if(pArrayListEmployee != NULL)
    {
        FILE* archivo;
        archivo = fopen(path,"rb");
        if (archivo != NULL)
        {
            parser_EmployeeFromBinary(archivo,pArrayListEmployee);
            error=0;
        }
        else
        {
            printf("no se puede abrir el arhivo");
            exit(EXIT_FAILURE);
        }
    }
    return error;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int proximoId;
    int escape = 0;
    char nombre[128];
    int horasTrabajo;
    int sueldo;
    if ( pArrayListEmployee != NULL )
    {
        Employee* nuevoEmpleado = NULL;
        nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
        if(nuevoEmpleado == NULL)
        {
            printf("problema para conseguir memoria\n");
            exit(EXIT_FAILURE);
        }
        do
        {
            system("cls");
            printf(" *** Alta de Empleado *** \n\n");
            proximoId = ll_len(pArrayListEmployee);
            printf("ID : %d\n",proximoId);
            employee_setId(nuevoEmpleado,proximoId);

            printf("ingrese nombre : ");
            scanf("%s",nombre);
            employee_setNombre(nuevoEmpleado,nombre);

            printf("Ingrese Horas trabajadas: ");
            scanf("%d",&horasTrabajo);
            employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajo);

            printf("Ingrese Sueldo: ");
            scanf("%d", &sueldo);
            employee_setSueldo(nuevoEmpleado,sueldo);

            if(confirmacion("Alta?") == 's')
            {
                ll_add(pArrayListEmployee,nuevoEmpleado);
                error= 0;
            }else
            {
                error=-1;
            }


            escape = 1;
        }
        while(escape==0);
    }

    return error;
}

/** \brief devuelve indice deseado
 *
 * \param pArrayListEmployee LinkedList*
 * \param idEmpleado int
 * \return int -1 si no se encuentra en indice
 *
 */
int buscarEmpleado(LinkedList* pArrayListEmployee,int idEmpleado)
{
    int indice = -1;
    int tamLista = ll_len(pArrayListEmployee);
    Employee* auxempleado;
    if(pArrayListEmployee != NULL)
    {
        for(int i = 0; i<tamLista; i++)
        {
            auxempleado = (Employee*)ll_get(pArrayListEmployee,i);
            if(auxempleado->id == idEmpleado)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}
/** \brief Listar empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 error /1 si esta bien
 *
 */
int print_Employe(Employee* empleado)
{
    int error = 0;
    if ( empleado != NULL)
    {
        error = 1;
        printf(" %4d  %10s  %15d  %5d\n", empleado->id,empleado->nombre,empleado->horasTrabajadas,empleado->sueldo);
    }
    return error;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int error = 1;
    int tam = ll_len(pArrayListEmployee);
    Employee* auxiliar;
    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf(" ID       nombre  horas trabajadas  sueldo  \n");
        printf("------------------------------------------\n");
        for( int i = 0; i < tam ; i++)
        {
            auxiliar = (Employee*)ll_get(pArrayListEmployee, i);

            if( auxiliar != NULL)
            {
                print_Employe(auxiliar);
            }
        }
        error = 0;
    }
    return error;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error;
    int opcion;
    int opcionOrden;
    if( pArrayListEmployee != NULL)
    {
        system("cls");
        printf("*** ordenar empleados ***\n");
        printf("1. ordenar por ID \n");
        printf("2. ordenar por nombre \n");
        printf("3. ordenar por Horas trabajadas \n");
        printf("4. ordenar por sueldo \n");
        printf("   ingrese opcion : ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("1. ascendente\n");
            printf("2. descendente\n");
            scanf("%d",&opcionOrden);
            if(opcionOrden == 1)
            {
                ll_sort(pArrayListEmployee,employee_SortById,1);
            }
            else
            {
                ll_sort(pArrayListEmployee,employee_SortById,0);
            }
            break;
        case 2:
            system("cls");
            printf("1. ascendente\n");
            printf("2. descendente\n");
            printf("   ingrese opcion : ");
            scanf("%d",&opcionOrden);
            if(opcionOrden == 1)
            {
                ll_sort(pArrayListEmployee,employee_SortByName,1);
            }
            else
            {
                ll_sort(pArrayListEmployee,employee_SortByName,0);
            }
            break;
        case 3:
            system("cls");
            printf("1. ascendente\n");
            printf("2. descendente\n");
            printf("   ingrese opcion : ");
            scanf("%d",&opcionOrden);
            if(opcionOrden == 1)
            {
                ll_sort(pArrayListEmployee,employee_SortByHorasTrabajadas,1);
            }
            else
            {
                ll_sort(pArrayListEmployee,employee_SortByHorasTrabajadas,0);
            }
            break;
        case 4:
            system("cls");
            printf("1. ascendente\n");
            printf("2. descendente\n");
            printf("   ingrese opcion : ");
            scanf("%d",&opcionOrden);
            if(opcionOrden == 1)
            {
                ll_sort(pArrayListEmployee,employee_SortBySueldo,1);
            }
            else
            {
                ll_sort(pArrayListEmployee,employee_SortBySueldo,0);
            }
            break;
        default:
            printf("opcion incorrecta!\n");
            break;
        }

    error=0;



    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    FILE* archivo = fopen(path,"w");
    int tam = ll_len(pArrayListEmployee);
    int flag = 0;
    Employee* auxEmpleado =  employee_new();
    if(pArrayListEmployee != NULL && archivo!=NULL)
    {
        for(int i = 0; i <tam ; i++)
        {
            if ( flag == 0 )
            {
                fprintf(archivo,"  ID  nombre  Horas trabajadas  Sueldo \n");
                flag++;
            }
            else
            {
                auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                fprintf(archivo,"  %d  %s  %d  %d \n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
            }

        }
        fclose(archivo);
        error = 0;
    }

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int error = 1;
    FILE* archivo = fopen(path,"wb");
    int tam = ll_len(pArrayListEmployee);
    int flag = 0;
    Employee* auxEmpleado =  employee_new();
    char titulo[]= {" ID   nombre     horas trabajadas  sueldo  \n"};
    int tamString = strlen(titulo)+1;
    if(pArrayListEmployee != NULL && archivo!=NULL)
    {
        for(int i = 0; i <tam ; i++)
        {
            if ( flag == 0 )
            {
                fwrite(&titulo,sizeof(char),tamString,archivo);
                flag++;
            }
            else
            {

                auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                fwrite(&auxEmpleado,sizeof(Employee),1,archivo);
            }

        }
        fclose(archivo);
        error = 0;
    }

    return error;


    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int indiceBaja;
    int idBaja;
    Employee* empleadoBaja;
    if( pArrayListEmployee != NULL)
    {
        printf("*** Baja de empleado ***\n");
        printf("-------------------------\n");
        controller_ListEmployee(pArrayListEmployee);
        printf("ingrese id : ");
        scanf("%d",&idBaja);
        indiceBaja = buscarEmpleado(pArrayListEmployee,idBaja);
        if(indiceBaja == -1)
        {
            printf("no existe ID!\n");
        }
        else
        {
            empleadoBaja = (Employee*)ll_get(pArrayListEmployee,indiceBaja) ;
            printf("-----------------------------\n");
            print_Employe(empleadoBaja);
            printf("-----------------------------\n");
            if(confirmacion("Baja") == 's')
            {
                ll_remove(pArrayListEmployee,indiceBaja);
                error = 0;
            }else
            {
                error = -1;
            }
        }
    }
    return error;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int indiceModificar;
    int idModificar;
    int opcion;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;
    char seguir = 's';
    Employee* empleadoModificar;


    if(pArrayListEmployee != NULL)
    {
        system("cls");
        printf("  *** Modificar datos *** \n");
        controller_ListEmployee(pArrayListEmployee);
        printf("\ningrese ID :");
        scanf("%d", &idModificar);

        indiceModificar = buscarEmpleado(pArrayListEmployee,idModificar);

        if(indiceModificar == -1)
        {
            printf("no existe ID");
        }
        else
        {

            empleadoModificar = (Employee*)ll_get(pArrayListEmployee,indiceModificar);

            do
            {
                system("cls");
                printf("-----------------------------\n");
                print_Employe(empleadoModificar);
                printf("-----------------------------\n\n");
                printf("1. Modificar nombre \n");
                printf("2. Modificar  horas trabajada\n");
                printf("3. Modificar  sueldo\n");
                printf("   Ingrese opcion : ");
                scanf("%d",&opcion);
                switch(opcion)
                {
                case 1:
                    printf("Ingrese nuevo nombre : ");
                    fflush(stdin);
                    gets(auxNombre);
                    break;
                case 2:
                    printf("Ingrese nuevo horas trabajadas : ");
                    scanf("%d",&auxHoras);
                    break;
                case 3:
                    printf("Ingrese nuevo sueldo : ");
                    scanf("%d",&auxSueldo);
                    break;
                default:
                    printf("opcion incorecta!!!\n");
                    break;
                }
                printf("desea realizar otros cambios?  s/n :");
                scanf("%s", &seguir);
                if(seguir!='s')
                {
                    seguir = 'n';
                }
            }
            while(seguir== 's');
            system("cls");
            if(confirmacion("Cambios")== 's')
            {
                strcpy(empleadoModificar->nombre,auxNombre);
                empleadoModificar->horasTrabajadas = auxHoras;
                empleadoModificar->sueldo = auxSueldo;
                error=0;
            }
            else
            {
                error=-1;
            }

        }
        printf("%d\n", error);
    }
    return error;
}
