#include <stdio.h>
#include <stdlib.h>

/** \brief Se encarga de pedir los valores de los operandos
 *
 * \param void No recibe ningun valor
 * \return float Retorna el valor ingreso del operando
 *
 */
float ingreso(void)
{
    float var;
    printf("Ingrese valor que tomara la variable\n");
    scanf("%f",&var);
    return var;

}
/** \brief Se encarga de realizar la suma de los operandos
 *
 * \param a float Recibe el valor del primer operando
 * \param b float Recibe el valor del segundo operando
 * \return float Retorna el resultado de la suma
 *
 */
float suma(float a,float b)
{
    return a+b;
}
/** \brief Se encarga de realizar la resta de los operandos
 *
 * \param a float Recibe el valor del primer operando
 * \param b float Recibe el valor del segundo operando
 * \return float Retorna el resultado de la resta
 *
 */
float resta(float a,float b)
{
    return a-b;
}
/** \brief Se encarga de realizar la division de los operandos
 *
 * \param a float Recibe el valor del primer operando
 * \param b float Recibe el valor del segundo operando
 * \return float Retorna el resultado de la division
 *
 */
float division(float a,float b)
{
    return a/b;
}
/** \brief Se encarga de realizar la multiplicacion de los operandos
 *
 * \param a float Recibe el valor del primer operando
 * \param b float Recibe el valor del primer operando
 * \return float Retorna el resultado de la multiplicacion
 *
 */
float multiplicar(float a,float b)
{
    return a*b;
}
/** \brief Se encarga de realizar el factorial del primer operando
 *
 * \param a double Recibe el valor del primer operando
 * \return double Retorna el factorial del primer operando
 *
 */
double factorial(double a)
{
    double rta;
    if(a==0)
    {
        rta=1;
    }
    else
    {
        rta=a*factorial(a-1);
    }
    return rta;
}
