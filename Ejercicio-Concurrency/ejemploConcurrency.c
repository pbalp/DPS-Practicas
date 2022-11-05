#include <threads.h>
#include <stdio.h>

/*
 * El siguiente ejemplo consiste en un programa que crea un hilo y, 
 * en caso de que no haya surgido ningún problema, le pasa al hilo hijo
 * la dirección en la que se almacena esa variable. Por último, el hilo hijo
 * imprime por salida estándar esa variable.
 * La variable tiene un tiempo de almacenado automático.
 * Si el hilo hijo intenta acceder a esta variable después de que se le haya
 * agotado el tiempo de almacenado en el hilo padre, ésta se borrará de la memoria
 * y se producirá un acceso inválido a memoria por parte del hilo hijo.
*/

int child_thread(void *val) {
    int *res = (int *)val;
    printf("Result: %d\n", *res);
    return 0;
}

void create_thread(thrd_t *tid) {
    /*
     * Para solucionar este problema, se declara la variable como estática.
     * De esta forma, la variable se mantendrá almacenada en la memoria durante
     * durante toda la ejecución del programa y no se producirán accesos inválidos
     * a la memoria.
     * Además, proporciona un acceso más seguro para los hilos.
    */
    static int val = 1;
    if (thrd_success != thrd_create(tid, child_thread, &val)) {
        /* Handle error */
        print("ERROR: Error en la creacion del hilo");
        return 1;
    }
}

int main(void) {
    thrd_t tid;
    create_thread(&tid);
    if (thrd_success != thrd_join(tid, NULL)) {
        /* Handle error */
        print("ERROR: Error en el bloqueo del hilo");
        return 1;
    }
    return 0;
}