#include <stdio.h>

unsigned long long int factorial(unsigned int i) {
    if(i<=1) {
        return 1;
    }
    return i*factorial(i-1);
}

int main(int argc, char *argv[]) {
    int i=12, j=3, f=0;

    if(argc==1) {
        printf("Factorial of %d is %11d\n", i, factorial(i));
    }
    else {
        j = atoi(argv[1]);
        for(f=0;f<j;f++) {
            printf("Factorial of %d id %11d\n", f, factorial(f));
        }
    }
}

/*
El segmento de código calcula el factorial de la variable i
mediante el uso de recursividad
*/