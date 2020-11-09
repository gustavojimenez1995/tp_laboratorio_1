#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "validacionesHerramientas.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int menu();


int main()
{


    int seguir = 's';
    int flagCarga = 0;
    int triggerCargaTexto = 0;
    int triggerCargaBinario = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            if(flagCarga==0)
            {
                flagCarga++;

                if(!(controller_loadFromText("data.csv",listaEmpleados)))
                {
                    printf("Archivo cargado con exito\n");
                    triggerCargaTexto++;
                }
                else
                {
                    printf("Error al cargar archivo\n");
                }
            }
            else
            {
                printf("los datos ya fueron cargados!!\n");
            }
            break;
        case 2:
            if(flagCarga==0)
            {
                flagCarga++;
                if(!(controller_loadFromBinary("data.bin",listaEmpleados)))
                {
                    printf("Archivo cargado con exito\n");
                    triggerCargaBinario++;
                }
                else
                {
                    printf("Error al cargar archivo\n");
                }
            }
            else
            {
                printf("los datos ya fueron cargados!!\n");
            }
            break;
        case 3:
            if(triggerCargaTexto!=0 || triggerCargaBinario!=0)
            {
                if((controller_addEmployee(listaEmpleados))-1)
                {
                    printf("Alta Cancelado");
                }
                else if((controller_addEmployee(listaEmpleados)))
                {
                    printf("Exito al dar Alta!!!\n");
                }
                else
                {
                    printf("Error al realizar Alta!!! \n");
                }
            }
            else
            {
                printf("Carge datos antes de dar Alta!!\n");
            }
            break;
        case 4:
            if(triggerCargaTexto!=0 || triggerCargaBinario!=0)
            {
                if((controller_editEmployee(listaEmpleados))-1)
                {
                    printf("Modificacion Cancelado\n");
                }
                else if((controller_editEmployee(listaEmpleados)))
                {
                    printf("Exito Modificacion!!!\n");
                }
                else
                {
                    printf("Error al realizar Modificacion!!! \n");
                }
            }
            else
            {
                printf("Carge datos antes de Modificar!!\n");
            }


            break;
        case 5:
            if(triggerCargaTexto!=0 || triggerCargaBinario!=0)
            {
                if((controller_removeEmployee(listaEmpleados))-1)
                {
                    printf("Baja Cancelada!!\n");
                }
                else if((controller_removeEmployee(listaEmpleados)))
                {
                    printf("Exito al realizar Baja!!!\n");
                }
                else
                {
                    printf("Error al realizar Baja!!! \n");
                }
            }
            else
            {
                printf("Carge datos antes de Modificar!!\n");
            }
            break;
        case 6:
            if(triggerCargaTexto!=0 || triggerCargaBinario!=0)
            {
                if(controller_ListEmployee(listaEmpleados))
                {
                    printf("Error al Listar empleados\n");
                }
            }
            else
            {
                printf("Carge datos antes de Listar datos!!\n");
            }
            break;
        case 7:
            if(triggerCargaTexto!=0 || triggerCargaBinario!=0)
            {
                if(!(controller_sortEmployee(listaEmpleados)))
                {
                    printf("Orden de Ordenad lista!!\n");
                }
            }
            else
            {
                printf("Carge datos antes de Listar datos!!\n");
            }

            break;
        case 8:
            if(!controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("Archivo guardado con exito\n");
            }
            else
            {
                printf("Error al guardad Archivo\n");
            }
            break;
        case 9:
            if(!controller_saveAsBinary("data.bin",listaEmpleados))
            {
                printf("Archivo guardado con exito\n");
            }
            else
            {
                printf("Error al guardad Archivo\n");
            }
            break;
        case 10:
            if(confirmacion("Salida") == 's')
            {
                seguir = 'n';
            }
            break;
        default:
            printf("\nOpcion invalida!!!\n");
        }
        system("pause");
    }
    while(seguir == 's');
    return 0;
}

int menu()
{
    int opcion;
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin(modo binario).\n");
    printf("10. Salir\n");
    scanf("%d",&opcion);

    return opcion;

}

