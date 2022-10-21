#include <stdio.h>
#include <stddef.h>

const char *p;

char *funcion1(char array[]) {
   /* DLC30-C: Se inicializa el arrray de forma local,
    * de forma que cuando acaba funcion1 el array se puede borrar
    * Solucion: Inicializar el array en funcion1 y asociale el valor "Mi Cadena"
    * en la funcion main
   */
   //char array[10] = "Mi Cadena";
   array = "Mi Cadena";
   /* Initialize array */
   return array;
}

void funcion2(void) {
   const char c_str[] = "Todo va bien";
   /* DCL30-C: El puntero p se inicializa el array de forma global
    * mientras que el arra c_str se inicializa de forma local, lo que da lugar
    * a que el valor de c_str se sobreescriba o se borre cuando acabe funcion2
    * Solucion: vaciar el puntero p una vez ha finalizado funcion2
    */
   p = c_str;
}

void funcion3(void) {
   printf("%s\n", p);
}

int main(void) {

   char array[10]; 
   p = funcion1(array);
   printf("%s\n", p);
   p = NULL;
   funcion2();
   funcion3();
   printf("%s\n", p);

   return 0;
}
