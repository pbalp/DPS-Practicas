#include <stdio.h>

extern void f(int i);

void func(int expr) {
    int i=4;    
    f(i);
    switch (expr) {
        /* DCL41-C: Se declara la variable i y se invoca a la función f antes del primer caso,
         * por lo que ninguna de las dos líneas se va a ejecutar nunca 
         * Solución: Mover las dos líneas fuera del switch
         */
        /*int i=4;
        f(i);*/
        case 0:
            i=17;
        default:
            printf("%d\n", i);
    }
}

int main(void) {
    func(0);
    return 0;
}

/*
 * 1. Si invocamos func con un 0, la función entrará en el caso 0 del switch e imprimirá 17
 * 2. El problema se encuentra en las líneas 11 y 12, ya que el código de esas líneas no se va a ejecutar nunca

*/