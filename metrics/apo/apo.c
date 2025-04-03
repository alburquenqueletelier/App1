#include <stdio.h>
#include <string.h>
#include "../../types/orders.h"

void apo(Order *orders, int index) {

    float sum = 0;
    for (int i=1; i<index; i++){
        sum+= orders[i].quantity;
    }
     double prom = (double) sum/index;

    printf("Promedio de pizzas por orden: %2f\n", prom) ;
}