#include <stdlib.h>

struct flexArrayStruct {
   int num;
   /* DCL38-C: Asigna un tamaño fijo al array data, de forma que si array_size
    * es mayor que 1 provocará un problema de overflow.
    Solución: Hacer que el array data tenga un tamaño dinámico
   */
   int data[];
   //int data[1];
};

/* Crea un puntero que va a almacenar una estructura del tipo flexArrayStruct.
 * Para ello, reserva memoria para la estructura, para un número entero y para el tamaño del array
*/
void func(size_t array_size) {
   /* Space is allocated for the struct */
   struct flexArrayStruct *structP = (struct flexArrayStruct *) malloc(sizeof(struct flexArrayStruct) + sizeof(int) * (array_size-1));
   if (structP == NULL) {
      /* Handle malloc failure */
   }

   /* Asigna al campo num de la estructura el tamaño del array */
   structP->num = array_size;

   /*
    * Access data[] as if it has been allocated
    * as data[array_size]
   */
   /*
   * Asigna 1 a las posiciones de data hasta llegar a la posición anterior al número array_size
   */
   for (size_t i = 0; i < array_size; ++i) {
      structP->data[i] = 1;
   }
}

int main(void) {
   func(5);
   return 0;
}

