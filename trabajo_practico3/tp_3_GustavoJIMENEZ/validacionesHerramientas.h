#ifndef VALIDACIONESHERRAMIENTAS_H_INCLUDED
#define VALIDACIONESHERRAMIENTAS_H_INCLUDED



#endif // VALIDACIONESHERRAMIENTAS_H_INCLUDED
/** \brief evita el desbordamiento
 *
 * \param cadena[] char variable donde se almacena la cadena
 * \param tamVector int tamaño de la cadena de caracteres
 * \param texto[] char descripcion de tipo de dato
 * \return int 1 si hay error/0 si esta bien
 *
 */
int antiOverflow(char cadena[],int tamVector,char texto[]);
/** \brief valida la confirmacion 's' o 'n'
 *
 * \param texto[] char descripcion de tipo de confirmacion
 * \return char 's' o 'n'
 *
 */
char confirmacion(char texto[]);


