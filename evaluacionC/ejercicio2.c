#include <stdio.h>

unsigned long long int factorial(unsigned int i) {
    if(i<=1) {
        return 1;
    }
    return i*factorial(i-1);
}

int main(int argc, char *argv[]) {
    /* 
     * DCL04-C: Se declaran tres variables en la misma línea de código, lo que puede dar lugar a confusiones
     * Solución: Declarar cada variable en una línea
     * int i=12, j=3, f=0;
    */
    int i=12;
    int j=3;
    int f=0;

    if(argc==1) {
        printf("Factorial of %d is %lld\n", i, factorial(i));
    }
    else {
        /*
         * MSC24-C: Se usa la función deprecada atoi()
         * Solución: Usar la función strtol
         * j = atoi(argv[1]);
        */
        j = strtol(argv[1]);
        for(f=0;f<j;f++) {
            printf("Factorial of %d id %lld\n", f, factorial(f));
        }
    }
}

/*
El segmento de código calcula el factorial de la variable i
mediante el uso de recursividad
*/