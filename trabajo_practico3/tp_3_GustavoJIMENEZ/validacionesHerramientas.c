#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

int antiOverflow(char cadena[],int tamVector,char texto[])
{
    int error = 1;
    int tamBuffer;
    char buffer[1024];

    if (tamVector>0)
    {

        printf("ingrese %s: ",texto);
        fflush(stdin);
        gets(buffer);
        tamBuffer = strlen(buffer);
        while(tamBuffer>=tamVector )
        {
            printf("Demaciado largo Reingrese %s: ",texto);
            fflush(stdin);
            gets(buffer);
            tamBuffer = strlen(buffer);
        }
        strcpy(cadena,buffer);
        error= 0;
    }

    return error;
}

char confirmacion(char texto[])
{
    char siNo;
    printf("Confirma %s  s/n?: ",texto);
    fflush(stdin);
    scanf("%c", &siNo);
    siNo = tolower(siNo);
    while(siNo!='s' && siNo!='n' )
    {
        printf("ERROR: Confirma %s  s/n?: ",texto);
        fflush(stdin);
        scanf("%c", &siNo);
        siNo = tolower(siNo);

    }

    return siNo;
}
