#include <stdio.h>
#include <string.h>
#include "../../types/dates.h"

void apd(Date_sale *dates, int index) {

    float sum = 0;
    for (int i=1; i<index; i++){
        sum += dates[i].quantity;  // `quantity` es la cantidad de pizzas
    }
    float promedio = sum/index;

    printf("Promedio de pizzas al dia: %.2f\n", promedio);
}