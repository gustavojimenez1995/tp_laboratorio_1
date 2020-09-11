/*
 * validacionesMenu.h
 *
 *  Created on: 11 sep. 2020
 *      Author: A.G.J.C
 */

#ifndef VALIDACIONESMENU_H_
#define VALIDACIONESMENU_H_

//funciones de menu me (faltan los doxigen)

/** \brief muestra el menu completo
 *
 * \param int trigger1 condicional para otra funcion dentro de esta funcion menu
 * \param int trigger2 condicional para funcion dentro de esta funcion menu
 * \param int trigger3 condicional para funcion dentro de esta funcion menu
 * \param int operando1 valor de operando A
 * \param int operando2 valor de operando B
 * \return opcion elegida por el usuario
 *
 */
int menu (int trigger1, int trigger2,int trigger3,int operando1, int operando2);

/** \brief intercambia valor X y Y por valores ingresados(dentro de funcion menu)
 *
 * \param   char texto1 texto sin intercambio de valores
 * \param   char texto2 texto con intercambio de valores
 * \return void
 *
 */
void cambioXy ( char texto1[],char texto2[], int valorxy,int trigger);

/** \brief intercambia valores de  la opcion3(dentro de funcion menu)
 *
 * \param int trigger valor para la condicional , trigger = 1 muestra opcion3 con valores cambiados

 * \param int operandoA primer valor ingresado por el usuario
 * \param int operandoB primer valor ingresado por el usuario
 * \return void
 *
 */
void menuOpc3 (int trigger,int operandoA, int operandoB);

/** \brief valida que el entero ingresado sea positivo
 *
 * \param char texto[]  texto para ingresar dato
 * \param int operando numero ingresado para la validacion
 * \return int  valor que se ingreso ya validado
 */
int validacionPositivos(char texto[] ,int operando);

/** \brief devuelve texto error en caso de que el divisor sea cero, y limita decimales
           dependiendo la division
 *
 * \param dividendo int numero ingresador por el usuario
 * \param divisor int numero ingresador por el usuario
 * \return void
 *
 */
void validacionDivision(int dividendo, int divisor);


/** \brief confirma si desea salir, de ser distinto a  's' si , 'n', no muestra error
 *
 * \return char devuelve caracter ingresado
 *
 */
char validacionSalir();

/** \brief muestra error en caso de que el trigger no este activado
 *
 * \param textoError[] texto de error
 * \param trigger int trigger que activa o desactiva el mensaje de error
 * \return int cero si es error , uno si es valido
 *
 */
int activador(char textoError[],int trigger);




#endif /* VALIDACIONESMENU_H_ */
