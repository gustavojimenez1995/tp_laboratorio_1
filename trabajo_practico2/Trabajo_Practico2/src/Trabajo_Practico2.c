/*
 ============================================================================
 Name        : Trabajo_Practico2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define TAM 1000


int main(void) {

	setbuf(stdout,NULL);

	int numerosIde=1000;
	    char seguir='n';
	    int opcionOrdenar;
	    int flagEmpleado=0;
	    empleados listaEmpleados [TAM];

	    initEmployees(listaEmpleados,TAM);

	    do
	    {

	        system("cls");

	        switch(menu())
	        {
	        case 1:
	            if(!addEmployees(listaEmpleados,TAM,&numerosIde))
	            {
	            printf("Carga exitosa!\n");
	            flagEmpleado=1;
	            }
	            else
	            {
	                printf("Error al cargar datos\n");
	            }
	            break;
	        case 2:if(flagEmpleado){
	                if(!modificarEmpleado(listaEmpleados,TAM)){
	                    printf("Modificacion exitosa!\n");
	                }
	                else
	                {
	                   printf("Modificacion cancelada\n");
	                }
	                }else{
	                printf("Error : realice la carga de algun empleado.\n");
	                }

	            break;
	        case 3:if(flagEmpleado){
	                if(!removeEmployee(listaEmpleados,TAM))
	                {
	                    printf("baja exitosa!\n");
	                }else if(removeEmployee(listaEmpleados,TAM))
	                {
	                    printf("Error\n");
	                }else
	                {
	                    printf("baja cancelada\n");
	                }
	                }else{
	                printf("Error : realice la carga de algun empleado.\n");
	                }

	                break;
	        case 4: if(flagEmpleado){
	                    printEmployees(listaEmpleados,TAM);
	                    printf("\n0.Ordenar Ascendente : \n1.Ordenar descendente : \n2.Salir : ");
	                    printf("\nIngrese opcion:");
	                    scanf("%d",&opcionOrdenar);
	                    while(opcionOrdenar!=0 && opcionOrdenar!=1 && opcionOrdenar!=2)
	                    {
	                        printf("\n0.Ordenar Ascendente : \n1.Ordenar descendente : \n2.Salir : ");
	                        scanf("%d",&opcionOrdenar);
	                    }
	                    if(!opcionOrdenar || opcionOrdenar)
	                    {
	                        sortEmployees(listaEmpleados,TAM,opcionOrdenar);
	                    }
	                    else
	                    {
	                        seguir=validacionSalir();
	                    }
	                    }else{
	                    printf("Error : realice la carga de algun empleado.\n");
	                    }
	                    break;
	        case 5:
	                seguir=validacionSalir();
	                       break;


	            }
	        system("pause");
	    }
	    while(seguir!='s');
	return EXIT_SUCCESS;
}
